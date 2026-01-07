#include <Arduino.h>

enum State { DRONE_INSIDE, TAKE_OFF, DRONE_OUT, LANDING };
State currentState = DRONE_INSIDE;

const int ledPin = LED_BUILTIN;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  // Non serve Serial.begin(), la seriale è occupata da Java
}

void loop() {
  receiveCommand();
  delay(50); // piccolo delay per non saturare il ciclo
}

void receiveCommand() {
  while (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    State previousState = currentState;
    bool validCommand = true;

    if (cmd == "TAKE_OFF") {
      if (currentState == DRONE_INSIDE) currentState = TAKE_OFF;
      else validCommand = false;
    } 
    else if (cmd == "LANDING") {
      if (currentState == DRONE_OUT) currentState = LANDING;
      else validCommand = false;
    } 
    else if (cmd == "DRONE_INSIDE") currentState = DRONE_INSIDE;
    else if (cmd == "DRONE_OUT") currentState = DRONE_OUT;
    else validCommand = false;

    // Controllo stato
    if (validCommand && currentState == previousState) {
      // Stato non cambiato quando doveva
      blinkLED(3, 400);
    } 
    else if (validCommand) {
      // Stato cambiato correttamente
      blinkLED(1, 500);
    } 
    else {
      // Comando non valido
      blinkLED(2, 250);
    }
  }
}

// Funzione per lampeggiare il LED
void blinkLED(int times, int duration) {
  for(int i=0; i<times; i++){
    digitalWrite(ledPin, HIGH);
    delay(duration);
    digitalWrite(ledPin, LOW);
    delay(duration);
  }
}

#include "DoorTask.h"
#include <Arduino.h>

#define FWD_TIME 1000  // tempo di apertura/chiusura in ms

DoorTask::DoorTask(ServoMotor* motor, Context& context) 
    : motor(motor), context(context), state(DoorState::CLOSE), countingTime(false), currentPos(0) 
{
    motor->setPosition(0); // assicuriamoci che la porta parta chiusa
}

void DoorTask::init(int period){
    Task::init(period);
    motor->on();
}

void DoorTask::tick() {
    switch(state) {
        case DoorState::CLOSE:
        motor->off();
            if(context.getState() == State::LANDING || context.getState() == State::TAKE_OFF) {
                motor->on();
                setState(DoorState::OPENING);
            }
            break;

        case DoorState::OPENING:
            if(!countingTime) startTime();
            motor->setPosition(computePosition(true)); // true = apertura
            if(elapsedTimeInState() >= FWD_TIME) {
                motor->setPosition(MAX_OPEN_DEGREE); // sicurezza
                stopTime();
                setState(DoorState::OPEN);
            }
            break;

        case DoorState::OPEN:
            motor->off();
            if(context.getState() == State::DRONE_INSIDE || 
               context.getState() == State::DRONE_OUT || 
               context.getState() == State::FORCED_CLOSING) {
                motor->on();
                setState(DoorState::CLOSING);
            }
            break;

        case DoorState::CLOSING:
            if(!countingTime) startTime();
            motor->setPosition(computePosition(false)); // false = chiusura
            if(elapsedTimeInState() >= FWD_TIME) {
                motor->setPosition(0); // sicurezza
                stopTime();
                setState(DoorState::CLOSE);
            }
            break;
    }
}

void DoorTask::setState(DoorState s) {
    state = s;
    countingTime = false; // reset timer al cambio stato
}

// inizio il conteggio del tempo
void DoorTask::startTime() {
    timeStamp = millis();
    countingTime = true;
}

// tempo trascorso nello stato corrente
unsigned long DoorTask::elapsedTimeInState() {
    return millis() - timeStamp;
}

// ferma il conteggio del tempo
void DoorTask::stopTime() {
    countingTime = false;
}

// calcola la posizione della porta in base al tempo e alla direzione
float DoorTask::computePosition(bool opening) {
    float progress = (float)elapsedTimeInState() / FWD_TIME;
    if(progress > 1.0) progress = 1.0; // limite massimo
    float angle =  opening ? progress * MAX_OPEN_DEGREE : MAX_OPEN_DEGREE * (1.0 - progress);
    return round(angle);
}

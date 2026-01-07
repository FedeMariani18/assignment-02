#include "Arduino.h"
#include "config.h"
#include "MsgService.h"

void serialEvent();

String content;
MsgServiceClass MsgService;

bool MsgServiceClass::isMsgAvailable(){
    serialEvent();
    return msgAvailable;
}

Msg* MsgServiceClass::receiveMsg(){
    Msg* msg = currentMsg;
    resetMsg();
    return msg;
}

void MsgServiceClass::init(){
    Serial.begin(115200);
    content.reserve(256);
    pinMode(LED1_PIN, OUTPUT);
    resetMsg();

    // small startup blink to indicate service initialized
    blinkLED(1, 100);
}

void MsgServiceClass::resetMsg(){
    currentMsg->setContent("");
    msgAvailable = false;
    content = "";
}

void MsgServiceClass::sendMsg(const String& msg){
    Serial.println(msg);
}

void serialEvent() {
    /* reading the content */
    while (Serial.available()) {
        String cmd = Serial.readStringUntil('\n');
        cmd.trim();
        //if(cmd.equals("TAKE_OFF")){
            MsgService.blinkLED(5, 100);
        //}
        MsgService.currentMsg->setContent(cmd);
        MsgService.msgAvailable = true; 
        content = "";     
    }
}

bool MsgServiceClass::isMsgAvailable(Pattern& pattern){
    return (msgAvailable && pattern.match(*currentMsg));
}

Msg* MsgServiceClass::receiveMsg(Pattern& pattern){
    if (msgAvailable && pattern.match(*currentMsg)){
        Msg* msg = currentMsg;
        resetMsg();
        return msg;  
    } else {
        return NULL; 
    }
}

void MsgServiceClass::blinkLED(int times, int duration) {
  for(int i=0; i<times; i++){
    digitalWrite(LED1_PIN, HIGH);
    delay(duration);
    digitalWrite(LED1_PIN, LOW);
    delay(duration);
  }
}
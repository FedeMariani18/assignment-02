#include "L3Task.h"

L3Task::L3Task(Led* led, ContextAlarm& contextAlarm): led(led), contextAlarm(contextAlarm){
    
}

void L3Task::tick(){
    if(contextAlarm.getAlarmState() == AlarmState::ALARM){
        led->switchOn();
    } else {
        led->switchOff();
    }
}
#include "tasks\TemperatureAlarmTask.h"
#include "config.h"
#include <Arduino.h>

TemperatureAlarmTask::TemperatureAlarmTask(ContextAlarm& contextAlarm, Context& context, double temp, Button* resetBtn):
    contextAlarm(contextAlarm), context(context), temp(temp), resetBtn(resetBtn){

}

void TemperatureAlarmTask::tick(){
    switch (contextAlarm.getAlarmState()){
        
        case AlarmState::NORMAL_OUT:
            if(context.getState() != State::DRONE_OUT){
                contextAlarm.setAlarmState(AlarmState::NORMAL);
            }
            break;

        case AlarmState::NORMAL:
            if(context.getState() == State::DRONE_OUT){
                contextAlarm.setAlarmState(AlarmState::NORMAL_OUT);
            }
            if(temp > TEMP1) {
                if(countingTime && elapsedTimeInTemp() > T3){
                    contextAlarm.setAlarmState(AlarmState::PRE_ALARM);
                    stopTimeInTemp();
                } else if(!countingTime) {
                    startTimeInTemp();
                }
            }
            break;

        case AlarmState::PRE_ALARM:
            if(temp < TEMP1){
                contextAlarm.setAlarmState(chooseNormalState());
            }
            if(temp > TEMP2) {
                if(countingTime && elapsedTimeInTemp() > T4){
                    contextAlarm.setAlarmState(AlarmState::ALARM);
                    stopTimeInTemp();
                } else if(!countingTime) {
                    startTimeInTemp();
                }
            }
            break;

        case AlarmState::ALARM:
            if(resetBtn->isPressed()){
                contextAlarm.setAlarmState(chooseNormalState());
            }
            break;
        default:
            break;
    }
    
}

AlarmState TemperatureAlarmTask::chooseNormalState(){
    if(context.getState() == State::DRONE_OUT){
        return AlarmState::NORMAL_OUT;
    } else if(context.getState() != State::DRONE_OUT){
        return AlarmState::NORMAL;
    }
}

void TemperatureAlarmTask::startTimeInTemp(){
    tempTimeStamp = millis();
    countingTime = true;
}

long TemperatureAlarmTask::elapsedTimeInTemp(){
    return millis() - tempTimeStamp;
}

void TemperatureAlarmTask::stopTimeInTemp(){
    countingTime = false;
}
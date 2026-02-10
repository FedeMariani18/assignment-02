#include "tasks\TemperatureAlarmTask.h"
#include "config.h"
#include <Arduino.h>

TemperatureAlarmTask::TemperatureAlarmTask(ContextAlarm& contextAlarm, Context& context, double& temp, Button* resetBtn):
    contextAlarm(contextAlarm), context(context), temp(temp), resetBtn(resetBtn){

}

void TemperatureAlarmTask::tick() {

    // Serial.print("Temp=");
    // Serial.print(temp);
    // Serial.print("  State=");
    // Serial.print((int)contextAlarm.getAlarmState());
    // Serial.print("  counting=");
    // Serial.print(countingTime);
    // Serial.print("  elapsed=");
    // Serial.println(elapsedTimeInTemp());
    switch (contextAlarm.getAlarmState()) {

    case AlarmState::NORMAL_OUT:
        if (context.getState() != State::DRONE_OUT)
            contextAlarm.setAlarmState(AlarmState::NORMAL);
        break;

    case AlarmState::NORMAL:

        if (context.getState() == State::DRONE_OUT)
            contextAlarm.setAlarmState(AlarmState::NORMAL_OUT);

        if (temp >= TEMP1) {
            if (!countingTime) startTimeInTemp();
            else if (elapsedTimeInTemp() > T3) {
                contextAlarm.setAlarmState(AlarmState::PRE_ALARM);
                stopTimeInTemp();
            }
        } else {
            stopTimeInTemp();
        }
        break;

    case AlarmState::PRE_ALARM:

        if (temp < TEMP1) {
            contextAlarm.setAlarmState(chooseNormalState());
            stopTimeInTemp();
            break;
        }

        if (temp >= TEMP2) {
            if (!countingTime) startTimeInTemp();
            else if (elapsedTimeInTemp() > T4) {
                contextAlarm.setAlarmState(AlarmState::ALARM);
                stopTimeInTemp();
            }
        } else {
            stopTimeInTemp();
        }
        break;

    case AlarmState::ALARM:
        resetBtn->update();
        if (resetBtn->wasPressed()) {
            contextAlarm.setAlarmState(chooseNormalState());
        }
        break;
    }
}

AlarmState TemperatureAlarmTask::chooseNormalState(){
    if(context.getState() == State::DRONE_OUT){
        return AlarmState::NORMAL_OUT;
    } else{
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
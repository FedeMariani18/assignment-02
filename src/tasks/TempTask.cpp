#include "TempTask.h"
#include "config.h"

TempTask::TempTask(TempSensor* tempSensor, ContextAlarm& contextAlarm, double& temp):
    tempSensor(tempSensor), contextAlarm(contextAlarm), temp(temp){
    
}

void TempTask::tick(){
    if(contextAlarm.getAlarmState() != AlarmState::NORMAL_OUT){
        temp = tempSensor->getTemperature();
    }
}
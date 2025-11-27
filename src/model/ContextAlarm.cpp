#include "ContextAlarm.h"
#include "config.h"

ContextAlarm::ContextAlarm(){
  this->alarmState = AlarmState::NORMAL;
}

void ContextAlarm::setAlarmState(AlarmState s){
  alarmState = s;
}

AlarmState ContextAlarm::getAlarmState(){
  return alarmState;
}

void ContextAlarm::reset(){
  alarmState = AlarmState::NORMAL;
}


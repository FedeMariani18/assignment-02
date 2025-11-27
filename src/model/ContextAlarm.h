#ifndef __ALARM_CONTEXT__
#define __ALARM_CONTEXT__

#include "config.h"

class ContextAlarm {

public:
  ContextAlarm();

  void setAlarmState(AlarmState state);
  AlarmState getAlarmState();
  void reset();
  
private:
  AlarmState alarmState;
};

#endif

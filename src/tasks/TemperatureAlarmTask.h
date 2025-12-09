#ifndef __TEMP_ALARM_TASK__
#define __TEMP_ALARM_TASK__

#include "kernel\Task.h"
#include "model\ContextAlarm.h"
#include "model\Context.h"
#include "devices\button\Button.h"
#include "config.h"

class TemperatureAlarmTask: public Task{

public:
    TemperatureAlarmTask(ContextAlarm& contextAlarm, Context& context, double temp, Button* resetBtn);
    void tick();

private:
    AlarmState chooseNormalState();

    void startTimeInTemp();
    void stopTimeInTemp();
    long elapsedTimeInTemp();
    
    ContextAlarm& contextAlarm;
    Context& context;
    double temp;
    Button* resetBtn;
    
    long tempTimeStamp;
    bool countingTime;
};

#endif 
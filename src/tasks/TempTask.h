#ifndef __TEMP_TASK__
#define __TEMP_TASK__

#include "kernel\Task.h"
#include "devices\tempSensor\TempSensor.h"
#include "model\ContextAlarm.h"

class TempTask: public Task{

public:
    TempTask(TempSensor* tempSensor, ContextAlarm& contextAlarm, double& temp);
    void tick();

private:
    double temp;

    TempSensor* tempSensor;
    ContextAlarm& contextAlarm;
};

#endif
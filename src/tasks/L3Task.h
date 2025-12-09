#ifndef __L3_TASK__
#define __L3_TASK__

#include "kernel\Task.h"
#include "devices\led\Led.h"
#include "model\ContextAlarm.h"

class L3Task: public Task{

public:
    L3Task(Led* led, ContextAlarm& contextAlarm);
    void tick();

private:
    Led* led;
    ContextAlarm& contextAlarm;
};

#endif
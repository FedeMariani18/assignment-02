#ifndef __L2_TASK__
#define __L2_TASK__

#include "kernel\Task.h"
#include "devices\led\Led.h"
#include "model\Context.h"

class L2Task: public Task{

public:
    L2Task(Led* led, Context& context);
    void tick();

private:
    void setState(int state);
    enum {OFF,ON} state;
    Led* led;
    Context& context;
};

#endif
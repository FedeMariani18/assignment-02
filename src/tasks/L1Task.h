#ifndef __L1_TASK__
#define __L1_TASK__

#include "kernel\Task.h"
#include "devices\led\Led.h"
#include "model\Context.h"

class L1Task: public Task{

public:
    L1Task(Led* led, Context& context);
    void tick();

private:
    Led* led;
    Context& context;
};

#endif
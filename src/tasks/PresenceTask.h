#ifndef __PRESENCE_TASK__
#define __PRESENCE_TASK__

#include "kernel\Task.h"
#include "devices\presenceSensor\PresenceSensor.h"
#include "model\Context.h"

class PresenceTask: public Task{

public:
    PresenceTask(PresenceSensor* presenceSensor, Context& context, bool& present);
    void tick();

private:
    PresenceSensor* presenceSensor;
    Context& context;
    bool present;
};

#endif
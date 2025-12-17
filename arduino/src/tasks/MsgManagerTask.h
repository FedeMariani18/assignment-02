#ifndef __MESSAGE_TASK__
#define __MESSAGE_TASK__

#include "kernel\Task.h"
#include "kernel\MsgService.h"
#include "model\Context.h"
#include "model\ContextAlarm.h"


class MsgManagerTask: public Task{

public:
    MsgManagerTask(Context& context, ContextAlarm& contextAlarm, Command& command, double& distance);
    void tick();

private:
    void receive();
    void send();

    Context& context;
    ContextAlarm& contextAlarm;
    Command& command;
    double& distance; 
};

#endif
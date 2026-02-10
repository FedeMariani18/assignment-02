#ifndef __MESSAGE_TASK__
#define __MESSAGE_TASK__

#include "kernel\Task.h"
#include "kernel\MsgService.h"
#include "model\Context.h"
#include "model\ContextAlarm.h"


class MsgManagerTask: public Task{

public:
    MsgManagerTask(Context& context, ContextAlarm& contextAlarm, Command& command, double& distance, double& temp);
    void init(int period) override;
    void tick();

private:
    void receive();
    void send();
    Command transformMsgToCommand(Msg* msg);
    String transformStateToSring(AlarmState state);

    Context& context;
    ContextAlarm& contextAlarm;
    Command& command;
    double& distance;
    double& temp;
};

#endif
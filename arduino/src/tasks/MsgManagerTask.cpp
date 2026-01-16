#include "MsgManagerTask.h"

MsgManagerTask::MsgManagerTask(Context& context, ContextAlarm& contextAlarm, Command& command, double& distance):
    context(context), contextAlarm(contextAlarm), command(command), distance(distance){
};

void MsgManagerTask::init(int period){
    Task::init(period);
    MsgService.init();
}

void MsgManagerTask::tick(){
    receive();
    send();
}

void MsgManagerTask::receive(){
    if(MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();
        if (msg != NULL) {
            command = transformMsgToCommand(msg);
        }
    }
}

void MsgManagerTask::send() {
    static String lastMsg = "";
    String msg = "";

    msg += (contextAlarm.getAlarmState() == AlarmState::ALARM)
           ? "ALARM "
           : "NORMAL ";

    switch (context.getState()) {
        case State::DRONE_INSIDE:
            msg += "DRONE_INSIDE";
            break;
        case State::TAKE_OFF:
            msg += "TAKE_OFF" + String(distance, 2);
            break;
        case State::DRONE_OUT:
            msg += "DRONE_OUT";
            break;
        case State::LANDING:
            msg += "LANDING" + String(distance, 2);
            break;
        case State::FORCED_CLOSING:
            msg += "";
            break;
    }

    //if (msg != lastMsg) {
        MsgService.sendMsg(msg);
        lastMsg = msg;
    //}
}



Command MsgManagerTask::transformMsgToCommand(Msg* msg){
    String content = msg->getContent();

    if (content.equals("TAKE_OFF")) {
        return Command::TAKE_OFF;
    } else if (content.equals("LANDING")) {
        return Command::LANDING;
    }

    return Command::NONE; // no change
}
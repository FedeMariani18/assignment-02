#include "MsgManagerTask.h"

MsgManagerTask::MsgManagerTask(Context& context, ContextAlarm& contextAlarm, Command& command, double& distance):
    context(context), contextAlarm(contextAlarm), command(command), distance(distance){
    MsgService.init();
};

void MsgManagerTask::tick(){
    receive();
    send();
}

void MsgManagerTask::receive(){
    if(MsgService.isMsgAvailable()) {
        command = transformMsgToCommand(MsgService.receiveMsg());
    }
}

void MsgManagerTask::send(){
    String stringMsg = "";

    if(contextAlarm.getAlarmState() == AlarmState::ALARM){
        stringMsg += "ALARM ";
    } else {
        stringMsg += "NORMAL ";
    }

    switch(context.getState()){
        case State::DRONE_INSIDE:
            stringMsg += "DRONE_INSIDE ";
            break;
        case State::TAKE_OFF:
            stringMsg += "TAKE_OFF ";
            break;
        case State::DRONE_OUT:
            stringMsg += "DRONE_OUT ";
            break;
        case State::LANDING:
            stringMsg += "LANDING " + (String)distance;
            break;
    }

    MsgService.sendMsg(stringMsg);
}

Command transformMsgToCommand(Msg* msg){
    if(msg->getContent() == "TAKE_OFF"){
        return Command::TAKE_OFF;
    } else if(msg->getContent() == "LANDING"){
        return Command::LANDING;
    }
}
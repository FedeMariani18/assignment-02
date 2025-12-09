#include "DoorTask.h"

DoorTask::DoorTask(ServoMotor* motor, Context& context):
    motor(motor), context(context){

}

void DoorTask::tick(){
    switch (state) {
    case CLOSED:
        if(context.getState() == State::LANDING || context.getState() == State::TAKE_OFF){
            setState(OPENING);
        }
        break;

    case OPENING:
        motor->setPosition(90);
        
        break;

    case OPEN:
        if(context.getState() == State::DRONE_INSIDE || context.getState() == State::DRONE_OUT || 
            context.getState() == State::FORCED_CLOSING){
            setState(CLOSING);
        }
        break;

    case CLOSING:
        /* code */
        break;
    }
}
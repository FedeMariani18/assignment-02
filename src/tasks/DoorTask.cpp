#include "DoorTask.h"
#include <Arduino.h>

#define FWD_TIME 1000

DoorTask::DoorTask(ServoMotor* motor, Context& context):
    motor(motor), context(context){

}

void DoorTask::tick(){
    switch (state) {
    case CLOSE:
        if(context.getState() == State::LANDING || context.getState() == State::TAKE_OFF){
            setState(OPENING);
        }
        break;

    case OPENING:
        long dt = elapsedTimeInState();
        currentPos = (((float) dt)/FWD_TIME)*MAX_OPEN_DEGREE;
        motor->setPosition(currentPos);
        
        if(currentPos >= 90){
            setState(OPEN);
        }
        break;

    case OPEN:
        if(context.getState() == State::DRONE_INSIDE || context.getState() == State::DRONE_OUT || 
            context.getState() == State::FORCED_CLOSING){
            setState(CLOSING);
        }
        break;

    case CLOSING:
        long dt = elapsedTimeInState();
        currentPos = (((float) dt)/FWD_TIME)*MAX_OPEN_DEGREE;
        motor->setPosition(currentPos);
        
        if(currentPos <= 0){
            setState(CLOSE);
        }
        break;
    }
}
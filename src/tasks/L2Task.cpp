#include "L2Task.h"

L2Task::L2Task(Led* led, Context* context): led(led), context(context){

}

void L2Task::tick(){
    switch (context->getState()){
    case State::DRONE_INSIDE:
        led->switchOn();
        break;
    default:
        led->switchOff();
        break;
    }
}
#include "L1Task.h"

L1Task::L1Task(Led* led, Context& context): led(led), context(context){

}

void L1Task::tick(){
    switch (context.getState()){
    case State::DRONE_INSIDE:
        led->switchOn();
        break;
    default:
        led->switchOff();
        break;
    }
}
#include "L1Task.h"

L1Task::L1Task(Led* led, Context& context): led(led), context(context){

}

void L1Task::tick(){
    if(context.getState() == State::DRONE_INSIDE){
        led->switchOn();
    } else {
        led->switchOff();
    }
}
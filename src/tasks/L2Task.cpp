#include "L2Task.h"

L2Task::L2Task(Led* led, Context& context): led(led), context(context){
    setState(OFF);
}

void L2Task::tick(){
    if(context.getState() == State::LANDING || context.getState() == State::TAKE_OFF){
        switch(state){
            case ON:
                led->switchOff();
                setState(OFF);
                break;
            case OFF:
                led->switchOn();
                setState(ON);
                break;
        }
    } 
}
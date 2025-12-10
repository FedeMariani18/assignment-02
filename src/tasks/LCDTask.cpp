#include "LCDTask.h"
#include "config.h"

LCDTask::LCDTask(LiquidCrystal_I2C* lcd, Context& context, ContextAlarm& contextAlarm):
    lcd(lcd), context(context), contextAlarm(contextAlarm), lastState(State::DRONE_INSIDE){

}

void LCDTask::tick(){
    State currentState = context.getState();
    if(currentState != lastState){
        if(contextAlarm.getAlarmState() == AlarmState::ALARM){
            printString("ALARM");
            return;
        } else {
            switch(currentState){
                case State::DRONE_INSIDE:
                    printString("DRONE INSIDE");
                    break;
                case State::TAKE_OFF:
                    printString("TAKE OFF");
                    break;
                case State::DRONE_OUT:
                    printString("DRONE OUT");
                    break;
                case State::LANDING:
                    printString("LANDING");
                    break;
            }
        }
        lastState = currentState;
    }
}

void LCDTask::printString(String s){
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print(s);
}
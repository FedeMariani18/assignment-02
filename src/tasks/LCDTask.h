#ifndef __LCD_TASK__
#define __LCD_TASK__

#include <Arduino.h>
#include "kernel\Task.h"
#include "model\Context.h"
#include "model\ContextAlarm.h"
#include "LiquidCrystal_I2C.h"

class LCDTask: public Task{
    public:
        LCDTask(LiquidCrystal_I2C* lcd, Context& context, ContextAlarm& contextAlarm);
        void tick();

    private:
        Context& context;
        ContextAlarm& contextAlarm;
        LiquidCrystal_I2C* lcd;
        State lastState;
        void printString(String s);
};
#endif
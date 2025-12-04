#ifndef __DOOR_TASK__
#define __DOOR_TASK__

#include "kernel\Task.h"
#include "devices\servoMotor\ServoMotor.h"
#include "model\Context.h"

class DoorTask: public Task{

public:
    DoorTask(ServoMotor* motor, Context* context);
    void tick();

private:
    void setState(int state);

    ServoMotor* motor;
    Context* context;

    enum {CLOSED, CLOSING, OPENING, OPEN} state;
};

#endif
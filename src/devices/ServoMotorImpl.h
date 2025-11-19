#ifndef __SERVO_MOTOR_IMPL__
#define __SERVO_MOTOR_IMPL__

#include "ServoMotor.h"
#include <arduino.h>
#include "ServoTimer2.h"

class ServoMotorImpl : public ServoMotor {

private:
    int pin;
    bool _on;
    ServoTimer2 motor;


public:
    ServoMotorImpl(int pin);

    virtual void on() = 0;
    virtual void isOn() = 0;
    virtual void setPosition(int angle) = 0;
    virtual void off() = 0;
};

#endif
#include "FlowTask.h"
#include <Arduino.h>

FlowTask::FlowTask(ContextAlarm& contextAlarm, Context& context, bool& present, double& distance, Command& command):
    contextAlarm(contextAlarm), context(context), present(present), distance(distance), command(command) {

}

void FlowTask::tick() {
    switch (context.getState())
    {
        case State::DRONE_INSIDE:
            if (present == true && contextAlarm.getAlarmState() != AlarmState::ALARM && command == Command::TAKE_OFF) {
                context.setState(State::TAKE_OFF);
            }
        break;

        case State::TAKE_OFF:
            if (contextAlarm.getAlarmState() == AlarmState::ALARM) {
                context.setState(State::FORCED_CLOSING);
            }
            
            if (distance > d1) {
                if (firstTime) {
                    startTimer();
                    firstTime = false;
                } else if (elapsedTime() > t1) {
                    context.setState(State::DRONE_OUT);
                    firstTime = true;
                }
            } else {
                firstTime = true;
            }
        break;

        case State::DRONE_OUT:
            if (command == Command::LANDING) {
                context.setState(State::LANDING);
            }
        break;

        case State::LANDING:
            if (contextAlarm.getAlarmState() == AlarmState::ALARM) {
                context.setState(State::FORCED_CLOSING);
            }

            if (distance < d2) {
                if (firstTime) {
                    startTimer();
                    firstTime = false;
                } else if (elapsedTime() > t2) {
                    context.setState(State::DRONE_INSIDE);
                    firstTime = true;
                }
            } else {
                firstTime = true;
            }
        break;

        case State::FORCED_CLOSING:
            if (distance > d1) {
                if (firstTime) {
                    startTimer();
                    firstTime = false;
                } else if (elapsedTime() > t1) {
                    context.setState(State::DRONE_OUT);
                    firstTime = true;
                }
            } else if (distance < d2) {
                if (firstTime) {
                    startTimer();
                    firstTime = false;
                } else if (elapsedTime() > t2) {
                    context.setState(State::DRONE_INSIDE);
                    firstTime = true;
                }
            } else {
                firstTime = true;
            }
        break;
    }
}

void FlowTask::startTimer() {
    time = millis();
}

long FlowTask::elapsedTime() {
    return millis() - time;
}


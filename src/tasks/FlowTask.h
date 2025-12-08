#ifndef __FLOWTASK__
#define __FLOWTASK__

#include "kernel\Task.h"
#include "model\ContextAlarm.h"
#include "model\Context.h"
#include "config.h"

class FlowTask: public Task {
    public:
        FlowTask(ContextAlarm& contextAlarm, Context& context, bool& present, double& distance, Command& command);
        void tick();

    private:
        void startTimer();
        long elapsedTime();

        ContextAlarm& contextAlarm;
        Context& context;
        bool& present;
        double& distance;
        Command& command;

        long time = 0;
        bool firstTime = true;
        int d1 = 1; //da modificare
        int t1 = 1;
        int d2 = 1;
        int t2 = 1;
};

#endif
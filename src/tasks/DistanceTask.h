#ifndef __DISTANCE_TASK__
#define __DISTANCE_TASK__

#include "kernel\Task.h"
#include "devices\proximitySensor\ProximitySensor.h"
#include "model\Context.h"

class DistanceTask: public Task{

public:
    DistanceTask(ProximitySensor* proximitySensor, Context& context, double& distance);
    void tick();

private:
    ProximitySensor* proximitySensor;
    Context& context;
    double distance;
};

#endif
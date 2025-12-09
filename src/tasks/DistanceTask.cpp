#include "DistanceTask.h"

DistanceTask::DistanceTask(ProximitySensor* proximitySensor, Context& context, double& distance):
    proximitySensor(proximitySensor), context(context), distance(distance){

}

void DistanceTask::tick(){
    if(context.getState() == State::TAKE_OFF || 
    context.getState() == State::LANDING ||
    context.getState() == State::FORCED_CLOSING){
        distance = proximitySensor->getDistance();
    }
}
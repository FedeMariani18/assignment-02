#include "PresenceTask.h"

PresenceTask::PresenceTask(PresenceSensor* presenceSensor, Context& context, bool& present): 
    presenceSensor(presenceSensor), context(context), present(present){
    
}

void PresenceTask::tick(){
    if(context.getState() == State::LANDING){
        present = presenceSensor->isDetected();
    }
}
#include "Context.h"
#include "config.h"

Context::Context(){
  this->state = State::DRONE_INSIDE;
}

void Context::setState(State s){
  state = s;
}

State Context::getState(){
  return state;
}

void Context::reset(){
  state = State::DRONE_INSIDE;
}


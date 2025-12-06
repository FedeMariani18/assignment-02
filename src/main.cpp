#include <Arduino.h>
#include "kernel/Scheduler.h"
#include "model/Context.h"
#include "model/ContextAlarm.h"
#include "model/HWPlatform.h"
#include "tasks/DistanceTask.h"


Scheduler sched;
HWPlatform* hWPlatform;
Context* context;
ContextAlarm* contextAlarm;

double* distance;

void setup() {
  sched.init(PERIOD);

  hWPlatform = new HWPlatform();
  hWPlatform->init();

  context = new Context();
  contextAlarm = new ContextAlarm();

  //Task* distance = new DistanceTask(hWPlatform->getProximitySensor(), context, distance);
}

void loop() {
  sched.schedule();
}

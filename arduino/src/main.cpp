#include <Arduino.h>
#include "kernel/Scheduler.h"
#include "model/Context.h"
#include "model/ContextAlarm.h"
#include "model/HWPlatform.h"
#include "tasks/DistanceTask.h"
#include "tasks/DoorTask.h"
#include "tasks/L1Task.h"
#include "tasks/L2Task.h"
#include "tasks/L3Task.h"
#include "tasks/LCDTask.h"
#include "tasks/PresenceTask.h"
#include "tasks/TemperatureAlarmTask.h"
#include "tasks/TempTask.h"
#include "tasks/FlowTask.h"
#include "tasks/MsgManagerTask.h"


Scheduler sched;
HWPlatform* hWPlatform;
Context context;
ContextAlarm contextAlarm;

double distanceValue;
bool dronePresence;
double tempValue;
Command command;

void setup() {
  sched.init(PERIOD);

  hWPlatform = new HWPlatform();
  hWPlatform->init();

  Task* msgManagerTask = new MsgManagerTask(context, contextAlarm, command, distanceValue, tempValue);
  msgManagerTask->init(MESSAGE_MANAGER_TASK_PERIOD);
  
  Task* flowtask = new FlowTask(contextAlarm, context, dronePresence, distanceValue, command);
  flowtask->init(FLOW_TASK_PERIOD);

  Task* distanceTask = new DistanceTask(hWPlatform->getProximitySensor(), context, distanceValue);
  distanceTask->init(DISTANCE_TASK_PERIOD);

  Task* doorTask = new DoorTask(hWPlatform->getMotor(), context);
  doorTask->init(DOOR_TASK_PERIOD);

  Task* l1Task = new L1Task(hWPlatform->getLed1(), context);
  l1Task->init(L1_TASK_PERIOD);

  Task* l2Task = new L2Task(hWPlatform->getLed2(), context);
  l2Task->init(L2_TASK_PERIOD);

  Task* l3Task = new L3Task(hWPlatform->getLed3(), contextAlarm);
  l3Task->init(L3_TASK_PERIOD);

  Task* presenceTask = new PresenceTask(hWPlatform->getPresenceSensor(), context, dronePresence);
  presenceTask->init(PRESENCE_TASK_PERIOD);

  Task* tempTask = new TempTask(hWPlatform->getTempSensor(), contextAlarm, tempValue);
  tempTask->init(TEMP_TASK_PERIOD);

  Task* temperatureAlarmTask = new TemperatureAlarmTask(contextAlarm, context, tempValue, hWPlatform->getResetButton());
  temperatureAlarmTask->init(TEMPERATURE_ALARM_TASK_PERIOD);

  Task* lcdTask = new LCDTask(hWPlatform->getLcd(), context, contextAlarm);
  lcdTask->init(LCD_TASK_PERIOD);

  sched.addTask(msgManagerTask);
  sched.addTask(flowtask);
  sched.addTask(distanceTask);
  sched.addTask(doorTask);  
  sched.addTask(l1Task);
  sched.addTask(l2Task);
  sched.addTask(l3Task);
  sched.addTask(presenceTask);
  sched.addTask(tempTask);
  sched.addTask(temperatureAlarmTask);
  sched.addTask(lcdTask);
}

void loop() {
  sched.schedule();
}
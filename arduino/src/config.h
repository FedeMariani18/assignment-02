#ifndef __CONFIG__
#define __CONFIG__

#define BT_PIN 3
#define LED1_PIN 6
#define LED2_PIN 5
#define RED_LED_PIN 4
#define MOTOR_PIN 9
#define PIR_PIN 2
#define SONAR_ECHO_PIN 7
#define SONAR_TRIG_PIN 8
#define SONAR_TIMEOUT 1
#define TEMP_PIN A0

#define LCD_ADRR 0x27
#define LCD_COLS 16
#define LCD_ROWS 2

#define T1 200
#define T2 200
#define T3 1000
#define T4 1000

#define TEMP1 20
#define TEMP2 24

#define PERIOD 10
#define FLOW_TASK_PERIOD 20
#define TEMPERATURE_ALARM_TASK_PERIOD 100
#define TEMP_TASK_PERIOD 200
#define L1_TASK_PERIOD 250
#define L2_TASK_PERIOD 500
#define L3_TASK_PERIOD 250
#define DISTANCE_TASK_PERIOD 50
#define PRESENCE_TASK_PERIOD 100
#define DOOR_TASK_PERIOD 50
#define LCD_TASK_PERIOD 250
#define MESSAGE_MANAGER_TASK_PERIOD 250

#define D1 1
#define D2 1

enum class State {
    DRONE_INSIDE,
    TAKE_OFF,
    DRONE_OUT,
    LANDING,
    FORCED_CLOSING
};

enum class AlarmState {
    NORMAL_OUT,
    NORMAL,
    PRE_ALARM,
    ALARM
};

enum class Command {
    TAKE_OFF,
    LANDING,
    NONE,
};

#endif
#define BT_PIN 0
#define LED1_PIN 0
#define LED2_PIN 0
#define RED_LED_PIN 0
#define MOTOR_PIN 0
#define PIR_PIN 0
#define SONAR_ECHO_PIN 0
#define SONAR_TRIG_PIN 0
#define SONAR_TIMEOUT 0
#define TEMP_PIN 0

#define LCD_ADRR 0
#define LCD_COLS 0
#define LCD_ROWS 0

#define T1 200
#define T2 200
#define T3 1000
#define T4 1000

#define TEMP1 20
#define TEMP2 24

#define PERIOD 50
#define DISTANCE_PERIOD 0

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
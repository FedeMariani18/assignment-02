#define BT_PIN 0
#define LED_PIN 0
#define MOTOR_PIN 0
#define PIR_PIN 0
#define SONAR_ECHO_PIN 0
#define SONAR_TRIG_PIN 0
#define SONAR_TIMEOUT 0
#define TEMP_PIN 0

#define LCD_ADRR 0
#define LCD_COLS 0
#define LCD_ROWS 0

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
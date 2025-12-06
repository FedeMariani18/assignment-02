#include <Arduino.h>
#include "HWPlatform.h"
#include "devices/button/ButtonImpl.h"
#include "devices/led/Led.h"
#include "devices/servoMotor/ServoMotorImpl.h"
#include "devices/presenceSensor/Pir.h"
#include "devices/proximitySensor/Sonar.h"
#include "devices/tempSensor/TempSensorLM35.h"

void wakeUp(){}

HWPlatform::HWPlatform(){
  resetButton = new ButtonImpl(BT_PIN);
  led1 = new Led(LED1_PIN);
  led2 = new Led(LED2_PIN);
  led3 = new Led(RED_LED_PIN);
  motor = new ServoMotorImpl(MOTOR_PIN);
  presenceSensor = new Pir(PIR_PIN);
  proximitySensor = new Sonar(SONAR_ECHO_PIN, SONAR_TRIG_PIN, SONAR_TIMEOUT);
  tempSensor = new TempSensorLM35(TEMP_PIN);
  lcd = new LiquidCrystal_I2C(LCD_ADRR, LCD_COLS, LCD_ROWS);
}

void HWPlatform::init(){}

Button* HWPlatform::getResetButton(){
  return resetButton;
}

Led* HWPlatform::getLed1(){
  return led1;
}

Led* HWPlatform::getLed2(){
  return led2;
}

Led* HWPlatform::getLed3(){
  return led3;
}

ServoMotor* HWPlatform::getMotor(){
  return motor;
}

PresenceSensor* HWPlatform::getPresenceSensor(){
  return presenceSensor;
}

ProximitySensor* HWPlatform::getProximitySensor(){
  return proximitySensor;
}

TempSensor* HWPlatform::getTempSensor(){
  return tempSensor;
}

LiquidCrystal_I2C* HWPlatform::getLcd(){
  return lcd;
}

void HWPlatform::test(){}

// void HWPlatform::test(){
//   bool btPressed = pButton->isPressed();
//   pLed->switchOn();
//   pMotor->on();
//   pMotor->setPosition(90);
//   Logger.log("Button: " + String(btPressed ? "pressed" : " not pressed"));
//   delay(1000);
//   pMotor->setPosition(0);
//   delay(1000);
//   pMotor->off();
//   pLed->switchOff();
// }


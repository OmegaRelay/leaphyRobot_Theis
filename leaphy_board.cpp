#include "leaphy_board.h"
#include <Arduino.h>


/**** Local Function Prototypes ****/

/************ Typedefs *************/
/******** Public Functions *********/

void board_init() {
  //Outputs
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  pinMode(US_TRIG_PIN, OUTPUT);

  pinMode(MOTOR_LEFT_SPD_PIN, OUTPUT);
  pinMode(MOTOR_RIGHT_SPD_PIN, OUTPUT);
  pinMode(MOTOR_LEFT_DIR_PIN, OUTPUT);
  pinMode(MOTOR_RIGHT_DIR_PIN, OUTPUT);

  //inputs
  pinMode(US_ECHO_PIN, INPUT);

  //Start value
  digitalWrite(BLUE_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);

  digitalWrite(US_TRIG_PIN, LOW);

  digitalWrite(MOTOR_LEFT_SPD_PIN, LOW);
  digitalWrite(MOTOR_RIGHT_SPD_PIN, LOW);
  digitalWrite(MOTOR_LEFT_DIR_PIN, LOW);
  digitalWrite(MOTOR_RIGHT_DIR_PIN, LOW);
}

int board_getPinValue(bool type, uint8_t pin){
  int retVal = -5;
  
  if (type == ANALOG){
    retVal = analogRead(pin);
  } else if (type == DIGITAL){
    retVal = digitalRead(pin);
  }
  return retVal;
}

bool board_setPin(bool type, uint8_t pin, int value){
  if (type == ANALOG){
    analogWrite(pin, value);
    return 0;
  } else if (type == DIGITAL){
    digitalWrite(pin, value);
    return 0;
  }
  return 1;
}

bool board_setLeds(bool red, bool green, bool blue){
  digitalWrite(RED_LED_PIN, (uint8_t) red);
  digitalWrite(GREEN_LED_PIN, (uint8_t) green);
  digitalWrite(BLUE_LED_PIN, (uint8_t) blue);

  return 0;
}
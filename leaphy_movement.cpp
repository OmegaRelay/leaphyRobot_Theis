#include "leaphy_movement.h"
#include <Arduino.h>

#include "DEBUG.h"

/********* Local Variables *********/
static move_t currentDir = MOVE_NONE;
static move_t previousDir = MOVE_NONE;

/**** Local Function Prototypes ****/
void moveMotor(bool leftDir, bool rightDir, int speed);


/******** Public Functions *********/
void movementStop() {
  currentDir = MOVE_NONE;
  moveMotor(FORWARD, FORWARD, 0);
}

void movementForwardSpeed(int speed) {
  currentDir = MOVE_FORWARD;
  moveMotor(FORWARD, FORWARD, speed);
}

void movementReverse() {
  currentDir = MOVE_BACKWARD;
  moveMotor(BACKWARD, BACKWARD, SPEED_SLOW);
}

bool movementTurn(move_t dir) {
  currentDir = dir;
  if (dir == MOVE_LEFT) {
    moveMotor(BACKWARD, FORWARD, SPEED_SLOW);
  } else if (dir == MOVE_RIGHT) {
    moveMotor(FORWARD, BACKWARD, SPEED_SLOW);
  } else {
    moveMotor(0, 0, 0);
    return 1;
  }
  return 0;
}

/********* Local Functions *********/
void moveMotor(bool leftDir, bool rightDir, int speed) {
  board_setPin(DIGITAL, MOTOR_LEFT_DIR_PIN, leftDir);
  board_setPin(DIGITAL, MOTOR_RIGHT_DIR_PIN, rightDir);

  if (speed > 0) {
    if (currentDir != previousDir) {
      //drive the motors with high PWM for high torque
      board_setPin(ANALOG, MOTOR_LEFT_SPD_PIN, MAX_MOTOR_SPEED);
      board_setPin(ANALOG, MOTOR_RIGHT_SPD_PIN, MAX_MOTOR_SPEED);
      delay(30);
      previousDir = currentDir;
    }
  } else
    previousDir = MOVE_NONE;


  board_setPin(ANALOG, MOTOR_LEFT_SPD_PIN, speed);
  board_setPin(ANALOG, MOTOR_RIGHT_SPD_PIN, speed);
}
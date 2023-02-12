#include "leaphy_movement.h"
#include "leaphy_board.h"

/**** Local Function Prototypes ****/
void moveMotor(bool leftDir, bool rightDir, short speed);


/******** Public Functions *********/
void movementStop(){
  moveMotor(FORWARD, FORWARD, 0);
}

void movementSpin(){
  moveMotor(FORWARD, BACKWARD, 20);
}

void movementForwardSpeed(unsigned short speed) {
  if (speed <= 255) {
    moveMotor(FORWARD, FORWARD, speed);
  }
}

void movementForwardUntil(trigger_t trigger) {
  moveMotor(FORWARD, FORWARD, MAX_MOTOR_SPEED / 4);
}

bool movementTurn45(turn_t dir) {

  if (dir = TURN_LEFT) {
    moveMotor(BACKWARD, FORWARD, MAX_MOTOR_SPEED / 4);
  } else if (dir = TURN_RIGHT) {
    moveMotor(FORWARD, BACKWARD, MAX_MOTOR_SPEED / 4);
  } else {
    moveMotor(0, 0, 0);
    return 1;
  }

  delay(250);

  moveMotor(0, 0, 0);

  return 0;
}

void movementReverse() {
  moveMotor(BACKWARD, BACKWARD, MAX_MOTOR_SPEED / 4);
}

bool movementTurn(turn_t dir) {
  if (dir = TURN_LEFT) {
    moveMotor(BACKWARD, FORWARD, MAX_MOTOR_SPEED / 4);
  } else if (dir = TURN_RIGHT) {
    moveMotor(FORWARD, BACKWARD, MAX_MOTOR_SPEED / 4);
  } else {
    moveMotor(0, 0, 0);
    return 1;
  }
  return 0;
}

/********* Local Functions *********/
void moveMotor(bool leftDir, bool rightDir, short speed) {
  board_setPin(DIGITAL, MOTOR_LEFT_DIR_PIN, leftDir);
  board_setPin(DIGITAL, MOTOR_RIGHT_DIR_PIN, rightDir);

  if (speed > 0) {
    //drive the motors with high PWM for high torque
    board_setPin(ANALOG, MOTOR_LEFT_SPD_PIN, MAX_MOTOR_SPEED);
    board_setPin(ANALOG, MOTOR_RIGHT_SPD_PIN, MAX_MOTOR_SPEED);
    delay(20);
  }

  board_setPin(ANALOG, MOTOR_LEFT_SPD_PIN, speed);
  board_setPin(ANALOG, MOTOR_RIGHT_SPD_PIN, speed);
}
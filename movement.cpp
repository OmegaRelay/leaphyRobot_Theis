#include "movement.h"

void moveMotor(bool leftDir, bool rightDir, short speed);

void movementForwardUntil(trigger_t trigger) {
  moveMotor(FORWARD, FORWARD, MAX_MOTOR_SPEED/4);
}

bool movementTurn45(turn_t dir) {

  if (dir = TURN_LEFT) {
    moveMotor(BACKWARD, FORWARD, MAX_MOTOR_SPEED/4);
  } else if (dir = TURN_RIGHT) {
    moveMotor(FORWARD, BACKWARD, MAX_MOTOR_SPEED/4);
  }  else {
    moveMotor(0, 0, 0);
    return 1;
  }

  delay(250);

  moveMotor(0, 0, 0);

  return 0;
}

void movementReverse() {
  moveMotor(BACKWARD, BACKWARD, MAX_MOTOR_SPEED/4);
}

void moveMotor(bool leftDir, bool rightDir, short speed) {
  if (speed != 0) {
    //drive the motors with high PWM for high torque
    analogWrite(MOTOR_LEFT_PWM_PIN, MAX_MOTOR_SPEED);
    analogWrite(MOTOR_RIGHT_PWM_PIN, MAX_MOTOR_SPEED);
    delay(20);
  }
  
  analogWrite(MOTOR_LEFT_PWM_PIN, speed);
  analogWrite(MOTOR_RIGHT_PWM_PIN, speed);
}
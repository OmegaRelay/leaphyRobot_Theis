#include "movement.h"

void moveMotor(short speed);

void movementForwardUntil(trigger_t trigger) {
  digitalWrite(MOTOR_LEFT_DIR_PIN, HIGH);
  digitalWrite(MOTOR_RIGHT_DIR_PIN, HIGH);

  moveMotor(MAX_MOTOR_SPEED/4);
}

void movementTurn45(turn_t dir) {
  if (dir = TURN_LEFT) {
    digitalWrite(MOTOR_LEFT_DIR_PIN, BACKWARD);
    digitalWrite(MOTOR_RIGHT_DIR_PIN, FORWARD);
  } else if (dir = TURN_RIGHT) {
    digitalWrite(MOTOR_LEFT_DIR_PIN, FORWARD);
    digitalWrite(MOTOR_RIGHT_DIR_PIN, BACKWARD);
  }  //else error("error: incorrect turn direction passed to movementTurn function");


  moveMotor(MAX_MOTOR_SPEED/4);
  //convert angle to milliseconds
  // double angleTime = (double)angle / DEGREES_PER_SECOND;
  // Serial.println(angleTime);
  delay(250);

  moveMotor(0);
}

void movementReverse() {
}

void moveMotor(short speed) {
  if (speed != 0) {
    //drive the motors with high PWM for high torque
    analogWrite(MOTOR_LEFT_PWM_PIN, MAX_MOTOR_SPEED);
    analogWrite(MOTOR_RIGHT_PWM_PIN, MAX_MOTOR_SPEED);
    delay(20);
  }
  
  analogWrite(MOTOR_LEFT_PWM_PIN, speed);
  analogWrite(MOTOR_RIGHT_PWM_PIN, speed);
}
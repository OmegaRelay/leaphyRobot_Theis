#include "movement.h"

void movementForwardUntil(trigger_t trigger) {
  digitalWrite(MOTOR_LEFT_DIR_PIN, HIGH);
  digitalWrite(MOTOR_RIGHT_DIR_PIN, HIGH);
}

void movementTurn45(turn_t dir) {
  if (dir = TURN_LEFT) {
    digitalWrite(MOTOR_LEFT_DIR_PIN, BACKWARD);
    digitalWrite(MOTOR_RIGHT_DIR_PIN, FORWARD);
  } else if (dir = TURN_RIGHT) {
    digitalWrite(MOTOR_LEFT_DIR_PIN, FORWARD);
    digitalWrite(MOTOR_RIGHT_DIR_PIN, BACKWARD);
  } //else error("error: incorrect turn direction passed to movementTurn function");


  analogWrite(MOTOR_LEFT_PWM_PIN, MAX_MOTOR_SPEED/2);
  analogWrite(MOTOR_RIGHT_PWM_PIN, MAX_MOTOR_SPEED/2);
  //convert angle to milliseconds
  // double angleTime = (double)angle / DEGREES_PER_SECOND;
  // Serial.println(angleTime);
  delay(200);

  analogWrite(MOTOR_LEFT_PWM_PIN, 0);
  analogWrite(MOTOR_RIGHT_PWM_PIN, 0);
  
}

void movementReverse(){
  

}

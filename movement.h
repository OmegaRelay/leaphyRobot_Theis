/**
 * Movement driver is to modularize leaphy movements
 * 
 */
#include<arduino.h>

/*********** Definitions ***********/

#define MOTOR_LEFT_DIR_PIN 12
#define MOTOR_RIGHT_DIR_PIN 13
#define MOTOR_LEFT_PWM_PIN 10
#define MOTOR_RIGHT_PWM_PIN 11

#define FORWARD HIGH
#define BACKWARD LOW
#define MAX_MOTOR_SPEED 255
#define DEGREES_PER_SECOND 450
//363.64

typedef enum {
  TURN_LEFT = 0,
  TURN_RIGHT = 1,
} turn_t;

typedef enum {
  TRIGGER_ULTRASOUND,
} trigger_t;


/*********** Functions Prototypes ************/

/**
 * @brief motorForwardUntil() moves the robot forward until a trigger
 */
 void movementForwardUntil(trigger_t trigger);

 /**
  * @brief motorturn() drives the wheel motors in opposite directions to turn the robot
  * 
  * @param dir a direction_t type indicating direction to turn
  * @param angle a 16-bit variale for how much to turn in degrees
  */
bool movementTurn45(turn_t dir);

/**
 * 
 */
 void movementReverse();

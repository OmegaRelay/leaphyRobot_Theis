/**
 * Movement driver is to modularize leaphy movements
 * 
 */
#include<arduino.h>

/*********** Definitions ***********/
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


/****** Public Functions APIs ******/
/**
 * @brief motorStop() stops the movement
 */
void movementStop();

void movementSpin();

/**
 * @brief motorForwardSpeed() moves the robot forward at speed
 */
void movementForwardSpeed(unsigned short speed);

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

/**
 * 
 */
bool movementTurn(turn_t dir);
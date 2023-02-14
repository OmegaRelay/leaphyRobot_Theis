/**
 * Movement driver is to modularize leaphy movements
 * 
 */
#include "leaphy_board.h"

/*********** Definitions ***********/
#define FORWARD HIGH
#define BACKWARD LOW
#define MAX_MOTOR_SPEED 255
#define DEGREES_PER_SECOND 450

#define SPEED_FAST 72
#define SPEED_SLOW 50

typedef enum {
  MOVE_LEFT = 0,
  MOVE_RIGHT = 1,
  MOVE_FORWARD = 2,
  MOVE_BACKWARD = 3,
  MOVE_STOP = 4, 
  MOVE_NONE = 5
} move_t;

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
void movementForwardSpeed(int speed);

/**
 * 
 */
void movementReverse();

/**
 * 
 */
bool movementTurn(move_t dir);
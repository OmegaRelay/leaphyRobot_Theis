/**
 * leaphy_sensor.h contains all API calls for the sensors on the board, as well as handles detection task
 * 
 */

/*********** Definitions ***********/
#define LEFT    0
#define RIGHT   1
#define SUCCESS 0
#define FAIL    1

#define OBSTACLE_NONE       0
#define OBSTACLE_CLOSE      1
#define OBSTACLE_VERY_CLOSE 2

// #define LINE_TRACK_RIGHT  1
// #define LINE_TRACK_LEFT   2

#define TRACK_BOTH_BLACK  3
#define TRACK_LEFT_BLACK 1
#define TRACK_RIGHT_BLACK  2
#define TRACK_BOTH_WHITE  0

#define NO_GUIDANCE 0
#define LEFT_GUIDANCE 1
#define RIGHT_GUIDANCE 2


/************ Typedefs *************/
/****** Public Functions APIs ******/

void obstacleDetectionTask(void* pvParameters);

void lineDetectionTask(void* pvParameters);

unsigned short sensor_obstacleDetected();

/**
 * @brief
 * @param side of the car of which to get the ldr value
 *
 * @return value of the requested ldr
 */
unsigned short sensor_getLdrValue(bool side);

/**
 * @brief compares the values of the two LDRs
 *
 * @return 0 if the within the sensitivity range, 1 if not 
 */
unsigned short sensor_getLdrRelativeStatus();

/**
 * @brief gets the status of the line tracker
 *
 * @return Two bits where the least significant bit is the right tracker and the second least sig is the left
 */
unsigned short sensor_getLineStatus();

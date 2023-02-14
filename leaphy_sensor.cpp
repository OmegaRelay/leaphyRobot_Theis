/************ Includes *************/
#include "leaphy_sensor.h"

#include <Arduino_FreeRTOS.h>
#include <HCSR04.h>
#include "leaphy_board.h"

#include "DEBUG.h"

#define OBSTACLE_TIME_PERIOD 60
#define LINE_TIME_PERIOD 15

//the value between 0 and 511 setting the range for the LDR comparison
#define LDR_TOLERANCE 500

#if LDR_TOLERANCE > 511 || LDR_TOLERANCE <= 0
#error ldr tolerence out of range please please choose a value between 0 and 511 
#endif


/********* Local Variables *********/
static unsigned long distanceVal = 0;
static unsigned short lineStatus = 0;
static unsigned short ldrRelativeStatus = 0;

/**** Local Function Prototypes ****/
void sensor_updateLineStatus();
void sensor_updateLdrStatus();

/******** Public Functions *********/
void obstacleDetectionTask(void* pvParameters) {
  HCSR04 hc(US_TRIG_PIN, US_ECHO_PIN);

  while (1) {
    //update ultrasonic sensor
    distanceVal = hc.dist();
    vTaskDelay(OBSTACLE_TIME_PERIOD / portTICK_PERIOD_MS);
  }
}

void lineDetectionTask(void* pvParameters) {
  while (1) {
    //update line sensor
    sensor_updateLineStatus();
    sensor_updateLdrStatus();
    vTaskDelay(LINE_TIME_PERIOD  / portTICK_PERIOD_MS);
  }
}


unsigned short sensor_obstacleDetected() {
  if (distanceVal > 25)
    return OBSTACLE_NONE;
  if (distanceVal > 15)
    return OBSTACLE_CLOSE;
  return OBSTACLE_VERY_CLOSE;
}

unsigned short sensor_getLdrValue(bool side) {
  int ldrValue = 0;
  if (side == LEFT) {
    ldrValue = board_getPinValue(ANALOG, LDR_LEFT_PIN);
  } else if (side == RIGHT) {
    int ldrValue = board_getPinValue(ANALOG, LDR_RIGHT_PIN);
  }
  return ldrValue;
}

unsigned short sensor_getLdrRelativeStatus() {
  return ldrRelativeStatus;
}

unsigned short sensor_getLineStatus(){
    return lineStatus;
}

/********* Local Functions *********/

void sensor_updateLineStatus(){
  int rightTrackVal = board_getPinValue(ANALOG, TRACKSENSE_RIGHT_PIN);
  int leftTrackVal = board_getPinValue(ANALOG, TRACKSENSE_LEFT_PIN);

  if (rightTrackVal <= 500) //black surface
    lineStatus |= 1;
  else 
    lineStatus &= 2;
  if (leftTrackVal <= 500)
    lineStatus |= 2;
  else 
    lineStatus &= 1;
}

void sensor_updateLdrStatus(){
  int ldrLeftValue = board_getPinValue(ANALOG, LDR_LEFT_PIN);
  int ldrRightValue = board_getPinValue(ANALOG, LDR_RIGHT_PIN);


  if (ldrLeftValue >= (ldrRightValue + LDR_TOLERANCE))
    ldrRelativeStatus = 2;
  else if (ldrLeftValue <= (ldrRightValue - LDR_TOLERANCE))
    ldrRelativeStatus = 1;
  else 
    ldrRelativeStatus = 0;
  DEBUG_PRINTLN(ldrRelativeStatus);
}
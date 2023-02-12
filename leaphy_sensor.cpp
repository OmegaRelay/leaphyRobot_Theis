/************ Includes *************/
#include "leaphy_sensor.h"

#include <Arduino_FreeRTOS.h>
#include <HCSR04.h>
#include "leaphy_board.h"


/********* Local Variables *********/
static unsigned long distanceVal = 0;
static bool leftLineStatus = 0;
static bool rightLineStatus = 0;

/**** Local Function Prototypes ****/
void sensor_updateDistance(HCSR04 *instance);
void sensor_updateLineStatus();

/******** Public Functions *********/
void detectionTask(void* pvParameters) {
  HCSR04 hc(US_TRIG_PIN, US_ECHO_PIN);
  static bool redState = 0;
  static bool greenState = 0;
  static bool blueState = 0;


  while (1) {

    //line following

    if (distanceVal < 20) {
      if (distanceVal < 10) {
        redState = 1;
        greenState = 0;
        blueState = 0;
      } else {
        redState = 1;
        greenState = 1;
        blueState = 0;
      }
    } else {
      redState = 0;
      greenState = 1;
      blueState = 0;
    }
    board_setLeds(redState, greenState, blueState);
    sensor_updateDistance(&hc);
    sensor_updateLineStatus();
    vTaskDelay(60 / portTICK_PERIOD_MS);
  }
}

unsigned short sensor_obstacleDetected() {
  if (distanceVal > 20)
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

unsigned int sensor_compareLdrValues(unsigned short sensitivityRange) {
  int ldrLeftValue = board_getPinValue(ANALOG, LDR_LEFT_PIN);
  int ldrRightValue = board_getPinValue(ANALOG, LDR_RIGHT_PIN);
  unsigned short halfRange = sensitivityRange / 2;


  if (ldrLeftValue <= (ldrRightValue + halfRange) && ldrLeftValue >= (ldrRightValue - halfRange)) {
    return SUCCESS;
  }
  return FAIL;
}

unsigned short sensor_getLineStatus(){
    unsigned short retVal = (leftLineStatus<<1);
    retVal |= rightLineStatus;
    Serial.println(retVal);
    return retVal;
}

/********* Local Functions *********/
void sensor_updateDistance(HCSR04 *instance) {
  distanceVal = instance->dist();
}

void sensor_updateLineStatus(){
  int rightTrackVal = board_getPinValue(ANALOG, TRACKSENSE_RIGHT_PIN);
  int leftTrackVal = board_getPinValue(ANALOG, TRACKSENSE_LEFT_PIN);

  // Serial.print(rightTrackVal);
  // Serial.print(F("\t"));
  // Serial.println(leftTrackVal);

  rightLineStatus = 0;
  leftLineStatus = 0;

  if (rightTrackVal <= 500) //black surface
    rightLineStatus = 1;
  if (leftTrackVal <= 500)
    leftLineStatus = 1;
}
#include <Arduino_FreeRTOS.h>
#include <Arduino.h>

#include "DEBUG.h"

#include "leaphy_main.h"
#include "leaphy_sensor.h"
#include "leaphy_board.h"

void setup() {

#ifdef DEBUG_MESSAGES
  Serial.begin(9600);
#endif

  //initialize the board and pins
  DEBUG_PRINTLN(F("Initializing board"));
  board_init();

  /* Create two tasks with priorities 1 and 2. An idle task is also created, 
     which will be run when there are no tasks in RUN state */

  xTaskCreate(obstacleDetectionTask, "obstacleDetectionTask", 100, NULL, 1, NULL);
  xTaskCreate(lineDetectionTask, "lineDetectionTask", 100, NULL, 1, NULL);
  xTaskCreate(mainTask, "mainTask", 300, NULL, 2, NULL);
  xTaskCreate(MyIdleTask, "IdleTask", 100, NULL, 0, NULL);  //todo do i need this?
}


void loop() {
  // DO nothing
}



/* Idle Task with priority Zero */
static void MyIdleTask(void* pvParameters) {
  while (1) {
    //Serial.println(F("Idle state"));
    //delay(50);
  }
}

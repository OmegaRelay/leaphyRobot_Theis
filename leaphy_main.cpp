#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "leaphy_main.h"
#include "leaphy_sensor.h"
#include "leaphy_movement.h"

void mainTask(void* pvParameters) {
  while (1) {

    static bool obstacleDetected = sensor_obstacleDetected();

    static unsigned short trackStatus = sensor_getLineStatus();

    switch (obstacleDetected) {
      case OBSTACLE_NONE:
        switch (trackStatus){
          case TRACK_BOTH_BLACK:
            movementStop();
            break;

          case TRACK_RIGHT_BLACK:
            movementTurn(TURN_LEFT);
            break;

          case TRACK_LEFT_BLACK:
            movementTurn(TURN_RIGHT);
            break;
          case TRACK_BOTH_WHITE:
            movementForwardSpeed(100);
            break;

          default:
            movementTurn(TURN_LEFT);
            break;
        }
        break;
      case OBSTACLE_CLOSE:
        // movementStop();
        // vTaskDelay(100 / portTICK_PERIOD_MS);
        // movementTurn45(TURN_LEFT);
        // vTaskDelay(100 / portTICK_PERIOD_MS);
        // movementTurn45(TURN_LEFT);
        break;

      case OBSTACLE_VERY_CLOSE:
      default:
        movementTurn(TURN_LEFT);
        break;
    }
    vTaskDelay(60 / portTICK_PERIOD_MS);
  }
}
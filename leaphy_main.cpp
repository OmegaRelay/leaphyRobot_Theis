#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "leaphy_main.h"
#include "leaphy_sensor.h"
#include "leaphy_movement.h"
#include "leaphy_notify.h"

#include "DEBUG.h"

#define MAIN_TIME_PERIOD 30

void mainTask(void* pvParameters) {

  static unsigned short trackStatus = 0;
  static unsigned short obstacleDetected = 0;
  static unsigned short ldrRelativeStatus = 0;

  while (1) {

    obstacleDetected = sensor_obstacleDetected();

    trackStatus = sensor_getLineStatus();

    ldrRelativeStatus = sensor_getLdrRelativeStatus();

    switch (ldrRelativeStatus) {
      case NO_GUIDANCE:
        switch (trackStatus) {
          case TRACK_BOTH_WHITE:
            switch (obstacleDetected) {
              case OBSTACLE_NONE:
                notifyGreen();
                movementForwardSpeed(SPEED_FAST);
                break;
              case OBSTACLE_CLOSE:
                notifyYellow();
                movementForwardSpeed(SPEED_SLOW);
                break;

              case OBSTACLE_VERY_CLOSE:
                notifyRed();
                movementStop();
                break;

              default:
                notifyRed();
                movementStop();
                break;
            }
            break;

          case TRACK_BOTH_BLACK:
            notifyPurple();
            movementStop();
            break;

          case TRACK_RIGHT_BLACK:
            notifyBlue();
            movementTurn(MOVE_RIGHT);
            break;

          case TRACK_LEFT_BLACK:
            notifyBlue();
            movementTurn(MOVE_LEFT);
            break;

          default:
            movementStop();
            break;
        }
        break;
      case LEFT_GUIDANCE:
        notifyYellow();
        movementTurn(MOVE_LEFT);
        break;

      case RIGHT_GUIDANCE:
        notifyYellow();
        movementTurn(MOVE_RIGHT);
        break;
      default:
        movementStop();
        break;
    }

    vTaskDelay(MAIN_TIME_PERIOD / portTICK_PERIOD_MS);
  }
}
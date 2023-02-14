#include "leaphy_notify.h"
#include "leaphy_board.h"

#include "DEBUG.h"

void notifyBlue(){
  board_setPin(DIGITAL, RED_LED_PIN, LOW);
  board_setPin(DIGITAL, GREEN_LED_PIN, LOW);
  board_setPin(DIGITAL, BLUE_LED_PIN, HIGH);
}

void notifyGreen(){
  board_setPin(DIGITAL, RED_LED_PIN, LOW);
  board_setPin(DIGITAL, GREEN_LED_PIN, HIGH);
  board_setPin(DIGITAL, BLUE_LED_PIN, LOW);
}

void notifyYellow(){
  board_setPin(ANALOG, RED_LED_PIN, 190);
  board_setPin(ANALOG, GREEN_LED_PIN, 63);
  board_setPin(DIGITAL, BLUE_LED_PIN, LOW);
}

void notifyRed(){
  board_setPin(DIGITAL, RED_LED_PIN, HIGH);
  board_setPin(DIGITAL, GREEN_LED_PIN, LOW);
  board_setPin(DIGITAL, BLUE_LED_PIN, LOW);
}

void notifyPurple(){
  board_setPin(DIGITAL, RED_LED_PIN, HIGH);
  board_setPin(DIGITAL, GREEN_LED_PIN, LOW);
  board_setPin(ANALOG, BLUE_LED_PIN, 63);
}
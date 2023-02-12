/**
 * author: Theis Mejnertsen
 * 
 */
/************ Includes *************/
#include <stdint.h>


/*********** Definitions ***********/
//Pins
#define BLUE_LED_PIN          3
#define GREEN_LED_PIN         5
#define RED_LED_PIN           6

#define BUZZER_PIN            4

#define US_TRIG_PIN           7
#define US_ECHO_PIN           8

#define TRACKSENSE_RIGHT_PIN  A0
#define TRACKSENSE_LEFT_PIN   A1

#define LDR_RIGHT_PIN         A2
#define LDR_LEFT_PIN          A3

#define MOTOR_LEFT_SPD_PIN    10
#define MOTOR_RIGHT_SPD_PIN   11
#define MOTOR_LEFT_DIR_PIN    12
#define MOTOR_RIGHT_DIR_PIN   13

#define ANALOG  0
#define DIGITAL 1

/************ Typedefs *************/
/****** Public Functions APIs ******/

void board_init();

int board_getPinValue(bool type, uint8_t pin);

bool board_setPin(bool type, uint8_t pin, int value);

bool board_setLeds(bool red, bool green, bool blue);
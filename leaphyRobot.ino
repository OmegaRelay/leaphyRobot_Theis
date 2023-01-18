#include "movement.h"


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  Serial.println("Tracker_Left, Tracker_Right, LDR_Left, LDR_Right");
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int trackLeftValue = analogRead(A0);
  int trackRightValue = analogRead(A1);
  int ldrLeftValue = analogRead(A2);
  int ldrRightValue = analogRead(A3);
  // print out the value you read:
//  Serial.print(trackLeftValue);
  // Serial.print(",");
//  Serial.print(trackRightValue);
  // Serial.print(",");
  // Serial.print(ldrLeftValue);
  // Serial.print(",");
  // Serial.println(ldrRightValue);
  movementTurn45(TURN_LEFT);
  
  delay(1000);  // delay in between reads for stability
}

//void error(string err_msg){
//  Serial.println (err_msg);
//  Serial.flush ();
//  exit (1);
//}

/* 
 
Ringo Robot
Code for teh Square movement of the robot. 
Code written by Raksharth Choudhary
My.UNL ID: rchoudhary3

*/

#include <Arduino_FreeRTOS.h>
#include "RingoHardware.h"

// define two tasks for Moving Forward & Turning Right.
void TaskMoveForward(void);
void TaskTurnRight(void);

// the setup function runs once when you press reset or power the board
void setup(){
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  }

  // Now set up two tasks to run independently.
  xTaskCreate(
    TaskTurnRight
    ,  (const portCHAR *)"TurnRight"   // A name just for humans
    ,  128                             // This stack size
    ,  NULL
    ,  1                               // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL );

  xTaskCreate(
    TaskMoveForward
    ,  (const portCHAR *) "MoveForward"
    ,  128  // Stack size
    ,  NULL
    ,  2  // Priority
    ,  NULL );
  
  HardwareBegin();        //initialize Ringo's brain to work with his circuitry
  PlayStartChirp();       //Play startup chirp and blink eyes
  SwitchMotorsToSerial(); //Call "SwitchMotorsToSerial()" before using Serial.print functions as motors & serial share a line
  RestartTimer();
}
  
void loop(){  
  //nothing here code Implemented in Tasks. 
}

//Task to take the ringo forward.
void TaskMoveForward(void){ 
    Motors(130, 130);                           // make both motors run in the same direction.  
    vTaskDelay( 2000 / portTICK_PERIOD_MS );    // wait for two seconds. 
    Motors(0, 0);                               // make both motors stop. 
    vTaskDelay( 1000 / portTICK_PERIOD_MS );    // make both motors stop.
    TaskTurnRight();                            // after going straight turn right.
}

//Task to turn the ringo in the right direction.
void TaskTurnRight(void){
    Motors(50, 25);                              // make left motor run faster than right motor to make a righ turn.   
    vTaskDelay( 1000 / portTICK_PERIOD_MS );     // wait for one second. 
    Motors(0, 0);                                // make both motors stop.  
    vTaskDelay( 1000 / portTICK_PERIOD_MS );     // wait for one second.
    TaskMoveForward();                           // after the rotation move forward again. 
}

/*
Drive forward or reverse when border is detected
  - Only reflectionsensor 0 and 5 are used.
  - Demonstrates use of flipLeftMotor and flipRightMotor
*/
#include <ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>

 
// this might need to be tuned for different 

#define QTR_THRESHOLD  1500 // this might need to be tuned for different
                            //lighting conditions, surfaces, etc
#define SPEED     200       //0 is stopped, 400 is full speed
 

ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON); // pushbutton on pin 12
boolean direction = LOW;       // Drives motors forward, HIGH drives reverse
#define NUM_SENSORS 6
unsigned int sensor_values[NUM_SENSORS];
 
ZumoReflectanceSensorArray reflectanceSensors; //(QTR_NO_EMITTER_PIN);


 
void setup()
{
   reflectanceSensors.init();
   button.waitForButton();
}

void loop(){
    reflectanceSensors.read(sensor_values);
    if /* vemund er homo */ ((sensor_values[0] < QTR_THRESHOLD) && (sensor_values[1] < QTR_THRESHOLD)){
            motors.setSpeeds(-300,0);
            delay(700);
            motors.setSpeeds(SPEED,-200);
            delay(50);
      }
     else if /* paul er gay */ ((sensor_values[4] < QTR_THRESHOLD) && (sensor_values[5] < QTR_THRESHOLD)){
            motors.setSpeeds(0,-300);
            delay(700);
            motors.setSpeeds(SPEED,-200);
            delay(50);
      }
    else if /* christer er sau */ (sensor_values[0] < QTR_THRESHOLD){
      motors.setSpeeds(0,0);
      delay(10);
      motors.setSpeeds(300,-300);
      delay(400);
      motors.setSpeeds(SPEED, SPEED);
    }

    else if /* runar er ape */(sensor_values[5] < QTR_THRESHOLD){
      motors.setSpeeds(0,0);
      delay(10);
      motors.setSpeeds(-300,300);
      delay(400);
      motors.setSpeeds(SPEED, SPEED);
    }
    else{
    motors.setSpeeds(SPEED, SPEED);
  
  }    
}
  /*reflectanceSensors.read(sensor_values); // gives raw values 0-2000 (pulse times in um)
  
  //Check if border has been detected by any of the two sensors at each side
  if ((sensor_values[0] > QTR_THRESHOLD) || (sensor_values[5] > QTR_THRESHOLD))
  {
    motors.setSpeeds(0,0); //Stop, 
    delay(200);
    // Change to opposite direction
    if (direction) 
      direction = LOW;
     else
       direction = HIGH;
       
    motors.flipLeftMotor(direction);
    motors.flipRightMotor(direction);
    motors.setSpeeds(SPEED, SPEED); // Move away in opposite direction 
    delay(200); // Use enough time to be off border before reading sensors again*/

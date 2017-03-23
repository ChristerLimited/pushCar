/*
Drive forward or reverse when border is detected
  - Only reflectionsensor 0 and 5 are used.
  - Demonstrates use of flipLeftMotor and flipRightMotor
*/
#include <ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>
#include <NewPing.h>

 
// this might need to be tuned for different 

#define QTR_THRESHOLD  1500 // this might need to be tuned for different
                            //lighting conditions, surfaces, etc
#define SPEED     200       //0 is stopped, 400 is full speed
 

ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON); // pushbutton on pin 12
boolean direction = LOW;       // Drives motors forward, HIGH drives reverse
#define NUM_SENSORS 6
unsigned int sensor_values[NUM_SENSORS];

// NewPing Stuff
// Trigger er alltid grønn, echo er blå. (pga. ubåter bruker echo og er i vann som er blått)
const int maxDistance = 25;
const int triggerPin = 2;
const int echoPin = 3;
const int triggerPinR = 6;
const int echoPinR = A1;
const int triggerPinL = A4;
const int echoPinL = A5;
NewPing sonar(triggerPin, echoPin, maxDistance);
NewPing sonarL(triggerPinL, echoPinL, maxDistance);
NewPing sonarR(triggerPinR, echoPinR, maxDistance);

 
ZumoReflectanceSensorArray reflectanceSensors; //(QTR_NO_EMITTER_PIN);


 
void setup()
{
   reflectanceSensors.init();
   button.waitForButton();
   Serial.begin(9600);

}

void loop(){
    reflectanceSensors.read(sensor_values);
    Serial.println(sonarL.ping_cm());
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

    //Når den ser noe til venstre spinner den mot venstre til den ser det foran
    else if (sonarL.ping_cm() > 0) {
      while (!(sonar.ping_cm() > 0)) {
        motors.setSpeeds(-100,100);
        delay(100);
      }
      motors.setSpeeds(SPEED, SPEED);
    }
    
    // Samma når den ser noe til høyre
   /* else if (sonarR.ping_cm() > 0) {
      while (!(sonar.ping_cm() > 0)) {
        motors.setSpeeds(100,-100);
        delay(100);
      }
      motors.setSpeeds(SPEED, SPEED);
    }*/
    else {
    motors.setSpeeds(SPEED, SPEED);
    }    
}

#include <Servo.h>
Servo myservo;
int pos = 0;
const int echoPin = 7;
const int triggerPin = 8;
 

void setup() {
  Serial.begin(9600);
  
  // Definer hvilken type de forskjellige pinnene er
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(9);
}

void loop() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  // Mål hvor lang tid det tar før ekkoet kommer tilbake
  long duration = pulseIn(echoPin, HIGH);
  // Regn ut avstanden
  float distance = duration * 0.017;  
   
  Serial.println(distance);
  delay(150);
  /*
  myservo.write(0);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(90);
  delay(1000);
  for (pos = 0; pos <= 30; pos += 1) {
    myservo.write(pos);
    delay(50);
  }
  for (pos = 30; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(50);
  }
  */
}

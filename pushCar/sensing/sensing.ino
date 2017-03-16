#include <NewPing.h>
const int triggerPin=7;
const int echoPin = 8;
const int maxDistance = 30;

NewPing sonar(triggerPin, echoPin, maxDistance);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int distance = sonar.ping_cm();
  Serial.println(distance);
  delay(100);
}


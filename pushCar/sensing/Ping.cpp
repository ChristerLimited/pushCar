#include "Arduino.h"
#include "Ping.h"

Ping::Ping(const int echoPin, const int triggerPin) {
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);
  _echoPin = echoPin;
  _triggerPin = triggerPin;
}

float Ping::pulse() {
  digitalWrite(_triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(_triggerPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(_triggerPin, LOW);
  // Mål hvor lang tid det tar før ekkoet kommer tilbake 
  long duration = pulseIn(_echoPin, HIGH);
  // Calculate distance in cm:
  // 58 comes from the HC-SR04 datasheet (check docs/ folder)
  float distance = (float)duration / (float)58;
  return distance;
}


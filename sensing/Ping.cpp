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
  // Regn ut avstanden 
  float distance = duration * 0.0017;
  return distance;
}


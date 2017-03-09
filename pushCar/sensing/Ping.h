#ifndef Ping_h
#define Ping_h

#include "Arduino.h"

// Class for ultrasonic rangefinders
class Ping {
  public:
    Ping(const int echoPin, const int triggerPin);
    // Pulse returns range in cm
    float pulse();
  private:
    int _echoPin;
    int _triggerPin;
};

#endif

#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

class Ping {
  public:
    Ping(const int echoPin, const int triggerPin);
    float pulse();
  private:
    int _echoPin;
    int _triggerPin;
};

#endif

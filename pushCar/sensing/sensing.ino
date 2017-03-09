#include "Ping.h"

Ping ping(8, 7);

void setup() {
  Serial.begin(9600);
}

void loop() {
  float distance = ping.pulse();
  Serial.println(distance);
  delay(100);
}


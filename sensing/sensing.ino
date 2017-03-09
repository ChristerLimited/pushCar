Servo myservo;
int pos = 0;

void setup() {
  myservo.attach(9)
}

void loop() {
  for (pos = 0; pos <= 30; pos += 1) {
    myservo.write(pos);
    delay(15);
  }
  for (pos = 30; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
}

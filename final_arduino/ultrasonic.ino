//////////////////////////////////////****************** ultrasonic sensor raw data **************////////////////////////////
long ultrasonic(int sensor) {
  if (sensor == 1) {
    long duration, cm;
    pinMode(pingPin1, OUTPUT);
    digitalWrite(pingPin1, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(pingPin1, LOW);
    pinMode(echoPin1, INPUT);
    duration = pulseIn(echoPin1, HIGH);
    cm = (duration / 29 / 2);
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    return cm;
  }
  else if (sensor == 2) {
    long duration, cm;
    pinMode(pingPin2, OUTPUT);
    digitalWrite(pingPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(pingPin2, LOW);
    pinMode(echoPin2, INPUT);
    duration = pulseIn(echoPin2, HIGH);
    cm = (duration / 29 / 2);
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    return cm;
  }
}

//////////////////////////////////////****************** ultrasonic decision **************////////////////////////////
int ultrasonicDecision() {
  long sensor1 = ultrasonic(1);
  long sensor2 = ultrasonic(2);
  if ( (ultrasonicTreshold - ultrasonicBuffer < sensor1 < ultrasonicTreshold + ultrasonicBuffer) && (ultrasonicTreshold - ultrasonicBuffer < sensor2 < ultrasonicTreshold + ultrasonicBuffer) ) {
    return 0; // forward
  }
  else if ((ultrasonicTreshold - ultrasonicBuffer > sensor1 ) && (sensor2 > ultrasonicTreshold + ultrasonicBuffer) ) {
    return 1; // left
  }
  else if ( (sensor1 > ultrasonicTreshold + ultrasonicBuffer) && (ultrasonicTreshold - ultrasonicBuffer > sensor2 ) ) {
    return -1; // right
  }
  else {
    return 10; // stop
  }
}

//////////////////////////////////////****************** IR decision **************////////////////////////////
int irDecision() {
  pinMode(IRSensor1, INPUT);
  pinMode(IRSensor2, INPUT);
  int sensor1 = digitalRead(IRSensor1);
  int sensor2 = digitalRead(IRSensor2);
  if ( sensor1 && sensor2 ) {
    return 0; // forward
  }
  else if (sensor1 == 0 && sensor2 == 1 ) {
    return 1; // left
  }
  else if ( sensor1 == 1 && sensor2 == 0 ) {
    return -1; // right
  }
  else {
    return 10; // stop
  }
}

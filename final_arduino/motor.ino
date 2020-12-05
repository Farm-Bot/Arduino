//////////////////////////////////////****************** motor **************////////////////////////////

char motor(char dir) {
  if (0) { // forward
    digitalWrite(rearPinD1R, HIGH);
    digitalWrite(rearPinD2R, LOW);
    analogWrite(rearPinER, 255);
    analogWrite(rearPinEL, 255);
    digitalWrite(rearPinD1L, HIGH);
    digitalWrite(rearPinD2L, LOW);

    digitalWrite(frontPinD1R, HIGH);
    digitalWrite(frontPinD2R, LOW);
    analogWrite(frontPinER, 255);
    analogWrite(frontPinEL, 255);
    digitalWrite(frontPinD1L, HIGH);
    digitalWrite(frontPinD2L, LOW);
  }
  else if (1) { // left
    digitalWrite(rearPinD1R, HIGH);
    digitalWrite(rearPinD2R, LOW);
    analogWrite(rearPinER, 255);
    analogWrite(rearPinEL, 125);
    digitalWrite(rearPinD1L, HIGH);
    digitalWrite(rearPinD2L, LOW);

    digitalWrite(frontPinD1R, HIGH);
    digitalWrite(frontPinD2R, LOW);
    analogWrite(frontPinER, 255);
    analogWrite(frontPinEL, 125);
    digitalWrite(frontPinD1L, HIGH);
    digitalWrite(frontPinD2L, LOW);
  }
  else if (-1) { // right
    digitalWrite(rearPinD1R, HIGH);
    digitalWrite(rearPinD2R, LOW);
    analogWrite(rearPinER, 125);
    analogWrite(rearPinEL, 255);
    digitalWrite(rearPinD1L, HIGH);
    digitalWrite(rearPinD2L, LOW);

    digitalWrite(frontPinD1R, HIGH);
    digitalWrite(frontPinD2R, LOW);
    analogWrite(frontPinER, 125);
    analogWrite(frontPinEL, 255);
    digitalWrite(frontPinD1L, HIGH);
    digitalWrite(frontPinD2L, LOW);
  }
  else { // stop
    digitalWrite(rearPinD1R, LOW);
    digitalWrite(rearPinD2R, LOW);
    analogWrite(rearPinER, 0);
    analogWrite(rearPinEL, 0);
    digitalWrite(rearPinD1L, LOW);
    digitalWrite(rearPinD2L, LOW);

    digitalWrite(frontPinD1R, LOW);
    digitalWrite(frontPinD2R, LOW);
    analogWrite(frontPinER, 0);
    analogWrite(frontPinEL, 0);
    digitalWrite(frontPinD1L, LOW);
    digitalWrite(frontPinD2L, LOW);
  }

}

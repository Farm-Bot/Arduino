//////////////////////////////////////****************** ultrasonic sensor decleration **************////////////////////////////
// sensor 1 = left side
// sensor 2 = right side
const int pingPin1 = 6; // Trigger Pin of Ultrasonic Sensor 1
const int echoPin1 = 7; // Echo Pin of Ultrasonic Sensor 1
const int pingPin2 = 8; // Trigger Pin of Ultrasonic Sensor 2
const int echoPin2 = 9; // Echo Pin of Ultrasonic Sensor 2

//////////////////////////////////////****************** ultrasonic parameters **************////////////////////////////
const int ultrasonicBuffer = 2; // 2cm of buffer for the plants
const int ultrasonicTreshold = 6; // 6cm Treshold from the vehicle

//////////////////////////////////////****************** IR sensor decleration **************////////////////////////////
const int IRSensor1 = 36; // IR sensor input
const int IRSensor2 = 37; // IR sensor input

//////////////////////////////////////****************** motor driver parameters rear side **************////////////////////////////
#define rearPinD1R  2 // rear right motor positive
#define rearPinD2R  3 // rear right motor negitive
#define rearPinER   4 // rear right motor pwm
#define rearPinEL   5 // rear left  motor pwm
#define rearPinD1L  6 // rear left motor positive
#define rearPinD2L  7 // rear left motor negitive

//////////////////////////////////////****************** motor driver parameters front side **************////////////////////////////
#define frontPinD1R  8 // front right motor positive
#define frontPinD2R  9 // front right motor negitive
#define frontPinER   10 // front right motor pwm
#define frontPinEL   11 // front left  motor pwm
#define frontPinD1L  12 // front left motor positive
#define frontPinD2L  13 // front left motor negitive

void setup() {
  Serial.begin(9600); // Starting Serial Terminal

  //////////////////////////////////////****************** motor driver decleration rear side **************////////////////////////////
  pinMode(rearPinD1R, OUTPUT);
  pinMode(rearPinD2R, OUTPUT);
  pinMode(rearPinER, OUTPUT);
  pinMode(rearPinEL, OUTPUT);
  pinMode(rearPinD1L, OUTPUT);
  pinMode(rearPinD2L, OUTPUT);


  //////////////////////////////////////****************** motor driver decleration front side **************////////////////////////////

  pinMode(frontPinD1R, OUTPUT);
  pinMode(frontPinD2R, OUTPUT);
  pinMode(frontPinER, OUTPUT);
  pinMode(frontPinEL, OUTPUT);
  pinMode(frontPinD1L, OUTPUT);
  pinMode(frontPinD2L, OUTPUT);

}


//////////////////////////////////////****************** main function **************////////////////////////////

void loop() {
  while (1) {
    int pyDirection = pyserial();
    int ultrasonicDirection = ultrasonicDecision();
    int irDirection = irDecision();

    if (pyDirection) {
      motor(pyDirection);
      break;
    }
    else {
      if (ultrasonicDirection == irDirection) {
        motor(irDirection);
      }
      else {
        motor(ultrasonicDirection);

      }
    }
  }
}

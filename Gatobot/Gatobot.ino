/*
 * Gatobot
 */
const int motionFront = 1;
const int motionBack = -1;
const int motionLeft = 2;
const int motionRight = 3;
const int motionStopped = 0;

// Special motions / attacks
const int attackLeft = 4;
const int attackRight = 5;

int tLed = 13;         //LED
int btPower = 12;      //Bluetooth power 
// H bridge pins
const int ENA = 2;
const int ENB = 3;
const int IN1 = 4;
const int IN2 = 5;
const int IN3 = 6;
const int IN4 = 7;

const int delayLongLongTime = 500;
const int delayLongTime = 100;
const int delaySmallTime = 50;

//if we get noise, we move as the last known motion
int previousMotion;
//turn engines to move front
void moveFront(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

//turn engines to move  back
void moveBack(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); 
}

//turn right
void moveRight(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); 
}

//turn left
void moveLeft(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH); 
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

//stop engines
void stopMotors(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);   
}

//Read serial port, and get the motion command
int decideMotion(){
  int nextMotion;
  char btInput;
  digitalWrite(tLed, LOW);  //by default, alert led is turned off
  if (Serial.available()) {
    btInput = Serial.read();
    switch (btInput){
      case 'w':
        nextMotion = motionFront;
        break;
      case 's':
        nextMotion = motionBack;
        break;
      case 'a':
        nextMotion = motionLeft;
        break;
      case 'd':
        nextMotion = motionRight;
        break;
      case 'A':
        nextMotion = attackLeft;
        break;
      case 'D':
        nextMotion = attackRight;
        break;
      //if we get a unexpected command, we need to execute the last known motion command recived.
      default:
        nextMotion = previousMotion;
        digitalWrite(tLed, HIGH);
    }
  //if we don't know how to move, we stop
  } else {
    nextMotion = motionStopped;
  }
  previousMotion = nextMotion;
  return nextMotion;
}
 
// engines do a motion
void executeMotion (int nextMotion){
  switch (nextMotion){
    case motionFront:
      moveFront();
      delay(delayLongTime);
      break;
    case motionLeft:
      moveLeft();
      delay(delaySmallTime);
      break;
    case motionRight:
      moveRight();
      delay(delaySmallTime);
      break;
    case motionBack:
      moveBack();
      delay(delayLongTime);
      break;
    case attackLeft:
      moveLeft();
      delay(delayLongLongTime);
      break;
    case attackRight:
      moveRight();
      delay(delayLongLongTime);
      break;
    default:
      stopMotors();
      delay(delayLongTime);
  }
}

void setup() {
  // set pin modes
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(tLed, OUTPUT);
  pinMode(btPower, OUTPUT);
  // enable both engines
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  //Turn down alert alert led
  digitalWrite(tLed, LOW);
  //Turn on bluetooth device
  digitalWrite(btPower, HIGH);
  // set the serial port
  Serial.begin(9600);
}

void loop() {
  int nextMotion;
  nextMotion = decideMotion();
  executeMotion(nextMotion);
}

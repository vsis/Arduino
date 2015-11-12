boolean frontBlocked;  //true if IR sensor detects an obstacule
int previousMotion;   //previous motion of vehicle
                      /*
                        -1: there were no previos motion / back
                        1: front
                        2: left
                        3: right
                      */
const int motionFront = 1;
const int motionBack = -1;
const int motionLeft = 2;
const int motionRight = 3;
//times for motions
const int timeBack = 500;
const int timeTurn = 300;
const int timeFront = 100;
int motionNumber; //the number of front motions done
int tLED = 13;         //LED
// H bridge pins
const int ENA = 2;
const int ENB = 3;
const int IN1 = 4;
const int IN2 = 5;
const int IN3 = 6;
const int IN4 = 7;
// IR sensor
const int IR = 0;   //sensor pin
int IRValue;  // value returned by sensor

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

//decide how to move
int decideMotion(){
  int nextMotion;
  
  // if our front is blocked
  if (frontBlocked){
    motionNumber = 0; // we no longer go front
    // if previousley we were going front
    if (previousMotion == motionFront){
      nextMotion = random(2,4); //we turn left or righ
      return nextMotion;
    //if prevoiusly we have turned left, right or back
    } else {
      nextMotion = motionBack; //we turn back
      return nextMotion;
    }
  } 

  // if we have executed 32 front motions
  if (motionNumber % 32 == 0) {
    motionNumber = 0;
    nextMotion = random(1,4); // we go front, left or right
    return nextMotion;
  }
  
  // go front by default
  nextMotion = motionFront; 
  return nextMotion;
}
 
// engines do a motion
void executeMotion (int nextMotion){
  switch (nextMotion){
    case motionFront:
      moveFront();
      delay(timeFront);
      break;
    case motionLeft:
      moveBack();
      delay(timeBack);
      moveLeft();
      delay(timeTurn);
      stopMotors();
      break;
    case motionRight:
      moveBack();
      delay(timeBack);
      moveRight();
      delay(timeTurn);
      break;
    default:
      stopMotors();
      delay(timeBack);
      moveBack();
      delay(timeBack);
  }
  previousMotion = nextMotion;
  motionNumber++;
}

// determine if front space is blocked
void setBlocked(){
  IRValue = analogRead(IR);
  frontBlocked = (IRValue >= 490);
  digitalWrite(tLED, frontBlocked);
  Serial.println(IRValue);
}

void setup() {
  // set pin modes
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(tLED, OUTPUT);
  // turn off engines
  stopMotors();
  // enable both engines
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  //set a (hopefully) random seed
  randomSeed(analogRead(5));
  //we are ready to do our first motion
  motionNumber = 0;
  // set the serial port
  Serial.begin(9600);
}

void loop() {
  int nextMotion;
  setBlocked();
  nextMotion = decideMotion();
  executeMotion(nextMotion);
}

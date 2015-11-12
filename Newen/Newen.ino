boolean timeCuantum = false;
int tLED = 13;
// H bridge pins
int ENA = 2;
int ENB = 3;
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
// IR sensor
int IR = 0;
int IRValue;

//turn engines to move front
void moveFront(){
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN4, HIGH);
}

//turn engines to move  back
void moveBack(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);    
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
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  // enable both engines
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  // set the serial port
  Serial.begin(9600);
}

void loop() {
  timeCuantum = ! timeCuantum;
  
  if (timeCuantum){
    moveFront();
  } else {
    moveBack(); 
  }
  IRValue = analogRead(IR);
  if (IRValue >= 490){
    digitalWrite(tLED, HIGH);
  } else { 
    digitalWrite(tLED, LOW);
  }
  Serial.println(IRValue);
  delay(500);
}

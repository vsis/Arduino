const int threshold = 256 ;
const int ledTime = 64;
int inValue;
int ledValue;
  
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  inValue = analogRead(0);
  if (inValue >= threshold){
    ledValue = HIGH;
  } else {
    ledValue = LOW;
  }
  digitalWrite(13, ledValue);
  Serial.println(inValue);
  delay(ledTime);
}

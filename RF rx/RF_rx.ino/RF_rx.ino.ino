const int threshold = 256;
int inValue;
int ledValue;
  
void setup() {
  pinMode(13, OUTPUT); 
}

void loop() {
  inValue = analogRead(0);
  if (inVaue >= threshold){
    ledValue = HIGH;
  } else {
    ledValue = LOW;
  }
}

/*
 * Testing bluetooth RxTx
 * 
 */

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    char btInput = Serial.read();
    Serial.println(btInput);
  }
}

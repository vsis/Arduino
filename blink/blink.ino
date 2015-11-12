int tiempo = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH); // se prende el trece
  digitalWrite(2,LOW);
  digitalWrite(3, LOW);
  delay(tiempo);
  digitalWrite(13, LOW);
  digitalWrite(2,HIGH);
  delay(tiempo);
  digitalWrite(13, HIGH); // se prende el trece
  digitalWrite(2,LOW);
  digitalWrite(3, LOW);
  delay(tiempo * 2);
  digitalWrite(13, LOW);
  digitalWrite(2,HIGH);
  delay(tiempo * 2);

}


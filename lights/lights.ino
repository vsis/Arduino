void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
  
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(13, HIGH);
  
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
}

void loop() {
  int i =0;
  while(true){
    i++;
    if (i == 0){
      digitalWrite(13,HIGH);
    }
    if (i < 0){
      digitalWrite(13,LOW);
    }
  }
}

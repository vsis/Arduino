const int X = 0;
const int Y = 1;
const int Z = 2;


void setup() {
  Serial.begin(9600);
  analogReference(EXTERNAL);
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(Z, INPUT);
}

void loop() {
  int x,y,z;
  x = analogRead(X);
  delay(10);
  y = analogRead(Y);
  delay(10);
  z = analogRead(Z);
  delay(10);
  Serial.println( String(String(x) + ", " + String(y) + ", " + String(z)));
  delay(1000);
}

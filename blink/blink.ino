int ledTime = 128;
int ledValue = HIGH;
int ledSync = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ledValue = (ledSync % 0 == 0) || (ledSync % 7 == 0);
  digitalWrite(13, ledValue);
  digitalWrite(12, ledValue);
  ledSync++;
  delay(ledTime);
}


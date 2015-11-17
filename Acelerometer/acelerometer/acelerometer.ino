const int X = 0;
const int Y = 1;
const int Z = 2;
const float G = 512;
const float scale_x = 95.97;
const float scale_y = 106.72;
const float scale_z = 137.082;

void setup() {
  Serial.begin(9600);
  analogReference(EXTERNAL);
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(Z, INPUT);
}

void loop() {
  int x,y,z;
  float rx, ry, rz;
  double current_a;
  x = analogRead(X);
  y = analogRead(Y);
  z = analogRead(Z);
  delay(10);
  rx = ((float)x - G) / scale_x;
  ry = ((float)y - G) / scale_y;
  rz = ((float)z - G) / scale_z;
  current_a = sqrt(sq(rx) + sq(ry) + sq(rz));
  Serial.println( String(String(rx) + ", " + String(ry) + ", " + String(rz) + ", ") + String(current_a));
  delay(100);
}

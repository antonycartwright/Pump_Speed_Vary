#define vrSpeedPin A0
#define mosGatePin 3

void setup() {
  // put your setup code here, to run once:
  pinMode(vrSpeedPin, INPUT);
  pinMode(mosGatePin, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int speedFromPin = analogRead(vrSpeedPin);
  int speed = 0;

  //Serial.print(speedFromPin);

  //  if (speedFromPin < 16) {
  //    speed = 0;
  //  } else if (speedFromPin > 16 && speedFromPin < 168) {
  //    speed = 168;
  //  } else if (speedFromPin > 168 && speedFromPin < 1000) {
  //    speed = speedFromPin;
  //  } else if (speedFromPin > 1000) {
  //    speed = 1023;
  //  }

  //Serial.println(String(speedFromPin) + " " + String(speed));

  speed = map(speedFromPin, 0, 1023, 168, 1023);
  Serial.println(String(speedFromPin) + " " + String(speed));

  analogWrite(mosGatePin, speed);

  delay(2);
}

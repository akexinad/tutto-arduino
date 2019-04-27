const int isTooHighSensorPin = 0;
const int isHighSensorPin = 2;
const int isLevelSensorPin = 7;
const int isLowSensorPin = 11;
const int isTooLowSensorPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(isTooHighSensorPin, INPUT);
  pinMode(isHighSensorPin, INPUT);
  pinMode(isLevelSensorPin, INPUT);
  pinMode(isLowSensorPin, INPUT);
  pinMode(isTooLowSensorPin, INPUT);
}

void loop () {
  int isTooHigh = digitalRead(isTooHighSensorPin);
  int isHigh = digitalRead(isHighSensorPin);
  int isLevel = digitalRead(isLevelSensorPin);
  int isLow = digitalRead(isLowSensorPin);
  int isTooLow = digitalRead(isTooLowSensorPin);

  if (isTooHigh == HIGH) {
    Serial.println("TOO HIGH");
  } else if (isHigh == HIGH) {
    Serial.println("High");
  } else if (isLevel == HIGH) {
    Serial.println("LEVEL");
  } else if (isLow == HIGH) {
    Serial.println("Low");
  } else if (isTooLow == HIGH) {
    Serial.println("TOO LOW");
  } else {
    Serial.println("No Signal");
  }

  delay(50);
}

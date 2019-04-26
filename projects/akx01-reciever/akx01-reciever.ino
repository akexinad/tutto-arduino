const int isHighSensorPin = A2;
const int isLevelSensorPin = A1;
const int isLowSensorPin = A0;

int isHighSensorValue = 0;
int isLevelSensorValue = 0;
int isLowSensorValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop () {
  isHighSensorValue = analogRead(isHighSensorPin);
  delay(250);
  isLevelSensorValue = analogRead(isLevelSensorPin);
  delay(250);
  isLowSensorValue = analogRead(isLowSensorPin);
  delay(250);

  Serial.print("Sensor Values:");
  Serial.println("TOO HIGH: ");
  Serial.print(isHighSensorValue);
  Serial.print("LEVEL: ");
  Serial.print(isLevelSensorValue);
  Serial.print("TOO LOW: ");
  Serial.print(isLowSensorValue);
}

const int greenLEDPin = 9;
  const int redLEDPin = 10;
  const int blueLEDPin = 11;
  const int redSensorPin = A0;
  const int greenSensorPin = A1;
  const int blueSensorPin = A2;
  int redValue = 0;                               // Give all values a baseline of 0;
  int greenValue = 0;
  int blueValue = 0;
  int redSensorValue = 0;
  int greenSensorValue = 0;
  int blueSensorValue = 0;

void setup () { 
  Serial.begin(9600);                             // Open a serial port communication line between arduino and pc
  pinMode(redLEDPin, OUTPUT);                     // Set the LED pins as an output.
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);  
}

void loop () {
  redSensorValue = analogRead(redSensorPin);      // The following variables are to recieve their information from via their respective sensor pins with the analogRead function
  delay(500);
  greenSensorValue = analogRead(greenSensorPin);
  delay(500);
  blueSensorValue = analogRead(blueSensorPin);
  delay(500);
  Serial.print("Raw Sensor Values \t Red: ");     // Print the values on the pc
  Serial.print(redSensorValue);
  Serial.print("\t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.println(blueSensorValue);
  redValue = redSensorValue / 4;                  // Since the colorSensorValue is in voltage. To get an RGB value between 0 and 255, you need to divide it by 4.
  greenValue = greenSensorValue / 4;
  blueValue = blueSensorValue / 4;
  Serial.print("Mapped sensor values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.println(blueValue);
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
}

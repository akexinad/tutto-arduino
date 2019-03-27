#include <Servo.h>             // Import the library

Servo myServo;                 // Name the library

int const potPin = A0;         // variable for pentiommeter(potPin) in pin A0
int potVal;                    // pentiommeter value
int angle;                     // Angle at which pot is turned

void setup() {
  myServo.attach(9);           // Connecting Servo to output pin 9

  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);               // Reading analog value of potPin
  Serial.println("potVal: ");
  Serial.println(potVal);
  angle = map(potVal, 0, 1023, 0, 179);      // Converting value from potVal (which is between 0 and 1023 V, to an angle between 0 and 179 degrees.)
  Serial.println(", angle: ");
  Serial.println(angle);
  myServo.write(angle);                      // Write angle to the servo
  delay(15);
}

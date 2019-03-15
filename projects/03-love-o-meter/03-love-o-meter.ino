const int sensorPin = A0;                                     // Constant variable to declare the analog input for easy referencing.
const float baselineTemp = 38.0;                              // Constant variable for a baseline temperature as a starting for function execution.

void setup() {
  Serial.begin(9600);                                         // This command opens a serial port connection between arduino and pc so we can see the input values in the console. The arguement is the speed of communication from the arduino, i.e. 9600 bits/sec.
  for (int pinNumbers = 2; pinNumbers < 5; pinNumbers ++) {   // This for loop will iterate through the LED's connected to pins 2 3 and 4.
    pinMode(pinNumbers, OUTPUT);                              // First it will turn each pin into an output.
    digitalWrite(pinNumbers, LOW);                            // Then it will turn them off.
  }
}
void loop() {
  int sensorVal = analogRead(sensorPin);                      // Declare a variable o store the reading of the A0 sensor pin;
  Serial.print("Sensor Value: ");                             // This command will send the info from the arduino to the pc.
  Serial.print(sensorVal);                                    // Here it will print the value read by the A0 sensor pin.
  
  float voltage = (sensorVal / 1024.0) * 5.0;                 // Here we convert the sensorVal reading to volts.
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  
  float temperature = (voltage - .5) * 100;                   // converting voltage to temperature in celcius.
  Serial.println(temperature);                                // this command will print the argument on a new line.
//  Serial.println("-----------------");
  if (temperature < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);
}


// NOTE: An big that held me up was that the denominator constant of 1024 was supposed to written in float format - 1024.0 - and not integer format. Meaning that 1024 was incorrect and not giving the correct temperatire reading.

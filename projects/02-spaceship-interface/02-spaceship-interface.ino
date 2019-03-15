int switchState = 0;                   // Variable to declare the initial state of the switch when untouched. 0 meaning that there is no voltage to start with.

void setup() {
  // put your setup code here, to run once:
  
  pinMode(3, OUTPUT);                   // Green LED connected to pin 3 is set as OUTPUT.
  pinMode(4, OUTPUT);                   // Red LED connected to pin 4 is set as OUTPUT.
  pinMode(5, OUTPUT);                   // Red LED connected to pin 5 is set as OUTPUT.
  pinMode(2, INPUT);                    // Switch connected to pin 2 is set as INPUT.

}

void loop() {
  // put your main code here, to run repeatedly:
  
  switchState = digitalRead(2);

  if (switchState == LOW) {             // If the button is NOT pressed.
    digitalWrite(3, HIGH);              // Then switch on the green LED connected to pin 3.
    digitalWrite(4, LOW);               // Switch off the red LED connected to pin 4.
    digitalWrite(5, LOW);               // Switch off the other red LED connected to pin 5.
  }
  else {                                // HOWEVER, if the button IS PRESSED
    digitalWrite(3, LOW);               // Then switch OFF the green LED connected to pin 3.
    digitalWrite(4, HIGH);              // Switch ON the red LED connected to pin 4.
    digitalWrite(5, HIGH);              // Switch ON the red LED connected to pin 5.

    delay(1000);                        // Before toggling the LED's, wait for one second.
    digitalWrite(3, HIGH);              // Then turn ON the green led connected to pin 3.
    digitalWrite(4, LOW);               // Then turn OFF the green led connected to pin 4.
    digitalWrite(5, LOW);               // Then turn OFF the green led connected to pin 5.
    delay(1000);                        // Before repeating, wait one second before going back to the beginning of the loop.
  }

}

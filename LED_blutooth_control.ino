char command;

void setup() {
  Serial.begin(9600);   // Initialize Serial Communication for Bluetooth
  pinMode(9, OUTPUT);   // Red LED pin
  pinMode(10, OUTPUT);  // Green LED pin
  pinMode(11, OUTPUT);  // Blue LED pin
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();  // Read Bluetooth command
    if (command == '1') {
      Serial.print("1");
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      delay(1000);
       digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      delay(1000);
       digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      delay(1000);
    }
    
    // Red LED on and off
    if (command == 'R') {
      Serial.print("R");
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
    } else if (command == 'r') {
      digitalWrite(9, LOW);
    }

    // Green LED on and off
    else if (command == 'G') {
      Serial.print("G");
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
    } else if (command == 'g') {
      digitalWrite(10, LOW);
    }

    // Blue LED on and off
    else if (command == 'B') {
      Serial.print("B");
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
    } else if (command == 'b') {
      digitalWrite(11, LOW);
    }

    // Blink all colors
    else if (command == 'X') {
      Serial.print("X");
      for (int i = 0; i < 3; i++) {
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        delay(500);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        delay(500);
      }
    }
  }
}

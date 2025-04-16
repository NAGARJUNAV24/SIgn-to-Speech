void setup() {
    pinMode(2, INPUT);  // LDR for Finger 1
    pinMode(3, INPUT);  // LDR for Finger 2
    pinMode(4, INPUT);  // LDR for Finger 3
    pinMode(5, INPUT);  // LDR for Finger 4
    pinMode(6, OUTPUT); // Buzzer output
  
    Serial.begin(9600); // Start serial communication
  }
  
  void loop() {
    int ldr1 = digitalRead(2); // Finger 1
    int ldr2 = digitalRead(3); // Finger 2
    int ldr3 = digitalRead(4); // Finger 3
    int ldr4 = digitalRead(5); // Finger 4
  
    bool f1_closed = (ldr1 == HIGH);
    bool f2_closed = (ldr2 == HIGH);
    bool f3_closed = (ldr3 == HIGH);
    bool f4_closed = (ldr4 == HIGH);
  
    if (f1_closed && f2_closed && f3_closed && f4_closed) {
      Serial.println("IT’S EMERGENCY PLEASE HELP!!!");
      digitalWrite(6, HIGH);
      delay(200);
      digitalWrite(6, LOW);
      delay(200);
    } else {
      digitalWrite(6, LOW);
  
      if (f1_closed && f2_closed && f3_closed)
        Serial.println("HOW ARE YOU FEELING TODAY?");
      else if (f1_closed && f2_closed && f4_closed)
        Serial.println("ARE YOU OK?");
      else if (f1_closed && f3_closed && f4_closed)
        Serial.println("I NEED SOME WATER");
      else if (f2_closed && f3_closed && f4_closed)
        Serial.println("LET US HAVE PIZZA TONIGHT");
      else if (f1_closed && f2_closed)
        Serial.println("I AM SLEEPY");
      else if (f1_closed && f3_closed)
        Serial.println("I WANT TO FIX THAT");
      else if (f1_closed && f4_closed)
        Serial.println("I DON’T UNDERSTAND");
      else if (f2_closed && f3_closed)
        Serial.println("CAN I JOIN YOU?");
      else if (f2_closed && f4_closed)
        Serial.println("THAT WOULD BE GREAT");
      else if (f3_closed && f4_closed)
        Serial.println("SHALL WE GO FOR A MOVIE?");
      else if (f1_closed)
        Serial.println("HOW ARE YOU?");
      else if (f2_closed)
        Serial.println("TALK TO YOU LATER");
      else if (f3_closed)
        Serial.println("I AM GOOD");
      else if (f4_closed)
        Serial.println("HELLO");
      else
        Serial.println("No fingers closed");
    }
  
    delay(5000); // 5 second delay
  }
  
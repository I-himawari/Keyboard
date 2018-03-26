void setup() {
  // Keyboard input
     pinMode(2,INPUT);
     pinMode(3,INPUT);
     pinMode(4,INPUT);
     pinMode(5,INPUT);
     pinMode(6,INPUT);

    // Switch input
     pinMode(13,INPUT);

     // LED output
     pinMode(12,OUTPUT);

     // Keyboard output
     pinMode(8,OUTPUT);
}
void loop() {
     if (digitalRead(13) == HIGH) {
          digitalWrite(8,HIGH);
          if (digitalRead(2) == HIGH) {
           digitalWrite(12, HIGH);
          }
     } else {
          digitalWrite(8,LOW);
          digitalWrite(12, LOW);
     }
}

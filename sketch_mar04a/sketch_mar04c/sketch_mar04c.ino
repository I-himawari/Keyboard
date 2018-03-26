#include "Keyboard.h"

#define DATAPIN    (7)   // 74HC595のDSへ
#define LATCHPIN  (8)  // 74HC595のST_CPへ
#define CLOCKPIN  (9)  // 74HC595のSH_CPへ

bool toggle = true;

void MyShiftOut( int dataPin, int clockPin, int bit, int val )
{
  for( int i = 0; i < bit; i++ )
  {
    digitalWrite(dataPin, val == i);
    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW);
  }
}

void OutputAllSwitch() {
  int key_size = 12;
  for( int i = 0; i < key_size; i++ )
  {
    digitalWrite(LATCHPIN, LOW);
    MyShiftOut( DATAPIN, CLOCKPIN, key_size, i );
    digitalWrite(LATCHPIN, HIGH);
    int r = digitalRead(2) * 16 + digitalRead(3) * 8 + digitalRead(4) * 4 + digitalRead(5) * 2 + digitalRead(6);
    /*
    String out = "E";
    switch (r) {
      case 0:
        out = "E";
        break;
        
      case 1:
        out = "1";
        break;

      default:
        out = "E";
        break;
    }
    */
    Keyboard.print(r);
    Keyboard.print(",");
  }
  digitalWrite(LATCHPIN, LOW);
}

void setup()
{
  Serial.begin(9600);
  
  // Keyboard output
  pinMode(DATAPIN, OUTPUT);
  pinMode(LATCHPIN, OUTPUT);
  pinMode(CLOCKPIN, OUTPUT);
  
  // Keyboard input
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  
  // Switch input
  pinMode(13,INPUT);
}

void loop()
{
  if (digitalRead(13) == HIGH) {
    if (toggle == true) {
      Serial.println("START");
      OutputAllSwitch();
      Serial.println("END");
    }
    toggle = false;
  } else {
    toggle = true;
  }
}


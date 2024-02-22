#include <Arduino.h>

#define selector0 14
#define selector1 15
#define selector2 16

#define LEDCommon 10

// #define DEBUG // Uncomment to print LED states to monitor

// FOR TESTING
bool buttonState1 = HIGH;
bool buttonState2 = HIGH;
// END FOR TESTING

// State of LEDs (color)
int LED1 = 0;
int LED2 = 0;

void setup() {
  Serial.begin(115200);

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  pinMode(selector0, OUTPUT);
  pinMode(selector1, OUTPUT);
  pinMode(selector2, OUTPUT);
  pinMode(LEDCommon, OUTPUT);
}

void loop() {
  // TESTING CODE
  if (digitalRead(2) == LOW && buttonState1 != LOW) {
    if (LED1 < 3) {
      LED1++;
    } else if (LED1 == 3) {
      LED1 = 0;
    }
    buttonState1 = LOW;
  } else if (digitalRead(2) == HIGH) {
    buttonState1 = HIGH;
  }
  if (digitalRead(3) == LOW && buttonState2 != LOW) {
    if (LED2 < 3) {
      LED2++;
    } else if (LED2 == 3) {
      LED2 = 0;
    }
    buttonState2 = LOW;
  } else if (digitalRead(3) == HIGH) {
    buttonState2 = HIGH;
  }
  // END TESTING CODE

  // LED COLORS
  // 0 = OFF
  // 1 = Red
  // 2 = Green
  // 3 = Blue

  // CHANNEL INFO:
  // LED1 Red - Channel 0
  // LED1 Green - Channel 1
  // LED1 Blue - Channel 3
  // LED2 Red - Channel 7
  // LED2 Green - Channel 6
  // LED2 Blue - Channel 4
  if (LED1 == 0) {
    digitalWrite(LEDCommon, LOW);
  }
  if (LED2 == 0) {
    digitalWrite(LEDCommon, LOW);
  }
  if (LED1 == 1) {
    writeChannel(0);
  }
  if (LED1 == 2) {
    writeChannel(1);
  }
  if (LED1 == 3) {
    writeChannel(2);
  }
  if (LED2 == 1) {
    writeChannel(7);
  }
  if (LED2 == 2) {
    writeChannel(6);
  }
  if (LED2 == 3) {
    writeChannel(4);
  }

#ifdef DEBUG
  Serial.print("LED1: ");
  Serial.print(LED1);
  Serial.print(" LED2: ");
  Serial.println(LED2);
#endif
}

void writeChannel(int i) {
  digitalWrite(LEDCommon, LOW);  // Turn off previous color
  // Bitwise operation selects channel based on the binary of i
  digitalWrite(selector0, (i & 0x01) ? HIGH : LOW);
  digitalWrite(selector1, (i & 0x02) ? HIGH : LOW);
  digitalWrite(selector2, (i & 0x04) ? HIGH : LOW);
  digitalWrite(LEDCommon, HIGH);  // Turn on LED
}
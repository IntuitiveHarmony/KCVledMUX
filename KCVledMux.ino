#include <Arduino.h>

#define selector0 14
#define selector1 15
#define selector2 16

#define LEDCommon 10

// 0 = OFF
// 1 = Red
// 2 = Green
// 3 = Blue

// FOR TESTING
bool buttonState1 = HIGH;
bool buttonState2 = HIGH;
// END FOR TESTING

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
  // END TESTING

  if (LED1 == 0) {
    digitalWrite(LEDCommon, LOW);
  }
  if (LED2 == 0) {
    digitalWrite(LEDCommon, LOW);
  }
  if (LED1 == 1) {
    writeLED1Red();
  }
  if (LED1 == 2) {
    writeLED1Green();
  }
  if (LED1 == 3) {
    writeLED1Blue();
  }
  if (LED2 == 1) {
    writeLED2Red();
  }
  if (LED2 == 2) {
    writeLED2Green();
  }
  if (LED2 == 3) {
    writeLED2Blue();
  }

  Serial.print("LED1: ");
  Serial.print(LED1);
  Serial.print(" LED2: ");
  Serial.println(LED2);
}

void writeLED1Red() {
  digitalWrite(LEDCommon, LOW);  // Turn off previous color
  digitalWrite(selector0, LOW);  // Selector Logic for channel 0
  digitalWrite(selector1, LOW);
  digitalWrite(selector2, LOW);
  digitalWrite(LEDCommon, HIGH);  // Turn on LED
}
void writeLED1Green() {
  digitalWrite(LEDCommon, LOW);   // Turn off previous color
  digitalWrite(selector0, HIGH);  // Selector Logic for channel 1
  digitalWrite(selector1, LOW);
  digitalWrite(selector2, LOW);
  digitalWrite(LEDCommon, HIGH);  // Turn on LED
}
void writeLED1Blue() {
  digitalWrite(LEDCommon, LOW);  // Turn off previous color
  digitalWrite(selector0, LOW);  // Selector Logic for channel 2
  digitalWrite(selector1, HIGH);
  digitalWrite(selector2, LOW);
  digitalWrite(LEDCommon, HIGH);  // Turn on LED
}
void writeLED2Red() {
  digitalWrite(LEDCommon, LOW);   // Turn off previous color
  digitalWrite(selector0, HIGH);  // Selector Logic for channel 7
  digitalWrite(selector1, HIGH);
  digitalWrite(selector2, HIGH);
  digitalWrite(LEDCommon, HIGH);  // Turn on LED
}
void writeLED2Green() {
  digitalWrite(LEDCommon, LOW);  // Turn off previous color
  digitalWrite(selector0, LOW);  // Selector Logic for channel 6
  digitalWrite(selector1, HIGH);
  digitalWrite(selector2, HIGH);
  digitalWrite(LEDCommon, HIGH);  // Turn on LED
}
void writeLED2Blue() {
  digitalWrite(LEDCommon, LOW);  // Turn off previous color
  digitalWrite(selector0, LOW);  // Selector Logic for channel 4
  digitalWrite(selector1, LOW);
  digitalWrite(selector2, HIGH);
  digitalWrite(LEDCommon, HIGH);  // Turn on LED
}

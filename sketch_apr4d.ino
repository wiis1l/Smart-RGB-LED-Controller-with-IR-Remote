#include <IRremote.hpp>

// RGB LED pins
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(2, ENABLE_LED_FEEDBACK);  // IR receiver on pin 2
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  turnOff();  // Start with LED OFF
}

void loop() {
  if (IrReceiver.decode()) {

    unsigned long code = IrReceiver.decodedIRData.decodedRawData;

    if (code != 0) {         // ignore repeated signals
      Serial.println(code);  // Print code to Serial Monitor for verification

      if (code == 3091726080UL) {  // Red
        setColor(255, 0, 0);
      } else if (code == 3158572800UL) {  // Green
        setColor(0, 255, 0);
      } else if (code == 3208707840UL) {  // Blue
        setColor(0, 0, 255);
      } else if (code == 3910598400UL) {  // LED OFF
        turnOff();
      }
    }

    IrReceiver.resume();  // Prepare for next signal
  }
}

void setColor(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

void turnOff() {
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
}
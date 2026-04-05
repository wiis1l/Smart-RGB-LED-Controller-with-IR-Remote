#Smart RGB LED Controller with IR Remote

A simple but powerful Arduino project that allows you to control an RGB LED using an IR remote.
This project demonstrates the basics of embedded systems, IR communication, and color control using PWM.

✨ Features
🔴 Control Red, Green, Blue colors
📴 Turn LED OFF using remote
📡 IR remote input using receiver module
🎛️ PWM control for smooth color output
🧠 How It Works

The IR receiver detects signals from a remote control and sends the decoded data to the Arduino.
Based on the received code, the Arduino changes the RGB LED color using PWM (analogWrite).

🔧 Components Used
Arduino UNO
IR Receiver Module
RGB LED (Common Cathode)
3 × 220Ω Resistors
Jumper Wires
IR Remote
⚡ Circuit Connections
IR Receiver → Pin 2
Red Pin → Pin 9 (with resistor)
Green Pin → Pin 10 (with resistor)
Blue Pin → Pin 11 (with resistor)
Common Cathode → GND
🎮 Remote Control Mapping
Button Code	Action
3091726080	Red 🔴
3158572800	Green 🟢
3208707840	Blue 🔵
3910598400	Turn OFF ⛔

⚠️ Note: IR codes may vary depending on your remote.

🧪 Code
#include <IRremote.hpp>

int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(2, ENABLE_LED_FEEDBACK);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  turnOff();
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned long code = IrReceiver.decodedIRData.decodedRawData;

    if (code != 0) {
      Serial.println(code);

      if (code == 3091726080UL) setColor(255, 0, 0);
      else if (code == 3158572800UL) setColor(0, 255, 0);
      else if (code == 3208707840UL) setColor(0, 0, 255);
      else if (code == 3910598400UL) turnOff();
    }

    IrReceiver.resume();
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
📸 Preview

(Add your project photos or setup images here)

🚀 Future Improvements
Add brightness control
Add smooth color transitions
Add multiple lighting modes (fade, rainbow)
Control via Bluetooth (mobile app)
Integrate with a smart room system
💡 Author

Made with 💻 by Wissal Arjdal

⭐ Support

If you like this project, consider giving it a ⭐ on GitHub!

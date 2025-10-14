const int buttonPin = 2;
const int rLEDPin = 3;
const int gLEDPin = 6;
const int bLEDPin = 5;

int brightness = 0;
int buttonState = 0;
int ledColor = 0;
bool ButtonPressed = false;
int fadeAmount = 5;
int prevLedColor = -1;


void setup() {
  // put your setup code here, to run once:
  pinMode (rLEDPin, OUTPUT);
  pinMode (gLEDPin, OUTPUT);
  pinMode (bLEDPin, OUTPUT);
  pinMode (buttonPin, INPUT);
}


void loop() {

  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH && !ButtonPressed) {
    ledColor = ledColor + 1;
    ButtonPressed = true;
  // delay(100);
  } 

  if (buttonState == LOW && ButtonPressed) {
    ButtonPressed = false;
  }

  if (ledColor != prevLedColor) {
    prevLedColor = ledColor;
    // jalankan fade sesuai warna ledColor
    switch (ledColor % 8) {
      case 0: fadeColor(255, 255, 255); break; // white
      case 1: fadeColor(0, 255, 255); break;   // cyan
      case 2: fadeColor(255, 0, 255); break;   // magenta
      case 3: fadeColor(255, 255, 0); break;   // yellow
      case 4: fadeColor(0, 0, 255); break;     // blue
      case 5: fadeColor(0, 255, 0); break;     // green
      case 6: fadeColor(255, 0, 0); break;     // red
      case 7: fadeColor(0, 0, 0); break;       // off
    }
  }

  if (ledColor == 0) {
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(gLEDPin, HIGH);
    digitalWrite(bLEDPin, HIGH);
  }

  else if (ledColor == 1) {
    digitalWrite(rLEDPin, LOW);
    digitalWrite(gLEDPin, HIGH);
    digitalWrite(bLEDPin, HIGH);
  }

  else if (ledColor == 2) {
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(gLEDPin, LOW);
    digitalWrite(bLEDPin, HIGH);
  }

  else if (ledColor == 3) {
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(gLEDPin, HIGH);
    digitalWrite(bLEDPin, LOW);
  }

  else if (ledColor == 4) {
    digitalWrite(rLEDPin, LOW);
    digitalWrite(gLEDPin, LOW);
    digitalWrite(bLEDPin, HIGH);
  }

  else if (ledColor == 5) {
    digitalWrite(rLEDPin, LOW);
    digitalWrite(gLEDPin, HIGH);
    digitalWrite(bLEDPin, LOW);
  }

  else if (ledColor == 6) {
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(gLEDPin, LOW);
    digitalWrite(bLEDPin, LOW);
  }

  else if (ledColor == 7) {
    digitalWrite(rLEDPin, LOW);
    digitalWrite(gLEDPin, LOW);
    digitalWrite(bLEDPin, LOW);
  }

  else if(ledColor == 8) {
    ledColor = 0;
  }
  

}

void fadeColor(int rTarget, int gTarget, int bTarget) {
  for (int brightness = 0; brightness <= 255; brightness++) {
    int rVal = (rTarget * brightness) / 255;
    int gVal = (gTarget * brightness) / 255;
    int bVal = (bTarget * brightness) / 255;
    analogWrite(rLEDPin, rVal);
    analogWrite(gLEDPin, gVal);
    analogWrite(bLEDPin, bVal);
    delay(4);
  }
}




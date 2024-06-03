#include <Servo.h>
Servo myservo;
const int waterSens = A0;
int pos = 0;
int LEDState = 0;
int LEDPin = 8;
int buttonPin = 12;
int buttonNew;
int buttonOld = 1;
int In1 = 7;
int In2 = 8;
int ENA = 5;
int SPEED = 255;
int dt = 100;
void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(ENA, OUTPUT);
  myservo.attach(9);
}
void loop() {
  buttonNew = digitalRead(buttonPin);
  Serial.println(buttonNew);
  delay(dt);
  if (buttonOld == 0 && buttonNew == 1) {
    if (LEDState == 0) {
      digitalWrite(LEDPin, HIGH);
      digitalWrite(In1, LOW);
      digitalWrite(In2, HIGH);
      analogWrite(ENA, SPEED);
      LEDState = 1;
    } else {
      digitalWrite(LEDPin, LOW);
      digitalWrite(In1, HIGH);
      digitalWrite(In2, LOW);
      analogWrite(ENA, SPEED);
      LEDState = 0;
    }
  }
  buttonOld = buttonNew;
  int sensorValue = analogRead(waterSens);  //read the water sensor value
  sensorValue = map(sensorValue, 0, 1023, 0, 180);
  if (sensorValue >= 50) {
    for (pos = 0; pos <= 180; pos += 1) {  // goes from 0 degrees to 180 degrees

      // in steps of 1 degree

      myservo.write(pos);  // tell servo to go to position in variable 'pos'

      delay(15);  // waits 15ms for the servo to reach the position
    }

    for (pos = 180; pos >= 0; pos -= 1) {  // goes from 180 degrees to 0 degrees

      myservo.write(pos);  // tell servo to go to position in variable 'pos'

      delay(15);  // waits 15ms for the servo to reach the position
    }


  }
  else 
  {

    myservo.write(0);
  }
  Serial.println(sensorValue);
  delay(20);
}
#include <Servo.h>

Servo trackerServo;

const int ldrLeftPin = A0;   
const int ldrRightPin = A1;  
const int servoPin = 9;      

int ldrLeftValue = 0;
int ldrRightValue = 0;
int servoAngle = 90; 

const int threshold = 15; 

void setup() {
  Serial.begin(9600); 
  trackerServo.attach(servoPin);
  trackerServo.write(servoAngle); 
  delay(1000); 
}

void loop() {
  ldrLeftValue = analogRead(ldrLeftPin);
  ldrRightValue = analogRead(ldrRightPin);

  int difference = abs(ldrLeftValue - ldrRightValue);

  Serial.print("Left LDR: ");
  Serial.print(ldrLeftValue);
  Serial.print(" | Right LDR: ");
  Serial.print(ldrRightValue);
  Serial.print(" | Difference: ");
  Serial.println(difference);

  if (difference > threshold) {
    if (ldrLeftValue > ldrRightValue) {
      servoAngle--;
    } else if (ldrRightValue > ldrLeftValue) {
      servoAngle++;
    }
  }

  servoAngle = constrain(servoAngle, 0, 180);
  trackerServo.write(servoAngle);
  
  delay(20); 
}

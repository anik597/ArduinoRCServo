/*Arduino Car and Tank Control 
 * Written by Anirrudh Krishnan 
 * GitHub link: (https://github.com/anik597/arudino-projects.git) 
 * Modified Sunday March 27th, 2016
 */
#include <VarSpeedServo.h> //This Package allows control over continuous Servo

VarSpeedServo servoLeft; //Dimensionalize the Left Servo Motor
VarSpeedServo servoRight; //Dimensionalize the Right Servo Motor

//This next piece of code allows the Uno to be attached to Specific Pins on the UNO; connect 
//accordingly.
const int servoLeftPin = 5; 
const int servoRightPin = 6; 
int Go = 1; 
int countUp = 1; 
void setup() {
  // Attach Servos to the Motors and talk about speed in microseconds, meaning that 
  // the servos will rotate in this order: 
  servoLeft.attach(servoLeftPin); 
  servoRight.attach(servoRightPin);
  Serial.begin(9600);
  
}

int addToInt(int iNum)
{ 
  //int countUp; 
  countUp = countUp + 1; 
  return countUp;
}

void loop() { 
  int i;
  i = addToInt(countUp);
  if (i <= 500) 
  { 
    Serial.println(i);
    servoLeft.write(-180, 20);
    servoRight.write(180, 20);
    Serial.println("Forward");
    //Serial.println(countUp);
    i = addToInt(countUp);
    Serial.println(i);
    //break; 
    delay(15);
  }
  else if ( i > 500 && i < 600)
  {
   servoLeft.write(180, 0);
   servoRight.write(180, 1);
   Serial.println("Right");
   i = addToInt(countUp);
   delay(15);
  }
  else if (i >= 600 && i < 1400) 
  { 
    servoLeft.write(180, 20);
    servoRight.write(-180, 20);
    Serial.println("Backwards");
    i = addToInt(countUp);
    Serial.println(i);
    delay(15); 
  }
  else if ( i >= 1400 && i < 1500)
  {
    servoLeft.write(180, 1); 
    servoRight.write(180, 0);
    Serial.println("Left");
    i = addToInt(countUp);
    Serial.println(i);
  }
  else if (i >= 1500)
  {
    servoLeft.write(90);
    servoRight.write(90); 
  }
  i = 0; 
}

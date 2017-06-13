/* Arduino Continuous Servo-Powered Tank
 * Written by Anirrudh Krishnan
 * Loyola University Chicago Physics Freshman Project 2015-2016
 * Written for "Tank" designed by Stefan Vlad 
 * Wrtten specifically for the Tank Demonstration, please adapt  
 * Project Guide: Dr. Maria K. Udo
 * Special Thanks: Christopher Riccardi
 */

#include <VarSpeedServo.h> //This Package allows control over continuous Servo

VarSpeedServo servoLeft; //Dimensionalize the Left Servo Motor as an object of VarSpeedServo
VarSpeedServo servoRight; //Dimensionalize the Right Servo Motor as an object of VarSpeedServo
/*This next piece of code allows the Uno to be attached to Specific Pins on the UNO; connect 
accordingly.*/
const int servoLeftPin = 5; //Pin 5
const int servoRightPin = 6; //Pin 6
int countUp = 1; //Since Arduino compiles code in a hybrid fashion (C/C++/Java), we need a variable to count our main integer, i, initialized here.
 
void setup() {
  // Attach Servos to the Motors and talk about speed in microseconds, meaning that the servos will rotate in this order: 
  
  servoLeft.attach(servoLeftPin); // Attach the left haneded servo the left pin
  servoRight.attach(servoRightPin); //Attach the right servo to the right pin
  Serial.begin(9600); //Open the Serial Monitor to make sure everything is ok
  
}

//Write a Method to control the value of the variable, i, which will control the integer. 
int addToInt(int iNum)
{ 
  countUp = countUp + 1; 
  return countUp;
}
//Write a Method for stopping the tank in the middle 
int addToStop(int iNum2) 
{ 
  countUp = countUp + .001;
  return countUp; 
}
//Main loop, here is what the Arduino will execute:

void loop() { 
  
  int i;
  i = addToInt(countUp); //Remember the method we wrote? Here it is! 
  
  if (i >= 1 && i <= 1000) 
  { 
    Serial.println(i); //Use this to make sure your "i" value increases! 
    servoLeft.write(-180, 0); 
    servoRight.write(180, 0);
    Serial.println("Forward");
    i = addToInt(countUp);
    Serial.println(i);
  }

  else if (i >= 1000 && i <= 9000) 
  { 
    //Stop Servo Rotation
    servoLeft.write(90, true);
    servoRight.write(90, true);
    i = addToStop(countUp); 
    Serial.println(i); 
  }

  else if(i >= 9000 && i <= 10800)
  { 
    Serial.println(i); //Use this to make sure your "i" value increases! 
    servoLeft.write(180, 0); 
    servoRight.write(-180, 0);
    Serial.println("Backwards");
    i = addToInt(countUp);
    Serial.println(i);
  }

  else if (i >= 10800)
  {
    servoLeft.write(90);
    servoRight.write(90); 
    exit(0); //exit the loop once and for all; stops the Tank from moving any further
  }
}

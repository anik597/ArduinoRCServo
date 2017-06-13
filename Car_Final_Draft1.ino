#include <VarSpeedServo.h> //This Package allows control over continuous Servo
/* Arduino Continuous Servo-Powered Car
 * Written by Anirrudh Krishnan
 * Loyola University Chicago Physics Freshman Project 2015-2016
 * Written for "Car" designed by Michaela Johnson 
 * Wrtten specifically for the Tank Demonstration, please adapt  
 * Project Guide: Dr. Maria K. Udo
 * Special Thanks: Christopher Riccardi
 * Makes use of Open Source Project VarSpeedServo found at <>
 */

VarSpeedServo servoLeft; //Dimensionalize the Left Servo Motor
VarSpeedServo servoRight; //Dimensionalize the Right Servo Motor

//This next piece of code allows the Uno to be attached to Specific Pins on the UNO; connect 
//accordingly.
const int servoLeftPin = 5; 
const int servoRightPin = 6;  
int countUp = 1; 

void setup() {
  /* Attach Servos to the Motors and talk about speed in microseconds, meaning that 
  the servos will rotate in this order:*/ 
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
  if (i >= 1 && i <= 5000) 
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
  else if ( i > 5000 && i < 15000)
  {
   /*servoLeft.write(180, 255);
   servoRight.write(180, 1);
   Serial.println("Right");
   i = addToInt(countUp);
   delay(30);*/
   servoLeft.write(90);
   servoRight.write(90); 
   i = addToInt(countUp);
   Serial.print("LOL"); 
  }
  else if (i >= 15000 && i < 15700) 
  { 
    /*Serial.println(i);
    servoLeft.write(-180, 20);
    servoRight.write(180, 20);
    Serial.println("Forward");
    //Serial.println(countUp);
    i = addToInt(countUp);
    Serial.println(i);
    //break; 
    delay(15);*/
   servoLeft.write(180,0,false);        // move the servo to 180, fast speed, run background
                                        // write(degrees 0-180, speed 1-255, wait to complete true-false)
  servoRight.write(180,0,true);         // move the servo to 180, fast speed, wait until done
   //myservo1.write(0,1,false);
   
   servoRight.write(0,70,true);
   i = addToInt(countUp);
   
   //delay(30);
  }
  /*else if ( i >= 2100 && i < 3000)
  {
    servoLeft.write(180, 1, true); 
    servoRight.write(180, 0, true);
    Serial.println("Left");
    i = addToInt(countUp);
    Serial.println(i);
  }
  */
  else if (i >= 157000)
  {
    servoLeft.write(90);
    servoRight.write(90); 
    exit(0); //exit the loop once and for all
  }

 
}

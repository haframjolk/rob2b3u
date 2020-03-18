#include "Servo.h"

// Pin 13 has an LED connected on most Arduino boards.
int led = 13;

//motor object
Servo motor; 

//setup
void setup() 
{
       motor.attach(9,1000,2000);
       motor.write(0); 
       pinMode(led, OUTPUT);  
}

//main loop
void loop() 
{

        digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
        motor.write(110);
        delay(2000);               // wait for a second

        digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
        motor.write(0);  
        delay(1000);               // wait for a second

}

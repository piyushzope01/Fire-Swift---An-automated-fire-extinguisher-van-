#include <Servo.h>
Servo ultra_servo;	// create servo object to control a servo
Servo motor_servo;	// create servo object to control a servo
int pos = 0;	// variable to store the servo position
void setup() 
{
	// attaches the servo on pin 10 to the servo object
	ultra_servo.attach(10); 
  motor_servo.attach(9);  
}
void loop() 
{
	// sweeps from 0 degrees to 180 degrees
	for(pos = 0; pos <= 180; pos += 1) 
	{
		ultra_servo.write(pos);
    //motor_servo.write(pos);
		delay(15);
	}
	// sweeps from 180 degrees to 0 degrees
	for(pos = 180; pos>=0; pos-=1)
	{
		ultra_servo.write(pos);
    //motor_servo.write(pos);
		delay(15);
	}
/*
  for(pos = 0; pos <= 180; pos += 1) 
	{
		//ultra_servo.write(pos);
    motor_servo.write(pos);
		delay(15);
	}
	// sweeps from 180 degrees to 0 degrees
	for(pos = 180; pos>=0; pos-=1)
	{
		//ultra_servo.write(pos);
    motor_servo.write(pos);
		delay(15);
	} */
}

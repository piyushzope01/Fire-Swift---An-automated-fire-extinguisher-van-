// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
 
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void loop() {
  uint8_t i;
  
  Serial.print("tick");go();
  delay(5000);
  Serial.print("tock");reverse();
  delay(5000);
  Serial.print("tech");stop();
  delay(1000);
}

void stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void go()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  /*
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
    delay(10);
 }
  */
}

void reverse()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  /*
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
    delay(10);
 }
  */

}

void turn_left()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void turn_right()
{
  
  motor4.run(FORWARD);
  motor3.run(FORWARD);
  motor2.run(BACKWARD);
  motor1.run(BACKWARD);

}
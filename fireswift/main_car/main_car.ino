// Adafruit Motor shield library needed.
#include <AFMotor.h>
#include <Servo.h>
Servo ultra_servo;	// create servo object to control a servo
Servo motor_servo;	// create servo object to control a servo

int pos = 90;	// variable to store the servo position




const int pingPin = 52; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 53; // Echo Pin of Ultrasonic Sensor

// lowest and highest sensor readings:
const int sensorMin = 0;     //  sensor minimum
const int sensorMax = 1024;  // sensor maximum

 int pump=22;


AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  ultra_servo.attach(10); 
  motor_servo.attach(9);

  pinMode(pump, OUTPUT);

  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("main code");

  // turn on motor
  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor3.setSpeed(150);
  motor4.setSpeed(150);
  
  stop();
}

void loop() {
    
   
  long distance;
  go(125);
  check_fire();
  distance=check_distance();
  Serial.print("\n D      : ");
  Serial.print(distance);
  if (distance<30){
    stop();
    sweep_ultra(); }
}


void pump_start()
{
 digitalWrite(pump, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);
}

void pump_stop()
{
  digitalWrite(pump, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);
}

void sweep_pump()
{
  stop();
  int count=0;
  pump_start();
  for (count=0;count<1;count++)
  {
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
      }
  }
  pump_stop();
  go(175);

}

void sweep_ultra()
{
  long left_distance;
  long right_distance;
  
 	for(pos = 90; pos>=0; pos-=1)
	{
		ultra_servo.write(pos);
    //motor_servo.write(pos);
		delay(15);
	}
  left_distance=check_distance();
  for(pos = 0; pos <= 180; pos += 1) 
	{
		ultra_servo.write(pos);
    //motor_servo.write(pos);
		delay(15);
	}
  right_distance=check_distance();

	// sweeps from 180 degrees to 0 degrees
	for(pos = 180; pos>=90; pos-=1)
	{
		ultra_servo.write(pos);
    //motor_servo.write(pos);
		delay(15);
	}
  Serial.print("\n Left  : ");
  Serial.print(left_distance);
  Serial.print("\n Right : ");
  Serial.print(right_distance);

  if (left_distance>right_distance)
  {
    //Serial.print(" turninggg Left <<<<<<<<<<<");
      turn_left(180);
  }
  else
  {
    //Serial.print(" turninggg Right >>>>>>>>>>>>>");
      turn_right(180);
  }

}


long check_distance()
{
  long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   delay(100);
      // Serial.print(inches);
   //Serial.print("in, ");
   //Serial.print(cm);
   //Serial.print("cm");
   //Serial.println();

   return cm;
}

void check_fire()
{
  // read the sensor on analog A0:
	int sensorReading  = analogRead(A8);
  // map the sensor range (four options):
  // ex: 'long  int map(long int, long int, long int, long int, long int)'
	int range = map(sensorReading,  sensorMin, sensorMax, 0, 3);
  
  // range value:
  switch (range) {
  case 0:    // A fire closer than 1.5 feet away.
    Serial.println("** Fire **");
    sweep_pump();
    break;
  case 1:    // A fire between 1-3 feet away.
    Serial.println("**  Distant Fire **");
    break;
  case 2:    // No fire detected.
    Serial.println("No  Fire");
    break;
  }
  delay(1);

}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

void stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void reverse()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  /*
  uint8_t i;
  
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

void go(int s)
{
  speed(s);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  /*

  uint8_t i;
  
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

void turn_left(int s)
{
  speed(s);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(500);
}

void turn_right(int s)
{
  speed(s);
  motor4.run(FORWARD);
  motor3.run(FORWARD);
  motor2.run(BACKWARD);
  motor1.run(BACKWARD);
  delay(500);
}

void speed(int s)
{
  motor1.setSpeed(s);
  motor2.setSpeed(s);
  motor3.setSpeed(s);
  motor4.setSpeed(s);
}
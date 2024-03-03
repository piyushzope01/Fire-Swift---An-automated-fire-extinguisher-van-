#define motorpin0 2 // Direction ch1 front right motor
#define motorpin1 3 // Direction ch2 front left motor
#define motorpin2 4 // Direction ch3 back right motor
#define motorpin3 7 // Direction ch4 back left motor
#define speedpin0 5 //Speed Ch1
#define speedpin1 6 //Speed Ch2
#define speedpin2 9 //Speed Ch3
#define speedpin3 10 //Speed Ch4
int count=0;

void setup() {
//the motor control wires are outputs
pinMode (motorpin0, OUTPUT);
pinMode(motorpin1, OUTPUT);
pinMode(motorpin2, OUTPUT);
pinMode(motorpin3, OUTPUT);
//PWM Pins are outputs
pinMode(speedpin0, OUTPUT);
pinMode(speedpin1, OUTPUT);
pinMode(speedpin2, OUTPUT);
pinMode(speedpin3, OUTPUT);

}

void loop() {
  
    analogWrite(speedpin0,255);
    analogWrite(speedpin1,255);
    analogWrite(speedpin2,255);
    analogWrite(speedpin3,255);
    
  switch (count)
  {
    case 0: //forward
    digitalWrite(motorpin0,1);
    digitalWrite(motorpin1,1);
    digitalWrite(motorpin2,1);
    digitalWrite(motorpin3,1);
    delay(10000);
    count++;
    break;
    
     case 1: //Turn right
    
    analogWrite(speedpin0,50);
    analogWrite(speedpin2,50);
    
    digitalWrite(motorpin0,1);
    digitalWrite(motorpin1,1);
    digitalWrite(motorpin2,1);
    digitalWrite(motorpin3,1);
    delay(1200);
    count++;
    break;
    
    case 2: //backward
    
    digitalWrite(motorpin0,0);
    digitalWrite(motorpin1,0);
    digitalWrite(motorpin2,0);
    digitalWrite(motorpin3,0);
    delay (5000);
    count++;
    break;
    
   
    case 3: //Turn left
    
    analogWrite(speedpin1,50);
    analogWrite(speedpin3,50);
    
    digitalWrite(motorpin0,1);
    digitalWrite(motorpin1,1);
    digitalWrite(motorpin2,1);
    digitalWrite(motorpin3,1);
    delay(1200);
    count++;
    break;
}
}
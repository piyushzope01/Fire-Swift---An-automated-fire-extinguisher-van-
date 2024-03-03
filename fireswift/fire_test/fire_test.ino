// lowest and highest sensor readings:
const int sensorMin = 0;     //  sensor minimum
const int sensorMax = 1024;  // sensor maximum

 int pump=31;
void setup()  {
  // initialize serial communication @ 9600 baud:
  Serial.begin(9600); 
  pinMode(pump, OUTPUT); 
}
void loop() {
  // read the sensor on analog A0:
	int sensorReading  = analogRead(A8);
  // map the sensor range (four options):
  // ex: 'long  int map(long int, long int, long int, long int, long int)'
	int range = map(sensorReading,  sensorMin, sensorMax, 0, 3);
  
  // range value:
  switch (range) {
  case 0:    // A fire closer than 1.5 feet away.
    Serial.println("** Fire **");
    digitalWrite(pump, HIGH);  // turn the LED on (HIGH is the voltage level)
    //delay(5000); 
    break;
  case 1:    // A fire between 1-3 feet away.
    Serial.println("**  Distant Fire **");
    digitalWrite(pump, HIGH);  // turn the LED on (HIGH is the voltage level)
    //delay(5000); 
    break;
  case 2:    // No fire detected.
    Serial.println("No  Fire");
    digitalWrite(pump, 
    );  // turn the LED on (HIGH is the voltage level)
    //delay(5000); 
    break;
  }
  delay(1);  // delay between reads
}
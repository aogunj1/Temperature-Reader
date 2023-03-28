//Variables for readings and calculations
int MyThermistorPin = 0;
int Volt;
float R1 = 10000;
float logR2, R2, Temp;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
  //serial communication at baud rate of 9600 bits per second
Serial.begin(9600);
}

void loop() {
// Read voltage on input pin and store itin the Volt variable
  Volt = analogRead(MyThermistorPin);
  //Calculate resistance based on voltage reading
  R2 = R1 * (1023.0 / (float)Volt - 1.0);
  // take log of resistance value for later calculation
  logR2 = log(R2);
  Temp = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  //Can change to Celcius or Kelvin if you remove calculation below
  Temp = Temp - 273.15;
  Temp = (Temp * 9.0)/ 5.0 + 32.0; 
// Print the temperature
  Serial.print("The Temperature is : "); 
  Serial.print(Temp);
  Serial.println(" F"); 
//Delay to avoid flooding serial port
  delay(500);
}
// https://www.circuitbasics.com/arduino-thermistor-temperature-sensor-tutorial/
#include <max6675.h>
#include <Wire.h>

int thermoDO = 6;
int thermoCLK = 7;
int thermoCS1 = 5;
int thermoCS2 = 4;

MAX6675 thermocouple1(thermoCLK, thermoCS1, thermoDO);
MAX6675 thermocouple2(thermoCLK, thermoCS2, thermoDO);

const int SSR = 2;
const int buttonOne = 7;
const int buttonTwo = 8;

int targetTemp = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(SSR, OUTPUT);
  pinMode(buttonOne, INPUT);
  pinMode(buttonTwo, INPUT);
  
  // wait fror MAX to stabilize
  delay(500);
}

void loop() {
// basic readout test, just print the current temp
  
   Serial.print("C1 = "); 
   Serial.println(thermocouple1.readCelsius());
   Serial.print("c2 = ");
   Serial.println(thermocouple2.readCelsius());

   
 
delay(1000);
}

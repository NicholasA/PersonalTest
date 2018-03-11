// Two k type thermocouples are used to measure the tempriture of a reflow oven
// and a Solid State Relay is used control the heating element
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

//Arrays with the thermal profiles [temp][time in seconds]
const int[2][6] standard = [[0,150,150,250,250,0],[0,100,180,240,260,360]]; 
int startTime = 0;

void setup() {
  Serial.begin(9600);
  time = millis;
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

bool heatingElement(int[][] profile){
  // given a particular profile should at this time the element be turned on.
  int currentTime = millis() - startTime;
  for(int i =1; currentTime <= profile[1][i]; i++){
    int targetTemp = profile[i][0];
    

  }
}

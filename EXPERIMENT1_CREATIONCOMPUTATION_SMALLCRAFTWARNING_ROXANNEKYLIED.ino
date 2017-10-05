/* Kylie Caraway / Dave Foster / Roxanne Baril-Bedard
 * Creation & Computation - Digital Futures, OCAD University
 * Kate Hartman / Nick Puckett
 * 
 * Read an Ultrasonic Proximity Sensor using the NewPing Library https://bitbucket.org/teckel12/arduino-new-ping/downloads/
 * print the value to Serial and scale it using a timer
 * 
 * 
 */
#include <NewPing.h>   //include the library, this is used by the ultrasonic proximity sensor


int triggerPin = 12;   //pin connected to the Trig pin on the sensor
int echoPin = 11;       //pin connected to the Echo pin on the sensor
int maxDistance = 200;  //set the max distance for the sensor to read (helps with errors)
int distanceVal;        //variable to hold the distance val

int sampleRate = 200;   //how fast to sample the value
long lastReading;       //used for the timer
int motorPin = 10;      //pin connected to DC Motor

NewPing proximity1(triggerPin, echoPin, maxDistance);   //sets up the sensor object

void setup() 
{
  Serial.begin(9600);  //start the serial port
  
pinMode(motorPin, OUTPUT);
}

void loop() 
{

  if(millis()-lastReading>=sampleRate) //this very simple statement is the timer,
  { 
  distanceVal = proximity1.ping_cm();  //get the distance value in centimeters

  
  lastReading = millis();


  Serial.print("Distance Reading CM : ");  //print the value to the Serial monitor
  Serial.println(distanceVal);

    
  }
  if(distanceVal>80) // far distance value for sensor
{
  
analogWrite(motorPin,0); // speed of motor resulting from far middle sensor distance value

}
 else if(distanceVal>=20 && distanceVal<=80) // middle distance value for sensor
 {
  
  analogWrite(motorPin,160); // speed of motor resulting from middle sensor distance value
}

 else if(distanceVal<20 && distanceVal>=0) // distance value for close to the sensor
 {

  analogWrite(motorPin,255); //speed of motor resulting from close sensor distance value
 }













 

}

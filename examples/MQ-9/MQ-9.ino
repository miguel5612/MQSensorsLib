/*
  MQUnifiedsensor Library - reading an MQ9

  Demonstrates the use a MQ9 sensor.
  Library originally added 01 may 2019
  by Miguel A Califa, Yersson Carrillo, Ghiordy Contreras, Mario Rodriguez
 
  Added example
  modified 23 May 2019
  by Miguel Califa 

 This example code is in the public domain.

*/

//Include the library
#include <MQUnifiedsensor.h>

//Definitions
#define pin A0 //Analog input 0 of your arduino
#define type 9 //MQ9

//Declare Sensor

MQUnifiedsensor MQ9(pin, type);

void setup() {
  //init the sensor
  MQ9.inicializar(); 
}

void loop() {
  //Read the sensor
  int read =  MQ9.readSensor();
  //Print measurements
  Serial.print("MQ9: ");
  Serial.print(read);
  Serial.println(" PPM");
  //delay 1s to next measure
  delay(1000);
}

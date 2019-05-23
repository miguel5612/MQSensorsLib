/*
  MQUnifiedsensor Library - reading an MQ4

  Demonstrates the use a MQ4 sensor.
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
#define type 4 //MQ4

//Declare Sensor

MQUnifiedsensor MQ4(pin, type);

void setup() {
  //init the sensor
  MQ4.inicializar(); 
}

void loop() {
  //Read the sensor
  int read =  MQ4.readSensor();
  //Print measurements
  Serial.print("MQ4: ");
  Serial.print(read);
  Serial.println(" PPM");
  //delay 1s to next measure
  delay(1000);
}

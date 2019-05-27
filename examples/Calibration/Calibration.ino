/*
  MQUnifiedsensor Library - calibrating an MQ2

  Demonstrates the use a MQ2 sensor.
  Library originally added 01 may 2019
  by Miguel A Califa, Yersson Carrillo, Ghiordy Contreras, Mario Rodriguez
 
  Added example
  modified 27 May 2019
  by Miguel Califa 

 This example code is in the public domain.

*/

//Include the library
#include <MQUnifiedsensor.h>

//Definitions
#define pin A0 //Analog input 0 of your arduino
#define type 2 //MQ2

//Declare Sensor

MQUnifiedsensor MQ2(pin, type);
unsigned long contador = 0;

void setup() {
  //Init serial port
  Serial.begin(115200);
  //init the sensor
  MQ2.inicializar(); 
  //Print in serial monitor
  Serial.print("MQ2 - Calibracion");
  Serial.print("Note - Make sure you are in a clean room and the sensor has pre-heated almost 4 hours");
  Serial.print("Autonumeric, lecture");
}

void loop() {
  //Read the sensor and print in serial port
  int lecture =  MQ2.calibrate();
  //Print in serial monitor
  Serial.print(String(contador) + ",");
  Serial.println(lecture);
  //Increment counter
  contador++;
  //Wait to measure next sample
  delay(400);
}

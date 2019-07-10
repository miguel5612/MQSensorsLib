/*
  MQUnifiedsensor Library - implementing an alcoholimeter

  Demonstrates the use a MQ3 sensor.
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
#define type 3 //MQ3

//Declare Sensor

MQUnifiedsensor MQ3(pin, type);

void setup() {
  //init the sensor
  /*****************************  MQInicializar****************************************
  Input:  pin, type 
  Output:  
  Remarks: This function create the sensor object.
  ************************************************************************************/ 
  MQ3.inicializar(); 
}

void loop() {
  /*****************************  MQReadSensor  ****************************************
  Input:   Gas - Serial print flag
  Output:  Value in PPM
  Remarks: This function use readPPM to read the value in PPM the gas in the air.
  ************************************************************************************/ 
  //Read the sensor and print in serial port
  //Lecture will be saved in lecture variable
  int lecture =  MQ3.readSensor(""); // Return Alcohol concentration
  int gL = lecture/1000;
  Serial.print("Alcohol ppm measured: ");
  Serial.print(lecture);
  Serial.println("ppm");

  Serial.print("Alcohol gL measured: ");
  Serial.print(gL);
  Serial.println("g/L");
}

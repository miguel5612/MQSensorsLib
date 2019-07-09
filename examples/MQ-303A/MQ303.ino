/*
  MQUnifiedsensor Library - reading an MQ4

  Demonstrates the use a MQ303 sensor.
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
#define type 303 //MQ303

//Declare Sensor

MQUnifiedsensor MQ303(pin, type);

void setup() {
   //init the sensor
  /*****************************  MQInicializar****************************************
  Input:  pin, type 
  Output:  
  Remarks: This function create the sensor object.
  ************************************************************************************/ 
  MQ303.inicializar(); 
}

void loop() {
  /*****************************  MQReadSensor  ****************************************
  Input:   Gas - Serial print flag
  Output:  Value in PPM
  Remarks: This function use readPPM to read the value in PPM the gas in the air.
  ************************************************************************************/ 
  //Read the sensor and print in serial port
  //Lecture will be saved in lecture variable
  int lecture =  MQ303.readSensor("", true); // Return Isobutano concentration
  // Options, uncomment where you need
  //int lecture =  MQ303.readSensor("Iso_butano", true); // Return Iso_butano concentration
  //int lecture =  MQ303.readSensor("Hydrogeno", true); // Return Hydrogeno concentration
  //int lecture =  MQ303.readSensor("Ethanol", true); // Return Ethanol concentration
  delay(400);
}

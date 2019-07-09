/*
  MQUnifiedsensor Library - reading an MQ131

  Demonstrates the use a MQ131 sensor.
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
#define type 131 //MQ131

//Declare Sensor

MQUnifiedsensor MQ131(pin, type);

void setup() {
   //init the sensor
  /*****************************  MQInicializar****************************************
  Input:  pin, type 
  Output:  
  Remarks: This function create the sensor object.
  ************************************************************************************/ 
  MQ131.inicializar(); 
}

void loop() {
  /*****************************  MQReadSensor  ****************************************
  Input:   Gas - Serial print flag
  Output:  Value in PPM
  Remarks: This function use readPPM to read the value in PPM the gas in the air.
  ************************************************************************************/ 
  //Read the sensor and print in serial port
  //Lecture will be saved in lecture variable
  int lecture =  MQ131.readSensor("", true); // Return O3 concentration
  // Options, uncomment where you need
  //int lecture =  MQ131.readSensor("NOx", true); // Return NOx concentration
  //int lecture =  MQ131.readSensor("CL2", true); // Return CL2 concentration
  //int lecture =  MQ131.readSensor("O3", true); // Return O3 concentration
}

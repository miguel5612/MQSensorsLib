/*
  MQUnifiedsensor Library - reading an MQ3

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
  int lecture =  MQ3.readSensor("", true); // Return Alcohol concentration
  // Options, uncomment where you need
  //int lecture =  MQ3.readSensor("CH4", true); // Return CH4 concentration
  //int lecture =  MQ3.readSensor("LPG", true); // Return LPG concentration
  //int lecture =  MQ3.readSensor("CO", true); // Return CO concentration
  //int lecture =  MQ3.readSensor("Alcohol", true); // Return Alcohol concentration
  //int lecture =  MQ3.readSensor("Hexane", true); // Return Hexane concentration
  //int lecture =  MQ3.readSensor("Benzene", true); // Return Benzene concentration
}

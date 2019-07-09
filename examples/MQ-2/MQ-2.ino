/*
  MQUnifiedsensor Library - reading an MQ2

  Demonstrates the use a MQ2 sensor.
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
#define type 2 //MQ2

/*****************************  MQInicializar****************************************
  Input:  pin, type 
  Output:  
  Remarks: This function create the sensor object.
  ************************************************************************************/ 
//Declare Sensor
MQUnifiedsensor MQ2(pin, type);

void setup() {
  //Init serial port
  Serial.begin(115200);
  /*****************************  MQInicializar****************************************
  Input:   
  Output:  
  Remarks: This function configure the pinMode
  ************************************************************************************/ 
  //init the sensor
  MQ2.inicializar(); 
}

  void loop() {
  /*****************************  MQReadSensor  ****************************************
  Input:   Gas - Serial print flag
  Output:  Value in PPM
  Remarks: This function use readPPM to read the value in PPM the gas in the air.
  ************************************************************************************/ 
  //Read the sensor and print in serial port
  //Lecture will be saved in lecture variable
  int lecture =  MQ2.readSensor("", true); // Return LPG concentration
  // Options, uncomment where you need
  //int lecture =  MQ2.readSensor("H2", true); // Return H2 concentration
  //int lecture =  MQ2.readSensor("LPG", true); // Return LPG concentration
  //int lecture =  MQ2.readSensor("CO", true); // Return CO concentration
  //int lecture =  MQ2.readSensor("Alcohol", true); // Return Alcohol concentration
  //int lecture =  MQ2.readSensor("Propane", true); // Return Propane concentration
  //int lecture =  MQ2.readSensor("Benzene", true); // Return Benzene concentration
  delay(400);
}

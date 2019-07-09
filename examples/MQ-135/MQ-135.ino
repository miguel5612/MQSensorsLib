/*
  MQUnifiedsensor Library - reading an MQ135

  Demonstrates the use a MQ135 sensor.
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
#define type 135 //MQ135

//Declare Sensor

MQUnifiedsensor MQ135(pin, type);

void setup() {
   //init the sensor
  /*****************************  MQInicializar****************************************
  Input:  pin, type 
  Output:  
  Remarks: This function create the sensor object.
  ************************************************************************************/ 
  MQ135.inicializar(); 
}

void loop() {
   /*****************************  MQReadSensor  ****************************************
  Input:   Gas - Serial print flag
  Output:  Value in PPM
  Remarks: This function use readPPM to read the value in PPM the gas in the air.
  ************************************************************************************/ 
  //Read the sensor and print in serial port
  //Lecture will be saved in lecture variable
  int lecture =  MQ135.readSensor("", true); // Return NH4 concentration
  // Options, uncomment where you need
  //int lecture =  MQ135.readSensor("CO", true); // Return CO concentration
  //int lecture =  MQ135.readSensor("Alcohol", true); // Return Alcohol concentration
  //int lecture =  MQ135.readSensor("CO2", true); // Return CO2 concentration
  //int lecture =  MQ135.readSensor("Tolueno", true); // Return Tolueno concentration
  //int lecture =  MQ135.readSensor("NH4", true); // Return NH4 concentration
  //int lecture =  MQ135.readSensor("Acetona", true); // Return Acetona concentration
}

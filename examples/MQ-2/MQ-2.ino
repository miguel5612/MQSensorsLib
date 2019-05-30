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
  int lecture =  MQ2.readSensor("", true);
  delay(400);
}

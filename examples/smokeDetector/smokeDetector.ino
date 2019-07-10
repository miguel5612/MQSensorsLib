/*
  MQUnifiedsensor Library - smokeDetector
  
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
#define type 4 //MQ4

//Declare Sensor
MQUnifiedsensor MQ4(pin, type);

void setup() {
  //Init serial port
  Serial.begin(115200);
  /*****************************  MQInicializar****************************************
  Input:   
  Output:  
  Remarks: This function configure the pinMode
  ************************************************************************************/ 
  //init the sensor
  MQ4.inicializar(); 
}

  void loop() {
  /*****************************  MQReadSensor  ****************************************
  Input:   Gas - Serial print flag
  Output:  Value in PPM
  Remarks: This function use readPPM to read the value in PPM the gas in the air.
  ************************************************************************************/ 
  //Read the sensor and print in serial port
  //Lecture will be saved in lecture variable
  int lecture =  MQ4.readSensor("smoke"); // Return smoke concentration
  Serial.print("MQ4 smoke ppm lecture: ");
  Serial.print(lecture);
  Serial.println(" ppm");
  delay(400);
}

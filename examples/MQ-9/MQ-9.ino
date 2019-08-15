/*
  MQUnifiedsensor Library - reading an MQ9

  Demonstrates the use a MQ9 sensor.
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
#define type 9 //MQ9
//#define calibration_button 13 //Pin to calibrate your sensor

//Declare Sensor
MQUnifiedsensor MQ9(pin, type);

//Variables
float CO, CH4, LPG;

void setup() {
  Serial.begin(9600); //Init serial port
  //init the sensor
  /*****************************  MQInicializar****************************************
  Input:  pin, type 
  Output:  
  Remarks: This function create the sensor object.
  ************************************************************************************/ 
  MQ9.inicializar(); 
  //pinMode(calibration_button, INPUT);
}

void loop() {
  MQ9.update(); // Update data, the arduino will be read the voltaje in the analog pin
  /*
  //Rutina de calibracion - Uncomment if you need (setup too and header)
  if(calibration_button)
  {
    float R0 = MQ9.calibrate();
    MQ9.setR0(R0):
  }
  */
 /*****************************  MQReadSensor  ****************************************
  Input:   Gas - Serial print flag
  Output:  Value in PPM
  Remarks: This function use readPPM to read the value in PPM the gas in the air.
  ************************************************************************************/ 
  //Read the sensor and print in serial port
  //Lecture will be saved in lecture variable
  //float lecture =  MQ9.readSensor("", true); // Return LPG concentration
  // Options, uncomment where you need
  LPG =  MQ9.readSensor("LPG"); // Return LPG concentration
  CH4 =  MQ9.readSensor("CH4"); // Return CH4 concentration
  CO =  MQ9.readSensor("CO"); // Return CO concentration
  
  Serial.println("***************************");
  Serial.println("Lectures for MQ-9");
  Serial.print("Volt: ");Serial.print(MQ9.getVoltage(false));Serial.println(" V"); 
  Serial.print("R0: ");Serial.print(MQ9.getR0());Serial.println(" Ohm"); 
  Serial.print("CO: ");Serial.print(CO,2);Serial.println(" ppm");
  Serial.print("LPG: ");Serial.print(LPG,2);Serial.println(" ppm");
  Serial.print("CH4: ");Serial.print(CH4,2);Serial.println(" ppm");
  Serial.println("***************************");  
}

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
//#define calibration_button 13 //Pin to calibrate your sensor

//Declare Sensor
MQUnifiedsensor MQ2(pin, type);

//Variables
float H2, LPG, CO, Alcohol, Propane, Benzene;

void setup() {
  Serial.begin(9600); //Init serial port
  /*****************************  MQInicializar****************************************
  Input:   
  Output:  
  Remarks: This function configure the pinMode
  ************************************************************************************/ 
  //init the sensor
  MQ2.inicializar(); 
  //pinMode(calibration_button, INPUT);
}

  void loop() {
  MQ2.update(); // Update data, the arduino will be read the voltaje in the analog pin
  /*
  //Rutina de calibracion - Uncomment if you need (setup too and header)
  if(calibration_button)
  {
    float R0 = MQ2.calibrate();
    MQ2.setR0(R0):
  }
  */
  /*****************************  MQReadSensor  ****************************************
  Input:   Gas - Serial print flag
  Output:  Value in PPM
  Remarks: This function use readPPM to read the value in PPM the gas in the air.
  ************************************************************************************/ 
  //Read the sensor and print in serial port
  //Lecture will be saved in lecture variable
  //float lecture =  MQ2.readSensor("", true); // Return LPG concentration
  // Options, uncomment where you need
  H2 =  MQ2.readSensor("H2"); // Return H2 concentration
  LPG =  MQ2.readSensor("LPG"); // Return LPG concentration
  CO =  MQ2.readSensor("CO"); // Return CO concentration
  Alcohol =  MQ2.readSensor("Alcohol"); // Return Alcohol concentration
  Propane =  MQ2.readSensor("Propane"); // Return Propane concentration
  
  Serial.println("***************************");
  Serial.println("Lectures for MQ-2");
  Serial.print("Volt: ");Serial.print(MQ2.getVoltage(false));Serial.println(" V"); 
  Serial.print("R0: ");Serial.print(MQ2.getR0());Serial.println(" Ohm"); 
  Serial.print("H2: ");Serial.print(H2,2);Serial.println(" ppm");
  Serial.print("LPG: ");Serial.print(LPG,2);Serial.println(" ppm");
  Serial.print("CO: ");Serial.print(CO,2);Serial.println(" ppm");
  Serial.print("Alcohol: ");Serial.print(Alcohol,2);Serial.println(" ppm");
  Serial.print("Propane: ");Serial.print(Propane,2);Serial.println(" ppm");
  Serial.println("***************************");
}

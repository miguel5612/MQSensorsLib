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
//#define calibration_button 13 //Pin to calibrate your sensor

//Declare Sensor
MQUnifiedsensor MQ3(pin, type);

//Variables
float CH4, LPG, CO, Alcohol, Hexane, Benzine;

void setup() {
  Serial.begin(9600); //Init serial port
  //init the sensor
  /*****************************  MQInicializar****************************************
  Input:  pin, type 
  Output:  
  Remarks: This function create the sensor object.
  ************************************************************************************/ 
  MQ3.inicializar(); 
  //pinMode(calibration_button, INPUT);
}

void loop() {
  MQ3.update(); // Update data, the arduino will be read the voltaje in the analog pin
  /*
  //Rutina de calibracion - Uncomment if you need (setup too and header)
  if(calibration_button)
  {
    float R0 = MQ3.calibrate();
    MQ3.setR0(R0):
  }
  */
  /*****************************  MQReadSensor  ****************************************
  Input:   Gas - Serial print flag
  Output:  Value in PPM
  Remarks: This function use readPPM to read the value in PPM the gas in the air.
  ************************************************************************************/ 
  //Read the sensor and print in serial port
  //Lecture will be saved in lecture variable
  //float lecture =  MQ3.readSensor("", true); // Return Alcohol concentration
  // Options, uncomment where you need
  CH4 =  MQ3.readSensor("CH4"); // Return CH4 concentration
  LPG =  MQ3.readSensor("LPG"); // Return LPG concentration
  CO =  MQ3.readSensor("CO"); // Return CO concentration
  Alcohol =  MQ3.readSensor("Alcohol"); // Return Alcohol concentration
  Hexane =  MQ3.readSensor("Hexane"); // Return Hexane concentration
  Benzine =  MQ3.readSensor("Benzene"); // Return Benzene concentration

  Serial.println("***************************");
  Serial.println("Lectures for MQ-3");
  Serial.print("Volt: ");Serial.print(MQ3.getVoltage(false));Serial.println(" V"); 
  Serial.print("R0: ");Serial.print(MQ3.getR0());Serial.println(" Ohm"); 
  Serial.print("CH4: ");Serial.print(CH4,2);Serial.println(" mg/L");
  Serial.print("LPG: ");Serial.print(LPG,2);Serial.println(" mg/L");
  Serial.print("CO: ");Serial.print(CO,2);Serial.println(" mg/L");
  Serial.print("Alcohol: ");Serial.print(Alcohol,2);Serial.println(" mg/L");
  Serial.print("Hexane: ");Serial.print(Hexane,2);Serial.println(" mg/L");
  Serial.print("Benzine: ");Serial.print(Benzine,2);Serial.println(" mg/L");
  Serial.println("***************************");
  
}
/*
  MQUnifiedsensor Library - reading an MQ8

  Demonstrates the use a MQ8 sensor.
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
#define type 8 //MQ8
//#define calibration_button 13 //Pin to calibrate your sensor

//Declare Sensor
MQUnifiedsensor MQ8(pin, type);

//Variables
float H2, LPG, CH4, CO, Alcohol;

void setup() {
  Serial.begin(9600); //Init serial port
   //init the sensor
  /*****************************  MQInicializar****************************************
  Input:  pin, type 
  Output:  
  Remarks: This function create the sensor object.
  ************************************************************************************/ 
  MQ8.inicializar(); 
  //pinMode(calibration_button, INPUT);
}

void loop() {
  MQ8.update(); // Update data, the arduino will be read the voltaje in the analog pin
  /*
  //Rutina de calibracion - Uncomment if you need (setup too and header)
  if(calibration_button)
  {
    float R0 = MQ8.calibrate();
    MQ8.setR0(R0):
  }
  */
  /*****************************  MQReadSensor  ****************************************
  Input:   Gas - Serial print flag
  Output:  Value in PPM
  Remarks: This function use readPPM to read the value in PPM the gas in the air.
  ************************************************************************************/ 
  //Read the sensor and print in serial port
  //Lecture will be saved in lecture variable
  //float lecture =  MQ8.readSensor("", true); // Return H2 concentration
  // Options, uncomment where you need
  H2 =  MQ8.readSensor("H2"); // Return CH4 concentration
  LPG =  MQ8.readSensor("LPG"); // Return LPG concentration
  CH4 =  MQ8.readSensor("CH4"); // Return CH4 concentration
  CO =  MQ8.readSensor("CO"); // Return CO concentration
  Alcohol =  MQ8.readSensor("Alcohol"); // Return Alcohol concentration
  
  Serial.println("***************************");
  Serial.println("Lectures for MQ-8");
  Serial.print("Volt: ");Serial.print(MQ8.getVoltage(false));Serial.println(" V"); 
  Serial.print("R0: ");Serial.print(MQ8.getR0());Serial.println(" Ohm"); 
  Serial.print("H2: ");Serial.print(H2,2);Serial.println(" ppm");
  Serial.print("LPG: ");Serial.print(LPG,2);Serial.println(" ppm");
  Serial.print("CH4: ");Serial.print(CH4,2);Serial.println(" ppm");
  Serial.print("CO: ");Serial.print(CO,2);Serial.println(" ppm");
  Serial.print("Alcohol: ");Serial.print(Alcohol,2);Serial.println(" ppm");
  Serial.println("***************************");  
}

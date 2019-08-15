/*
  MQUnifiedsensor Library - reading an MQ4

  Demonstrates the use a MQ6 sensor.
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
#define type 6 //MQ6
//#define calibration_button 13 //Pin to calibrate your sensor

//Declare Sensor
MQUnifiedsensor MQ6(pin, type);

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
  MQ6.inicializar(); 
  //pinMode(calibration_button, INPUT);
}

void loop() {
  MQ6.update(); // Update data, the arduino will be read the voltaje in the analog pin
  /*
  //Rutina de calibracion - Uncomment if you need (setup too and header)
  if(calibration_button)
  {
    float R0 = MQ6.calibrate();
    MQ6.setR0(R0):
  }
  */
  /*****************************  MQReadSensor  ****************************************
  Input:   Gas - Serial print flag
  Output:  Value in PPM
  Remarks: This function use readPPM to read the value in PPM the gas in the air.
  ************************************************************************************/ 
  //Read the sensor and print in serial port
  //Lecture will be saved in lecture variable
  //float lecture =  MQ6.readSensor("", true); // Return CH4 concentration
  // Options, uncomment where you need
  H2 =  MQ6.readSensor("H2"); // Return H2 concentration
  LPG =  MQ6.readSensor("LPG"); // Return LPG concentration
  CH4 =  MQ6.readSensor("CH4"); // Return CH4 concentration
  CO =  MQ6.readSensor("CO"); // Return CO concentration
  Alcohol =  MQ6.readSensor("Alcohol"); // Return Alcohol concentration

  Serial.println("***************************");
  Serial.println("Lectures for MQ-6");
  Serial.print("Volt: ");Serial.print(MQ6.getVoltage(false));Serial.println(" V"); 
  Serial.print("R0: ");Serial.print(MQ6.getR0());Serial.println(" Ohm"); 
  Serial.print("H2: ");Serial.print(H2,2);Serial.println(" ppm");
  Serial.print("LPG: ");Serial.print(LPG,2);Serial.println(" ppm");
  Serial.print("CH4: ");Serial.print(CH4,2);Serial.println(" ppm");
  Serial.print("CO: ");Serial.print(CO,2);Serial.println(" ppm");
  Serial.print("Alcohol: ");Serial.print(Alcohol,2);Serial.println(" ppm");
  Serial.println("***************************");  
}

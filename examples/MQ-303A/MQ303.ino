/*
  MQUnifiedsensor Library - reading an MQ4

  Demonstrates the use a MQ303 sensor.
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
#define type 303 //MQ303
//#define calibration_button 13 //Pin to calibrate your sensor

//Declare Sensor
MQUnifiedsensor MQ303(pin, type);

//Variables
float Iso_butano, Hydrogeno, Ethanol;

void setup() {
  Serial.begin(9600); //Init serial port
   //init the sensor
  /*****************************  MQInicializar****************************************
  Input:  pin, type 
  Output:  
  Remarks: This function create the sensor object.
  ************************************************************************************/ 
  MQ303.inicializar(); 
  //pinMode(calibration_button, INPUT);
}

void loop() {
  MQ303.update();
  /*
  //Rutina de calibracion - Uncomment if you need (setup too and header)
  if(calibration_button)
  {
    float R0 = MQ303.calibrate();
    MQ303.setR0(R0):
  }
  */
  /*****************************  MQReadSensor  ****************************************
  Input:   Gas - Serial print flag
  Output:  Value in PPM
  Remarks: This function use readPPM to read the value in PPM the gas in the air.
  ************************************************************************************/ 
  //Read the sensor and print in serial port
  //Lecture will be saved in lecture variable
  //float lecture =  MQ303.readSensor("", true); // Return Isobutano concentration
  // Options, uncomment where you need
  Iso_butano =  MQ303.readSensor("Iso_butano"); // Return Iso_butano concentration
  Hydrogeno =  MQ303.readSensor("Hydrogeno"); // Return Hydrogeno concentration
  Ethanol =  MQ303.readSensor("Ethanol"); // Return Ethanol concentration
  
  Serial.println("***************************");
  Serial.println("Lectures for MQ-303");
  Serial.print("Volt: ");Serial.print(MQ303.getVoltage(false));Serial.println(" V"); 
  Serial.print("R0: ");Serial.print(MQ303.getR0());Serial.println(" Ohm"); 
  Serial.print("Iso_butano: ");Serial.print(Iso_butano,2);Serial.println(" ppm");
  Serial.print("Hydrogeno: ");Serial.print(Hydrogeno,2);Serial.println(" ppm");
  Serial.print("Ethanol: ");Serial.print(Ethanol,2);Serial.println(" ppm");
  Serial.println("***************************");  

}

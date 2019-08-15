/*
  MQUnifiedsensor Library - reading an MQ131

  Demonstrates the use a MQ131 sensor.
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
#define type 131 //MQ131
//#define calibration_button 13 //Pin to calibrate your sensor

//Declare Sensor
MQUnifiedsensor MQ131(pin, type);

//Variables
float NOx, CL2, O3;

void setup() {
  Serial.begin(9600); //Init serial port
   //init the sensor
  /*****************************  MQInicializar****************************************
  Input:  pin, type 
  Output:  
  Remarks: This function create the sensor object.
  ************************************************************************************/ 
  MQ131.inicializar(); 
  //pinMode(calibration_button, INPUT);
}

void loop() {
  MQ131.update(); // Update data, the arduino will be read the voltaje in the analog pin
   /*
  //Rutina de calibracion - Uncomment if you need (setup too and header)
  if(calibration_button)
  {
    float R0 = MQ131.calibrate();
    MQ131.setR0(R0):
  }
  */
  /*****************************  MQReadSensor  ****************************************
  Input:   Gas - Serial print flag
  Output:  Value in PPM
  Remarks: This function use readPPM to read the value in PPM the gas in the air.
  ************************************************************************************/ 
  //Read the sensor and print in serial port
  //Lecture will be saved in lecture variable
  //float lecture =  MQ131.readSensor("", true); // Return O3 concentration
  // Options, uncomment where you need
  NOx =  MQ131.readSensor("NOx"); // Return NOx concentration
  CL2 =  MQ131.readSensor("CL2"); // Return CL2 concentration
  O3 =  MQ131.readSensor("O3"); // Return O3 concentration

  Serial.println("***************************");
  Serial.println("Lectures for MQ-131");
  Serial.print("Volt: ");Serial.print(MQ131.getVoltage(false));Serial.println(" V"); 
  Serial.print("R0: ");Serial.print(MQ131.getR0());Serial.println(" Ohm"); 
  Serial.print("NOx: ");Serial.print(NOx,2);Serial.println(" ppm");
  Serial.print("CL2: ");Serial.print(CL2,2);Serial.println(" ppm");
  Serial.print("O3: ");Serial.print(O3,2);Serial.println(" ppm");
  Serial.println("***************************");  
}

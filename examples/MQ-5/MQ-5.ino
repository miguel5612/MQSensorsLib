/*
  MQUnifiedsensor Library - reading an MQ5

  Demonstrates the use a MQ5 sensor.
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
#define type 5 //MQ5
//#define calibration_button 13 //Pin to calibrate your sensor

//Declare Sensor
MQUnifiedsensor MQ5(pin, type);

//Variables
float H2, LPG, CH4, CO, smoke;

void setup() {
  Serial.begin(9600); //Init serial port
   //init the sensor
  /*****************************  MQInicializar****************************************
  Input:  pin, type 
  Output:  
  Remarks: This function create the sensor object.
  ************************************************************************************/ 
  MQ5.inicializar(); 
  //pinMode(calibration_button, INPUT);
}

void loop() {

  MQ5.update(); // Update data, the arduino will be read the voltaje in the analog pin
  /*
  //Rutina de calibracion - Uncomment if you need (setup too and header)
  if(calibration_button)
  {
    float R0 = MQ5.calibrate();
    MQ5.setR0(R0):
  }
  */
  /*****************************  MQReadSensor  ****************************************
  Input:   Gas - Serial print flag
  Output:  Value in PPM
  Remarks: This function use readPPM to read the value in PPM the gas in the air.
  ************************************************************************************/ 
  //Read the sensor and print in serial port
  //Lecture will be saved in lecture variable
  //float lecture =  MQ5.readSensor("", true); // Return H2 concentration
  // Options, uncomment where you need
  H2 =  MQ5.readSensor("H2"); // Return H2 concentration
  LPG =  MQ5.readSensor("LPG"); // Return LPG concentration
  CH4 =  MQ5.readSensor("CH4"); // Return CH4 concentration
  CO =  MQ5.readSensor("CO"); // Return CO concentration
  smoke =  MQ5.readSensor("smoke"); // Return smoke concentration

  Serial.println("***************************");
  Serial.println("Lectures for MQ-5");
  Serial.print("Volt: ");Serial.print(MQ5.getVoltage(false));Serial.println(" V"); 
  Serial.print("R0: ");Serial.print(MQ5.getR0());Serial.println(" Ohm"); 
  Serial.print("H2: ");Serial.print(H2,2);Serial.println(" ppm");
  Serial.print("LPG: ");Serial.print(LPG,2);Serial.println(" ppm");
  Serial.print("CH4: ");Serial.print(CH4,2);Serial.println(" ppm");
  Serial.print("CO: ");Serial.print(CO,2);Serial.println(" ppm");
  Serial.print("smoke: ");Serial.print(smoke,2);Serial.println(" ppm");
  Serial.println("***************************");  
}

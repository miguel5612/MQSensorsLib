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
#define placa "Arduino UNO"
#define Voltage_Resolution 5
#define pin A0 //Analog input 0 of your arduino
#define type "MQ-3" //MQ3
#define ADC_Bit_Resolution 10 // For arduino UNO/MEGA/NANO
//#define calibration_button 13 //Pin to calibrate your sensor

//Declare Sensor
MQUnifiedsensor MQ3(placa, Voltage_Resolution, ADC_Bit_Resolution, pin, type);

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
  MQ3.setRegressionMethod("Exponential");
  MQ3.setA(4.8387); MQ3.setB(-2.68); // Configurate the ecuation values to get Benzene concentration
  
  /* 
    //Si el valor de RL es diferente a 10K por favor asigna tu valor de RL con el siguiente metodo:
    MQ3.setRL(10);
  */

  MQ3.init(); 
  MQ3.serialDebug(true);
  //pinMode(calibration_button, INPUT);
}

void loop() {
  MQ3.update(); // Update data, the arduino will be read the voltage on the analog pin
  MQ3.readSensor(); // Sensor will read PPM concentration using the a and b values setted before or on setup
  MQ3.serialDebug(); // Will print the table on the serial port
  /*
  //Rutina de calibracion - Uncomment if you need (setup too and header)
  if(calibration_button)
  {
    float R0 = MQ3.calibrate();
    MQ3.setR0(R0);
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
  /*
  MQ3.setA(2*10^31); MQ3.setB(19.01); // Configurate the ecuation values
  CH4 =  MQ3.readSensor(); // Return CH4 concentration

  MQ3.setA(44771); MQ3.setB(-3.245); // Configurate the ecuation values
  LPG =  MQ3.readSensor(); // Return LPG concentration

  MQ3.setA(521853); MQ3.setB(-3.821); // Configurate the ecuation values
  CO =  MQ3.readSensor(); // Return CO concentration
  
  MQ3.setA(0.3934); MQ3.setB(-1.504); // Configurate the ecuation values
  Alcohol =  MQ3.readSensor(); // Return Alcohol concentration
  
  MQ3.setA(7585.3); MQ3.setB(-2.849); // Configurate the ecuation values
  Hexane =  MQ3.readSensor(); // Return Hexane concentration

  MQ3.setA(4.8387); MQ3.setB(-2.68); // Configurate the ecuation values
  Benzine =  MQ3.readSensor(); // Return Benzene concentration
  */

  /*
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
  */
}
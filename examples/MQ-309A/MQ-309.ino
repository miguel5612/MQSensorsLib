/*
  MQUnifiedsensor Library - reading an MQ309

  Demonstrates the use a MQ309 sensor.
  Library originally added 01 may 2019
  by Miguel A Califa, Yersson Carrillo, Ghiordy Contreras, Mario Rodriguez
 
  Added example
  modified 23 May 2019
  by Miguel Califa 

  Updated library usage
  modified 26 March 2020
  by Miguel Califa 

 This example code is in the public domain.

*/

//Include the library
#include <MQUnifiedsensor.h>

//Definitions
#define placa "Arduino UNO"
#define Voltage_Resolution 5
#define pin A0 //Analog input 0 of your arduino
#define type "MQ-309" //MQ309
#define ADC_Bit_Resolution 10 // For arduino UNO/MEGA/NANO
//#define calibration_button 13 //Pin to calibrate your sensor

//Declare Sensor
MQUnifiedsensor MQ309(placa, Voltage_Resolution, ADC_Bit_Resolution, pin, type);

void setup() {
  //Init the serial port communication - to debug the library
  Serial.begin(9600); //Init serial port

  //Set math model to calculate the PPM concentration and the value of constants
  MQ309.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ309.setA(1000000); MQ309.setB(-4.01); // Configurate the ecuation values to get CO concentration

  /*
    Exponential regression:
  GAS     | a       | b
  H2      | 1532.9  | -1.951
  CH4     | 980.24  | -1.68
  CO      | 1000000 | -4.01
  ALCOHOL | 473622  | -3.647
  */

  // Calibration setup
  MQ309.setR0(10);

  /* 
    //If the RL value is different from 10K please assign your RL value with the following method:
    MQ309.setRL(10);
  */

  /*****************************  MQ Init ********************************************/ 
  //Remarks: Configure the pin of arduino as input.
  /************************************************************************************/ 
  MQ309.init(); 
  /*****************************  MQ Init ********************************************/ 
  //Input: setup flag, if this function are on setup will print the headers (Optional - Default value: False)
  //Output: print on serial port the information about sensor and sensor readings
  //Remarks: Configure the pin of arduino as input.
  /************************************************************************************/ 
  MQ309.serialDebug(true);
}

void loop() {
  MQ309.update(); // Update data, the arduino will be read the voltage on the analog pin
  MQ309.readSensor(); // Sensor will read PPM concentration using the model and a and b values setted before or in the setup
  MQ309.serialDebug(); // Will print the table on the serial port
  delay(500); //Sampling frequency
}
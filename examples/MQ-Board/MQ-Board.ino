/*
  MQUnifiedsensor Library - calibrating an MQ2 to MQ9

  Demonstrates the use a MQ2 sensor.
  Library originally added 01 may 2019
  by Miguel A Califa, Yersson Carrillo, Ghiordy Contreras, Mario Rodriguez
 
  Added example
  modified 27 May 2019
  by Miguel Califa 

 This example code is in the public domain.

*/

//Include the library
#include <MQUnifiedsensor.h>

//Definitions
#define placa "Arduino UNO"
#define Voltage_Resolution 5
#define type "MQ-Board"
#define ADC_Bit_Resolution 10 // For arduino UNO/MEGA/NANO
#define pin2 A2 //Analog input 2 of your arduino
#define pin3 A3 //Analog input 3 of your arduino
#define pin4 A4 //Analog input 4 of your arduino
#define pin5 A5 //Analog input 5 of your arduino
#define pin6 A6 //Analog input 6 of your arduino
#define pin7 A7 //Analog input 7 of your arduino
#define pin8 A8 //Analog input 8 of your arduino
#define pin9 A9 //Analog input 9 of your arduino
//#define calibration_button 13 //Pin to calibrate your sensor

//Declare Sensor
MQUnifiedsensor MQ2(placa, Voltage_Resolution, ADC_Bit_Resolution, pin2, type);
MQUnifiedsensor MQ3(placa, Voltage_Resolution, ADC_Bit_Resolution, pin3, type);
MQUnifiedsensor MQ4(placa, Voltage_Resolution, ADC_Bit_Resolution, pin4, type);
MQUnifiedsensor MQ5(placa, Voltage_Resolution, ADC_Bit_Resolution, pin5, type);
MQUnifiedsensor MQ6(placa, Voltage_Resolution, ADC_Bit_Resolution, pin6, type);
MQUnifiedsensor MQ7(placa, Voltage_Resolution, ADC_Bit_Resolution, pin7, type);
MQUnifiedsensor MQ8(placa, Voltage_Resolution, ADC_Bit_Resolution, pin8, type);
MQUnifiedsensor MQ9(placa, Voltage_Resolution, ADC_Bit_Resolution, pin9, type);

//Variables
float  LPG, Alcohol, CH4, H2, CH42, CO, H22, LPG2;

void setup() {
  //Init serial port
  Serial.begin(9600);
  //init the sensor
  MQ2.init();
  MQ2.setRegressionMethod("Exponential"); //_PPM =  a*ratio^b
  MQ2.setA(574.25); MQ2.setB(-2.222); // Configurate the ecuation values to get LPG concentration
  MQ2.setR0(9.659574468);

  MQ3.init(); 
  MQ3.setRegressionMethod("Exponential"); //_PPM =  a*ratio^b
  MQ3.setA(4.8387); MQ3.setB(-2.68); // Configurate the ecuation values to get Benzene concentration
  MQ3.setR0(3.86018237);

  MQ4.init(); 
  MQ4.setRegressionMethod("Exponential"); //_PPM =  a*ratio^b
  MQ4.setA(1012.7); MQ4.setB(-2.786); // Configurate the ecuation values to get CH4 concentration
  MQ4.setR0(3.86018237);

  MQ5.init(); 
  MQ5.setRegressionMethod("Exponential"); //_PPM =  a*ratio^b
  MQ5.setA(1163.8); MQ5.setB(-3.874); // Configurate the ecuation values to get H2 concentration
  MQ5.setR0(71.100304);
  
  MQ6.init(); 
  MQ6.setRegressionMethod("Exponential"); //_PPM =  a*ratio^b
  MQ6.setA(2127.2); MQ6.setB(-2.526); // Configurate the ecuation values to get CH4 concentration
  MQ6.setR0(13.4285714);
  
  MQ7.init(); 
  MQ7.setRegressionMethod("Exponential"); //_PPM =  a*ratio^b
  MQ7.setA(99.042); MQ7.setB(-1.518); // Configurate the ecuation values to get CO concentration
  MQ7.setR0(4);
  
  MQ8.init(); 
  MQ8.setRegressionMethod("Exponential"); //_PPM =  a*ratio^b
  MQ8.setA(976.97); MQ8.setB(-0.688); // Configurate the ecuation values to get H2 concentration
  MQ8.setR0(1);
  
  MQ9.init(); 
  MQ9.setRegressionMethod("Exponential"); //_PPM =  a*ratio^b
  MQ9.setA(1000.5); MQ9.setB(-2.186); // Configurate the ecuation values to get LPG concentration
  MQ9.setR0(9.42857143);
  //Print in serial monitor
  Serial.print("MQ2 to MQ9 - lecture");
  //pinMode(calibration_button, INPUT);
}

void loop() {
  //Update the voltage lectures
  MQ2.update();
  MQ3.update();
  MQ4.update();
  MQ5.update();
  MQ6.update();
  MQ7.update();
  MQ8.update();
  MQ9.update();
  /*
  //Rutina de calibracion - Uncomment if you need (setup too and header)
  if(calibration_button)
  {
    float R0 = MQ2.calibrate();
    MQ2.setR0(R0):
    R0 = MQ3.calibrate();
    MQ3.setR0(R0):
    R0 = MQ4.calibrate();
    MQ4.setR0(R0):
    R0 = MQ5.calibrate();
    MQ5.setR0(R0):
    R0 = MQ6.calibrate();
    MQ6.setR0(R0):
    R0 = MQ7.calibrate();
    MQ7.setR0(R0):
    R0 = MQ8.calibrate();
    MQ8.setR0(R0):
    R0 = MQ9.calibrate();
    MQ9.setR0(R0):
  }
  */
  //Read the sensor and print in serial port
  LPG =  MQ2.readSensor();
  Alcohol =  MQ3.readSensor();
  CH4 =  MQ4.readSensor();
  H2 =  MQ5.readSensor();
  CH42 =  MQ6.readSensor();
  CO =  MQ7.readSensor();
  H22 =  MQ8.readSensor();
  LPG2 =  MQ9.readSensor();

  Serial.println("***************************");
  Serial.println("Lectures for MQ-Board");
  Serial.print("LPG: ");Serial.print(LPG,2);Serial.println(" PPM");
  Serial.print("Alcohol: ");Serial.print(Alcohol,2);Serial.println(" PPM");
  Serial.print("CH4: ");Serial.print(CH4,2);Serial.println(" PPM");
  Serial.print("H2: ");Serial.print(H2,2);Serial.println(" PPM");
  Serial.print("CH4_2: ");Serial.print(CH42,2);Serial.println(" PPM");
  Serial.print("CO: ");Serial.print(CO,2);Serial.println(" PPM");
  Serial.print("H2_2: ");Serial.print(H22,2);Serial.println(" PPM");
  Serial.print("LPG_2: ");Serial.print(LPG2,2);Serial.println(" PPM");
  Serial.println("***************************");  
}

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
MQUnifiedsensor MQ2(pin2, 2);
MQUnifiedsensor MQ3(pin3, 3);
MQUnifiedsensor MQ4(pin4, 4);
MQUnifiedsensor MQ5(pin5, 5);
MQUnifiedsensor MQ6(pin6, 6);
MQUnifiedsensor MQ7(pin7, 7);
MQUnifiedsensor MQ8(pin8, 8);
MQUnifiedsensor MQ9(pin9, 9);

//Variables
float  LPG, Alcohol, CH4, H2, CH42, CO, H22, LPG2;

void setup() {
  //Init serial port
  Serial.begin(9600);
  //init the sensor
  MQ2.inicializar(); 
  MQ3.inicializar(); 
  MQ4.inicializar(); 
  MQ5.inicializar(); 
  MQ6.inicializar(); 
  MQ7.inicializar(); 
  MQ8.inicializar(); 
  MQ9.inicializar(); 
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
  Serial.print("LPG: ");Serial.print(LPG,2);Serial.println(" ppm");
  Serial.print("Alcohol: ");Serial.print(Alcohol,2);Serial.println(" ppm");
  Serial.print("CH4: ");Serial.print(CH4,2);Serial.println(" ppm");
  Serial.print("H2: ");Serial.print(H2,2);Serial.println(" ppm");
  Serial.print("CH4_2: ");Serial.print(CH42,2);Serial.println(" ppm");
  Serial.print("CO: ");Serial.print(CO,2);Serial.println(" ppm");
  Serial.print("H2_2: ");Serial.print(H22,2);Serial.println(" ppm");
  Serial.print("LPG_2: ");Serial.print(LPG2,2);Serial.println(" ppm");
  Serial.println("***************************");  
}

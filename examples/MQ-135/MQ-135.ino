/*
  MQUnifiedsensor Library - reading an MQ135

  Demonstrates the use a MQ135 sensor.
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
#define type 135 //MQ135
//#define calibration_button 13 //Pin to calibrate your sensor

//Declare Sensor
MQUnifiedsensor MQ135(pin, type);

//Variables
float CO, Alcohol, CO2, Tolueno, NH4, Acetona;

void setup() {
  Serial.begin(9600); //Init serial port
   //init the sensor
  /*****************************  MQInicializar****************************************
  Input:  pin, type 
  Output:  
  Remarks: This function create the sensor object.
  ************************************************************************************/ 
  MQ135.inicializar(); 
  //pinMode(calibration_button, INPUT);
}

void loop() {
  MQ135.update(); // Update data, the arduino will be read the voltaje in the analog pin
  /*
    //Si el valor de RL es diferente a 10K por favor asigna tu valor de RL con el siguiente metodo:
    MQ135.setRL(10);
  */
  /*
  //Rutina de calibracion - Uncomment if you need (setup too and header)
  if(calibration_button)
  {
    float R0 = MQ135.calibrate();
    MQ135.setR0(R0):
  }
  */
   /*****************************  MQReadSensor  ****************************************
  Input:   Gas - Serial print flag
  Output:  Value in PPM
  Remarks: This function use readPPM to read the value in PPM the gas in the air.
  ************************************************************************************/ 
  //Read the sensor and print in serial port
  //Lecture will be saved in lecture variable
  //float lecture =  MQ135.readSensor("", true); // Return NH4 concentration
  // Options, uncomment where you need
  CO =  MQ135.readSensor("CO"); // Return CO concentration
  Alcohol =  MQ135.readSensor("Alcohol"); // Return Alcohol concentration
  CO2 =  MQ135.readSensor("CO2"); // Return CO2 concentration
  Tolueno =  MQ135.readSensor("Tolueno"); // Return Tolueno concentration
  NH4 =  MQ135.readSensor("NH4"); // Return NH4 concentration
  Acetona =  MQ135.readSensor("Acetona"); // Return Acetona concentration

  Serial.println("***************************");
  Serial.println("Lectures for MQ-135");
  Serial.print("Volt: ");Serial.print(MQ135.getVoltage(false));Serial.println(" V"); 
  Serial.print("R0: ");Serial.print(MQ135.getR0());Serial.println(" Ohm"); 
  Serial.print("CO: ");Serial.print(CO,2);Serial.println(" ppm");
  Serial.print("Alcohol: ");Serial.print(Alcohol,2);Serial.println(" ppm");
  Serial.print("CO2: ");Serial.print(CO2,2);Serial.println(" ppm");
  Serial.print("Tolueno: ");Serial.print(Tolueno,2);Serial.println(" ppm");
  Serial.print("NH4: ");Serial.print(NH4,2);Serial.println(" ppm");
  Serial.print("Acetona: ");Serial.print(Acetona,2);Serial.println(" ppm");
  Serial.println("***************************");  
}

/*
  MQUnifiedsensor Library - implementing an alcoholimeter

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
#define pin A3 //Analog input 0 of your arduino
#define type 3 //MQ3

//Declare Sensor

MQUnifiedsensor MQ3(pin, type);

void setup() {
  Serial.begin(9600);
  //init the sensor
  /*****************************  MQInicializar****************************************
  Input:  pin, type 
  Output:  
  Remarks: This function create the sensor object.
  ************************************************************************************/ 
  MQ3.inicializar(); 

  float RoCleanAir = MQ3.calibrate();

  Serial.print("R0 preconfigurado: ");
  Serial.println(MQ3.getR0());
  Serial.print("R0 clean air: ");
  Serial.println(RoCleanAir);
  //MQ3.setR0(RoCleanAir);
}

void loop() {
  /*****************************  MQReadSensor  ****************************************
  Input:   Gas - Serial print flag
  Output:  Value in PPM
  Remarks: This function use readPPM to read the value in PPM the gas in the air.
  ************************************************************************************/ 
  //Read the sensor and print in serial port
  //Lecture will be saved in lecture variable
  int lecture =  MQ3.readSensor("", true); // Return Alcohol concentration
  /*
  int gL = lecture/1000;
  Serial.print("Alcohol ppm measured: ");
  Serial.print(lecture);
  Serial.println("ppm");

  Serial.print("Alcohol gL measured: ");
  Serial.print(gL);
  Serial.println("g/L");
  */
}

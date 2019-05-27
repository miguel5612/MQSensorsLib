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

//Declare Sensor

MQUnifiedsensor MQ2(pin2, 2);
MQUnifiedsensor MQ3(pin3, 2);
MQUnifiedsensor MQ4(pin4, 2);
MQUnifiedsensor MQ5(pin5, 2);
MQUnifiedsensor MQ6(pin6, 2);
MQUnifiedsensor MQ7(pin7, 2);
MQUnifiedsensor MQ8(pin8, 2);
MQUnifiedsensor MQ9(pin9, 2);

unsigned long contador = 0;

void setup() {
  //Init serial port
  Serial.begin(115200);
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
  Serial.print("MQ2 to MQ9 - Calibracion");
  Serial.print("Note - Make sure you are in a clean room and the sensor has pre-heated almost 4 hours");
  Serial.print("Autonumeric, lecture");
}

void loop() {
  //Read the sensor and print in serial port
  int lecture2 =  MQ2.calibrate();
  int lecture3 =  MQ3.calibrate();
  int lecture4 =  MQ4.calibrate();
  int lecture5 =  MQ5.calibrate();
  int lecture6 =  MQ6.calibrate();
  int lecture7 =  MQ7.calibrate();
  int lecture8 =  MQ8.calibrate();
  int lecture9 =  MQ9.calibrate();
  //Print in serial monitor
  Serial.print(String(contador) + ",");
  Serial.println(String(lecture2) + ",";
  Serial.println(String(lecture3) + ",";
  Serial.println(String(lecture4) + ",";
  Serial.println(String(lecture5) + ",";
  Serial.println(String(lecture6) + ",";
  Serial.println(String(lecture7) + ",";
  Serial.println(String(lecture8) + ",";
  Serial.println(String(lecture9) + ",";
  //Increment counter
  contador++;
  //Wait to measure next sample
  delay(400);
}

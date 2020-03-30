/*
  MQUnifiedsensor Library - reading an MQ3

  Demonstrates the use a MQ3 sensor.
  Library originally added 01 may 2019
  by Miguel A Califa, Yersson Carrillo, Ghiordy Contreras, Mario Rodriguez
 
  Added example
  modified 23 May 2019
  by Miguel Califa 

  Updated library usage
  modified 29 March 2020
  by Miguel Califa 
  
  Wiring:
  https://github.com/miguel5612/MQSensorsLib_Docs/blob/master/static/img/MQ_Arduino.PNG
  Please take care, arduino A0 pin represent the analog input configured on #define pin

 This example code is in the public domain.

*/

//Include the library
#include <MQUnifiedsensor.h>
/************************Hardware Related Macros************************************/
#define         Board                   ("Arduino UNO")
#define         Pin                     (A3)  //Analog input 3 of your arduino
/***********************Software Related Macros************************************/
#define         Type                    ("MQ-3") //MQ3
#define         Voltage_Resolution      (5)
#define         ADC_Bit_Resolution      (10) // For arduino UNO/MEGA/NANO

/*****************************Globals***********************************************/
double          alcoholPPM          =   (0);
/**************************Object_Sensor********************************************/
MQUnifiedsensor MQ3(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin, Type);

void setup() {
  //Init the serial port communication - to debug the library
  Serial.begin(9600); //Init serial port

  //Set math model to calculate the PPM concentration and the value of constants
  MQ3.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ3.setA(0.3934); MQ3.setB(-1.504); // Configurate the ecuation values to get Alcohol concentration
  /*
    Exponential regression:
  Gas    | a      | b     
  LPG    | 44771  | -3.245
  CH4    | 2*10^31| 19.01
  CO     | 521853 | -3.821
  Alcohol| 0.3934 | -1.504
  Benzene| 4.8387 | -2.68
  Hexane | 7585.3 | -2.849
  */

  // Calibration setup
  MQ3.setR0(3.86018237);

  /* 
    //If the RL value is different from 10K please assign your RL value with the following method:
    MQ3.setRL(10);
  */

  /*****************************  MQ Init ********************************************/ 
  //Remarks: Configure the pin of arduino as input.
  /************************************************************************************/ 
  MQ3.init(); 
}

void loop() {
  MQ3.update(); // Update data, the arduino will be read the voltage on the analog pin
  alcoholPPM = MQ3.readSensor(); // Sensor will read PPM concentration using the model and a and b values setted before or in the setup
  Serial.print("Alcohol now (PPM): ");
  Serial.println(alcoholPPM);
  delay(500); //Sampling frequency
}

/*
  MQUnifiedsensor Library - reading an MQ303

  Demonstrates the use a MQ303 sensor.
  Library originally added 01 may 2019
  by Miguel A Califa, Yersson Carrillo, Ghiordy Contreras, Mario Rodriguez
 
  Added example
  modified 23 May 2019
  by Miguel Califa 

  Updated library usage
  modified 26 March 2020
  by Miguel Califa 

  Wiring:
  https://github.com/miguel5612/MQSensorsLib_Docs/blob/master/static/img/MQ_Arduino.PNG
  Please make sure arduino A0 pin represents the analog input configured on #define pin

 This example code is in the public domain.

*/

//Include the library
#include <MQUnifiedsensor.h>

//Definitions
#define placa "Arduino UNO"
#define Voltage_Resolution 5
#define pin A0 //Analog input 0 of your arduino
#define type "MQ-303" //MQ303
#define ADC_Bit_Resolution 10 // For arduino UNO/MEGA/NANO
#define RatioMQ303CleanAir 1  //RS / R0 = 1 ppm    
//#define calibration_button 13 //Pin to calibrate your sensor

//Declare Sensor
MQUnifiedsensor MQ303(placa, Voltage_Resolution, ADC_Bit_Resolution, pin, type);

void setup() {
  //Init the serial port communication - to debug the library
  Serial.begin(9600); //Init serial port

  //Set math model to calculate the PPM concentration and the value of constants
  MQ303.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ303.setA(6.2144); MQ303.setB(-2.894); // Configure the equation to to calculate Isobutano concentration

  /*
    Exponential regression:
  GAS        | a      | b
  Iso_butano | 6.2144 | -2.894
  Hydrogen   | 4.1487 | -2.716
  Ethanol    | 3.4916 | -2.432
  */

  /*****************************  MQ Init ********************************************/ 
  //Remarks: Configure the pin of arduino as input.
  /************************************************************************************/ 
  MQ303.init(); 
  /* 
    //If the RL value is different from 10K please assign your RL value with the following method:
    MQ303.setRL(10);
  */
  /*****************************  MQ CAlibration ********************************************/ 
  // Explanation: 
   // In this routine the sensor will measure the resistance of the sensor supposedly before being pre-heated
  // and on clean air (Calibration conditions), setting up R0 value.
  // We recomend executing this routine only on setup in laboratory conditions.
  // This routine does not need to be executed on each restart, you can load your R0 value from eeprom.
  // Acknowledgements: https://jayconsystems.com/blog/understanding-a-gas-sensor
  Serial.print("Calibrating please wait.");
  float calcR0 = 0;
  for(int i = 1; i<=10; i ++)
  {
    MQ303.update(); // Update data, the arduino will read the voltage from the analog pin
    calcR0 += MQ303.calibrate(RatioMQ303CleanAir);
    Serial.print(".");
  }
  MQ303.setR0(calcR0/10);
  Serial.println("  done!.");
  
  if(isinf(calcR0)) {Serial.println("Warning: Conection issue, R0 is infinite (Open circuit detected) please check your wiring and supply"); while(1);}
  if(calcR0 == 0){Serial.println("Warning: Conection issue found, R0 is zero (Analog pin shorts to ground) please check your wiring and supply"); while(1);}
  /*****************************  MQ CAlibration ********************************************/ 
  MQ303.serialDebug(true);
}

void loop() {
  MQ303.update(); // Update data, the arduino will read the voltage from the analog pin
  MQ303.readSensor(true); // Sensor will read PPM concentration using the model, a and b values set previously or from the setup
  MQ303.serialDebug(); // Will print the table on the serial port
  delay(500); //Sampling frequency
}
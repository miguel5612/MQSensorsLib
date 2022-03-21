/*
  MQUnifiedsensor Library - reading an MQ136

  Demonstrates the use a MQ136 sensor.
  Library originally added 01 may 2019
  by Miguel A Califa, Yersson Carrillo, Ghiordy Contreras, Mario Rodriguez
 
  Added example
  modified 21 March 2022
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
#define type "MQ-136" //MQ136
#define ADC_Bit_Resolution 10 // For arduino UNO/MEGA/NANO
#define RatioMQ136CleanAir 3.6//RS / R0 = 3.6 ppm  
//#define calibration_button 13 //Pin to calibrate your sensor

//Declare Sensor
MQUnifiedsensor MQ136(placa, Voltage_Resolution, ADC_Bit_Resolution, pin, type);

void setup() {
  //Init the serial port communication - to debug the library
  Serial.begin(9600); //Init serial port

  //Set math model to calculate the PPM concentration and the value of constants
  MQ136.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ136.setA(36.737); MQ136.setB(-3.536); // Configure the equation to to calculate H2S Concentration

  /*
    Exponential regression:
  GAS      | a      | b
  H2S      | 36.737 | -3.536
  NH4      | 98.551 | -2.475
  CO       | 503.34 | -3.774
  */
  
  /*****************************  MQ Init ********************************************/ 
  //Remarks: Configure the pin of arduino as input.
  /************************************************************************************/ 
  MQ136.init(); 
  /* 
    //If the RL value is different from 10K please assign your RL value with the following method:
    MQ136.setRL(10);
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
    MQ136.update(); // Update data, the arduino will read the voltage from the analog pin
    calcR0 += MQ136.calibrate(RatioMQ136CleanAir);
    Serial.print(".");
  }
  MQ136.setR0(calcR0/10);
  Serial.println("  done!.");
  
  if(isinf(calcR0)) {Serial.println("Warning: Conection issue, R0 is infinite (Open circuit detected) please check your wiring and supply"); while(1);}
  if(calcR0 == 0){Serial.println("Warning: Conection issue found, R0 is zero (Analog pin shorts to ground) please check your wiring and supply"); while(1);}
  /*****************************  MQ CAlibration ********************************************/ 
  MQ136.serialDebug(true);
}

void loop() {
  MQ136.update(); // Update data, the arduino will read the voltage from the analog pin
  MQ136.readSensor(); // Sensor will read PPM concentration using the model, a and b values set previously or from the setup
  MQ136.serialDebug(); // Will print the table on the serial port
  delay(500); //Sampling frequency
}
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
#define type "MQ-309" //MQ309
#define ADC_Bit_Resolution 10 // For arduino UNO/MEGA/NANO
#define RatioMQ309CleanAir 11 //RS / R0 = 11 ppm 
#define PWMPin 5 // Pin connected to mosfet

//Declare Sensor
MQUnifiedsensor MQ309(placa, Voltage_Resolution, ADC_Bit_Resolution, pin, type);
unsigned long oldTime = 0;

void setup() {
  //Init the serial port communication - to debug the library
  Serial.begin(9600); //Init serial port
  pinMode(PWMPin, OUTPUT);

  //Set math model to calculate the PPM concentration and the value of constants
  MQ309.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ309.setA(1000000); MQ309.setB(-4.01); // Configure the equation to calculate CO concentration value

  /*
    Exponential regression:
  GAS     | a       | b
  H2      | 1532.9  | -1.951
  CH4     | 980.24  | -1.68
  CO      | 1000000 | -4.01
  ALCOHOL | 473622  | -3.647
  */

  /*****************************  MQ Init ********************************************/ 
  //Remarks: Configure the pin of arduino as input.
  /************************************************************************************/ 
  MQ309.init(); 
  /* 
    //If the RL value is different from 10K please assign your RL value with the following method:
    MQ309.setRL(10);
  */
  /*****************************  MQ CAlibration ********************************************/ 
  // Explanation: 
   // In this routine the sensor will measure the resistance of the sensor supposedly before being pre-heated
  // and on clean air (Calibration conditions), setting up R0 value.
  // We recommend executing this routine only on setup in laboratory conditions.
  // This routine does not need to be executed on each restart, you can load your R0 value from eeprom.
  // Acknowledgements: https://jayconsystems.com/blog/understanding-a-gas-sensor
  Serial.print("Calibrating please wait.");
  float calcR0 = 0;
  for(int i = 1; i<=10; i ++)
  {
    MQ309.update(); // Update data, the arduino will read the voltage from the analog pin
    calcR0 += MQ309.calibrate(RatioMQ309CleanAir);
    Serial.print(".");
  }
  MQ309.setR0(calcR0/10);
  Serial.println("  done!.");
  
  if(isinf(calcR0)) {Serial.println("Warning: Connection issue, R0 is infinite (Open circuit detected) please check your wiring and supply"); while(1);}
  if(calcR0 == 0){Serial.println("Warning: Connection issue found, R0 is zero (Analog pin shorts to ground) please check your wiring and supply"); while(1);}
  /*****************************  MQ CAlibration ********************************************/ 
  MQ309.serialDebug(true);
}

void loop() {
  // 60s cycle
  oldTime = millis();
  while(millis() - oldTime <= (30*1000))
  {
    // VH 0.9 Volts
    analogWrite(5, 2); // 255 is 100%, 2.295 is aprox 0.9% of Duty cycle for 60s
    MQ309.update(); // Update data, the arduino will read the voltage from the analog pin
    float correctionFactor = 0; // Optional environmental correction
    MQ309.readSensor(false, correctionFactor); // Sensor will read PPM concentration using the model, a and b values set previously or from the setup
    MQ309.serialDebug(); // Will print the table on the serial port
    delay(500); //Sampling frequency
  }

  // 90s cycle
  oldTime = millis();
  while(millis() - oldTime <= (120*1000))
  {
    // VL 0.2 Volts
    analogWrite(5, 1); // 255 is 100%, 0.51 is aprox 0.2% of Duty cycle for 120s
    MQ309.update(); // Update data, the arduino will read the voltage from the analog pin
    float correctionFactor2 = 0; // Optional environmental correction
    MQ309.readSensor(false, correctionFactor2); // Sensor will read PPM concentration using the model, a and b values set previously or from the setup
    MQ309.serialDebug(); // Will print the table on the serial port
    delay(500); //Sampling frequency
  } 
  // Total: 30 + 120s =  2.5 minutes.
}
/*
  MQUnifiedsensor Library - reading an MQ7

  Demonstrates the use a MQ7 sensor.
  Library originally added 01 may 2019
  by Miguel A Califa, Yersson Carrillo, Ghiordy Contreras, Mario Rodriguez
 
  Added example
  modified 23 May 2019
  by Miguel Califa 

  Updated library usage
  modified 26 March 2020
  by Miguel Califa 

  Updated example of MQ-7 AND MQ-309A
  modified 20 April 2020
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
#define type "MQ-7" //MQ7
#define ADC_Bit_Resolution 10 // For arduino UNO/MEGA/NANO
#define RatioMQ7CleanAir 27.5 //RS / R0 = 27.5 ppm 
#define PWMPin 5 // Pin connected to mosfet

//Declare Sensor
MQUnifiedsensor MQ7(placa, Voltage_Resolution, ADC_Bit_Resolution, pin, type);
unsigned long oldTime = 0;

void setup() {
  //Init the serial port communication - to debug the library
  Serial.begin(9600); //Init serial port
  pinMode(PWMPin, OUTPUT);

  //Set math model to calculate the PPM concentration and the value of constants
  MQ7.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ7.setA(99.042); MQ7.setB(-1.518); // Configure the equation to calculate CO concentration value

  /*
    Exponential regression:
  GAS     | a      | b
  H2      | 69.014  | -1.374
  LPG     | 700000000 | -7.703
  CH4     | 60000000000000 | -10.54
  CO      | 99.042 | -1.518
  Alcohol | 40000000000000000 | -12.35
  */
  
  /*****************************  MQ Init ********************************************/ 
  //Remarks: Configure the pin of arduino as input.
  /************************************************************************************/ 
  MQ7.init(); 
  /* 
    //If the RL value is different from 10K please assign your RL value with the following method:
    MQ7.setRL(10);
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
    MQ7.update(); // Update data, the arduino will read the voltage from the analog pin
    calcR0 += MQ7.calibrate(RatioMQ7CleanAir);
    Serial.print(".");
  }
  MQ7.setR0(calcR0/10);
  Serial.println("  done!.");
  
  if(isinf(calcR0)) {Serial.println("Warning: Conection issue, R0 is infinite (Open circuit detected) please check your wiring and supply"); while(1);}
  if(calcR0 == 0){Serial.println("Warning: Conection issue found, R0 is zero (Analog pin shorts to ground) please check your wiring and supply"); while(1);}
  /*****************************  MQ CAlibration ********************************************/ 
  MQ7.serialDebug(true);
}

void loop() {
  // 60s cycle
  oldTime = millis();
  while(millis() - oldTime <= (60*1000))
  {
    // VH 5 Volts
    analogWrite(5, 255); // 255 is DC 5V output
    MQ7.update(); // Update data, the arduino will read the voltage from the analog pin
    MQ7.readSensor(); // Sensor will read PPM concentration using the model, a and b values set previously or from the setup
    MQ7.serialDebug(); // Will print the table on the serial port
    delay(500); //Sampling frequency
  }

  // 90s cycle
  oldTime = millis();
  while(millis() - oldTime <= (90*1000))
  {
    // VH 1.4 Volts
    analogWrite(5, 20); // 255 is 100%, 20.4 is aprox 8% of Duty cycle for 90s
    MQ7.update(); // Update data, the arduino will read the voltage from the analog pin
    MQ7.readSensor(); // Sensor will read PPM concentration using the model, a and b values set previously or from the setup
    MQ7.serialDebug(); // Will print the table on the serial port
    delay(500); //Sampling frequency
  } 
  // Total: 60 + 90s =  2.5 minutes.
}
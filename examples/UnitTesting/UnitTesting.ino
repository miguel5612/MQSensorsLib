/*
  MQUnifiedsensor Library - testing library

  Library originally added 01 may 2019
  by Miguel A Califa, Yersson Carrillo, Ghiordy Contreras, Mario Rodriguez
 
  Added example
  modified 21 March 2022
  by Miguel Califa 

 This example code is in the public domain.

*/

//Include the library
#include <MQUnifiedsensor.h>
#line 2 "basic.ino"
#include <ArduinoUnit.h>

/************************Hardware Related Macros************************************/
#define         Board                   ("Arduino Mega")
#define         Pin2                     (A2)  //Analog input 2 of your arduino
#define         Pin3                     (A3)  //Analog input 3 of your arduino
#define         Pin4                     (A4)  //Analog input 4 of your arduino
#define         Pin5                     (A5)  //Analog input 5 of your arduino
#define         Pin6                     (A6)  //Analog input 6 of your arduino
#define         Pin7                     (A7)  //Analog input 7 of your arduino
#define         Pin8                     (A8)  //Analog input 8 of your arduino
#define         Pin9                     (A9)  //Analog input 9 of your arduino
#define         Pin10                    (A10) //Analog input 9 of your arduino
#define         Pin11                    (A11) //Analog input 9 of your arduino
#define         Pin12                    (A12) //Analog input 9 of your arduino
#define         Pin13                    (A13) //Analog input 9 of your arduino
#define         Pin14                    (A14) //Analog input 9 of your arduino
#define         PWMPin                   (5)   // Pin connected to mosfet
/***********************Software Related Macros************************************/
#define         RatioMQ2CleanAir          (9.83) //RS / R0 = 9.83 ppm 
#define         RatioMQ3CleanAir          (60) //RS / R0 = 60 ppm 
#define         RatioMQ4CleanAir          (4.4) //RS / R0 = 4.4 ppm 
#define         RatioMQ5CleanAir          (6.5) //RS / R0 = 6.5 ppm 
#define         RatioMQ6CleanAir          (10) //RS / R0 = 10 ppm 
#define         RatioMQ7CleanAir          (27.5) //RS / R0 = 27.5 ppm  
#define         RatioMQ8CleanAir          (70) //RS / R0 = 70 ppm   
#define         RatioMQ9CleanAir          (9.6) //RS / R0 = 9.6 ppm 
#define         RatioMQ136CleanAir        (3.6) //RS / R0 = 9.6 ppm 
#define         ADC_Bit_Resolution        (10) // 10 bit ADC 
#define         Voltage_Resolution        (5) // Volt resolution to calc the voltage
#define         Type                      ("Arduino Mega 2560") //Board used
/*****************************Globals***********************************************/
//Declare Sensor
MQUnifiedsensor MQ2(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin2, Type);
MQUnifiedsensor MQ3(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin3, Type);
MQUnifiedsensor MQ4(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin4, Type);
MQUnifiedsensor MQ5(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin5, Type);
MQUnifiedsensor MQ6(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin6, Type);
MQUnifiedsensor MQ7(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin7, Type);
MQUnifiedsensor MQ8(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin8, Type);
MQUnifiedsensor MQ9(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin9, Type);
MQUnifiedsensor MQ131(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin10, Type); //mq131
MQUnifiedsensor MQ135(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin11, Type); //mq135
MQUnifiedsensor MQ136(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin12, Type); //mq136
MQUnifiedsensor MQ303A(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin13, Type); //mq303
MQUnifiedsensor MQ309A(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin14, Type); //mq309


test(adcMaxValue)
{
  int adcVal=1023;
  int volt = MQ2.getVoltage(false, true, adcVal);
  int expVolt = 5;
  assertEqual(volt,expVolt);
}

test(adcMinValue)
{
  int adcVal=0;
  int volt = MQ2.getVoltage(false, true, adcVal);
  int expVolt = 0;
  assertEqual(volt,expVolt);
}

test(adcMidValue)
{
  int adcVal=410;
  int volt = MQ2.getVoltage(false, true, adcVal);
  int expVolt = 2;
  assertEqual(volt,expVolt);
}

test(MQ2_LPG)
{
  MQ2.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ2.setA(574.25); MQ2.setB(-2.222); // Configure the equation to to calculate LPG concentration
  MQ2.init(); 
  MQ2.setR0(10);
  
  int ppmExp=464;
  int PPM = MQ2.setRsR0RatioGetPPM(1.1); // Send and Rs/R0 and return PPM (Using datasheet)
  
  assertEqual(PPM,ppmExp);
}

test(MQ3_Alcohol)
{
  MQ3.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ3.setA(0.3934); MQ3.setB(-1.504); // Configure the equation to to calculate Alcohol concentration
  MQ3.init(); 
  MQ3.setR0(10);
  
  int ppmExp=4;
  int PPM = MQ3.setRsR0RatioGetPPM(0.2); // Send and Rs/R0 and return PPM (Using datasheet)
  
  assertEqual(PPM,ppmExp);
}


test(MQ4_Smoke)
{
  MQ4.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ4.setA(30000000); MQ4.setB(-8.31); // Configure the equation to to calculate Smoke concentration
  MQ4.init(); 
  MQ4.setR0(10);
  
  int ppmExp=297;
  int PPM = MQ4.setRsR0RatioGetPPM(4); // Send and Rs/R0 and return PPM (Using datasheet)
  
  assertEqual(PPM,ppmExp);
}

test(MQ5_LPG)
{
  MQ5.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ5.setA(80.897); MQ5.setB(-2.431); // Configure the equation to to calculate LPG concentration
  MQ5.init(); 
  MQ5.setR0(10);
  
  int ppmExp=192;
  int PPM = MQ5.setRsR0RatioGetPPM(0.7); // Send and Rs/R0 and return PPM (Using datasheet)
  
  assertEqual(PPM,ppmExp);
}

test(MQ6_CH4)
{
  MQ6.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ6.setA(2127.2); MQ6.setB(-2.526); // Configure the equation to to calculate CH4 concentration
  MQ6.init(); 
  MQ6.setR0(10);
  
  int ppmExp=2127;
  int PPM = MQ6.setRsR0RatioGetPPM(1); // Send and Rs/R0 and return PPM (Using datasheet)
  
  assertEqual(PPM,ppmExp);
}

test(MQ7_CH4)
{
  MQ7.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ7.setA(99.042); MQ7.setB(-1.518); // Configure the equation to to calculate CH4 concentration
  MQ7.init(); 
  MQ7.setR0(10);
  
  int ppmExp=1139;
  int PPM = MQ7.setRsR0RatioGetPPM(0.2); // Send and Rs/R0 and return PPM (Using datasheet)
  
  assertEqual(PPM,ppmExp);
}

test(MQ8_H2)
{
  MQ8.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ8.setA(976.97); MQ8.setB(-0.688); // Configure the equation to to calculate H2 concentration
  MQ8.init(); 
  MQ8.setR0(10);
  
  int ppmExp=2956;
  int PPM = MQ8.setRsR0RatioGetPPM(0.2); // Send and Rs/R0 and return PPM (Using datasheet)
  
  assertEqual(PPM,ppmExp);
}


test(MQ9_CO)
{
  MQ9.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ9.setA(599.65); MQ9.setB(-2.244); // Configure the equation to to calculate CO concentration
  MQ9.init(); 
  MQ9.setR0(10);
  
  int ppmExp=989;
  int PPM = MQ9.setRsR0RatioGetPPM(0.8); // Send and Rs/R0 and return PPM (Using datasheet)
  
  assertEqual(PPM,ppmExp);
}

test(MQ131_O3)
{    
  MQ131.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ131.setA(23.943); MQ131.setB(-1.11); // Configure the equation to to calculate O3 concentration
  MQ131.init(); 
  MQ131.setR0(10);  
  
  int ppmExp=11;
  int PPM = MQ131.setRsR0RatioGetPPM(2); // Send and Rs/R0 and return PPM (Using datasheet)
  
  assertEqual(PPM,ppmExp);
}


test(MQ135_CO2)
{
  MQ135.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ135.setA(110.47); MQ135.setB(-2.862); // Configure the equation to to calculate CO2 concentration
  MQ135.init(); 
  MQ135.setR0(10);
  
  int ppmExp=110;
  int PPM = MQ135.setRsR0RatioGetPPM(1); // Send and Rs/R0 and return PPM (Using datasheet)
  
  assertEqual(PPM,ppmExp);
}

test(MQ136_H2S)
{
  MQ136.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ136.setA(36.737); MQ136.setB(-3.536); // Configure the equation to to calculate H2S concentration
  MQ136.init(); 
  MQ136.setR0(10);
  
  int ppmExp=223;
  int PPM = MQ136.setRsR0RatioGetPPM(0.6); // Send and Rs/R0 and return PPM (Using datasheet)
  
  assertEqual(PPM,ppmExp);
}

test(MQ303A_Ethanol)
{
  MQ303A.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ303A.setA(3.4916); MQ303A.setB(-2.432); // Configure the equation to to calculate Ethanol concentration
  MQ303A.init(); 
  MQ303A.setR0(10);
  
  int ppmExp=944;
  int PPM = MQ303A.setRsR0RatioGetPPM(0.1); // Send and Rs/R0 and return PPM (Using datasheet)
  
  assertEqual(PPM,ppmExp);
}

test(MQ309A_CO)
{
  MQ309A.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ309A.setA(1000000); MQ309A.setB(-4.01); // Configure the equation to to calculate CO concentration
  MQ309A.init(); 
  MQ309A.setR0(10);
  
  int ppmExp=757;
  int PPM = MQ309A.setRsR0RatioGetPPM(6); // Send and Rs/R0 and return PPM (Using datasheet)
  
  assertEqual(PPM,ppmExp);
}


void setup()
{
  Serial.begin(9600);
  while(!Serial) {} // Portability for Leonardo/Micro
}

void loop()
{
  Test::run();
}

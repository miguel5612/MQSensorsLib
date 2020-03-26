/*
  MQUnifiedsensor Library - calibrating an MQ2 to MQ9

  Demonstrates the use a MQ2 sensor.
  Library originally added 01 may 2019
  by Miguel A Califa, Yersson Carrillo, Ghiordy Contreras, Mario Rodriguez
 
  Added example
  modified 27 May 2019
  by Miguel Califa 

  Added LCD
  modified 26 May 2019
  by Miguel Califa 

  Changed sample frecuency
  modified 28 May 2019
  by Ghiordy contreras, Miguel Califa 

  Added voltaje to log
  modified 29 May 2019
  by Miguel Califa 
  
 This example code is in the public domain.

*/

//Include the library
#include <MQUnifiedsensor.h>
//And lcd library
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

//Definitions
#define placa "Arduino Mega 2560"
#define Voltage_Resolution 5
#define type "MQ-Board"
#define ADC_Bit_Resolution 10 // For arduino UNO/MEGA/NANO
#define pin2 A2 //Analog input 2 of your arduino
#define pin3 A3 //Analog input 3 of your arduino
#define pin4 A4 //Analog input 4 of your arduino
#define pin5 A5 //Analog input 5 of your arduino
#define pin6 A6 //Analog input 6 of your arduino
#define pin7 A7 //Analog input 7 of your arduino
#define pin8 A8 //Analog input 8 of your arduino
#define pin9 A9 //Analog input 9 of your arduino

#define RatioMQ2CleanAir 9.83 //RS / R0 = 9.83 ppm 
#define RatioMQ3CleanAir 60   //RS / R0 = 60 ppm 
#define RatioMQ4CleanAir 4.4  //RS / R0 = 4.4 ppm 
#define RatioMQ5CleanAir 6.5  //RS / R0 = 6.5 ppm 
#define RatioMQ6CleanAir 10   //RS / R0 = 10 ppm 
#define RatioMQ7CleanAir 27.5 //RS / R0 = 27.5 ppm  
#define RatioMQ8CleanAir 70   //RS / R0 = 70 ppm   
#define RatioMQ9CleanAir 9.6  //RS / R0 = 9.6 ppm    
#define RatioMQ131CleanAir 15 //RS / R0 = 15 ppm
#define RatioMQ135CleanAir 3.6//RS / R0 = 3.6 ppm     
#define RatioMQ303CleanAir 1  //RS / R0 = 1 ppm    
#define RatioMQ309CleanAir 11 //RS / R0 = 11 ppm    


#define timeDelay 500
//Declare Sensor

MQUnifiedsensor MQ2(placa, Voltage_Resolution, ADC_Bit_Resolution, pin2, type);
MQUnifiedsensor MQ3(placa, Voltage_Resolution, ADC_Bit_Resolution, pin3, type);
MQUnifiedsensor MQ4(placa, Voltage_Resolution, ADC_Bit_Resolution, pin4, type);
MQUnifiedsensor MQ5(placa, Voltage_Resolution, ADC_Bit_Resolution, pin5, type);
MQUnifiedsensor MQ6(placa, Voltage_Resolution, ADC_Bit_Resolution, pin6, type);
MQUnifiedsensor MQ7(placa, Voltage_Resolution, ADC_Bit_Resolution, pin7, type);
MQUnifiedsensor MQ8(placa, Voltage_Resolution, ADC_Bit_Resolution, pin8, type);
MQUnifiedsensor MQ9(placa, Voltage_Resolution, ADC_Bit_Resolution, pin9, type);

unsigned long contador = 0;
unsigned long time = millis();

void setup() {
  //Init serial port
  Serial.begin(9600);
  // initialize the LCD
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  //Welcome message
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MQ2 to MQ9");
  lcd.setCursor(0,1);
  lcd.print("   Calibrating");
  //init the sensor
  
  MQ2.init();
  MQ2.setRegressionMethod("Exponential"); //_PPM =  a*ratio^b
  MQ2.setA(574.25); MQ2.setB(-2.222); // Configurate the ecuation values to get LPG concentration
  MQ2.setR0(9.659574468);

  MQ3.init(); 
  MQ3.setRegressionMethod("Exponential"); //_PPM =  a*ratio^b
  MQ3.setA(4.8387); MQ3.setB(-2.68); // Configurate the ecuation values to get Benzene concentration
  MQ3.setR0(3.86018237);

  MQ4.init(); 
  MQ4.setRegressionMethod("Exponential"); //_PPM =  a*ratio^b
  MQ4.setA(1012.7); MQ4.setB(-2.786); // Configurate the ecuation values to get CH4 concentration
  MQ4.setR0(3.86018237);

  MQ5.init(); 
  MQ5.setRegressionMethod("Exponential"); //_PPM =  a*ratio^b
  MQ5.setA(1163.8); MQ5.setB(-3.874); // Configurate the ecuation values to get H2 concentration
  MQ5.setR0(71.100304);
  
  MQ6.init(); 
  MQ6.setRegressionMethod("Exponential"); //_PPM =  a*ratio^b
  MQ6.setA(2127.2); MQ6.setB(-2.526); // Configurate the ecuation values to get CH4 concentration
  MQ6.setR0(13.4285714);
  
  MQ7.init(); 
  MQ7.setRegressionMethod("Exponential"); //_PPM =  a*ratio^b
  MQ7.setA(99.042); MQ7.setB(-1.518); // Configurate the ecuation values to get CO concentration
  MQ7.setR0(4);
  
  MQ8.init(); 
  MQ8.setRegressionMethod("Exponential"); //_PPM =  a*ratio^b
  MQ8.setA(976.97); MQ8.setB(-0.688); // Configurate the ecuation values to get H2 concentration
  MQ8.setR0(1);
  
  MQ9.init(); 
  MQ9.setRegressionMethod("Exponential"); //_PPM =  a*ratio^b
  MQ9.setA(1000.5); MQ9.setB(-2.186); // Configurate the ecuation values to get LPG concentration
  MQ9.setR0(9.42857143);

  //Print in serial monitor
  Serial.println("MQ2 to MQ9 - Calibracion");
  Serial.println("Note - Make sure you are in a clean room and the sensor has pre-heated almost 4 hours");
  Serial.println("Note - All values are in KOhms");
  Serial.println("Autonumeric, MQ2(R0), MQ3(R0), MQ4(R0), MQ5(R0), MQ6(R0), MQ7(R0), MQ8(R0), MQ9(R0), v2(VDC), v3(VDC), v4(VDC), v5(VDC), v6(VDC), v7(VDC), v8(VDC), v9(VDC)");
  //Wait one second to continue
  delay(timeDelay/10);
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
  
  //Read the sensor
  float lecture2 =  MQ2.calibrate(RatioMQ2CleanAir);
  float lecture3 =  MQ3.calibrate(RatioMQ3CleanAir);
  float lecture4 =  MQ4.calibrate(RatioMQ4CleanAir);
  float lecture5 =  MQ5.calibrate(RatioMQ5CleanAir);
  float lecture6 =  MQ6.calibrate(RatioMQ6CleanAir);
  float lecture7 =  MQ7.calibrate(RatioMQ7CleanAir);
  float lecture8 =  MQ8.calibrate(RatioMQ8CleanAir);
  float lecture9 =  MQ9.calibrate(RatioMQ9CleanAir);

    //Read voltage the sensor
  float v2 =  MQ2.getVoltage(false);
  float v3 =  MQ3.getVoltage(false);
  float v4 =  MQ4.getVoltage(false);
  float v5 =  MQ5.getVoltage(false);
  float v6 =  MQ6.getVoltage(false);
  float v7 =  MQ7.getVoltage(false);
  float v8 =  MQ8.getVoltage(false);
  float v9 =  MQ9.getVoltage(false);

  
  //Print in serial monitor
  Serial.print(contador);Serial.print(",");
  Serial.print(lecture2);Serial.print(",");
  Serial.print(lecture3);Serial.print(",");
  Serial.print(lecture4);Serial.print(",");
  Serial.print(lecture5);Serial.print(",");
  Serial.print(lecture6);Serial.print(",");
  Serial.print(lecture7);Serial.print(",");
  Serial.print(lecture8);Serial.print(",");
  Serial.print(lecture9);Serial.print(",");
  //Print voltages
  Serial.print(v2);Serial.print(",");
  Serial.print(v3);Serial.print(",");
  Serial.print(v4);Serial.print(",");
  Serial.print(v5);Serial.print(",");
  Serial.print(v6);Serial.print(",");
  Serial.print(v7);Serial.print(",");
  Serial.print(v8);Serial.print(",");
  Serial.println(v9);
  

  //Print in LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("**CALIBRATING***");
  lcd.setCursor(0,1);
  lcd.print("Time: " + String((millis() - time)/60000) + "min");
  //Increment counter
  contador++;
  //Wait to measure next sample
  delay(timeDelay/4);
}
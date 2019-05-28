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
//And lcd library
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

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
  // initialize the LCD
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  //Welcome message
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MQ2 to MQ9");
  lcd.setCursor(0,1);
  lcd.print("   Calibracion");
  //init the sensor
  
  MQ2.inicializar(); 
  MQ3.inicializar(); 
  MQ4.inicializar(); 
  MQ5.inicializar(); 
  MQ6.inicializar(); 
  MQ7.inicializar(); 
  MQ8.inicializar(); 
  //MQ9.inicializar();
  
  //Print in serial monitor
  Serial.println("MQ2 to MQ9 - Calibracion");
  Serial.println("Note - Make sure you are in a clean room and the sensor has pre-heated almost 4 hours");
  Serial.println("Autonumeric, MQ2(PPM), MQ3(PPM), MQ4(PPM), MQ5(PPM), MQ6(PPM), MQ7(PPM)");
  //Wait one second to continue
  delay(1000);
}

void loop() {
  //Read the sensor
  int lecture2 =  MQ2.calibrate();
  int lecture3 =  MQ3.calibrate();
  int lecture4 =  MQ4.calibrate();
  int lecture5 =  MQ5.calibrate();
  int lecture6 =  MQ6.calibrate();
  int lecture7 =  MQ7.calibrate();
  int lecture8 =  MQ8.calibrate();
  int lecture9 =  MQ9.calibrate();
  
  //Print in serial monitor
  char out[40];
  snprintf(out, 30, "%d,%d,%d,%d,%d,%d,%d,%d", contador, lecture2, lecture3, lecture4, lecture5, lecture6, lecture7, lecture8, lecture9);
  Serial.println(out);
  
  //Print in LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MQ2: ");
  lcd.print(lecture2);
  lcd.print(" PPM");
  lcd.setCursor(0,1);
  lcd.print("MQ3: ");
  lcd.print(lecture3);
  lcd.print(" PPM");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MQ4: ");
  lcd.print(lecture4);
  lcd.print(" PPM");
  lcd.setCursor(0,1);
  lcd.print("MQ5: ");
  lcd.print(lecture5);
  lcd.print(" PPM");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MQ6: ");
  lcd.print(lecture6);
  lcd.print(" PPM");
  lcd.setCursor(0,1);
  lcd.print("MQ7: ");
  lcd.print(lecture7);
  lcd.print(" PPM");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MQ8: ");
  lcd.print(lecture2);
  lcd.print(" PPM");
  lcd.setCursor(0,1);
  lcd.print("MQ8: ");
  lcd.print(lecture8);
  lcd.print(" PPM");
  delay(2000);

  //Increment counter
  contador++;
  //Wait to measure next sample
  delay(400);
}

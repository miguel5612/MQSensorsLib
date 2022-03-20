/*
  MQUnifiedsensor Library - calibrating an MQ2 to MQ9

  Demonstrates the use a MQ2 sensor.
  Library originally added 01 may 2019
  by Miguel A Califa, Yersson Carrillo, Ghiordy Contreras, Mario Rodriguez
 
  Added example
  modified 27 May 2019
  by Miguel Califa 

  Wiring:
  https://github.com/miguel5612/MQSensorsLib_Docs/blob/master/static/img/MQ_Arduino.PNG
  Please make sure arduino A0 pin represents the analog input configured on #define pin

 This example code is in the public domain.

*/

//Include the library
#include <MQUnifiedsensor.h>
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

unsigned long oldTime = 0;

void setup() {
  //Init serial port
  Serial.begin(9600);
  //init the sensor
  MQ2.init();
  MQ2.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ2.setA(574.25); MQ2.setB(-2.222); // Configure the equation to to calculate LPG concentration
  MQ2.setR0(9.659574468);

  MQ3.init(); 
  MQ3.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ3.setA(0.3934); MQ3.setB(-1.504); //Configure the equation to calculate Alcohol concentration value
  MQ3.setR0(3.86018237);

  MQ4.init(); 
  MQ4.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ4.setA(1012.7); MQ4.setB(-2.786); // Configure the equation to to calculate CH4 concentration
  MQ4.setR0(3.86018237);

  MQ5.init(); 
  MQ5.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ5.setA(97124); MQ5.setB(-4.918); //Configure the equation to calculate Alcohol concentration value
  MQ5.setR0(71.100304);
  
  MQ6.init(); 
  MQ6.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ6.setA(2127.2); MQ6.setB(-2.526); // Configure the equation to to calculate CH4 concentration
  MQ6.setR0(13.4285714);
  
  MQ7.init(); 
  MQ7.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ7.setA(99.042); MQ7.setB(-1.518); // Configure the equation to calculate CO concentration value
  MQ7.setR0(4);
    
  MQ8.init(); 
  MQ8.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ8.setA(976.97); MQ8.setB(-0.688); // Configure the equation to to calculate H2 concentration
  MQ8.setR0(1);
  
  MQ9.init(); 
  MQ9.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ9.setA(1000.5); MQ9.setB(-2.186); // Configure the equation to to calculate LPG concentration
  MQ9.setR0(9.42857143);

   /*****************************  MQ CAlibration ********************************************/ 
  // Explanation: 
   // In this routine the sensor will measure the resistance of the sensor supposedly before being pre-heated
  // and on clean air (Calibration conditions), setting up R0 value.
  // We recomend executing this routine only on setup in laboratory conditions.
  // This routine does not need to be executed on each restart, you can load your R0 value from eeprom.
  // Acknowledgements: https://jayconsystems.com/blog/understanding-a-gas-sensor
  Serial.print("Calibrating please wait.");
  float MQ2calcR0 = 0, 
  MQ3calcR0 = 0,
  MQ4calcR0 = 0,
  MQ5calcR0 = 0,
  MQ6calcR0 = 0,
  MQ7calcR0 = 0,
  MQ8calcR0 = 0,
  MQ9calcR0 = 0;
  for(int i = 1; i<=10; i ++)
  {
    //Update the voltage Values
    MQ2.update();
    MQ3.update();
    MQ4.update();
    MQ5.update();
    MQ6.update();
    MQ7.update();
    MQ8.update();
    MQ9.update();

    MQ2calcR0 += MQ2.calibrate(RatioMQ2CleanAir);
    MQ3calcR0 += MQ2.calibrate(RatioMQ3CleanAir);
    MQ4calcR0 += MQ2.calibrate(RatioMQ4CleanAir);
    MQ5calcR0 += MQ2.calibrate(RatioMQ5CleanAir);
    MQ6calcR0 += MQ2.calibrate(RatioMQ6CleanAir);
    MQ7calcR0 += MQ2.calibrate(RatioMQ7CleanAir);
    MQ8calcR0 += MQ2.calibrate(RatioMQ8CleanAir);
    MQ9calcR0 += MQ2.calibrate(RatioMQ9CleanAir);

    Serial.print(".");
  }
  MQ2.setR0(MQ2calcR0/20);
  MQ3.setR0(MQ3calcR0/20);
  MQ4.setR0(MQ4calcR0/20);
  MQ5.setR0(MQ5calcR0/20);
  MQ6.setR0(MQ6calcR0/20);
  MQ7.setR0(MQ7calcR0/20);
  MQ8.setR0(MQ8calcR0/20);
  MQ9.setR0(MQ9calcR0/20);
  Serial.println("  done!.");
  
  Serial.print("Valores de R0 para cada sensor (MQ2 - MQ9):");
  Serial.print(MQ2calcR0/10); Serial.print(" | ");
  Serial.print(MQ3calcR0/10); Serial.print(" | ");
  Serial.print(MQ4calcR0/10); Serial.print(" | ");
  Serial.print(MQ5calcR0/10); Serial.print(" | ");
  Serial.print(MQ6calcR0/10); Serial.print(" | ");
  Serial.print(MQ7calcR0/10); Serial.print(" | ");
  Serial.print(MQ8calcR0/10); Serial.print(" | ");
  Serial.print(MQ9calcR0/10); Serial.println(" |");

  if(isinf(MQ2calcR0) || isinf(MQ3calcR0) || isinf(MQ4calcR0) || isinf(MQ5calcR0)  || isinf(MQ6calcR0) || isinf(MQ7calcR0) || isinf(MQ8calcR0) || isinf(MQ9calcR0)) {Serial.println("Warning: Conection issue founded, R0 is infite (Open circuit detected) please check your wiring and supply"); while(1);}
  if(MQ2calcR0 == 0 || MQ3calcR0 == 0 || MQ4calcR0 == 0 || MQ5calcR0 == 0 || MQ6calcR0 == 0 || MQ7calcR0 == 0 || MQ8calcR0 == 0 || MQ9calcR0 == 0){Serial.println("Warning: Conection issue founded, R0 is zero (Analog pin with short circuit to ground) please check your wiring and supply"); while(1);}
  /*****************************  MQ CAlibration ********************************************/ 
 
  //Print in serial monitor
  Serial.println("MQ2 to MQ9 - lecture");
  Serial.println("*************************** Values from MQ-board ***************************");
  Serial.println("|    LPG   |  Alcohol |   CH4    |  Alcohol |   CH4    |    CO    |    H2    |    LPG   |");  
  Serial.println("|    MQ-2  |   MQ-3   |   MQ-4   |   MQ-5   |   MQ-6   |   MQ-7   |   MQ-8   |   MQ-9   |");  
  //pinMode(calibration_button, INPUT);
}

void loop() {
  oldTime = millis();
  while(millis() - oldTime <= (60*1000))
  { 
    // VH 5 Volts
    analogWrite(5, 255); // 255 is DC 5V output
    readAllSensors();
    delay(500);
  }
  // 90s cycle
  oldTime = millis();
  while(millis() - oldTime <= (90*1000))
  {
    // VH 1.4 Volts
    analogWrite(5, 20); // 255 is 100%, 20.4 is aprox 8% of Duty cycle for 90s
    readAllSensors();
    delay(500);
  }
}

void readAllSensors()
{
  //Update the voltage Values
  MQ2.update();
  MQ3.update();
  MQ4.update();
  MQ5.update();
  MQ6.update();
  MQ7.update();
  MQ8.update();
  MQ9.update();
  //Read the sensor and print in serial port
  float MQ2Lecture =  MQ2.readSensor();
  float MQ3Lecture =  MQ3.readSensor();
  float MQ4Lecture =  MQ4.readSensor();
  float MQ5Lecture =  MQ5.readSensor();
  float MQ6Lecture =  MQ6.readSensor();
  float MQ7Lecture =  MQ7.readSensor();
  float MQ8Lecture =  MQ8.readSensor();
  float MQ9Lecture =  MQ9.readSensor();

  Serial.print("| "); Serial.print(MQ2Lecture);
  Serial.print("   |   "); Serial.print(MQ3Lecture);
  Serial.print("   |   "); Serial.print(MQ4Lecture);
  Serial.print("   |   "); Serial.print(MQ5Lecture);
  Serial.print("   |   "); Serial.print(MQ6Lecture);
  Serial.print("   |   "); Serial.print(MQ7Lecture);
  Serial.print("   |   "); Serial.print(MQ8Lecture);
  Serial.print("   |   "); Serial.print(MQ9Lecture);
  Serial.println("|");
}
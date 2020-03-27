//Include the library
#include <MQUnifiedsensor.h>

/*
    This program was made to test the algorithm that from the ratio obtains 
    the PPM (The core of this library), regardless of the plate in which the 
    result is executed should give a small error (ideally less than 5%), is 
    our way of self-evaluation, we tell the library what is the value of the 
    ratio and ask him to calculate the PPM and compare it against the value 
    that should really give, these values were taken from the same datasheet 
    with which the library was made.
*/

//Definitions
#define placa "Arduino Mega 2560"
#define Voltage_Resolution 5
#define type "MQ-Board"
#define ADC_Bit_Resolution 10 // For arduino UNO/MEGA/NANO
// On this program pin value doesn't matter
#define pin2 A2 //Analog input 2 of your arduino
#define pin3 A3 //Analog input 3 of your arduino
#define pin4 A4 //Analog input 4 of your arduino
#define pin5 A5 //Analog input 5 of your arduino
#define pin6 A6 //Analog input 6 of your arduino
#define pin7 A7 //Analog input 7 of your arduino
#define pin8 A6 //Analog input 6 of your arduino
#define pin9 A7 //Analog input 7 of your arduino
#define pin10 A6 //Analog input 6 of your arduino
#define pin11 A7 //Analog input 7 of your arduino
#define pin12 A6 //Analog input 6 of your arduino
#define pin13 A7 //Analog input 7 of your arduino
//#define calibration_button 13 //Pin to calibrate your sensor

//Declare Sensor
MQUnifiedsensor MQ2(placa, Voltage_Resolution, ADC_Bit_Resolution, pin2, type);
MQUnifiedsensor MQ3(placa, Voltage_Resolution, ADC_Bit_Resolution, pin3, type);
MQUnifiedsensor MQ4(placa, Voltage_Resolution, ADC_Bit_Resolution, pin4, type);
MQUnifiedsensor MQ5(placa, Voltage_Resolution, ADC_Bit_Resolution, pin5, type);
MQUnifiedsensor MQ6(placa, Voltage_Resolution, ADC_Bit_Resolution, pin6, type);
MQUnifiedsensor MQ7(placa, Voltage_Resolution, ADC_Bit_Resolution, pin7, type);
MQUnifiedsensor MQ8(placa, Voltage_Resolution, ADC_Bit_Resolution, pin8, type);
MQUnifiedsensor MQ9(placa, Voltage_Resolution, ADC_Bit_Resolution, pin9, type);
MQUnifiedsensor MQ131(placa, Voltage_Resolution, ADC_Bit_Resolution, pin10, type);
MQUnifiedsensor MQ135(placa, Voltage_Resolution, ADC_Bit_Resolution, pin11, type);
MQUnifiedsensor MQ303(placa, Voltage_Resolution, ADC_Bit_Resolution, pin12, type);
MQUnifiedsensor MQ309(placa, Voltage_Resolution, ADC_Bit_Resolution, pin13, type);

double ratio[4] = {};
double expectedValue[4] = {};
double calculatedValues[4] = {};
double error[4] = {};

void setup()
{
//Init serial port
  Serial.begin(9600);
  //init the sensor
  MQ2.init();
  MQ2.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ2.setA(574.25); MQ2.setB(-2.222); // Configurate the ecuation values to get LPG concentration
  MQ2.setR0(9.659574468);

  MQ3.init(); 
  MQ3.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ3.setA(4.8387); MQ3.setB(-2.68); // Configurate the ecuation values to get Benzene concentration
  MQ3.setR0(3.86018237);

  MQ4.init(); 
  MQ4.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ4.setA(1012.7); MQ4.setB(-2.786); // Configurate the ecuation values to get CH4 concentration
  MQ4.setR0(3.86018237);

  MQ5.init(); 
  MQ5.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ5.setA(1163.8); MQ5.setB(-3.874); // Configurate the ecuation values to get H2 concentration
  MQ5.setR0(71.100304);
  
  MQ6.init(); 
  MQ6.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ6.setA(2127.2); MQ6.setB(-2.526); // Configurate the ecuation values to get CH4 concentration
  MQ6.setR0(13.4285714);
  
  MQ7.init(); 
  MQ7.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ7.setA(99.042); MQ7.setB(-1.518); // Configurate the ecuation values to get CO concentration
  MQ7.setR0(4);
  
  MQ8.init(); 
  MQ8.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ8.setA(976.97); MQ8.setB(-0.688); // Configurate the ecuation values to get H2 concentration
  MQ8.setR0(1);
  
  MQ9.init(); 
  MQ9.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ9.setA(1000.5); MQ9.setB(-2.186); // Configurate the ecuation values to get LPG concentration
  MQ9.setR0(9.42857143);

  MQ131.init();
  MQ131.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ131.setA(23.943); MQ131.setB(-1.11); // Configurate the ecuation values to get O3 concentration
  MQ131.setR0(385.40);

  MQ135.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ135.setA(102.2); MQ135.setB(-2.473); // Configurate the ecuation values to get NH4 concentration
  MQ135.setR0(76.63);
  MQ135.init(); 

  MQ303.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ303.setA(6.2144); MQ303.setB(-2.894); // Configurate the ecuation values to get Isobutano concentration
  MQ303.setR0(10);
  MQ303.init(); 

  MQ309.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ309.setA(1000000); MQ309.setB(-4.01); // Configurate the ecuation values to get CO concentration 
  MQ309.setR0(10);
  MQ309.init(); 

  //Print in serial monitor
  Serial.println("MQ2 to MQ9 - test program");
}

void loop()
{
    // Testing MQ2 LPG
    Serial.println("**********************************************************************************************************************************");
    ratio[0] = 1.8; ratio[1] = 1.05; ratio[2] = 0.8; ratio[3] = 0.5;
    expectedValue[0] = 200; expectedValue[1] = 500; expectedValue[2] = 1000; expectedValue[3] = 3000;
    calculatedValues[0] = MQ2.validateEcuation(ratio[0]);
    calculatedValues[1] = MQ2.validateEcuation(ratio[1]);
    calculatedValues[2] = MQ2.validateEcuation(ratio[2]);
    calculatedValues[3] = MQ2.validateEcuation(ratio[3]);
    error[0] = calculatePercentualError(expectedValue[0], calculatedValues[0]);
    error[1] = calculatePercentualError(expectedValue[1], calculatedValues[1]);
    error[2] = calculatePercentualError(expectedValue[2], calculatedValues[2]);
    error[3] = calculatePercentualError(expectedValue[3], calculatedValues[3]);
    Serial.print("Error(%) MQ2: "); 
    Serial.print(error[0]); Serial.print(" ");
    Serial.print(error[1]); Serial.print(" ");
    Serial.print(error[2]); Serial.print(" ");
    Serial.print(error[3]); Serial.print(" | Calculated(PPM): ");
    Serial.print(calculatedValues[0]); Serial.print(" ");
    Serial.print(calculatedValues[1]); Serial.print(" ");
    Serial.print(calculatedValues[2]); Serial.print(" ");
    Serial.print(calculatedValues[3]); Serial.print(" | Expected(PPM): ");
    Serial.print(expectedValue[0]); Serial.print(" ");
    Serial.print(expectedValue[1]); Serial.print(" ");
    Serial.print(expectedValue[2]); Serial.print(" ");
    Serial.print(expectedValue[3]); Serial.println(" | ");
    // Testing MQ3 Benzene
    ratio[0] = 4; ratio[1] = 3; ratio[2] = 1; ratio[3] = 0.8;
    expectedValue[0] = 0.1; expectedValue[1] = 0.21; expectedValue[2] = 4; expectedValue[3] = 10;
    calculatedValues[0] = MQ3.validateEcuation(ratio[0]);
    calculatedValues[1] = MQ3.validateEcuation(ratio[1]);
    calculatedValues[2] = MQ3.validateEcuation(ratio[2]);
    calculatedValues[3] = MQ3.validateEcuation(ratio[3]);
    error[0] = calculatePercentualError(expectedValue[0], calculatedValues[0]);
    error[1] = calculatePercentualError(expectedValue[1], calculatedValues[1]);
    error[2] = calculatePercentualError(expectedValue[2], calculatedValues[2]);
    error[3] = calculatePercentualError(expectedValue[3], calculatedValues[3]);
    Serial.print("Error(%) MQ3: "); 
    Serial.print(error[0]); Serial.print(" ");
    Serial.print(error[1]); Serial.print(" ");
    Serial.print(error[2]); Serial.print(" ");
    Serial.print(error[3]); Serial.print(" | Calculated(PPM): ");
    Serial.print(calculatedValues[0]); Serial.print(" ");
    Serial.print(calculatedValues[1]); Serial.print(" ");
    Serial.print(calculatedValues[2]); Serial.print(" ");
    Serial.print(calculatedValues[3]); Serial.print(" | Expected(PPM): ");
    Serial.print(expectedValue[0]); Serial.print(" ");
    Serial.print(expectedValue[1]); Serial.print(" ");
    Serial.print(expectedValue[2]); Serial.print(" ");
    Serial.print(expectedValue[3]); Serial.println(" | ");
    // Testing MQ4 CH4
    ratio[0] = 1.9; ratio[1] = 1; ratio[2] = 0.6; ratio[3] = 0.42;
    expectedValue[0] = 200; expectedValue[1] = 1000; expectedValue[2] = 5000; expectedValue[3] = 10000;
    calculatedValues[0] = MQ4.validateEcuation(ratio[0]);
    calculatedValues[1] = MQ4.validateEcuation(ratio[1]);
    calculatedValues[2] = MQ4.validateEcuation(ratio[2]);
    calculatedValues[3] = MQ4.validateEcuation(ratio[3]);
    error[0] = calculatePercentualError(expectedValue[0], calculatedValues[0]);
    error[1] = calculatePercentualError(expectedValue[1], calculatedValues[1]);
    error[2] = calculatePercentualError(expectedValue[2], calculatedValues[2]);
    error[3] = calculatePercentualError(expectedValue[3], calculatedValues[3]);
    Serial.print("Error(%) MQ4: "); 
    Serial.print(error[0]); Serial.print(" ");
    Serial.print(error[1]); Serial.print(" ");
    Serial.print(error[2]); Serial.print(" ");
    Serial.print(error[3]); Serial.print(" | Calculated(PPM): ");
    Serial.print(calculatedValues[0]); Serial.print(" ");
    Serial.print(calculatedValues[1]); Serial.print(" ");
    Serial.print(calculatedValues[2]); Serial.print(" ");
    Serial.print(calculatedValues[3]); Serial.print(" | Expected(PPM): ");
    Serial.print(expectedValue[0]); Serial.print(" ");
    Serial.print(expectedValue[1]); Serial.print(" ");
    Serial.print(expectedValue[2]); Serial.print(" ");
    Serial.print(expectedValue[3]); Serial.println(" | ");
    // Testing MQ5 H2
    ratio[0] = 1.8; ratio[1] = 1.3; ratio[2] = 0.8; ratio[3] = 0.68;
    expectedValue[0] = 200; expectedValue[1] = 500; expectedValue[2] = 3000; expectedValue[3] = 10000;
    calculatedValues[0] = MQ5.validateEcuation(ratio[0]);
    calculatedValues[1] = MQ5.validateEcuation(ratio[1]);
    calculatedValues[2] = MQ5.validateEcuation(ratio[2]);
    calculatedValues[3] = MQ5.validateEcuation(ratio[3]);
    error[0] = calculatePercentualError(expectedValue[0], calculatedValues[0]);
    error[1] = calculatePercentualError(expectedValue[1], calculatedValues[1]);
    error[2] = calculatePercentualError(expectedValue[2], calculatedValues[2]);
    error[3] = calculatePercentualError(expectedValue[3], calculatedValues[3]);
    Serial.print("Error(%) MQ5: "); 
    Serial.print(error[0]); Serial.print(" ");
    Serial.print(error[1]); Serial.print(" ");
    Serial.print(error[2]); Serial.print(" ");
    Serial.print(error[3]); Serial.print(" | Calculated(PPM): ");
    Serial.print(calculatedValues[0]); Serial.print(" ");
    Serial.print(calculatedValues[1]); Serial.print(" ");
    Serial.print(calculatedValues[2]); Serial.print(" ");
    Serial.print(calculatedValues[3]); Serial.print(" | Expected(PPM): ");
    Serial.print(expectedValue[0]); Serial.print(" ");
    Serial.print(expectedValue[1]); Serial.print(" ");
    Serial.print(expectedValue[2]); Serial.print(" ");
    Serial.print(expectedValue[3]); Serial.println(" | ");
    // Testing MQ6 CH4
    ratio[0] = 2.6; ratio[1] = 1.9; ratio[2] = 1; ratio[3] = 0.8;
    expectedValue[0] = 200; expectedValue[1] = 500; expectedValue[2] = 2000; expectedValue[3] = 5000;
    calculatedValues[0] = MQ6.validateEcuation(ratio[0]);
    calculatedValues[1] = MQ6.validateEcuation(ratio[1]);
    calculatedValues[2] = MQ6.validateEcuation(ratio[2]);
    calculatedValues[3] = MQ6.validateEcuation(ratio[3]);
    error[0] = calculatePercentualError(expectedValue[0], calculatedValues[0]);
    error[1] = calculatePercentualError(expectedValue[1], calculatedValues[1]);
    error[2] = calculatePercentualError(expectedValue[2], calculatedValues[2]);
    error[3] = calculatePercentualError(expectedValue[3], calculatedValues[3]);
    Serial.print("Error(%) MQ6: "); 
    Serial.print(error[0]); Serial.print(" ");
    Serial.print(error[1]); Serial.print(" ");
    Serial.print(error[2]); Serial.print(" ");
    Serial.print(error[3]); Serial.print(" | Calculated(PPM): ");
    Serial.print(calculatedValues[0]); Serial.print(" ");
    Serial.print(calculatedValues[1]); Serial.print(" ");
    Serial.print(calculatedValues[2]); Serial.print(" ");
    Serial.print(calculatedValues[3]); Serial.print(" | Expected(PPM): ");
    Serial.print(expectedValue[0]); Serial.print(" ");
    Serial.print(expectedValue[1]); Serial.print(" ");
    Serial.print(expectedValue[2]); Serial.print(" ");
    Serial.print(expectedValue[3]); Serial.println(" | ");
    // Testing MQ7 CO
    ratio[0] = 1.8; ratio[1] = 1; ratio[2] = 0.4; ratio[3] = 0.25;
    expectedValue[0] = 50; expectedValue[1] = 100; expectedValue[2] = 400; expectedValue[3] = 1000;
    calculatedValues[0] = MQ7.validateEcuation(ratio[0]);
    calculatedValues[1] = MQ7.validateEcuation(ratio[1]);
    calculatedValues[2] = MQ7.validateEcuation(ratio[2]);
    calculatedValues[3] = MQ7.validateEcuation(ratio[3]);
    error[0] = calculatePercentualError(expectedValue[0], calculatedValues[0]);
    error[1] = calculatePercentualError(expectedValue[1], calculatedValues[1]);
    error[2] = calculatePercentualError(expectedValue[2], calculatedValues[2]);
    error[3] = calculatePercentualError(expectedValue[3], calculatedValues[3]);
    Serial.print("Error(%) MQ7: "); 
    Serial.print(error[0]); Serial.print(" ");
    Serial.print(error[1]); Serial.print(" ");
    Serial.print(error[2]); Serial.print(" ");
    Serial.print(error[3]); Serial.print(" | Calculated(PPM): ");
    Serial.print(calculatedValues[0]); Serial.print(" ");
    Serial.print(calculatedValues[1]); Serial.print(" ");
    Serial.print(calculatedValues[2]); Serial.print(" ");
    Serial.print(calculatedValues[3]); Serial.print(" | Expected(PPM): ");
    Serial.print(expectedValue[0]); Serial.print(" ");
    Serial.print(expectedValue[1]); Serial.print(" ");
    Serial.print(expectedValue[2]); Serial.print(" ");
    Serial.print(expectedValue[3]); Serial.println(" | ");    
    // Testing MQ8 H2
    ratio[0] = 2.6; ratio[1] = 1; ratio[2] = 0.21; ratio[3] = 0.03;
    expectedValue[0] = 500; expectedValue[1] = 1000; expectedValue[2] = 3000; expectedValue[3] = 10000;
    calculatedValues[0] = MQ8.validateEcuation(ratio[0]);
    calculatedValues[1] = MQ8.validateEcuation(ratio[1]);
    calculatedValues[2] = MQ8.validateEcuation(ratio[2]);
    calculatedValues[3] = MQ8.validateEcuation(ratio[3]);
    error[0] = calculatePercentualError(expectedValue[0], calculatedValues[0]);
    error[1] = calculatePercentualError(expectedValue[1], calculatedValues[1]);
    error[2] = calculatePercentualError(expectedValue[2], calculatedValues[2]);
    error[3] = calculatePercentualError(expectedValue[3], calculatedValues[3]);
    Serial.print("Error(%) MQ8: "); 
    Serial.print(error[0]); Serial.print(" ");
    Serial.print(error[1]); Serial.print(" ");
    Serial.print(error[2]); Serial.print(" ");
    Serial.print(error[3]); Serial.print(" | Calculated(PPM): ");
    Serial.print(calculatedValues[0]); Serial.print(" ");
    Serial.print(calculatedValues[1]); Serial.print(" ");
    Serial.print(calculatedValues[2]); Serial.print(" ");
    Serial.print(calculatedValues[3]); Serial.print(" | Expected(PPM): ");
    Serial.print(expectedValue[0]); Serial.print(" ");
    Serial.print(expectedValue[1]); Serial.print(" ");
    Serial.print(expectedValue[2]); Serial.print(" ");
    Serial.print(expectedValue[3]); Serial.println(" | ");        
    // Testing MQ9 LPG
    ratio[0] = 2; ratio[1] = 1.4; ratio[2] = 0.7; ratio[3] = 0.23;
    expectedValue[0] = 200; expectedValue[1] = 500; expectedValue[2] = 2000; expectedValue[3] = 10000;
    calculatedValues[0] = MQ9.validateEcuation(ratio[0]);
    calculatedValues[1] = MQ9.validateEcuation(ratio[1]);
    calculatedValues[2] = MQ9.validateEcuation(ratio[2]);
    calculatedValues[3] = MQ9.validateEcuation(ratio[3]);
    error[0] = calculatePercentualError(expectedValue[0], calculatedValues[0]);
    error[1] = calculatePercentualError(expectedValue[1], calculatedValues[1]);
    error[2] = calculatePercentualError(expectedValue[2], calculatedValues[2]);
    error[3] = calculatePercentualError(expectedValue[3], calculatedValues[3]);
    Serial.print("Error(%) MQ9: "); 
    Serial.print(error[0]); Serial.print(" ");
    Serial.print(error[1]); Serial.print(" ");
    Serial.print(error[2]); Serial.print(" ");
    Serial.print(error[3]); Serial.print(" | Calculated(PPM): ");
    Serial.print(calculatedValues[0]); Serial.print(" ");
    Serial.print(calculatedValues[1]); Serial.print(" ");
    Serial.print(calculatedValues[2]); Serial.print(" ");
    Serial.print(calculatedValues[3]); Serial.print(" | Expected(PPM): ");
    Serial.print(expectedValue[0]); Serial.print(" ");
    Serial.print(expectedValue[1]); Serial.print(" ");
    Serial.print(expectedValue[2]); Serial.print(" ");
    Serial.print(expectedValue[3]); Serial.println(" | ");
    // Testing MQ131 O3
    ratio[0] = 5; ratio[1] = 2; ratio[2] = 0.7; ratio[3] = 0.5;
    expectedValue[0] = 5; expectedValue[1] = 20; expectedValue[2] = 70; expectedValue[3] = 100;
    calculatedValues[0] = MQ131.validateEcuation(ratio[0]);
    calculatedValues[1] = MQ131.validateEcuation(ratio[1]);
    calculatedValues[2] = MQ131.validateEcuation(ratio[2]);
    calculatedValues[3] = MQ131.validateEcuation(ratio[3]);
    error[0] = calculatePercentualError(expectedValue[0], calculatedValues[0]);
    error[1] = calculatePercentualError(expectedValue[1], calculatedValues[1]);
    error[2] = calculatePercentualError(expectedValue[2], calculatedValues[2]);
    error[3] = calculatePercentualError(expectedValue[3], calculatedValues[3]);
    Serial.print("Error(%) MQ131: "); 
    Serial.print(error[0]); Serial.print(" ");
    Serial.print(error[1]); Serial.print(" ");
    Serial.print(error[2]); Serial.print(" ");
    Serial.print(error[3]); Serial.print(" | Calculated(PPM): ");
    Serial.print(calculatedValues[0]); Serial.print(" ");
    Serial.print(calculatedValues[1]); Serial.print(" ");
    Serial.print(calculatedValues[2]); Serial.print(" ");
    Serial.print(calculatedValues[3]); Serial.print(" | Expected(PPM): ");
    Serial.print(expectedValue[0]); Serial.print(" ");
    Serial.print(expectedValue[1]); Serial.print(" ");
    Serial.print(expectedValue[2]); Serial.print(" ");
    Serial.print(expectedValue[3]); Serial.println(" | ");
    // Testing MQ135 NH4
    ratio[0] = 2.6; ratio[1] = 1.9; ratio[2] = 1.1; ratio[3] = 0.75;
    expectedValue[0] = 10; expectedValue[1] = 20; expectedValue[2] = 100; expectedValue[3] = 200;
    calculatedValues[0] = MQ135.validateEcuation(ratio[0]);
    calculatedValues[1] = MQ135.validateEcuation(ratio[1]);
    calculatedValues[2] = MQ135.validateEcuation(ratio[2]);
    calculatedValues[3] = MQ135.validateEcuation(ratio[3]);
    error[0] = calculatePercentualError(expectedValue[0], calculatedValues[0]);
    error[1] = calculatePercentualError(expectedValue[1], calculatedValues[1]);
    error[2] = calculatePercentualError(expectedValue[2], calculatedValues[2]);
    error[3] = calculatePercentualError(expectedValue[3], calculatedValues[3]);
    Serial.print("Error(%) MQ135: "); 
    Serial.print(error[0]); Serial.print(" ");
    Serial.print(error[1]); Serial.print(" ");
    Serial.print(error[2]); Serial.print(" ");
    Serial.print(error[3]); Serial.print(" | Calculated(PPM): ");
    Serial.print(calculatedValues[0]); Serial.print(" ");
    Serial.print(calculatedValues[1]); Serial.print(" ");
    Serial.print(calculatedValues[2]); Serial.print(" ");
    Serial.print(calculatedValues[3]); Serial.print(" | Expected(PPM): ");
    Serial.print(expectedValue[0]); Serial.print(" ");
    Serial.print(expectedValue[1]); Serial.print(" ");
    Serial.print(expectedValue[2]); Serial.print(" ");
    Serial.print(expectedValue[3]); Serial.println(" | ");
    // Testing MQ303 Isobutano
    ratio[0] = 0.4; ratio[1] = 0.3; ratio[2] = 0.19; ratio[3] = 0.08;
    expectedValue[0] = 100; expectedValue[1] = 300; expectedValue[2] = 1000; expectedValue[3] = 10000;
    calculatedValues[0] = MQ303.validateEcuation(ratio[0]);
    calculatedValues[1] = MQ303.validateEcuation(ratio[1]);
    calculatedValues[2] = MQ303.validateEcuation(ratio[2]);
    calculatedValues[3] = MQ303.validateEcuation(ratio[3]);
    error[0] = calculatePercentualError(expectedValue[0], calculatedValues[0]);
    error[1] = calculatePercentualError(expectedValue[1], calculatedValues[1]);
    error[2] = calculatePercentualError(expectedValue[2], calculatedValues[2]);
    error[3] = calculatePercentualError(expectedValue[3], calculatedValues[3]);
    Serial.print("Error(%) MQ303: "); 
    Serial.print(error[0]); Serial.print(" ");
    Serial.print(error[1]); Serial.print(" ");
    Serial.print(error[2]); Serial.print(" ");
    Serial.print(error[3]); Serial.print(" | Calculated(PPM): ");
    Serial.print(calculatedValues[0]); Serial.print(" ");
    Serial.print(calculatedValues[1]); Serial.print(" ");
    Serial.print(calculatedValues[2]); Serial.print(" ");
    Serial.print(calculatedValues[3]); Serial.print(" | Expected(PPM): ");
    Serial.print(expectedValue[0]); Serial.print(" ");
    Serial.print(expectedValue[1]); Serial.print(" ");
    Serial.print(expectedValue[2]); Serial.print(" ");
    Serial.print(expectedValue[3]); Serial.println(" | ");
    // Testing MQ309 CO
    ratio[0] = 6; ratio[1] = 5; ratio[2] = 4.3; ratio[3] = 4;
    expectedValue[0] = 1000; expectedValue[1] = 3000; expectedValue[2] = 5000; expectedValue[3] = 7000;
    calculatedValues[0] = MQ309.validateEcuation(ratio[0]);
    calculatedValues[1] = MQ309.validateEcuation(ratio[1]);
    calculatedValues[2] = MQ309.validateEcuation(ratio[2]);
    calculatedValues[3] = MQ309.validateEcuation(ratio[3]);
    error[0] = calculatePercentualError(expectedValue[0], calculatedValues[0]);
    error[1] = calculatePercentualError(expectedValue[1], calculatedValues[1]);
    error[2] = calculatePercentualError(expectedValue[2], calculatedValues[2]);
    error[3] = calculatePercentualError(expectedValue[3], calculatedValues[3]);
    Serial.print("Error(%) MQ309: "); 
    Serial.print(error[0]); Serial.print(" ");
    Serial.print(error[1]); Serial.print(" ");
    Serial.print(error[2]); Serial.print(" ");
    Serial.print(error[3]); Serial.print(" | Calculated(PPM): ");
    Serial.print(calculatedValues[0]); Serial.print(" ");
    Serial.print(calculatedValues[1]); Serial.print(" ");
    Serial.print(calculatedValues[2]); Serial.print(" ");
    Serial.print(calculatedValues[3]); Serial.print(" | Expected(PPM): ");
    Serial.print(expectedValue[0]); Serial.print(" ");
    Serial.print(expectedValue[1]); Serial.print(" ");
    Serial.print(expectedValue[2]); Serial.print(" ");
    Serial.print(expectedValue[3]); Serial.println(" | ");
    
    Serial.println("Test finalizado, por favor verifica que no existan errores >= 0.3 -> significa que no sea mayor al 30%");
    delay(60000);
}

double calculatePercentualError(double expectedValue, double calculatedValue)
{
    // Return the diference between two measures
    return abs(calculatedValue-expectedValue)/expectedValue;
}

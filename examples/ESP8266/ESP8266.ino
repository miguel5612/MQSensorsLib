// This is an example of implementation using ESP8266
// Never connect the sensor direct to the ESP8266, sensor high level is 5V
// ADC of ESP8266 high level is 3.3
// To connect use a voltage divisor, where 5V will 3v3 on the middle point like
// this {{URL}}

/*
  MQUnifiedsensor Library - reading an MQSensor using ESP8266 board

  For this example wi will demonstrates the use a MQ3 sensor.
  Library originally added 01 may 2019
  by Miguel A Califa, Yersson Carrillo, Ghiordy Contreras, Mario Rodriguez
 
  Added ESP8266 example 
  29.03.2020
  Wiring:
  https://github.com/miguel5612/MQSensorsLib_Docs/blob/master/static/img/MQ_ESP8266.PNG

 This example code is in the public domain.

*/

//Include the library
#include <MQUnifiedsensor.h>

//Definitions
#define placa "ESP8266" //NodeMcu, WeMos D1, TTGo, ESP32.. etc
#define Voltage_Resolution 3.3
#define pin A0 //Analog input 0 of your ESP Board
#define type "MQ-3" //MQ3
#define ADC_Bit_Resolution 10 // For ESP8266

//Declare Sensor
MQUnifiedsensor MQ3(placa, Voltage_Resolution, ADC_Bit_Resolution, pin, type);

void setup() {
  //Init the serial port communication - to debug the library
  Serial.begin(9600); //Init serial port

  //Set math model to calculate the PPM concentration and the value of constants
  MQ3.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ3.setA(4.8387); MQ3.setB(-2.68); // Configurate the ecuation values to get Benzene concentration
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
  /*****************************  MQ Init ********************************************/ 
  //Input: setup flag, if this function are on setup will print the headers (Optional - Default value: False)
  //Output: print on serial port the information about sensor and sensor readings
  //Remarks: Configure the pin of arduino as input.
  /************************************************************************************/ 
  MQ3.serialDebug(true);
}

void loop() {
  MQ3.update(); // Update data, the arduino will be read the voltage on the analog pin
  MQ3.readSensor(); // Sensor will read PPM concentration using the model and a and b values setted before or in the setup
  MQ3.serialDebug(); // Will print the table on the serial port
  delay(500); //Sampling frequency
}
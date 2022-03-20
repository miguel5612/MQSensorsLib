/*
 *  This sketch fixes the MQ2 measuring issue when using Wifi.h
 *  Wifi.h deactivates pin 25 analogical input on esp32.ino default sketch.
 *  This is because Wifi.h works only with ADC1 for analogical measurement
 *  Please check the esp32-wroom-32d.jpg image on ESP32 folder
 * 

 * ADC1 GPIO
 * ADC1_CH0 (GPIO 36) // only tested on this and it works as expected :)
 * ADC1_CH1 (GPIO 37)
 * ADC1_CH2 (GPIO 38)
 * ADC1_CH3 (GPIO 39)
 * ADC1_CH4 (GPIO 32)
 * ADC1_CH5 (GPIO 33)
 * ADC1_CH6 (GPIO 34)
 * ADC1_CH7 (GPIO 35)
 *
 * ADC2 GPIO
 * ADC2_CH0 (GPIO 4)
 * ADC2_CH1 (GPIO 0)
 * ADC2_CH2 (GPIO 2)
 * ADC2_CH3 (GPIO 15)
 * ADC2_CH4 (GPIO 13)
 * ADC2_CH5 (GPIO 12)
 * ADC2_CH6 (GPIO 14)
 * ADC2_CH7 (GPIO 27)
 * ADC2_CH8 (GPIO 25)
 * ADC2_CH9 (GPIO 26)
 *
 */


#include <WiFi.h>

//Include the library
#include <MQUnifiedsensor.h>
/************************Hardware Related Macros************************************/
#define         Board                   ("ESP-32") // Wemos ESP-32 or other board, whatever have ESP32 core.

//https://www.amazon.com/HiLetgo-ESP-WROOM-32-Development-Microcontroller-Integrated/dp/B0718T232Z (Although Amazon shows ESP-WROOM-32 ESP32 ESP-32S, the board is the ESP-WROOM-32D)
#define         Pin                     (36) //check the esp32-wroom-32d.jpg image on ESP32 folder 

/***********************Software Related Macros************************************/
#define         Type                    ("MQ-2") //MQ2 or other MQ Sensor, if change this verify your a and b values.
#define         Voltage_Resolution      (3.3) // 3V3 <- IMPORTANT. Source: https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/
#define         ADC_Bit_Resolution      (12) // ESP-32 bit resolution. Source: https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/
#define         RatioMQ2CleanAir        (9.83) //RS / R0 = 9.83 ppm
/*****************************Globals***********************************************/
MQUnifiedsensor MQ2(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin, Type);
/*****************************Globals***********************************************/

const char* ssid     = "your-ssid";
const char* password = "your-password";

void setup()
{

  //Init the serial port communication - to debug the library
  Serial.begin(115200); //Init serial port
  delay(10);

  //Set math model to calculate the PPM concentration and the value of constants
  MQ2.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ2.setA(987.99); MQ2.setB(-2.162); // Configure the equation to to calculate H2 concentration
  
/*
    Exponential regression:
    Gas    | a      | b
    H2     | 987.99 | -2.162
    LPG    | 574.25 | -2.222
    CO     | 36974  | -3.109
    Alcohol| 3616.1 | -2.675
    Propane| 658.71 | -2.168
  */

  /*****************************  MQ Init ********************************************/ 
  //Remarks: Configure the pin of arduino as input.
  /************************************************************************************/ 
  MQ2.init(); 
 
  /* 
    //If the RL value is different from 10K please assign your RL value with the following method:
    MQ2.setRL(10);
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
    MQ2.update(); // Update data, the arduino will read the voltage from the analog pin
    calcR0 += MQ2.calibrate(RatioMQ2CleanAir);
    Serial.print(".");
  }
  MQ2.setR0(calcR0/10);
  Serial.println("  done!.");
  
  if(isinf(calcR0)) {Serial.println("Warning: Conection issue, R0 is infinite (Open circuit detected) please check your wiring and supply"); while(1);}
  if(calcR0 == 0){Serial.println("Warning: Conection issue found, R0 is zero (Analog pin shorts to ground) please check your wiring and supply"); while(1);}
  /*****************************  MQ CAlibration ********************************************/ 
  //MQ2.serialDebug(true); uncomment if you want to print the table on the serial port

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void loop()
{
  MQ2.update(); // Update data, the arduino will read the voltage from the analog pin
  //MQ2.serialDebug(); // Will print the table on the serial port
  Serial.print(MQ2.readSensor()); // Sensor will read PPM concentration using the model, a and b values set previously or from the setup
  Serial.println(" PPM");
  delay(500); //Sampling frequency
}


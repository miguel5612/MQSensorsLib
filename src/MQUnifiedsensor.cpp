#include "MQUnifiedsensor.h"

MQUnifiedsensor::MQSensor(int pin) {
  this->_pin = pin;
}

MQUnifiedsensor::setR0(double R0) {
  this->_R0 = R0;
}

/******************  Info of sensor graphic      *******************/
//MQ-2 - Methane, Butane, LPG, smoke



//MQ-3 - Alcohol, Ethanol, smoke



//MQ-4 - Methane, CNG Gas

const float R0 = 11.820;
const float m = -0.318;
const float b = 1.133;

//MQ-5 - Natural gas, LPG



//MQ-6 - LPG, butane gas



//MQ-7 - Carbon Monoxide



//MQ-8 - Hydrogen Gas



//MQ-9 - Carbon Monoxide, flammable gasses



//MQ131 - Ozone



//MQ135 - Air Quality (CO, Ammonia, Benzene, Alcohol, smoke)



//MQ136 - Hydrogen Sulfide gas



//MQ137 - Ammonia
   

/******************  Info of sensor graphic      *******************/



//***************** Operations ************************************/


int readMethane()
{

}
int readButane()
{

}
int readLPG()
{

}
int readSmoke()
{

}
int readAlcohol()
{

}
int readEthanol()
{

}
int readCNG()
{

}
int readLPG()
{

}
int readCO()
{

}
int readHO()
{

}
int readCarbonMonoxide()
{
    
}
int readNH4()
{
    
}
int readbenzene()
{
    
}
int readAlcohol()
{
    
}
int readHidrogen()
{
    
}
int readToluene()
{
    
}
int readAcetone()
{
    
}
int readPropane()
{
    
}
int readCoalGas()
{
    
}
















const float VOLT_RESOLUTION = 5.0; // if 3.3v use 3.3
const int ADC_RESOLUTION = 10; // for 10bit analog to digital converter.

const int retries = 50;
const int retry_interval = 20;

double MQUnifiedsensor::calibrate() {
    float sensor_volt; //Define variable for sensor voltage
    float RS_air; //Define variable for sensor resistance
    float R0; //Define variable for R0
    float sensorValue; //Define variable for analog readings
    sensor_volt = this->getVoltage(); //Convert average to voltage
    RS_air = ((5.0 * 10.0) / sensor_volt) - 10.0; //Calculate RS in fresh air
    R0 = RS_air / 4.4; //Calculate R0
    return R0;
}

double MQUnifiedsensor::getVoltage() {
  double avg = 0.0;
  for (int i = 0; i < retries; i ++) {
    avg += analogRead(this->_pin) / retries;
    delay(retry_interval);
  }

  double voltage = avg * VOLT_RESOLUTION / (pow(2, ADC_RESOLUTION) - 1);

  return voltage;
}
  
  /**
    * Returns the PPM concentration
    */
  int MQUnifiedsensor::read() {
    double sensor_volt = this->getVoltage();
    double RS_gas; //Define variable for sensor resistance
    double ratio; //Define variable for ratio

    RS_gas = ((5.0 * 10.0) / sensor_volt) - 10.0; //Get value of RS in a gas

    ratio = RS_gas / this->_R0;   // Get ratio RS_gas/RS_air

    double ppm_log = (log10(ratio) - b) / m; //Get ppm value in linear scale according to the the ratio value
    double ppm = pow(10, ppm_log); //Convert ppm value to log scale
    return floor(ppm);
}
#include "MQUnifiedsensor.h"


void MQUnifiedsensor::MQSensor(int pin, int type) {
  this->_pin = pin;
  this->_type = type; //2,3,4,5,6,7,8,9,131,135,303,309
}

void MQUnifiedsensor::setR0(double R0) {
  this->_R0 = R0;
}

String MQUnifiedsensor::readSensor(String nameLectureReqeuired)
{
  switch (_type)
  {
  case 1:
    break;
  
  default:
    break;
  }

}

void MQUnifiedsensor::getSensorCharacteristics(int MQ[38], String nameLectureReqeuired)
{
  if(nameLectureReqeuired = nameLecture[0])
  {
    _m = MQ[indexSlopeLectures[0]];
    _b = MQ[indexBPointLectures[0]];
  }
}

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
  int MQUnifiedsensor::readPPM(int m, int b) {
    double sensor_volt = this->getVoltage();
    double RS_gas; //Define variable for sensor resistance
    double ratio; //Define variable for ratio

    RS_gas = ((5.0 * 10.0) / sensor_volt) - 10.0; //Get value of RS in a gas

    ratio = RS_gas / this->_R0;   // Get ratio RS_gas/RS_air

    double ppm_log = (log10(ratio) - b) / m; //Get ppm value in linear scale according to the the ratio value
    double ppm = pow(10, ppm_log); //Convert ppm value to log scale
    return floor(ppm);
  }
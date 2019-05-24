#include "MQUnifiedsensor.h"


 MQUnifiedsensor::MQUnifiedsensor(int pin, int type) {

  this->_pin = pin;
  this->_type = type; //2,3,4,5,6,7,8,9,131,135,303,309
  //Set _MQ variable with MQ sensor selected
  if(_type == 2)
  {
    _MQ = MQ2;
  }
  else if(_type == 3)
  {
    _MQ = MQ3;
  }
  else if(_type == 4)
  {
    _MQ = MQ4;
  }
  else if(_type == 5)
  {
    _MQ = MQ5;
  }
  else if(_type == 6)
  {
    _MQ = MQ6;
  }
  else if(_type == 7)
  {
    _MQ = MQ7;
  }
  else if(_type == 8)
  {
    _MQ = MQ8;
  }
  else if(_type == 9)
  {
    _MQ = MQ9;
  }
  else if(_type == 131)
  {
    _MQ = MQ131;
  }
  else if(_type == 135)
  {
    _MQ = MQ135;
  }
  else if(_type == 303)
  {
    _MQ = MQ303A;
  }
  else if(_type == 309)
  {
    _MQ = MQ309;
  }
}

void MQUnifiedsensor::setR0(double R0) {
  this->_R0 = R0;
}

int MQUnifiedsensor::readSensor(String nameLectureRequeired = "")
{
  setSensorCharacteristics(nameLectureRequeired);
  return readPPM(_m, _b);
}
void MQUnifiedsensor::inicializar()
{
  pinMode(_pin, INPUT);
}
void MQUnifiedsensor::setSensorCharacteristics(String nameLectureRequeired)
{
  int wantedpos = 0;
  if(nameLectureRequeired == "")
  {
    if(_type == 2)
    {
      wantedpos = defaultMQ2;
    }
    else if(_type == 3)
    {
      wantedpos = defaultMQ3;
    }
    else if(_type == 4)
    {
      wantedpos = defaultMQ4;
    }
    else if(_type == 5)
    {
      wantedpos = defaultMQ5;
    }
    else if(_type == 6)
    {
      wantedpos = defaultMQ6;
    }
    else if(_type == 7)
    {
      wantedpos = defaultMQ7;
    }
    else if(_type == 8)
    {
      wantedpos = defaultMQ8;
    }
    else if(_type == 9)
    {
      wantedpos = defaultMQ9;
    }
    else if(_type == 131)
    {
      wantedpos = defaultMQ131;
    }
    else if(_type == 135)
    {
      wantedpos = defaultMQ135;
    }
    else if(_type == 303)
    {
      wantedpos = defaultMQ303;
    }
    else if(_type == 309)
    {
      wantedpos = defaultMQ309;
    }
  }
  else 
  {
    for (int i=0; i<lecturesAvailable; i++) {
        if (nameLectureRequeired = nameLecture[i]) {    //modified here
          wantedpos = i;
          break;
        }
      }
  }
    
  _m = MQ[indexSlopeLectures[wantedpos]];
  _b = MQ[indexBPointLectures[wantedpos]];
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
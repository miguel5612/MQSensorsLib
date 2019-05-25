#include "MQUnifiedsensor.h"

 MQUnifiedsensor::MQUnifiedsensor(int pin, int type) {

  this->_pin = pin;
  this->_type = type; //2,3,4,5,6,7,8,9,131,135,303,309
  //Set _MQ variable with MQ sensor selected
  if(_type == 2)
  {
    memcpy(_MQ, MQ2, sizeof(MQ2));
    //_MQ = MQ2;
  }
  else if(_type == 3)
  {
    memcpy(_MQ, MQ3, sizeof(MQ3));
    //_MQ = MQ3;
  }
  else if(_type == 4)
  {
    memcpy(_MQ, MQ4, sizeof(MQ4));
    //_MQ = MQ4;
  }
  else if(_type == 5)
  {
    memcpy(_MQ, MQ5, sizeof(MQ5));
    //_MQ = MQ5;
  }
  else if(_type == 6)
  {
    memcpy(_MQ, MQ6, sizeof(MQ6));
    //_MQ = MQ6;
  }
  else if(_type == 7)
  {
    memcpy(_MQ, MQ7, sizeof(MQ7));
    //_MQ = MQ7;
  }
  else if(_type == 8)
  {
    memcpy(_MQ, MQ8, sizeof(MQ8));
    //_MQ = MQ8;
  }
  else if(_type == 9)
  {
    memcpy(_MQ, MQ9, sizeof(MQ9));
    //_MQ = MQ9;
  }
  else if(_type == 131)
  {
    memcpy(_MQ, MQ131, sizeof(MQ131));
    //_MQ = MQ131;
  }
  else if(_type == 135)
  {
    memcpy(_MQ, MQ135, sizeof(MQ135));
    //_MQ = MQ135;
  }
  else if(_type == 303)
  {
    memcpy(_MQ, MQ303A, sizeof(MQ303A));
    //_MQ = MQ303A;
  }
  else if(_type == 309)
  {
    memcpy(_MQ, MQ309A, sizeof(MQ309A));
    //_MQ = MQ309;
  }
}
void MQUnifiedsensor::inicializar()
{
  pinMode(_pin, INPUT);
}
int MQUnifiedsensor::readSensor(String nameLectureRequeired, bool print)
{
  setSensorCharacteristics(nameLectureRequeired, print);
  _PPM =readPPM(_m, _b);
  if(print)
  {
    String nameLecture = getnameLecture();
  
    Serial.print("Medicion");
    Serial.print("(" + nameLecture + "): ");
    Serial.println(_PPM);
    Serial.print("Slope: ");
    Serial.print(String(_m));
    Serial.print(", B point: ");
    Serial.println(String(_b));
  }
  return _PPM;
}
String MQUnifiedsensor::getnameLecture()
{
  return _nameLectureRequeired;
}
void MQUnifiedsensor::setSensorCharacteristics(String nameLectureRequeired, bool print)
{
  //Defaults index
  if(nameLectureRequeired == "")
  {
    nameLectureRequeired = __nameLectureRequeired;
  }

  //Dinamic index search
  if(print)
  {
    Serial.println("Busqueda dinamica de los indices");
  }
  for (int i=0; i<sizeof(_MQ); i++) {
      if (nameLectureRequeired = _MQ[i]) {    //modified here
        _lecturePosInArray = i;
        break;
      }
    }
  
  //Serial debugging
  if(print)
  {
    String nameLecture = getnameLecture();
  
    Serial.print("index in nameLectures: ");
    Serial.println(_lecturePosInArray);
    Serial.print("Slope index: ");
    Serial.println(_lecturePosInArray+1);
    Serial.print("B point index: ");
    Serial.println(_lecturePosInArray+2);
  }
  _m = stringToDouble(_MQ[_lecturePosInArray+1]);
  _b = stringToDouble(_MQ[_lecturePosInArray+2]);
  //Save the name for future calls
  nameLectureRequeired = __nameLectureRequeired;
}
int MQUnifiedsensor::readPPM(int m, int b) {
  /**
  * Returns the PPM concentration
  */
  double sensor_volt = this->getVoltage();
  double RS_gas; //Define variable for sensor resistance
  double ratio; //Define variable for ratio

  RS_gas = ((5.0 * 10.0) / sensor_volt) - 10.0; //Get value of RS in a gas

  ratio = RS_gas / this->_R0;   // Get ratio RS_gas/RS_air

  double ppm_log = (log10(ratio) - b) / m; //Get ppm value in linear scale according to the the ratio value
  double ppm = pow(10, ppm_log); //Convert ppm value to log scale
  return floor(ppm);
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
void MQUnifiedsensor::setR0(double R0) {
  this->_R0 = R0;
}
void MQUnifiedsensor::setDefaultGas()
{
  Serial.println("Carga de los gases por defecto");
    if(_type == 2)
    {
      _nameLectureRequeired = defaultMQ2;
    }
    else if(_type == 3)
    {
      _nameLectureRequeired = defaultMQ3;
    }
    else if(_type == 4)
    {
      _nameLectureRequeired = defaultMQ4;
    }
    else if(_type == 5)
    {
      _nameLectureRequeired = defaultMQ5;
    }
    else if(_type == 6)
    {
      _nameLectureRequeired = defaultMQ6;
    }
    else if(_type == 7)
    {
      _nameLectureRequeired = defaultMQ7;
    }
    else if(_type == 8)
    {
      _nameLectureRequeired = defaultMQ8;
    }
    else if(_type == 9)
    {
      _nameLectureRequeired = defaultMQ9;
    }
    else if(_type == 131)
    {
      _nameLectureRequeired = defaultMQ131;
    }
    else if(_type == 135)
    {
      _nameLectureRequeired = defaultMQ135;
    }
    else if(_type == 303)
    {
      _nameLectureRequeired = defaultMQ303;
    }
    else if(_type == 309)
    {
      _nameLectureRequeired = defaultMQ309;
    }
}
double MQUnifiedsensor::stringToDouble(String & str)
{
  return atof( str.c_str() );
}
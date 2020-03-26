#include "MQUnifiedsensor.h"

MQUnifiedsensor::MQUnifiedsensor(String Placa, int Voltage_Resolution, int pin, String type) {
  this->_pin = pin;
  this->_type = type; //MQ-2, MQ-3 ... MQ-309A
  this->_placa = Placa;
  this-> _VOLT_RESOLUTION = Voltage_Resolution;
}
MQUnifiedsensor::setA(double a) {
  this->_a = a;
}
MQUnifiedsensor::setB(double b) {
  this->_b = b;
}
MQUnifiedsensor::serialDebug(boolean onSetup, String regressionMethod)
{
  if(onSetup)
  {
    Serial.println("************************************************************************************************************************************************");
    Serial.println("MQ sensor reading library for arduino");

    Serial.println("Note: remember that all the parameters below can be modified during the program execution with the methods:");
    Serial.println("setR0, setRL, setA, setB where you will have to send as parameter the new value, example: mySensor.setR0(20); //R0 = 20K");

    Serial.println("Authors: Miguel A. Califa U - Yersson R. Carrillo A - Ghiordy F. Contreras C");
    Serial.println("Contributors: Andres A. Martinez - Juan A. Rodríguez - Mario A. Rodríguez O ");

    Serial.println("Sensor:" + _type);
    Serial.println("Supply voltage:" + _VOLT_RESOLUTION);
    Serial.println("R0: " + _R0);
    Serial.println("RL: " + _RL);

    Serial.println("Model: Logarithmic regression with parameters.");
    Serial.println(_type + ":" + "a:" + _a + " | b:" + _b);

    Serial.println("Development board: " + _placa);
  }
  else 
  {
    if(!_firstFlag)
    {
      Serial.println("| ****************************************************************" + _type + "****************************************************************|");
      Serial.println("|ADC_In | Equation_V_ADC | Voltage_ADC |        Equation_R         | Resistance_RS  |    EQ_Ratio  | Ratio (RS/R0) | Equation_PPM |     PPM    |");
      _firstFlag = true;  //Headers are printed
    }
    else
    {
      String eq = "";
      if(regression == "Linear") eq = "ratio*a + b"
      if(regression == "Exponential") eq = "a*ratio^b"
      Serial.println("|" + _adc + "|" + "v = ADC*" + _VOLT_RESOLUTION + "/1024" + "|" + _sensor_volt + "|" + "RS = ((" + _VOLT_RESOLUTION + "*RL)/Voltage) - RL" + "|" + _RS_Calc + "|" + "Ratio = RS/R0" + "|" + _ratio + "|" + eq + "|" + _PPM);
    }
  }
}
void MQUnifiedsensor::update()
{
  _sensor_volt = this->getVoltage();
}
void MQUnifiedsensor::setVoltResolution(float voltaje)
{
  _VOLT_RESOLUTION = voltaje;
}
void MQUnifiedsensor::init()
{
  pinMode(_pin, INPUT);
}
float MQUnifiedsensor::readSensor(String regressionMethod)
{
  //More explained in: https://jayconsystems.com/blog/understanding-a-gas-sensor
  _RS_Calc = ((_VOLT_RESOLUTION*_RLValue)/_sensor_volt)-_RLValue; //Get value of RS in a gas
  if(_RS_Calc < 0)  _RS_Calc = 0; //No negative values accepted.
  _ratio = _RS_Calc / this->_R0;   // Get ratio RS_gas/RS_air
  if(_ratio <= 0 || _ratio>100)  _ratio = 0.01; //No negative values accepted or upper datasheet recomendation.
  if(regressionMethod == "Exponential") _PPM= _a*pow(_ratio, _b);
  if(regressionMethod == "Linear") _PPM= _a*_ratio + _b);
  if(_PPM < 0)  _PPM = 0; //No negative values accepted or upper datasheet recomendation.
  if(_PPM > 10000) _PPM = 9999; //No negative values accepted or upper datasheet recomendation.
  return _PPM;
}
String MQUnifiedsensor::getnameLecture()
{
  return _nameLectureRequeired;
}
float MQUnifiedsensor::calibrate() {
  //More explained in: https://jayconsystems.com/blog/understanding-a-gas-sensor
  /*
  V = I x R 
  VRL = [VC / (RS + RL)] x RL 
  VRL = (VC x RL) / (RS + RL) 
  Así que ahora resolvemos para RS: 
  VRL x (RS + RL) = VC x RL
  (VRL x RS) + (VRL x RL) = VC x RL 
  (VRL x RS) = (VC x RL) - (VRL x RL)
  RS = [(VC x RL) - (VRL x RL)] / VRL
  RS = [(VC x RL) / VRL] - RL
  */
  float RS_air; //Define variable for sensor resistance
  float R0; //Define variable for R0
  RS_air = ((_VOLT_RESOLUTION*_RLValue)/_sensor_volt)-_RLValue; //Calculate RS in fresh air
  if(RS_air < 0)  RS_air = 0; //No negative values accepted.
  R0 = RS_air/_ratioInCleanAir; //Calculate R0 
  if(R0 < 0)  R0 = 0; //No negative values accepted.
  return R0;
}
double MQUnifiedsensor::getVoltage(int read) {
  double voltage;
  if(read)
  {
    double avg = 0.0;
    for (int i = 0; i < retries; i ++) {
      _adc = analogRead(this->_pin);
      avg += _adc;
      delay(retry_interval);
    }
    voltage = (avg/ retries) * _VOLT_RESOLUTION / (pow(2, ADC_RESOLUTION) - 1);
  }
  else
  {
    voltage = _sensor_volt;
  }
  return voltage;
}


void MQUnifiedsensor::setR0(double R0) {
  this->_R0 = R0;
}

double MQUnifiedsensor::getR0() {
  return _R0;
}
void MQUnifiedsensor::setRL(double RL) {
  this->_RLValue = RL;
}

double MQUnifiedsensor::getRL() {
  return _RLValue;
}

double MQUnifiedsensor::stringToDouble(String & str)
{
  return atof( str.c_str() );
}
#include "MQUnifiedsensor.h"

 MQUnifiedsensor::MQUnifiedsensor(int pin, int type) {

  this->_pin = pin;
  this->_type = type; //2,3,4,5,6,7,8,9,131,135,303,309
  //Set _MQ variable with MQ sensor selected
  if(_type == 2)
  {
    //memcpy(_MQ, _MQ2, sizeof(_MQ2));
    _ratioInCleanAir = RatioMQ2CleanAir;
    _R0 = R0_MQ2;
    //_MQ = MQ2;
  }
  else if(_type == 3)
  {
    //memcpy(_MQ, _MQ3, sizeof(_MQ3));
    _ratioInCleanAir = RatioMQ3CleanAir;
    _R0 = R0_MQ3;
    //_MQ = MQ3;
  }
  else if(_type == 4)
  {
    //memcpy(_MQ, _MQ4, sizeof(_MQ4));
    _ratioInCleanAir = RatioMQ4CleanAir;
    _R0 = R0_MQ4;
    //_MQ = MQ4;
  }
  else if(_type == 5)
  {
    //memcpy(_MQ, _MQ5, sizeof(_MQ5));
    _ratioInCleanAir = RatioMQ5CleanAir;
    _R0 = R0_MQ5;
    //_MQ = MQ5;
  }
  else if(_type == 6)
  {
    //memcpy(_MQ, _MQ6, sizeof(_MQ6));
    _ratioInCleanAir = RatioMQ6CleanAir;
    _R0 = R0_MQ6;
    //_MQ = MQ6;
  }
  else if(_type == 7)
  {
    //memcpy(_MQ, _MQ7, sizeof(_MQ7));
    _ratioInCleanAir = RatioMQ7CleanAir;
    _R0 = R0_MQ7;
    //_MQ = MQ7;
  }
  else if(_type == 8)
  {
    //memcpy(_MQ, _MQ8, sizeof(_MQ8));
    _ratioInCleanAir = RatioMQ8CleanAir;
    _R0 = R0_MQ8;
    //_MQ = MQ8;
  }
  else if(_type == 9)
  {
    //memcpy(_MQ, _MQ9, sizeof(_MQ9));
    _ratioInCleanAir = RatioMQ9CleanAir;
    _R0 = R0_MQ9;
    //_MQ = MQ9;
  }
  else if(_type == 131)
  {
    //memcpy(_MQ, _MQ131, sizeof(_MQ131));
    _ratioInCleanAir = RatioMQ131CleanAir;
    _R0 = R0_MQ131;
    //_MQ = MQ131;
  }
  else if(_type == 135)
  {
    //memcpy(_MQ, _MQ135, sizeof(_MQ135));
    _ratioInCleanAir = RatioMQ135CleanAir;
    _R0 = R0_MQ135;
    //_MQ = MQ135;
  }
  else if(_type == 303)
  {
    //memcpy(_MQ, _MQ303A, sizeof(_MQ303A));
    _ratioInCleanAir = RatioMQ303CleanAir;
    _R0 = R0_MQ303;
    //_MQ = MQ303A;
  }
  else if(_type == 309)
  {
    //memcpy(_MQ, _MQ309A, sizeof(_MQ309A));
    _ratioInCleanAir = RatioMQ309CleanAir;
    _R0 = R0_MQ309;
    //_MQ = MQ309;
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
void MQUnifiedsensor::inicializar()
{
  pinMode(_pin, INPUT);
}
int MQUnifiedsensor::readSensor(String nameLectureRequeired, bool print)
{
  setSensorCharacteristics(nameLectureRequeired, print); //In this function update _a and _b
  _RS_Calc = ((_VOLT_RESOLUTION*_RLValue)/_sensor_volt)-_RLValue; //Get value of RS in a gas
  _ratio = _RS_Calc / this->_R0;   // Get ratio RS_gas/RS_air
  _PPM= a*pow(_ratio, b);

  if(print)
  {
    String nameLecture = getnameLecture();
    Serial.println("**********************");
    Serial.println("* Sensor: MQ-" + String(_type));
    Serial.println("* Vcc: " + String(_VOLT_RESOLUTION) + ", RS: " + String(_RS_Calc));
    Serial.println("* RS/R0 = " + String(_ratio) + " ,Voltaje leido(ADC): " + String(_sensor_volt));
    Serial.println("* PPM = " + _a + "pow(Rs/R0, +" + _b + ")");
    Serial.println("* Lectura(" + nameLecture + ")=" + String(_PPM) + " PPM");
    Serial.println("**********************");
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
    //Set default
    setDefaultGas();
    //Put  the default into variable internally used
    nameLectureRequeired = _nameLectureRequeired;
  }

  //Dinamic index search
  /*
  for (int i=0; i<sizeof(_MQ); i++) {
      if (nameLectureRequeired == _MQ[i]) {    //modified here
        _lecturePosInArray = i;
        break;
      }
    }
  */
  if(_type == 2)
    {
      if(_nameLectureRequeired == "H2")
      {
        _nameLectureRequeired = "H2";
        _a = MQ2_H2_m;
        _b = MQ2_H2_b;
      }
      else if(_nameLectureRequeired == "LPG")
      {
        _nameLectureRequeired = "LPG";
        _a = MQ2_LPG_m;
        _b = MQ2_LPG_b;
      }
      else if(_nameLectureRequeired == "CO")
      {
        _nameLectureRequeired = "CO";
        _a = MQ2_CO_m;
        _b = MQ2_CO_b;
      }    
      else if(_nameLectureRequeired == "Alcohol")
      {
        _nameLectureRequeired = "Alcohol";
        _a = MQ2_Alcohol_m;
        _b = MQ2_Alcohol_b;
      }  
      else if(_nameLectureRequeired == "Propane")
      {
        _nameLectureRequeired = "Propane";
        _a = MQ2_Propane_m;
        _b = MQ2_Propane_b;
      }   
      else if(_nameLectureRequeired == "Benzene")
      {
        _nameLectureRequeired = "Benzene";
        _a = MQ2_Benzene_m;
        _b = MQ2_Benzene_b;
      }    
    }
    else if(_type == 3)
    {
      if(_nameLectureRequeired == "LPG")
      {
        _nameLectureRequeired = "LPG";
        _a = MQ3_LPG_m;
        _b = MQ3_LPG_b;
      }
      else if(_nameLectureRequeired == "CH4")
      {
        _nameLectureRequeired = "CH4";
        _a = MQ3_CH4_m;
        _b = MQ3_CH4_b;
      }
      else if(_nameLectureRequeired == "CO")
      {
        _nameLectureRequeired = "CO";
        _a = MQ3_CO_m;
        _b = MQ3_CO_b;
      }    
      else if(_nameLectureRequeired == "Alcohol")
      {
        _nameLectureRequeired = "Alcohol";
        _a = MQ3_Alcohol_m;
        _b = MQ3_Alcohol_b;
      }  
      else if(_nameLectureRequeired == "Hexane")
      {
        _nameLectureRequeired = "Hexane";
        _a = MQ3_Hexane_m;
        _b = MQ3_Hexane_b;
      }   
      else if(_nameLectureRequeired == "Benzene")
      {
        _nameLectureRequeired = "Benzene";
        _a = MQ3_Benzene_m;
        _b = MQ3_Benzene_b;
      }
    }
    else if(_type == 4)
    {
      if(_nameLectureRequeired == "LPG")
      {
        _nameLectureRequeired = "LPG";
        _a = MQ4_LPG_m;
        _b = MQ4_LPG_b;
      }
      else if(_nameLectureRequeired == "CH4")
      {
        _nameLectureRequeired = "CH4";
        _a = MQ4_CH4_m;
        _b = MQ4_CH4_b;
      }
      else if(_nameLectureRequeired == "CO")
      {
        _nameLectureRequeired = "CO";
        _a = MQ4_CO_m;
        _b = MQ4_CO_b;
      }    
      else if(_nameLectureRequeired == "Alcohol")
      {
        _nameLectureRequeired = "Alcohol";
        _a = MQ4_Alcohol_m;
        _b = MQ4_Alcohol_b;
      }  
      else if(_nameLectureRequeired == "smoke")
      {
        _nameLectureRequeired = "smoke";
        _a = MQ4_smoke_m;
        _b = MQ4_smoke_b;
      }   
    }
    else if(_type == 5)
    {
      if(_nameLectureRequeired == "H2")
      {
        _nameLectureRequeired = "H2";
        _a = MQ5_H2_m;
        _b = MQ5_H2_b;
      }   
      else if(_nameLectureRequeired == "LPG")
      {
        _nameLectureRequeired = "LPG";
        _a = MQ5_LPG_m;
        _b = MQ5_LPG_b;
      }
      else if(_nameLectureRequeired == "CH4")
      {
        _nameLectureRequeired = "CH4";
        _a = MQ5_CH4_m;
        _b = MQ5_CH4_b;
      }
      else if(_nameLectureRequeired == "CO")
      {
        _nameLectureRequeired = "CO";
        _a = MQ5_CO_m;
        _b = MQ5_CO_b;
      }    
      else if(_nameLectureRequeired == "Alcohol")
      {
        _nameLectureRequeired = "Alcohol";
        _a = MQ5_Alcohol_m;
        _b = MQ5_Alcohol_b;
      }  
    }
    else if(_type == 6)
    {
      if(_nameLectureRequeired == "H2")
      {
        _nameLectureRequeired = "H2";
        _a = MQ6_H2_m;
        _b = MQ6_H2_b;
      }   
      else if(_nameLectureRequeired == "LPG")
      {
        _nameLectureRequeired = "LPG";
        _a = MQ6_LPG_m;
        _b = MQ6_LPG_b;
      }
      else if(_nameLectureRequeired == "CH4")
      {
        _nameLectureRequeired = "CH4";
        _a = MQ6_CH4_m;
        _b = MQ6_CH4_b;
      }
      else if(_nameLectureRequeired == "CO")
      {
        _nameLectureRequeired = "CO";
        _a = MQ6_CO_m;
        _b = MQ6_CO_b;
      }    
      else if(_nameLectureRequeired == "Alcohol")
      {
        _nameLectureRequeired = "Alcohol";
        _a = MQ6_Alcohol_m;
        _b = MQ6_Alcohol_b;
      }  
    }
    else if(_type == 7)
    {
      if(_nameLectureRequeired == "H2")
      {
        _nameLectureRequeired = "H2";
        _a = MQ7_H2_m;
        _b = MQ7_H2_b;
      }   
      else if(_nameLectureRequeired == "LPG")
      {
        _nameLectureRequeired = "LPG";
        _a = MQ7_LPG_m;
        _b = MQ7_LPG_b;
      }
      else if(_nameLectureRequeired == "CH4")
      {
        _nameLectureRequeired = "CH4";
        _a = MQ7_CH4_m;
        _b = MQ7_CH4_b;
      }
      else if(_nameLectureRequeired == "CO")
      {
        _nameLectureRequeired = "CO";
        _a = MQ7_CO_m;
        _b = MQ7_CO_b;
      }    
      else if(_nameLectureRequeired == "Alcohol")
      {
        _nameLectureRequeired = "Alcohol";
        _a = MQ7_Alcohol_m;
        _b = MQ7_Alcohol_b;
      } 
    }
    else if(_type == 8)
    {
      if(_nameLectureRequeired == "H2")
      {
        _nameLectureRequeired = "H2";
        _a = MQ8_H2_m;
        _b = MQ8_H2_b;
      }   
      else if(_nameLectureRequeired == "LPG")
      {
        _nameLectureRequeired = "LPG";
        _a = MQ8_LPG_m;
        _b = MQ8_LPG_b;
      }
      else if(_nameLectureRequeired == "CH4")
      {
        _nameLectureRequeired = "CH4";
        _a = MQ8_CH4_m;
        _b = MQ8_CH4_b;
      }
      else if(_nameLectureRequeired == "CO")
      {
        _nameLectureRequeired = "CO";
        _a = MQ8_CO_m;
        _b = MQ8_CO_b;
      }    
      else if(_nameLectureRequeired == "Alcohol")
      {
        _nameLectureRequeired = "Alcohol";
        _a = MQ8_Alcohol_m;
        _b = MQ8_Alcohol_b;
      } 
    }
    else if(_type == 9)
    {
      if(_nameLectureRequeired == "LPG")
      {
        _nameLectureRequeired = "LPG";
        _a = MQ9_LPG_m;
        _b = MQ9_LPG_b;
      }
      else if(_nameLectureRequeired == "CH4")
      {
        _nameLectureRequeired = "CH4";
        _a = MQ9_CH4_m;
        _b = MQ9_CH4_b;
      }
      else if(_nameLectureRequeired == "CO")
      {
        _nameLectureRequeired = "CO";
        _a = MQ9_CO_m;
        _b = MQ9_CO_b;
      }    
    }
    else if(_type == 131)
    {
      if(_nameLectureRequeired == "NOx")
      {
        _nameLectureRequeired = "NOx";
        _a = MQ131_NOx_m;
        _b = MQ131_NOx_b;
      }
      else if(_nameLectureRequeired == "CL2")
      {
        _nameLectureRequeired = "CL2";
        _a = MQ131_CL2_m;
        _b = MQ131_CL2_b;
      }
      else if(_nameLectureRequeired == "O3")
      {
        _nameLectureRequeired = "O3";
        _a = MQ131_O3_m;
        _b = MQ131_O3_b;
      }    
    }
    else if(_type == 135)
    {
      if(_nameLectureRequeired == "CO")
      {
        _nameLectureRequeired = "CO";
        _a = MQ135_CO_m;
        _b = MQ135_CO_b;
      }
      else if(_nameLectureRequeired == "Alcohol")
      {
        _nameLectureRequeired = "Alcohol";
        _a = MQ135_Alcohol_m;
        _b = MQ135_Alcohol_b;
      }
      else if(_nameLectureRequeired == "CO2")
      {
        _nameLectureRequeired = "CO2";
        _a = MQ135_CO2_m;
        _b = MQ135_CO2_b;
      } 
      else if(_nameLectureRequeired == "Tolueno")
      {
        _nameLectureRequeired = "Tolueno";
        _a = MQ135_Tolueno_m;
        _b = MQ135_Tolueno_b;
      }
      else if(_nameLectureRequeired == "NH4")
      {
        _nameLectureRequeired = "NH4";
        _a = MQ135_NH4_m;
        _b = MQ135_NH4_b;
      }
      else if(_nameLectureRequeired == "Acetona")
      {
        _nameLectureRequeired = "Acetona";
        _a = MQ135_Acetona_m;
        _b = MQ135_Acetona_b;
      } 
    }
    else if(_type == 303)
    {
      if(_nameLectureRequeired == "Iso_butano")
      {
        _nameLectureRequeired = "Iso_butano";
        _a = MQ303_Iso_butano_m;
        _b = MQ303_Iso_butano_b;
      }
      else if(_nameLectureRequeired == "Hydrogeno")
      {
        _nameLectureRequeired = "Hydrogeno";
        _a = MQ303_Hydrogeno_m;
        _b = MQ303_Hydrogeno_b;
      }
      else if(_nameLectureRequeired == "Ethanol")
      {
        _nameLectureRequeired = "Ethanol";
        _a = MQ303_Ethanol_m;
        _b = MQ303_Ethanol_b;
      } 
    }
    else if(_type == 309)
    {      
      if(_nameLectureRequeired == "H2")
      {
        _nameLectureRequeired = "H2";
        _a = MQ309_H2_m;
        _b = MQ309_H2_b;
      } 
      else if(_nameLectureRequeired == "CH4")
      {
        _nameLectureRequeired = "CH4";
        _a = MQ309_CH4_m;
        _b = MQ309_CH4_b;
      }
      else if(_nameLectureRequeired == "CO")
      {
        _nameLectureRequeired = "CO";
        _a = MQ309_CO_m;
        _b = MQ309_CO_b;
      }    
      else if(_nameLectureRequeired == "Alcohol")
      {
        _nameLectureRequeired = "Alcohol";
        _a = MQ309_Alcohol_m;
        _b = MQ309_Alcohol_b;
      } 
    }
  //Serial debugging
}
long MQUnifiedsensor::calibrate(boolean print) {
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
  R0 = RS_air/_ratioInCleanAir; //Calculate R0 
  if(print)
  {
    Serial.println("*******Calibrating*********");
    Serial.println("* Sensor: MQ-" + String(_type) + "*");
    Serial.println("* Vcc: " + String(_VOLT_RESOLUTION) + "*");
    Serial.println("* _sensor_volt: " + String(_sensor_volt) + "*");
    Serial.println("* _RLValue: " + String(_RLValue) + "*");
    Serial.println("* _ratioInCleanAir: " + String(_ratioInCleanAir) + "*");
    Serial.println("* R0: " + String(R0) + "*");
    Serial.println("*******Calibrating*********");
  }
  return R0;
}
double MQUnifiedsensor::getVoltage(int read) {
  double voltage = 0;
  if(read)
  {
    double avg = 0.0;
    for (int i = 0; i < retries; i ++) {
      avg += analogRead(this->_pin);
      delay(retry_interval);
    }
    voltage = (avg/ retries) * _VOLT_RESOLUTION / (pow(2, ADC_RESOLUTION) - 1);
  }
  return voltage;
}


void MQUnifiedsensor::setR0(double R0) {
  this->_R0 = R0;
}

double MQUnifiedsensor::getR0() {
  return _R0;
}
void MQUnifiedsensor::setDefaultGas()
{
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
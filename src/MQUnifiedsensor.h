#ifndef MQUnifiedsensor_H
  #define MQUnifiedsensor_H

#include <Arduino.h>
#include <stdint.h>

/***********************Software Related Macros************************************/

#define ADC_RESOLUTION 10 // for 10bit analog to digital converter.
#define retries 5
#define retry_interval 20

class MQUnifiedsensor
{
  public:
    MQUnifiedsensor(int pin, int type);
    
    //Functions to set values
    void inicializar();
    void update();
    void setR0(double R0 = 10);
    void setRL(double RL = 10);
    void setVoltResolution(float voltaje = 5);
    void setSensorCharacteristics(String nameLectureReqeuired = "", bool print = false);
    void setDefaultGas();
    
    //user functions
    float calibrate(boolean print = false);
    float readSensor(String nameLectureRequeired = "", bool print = false);
    
    //get function for info
    double getR0();
    double getRL();
    double getVoltage(int read = true);
    double stringToDouble(String & str);
    String getnameLecture();

    

  private:
    /************************Private vars************************************/
    byte _pin, _type, _lecturePosInArray; 
    byte _VOLT_RESOLUTION  = 5.0; // if 3.3v use 3.3
    byte _ratioInCleanAir, _sensor_volt;
    byte _RLValue = 10; //Value in KiloOhms
    float  _R0, RS_air, _ratio, _PPM, _RS_Calc;  
    float _b;
    double _a;    
    String  _nameLectureRequeired; 
};

#endif //MQUnifiedsensor_H

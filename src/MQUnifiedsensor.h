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
    MQUnifiedsensor(String Placa = "Arduino", int Voltage_Resolution =  5, int pin, String type);
    
    //Functions to set values
    void init();
    void update();
    void setR0(double R0 = 10);
    void setRL(double RL = 10);
    void setVoltResolution(double voltage_resolution =  5);
    void serialDebug(boolean onSetup = false); //Show on serial port information about sensor
    
    //user functions
    float calibrate(boolean print = false);
    float readSensor(<String regressionMethod = "Exponential", float _a, float _b);
    
    //get function for info
    double getR0();
    double getRL();
    double getVoltage(int read = true);
    
    double stringToDouble(String & str);    

  private:
    /************************Private vars************************************/
    byte _pin;
    byte _firstFlag = false;
    String _type;
    String _placa; 
    byte _VOLT_RESOLUTION  = 5.0; // if 3.3v use 3.3
    byte _ratioInCleanAir, _sensor_volt;
    byte _RLValue = 10; //Value in KiloOhms
    double _adc;
    float  _R0, RS_air, _ratio, _PPM, _RS_Calc;  
};

#endif //MQUnifiedsensor_H

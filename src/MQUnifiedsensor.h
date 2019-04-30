#ifndef MQUnifiedsensor_H
#define MQUnifiedsensor_H

#include <Arduino.h>

class MQUnifiedsensor
{
  public:
    /**
     * Constructor
     */
    MQSensor(int pin);
    setR0(double R0);
    setSensorTyp(int sensorNumber);
    /**
     * Returns the PPM concentration    
    MQ-2 - Methane, Butane, LPG, smoke
    MQ-3 - Alcohol, Ethanol, smoke
    MQ-4 - Methane, CNG Gas
    MQ-5 - Natural gas, LPG
    MQ-6 - LPG, butane gas
    MQ-7 - Carbon Monoxide
    MQ-8 - Hydrogen Gas
    MQ-9 - Carbon Monoxide, flammable gasses
    MQ131 - Ozone
    MQ135 - Air Quality (CO, Ammonia, Benzene, Alcohol, smoke)
    MQ136 - Hydrogen Sulfide gas
    MQ137 - Ammonia
    MQ138 - Benzene, Toluene, Alcohol, Acetone, Propane, Formaldehyde gas, Hydrogen
    */

    int readMethane();
    int readButane();
    int readLPG();
    int readSmoke();
    int readAlcohol();
    int readEthanol();
    int readCNG();
    int readLPG();
    int readCO();
    int readHO();
    int readCarbonMonoxide();
    int readNH4();
    int readbenzene();
    int readAlcohol();
    int readHidrogen();
    int readToluene();
    int readAcetone();
    int readPropane();
    int readCoalGas();


    /**
     * Calibrates the start point of 400
     */    
    double calibrate();

    /**
     * Returns the voltage
     */
    double getVoltage();
    
  private:
    int _pin;
    double _R0;
};

#endif //MQUnifiedsensor_H
#ifndef MQUnifiedsensor_H
  #define MQUnifiedsensor_H

#include <Arduino.h>
#include <stdint.h>

class MQUnifiedsensor
{
  public:
    /**
     * Constructor
     */
    void MQSensor(int pin, int type);
    void setR0(double R0);
    void setSensorCharacteristics(int MQ[38], String nameLectureReqeuired);
    
    int readSensor(String nameLectureReqeuired = "");
    int readPPM(int m, int b);

    /**
     * Calibrates the start point of 400
    */    
    double calibrate();

    /**
     * Returns the voltage
     */
    double getVoltage();
    

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
    MQ303A - Isobutano
    MQ309A - Monoxide
    */
    
    /* Index definitions and header names*/
    int lecturesAvailable = 19;
    String nameLecture[lecturesAvailable] = {"H2","LPG","CH4","CO","Alcohol","Propane","Benzine","Hexane","Smoke","Nox","CL2","O3","CO2","Tolueno","NH4","Acetona","Iso-butano","Hydrogeno","Ethanol"};
    int indexSlopeLectures[lecturesAvailable] ={0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36};
    int indexBPointLectures[lecturesAvailable] ={1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37};
    const int defaultMQ2 = 4; // LPG
    const int defaultMQ3 = 10 // Alcohol
    const int defaultMQ4 = 6; // CH4
    const int defaultMQ5 = 0; //H2 
    const int defaultMQ6 = 6; // CH4
    const int defaultMQ7 = 8; //CO
    const int defaultMQ8 = 0; //H2 
    const int defaultMQ9 = 4; // LPG
    const int defaultMQ131 = 24; //O3
    const int defaultMQ135 = 30; //NH4
    const int defaultMQ303 = 34; //Isobutano
    const int defaultMQ309 = 8; //CO

    /* Value of m (Slope) and b (Cut on x axis) points */
    int MQ2[38] = {-2.2459,2.9845,-2.2879,2.7901,-2.6208,3.6075,-3.1157,4.5134,-2.7028,3.5595,-2.2879,2.7901,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int MQ3[38] = {0,0,-3.1851,4.7048,-17.531,28.785,-4.339,6.4432,-1.435,0.4103,0,0,-2.7009,0.632,-2.7268,3.6299,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int MQ4[38] = {0,0,-2.5818,3.6303,0.9873,2.6386,-5.5945,5.6693,-11.89,9.0375,0,0,0,0,0,0,-11.189,9.0375,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int MQ5[38] = {-4.368,2.9667,-2.5723,1.8943,-2.4438,2.3044,-4.8188,5.2023,-4.419,4.8044,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int MQ6[38] = {-3.6775,5.0286,-1.6567,2.8775,-1,3.301,-12.791,14.523,-5.8057,7.5292,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int MQ7[38] = {-1.329,1.8864,-7.8626,9.1056,-5.4878,8.8387,-1.4065,2.0162,-6.3219,9.924,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int MQ8[38] = {-0.7152,2.9891,-3.419,7.3513,-7.5609,15.243,-7.0753,15.396,-1.7459,4.7575,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int MQ9[38] = {0,0,-2.2535,2.9855,-1.6012,3.1476,-1.749,2.827,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int MQ131[38] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-2.7245,3.3004,-1.0333,1.7117,-1.2037,1.6455,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int MQ135[38] = {0,0,0,0,0,0,-2.7268,2.301,-2.8608,1.8627,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-3.2819,1.9903,-5.7015,1.1612,-2.2119,2.0473,-5.9682,1.0175,0,0,0,0,0,0};
    int MQ303A[38] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-2.3543,1.144,-2.4338,0.7558,-2.5597,0.4436};
    int MQ309A[38] = {-2.1311,3.0886,0,0,-1.6554,2.985,-4.7623,6.7413,-3.7686,5.6744,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


  private:
    int _pin, _type, _MQ[38];
    double _R0, _m, _b;
    const float VOLT_RESOLUTION = 5.0; // if 3.3v use 3.3
    const int ADC_RESOLUTION = 10; // for 10bit analog to digital converter.
    const int retries = 50;
    const int retry_interval = 20;
};

#endif //MQUnifiedsensor_H
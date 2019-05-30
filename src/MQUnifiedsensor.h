#ifndef MQUnifiedsensor_H
  #define MQUnifiedsensor_H

#include <Arduino.h>
#include <stdint.h>


//Count of posible lectures
#define lecturesAvailable 19

/************************Global vars************************************/
int VOLT_RESOLUTION  = 5.0; // if 3.3v use 3.3
int RLValue = 10; //Value in KiloOhms
int  _ratioInCleanAir, _PPM;
double RS_air,_R0, _m, _b, _ratio;

/************************Hardware Related Macros************************************/

//Index in the nameLecture vector
#define defaultMQ2 "LPG" // LPG
#define defaultMQ3 "Alcohol" // Alcohol
#define defaultMQ4 "CH4" // CH4
#define defaultMQ5 "H2" //H2 
#define defaultMQ6 "CH4" // CH4
#define defaultMQ7 "CO" //CO
#define defaultMQ8 "H2" //H2 
#define defaultMQ9 "LPG" // LPG
#define defaultMQ131 "O3" //O3
#define defaultMQ135 "NH4" //NH4
#define defaultMQ303 "Isobutano" //Isobutano
#define defaultMQ309 "CO" //CO

/*****************************Globals***********************************************/
#define RatioMQ2CleanAir 1
#define RatioMQ3CleanAir 2
#define RatioMQ4CleanAir 3
#define RatioMQ5CleanAir 4
#define RatioMQ6CleanAir 5
#define RatioMQ7CleanAir 6
#define RatioMQ8CleanAir 7
#define RatioMQ9CleanAir 8
#define RatioMQ131CleanAir 9
#define RatioMQ135CleanAir 131
#define RatioMQ303CleanAir 135
#define RatioMQ309CleanAir 303

/***********************Software Related Macros************************************/

#define ADC_RESOLUTION 10 // for 10bit analog to digital converter.
#define retries 50
#define retry_interval 20

/**********************Application Related Macros**********************************/
/* Gas, Value of m (Slope) and b (Cut on x axis) points */
//Values consolidated
const String PROGMEM _MQ2[18] = {"H2","-2.2459","2.9845","LPG","-2.2879","2.7901","CO","-2.6208","3.6075","Alcohol","-3.1157","4.5134","Propane","-2.7028","3.5595","Benzene","-2.2879","2.7901"};
const String PROGMEM _MQ3[18] = {"LPG","-3.1851","4.7048","CH4","-17.531","28.785","CO","-4.339","6.4432","Alcohol","-1.435","0.4103","Benzene","-2.7009","0.632","Hexane","-2.7268","3.6299"};
const String PROGMEM _MQ4[15] = {"LPG","-2.5818","3.6303","CH4","0.9873","2.6386","CO","-5.5945","5.6693","Alcohol","-11.89","9.0375","smoke","-11.189","9.0375"};
const String PROGMEM _MQ5[15] = {"H2","-4.368","2.9667","LPG","-2.5723","1.8943","CH4","-2.4438","2.3044","CO","-4.8188","5.2023","Alcohol","-4.419","4.8044"};
const String PROGMEM _MQ6[15] = {"H2","-3.6775","5.0286","LPG","-1.6567","2.8775","CH4","-1","3.301","CO","-12.791","14.523","Alcohol","-5.8057","7.5292"};
const String PROGMEM _MQ7[15] = {"H2","-1.329","1.8864","LPG","-7.8626","9.1056","CH4","-5.4878","8.8387","CO","-1.4065","2.0162","Alcohol","-6.3219","9.924"};
const String PROGMEM _MQ8[15] = {"H2","-0.7152","2.9891","LPG","-3.419","7.3513","CH4","-7.5609","15.243","CO","-7.0753","15.396","Alcohol","-1.7459","4.7575"};
const String PROGMEM _MQ9[9] = {"LPG","-2.2535","2.9855","CH4","-1.6012","3.1476","CO","-1.749","2.827"};
const String PROGMEM _MQ131[9] = {"Nox","-2.7245","3.3004","CL2","-1.0333","1.7117","O3","-1.2037","1.6455"};
const String PROGMEM _MQ135[18] = {"CO","-2.7268","2.301","Alcohol","-2.8608","1.8627","CO2","-3.2819","1.9903","Tolueno","-5.7015","1.1612","NH4","-2.2119","2.0473","Acetona","-5.9682","1.0175"};
const String PROGMEM _MQ303A[9] = {"Iso-butano","-2.3543","1.144","Hydrogeno","-2.4338","0.7558","Ethanol","-2.5597","0.4436"};
const String PROGMEM _MQ309A[12] = {"H2","-2.1311","3.0886","CH4","-1.6554","2.985","CO","-4.7623","6.7413","Alcohol","-3.7686","5.6744"};

class MQUnifiedsensor
{
  public:
    MQUnifiedsensor(int pin, int type);
    void inicializar();
    void setR0(double R0);
    void setVoltResolution(float voltaje);
    void setSensorCharacteristics(String nameLectureReqeuired, bool print);
    void setDefaultGas();
    void setRatioInCleanAir();
    
    int readSensor(String nameLectureRequeired = "", bool print = false);
    int readPPM(int m, int b);
    
    double calibrate();
    double getVoltage();
    double stringToDouble(String & str);

    String getnameLecture();

    

  private:
    int _pin, _type; 
    String _MQ[19], _nameLectureRequeired;   
};

#endif //MQUnifiedsensor_H
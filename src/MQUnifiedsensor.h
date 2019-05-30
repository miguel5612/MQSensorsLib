#ifndef MQUnifiedsensor_H
  #define MQUnifiedsensor_H

#include <Arduino.h>
#include <stdint.h>


//Count of posible lectures
#define lecturesAvailable 19

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
//From the graph, we can see that the resistance ratio in fresh air is a constant:
#define RatioMQ2CleanAir 9.83 //RS / R0 = 9.83 ppm 
#define RatioMQ3CleanAir 60   //RS / R0 = 9.83 ppm 
#define RatioMQ4CleanAir 4.4  //RS / R0 = 4.4 ppm 
#define RatioMQ5CleanAir 6.5  //RS / R0 = 6.5 ppm 
#define RatioMQ6CleanAir 10   //RS / R0 = 10 ppm 
#define RatioMQ7CleanAir 11.6 //RS / R0 = 11.6 ppm  
#define RatioMQ8CleanAir 70   //RS / R0 = 70 ppm   
#define RatioMQ9CleanAir 9.6  //RS / R0 = 9.6 ppm    
#define RatioMQ131CleanAir 11 //RS / R0 = 11 ppm
#define RatioMQ135CleanAir 3.6//RS / R0 = 3.6 ppm     
#define RatioMQ303CleanAir 1  //RS / R0 = 1 ppm    
#define RatioMQ309CleanAir 11 //RS / R0 = 11 ppm    

//From the calibration program we can obtain the R0 value for each sensor
#define R0_MQ2 1 //R0 after 48 hours pre-heating the sensor
#define R0_MQ3 1   //R0 after 48 hours pre-heating the sensor
#define R0_MQ4 1  //R0 after 48 hours pre-heating the sensor
#define R0_MQ5 1  //R0 after 48 hours pre-heating the sensor
#define R0_MQ6 1   //R0 after 48 hours pre-heating the sensor
#define R0_MQ7 1 //R0 after 48 hours pre-heating the sensor
#define R0_MQ8 1   //R0 after 48 hours pre-heating the sensor
#define R0_MQ9 1  //R0 after 48 hours pre-heating the sensor
#define R0_MQ131  1 //R0 after 48 hours pre-heating the sensor
#define R0_MQ135  1//R0 after 48 hours pre-heating the sensor
#define R0_MQ303  1  //R0 after 48 hours pre-heating the sensor
#define R0_MQ309  1 //R0 after 48 hours pre-heating the sensor

/***********************Software Related Macros************************************/

#define ADC_RESOLUTION 10 // for 10bit analog to digital converter.
#define retries 50
#define retry_interval 20

/**********************Application Related Macros**********************************/
/* Gas, Value of m (Slope) and b (Cut on x axis) points */
//Values consolidated
/********************** MQ2 ******************************************************/
#define MQ2_H2_m -2.2459
#define MQ2_H2_b 2.9845
 
#define MQ2_LPG_m -2.2879
#define MQ2_LPG_b 2.7901

#define MQ2_CO_m -2.6208
#define MQ2_CO_b 3.6075

#define MQ2_Alcohol_m -3.1157
#define MQ2_Alcohol_b 4.5134

#define MQ2_Propane_m -2.7028
#define MQ2_Propane_b 3.5595

#define MQ2_Benzene_m -2.2879
#define MQ2_Benzene_b 2.7901
/********************** MQ3 ******************************************************/

#define MQ3_LPG_m -3.1851
#define MQ3_LPG_b 4.7048

#define MQ3_CH4_m -17.531
#define MQ3_CH4_b 28.785

#define MQ3_CO_m -4.339
#define MQ3_CO_b 6.4432

#define MQ3_Alcohol_m -1.435
#define MQ3_Alcohol_b 0.4103

#define MQ3_Benzene_m -2.7009
#define MQ3_Benzene_b 0.632

#define MQ3_Hexane_m -2.7268
#define MQ3_Hexane_b 3.6299
/********************** MQ4 ******************************************************/

#define MQ4_LPG_m -2.5818
#define MQ4_LPG_b 3.6303

#define MQ4_CH4_m 0.9873
#define MQ4_CH4_b 2.6386

#define MQ4_CO_m -5.5945
#define MQ4_CO_b 5.6693

#define MQ4_Alcohol_m -11.89
#define MQ4_Alcohol_b 9.0375

#define MQ4_smoke_m -11.189
#define MQ4_smoke_b 9.0375
/********************** MQ5 ******************************************************/

#define MQ5_H2_m -4.368
#define MQ5_H2_b 2.9667

#define MQ5_LPG_m -2.5723
#define MQ5_LPG_b 1.8943

#define MQ5_CH4_m -2.4438
#define MQ5_CH4_b 2.3044

#define MQ5_CO_m -4.8188
#define MQ5_CO_b 5.2023

#define MQ5_Alcohol_m -4.419
#define MQ5_Alcohol_b 4.8044
/********************** MQ6 ******************************************************/

#define MQ6_H2_m -3.6775
#define MQ6_H2_b 5.0286

#define MQ6_LPG_m -1.6567
#define MQ6_LPG_b 2.8775

#define MQ6_CH4_m -1
#define MQ6_CH4_b 3.301

#define MQ6_CO_m -12.791
#define MQ6_CO_b 14.523

#define MQ6_Alcohol_m -5.8057
#define MQ6_Alcohol_b 7.5292
/********************** MQ7 ******************************************************/

#define MQ7_H2_m -1.329
#define MQ7_H2_b 1.8864

#define MQ7_LPG_m -7.8626
#define MQ7_LPG_b 9.1056

#define MQ7_CH4_m -5.4878
#define MQ7_CH4_b 8.8387

#define MQ7_CO_m -1.4065
#define MQ7_CO_b 2.0162

#define MQ7_Alcohol_m -6.3219
#define MQ7_Alcohol_b 9.924

/********************** MQ8 ******************************************************/

#define MQ8_H2_m -0.7152
#define MQ8_H2_b 2.9891

#define MQ8_LPG_m -3.419
#define MQ8_LPG_b 7.3513

#define MQ8_CH4_m -7.5609
#define MQ8_CH4_b 15.243

#define MQ8_CO_m -7.0753
#define MQ8_CO_b 15.396

#define MQ8_Alcohol_m -1.7459
#define MQ8_Alcohol_b 4.7575

/********************** MQ9 ******************************************************/

#define MQ9_LPG_m -2.2535
#define MQ9_LPG_b 2.9855

#define MQ9_CH4_m -1.6012
#define MQ9_CH4_b 3.1476

#define MQ9_CO_m -1.749
#define MQ9_CO_b 2.827

/********************** MQ131 ******************************************************/

#define MQ131_NOx_m -2.7245
#define MQ131_NOx_b 3.3004

#define MQ131_CL2_m -1.0333
#define MQ131_CL2_b 1.7117

#define MQ131_O3_m -1.2037
#define MQ131_O3_b 1.6455

/********************** MQ135 ******************************************************/

#define MQ135_CO_m -2.7268
#define MQ135_CO_b 2.301

#define MQ135_Alcohol_m -2.8608
#define MQ135_Alcohol_b 1.8627

#define MQ135_CO2_m -3.2819
#define MQ135_CO2_b 1.9903

#define MQ135_Tolueno_m -5.7015
#define MQ135_Tolueno_b 1.1612

#define MQ135_NH4_m -2.2119
#define MQ135_NH4_b 2.0473

#define MQ135_Acetona_m -5.9682
#define MQ135_Acetona_b 1.0175

/********************** MQ303 ******************************************************/

#define MQ303_Iso_butano_m -2.3543
#define MQ303_Iso_butano_b 1.144

#define MQ303_Hydrogeno_m -2.4338
#define MQ303_Hydrogeno_b 0.7558

#define MQ303_Ethanol_m -2.5597
#define MQ303_Ethanol_b 0.4436

/********************** MQ309 ******************************************************/

#define MQ309_H2_m -2.1311
#define MQ309_H2_b 3.0886

#define MQ309_CH4_m -1.6554
#define MQ309_CH4_b 2.985

#define MQ309_CO_m -4.7623
#define MQ309_CO_b 6.7413

#define MQ309_Alcohol_m -3.7686
#define MQ309_Alcohol_b 5.6744

/*
const String _MQ2[18] = {"H2","-2.2459","2.9845","LPG","-2.2879","2.7901","CO","-2.6208","3.6075","Alcohol","-3.1157","4.5134","Propane","-2.7028","3.5595","Benzene","-2.2879","2.7901"};
const String _MQ3[18] = {"LPG","-3.1851","4.7048","CH4","-17.531","28.785","CO","-4.339","6.4432","Alcohol","-1.435","0.4103","Benzene","-2.7009","0.632","Hexane","-2.7268","3.6299"};
const String _MQ4[15] = {"LPG","-2.5818","3.6303","CH4","0.9873","2.6386","CO","-5.5945","5.6693","Alcohol","-11.89","9.0375","smoke","-11.189","9.0375"};
const String _MQ5[15] = {"H2","-4.368","2.9667","LPG","-2.5723","1.8943","CH4","-2.4438","2.3044","CO","-4.8188","5.2023","Alcohol","-4.419","4.8044"};
const String _MQ6[15] = {"H2","-3.6775","5.0286","LPG","-1.6567","2.8775","CH4","-1","3.301","CO","-12.791","14.523","Alcohol","-5.8057","7.5292"};
const String _MQ7[15] = {"H2","-1.329","1.8864","LPG","-7.8626","9.1056","CH4","-5.4878","8.8387","CO","-1.4065","2.0162","Alcohol","-6.3219","9.924"};
const String _MQ8[15] = {"H2","-0.7152","2.9891","LPG","-3.419","7.3513","CH4","-7.5609","15.243","CO","-7.0753","15.396","Alcohol","-1.7459","4.7575"};
const String _MQ9[9] = {"LPG","-2.2535","2.9855","CH4","-1.6012","3.1476","CO","-1.749","2.827"};
const String _MQ131[9] = {"Nox","-2.7245","3.3004","CL2","-1.0333","1.7117","O3","-1.2037","1.6455"};
const String _MQ135[18] = {"CO","-2.7268","2.301","Alcohol","-2.8608","1.8627","CO2","-3.2819","1.9903","Tolueno","-5.7015","1.1612","NH4","-2.2119","2.0473","Acetona","-5.9682","1.0175"};
const String _MQ303A[9] = {"Iso-butano","-2.3543","1.144","Hydrogeno","-2.4338","0.7558","Ethanol","-2.5597","0.4436"};
const String _MQ309A[12] = {"H2","-2.1311","3.0886","CH4","-1.6554","2.985","CO","-4.7623","6.7413","Alcohol","-3.7686","5.6744"};
*/

class MQUnifiedsensor
{
  public:
    MQUnifiedsensor(int pin, int type);
    void inicializar();
    void setR0(double R0);
    void setVoltResolution(float voltaje);
    void setSensorCharacteristics(String nameLectureReqeuired, bool print);
    void setDefaultGas();
    
    int readSensor(String nameLectureRequeired = "", bool print = false);
    int readPPM(int m, int b);
    
    int calibrate(boolean print = false);
    double getVoltage();
    double stringToDouble(String & str);

    String getnameLecture();

    

  private:
    /************************Private vars************************************/
    int _pin, _type, _R0, _lecturePosInArray; 
    String  _nameLectureRequeired;   
    int _VOLT_RESOLUTION  = 5.0; // if 3.3v use 3.3
    int _RLValue = 10; //Value in KiloOhms
    int  _ratioInCleanAir, _PPM, _sensor_volt;
    float RS_air, _m, _b, _ratio;
    
};

#endif //MQUnifiedsensor_H
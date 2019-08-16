#ifndef MQUnifiedsensor_H
  #define MQUnifiedsensor_H

#include <Arduino.h>
#include <stdint.h>


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
#define RatioMQ3CleanAir 60   //RS / R0 = 60 ppm 
#define RatioMQ4CleanAir 4.4  //RS / R0 = 4.4 ppm 
#define RatioMQ5CleanAir 6.5  //RS / R0 = 6.5 ppm 
#define RatioMQ6CleanAir 10   //RS / R0 = 10 ppm 
#define RatioMQ7CleanAir 27.5 //RS / R0 = 27.5 ppm  
#define RatioMQ8CleanAir 70   //RS / R0 = 70 ppm   
#define RatioMQ9CleanAir 9.6  //RS / R0 = 9.6 ppm    
#define RatioMQ131CleanAir 15 //RS / R0 = 15 ppm
#define RatioMQ135CleanAir 3.6//RS / R0 = 3.6 ppm     
#define RatioMQ303CleanAir 1  //RS / R0 = 1 ppm    
#define RatioMQ309CleanAir 11 //RS / R0 = 11 ppm    


//From the calibration program we can obtain the R0 value for each sensor
#define R0_MQ2 9.659574468 //R0 after 48 hours pre-heating the sensor
#define R0_MQ3 3.86018237   //R0 after 48 hours pre-heating the sensor
#define R0_MQ4 47.775076  //R0 after 48 hours pre-heating the sensor
#define R0_MQ5 71.100304  //R0 after 48 hours pre-heating the sensor
#define R0_MQ6 13.4285714   //R0 after 48 hours pre-heating the sensor
#define R0_MQ7 4 //R0 after 48 hours pre-heating the sensor
#define R0_MQ8 1   //R0 after 48 hours pre-heating the sensor
#define R0_MQ9 9.42857143  //R0 after 48 hours pre-heating the sensor
#define R0_MQ131  385.40 //R0 after 48 hours pre-heating the sensor Thanks ostaquet HIGH_CONCENTRATION
#define R0_MQ135  76.63 //R0 after 48 hours pre-heating the sensor  Thanks Georgk https://github.com/GeorgK/MQ135/blob/master/MQ135.h
#define R0_MQ303  10  //R0 after 48 hours pre-heating the sensor
#define R0_MQ309  10 //R0 after 48 hours pre-heating the sensor

/***********************Software Related Macros************************************/

#define ADC_RESOLUTION 10 // for 10bit analog to digital converter.
#define retries 5
#define retry_interval 20

/**********************Application Related Macros**********************************/
/* Gas, Value of a and b points */
//Values consolidated 
//Equation PPM = a*((x)^b)
/********************** MQ2 ******************************************************/
#define MQ2_H2_a 987.99
#define MQ2_H2_b -2.162
 
#define MQ2_LPG_a 574.25
#define MQ2_LPG_b -2.222

#define MQ2_CO_a 36974
#define MQ2_CO_b -3.109

#define MQ2_Alcohol_a 3616.1
#define MQ2_Alcohol_b -2.675

#define MQ2_Propane_a 658.71
#define MQ2_Propane_b -2.168


/********************** MQ3 ******************************************************/

#define MQ3_LPG_a 44771
#define MQ3_LPG_b -3.245

#define MQ3_CH4_a 2*10^31
#define MQ3_CH4_b 19.01

#define MQ3_CO_a 521853
#define MQ3_CO_b -3.821

#define MQ3_Alcohol_a 0.3934
#define MQ3_Alcohol_b -1.504

#define MQ3_Benzene_a 4.8387
#define MQ3_Benzene_b -2.68

#define MQ3_Hexane_a 7585.3
#define MQ3_Hexane_b -2.849
/********************** MQ4 ******************************************************/

#define MQ4_LPG_a 3811.9
#define MQ4_LPG_b -3.113

#define MQ4_CH4_a 1012.7
#define MQ4_CH4_b -2.786

#define MQ4_CO_a 200000000000000
#define MQ4_CO_b -19.05

#define MQ4_Alcohol_a 60000000000
#define MQ4_Alcohol_b -14.01

#define MQ4_smoke_a 30000000
#define MQ4_smoke_b -8.308
/********************** MQ5 ******************************************************/

#define MQ5_H2_a 1163.8
#define MQ5_H2_b -3.874

#define MQ5_LPG_a 80.897
#define MQ5_LPG_b -2.431

#define MQ5_CH4_a 177.65
#define MQ5_CH4_b -2.56

#define MQ5_CO_a 491204
#define MQ5_CO_b -5.826

#define MQ5_Alcohol_a 97124
#define MQ5_Alcohol_b -4.918
/********************** MQ6 ******************************************************/

#define MQ6_H2_a 88158
#define MQ6_H2_b -3.597

#define MQ6_LPG_a 1009.2
#define MQ6_LPG_b -2.35

#define MQ6_CH4_a 2127.2
#define MQ6_CH4_b -2.526

#define MQ6_CO_a 1000000000000000
#define MQ6_CO_b -13.5

#define MQ6_Alcohol_a 50000000
#define MQ6_Alcohol_b -6.017
/********************** MQ7 ******************************************************/

#define MQ7_H2_a 69.014
#define MQ7_H2_b -1.374

#define MQ7_LPG_a 700000000
#define MQ7_LPG_b -7.703

#define MQ7_CH4_a 60000000000000
#define MQ7_CH4_b -10.54

#define MQ7_CO_a 99.042
#define MQ7_CO_b -1.518

#define MQ7_Alcohol_a 40000000000000000
#define MQ7_Alcohol_b -12.35

/********************** MQ8 ******************************************************/

#define MQ8_H2_a 976.97
#define MQ8_H2_b -0.688

#define MQ8_LPG_a 10000000
#define MQ8_LPG_b -3.123

#define MQ8_CH4_a 80000000000000
#define MQ8_CH4_b -6.666

#define MQ8_CO_a 2000000000000000000
#define MQ8_CO_b -8.074

#define MQ8_Alcohol_a 76101
#define MQ8_Alcohol_b -1.86

/********************** MQ9 ******************************************************/

#define MQ9_LPG_a 1000.5
#define MQ9_LPG_b -2.186

#define MQ9_CH4_a 4269.6
#define MQ9_CH4_b -2.648

#define MQ9_CO_a 599.65
#define MQ9_CO_b -2.244

/********************** MQ131 ******************************************************/

#define MQ131_NOx_a -462.43
#define MQ131_NOx_b -2.204

#define MQ131_CL2_a 47.209
#define MQ131_CL2_b -1.186

#define MQ131_O3_a 23.943
#define MQ131_O3_b -1.11

/********************** MQ135 ******************************************************/

#define MQ135_CO_a 605.18
#define MQ135_CO_b -3.937

#define MQ135_Alcohol_a 77.255
#define MQ135_Alcohol_b -3.18

#define MQ135_CO2_a 110.47
#define MQ135_CO2_b -2.862

#define MQ135_Tolueno_a 44.947
#define MQ135_Tolueno_b -3.445

#define MQ135_NH4_a 102.2
#define MQ135_NH4_b -2.473

#define MQ135_Acetona_a 34.668
#define MQ135_Acetona_b -3.369

/********************** MQ303 ******************************************************/

#define MQ303_Iso_butano_a 6.2144
#define MQ303_Iso_butano_b -2.894

#define MQ303_Hydrogeno_a 4.1487
#define MQ303_Hydrogeno_b -2.716

#define MQ303_Ethanol_a 3.4916
#define MQ303_Ethanol_b -2.432

/********************** MQ309 ******************************************************/

#define MQ309_H2_a 1532.9
#define MQ309_H2_b -1.951

#define MQ309_CH4_a 980.24
#define MQ309_CH4_b -1.68

#define MQ309_CO_a 1000000
#define MQ309_CO_b -4.01

#define MQ309_Alcohol_a 473622
#define MQ309_Alcohol_b -3.647


class MQUnifiedsensor
{
  public:
    MQUnifiedsensor(int pin, int type);
    
    //Functions to set values
    void inicializar();
    void update();
    void setR0(double R0 = 10);
    void setVoltResolution(float voltaje = 5);
    void setSensorCharacteristics(String nameLectureReqeuired = "", bool print = false);
    void setDefaultGas();
    
    //user functions
    float calibrate(boolean print = false);
    float readSensor(String nameLectureRequeired = "", bool print = false);
    
    //get function for info
    double getR0();
    double getVoltage(int read = true);
    double stringToDouble(String & str);
    String getnameLecture();

    

  private:
    /************************Private vars************************************/
    int _pin, _type, _lecturePosInArray; 
    double  _R0;
    String  _nameLectureRequeired;   
    int _VOLT_RESOLUTION  = 5.0; // if 3.3v use 3.3
    int _RLValue = 10; //Value in KiloOhms
    float _PPM, _RS_Calc;
    float _ratioInCleanAir, _sensor_volt, RS_air, _a, _b, _ratio;
    
};

#endif //MQUnifiedsensor_H

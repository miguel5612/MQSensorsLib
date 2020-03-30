/*
  MQUnifiedsensor Library - reading an MQ3 using digital input

  Demonstrates the use a MQ3 sensor.
  Library originally added 01 may 2019
  by Miguel A Califa, Yersson Carrillo, Ghiordy Contreras, Mario Rodriguez
 
  Added example
  modified 23 May 2019
  by Miguel Califa 

  Updated library usage
  modified 26 March 2020
  by Miguel Califa 

 This example code is in the public domain.

 Instructions:
    1. Load the program contained in this example onto your card.
    2. Let the sensor preheat for 48 hours.
    3. Generate a contaminated atmosphere, to the point that it is the alert level, this can be done by enclosing the 
       sensor in a small pot and entering a chemical such as alcohol if it is the case in the form of a spray.
    4.  Move the potentiometer until the LED on the card lights up.
    5. Wait until the LED on the sensor card goes out.
    6. Each time the serial monitor displays an alert, the sensor has detected that the threshold programmed in step 4 has 
       been exceeded.

  Warning:
    For any reason you should not inhale the gases of the atmosphere generated to calibrate the sensor, 
    this calibration should be done in an open place and ventilate the space once the sensor is calibrated 
    and should always be done by at least two people, you should always know what to do in case of inhaling or
    coming into contact with the gases to which the sensor is being subjected.
    
    We as a team are not responsible for irresponsible handling of the information contained herein, before 
    following the instructions contained herein consult with a professional or a responsible teacher.
*/

#define pin 3 // Digital pin connected to your sensor

void setup() {
  //Init the serial port communication - to debug the library
  Serial.begin(9600); //Init serial port
  
  pinMode(pin, INPUT);

}

void loop() {
    if(digitalRead(pin))
    {
        Serial.println("Alarm high concentrations detected");
    }
    else
    {
        Serial.println("Status: Normal")
    }
}
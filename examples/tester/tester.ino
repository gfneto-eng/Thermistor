/*

To fill comments

*/
#include "thermistor.h"

Thermistor sensor1(A1,TEMP_SENSOR_1) ;

void setup() {
  Serial.begin(115200);// config serial port and start it
  delay(500); // wait by hardware initiate
  Serial.print("Starting..........\n"); // write at terminal

}

void loop() {
  float temperature = sensor1.readTemp(); //read temperature from sensor
  Serial.println("Temperature: "+ (String)temperature +" Celsius");//read and write at terminal
  delay(1000); //wait 1 second for next measure

}

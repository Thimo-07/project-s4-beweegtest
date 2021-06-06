/*
main code for the "balance beam" for the "beweegtest"
created on: may 18th
created by: Thimo Meeusen
last edited on: may 18th
last edited by: Thimo Meeusen                                   
*/
#include "Arduino.h"
#include "sensorread.hpp"
#include "mux.hpp"

sensor_read::sensor_read(){
  mux1 = new mux(mux1_s0_pin, mux1_s1_pin, mux1_s2_pin, mux1_s3_pin);
  mux2 = new mux(mux2_s0_pin, mux2_s1_pin, mux2_s2_pin, mux2_s3_pin);
  pinMode(mux1_signal_out, INPUT);
  pinMode(mux2_signal_out, INPUT);
}

void sensor_read::read_data(int sensordata[aantal_koperbanen]){
  for(int i=0; i<aantal_koperbanen; i++){
    if(i<16){
      mux1->select_pin(i);
      delay(5);
      sensordata[i] = analogRead(mux1_signal_out);
    }
    else{
      mux2->select_pin(i-16);
      delay(5);
      sensordata[i] = analogRead(mux2_signal_out);
    }
  }
}

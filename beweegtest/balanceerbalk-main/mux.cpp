/*
implementatian of multiplexer
created on: may 31
created by: Thimo Meeusen
last edited on: may 31
last edited by: Thimo Meeusen                                   
*/
#include "Arduino.h"
#include "mux.hpp"

mux::mux(int s0, int s1, int s2, int s3){
  select_pinout[0] = s0;
  select_pinout[1] = s1;
  select_pinout[2] = s2;
  select_pinout[3] = s3;
  for(int i=0; i < 4; i++){
    pinMode(select_pinout[i], OUTPUT);
    digitalWrite(select_pinout[i], LOW);
  }
}

void mux::select_pin(int pin_numb){
  bool select[4];
  int_to_bool_array(pin_numb, select);
  
  for(int i=0; i<4; i++){
    digitalWrite(select_pinout[i],select[i]);
  }
}

void mux::int_to_bool_array(int numb, bool output[4]){
  for(int i=0; i<4; i++){
    if(numb%2){
      output[i] = 1;
    }
    else{
      output[i] = 0;
    }
    numb=numb/2;
  }
}

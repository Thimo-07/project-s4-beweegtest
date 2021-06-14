/*
implementation code used to determene the scoring 
created on: may 18th
created by: Thimo Meeusen
last edited on: may 18th
last edited by: Thimo Meeusen                                        
*/

#include "balk_test.hpp"
#include "Arduino.h"

balk_test::balk_test(){
  sensor = new sensor_read;
  running = false;
  score = 0;
}

balk_test::~balk_test(){
  delete sensor;
}

int balk_test::start(){
  if(running == false){
    running = true;
    score = 0;
    for(int i=0; i < aantal_koperbanen; i++){
      old_bool_data[i] = 0;
    }
    return 0;
  }
  else{
    return -1;
  }
}

bool balk_test::run(){
  bool new_bool_data[aantal_koperbanen];
  if(running == true){
    int sensor_data[aantal_koperbanen];
    sensor->read_data(sensor_data);
    
    
    for(int i=0; i < aantal_koperbanen; i++){
      if(sensor_data[i] >= sensor_threshold){
        new_bool_data[i] = 1;
      }
      else{
        new_bool_data[i] = 0;
      }
      //Serial.print(i);
      //Serial.print(": ");
      //Serial.println(new_bool_data[i]);
    }
    
    if(user_started_test){
      bool stop_running = true;
      for(int i=0; i<aantal_koperbanen; i++){
        if(new_bool_data[i] == 1){
          //Serial.println("still running");
          stop_running = false;
        }

        if((i == (aantal_koperbanen-1)) && stop_running == true){
          Serial.println("stopped");
          running = false;
          return false;
        } 
      }

    for(int i=(aantal_koperbanen-1); i>=0; i--){
      if(old_bool_data[i] == 1){
          if( ((new_bool_data[i+1] == 1) && (new_bool_data[i+2] == 1)) || ((new_bool_data[i+2] == 1) && (new_bool_data[i+3] == 1)) || ((new_bool_data[i+1] == 1) && (new_bool_data[i+3] == 1)) )  
            score++;
            for(int i=0; i < aantal_koperbanen; i++){
              old_bool_data[i] = new_bool_data[i];
            }
            Serial.print("score:");
            Serial.println(score);
            if(score == 8){
              running = false;
              return false;
              }
            return true;
        }
      
      
      }
      
    }
    //if user_started_test
    //check if user is still on balk
    //check for next step
    else{
      if((new_bool_data[0] != old_bool_data[0]) || (new_bool_data[1] != old_bool_data[1]) ){
        user_started_test = 1;
        Serial.println("test started");
      }    
    }
    //else check if user has started
    for(int i=0; i < aantal_koperbanen; i++){
      old_bool_data[i] = new_bool_data[i];
    }
    return true;
  }
  else{
    return false;
  }
}

void balk_test::stop(){
  running = false;
}

int balk_test::get_score(){
  if(running == false){
    return score;
  }
  else{
    return -1;
  }
}

/*
implementation code used to determene the scoring 
created on: may 18th
created by: Thimo Meeusen
last edited on: may 18th
last edited by: Thimo Meeusen                                        
*/

#include "balk_test.hpp"

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
    return 0;
  }
  else{
    return -1;
  }
}

bool balk_test::run(){
  if(running == true){
    int sensor_data[aantal_koperbanen];
    sensor->read_data(sensor_data);
    //if user_started_test
    //check if user is on balk
    //check for next step
    //else check if user has started
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

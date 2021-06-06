/*
main code for the "balance beam" for the "beweegtest"
created on: may 18th
created by: Thimo Meeusen
last edited on: may 18th
last edited by: Thimo Meeusen                                   
*/

#ifndef balk_test_hpp
#define balk_test_hpp
#include "sensorread.hpp"

class balk_test{
  public:
  balk_test();
  ~balk_test();
  int start();
  bool run();
  void stop();
  int get_score();
  
  private:
  sensor_read *sensor;
  int score;
  bool running = false;
  bool user_started_test = false;
  
};

#endif //balk_test_hpp

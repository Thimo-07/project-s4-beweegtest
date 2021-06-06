/*
main code for the "balance beam" for the "beweegtest"
created on: may 18th
created by: Thimo Meeusen
last edited on: may 18th
last edited by: Thimo Meeusen                                   
*/

#ifndef sensorread_hpp
#define sensorread_hpp
#include "mux.hpp"
#include "config.hpp"

class sensor_read{
  public:
  void read_data(int sensordata[aantal_koperbanen]);
  sensor_read();
  
  private:
  mux *mux1;
  mux *mux2;
};

#endif // sensorread_hpp

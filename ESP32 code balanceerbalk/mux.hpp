/*
defenition of multiplexer
created on: may 31
created by: Thimo Meeusen
last edited on: may 31
last edited by: Thimo Meeusen                                   
*/

#ifndef mux_hpp
#define mux_hpp

class mux{
  public:
  mux(int s0, int s1, int s2, int s3);
  void select_pin(int pin_numb);
  
  private:
  void int_to_bool_array(int numb, bool output[4]);
  int select_pinout[4];
};

#endif

// file: .
//

// make sure definitions are only made once
//
#ifndef ISIP_EXAMPLE
#define ISIP_EXAMPLE

// system include files
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>





class circ_buffer{
public:
  circ_buffer(int bufferSize);
  ~circ_buffer();

  void display();
  void insert(int i);

  int get_ith_number(int i);
  void erase();
  
private:


  
  int buffSize;
  int* buffer;

  int index;


};







// end of include file
//
#endif


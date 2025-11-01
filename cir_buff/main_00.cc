// file:
//

// local include files
//
#include "example.h"

// function: mysum
//
// arguments:
//  float x: one operand
//  float y: another operand
//
// return:
//  a float value containing the sum of two numbers
//
// description:
//
//





circ_buffer::circ_buffer(int bufferSize){

  buffSize = bufferSize;
  
  buffer = new int[buffSize]; 

  index = 0;
}

circ_buffer::~circ_buffer() {

  delete []  buffer; 

}


void circ_buffer::insert(int i){
  
  buffer[index] = i;


  index = (index + 1) % buffSize;
  fprintf(stdout, "Index: %d\n", index);
}




int circ_buffer::get_ith_number(int i ){

  return buffer[(index + i) % buffSize];

}





void circ_buffer::display(){


  for(int i = 0; i < buffSize; i++){
    fprintf(stdout, "%d\n", buffer[i]);

  }
  fprintf(stdout, "\n\n");



}



void circ_buffer::erase(){

  for(int i = 0; i < buffSize; i++){
    buffer[i] = 0; 
  }

  fprintf(stdout, "Buffer Erased\n");
  fprintf(stdout, "Index:%d\n", index);
}

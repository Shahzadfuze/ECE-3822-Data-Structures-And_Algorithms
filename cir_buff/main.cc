// file: .
//

// local include files
//
#include "example.h"

// function: main
//
// Program Function: 
// 
//

int main(int argc, const char** argv) {


  circ_buffer fuze(8);
  fuze.insert(1);
  fuze.insert(2);
  fuze.insert(3);
  fuze.insert(4);
  fuze.insert(5);
  fuze.insert(6);
  fuze.insert(7);
  fuze.insert(8);
  fuze.insert(1000);


  
  fuze.display();
  //fuze.insert(100);
  

  
  int old = fuze.get_ith_number(5);

    
  fprintf(stdout, "i = %d\n",old );



  fuze.erase();

  fuze.display();

  

  
  // End Gracefully
  //
  return 0;	
}

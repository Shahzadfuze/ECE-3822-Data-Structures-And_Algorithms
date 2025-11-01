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


class linked_list{

private:
  struct Node{

    int data;
    Node* next; 

  };


public:

  Node* head; 

  linked_list();
  ~linked_list();
  
  void display();

  void insert(int num);


  void reverseList();


  void insertBeginning(int num);
  



};









// end of include file
//
#endif


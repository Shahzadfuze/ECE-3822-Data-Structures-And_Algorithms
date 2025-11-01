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



class binary_search_tree{


private:

  struct node{

    int value;
    node* left;
    node* right;    

    node(int v): value(v), left(nullptr), right(nullptr){}; 
    
  };

  node* insert(int x, node* currNode);

  void printInOrder(node* currNode);

  void printInReverse(node* currNode);

  node* root;

public:

  binary_search_tree(): root(nullptr) {};
  void insert(int x);

  void printInOrder(){}; 
  
  

    
  

};













// end of include file
//
#endif


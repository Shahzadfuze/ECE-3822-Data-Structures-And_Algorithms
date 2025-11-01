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


/* Defining a Construtor for our linked list that just delcares the head as a null
   ptr
*/

linked_list::linked_list(){
  head = nullptr;
};


/* Destructor basiclly loops through the linked list and deletes the current node well
   moving to the next one */
linked_list::~linked_list(){
  Node* current = head;

  while(current != nullptr){
    Node* next = current->next;
    delete current;
    current = next;
  }
  head = nullptr;
}


/* Loops through the list and printing every single value and then moving to the next */
void linked_list::display(){

  Node* current = head;

  while(current != nullptr){
    Node* next = current->next;

    fprintf(stdout, "%d\n", current->data);
    current = current->next;
  }
}


/* If we are starting at the beginning of the list basiclly making the head = to the node created
   If not, we loop through the list finding the end and placing the node there */


void linked_list::insert(int num){

  Node* current= new Node;

  if(head == nullptr) {
    head = current;
    head->data = num;
    head->next = nullptr;
    return;
  }

  else{
    Node* t = head;

    while(t->next != nullptr){
      t=t->next;
    }

    
    t->next = current;
    current->data = num;
    current->next = nullptr;
  }
}





#ifndef BOOKS_H
#define BOOKS_H

#include<string>
using namespace std;


class books{

private:
  // Defined the variables as private so no one else can touch them unless they ue the set
  //
  string title;
  string author;
  int year;
  int pages;
 
    // ADD VARIABLES HERE AS NEEDED


    public:

    // DON'T CHANGE THESE FUNCTION PROTOTYPES
    books(string="",string="",int=0,int=0);
    void set_title(string);
    void set_author(string);
    void set_year(int);
    void set_pages(int);
    double useless_fact();
    void static display_header();
    void display();

};

#endif 

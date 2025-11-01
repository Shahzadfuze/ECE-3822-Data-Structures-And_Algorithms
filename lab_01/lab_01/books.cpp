#include "books.h"
#include <cmath>

// Every function prototype is empty - fill it with whatever you think
// is appropriate

// Add a one or two-line comment for each function


// using the constructor to put the varaibles into memory. 
//
books::books(string n, string a, int y, int p){
  title = n;
  author = a;
  year = y;
  pages = p;




};


// Using the this-> to make sure the compiler knows we are talking about the variables inside the class
//
void books::set_title (string n){
  this->title = n;

}
// samke thing for almost every single variable
//
void books::set_author(string a){
  this->author = a;
}

void books::set_year(int y){
  this->year = y;

}

void books::set_pages(int p){
  this->pages = p;
}
// Just making it so it takes the sqrt of the year and the pages 
//
double books::useless_fact(){
  return sqrt(this->year*this->pages);


}

// do not edit
void books::display_header(){
    printf("\n");
    printf("%-30s", "Title"  );
    printf("%-15s", "Author" );
    printf("%-7s" , "Year"   );
    printf("%-7s" , "Pages"  );
    printf("%-12s", "Useless Fact"  );
    printf("\n");
}

// do not edit
void books::display(){
    printf("%-30s" , title.c_str()  );
    printf("%-15s" , author.c_str() );
    printf("%-7i"  , year  );
    printf("%-7i"  , pages );
    printf("%-12.2f"  , useless_fact() );

    printf("\n");
}


/*
  Shahzad khan
  3/2/025
  shahzad.khan@temple.edu

  


 */
#include<iostream>

#include<fstream>
#include "linked_list.h"
using namespace std;

#define DEFAULT_DIRECTORY "/data/courses/ece_3822/current/project_2/"
#define DEFAULT_FILENAME "dataFile1.txt"

// do not edit this function
string get_filename(int argc, char** argv){
    string filename = DEFAULT_DIRECTORY;
    
    // no command line inputs: use default
    if (argc == 1)
        filename += DEFAULT_FILENAME;

    // command line filename given
    else
        filename += (string) argv[1];
    
    return filename;
}

class linked_list_movies : public linked_list<int>{
    public:

    void display(){
      // WRITE CODE TO DISPLAY THE LIST OF MOVIES
      // Going through the linked list and printing out the data
      node* current = this->head;
     
      while(current != nullptr) {

	fprintf(stdout, "Movie Ids: %d\n", current->data);
	current = current->next;

      }


      
    }

  
  bool iterate(int movie_id){
    // This just returns true or false if the movie_id matches the data
    // of the linked list used to simplify another function 
    node* current = this->head;


    while(current != nullptr){
      if(current->data == movie_id) {
	return true;


      }

      current = current->next;

    }

    return false;
    
  }
  


  
};

class customer{
    public:

    int customer_id;
    linked_list_movies movie_ids;    

    void display(){
        // WRITE CODE TO DISPLAY THE CUSTOMER AND MOVIES
      // Simply just printing out the idea 
      fprintf(stdout, "Customer IDs: %d\n",  customer_id);
      movie_ids.display();
      
    }

};

// note this a linked list of POINTERS to customers...
// that way you only every make one copy of each customer
// and simply place a pointer to that customer in the linked list

class linked_list_customers : public linked_list<customer*>{

    public:





    void print_customer(int customer_id){
        // WRITE THIS FUNCTION
      // going through the linked list and and checking the id
      node* current = this->head;
      while(current) {
	// becuase it is a linked list of pointers we need to do this 
	if (current->data->customer_id ==  customer_id){
	
	  current->data->display();
	  return; 
	 
	}

	current = current->next;
      }

      fprintf(stdout, "Customer does Not exist\n");


      
    }

    void print_all(){
        // WRITE THIS FUNCTION
      
      node* current = this->head;
      // going through the linked list and printing everything 
      while(current){

	current->data->display();
	current = current->next;

      }
      
      

    }

    void print_views(int movie_id){
        // WRITE THIS FUNCTION

      node* current = this->head;

      int count = 0;

      
      while(current != nullptr){
	// Using the iterate function to count out many times the movie
	// shows up to then print it out 
	if(current->data->movie_ids.iterate(movie_id)){

	    count++;

	}
	current = current->next;
	
	  

      }
      fprintf(stdout, "The Views of ID: %d are %d\n", movie_id,  count);
   
      
    }


  void load_customers(string filename){
    
    
    ifstream file_id(filename);
    string line;
    int value;
    while (getline(file_id,line)) {
      value = stoi(line);


      // Creating a customer pointer that that gets the gets the value
      // then and then base on how many movies are in there based on the number
      // and then putti ng them inside the movie_id
      
      customer* fuze = new customer();

      fuze->customer_id = value;


      getline(file_id, line);
      int movies = stoi(line);

      for(int i = 0; i < movies; i++){
	getline(file_id, line);

	fuze->movie_ids.insert(stoi(line));
      }
      
      this->insert(fuze);

      

      
      //fprintf(stdout, "%d\n", value);
    }
  }

};



int main(int argc, char** argv){

    string filename;
    filename = get_filename(argc,argv);

    linked_list_customers clients;
    clients.load_customers(filename);

    clients.print_all();
    clients.print_customer(724);
    clients.print_views(109); 

    return 0;
}

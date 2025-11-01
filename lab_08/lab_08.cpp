#include <iostream>
#include <vector>
using namespace std;



struct student_pair {
    int id;
    string name;
};


/* Creaitng functions that just see if the number is grader than the prev, or
 for name the ascii value of the name like A, B, C */

bool compID(const student_pair& a, const student_pair& b){

  return a.id < b.id; 
}

bool compName(const student_pair& a, const student_pair& b){
  return a.name < b.name;

}



class my_class {
   private:
    const static int list_len = 10;
    student_pair students[list_len];
    int ctr = 0;





  
   public:
    void add_student(int id, string name);
    void sort_by_id();
    void sort_by_name();
    void print_list();
    void reset();
  /* Creating a overall sort function taking the reference of the student pair */
  
    void sort(bool (*compare)(const student_pair&, const student_pair&));
};

// reset the list
void my_class::reset() { ctr = 0; }

// print list
void my_class::print_list() {
    cout << "List of students: " << endl;
    cout << "ID\tName" << endl;
    for (int i = 0; i < ctr; i++) {
        cout << students[i].id << "\t" << students[i].name << endl;
    }
    cout << "\n" << endl;
}

// Add a student to the class
void my_class::add_student(int id, string name) {
    students[ctr++] = {id, name};
}






void my_class::sort(bool (*compare)(const student_pair&, const student_pair&)) {

  // Going through the list making a key and looking at the previous value with j
  // then well we compare the key (students) to the other, if true then move it and
  // go back if not move forward
  

  for(int i = 1; i < ctr; i++){

    student_pair key =students[i];
    int j = i -1;


    while(j >= 0 && compare(key, students[j])) {

      students[j + 1] = students[j];
      j--;
     
    }
    students[j+1] = key;
   


  }
}




















// sorts the students in order of id
void my_class::sort_by_id() {
    // your code here

  sort(compID);
  
  }

  







// sorts the students in order of name
void my_class::sort_by_name() {
    // your code here

  sort(compName);
}



 



int main() {

    my_class class_1;

    for (int i = 0; i < 2; i++) {

        class_1.reset();

        class_1.add_student(9, "Clarence");
        class_1.add_student(7, "Susan");
        class_1.add_student(3, "Peter");
        class_1.add_student(4, "Paul");
        class_1.add_student(1, "John");
        class_1.add_student(6, "Chris");
        class_1.add_student(2, "Mary");
        class_1.add_student(8, "Thomas");
        class_1.add_student(10, "Francesca");
        class_1.add_student(5, "Alex");

        if (i==0){
            class_1.sort_by_id();
            cout << "\n************** Sorted by ID **************" << endl;
            class_1.print_list();
        }
        else{ // i==1
            class_1.sort_by_name();
            cout << "\n************** Sorted by name **************" << endl;
            class_1.print_list();
        }
    }

    return 0;
}

/*
Lab 00

Description: <a brief description of what this file does>

@Author: <Shahzad Khan>
@Contact: <shahzadkhan@temple.edu>
@Date: <1/13/2025>

Example:
    This file can be compiled by typing:
    <g++ lab_00.cpp -o main.exe>

    This file can be run by typing:
    <./main.exe>
*/

#include<stdio.h>
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

/*
    Read in all the values from the file. Keep a running sum and then
    compute the average by dividing by the number of values in hte file.

    Print the average value with two decimal places.
*/

int main(int argc, char** argv){

  
    // step 0 - you can ignore this bit
    string filename = "/data/courses/ece_3822/current/lab_00/data.txt";
    if (argc>1)
        filename = argv[1];

    // step 1 init variables
    float s = 0;
    float n = 0;
    double avg = 0;
    string line;
    int val;
    // Added sums
    //
    int sum = 0;
    // step 2 open file
    ifstream file_id(filename);
    
    // step 3 read values from file
    // this is just an example to demonstrate syntax
    while (getline(file_id,line)){
      val = stoi(line);
      sum += val;
      n++;
    }

    //Calculate the average
    //
    


    if(n > 0){
      // Making sure n is a double
      //
      avg = sum/(double)n;
    }
    // A little error handling never hurt anyone
    //
    else{
      fprintf(stdout, "\nFile is empty please check it\n");
      return 1;
    }



    // Setiting the average to the percise average
    //

    
    ofstream outFile(filename);
    


    
    // step 4 print value
    //    outFile << "The average value is " << avg << endl;
    fprintf(stdout, "The average is %.2f\n", avg);
 

    
    file_id.close();

    return 0;
}
 

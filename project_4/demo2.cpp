#include<iostream>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;

void testCase3(){
    string fileName = "hospitalDataShort.txt";
    string line, substring;
    stringstream ss;

    // open the input file as a stream
    ifstream fileID(fileName);

    // getline reads one line from fileID and stores it as a string
    // in the variable named <line>
    while (getline(fileID,line)){
        cout << "Reading line: " << line << endl;

        // to split <line> into substrings (using spaces as the delimiter):

        // convert <line> into a stream
        ss.str( line );

        // take the first substring that ends in ' '
        getline(ss,substring,' ');
        cout << substring << endl;

        // take the second substring that ends in ' '
        getline(ss,substring,' ');
        cout << "Severity: " << stoi(substring) << endl;

        // take the third substring that ends in ' '
        getline(ss,substring,' ');
        cout << "Arrival Time: " << stoi(substring) << endl;

        // clear the stream for the next pass through the loop
        ss.clear();
        cout << endl;

    }

    // close the input file
    fileID.close();
}


void testCase4(){
    string fileName = "demoOutput.txt";
    ofstream fileID(fileName);

    // create dummy data to write to csv file
    string names[] = {"iyad","joe","john","saroj"};
    int    ids  [] = { 123  , 456 , 789  , 919};

    // print header
    fileID << "Name, ID"<< endl;

    // write to file
    for (int i = 0 ; i< 4 ; i++)
        fileID << names[i] << " , " << ids[i] << endl;
    
    // close the file
    fileID.close();

    // the resulting file can be imported (or just copy-pasted)
    // into Excel
}

int main(){
    testCase3();
    testCase4();
}
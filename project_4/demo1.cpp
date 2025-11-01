#include<iostream>
#include<bits/stdc++.h>
#include<fstream>

using namespace std;

void testCase1(){

    cout << endl;
    cout << endl;
    cout << "Test Case 1" << endl;

    int i;
    vector<int>data = {8,6,7,5,3,0,9};

    // create a max-heap queue
    priority_queue<int> maxQ;

    // push data onto the queue
    for (i = 0 ; i < data.size() ; i++ )
        maxQ.push(data[i]);

    // print the highest priority value and then pop it off
    while (!maxQ.empty() ){
        cout << maxQ.top() << endl;     // display the highest priority item
        maxQ.pop();                     // pop the highest priority item
    }
}

void testCase2(){

    cout << endl;
    cout << endl;
    cout << "Test Case 2" << endl;

    int i;
    vector<int>data = {8,6,7,5,3,0,9};

    // Use this syntax to specify what "lower priority" means.
    // Here, we define lower priority to mean "greater than"
    struct customLowerPriority{
        bool operator()(const int a, const int b) const { 
            return a > b;  // returning "true" means "it is true that a has lower priority than b"
        }
    };

    // create a min-heap queue
    priority_queue<int , vector<int> , customLowerPriority> minQ;

     // push data onto the queue
     for (i = 0 ; i < data.size() ; i++ )
        minQ.push(data[i]);

     // print the highest priority value and then pop it off
     while (!minQ.empty() ){
        cout << minQ.top() << endl;
        minQ.pop();
    }

}

int main(){

    testCase1();     // create a Max Heap (default priority_queue) of integers
    testCase2();     // create a Min Heap of integers by explicitly defining "lower priority"

    return 0;
}
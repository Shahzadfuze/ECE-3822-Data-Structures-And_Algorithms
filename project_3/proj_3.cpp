/* PROJECT 3 - proj_3.cpp

    @Shahzad Khan
    @tuk44487@temple.edu
    @3/19/2025

    Implements a system that models reading data asynchronously from the cloud,
    storing it temporarily in a buffer, and then placing it into a hash table.

    Compile:
        make all
    Compile for debug:
        make debug
    Run:
        ./proj_3 [OPT]
        where [OPT] is 0, 1, or 2 depending on which test case you are running.

*/

#include <iostream>
#include <thread>
#include <fstream>
#include <vector>
#include <chrono>
#include <mutex>

using namespace std;
using namespace std::chrono;

// ====================================
// Define the student structure
// ====================================
struct student {
    string first_name;
    string last_name;
    float gpa;
    long ID;
    string major;
};

// ====================================
// Queue Implementation
// ====================================
class queue {
private:
    vector<student*> data;  // Vector to store student data

public:
    // Add a student to the queue
    void push(student* s) {
        data.push_back(s);
    }

    // Remove and return the student at the front of the queue
    student* pop() {
        if (data.empty()) {
            return nullptr;
        }
        student* s = data.front();
        data.erase(data.begin());
        return s;
    }

    // Check if the queue is empty
    bool is_empty() {
        return data.empty();
    }

    // Return the size of the queue
    int size() {
        return data.size();
    }
};

// ====================================
// Hash Table Implementation
// ====================================
class hashTable {
private:
    // Node structure for linked list chaining
    struct node {
        student* data;
        node* next;

        node(student* s) {
            data = s;
            next = nullptr;
        }
    };

    vector<node*> table;  // Hash table (array of linked lists)
    int capacity;         // Size of the hash table

    // Hash function to map student ID to an index
    int hashFunction(long id) {
        id = (id * 2654435761) % capacity;  // Improved hash using Knuth's multiplicative method
        return (id + capacity) % capacity;  // Ensure non-negative index
    }

public:
    // Constructor to initialize the hash table
    hashTable(int size = 100) {
        capacity = size;
        table.resize(capacity, nullptr);
    }

    // Insert a student into the hash table
    void insert(student* s) {
        int index = hashFunction(s->ID);
        node* newNode = new node(s);

        // Insert at the beginning for simplicity (linked list chaining)
        newNode->next = table[index];
        table[index] = newNode;
    }

    // Search for a student by ID and return the student pointer
    student* search(long id) {
        int index = hashFunction(id);

        node* current = table[index];
        while (current != nullptr) {
            if (current->data->ID == id) {
                return current->data;  // Found student
            }
            current = current->next;
        }
        return nullptr;  // Not found
    }
};

// ====================================
// Global Variables
// ====================================
queue waiting_list;       // Queue to temporarily store student data
hashTable student_db;     // Hash table for storing processed data
mutex queue_mutex;        // Mutex to prevent race conditions

// ====================================
// Timing control - Do not modify
// ====================================
bool stop_thread = false;
steady_clock::time_point t1 = steady_clock::now();
float t_elapsed() {
    return duration_cast<seconds>(steady_clock::now() - t1).count();
}

// ====================================
// Process Input Data from Queue
// ====================================
void process_input_data() {
    student* p_student;

    while (!stop_thread) {
        queue_mutex.lock();

        // Check if the queue has data
        if (!waiting_list.is_empty()) {
            p_student = waiting_list.pop();
            if (p_student != nullptr) {
                student_db.insert(p_student);  // Insert into hash table
            }
        }

        queue_mutex.unlock();
    }
}

// ====================================
// Load Data from File and Push to Queue
// ====================================
void load_data(string filename) {
    string shared_path = "/data/courses/ece_3822/current/project_3/";
    string filename_complete = shared_path + filename;

    // Variables to store student data temporarily
    float arrival_time, gpa;
    string first, last, major;
    long id;

    ifstream f_id;
    f_id.open(filename_complete, ios_base::in);

    // Start the thread to process data asynchronously
    thread thr(process_input_data);

    while (f_id >> arrival_time) {
        // Read student data from the file
        f_id >> first >> last >> gpa >> id >> major;

        // Wait until the arrival time for the data packet
        while (t_elapsed() < arrival_time) {
            ;
        }

        // Create a new student object
        student* s = new student{first, last, gpa, id, major};

        // Push the student to the queue
        queue_mutex.lock();
        waiting_list.push(s);
        queue_mutex.unlock();
    }

    f_id.close();  // Close the file

    // Wait for the queue to empty before stopping the thread
    while (!waiting_list.is_empty()) {
        ;
    }

    stop_thread = true;  // Stop the processing thread
    thr.join();          // Wait for the thread to finish
}

// ====================================
// Main Function
// ====================================
int main(int argc, char** argv) {
    string filename;

    // Check for valid command line argument
    if (argc != 2) {
        cout << "ERROR: include a command line argument of 0, 1, or 2" << endl;
        return -1;
    }

    // Select the appropriate file based on the argument
    switch (stoi(argv[1])) {
        case 0: filename = "student_data_short.txt"; break;
        case 1: filename = "student_data_medium.txt"; break;
        case 2: filename = "student_data.txt"; break;
        default:
            cout << "ERROR: Invalid argument. Use 0, 1, or 2." << endl;
            return -1;
    }

    // Load data and process it
    load_data(filename);

    // ====================================
    // Lookup Student Data by ID
    // ====================================
    vector<long> student_ids = {206359917, 232489514, 948140115};

    for (long id : student_ids) {
        student* s = student_db.search(id);
        if (s != nullptr) {
            // Print student info if found
            fprintf(stdout, "Found student: %s %s, GPA: %.2f, Major: %s\n",
                    s->first_name.c_str(), s->last_name.c_str(), s->gpa, s->major.c_str());
        } else {
            fprintf(stdout, "Student with ID %ld not found\n", id);
        }
    }

    return 0;
}
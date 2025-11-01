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
// description: This is the file for part 1 just going through and
//              loading the files and placeing them in a hashtable
//              Also using a search function that goes through and find the movie,
//              For testing I used "The War of Godzilla" never watched it but it sounds cool
//              
//
// 




void loadMoviesFromfiles(MovieHashTable& table, const string& filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Failed to open " << filename << endl;
    return;
  }

  string line;
  getline(file, line); // Skip the header

  while (getline(file, line)) {
    stringstream ss(line);
    string id, title, yearStr, runtime, genres;

    // this line of code is crazy looking
    // basiclly what it does it "\t" is the tab character
    // it goes into the file and gets the id then tab gets the tile and then tab and so on

    
    getline(ss, id, '\t');
    getline(ss, title, '\t');
    getline(ss, yearStr, '\t');
    getline(ss, runtime, '\t');
    getline(ss, genres, '\t');

    if (yearStr == "\\N" || title.empty()) {
      continue; // Skip entries without a valid year or title
    }

    int year = stoi(yearStr);
    table.insert(title, id, year);

    // This i think was the only way to find the title using the Id
    // (I spent a lot of time just rtrying to figure this out)
    
    movieIdToTitleMap[id] = title; // Also for part 3 
  }

  file.close();
}


int MovieHashTable::hashFunction(const string& key) const {
  // Simple hashkey just found it online

  int hash = 0;
  for (char c : key) {
    hash = (hash * 31 + c) % tableSize;
  }
  return hash;
  }

MovieHashTable::MovieHashTable(int size) : tableSize(size) {

  // Using vectors makes this a lot easier cause I don't have to really
  // worry about the memory 
  table.resize(size); // Initialize the table
}

void MovieHashTable::insert(const string& title, const string& id, int year) {
  int index = hashFunction(title);
  table[index].push_back({title, {id, year}}); // Use push_back for vectors
}

bool MovieHashTable::lookup(const string& title, string& id, int& year) const {
  int index = hashFunction(title);
  for (const auto& entry : table[index]) { // Iterate through the vector at the index
    if (entry.first == title) {
      id = entry.second.first;
      year = entry.second.second;
      return true;
    }
  }
  return false;
}

// Display function for debugging, (I had to do a lot of debugging)
void MovieHashTable::display() {
  for (const auto& bucket : table) {
    for (const auto& entry : bucket) {
      cout << "Movie Title: " << entry.first << ", Movie ID: " << entry.second.first
	   << ", Release Year: " << entry.second.second << endl;
    }
  }
}

int MovieHashTable::getSize() {
  return tableSize;
}


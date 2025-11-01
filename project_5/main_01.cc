#include "example.h"
#include <utility>

/*This is for part 2 finding the actor, its bascilly the same as
 part 1 as in creating a hashtable for the actors and reading the file
and putiting the information in*/



ActorHashTable::ActorHashTable(int size) : tableSize(size) {
  table.resize(size);
}

int ActorHashTable::hashFunction(const string& key) const {
  int hashValue = 0;
  const int prime = 31; // Prime number to scale the sum of ASCII values

  for (int i = 0; i < key.length(); ++i) {
    hashValue = hashValue * prime + key[i];  // Multiply by prime and add ASCII value
  }

  // Ensure the value is within the bounds of the buffer size
  return abs(hashValue % tableSize);

}

void ActorHashTable::insert(const string& name, const string& id, int birthYear, int deathYear) {

  int index = hashFunction(name);
  
  if (index >= 0 && index < tableSize) {
    table[index].push_back({name, {id, {birthYear, deathYear}}});
  } else {
    cerr << "Error: Index out of bounds: " << index << endl;
  }

  
}
bool ActorHashTable::lookup(const string& name, string& id, int& birthYear, int& deathYear) const {

  int index = hashFunction(name);
  for (const auto& actor : table[index]) {
    if (actor.first == name) { // Accessing the first part of the pair (actor name)
      id = actor.second.first;  // Accessing the second part: id
      birthYear = actor.second.second.first; // Accessing birth year
      deathYear = actor.second.second.second; // Accessing death year
      return true;
    }
  }
  return false;
}

void ActorHashTable::display() const {
  for (const auto& bucket : table) {
    for (const auto& entry : bucket) {
      cout << "Name: " << entry.first
	   << ", ID: " << entry.second.first
	   << ", Birth Year: " << entry.second.second.first
	   << ", Death Year: ";
      if (entry.second.second.second == -1)
	cout << "N/A";
      else
	cout << entry.second.second.second;
      cout << endl;
    }
  }
}

int ActorHashTable::getSize() const {
  return tableSize;
}
void loadActorsFromFile(ActorHashTable& table, const string& filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Failed to open " << filename << endl;
    return;
  }

  
  
  string line;
  getline(file, line); // Skip header

  while (getline(file, line)) {
    stringstream ss(line);
    string id, name, birthStr, deathStr;

    getline(ss, id, '\t');
    getline(ss, name, '\t');
    getline(ss, birthStr, '\t');
    getline(ss, deathStr, '\t');


    // What these lines of code do are it checks to see if the birth or death
    // exist if it doesn't set it to -1 so when we print it we can get "N/A"
    if (name.empty() || birthStr == "\\N")
      continue;

    int birth, death;

    if (birthStr == "\\N") {
      birth = -1;
    }
    else{
      birth = stoi(birthStr);
    }
   
    if (deathStr == "\\N") {
      death = -1;
    }
    else{
      death = stoi(deathStr);
	    
    }


    // Chatgpt print statement for debugging
    /*    // Print out the information for the actor
    cout << "Inserting actor: Name: " << name << ", ID: " << id
	 << ", Birth Year: " << (birth == -1 ? "N/A" : to_string(birth))
	 << ", Death Year: " << (death == -1 ? "N/A" : to_string(death)) << endl;
    */

    // Then we place the actor into the hashtable
    table.insert(name, id, birth, death); 
    
    }

  file.close();
}

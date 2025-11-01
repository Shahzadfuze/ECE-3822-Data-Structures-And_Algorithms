// file: .
//

// make sure definitions are only made once
//
#ifndef ISIP_EXAMPLE
#define ISIP_EXAMPLE

// system include files
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;


/*Part 1 */

// Structure to store actor information
struct Actor {
  string name;
  int birthYear;
  int deathYear;

};

// Structure to store movie information
struct Movie {
  string title;
  int year;
};



extern unordered_map<std::string, std::string> movieIdToTitleMap; // I have to do this for part 3 `
 
// Part 1: Movie Hash Table
class MovieHashTable {
private:
  //vector<pair<string, pair<string, int>>> table; // Changed to vector of pairs
  vector<vector<pair<string, pair<string, int>>>> table;
  int hashFunction(const string& key) const; 
  int tableSize;


public:
  MovieHashTable(int size = 10000);

  void insert(const string& title, const string& id, int year);

  bool lookup(const string& title, string& id, int& year)const ; 

  void display();
  int getSize();
};

void loadMoviesFromfiles(MovieHashTable& table, const string& filename);


// Part 2 

class ActorHashTable {
private:
  vector<vector<pair<string, pair<string, pair<int, int>>>>> table;
  int tableSize;

  int hashFunction(const string& key) const;

public:
  ActorHashTable(int size);

  void insert(const string& name, const string& id, int birthYear, int deathYear);
  bool lookup(const string& name, string& id, int& birthYear, int& deathYear) const;
  void display() const;
  int getSize() const;
};

void loadActorsFromFile(ActorHashTable& table, const string& filename);

// Part 3




// RoleHashTable class
class RoleHashTable {
  private:
      struct Role {
          string actorID;
          vector<string> movieIDs;
      };
  
      vector<vector<Role>> table;
      int tableSize;
  
      int hashFunction(const string& key) const;


public:
  RoleHashTable(int size);
  void insert(const string& actorID, const string& movieID);
  bool lookup(const string& actorID, vector<string>& movieIDs) const;
  vector<string> getMoviesByActor(const string& actorName, const ActorHashTable& actorTable, const MovieHashTable& movieTable) const;
};

void loadRolesFromFile(RoleHashTable& table, const string& filename);








// end of include file
//
#endif




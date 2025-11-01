#include "example.h"


/*Oh boy, this function killed me, I spent so long trying to get this right,
 What I did is I made a hashtable of just the movie id and title so that I
can go back when I get the id and find the title. I did this because my look up
function only finds based of the title and I was not going to go back and rewrite everyting
for that */

unordered_map<std::string, std::string> movieIdToTitleMap; // I have to do this for part 3 `

// RoleHashTable implementation
int RoleHashTable::hashFunction(const string& key) const {

  // This hash function, I used a different one because I though it was
  // somehow interfering with my previous one, not really, I was just tired  basiccly want we
  // do is go through the key, this case being the actors name and for each chacater we times 5381 by 33 and add the character value
  // and then resize it to the table
  unsigned long hash = 5381;
  for (char c : key) {
    hash = ((hash << 5) + hash) + c; // hash * 33 + c
  }
  return hash % table.size();

}

RoleHashTable::RoleHashTable(int size) : tableSize(size) {
  if (size <= 0) {
      cerr << "Error: Invalid table size for RoleHashTable. Must be greater than 0." << endl;
      return; 
  }
  table.resize(size);
}

void RoleHashTable::insert(const string& actorID, const string& movieID) {
  if (actorID.empty() || movieID.empty()) {
      cerr << "Error: Attempted to insert empty actorID or movieID into RoleHashTable." << endl;
      return;
  }

  int index = hashFunction(actorID);
  
  for (auto& role : table[index]) {
      if (role.actorID == actorID) {
          role.movieIDs.push_back(movieID);
          return;
      }
  }
  table[index].push_back({actorID, {movieID}});
}

bool RoleHashTable::lookup(const string& actorID, vector<string>& movieIDs) const {
  if (actorID.empty()) {
      cerr << "Error: Attempted to lookup an empty actorID in RoleHashTable." << endl;
      return false;
  }

  //  Just going through the actorid and and matching it 
  int index = hashFunction(actorID);
  for (const auto& role : table[index]) {
      if (role.actorID == actorID) {
          movieIDs = role.movieIDs;
          return true;
      }
  }
  return false;
}




vector<string> RoleHashTable::getMoviesByActor(const string& actorName, const ActorHashTable& actorTable, const MovieHashTable& movieTable) const {
  string actorId;
  int birthYear, deathYear;


  // This gave me the most trouble 
  // Step 1: Lookup the actor to get their ID from the ActorHashTable
  if (actorTable.lookup(actorName, actorId, birthYear, deathYear)) {
    cout << "Found actor: " << actorName << ", ID: " << actorId << endl;
  } else {
    cout << "Actor not found!" << endl;
    return {};  // Return empty vector if the actor is not found
  }


  // Step 2: Find all roles associated with this actor's ID from the RoleHashTable
  vector<string> movieIds;
  if (!lookup(actorId, movieIds)) {
    cout << "No movies found for this actor!" << endl;
    return {};
  }

  // Step 3: Print out the movie details for each movie ID
  cout << "Movies starring " << actorName << ":" << endl;
  vector<string> movieTitles; // Store the titles of movies for this actor

  for (const string& movieId : movieIds) {
    // Use the auxiliary map to get the title for the movie ID
    auto it = movieIdToTitleMap.find(movieId);
    if (it == movieIdToTitleMap.end()) {
      cout << "Movie not found for ID: " << movieId << endl;
      continue;
    }

    string movieTitle = it->second;
    string movieIdFromTable;
    int movieYear;

    // Look up the movie title in the MovieHashTable
    if (movieTable.lookup(movieTitle, movieIdFromTable, movieYear)) {
      cout << movieTitle << " (" << movieYear << ")" << endl;
      movieTitles.push_back(movieTitle);
    } else {
      cout << "Movie not found in MovieHashTable for title: " << movieTitle << endl;
    }
  }

  return movieTitles;  // Return the list of movie titles
}




void loadRolesFromFile(RoleHashTable& table, const string& filename) {
  ifstream file(filename);
  if (!file.is_open()) {
      cerr << "Failed to open " << filename << endl;
      return;
  }

  // Bascilly the same thing we had before just making sure to only
  // keep actors and actress
  
  string line;
  while (getline(file, line)) {
    stringstream ss(line);
    string movieID, actorID, role, characters;

    getline(ss, movieID, '\t');
    getline(ss, actorID, '\t');
    getline(ss, role, '\t');
    getline(ss, characters, '\t');

    // Only keep roles that are "actor" or "actress"
    if (role == "actor" || role == "actress") {
      if (actorID.empty() || movieID.empty()) {
	cerr << "Warning: Skipping malformed line: " << line << endl;
	continue;
      }

      table.insert(actorID, movieID);
    }
  }
  file.close();
}

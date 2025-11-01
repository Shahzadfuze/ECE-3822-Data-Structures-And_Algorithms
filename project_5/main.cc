// file: .
//

// local include files
//
#include "example.h"

// function: main
//
// Program Function: 
// 
//

int main(int argc, char** argv) {


  // Finally just putting everything together 
  // Step 1: Load movies into the hash table
  MovieHashTable movieTable(1000); // Adjust the table size as necessary
  string movieFilename = "/data/courses/ece_3822/current/project_5_data/titles.tsv";
  loadMoviesFromfiles(movieTable, movieFilename);
  cout << "Movies loaded into hash table.\n";

  // Step 2: Load actors into the hash table
  ActorHashTable actorTable(10000);
  string actorFilename = "/data/courses/ece_3822/current/project_5_data/names.tsv";
  loadActorsFromFile(actorTable, actorFilename);
  cout << "Actors loaded into hash table.\n";

  // Step 3: Load roles into the hash table
  RoleHashTable roleTable(10000);
  string roleFilename = "/data/courses/ece_3822/current/project_5_data/roles.tsv";
  loadRolesFromFile(roleTable, roleFilename);
  cout << "Roles loaded into hash table.\n";

  /*  // Step 4: Search for a movie by name
  string searchMovie;
  cout << "Enter movie title to search: ";
  getline(cin, searchMovie);

  string movieId;
  int movieYear;
  if (movieTable.lookup(searchMovie, movieId, movieYear)) {
    cout << "Movie found! Title: " << searchMovie << ", Year: " << movieYear << ", ID: " << movieId << endl;
  } else {
    cout << "Movie not found.\n";
  }

  // Step 5: Search for an actor/actress by name
  string searchActor;
  cout << "Enter actor/actress name to search: ";
  getline(cin, searchActor);

  string actorId;
  int birthYear, deathYear;
  if (actorTable.lookup(searchActor, actorId, birthYear, deathYear)) {
    cout << "Name: " << searchActor
	 << ", ID: " << actorId
	 << ", Birth Year: " << birthYear
	 << ", Death Year: ";
    if (deathYear == -1)
      cout << "N/A";
    else
      cout << deathYear;
    cout << endl;
  } else {
    cout << "Actor/Actress not found.\n";

  }


  */
  string actorName = "Jason Derulo";

  //  cout << "Enter the name of the actor to search for their movies: ";
  //  getline(cin, actorName);

  // Search for movies by the actor
  roleTable.getMoviesByActor(actorName, actorTable, movieTable);
  
  


  
  return 0;
} // end of main

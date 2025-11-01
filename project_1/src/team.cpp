#include "team.h"

// YOUR CODE HERE


// So here with the constructor we place default values so that we can
// add player and a captain pretty cool
//
team::team(string n){
  name = n;
}

void team::add_player(player* p){
  if(find(roster.begin(), roster.end(), p) == roster.end()){
    roster.push_back(p);
  }
  else{
    fprintf(stdout, "Player is already on the roster");
  }
}

void team::remove_player(player* p){

  // See if the player is there
  //
  vector<player*>::iterator it = find(roster.begin(), roster.end(), p);
  // If they are then remove them
  //
  if(it != roster.end()){
    roster.erase(it);

    if(captain == p){
      this->captain = nullptr;
      fprintf(stdout, "Captain has been kicked out\n");
    }
  }
  else {
    fprintf(stdout, "Player is not on the roster\n");
  }
}

void team::set_captain(player* p){
  
  if(find(roster.begin(), roster.end(), p) != roster.end()){
    this->captain = p;
  }
  else{
    fprintf(stdout, "Player is not on the roster please choose someone else");
  }

}

int team::play_turn(){

  int turn_score = 0;

  // Each player gets one turn
  for (player* p : roster) {
    turn_score += p->play_turn();
  }

  // The captain gets an extra turn
  if (captain) {
    turn_score += captain->play_turn();
  }

  // Add the turn's score to the team's total score
  score += turn_score;

  fprintf(stdout, "The team scored %d this turn\n", turn_score);
  return turn_score;
}

void team::reset_score(){

  // Reset the team's total score
  score = 0;

  // Reset each player's score
  for (player* p : roster) {
    p->reset_score();
  }

  // Reset the captain's score (if a captain exists)
  if (captain) {
    captain->reset_score();
  }

  fprintf(stdout, "Team and player scores have been reset.\n");
}

string team::get_name(){
  return this->name;
}

int team::get_score(){
  return this->score;

}


void team::display(){

  fprintf(stdout, "Team names %s \n Total score %d\n", name.c_str(), score);
  
  if (captain) {
    fprintf(stdout, "Captain: %s\n", captain->get_name().c_str());
  }
  else {
    fprintf(stdout, "Captain: None\n");
  }
  fprintf(stdout, "Roster:\n");
  for (player* p : roster) {
    fprintf(stdout, "- %s (Score: %d)\n", p->get_name().c_str(), p->get_score());
  }
}


#ifndef _TEAM_
#define _TEAM_

#include<iostream>
#include<vector>
// So we can use the find function
//
#include<algorithm>
using namespace std;

#include "player.h"

class team{
private:
  // put whatever you think you need here
  string name;
  // We are using the vector libary to create a list that have all the players
  // place in memory so we don't have to copy the entire player to have them in a team
  //
  vector<player*> roster;
  int score = 0;
  // We set the captain to be a player* again so we don't have to load a whole
  // new copy of player into memory and set it to a null pointer so we can
  // point to it later pretty fire
  //
  player* captain = nullptr;
  
    
public:
  // don't edit
  
  team(string="");            // constructor
  void add_player(player*);   // add player to team
  void remove_player(player*);// remove player
  void set_captain(player*);  // specify who is the captain
  int play_turn();            // play turn, return score from the turn, update total score
  void reset_score();         // reset team score and all player scores
  string get_name();          // retrieve team name
  int get_score();            // retrieve team score
  void display();             // display team information

};

#endif

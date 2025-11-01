#ifndef _PLAYER_
#define _PLAYER_

#include<iostream>
using namespace std;

/* this include gives you access to 
    int generate_score(int)
    which takes ability (0,1,2) as input and returns a valid 
    score according to the project instructions */
#include "ece_3822.h"

class player{
private:
  // put whatever you think you need here
  string name;
  int ability_level;
  bool captain;
  int score;
  
public:
  // don't edit
  
  player(string="",int=0);    // constructor (name , ability level)
  void reset_score();         // reset player score to zero
  void set_ability(int);      // set ability level (0,1,2)
  int play_turn();            // play turn, return score
  int get_score();            // retrieve score
  void display();             // display player information
  string get_name();          // retrieve player name
  
};

#endif

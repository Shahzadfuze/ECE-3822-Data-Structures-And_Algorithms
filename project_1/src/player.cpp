#include"player.h"

// YOUR CODE HERE

player::player(string n, int a){
  name = n;
  ability_level = a;
  captain = 0;
  score = 0;
};


void player::reset_score(){


  // Dereferences pointer and puts the value as 0
  // *(player).score = 0;
  //
  this->score = 0;
  
}


void player::set_ability(int a){

  // Setting the ability level to the inputs
  //
  this->ability_level = a; 
}


int player::play_turn(){
  // Just returning a turn based on there ability level
  //
  if (this->ability_level == 0) return 1;  // Low ability
  if (this->ability_level == 1) return 3;  // Medium ability
  if (this->ability_level == 2) return 5;  // High ability
  return 0;
  
}

int player::get_score(){

  return this->score;
}

void player::display(){
  // Prints out a nicely displayed print statement
  //
  fprintf(stdout , "Name: %s\nAbility Level: %d \nCaptain: %d \nScore: %d\n", this->name.c_str(), this->ability_level, this->captain, this->score);

}

string player::get_name(){
  // Returns the name 
  //
  return this->name;

}



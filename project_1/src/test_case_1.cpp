#include<iostream>
#include"player.h"
using namespace std;

// Test case 1 - create and manipulate a single player
// Do not edit

void test_case_1(){

    cout << "********** Test Case 1 **********" << endl;

    // create a player
    player alice("Alice Adams");

    // reset player's score to zero
    alice.reset_score();

    // set player's ability (0, 1, or 2)
    alice.set_ability(0);

    // player gets a single turn (score is incremented by a random number)
    alice.play_turn();

    // return the player's score
    int score = alice.get_score();

    // display the player's name and total score
    alice.display();

    cout << endl;
}


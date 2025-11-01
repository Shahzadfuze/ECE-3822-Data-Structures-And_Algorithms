#include<iostream>
using namespace std;
#include "player.h"
#include "team.h"

// Test case 2 - create and manipulate a team of players
// Do not edit

void test_case_2(){

    cout << "********** Test Case 2 **********" << endl;

    // create players by specifying name and skill level
    player* alice = new player("Alice"  , 0);
    player* betty = new player("Betty"  , 2);
    player* chuck = new player("Chuck"  , 1);

    // create team
    team team_1("The Dragons");

    // assign players to teams, set Brett as the captain
    team_1.add_player(alice);
    team_1.add_player(betty);
    team_1.add_player(chuck);
    team_1.set_captain(betty);

    // display team information
    team_1.display();

    // play five turns
    for (int i = 0 ; i<5 ; i++)
        team_1.play_turn();
    
    // display total result
    cout << team_1.get_name() << " scored " << team_1.get_score() << endl;
    
    // destroy the players!
    delete alice;
    delete betty;
    delete chuck;

    cout << endl;
}


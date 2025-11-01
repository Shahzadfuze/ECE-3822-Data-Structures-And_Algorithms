#include<iostream>
#include"player.h"
#include"team.h"
using namespace std;

// Test case 3 - create two teams and trade players
// Do not edit

void test_case_3(){

    cout << "********** Test Case 3 **********" << endl;

    // create six players
    player alice("Alice");
    player betty("Betty");
    player chuck("Chuck");
    player danny("Danny");
    player eddie("Eddie");
    player frank("Frank");

    // reset player's score to zero
    alice.reset_score();
    betty.reset_score();
    chuck.reset_score();
    danny.reset_score();
    eddie.reset_score();
    frank.reset_score();

    // set player's ability (0, 1, or 2)
    alice.set_ability(0);
    betty.set_ability(1);
    chuck.set_ability(2);
    danny.set_ability(0);
    eddie.set_ability(1);
    frank.set_ability(2);

    // define and populate two teams
    team team_1("Team 1");
    team_1.add_player(&alice);
    team_1.add_player(&betty);
    team_1.add_player(&chuck);
    team_1.set_captain(&alice);

    team team_2("Team 2");
    team_2.add_player(&danny);
    team_2.add_player(&eddie);
    team_2.add_player(&frank);
    team_2.set_captain(&danny);

    // trade Frank to Team 1
    team_2.remove_player(&frank);
    team_1.add_player(&frank);

    // trade Alice to Team 2
    team_1.remove_player(&alice);
    team_2.add_player(&alice);

    // reassign captains
    team_1.set_captain(&betty);
    team_2.set_captain(&eddie);

    // display team rosters
    team_1.display();
    printf("\n");
    team_2.display();

}


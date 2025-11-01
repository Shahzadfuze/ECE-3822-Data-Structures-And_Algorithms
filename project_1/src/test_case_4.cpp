#include<iostream>
using namespace std;

#include "player.h"
#include "team.h"

// Test case 4 - play a sample game
// Do not edit

void test_case_4(){

    cout << "********** Test Case 4 **********" << endl;

    // step 1 create players
    // this time I'll use a loop to make it easier. We'll make 20 players.
    // to make things easier we'll assign them all the same ability level
    player* player_list[20];
    for (int i = 0 ; i<20 ; i++)
        player_list[i] = new player("Generic Name" , 2);
    
    // step 2 create teams
    team team_1("The Dragons");
    team team_2("The Knights");


    // step 3 pick teams (the draft)
    for (int i = 0 ; i < 10 ; i++)
        team_1.add_player(player_list[i]);      // team 1 gets ten players
    team_1.set_captain(player_list[0]);         // set team 1 captain

    for (int i = 10 ; i < 20 ; i++)
        team_2.add_player(player_list[i]);      // team 2 gets ten players
    team_2.set_captain(player_list[10]);        // set team 1 captain

    // step 4 - play the game! 5 rounds:
    for (int i = 0 ; i < 5 ; i++){
        team_1.play_turn();
        team_2.play_turn();
    }

    // step 5 - pick the winner
    cout << team_1.get_name() << " scored " << team_1.get_score() << endl;
    cout << team_2.get_name() << " scored " << team_2.get_score() << endl;

    if (team_1.get_score() > team_2.get_score() )
        cout << team_1.get_name() << " win!" << endl;

    else if (team_2.get_score() > team_1.get_score() )
        cout << team_2.get_name() << " win!" << endl;

    else
        cout << "its a tie!" << endl;

    // step 6: reset teams
    team_1.reset_score();
    team_2.reset_score();

    // step 7: demonstrate that scores were reset by displaying Team 1
    printf("\n");
    printf("Demonstrate that The Dragons were reset:\n");
    team_1.display();

    cout << endl;

    for (int i=0 ; i<10 ; i++)
        delete player_list[i];

}

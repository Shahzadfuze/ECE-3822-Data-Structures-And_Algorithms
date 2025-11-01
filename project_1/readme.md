# Project 1

## Purpose
The purpose of Project 1 is to practice using C++ classes and getting
comfortable with Makefiles, directories, and libraries. You will used C++ 
to code up a simple game I have invented. The game consists of `players`. Multiple players can be grouped into `teams` and two `teams` can play each other. 

Each **PLAYER** has:
- a name
- an ability level (0, 1, or 2)
- a player status (0: normal ; 1: captain)
- a score

Each **TEAM** has:
- a name
- a roster of players
- a total team score
- exactly one captain

Whenever a player has a turn, they get a random **score**:
- ability level 0: score is equally likely to be 0, 1, 2, or 3
- ability level 1: score is equally likely to be 2, 3, 4, or 5
- ability level 2: score is equally likely to be 4, 5, 6, or 7

Whenever a team has a turn:
- every player on the team gets a turn
- the captain gets two turns

A **game** goes as follows:
- players are created
- two teams are created
- a draft is conducted in which each team picks players
- the competition has 5 rounds
- during each round, each team gets a turn (see above)
- at the end, team with the highest score wins

## Steps
Your job is to write the code for `team.cpp` and `player.cpp` to make all
the test cases work. You will also need to make edits to `team.h` and `player.h`

## Provided Code
Other than `team.cpp` and `player.cpp` I have written all the other code you
will need. In particular I have provided four pre-built test cases that:

- **Test Case 1:** Create and manipulate a single player
- **Test Case 2:** Create and manipulate a team of players
- **Test Case 3:** Create two teams and trade players
- **Test Case 4:** Play a complete game

## Notes
Unless you want to add your own test cases (which you're welcome to do) do not
edit anything other than `team.cpp`, `team.h`, `player.cpp`, and `player.h`.

Do not mess with the directory structure!!! Source code belongs in
`src/`. Object files will automatically go into `obj`, and your executable
will be named `proj_1`.

The code for generating the random score values has been written for you.
The header is in `$SHARE/include/ece_3822.h` and you don't need to make *any*
edits. The compiled library containing the random score generator is in
`$SHARE/include/libece_3822.a`. Simply use the provided Makefile and your code
will automatically 'know' what that the `int generate_score(int)` function is 
all about.

You must **comment** your code. Every function must have at least a one line
description, must describe the inputs and outputs, and must use meaningful
variable names and self-commenting code. You must also remember to put your
name, date, contact info, and any other relevant notes at the top of
your `.cpp` files.

## Due
Sunday 2/9/2025 at midnight

## Questions
`iobeid@temple.edu`
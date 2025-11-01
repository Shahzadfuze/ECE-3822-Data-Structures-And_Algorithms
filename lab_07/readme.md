# Lab 7

## Purpose
The purpose of this lab is to complete the <are_connected> function that
returns "True" if there is a path from src to dst and "False" otherwise.
This includes indirect paths! If there is no direct connection between
Nodes 0 and 3, but you can get from 0 to 3 by passing through Nodes 1 and/or 2 then your code should return True.

You will achieve this by implementing <are_connected> with a 
_breadth-first search (DFS)_ (see below)

## Breadth-First Search
Breadth first search works as follows

[1] Create a list called `visited` which keeps track of which nodes
you've already visited. Initialize it to be empty.

[2] Create a queue called `in_progress` and initialize it to be empty. To create
a queue you can either use a normal list (using `append` and `pop(0)`
or a Python `deque` which you can read about [here](https://www.geeksforgeeks.org/queue-in-python/)

[3] Insert the `SRC` node into `in_progress`

[4] Repeat the following steps until either you reach `DST` or
`in_progress` is empty (which means there is no path)

- Pop a node from `in_progress` and insert it into `visited`
- Check each node that can be reached from the current node.
    - If that node is the `DST` node, then stop the search because a
    route from `SRC` to `DST` has been found
    - Else if that node is not already in `visited`, place it in the
    `in_progress` queue


## Test Files
There are three graphs provided in text files. I have already written the code for loading the graphs from file into a matrix (a list of lists). The graph is unidirectional and unweighted.

## Code Execution
To run the program you must provide three commandline arguements:
    opt     [0,1,2]             specifies which graph file to use
    src     [0,1,...,(size-1)]  specifies the identity of the src node
    dst     [0,1,...,(size-1)]  specifies the identity of the dst node

You should test your code extensively! 

## Notes
Submit using ./submit.py which will only turn in lab_07.py

## Due
Sunday 4/6/2025 at midnight

## Questions
`iobeid@temple.edu`

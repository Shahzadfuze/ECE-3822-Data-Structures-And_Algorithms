# Project 4

## Purpose
The purpose of this project is to acquaint you with C++'s own built-in
priority encoder and to use it to run a simulation of an emergency room
triage program.

## Step 1
Familiarize yourself with the C++ priority encoder by looking at
`testCase1()` and `testCase2()` in `demo1.cpp`. Note that unlike the code
we did in class, the `pop()` method doesn't return anything. Instead, to
see the highest priority element, use the `top()` command.

## Step 2
Familiarize yourself with reading a string from file and writing 
comma-separated data to a text file with `testCase3()` and `testCase4()`
respectively in `demo2.cpp`.

Note that each line of `hospitalData.txt` contains three elements:

- Patient identifier
- Severity of injury
- Arrival time to the hospital

## Step 3
Create a `patient` class or struct that stores patient ID, severity, 
and arrival time

## Step 4
Follow the syntax from `demo1.cpp` to create a struct operator
that defines lower patient priority to mean having a higher
severity level. If two patients have the same severity, the lower
priority is for the patient who arrived later. Use this struct as 
well as the `priority_queue<>` C++ container to create a priority
queue of patients. Create some sample data and test your priority queue
to be sure it works as expected.

## Step 5
Using everything you've learned above, write a program called 
`project_4.cpp` that simulates what happens when the 1000 patients in 
the file `hospitalData.txt` arrive at the hospital. Assume that there
is only one doctor and that it take five minutes to care for each patient.
While a patient is being seen, if new patients arrive, they are placed
in the priority queue. When the doctor is free, the highest priority
patient is popped from the queue and treated.

As each patient is treated, log them in a text file called `results.csv`
where each line stores the patient's severity and the amount of time they
waited to be seen.

## Step 6
Copy your results into Excel and confirm that patients with more severe
injuries have shorter average waiting times that those with less severe
injuries.

In a text file called `results.txt`, write the average wait time for each
of the ten severity levels.

## What to turn in
The submit script will turn in `project_4.cpp` and `results.txt` only.

## Extra credit
Repeat Step 5 using two doctors instead of just one.

## Due
Sunday 4/13/2025 at midnight

## Questions
`iobeid@temple.edu`
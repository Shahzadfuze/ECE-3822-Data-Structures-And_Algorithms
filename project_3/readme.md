# Project 3

## Purpose
Imagine a situation where you are receiving transmitted data packets of
information about students, and that the packets arrive at irregular intervals.
Each packet contains information about a single student: name, student ID, gpa,
and major. As is often the case in real life, data arrives at unpredictable
times and the computer might not be available to process it at the instant of
arrival. In that case, the solution is to temporarily stash the data in a
queue. When the computer becomes available to process data, it checks to see if
any data is waiting in the queue. Data is "processed" by popping it out of the
queue, and then storing it into a hash table so that it can be easily searched
in the future.

We will simulate incoming data packets with a text file that contains packet
information and the packet arrival time. The code automatically inserts a time
delay to simulate the packet's arrival time. While you are reading data into
the queue, a separate thread will be simultaneously running.  This thread will
be constantly checking the queue. If the queue contains data, then you will pop
one student packet from the queue, hash it, and store it in the hash table.

Finally, you will demonstrate that your code works by looking up some students
by their student ID.

## Acquire Code
`rsync -rv $SHARE/project_3 .`


## Goals
[1] Create a class named `student` that stores the fields for each student 

[2] Create a `queue` (many ways to implement this, but feel free to use the super
easy vector approach) 

[3] Push each student's object into the queue 

[4] Implement a hashing function that hashes the student ID number 

[5] Pop students off the queue and place them into the hash table appropriately 

[6] Implement a function that will look up students in the hash table and print out their
information

## Hints and Suggestions

There is a block diagram pdf that might be helpful to refer to.

Items 1-3 are meant to be simple

Item 4 is the trickiest part - you will have to determine a good hash 
function for the student ID numbers that will reasonably  distribute the 
data within the hash table. As a hint: each 9-digit student ID number was 
constructed using different bits of information about each student. Some of 
that information, such as year of birth, will be common to many students. 
Therefore many students will share certain common digits in their student 
ID numbers, and those would make for bad hash inputs because they wouldn't 
distribute uniformly. **Note:** We will look at the distribution of keys
when grading your assignment. Your hash function should distribute keys
over the entire buffer.

Items 5-6 are medium difficulty

Please don't re-invent the wheel. I've written a lot of code to try to make
this as straightforward as possible. For example, I handle reading the data
from file. No need for you to do that. Also don't worry about the "mutex
lock/unlock" stuff. That just prevents two parallel processes from trying to
modify the same data structure at the same time.

I've included shorter versions of the data file for testing purposes. The
longest version will take about 10 seconds for all the 'packets' to arrive and
be processed. Also, I've put all the code into a single file. You can keep it
that way or break it up into whatever number of sub files makes sense to you.

Finally, use the Makefile to compile your code. The Makefile includes the
-pthread flag, and the threaded coded won't work without it.

## Data Files
There are three data files for you to test your algorithm, the first 
one is pretty short, the last one is pretty long.

- student_data_short.txt
- student_data_medium.txt
- student_data.txt

## How to Make and Run
Use the Makefile!
- `make proj_3`
- `./proj_3`

## Code Comments
Document *everything*. I will be marking code off if it isn't commented 
*very* well.

## Submission
The submit script will submit all `cpp` and `h` files, as well as the
`Makefile` - this way you can break the code into multiple smaller files
if you find that easier.

## Due
Sunday 3/23/2025 at midnight

## Questions
`iobeid@temple.edu`

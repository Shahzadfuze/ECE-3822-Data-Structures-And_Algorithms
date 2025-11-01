# Project 5: Movies!

## Purpose
The purpose of this project is to build a searchable database by drawing
on your knowledge of data structures. The data for your database will
be real life information from the Internet Movie Database (IMDB).

## IMDB
The Internet Movie Database is a popular website containing information 
on every movie ever made. They also make a lot of their data publically 
available.

I went to this site:
https://datasets.imdbws.com/

and downloaded the names-basic, titles-basic, and titles-principal 
databases.

Explanations of the files can be found here:
https://www.imdb.com/interfaces/

The sheer amount of data was too much for our project, so I thinned it
out by limiting us to movies (not tv episodes or documentaries) created
between 2014 and 2019, inclusive.

## Data structure
Here's how the data is structured:

In the `titles.tsv` file, you'll find the names of all the movies
along with a unique movie identifier. For example, if I type the
following unix command, I can find Toy Story 4:

`grep "Toy Story 4" titles.tsv`

The result is

```
tt1979376       Toy Story 4     2019    100     Adventure,Animation,Comedy
```
This shows me that the movie's unique identifier is `tt1979376`, and that 
the movie came out in 2019.

I can then look up movie `tt1979376` in the `roles.tsv` file to see
who the main cast is:

```
grep tt1979376 roles.tsv
tt1979376       nm0566489       writer  \N
tt1979376       nm0000158       actor   ["Woody"]
tt1979376       nm0000741       actor   ["Buzz Lightyear"]
tt1979376       nm0001633       actress ["Bo Peep"]
tt1979376       nm0355024       actor   ["Forky"]
tt1979376       nm2155757       director        \N
tt1979376       nm0005124       writer  \N
tt1979376       nm0004056       writer  \N
tt1979376       nm1445746       writer  \N
tt1979376       nm0429069       writer  \N
```

So there are four lead acting roles in the movie. The first is an actor 
with unique identifier nm0000158 who plays the role of Woody. If 
I want to know the name of the actor with that identifier, I can check 
the third database:

```
grep nm0000158 names.tsv
nm0000158       Tom Hanks       1956    \N
```

That actor is Tom Hanks, born 1956.

## Data Files
The data files are stored in `/data/courses/ece_3822/current/project_5_data`.
Do *not* copy them to your local directory. Just access them directly
from the shared folder.

## Goal
Your goal is to make a data structure that can store and search this
information efficiently.

## Steps

Step 1: Create a data structure that can store all the movies. I should
be able to search this database for a movie name. If found, it will 
print the name of the movie and the year, otherwise it will say not 
found.

Step 2: Create a data structure that can store all the actors. I should
be able to search this datbase for an actor/actress name. If found, it 
will
print the name of the actor/actress and their year of birth (and death, 
if applicable).

Step 3: Create a data structure that lets me search for an actor/actress
and then print out all the movies they play a starring role in. For 
example, using the unix grep command, I can discover that Tom Hanks stars in:

```
tt1979376       nm0000158       actor   ["Woody"]
tt2980210       nm0000158       actor   ["Alan"]
tt3062096       nm0000158       actor   ["Robert Langdon"]
tt3224458       nm0000158       actor   ["Fred Rogers"]
tt3263904       nm0000158       actor   ["Chesley 'Sully' Sullenberger"]
tt3682448       nm0000158       actor   ["James B. Donovan"]
tt3760922       nm0000158       producer        \N
tt4287320       nm0000158       actor   ["Bailey"]
tt6294822       nm0000158       actor   ["Ben Bradlee"]
```

(remember this is just starring roles between 2014 and 2019; Tom's been 
busy)

Of course I would want to print the names and years of the movies, not 
their unique id numbers.

Step 4: (Optional but very cool) Create a search tool that takes
as input the names of two actors and returns the movies (if any) that
they appear in together.

## Notes
Use whatever data structures make sense to you. We have enough sample 
code floating around to handle every case. I expect you to design 
"intentionally" meaning that you make design choices that make sense 
for what you are trying to accomplish.

Remember we have tons of sample code from previous labs and projects, 
including how to read data from a text file. The "tsv" file format is 
"tab separated". If you are using the "split" command, you can specify 
a tab with "\t".

Feel free to code in C++ or Python.

Don't be discouraged if you can't get it all to work. I am not expecting
that everyone will successfully get this project working (but I'm 
keeping my fingers crossed!).

Finally, each data file has a header row. Obviously that doesn't 
contain any useful data.

## What to turn in:
All your code. Don't be afraid to split your code into multiple files.

A Makefile (if coding in C++)

A file named `design.txt` in which you explain the data structure(s) 
you've created and why. You can't just stuff everything into a vector 
and say "it was easy". That's a lousy and inefficient design! Explain 
your choices. In terms of length, I would expect this file would take 
2-3 minutes for me to read. Any longer and its too detailed (I want a
top-level explanation). Any shorter and its not detailed enough to be
useful.

## Submission
The submit script will submit everything in your project directory
except for any `.tsv` files. Make sure that your code directly
access the `.tsv` files from `/data/courses/ece_3822/project_5_data/`
and not from your home directory, because otherwise it won't run 
after it is submited.

## Due
Monday April 28th at midnight

## Questions
`iobeid@temple.edu`

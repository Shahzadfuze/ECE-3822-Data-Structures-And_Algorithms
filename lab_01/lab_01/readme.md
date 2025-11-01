# Lab 1

## Purpose
The purpose of Lab 1 is to practice using classes in both C++ and Python. I have
created some skeleton code which you are going to fill in and make functional.
The code creates a class called "books" for storing information about books.
Each book has properties: title, author, year, and pages. Each book also has a
display method as well as a `useless_fact()` method which returns a useless fact
about the book (defined as the square root of the product of the year and number
of pages). I am providing you with `lab_01.py` and `lab_01.cpp`, which you
should *not* edit. Instead you will edit `books.py` , `books.h` , `books.cpp` ,
and `Makefile` so that `lab_01.py` and `lab_01.cpp` can run properly.

## Steps
[1] Use the rsync command (or equivalent) to copy the code to your directory:
`rsync -rv $SHARE/lab_01 .`

[2] Edit `books.py` so that `lab_01.py` works as intended

[3] Edit `books.cpp` , `books.h` , and `Makefile` so that `lab_01.cpp` works as
intended

[4] Submit your assignment as you did in lab_00, using the `submit.py` command

## Expected Outcome
Both the Python and C++ implementations should return the exact same output:

<pre>
Title                         Author         Year   Pages  Useless Fact
Alice in Wonderland           Lewis Carroll  1865   112    457.03      
Fahrenheit 451                Ray Bradbury   1953   249    697.35      
Breakfast of Champions        Kurt Vonnegut  1973   303    773.19      
</pre>

## Due
Sunday 1/26/2025 at midnight

## Questions
`iobeid@temple.edu`
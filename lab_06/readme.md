# Lab 6

## Purpose
The purpose of this week's lab is to compare the execution times of three different
sort algorithms: bubblesort, heapsort, and comb sort. I have already written
the bubblesort and heapsort algorithms for you. For reference you can read
more about them if you want at the links here. You should read
Combsort in detail

[Bubblesort](https://en.wikipedia.org/wiki/Bubble_sort)  
[Heapsort](https://en.wikipedia.org/wiki/Heapsort)  
[Combsort](https://en.wikipedia.org/wiki/Comb_sort)

I have created a `base` sort class, which `bubl`, `heap`, and `comb`
inherit. The base class handles all the basic I/O. The inheriting
classes simply have to have the respective `sort` function.

The `main` code in `lab_06.py` creates random number arrays,
passes them to all three sorters, and measures the time and number
of swaps to sort the list. This process is repeated many times
and results are averaged. The code also tries sorting arrays of
different lengths.

## Steps
[1] Read about [combsort](https://en.wikipedia.org/wiki/Comb_sort).

[2] Look through all the `lab_06` code and try to understand what's there.
Make sure you understand what's happening with the inheritance, function
timing, and so on.

[3] Write the `comb` sort function

[4] Run `lab_06.py` and observe the times and swap counts for the
three algorithms. Verify that the times and swap counts increase as $N^2$ or $N\log N$ for Bubblesort and Heapsort, respectively.

[5] Create a file called `results.txt` where you provide a copy
of the output table created by `lab_06.py` and include a few
sentences explaining how Combsort compares to the other two. Can
you tell from the data what the average big-O sort time is for 
Combsort?

## Notes

Don't forget to document your code, including with the
comment block at the top of the file.

The submit script will only submit `comb.py`, and `results.txt`  

## Due
Sunday 3/30/2025 at midnight

## Questions
`iobeid@temple.edu`

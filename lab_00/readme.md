# Lab 00

## Purpose
The purpose of Lab 00 is to make sure you can log in and successfully submit an
assignment through the server.

## Steps
[1] Use the rsync command to make a copy of `$SHARE/lab_00` to your local
directory. To do so, open the terminal, `cd` to wherever you want in your local
directory tree, and type the command `rsync -rv $SHARE/lab_00 .` (make sure to
include the period `.` at the end of that command!)

[2] Edit `lab_00.py` so that it prints the average value of the data in
`data.txt`. Format your output to only show two significant digits. I know there
are many ways of getting Python to compute the average (including NumPy) but
stick to the structure I've provided.

[3] Also edit `lab_00.py` to include your name, date, and other comments at the
top of the file.

[4] Edit `lab_00.cpp` to print the average value of the data in `data.txt`.
Again, format your output to only show two significant digits. Also edit the
comment block at the top of the file appropriately.

[5] Submit your assignment as follows: open a terminal and `cd` into your
`lab_00` directory. Type `./submit.py`, which will automatically submit
`lab_00.py` and `lab_00.cpp` to me. You can check if your submission worked by
typing `./submit.py --list` . If for some reason you need to, you can always do
`./submit.py` again and it will just overwrite your previous submission.

## Due
Sunday 1/19/2024 at midnight

## Questions
`iobeid@temple.edu`

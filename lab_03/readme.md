# Lab 3

## Purpose
The purpose of Lab 2 is to implement FIR and IIR filters in Python.
We looked at FIR filters in class as an extension of circular buffers.
As will be explained below, an IIR filter is really just two FIR
filters, one filtering the inputs and one filtering the outputs.

## Background
A filter can be applied to a signal to change its properties. You might have heard
of _lowpass filtering_ to smooth a signal, for example. There are two main types
of digital filters, _FIR_ and _IIR_.

### FIR filter
An FIR (Finite Impuse Response) filter is provided with a list of numbers called 
_taps_. For each point in the input signal, the _N_ filter taps are multiplied 
against the _N_ most recent input values and then summed. For example, if your filter 
taps are

`taps = [0.1 , 0.3 , 0.2]`

and your input signal is

`x = [1,2,3,4,5,6,7]`

Then the output signal y is computed as:

`y[n] = 0.1x[n] + 0.3x[n-1] + 0.2x[n-2]`  
which in this case means:

```
y[0] = 0.1*1 + 0.3*0 + 0.2*0 = 0.1
y[1] = 0.1*2 + 0.3*1 + 0.2*0 = 0.5
y[2] = 0.1*3 + 0.3*2 + 0.2*1 = 1.1
y[3] = 0.1*4 + 0.3*3 + 0.2*2 = 1.7
y[4] = 0.1*5 + 0.3*4 + 0.2*3 = 2.3
etc
```

### IIR filter
An IIR filter is like two FIR filters connected together. One filters the previous inputs
and the other filters the previous outputs. There are two sets of taps, which I'll call $b$ and
$a$, because that's what they're always called in textbooks for some reason. Lets say our filter
taps are:

`b = [0.1 0.4, 0.3]`  
`a = [-0.1 0.6]`

Then the output `y[n]` is calculated as:

`y[n] = 0.1x[n] + 0.4x[n-1] + 0.3x[n-2] -0.1y[n-1] +0.6y[n-2]`

so if your input is  
`x = [1,2,3,4,5,6,7]`

then
```
y[0] = 0.1*1 + 0.4*0 + 0.3*0 -0.1*0     + 0.6*0     = 0.1
y[1] = 0.1*2 + 0.4*1 + 0.3*0 -0.1*0.1   + 0.6*0     = 0.59
y[2] = 0.1*3 + 0.4*2 + 0.3*1 -0.1*0.59  + 0.6*0.1   = 1.401
y[3] = 0.1*4 + 0.4*3 + 0.3*2 -0.1*1.401 + 0.6*0.59  = 2.414
y[4] = 0.1*5 + 0.4*4 + 0.3*3 -0.1*2.414 + 0.6*1.401 = 3.599
y[5] = 0.1*6 + 0.4*5 + 0.3*4 -0.1*3.599 + 0.6*2.414 = 4.888
y[6] = 0.1*7 + 0.4*6 + 0.3*5 -0.1*4.888 + 0.6*3.599 = 6.271
```

## Steps

[1] Copy all files to your local directory using `rsync -rv $SHARE/lab_03 .`

[2] Examine _but do not edit_ file `lab_03.py`. This file implements a circular
buffer and has some demonstration code to show that it works. You can run the program
using `python lab_03.py 0` to demonstrate the circular buffer. You can change the option
number to run the other test cases.

[3] Implement the FIR filter by creating a file called `FIR.py` that creates
a class called `FIR` which inherits `circ_buffer`. That class should have a constructor 
and a `get_filtered` method. Note that `FIR` must explicitly call the `circ_buffer` 
constructor and pass it the appropriate buffer size value. The syntax for calling base class constructor is detailed nicely [here](https://stackoverflow.com/questions/2399307/how-to-invoke-the-super-constructor-in-python).
 
Test your code using test cases 2, 3, and 4.

[4] Implement the IIR filter by creating a file called `IIR.py` that creates a class
called `IIR`. That class should _not_ inherit `circ_buffer`. Instead it should contain
two FIR filters. The IIR filter is initialized with a list of two sets of filter taps,
one for the input and one for the output values. See the test cases for clarity.

Test your code using test cases 5 and 6.

Plot your filtered data using Excel and try to determine what the filters do.
Write a short text file called `results.txt` that explains what kinds of filtering
each of the filters does.

Let me know if you have questions. Good luck!

## Submission
The submit script will only turn in `FIR.py` , `IIR.py`, and `results.txt`.

## Due
Sunday 2/16/2025 at midnight

## Questions
`iobeid@temple.edu`

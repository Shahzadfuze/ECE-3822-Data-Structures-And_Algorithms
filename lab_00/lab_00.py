'''
Lab 00

Description: <Computes the average of a array and displays the value with 2 sig figs>

@Author: <Shahzad Khan>
@Contact: <shahzadkhan@temple.edu>
@Date: <1/13/2025>

Example:
    This file can be run by typing
    <python lab_00.py>
'''

import sys

def compute_average(nums):
    # compute the average of a list of numbers of arbitrary length

    # input: array of integers
    # returns: the floating point average of those numbers

    # YOUR CODE HERE

    count = 0
    sum = 0
    for i in nums:
        sum += i
        count += 1
    avg = sum/count
        
    


    
    return avg

def display_value(val):
    # display a floating point number with two significant digits



    print(f"{val:0.2f}")

    
    # input: a single floating point value
    # returns: none

    # YOUR CODE HERE
    pass

def main(argv):

    # don't mess with this part
    filename = "/data/courses/ece_3822/current/lab_00/data.txt"
    if len(argv) > 1:
        filename = argv[1]

    # This is some demo code to show you how to read a list of integers out of a 
    # text file. There are other ways to do this but I like this one.
    with open(filename) as f:
        x = [int(line) for line in f]

    avg = compute_average(x)
    display_value(avg)    

if __name__=="__main__":
    main(sys.argv)

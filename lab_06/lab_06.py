##########################################
# imports
from random import sample
import datetime
from bubl import bubl
from heap import heap
from comb import comb

##########################################
# set loop variables
n_samples = [50, 100, 200, 500]#, 1000 , 2000]
n_trials  = 1000

##########################################
# define sort objects
x = bubl()
y = heap()
z = comb()

##########################################
# print table header
print("")
print(f"{'N':>7s}"  , end="")
print(f"{'heap/sw':>10s}{'bubl/sw':>10s}{'comb/sw':>10s}" , end="")
print(f"{'heap/ms':>10s}{'bubl/ms':>10s}{'comb/ms':>10s}" , end="")
print("")

##########################################
# main loop
for n in n_samples:
    # iterate over number of samples

    n_swaps_bubl = 0
    n_swaps_heap = 0
    n_swaps_comb = 0
    t_bubl , t_heap , t_comb = 0 , 0 , 0

    for _ in range(n_trials):
        # repeat so we can average results over trials

        x.reset()
        y.reset()
        z.reset()

        # generate list of numbers to sort
        values = sample( range(0,n) , n )

        # insert list of numbers into the sort objects
        x.insert(values)
        y.insert(values)
        z.insert(values)

        # sort the lists, measure elapsed time, update total number of swaps
        t0 = datetime.datetime.now()
        n_swaps_bubl += x.sort()
        t1 = datetime.datetime.now()
        n_swaps_heap += y.sort()
        t2 = datetime.datetime.now()
        n_swaps_comb += z.sort()
        t3 = datetime.datetime.now()

        #  update total elapsed time
        t_bubl += (t1-t0).microseconds / 1000 # convert to milliseconds
        t_heap += (t2-t1).microseconds / 1000 
        t_comb += (t3-t2).microseconds / 1000 

    # print one line of the table
    print(f"{n:7d}"                        , end="")
    print(f"{n_swaps_heap/n_trials:10.2f}" , end="")
    print(f"{n_swaps_bubl/n_trials:10.2f}" , end="")
    print(f"{n_swaps_comb/n_trials:10.2f}" , end="")
    print(f"{t_heap/n_trials:10.2f}"       , end="")
    print(f"{t_bubl/n_trials:10.2f}"       , end="")
    print(f"{t_comb/n_trials:10.2f}"       , end="")
    print("")
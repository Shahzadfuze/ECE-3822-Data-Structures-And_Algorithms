"""
    Lab 03 Main Code

    @Author: I. Obeid
    @Contact: iyad.obeid@temple.edu
    @Date: September 24, 2024

    Usage:
        python lab_03.py [option]
        where option is 0, 1, 2, 3, or 4 as follows: 
        0 - run the circular buffer demo code
        1 - run the moving average buffer code
        2 - apply filter 0 to the noisy data
        3 - apply filter 1 to the noisy data
        4 - apply filter 2 to the noisy data    
"""

from circ_buffer import circ_buffer
import argparse
from FIR import FIR
from IIR import IIR

#----------------------------------------------------------------------
#-- Define the filter taps. These are the values that define each
#-- filter. Do not modify these
#----------------------------------------------------------------------
global taps
taps = {}
taps['filt_0'] = [-0.03492495, -0.03706419,  0.02092361,  0.13680553,  0.2562279 ,
       0.307103  ,  0.2562279 ,  0.13680553,  0.02092361, -0.03706419,
     -0.03492495]



taps['filt_1'] = [0.26201958, 0.32574517, 0.26201958]

taps['filt_2'] = [ 0.03492495,  0.03706419, -0.02092361, -0.13680553, -0.2562279 ,
        0.692897  , -0.2562279 , -0.13680553, -0.02092361,  0.03706419,
        0.03492495]

taps['filt_3'] = [ [0.02290313, -0.01245771,  0.03631076, -0.01245771,  0.02290313] , [2.92986231, -3.75354709,  2.38136016, -0.63847478] ]
taps['filt_4'] = [ [0.08487107, -0.19305596,  0.26138438, -0.19305596,  0.08487107] , [-0.90129778, -1.40892419, -0.77224206, -0.41899562] ]

#----------------------------------------------------------------------
class moving_average_filter(circ_buffer):
    '''moving average filter class
    
    This class implements a moving average filter.
    It inherits circ_buffer and adds the <get_average>
    method
    '''
    def get_average(self):
        '''get buffer average value
        
        Args:
            none
        Returns:
            float:  buffer average value
        '''

        sum = 0
        for i in range(self.get_buff_size()):
            sum += self.get_element(i)
        return sum / self.get_buff_size()
#----------------------------------------------------------------------

#----------------------------------------------------------------------
def apply_FIR_filter(taps , filename_out):
    '''Apply FIR filter to <data_noisy.txt>

    ### Params
    * taps: filter taps (list)
    * filename_out: output file name (string)
    
    ### Returns
    * none
    '''
        
    filter = FIR(taps)
    
    file_in  = open("/data/courses/ece_3822/current/lab_03/data_noisy.txt",'r')
    file_out = open(filename_out,'w')

    for line in file_in:
        filter.insert( float(line) )
        y = filter.get_filtered()
        file_out.write(f"{y:0.2f}\n")
#----------------------------------------------------------------------

#----------------------------------------------------------------------
def apply_IIR_filter(taps , filename_out):
    '''Apply IIR filter to <data_noisy.txt>
    
    ### Params
    * taps: two sets of filter taps - this variable is a list containing two lists of taps
    * filename_out: output file name (string)
    
    ### Returns
    * none
    '''

    filter = IIR(taps)
    file_in  = open("/data/courses/ece_3822/current/lab_03/data_noisy.txt",'r')
    file_out = open(filename_out,'w')

    for line in file_in:
        filter.insert( float(line) )
        y = filter.get_filtered()
        file_out.write(f"{y:0.2f}\n")
#----------------------------------------------------------------------

#----------------------------------------------------------------------
def demonstrate_moving_average():
    '''Demonstrate moving average filter
    
    This function creates a filter from the moving_average_filter
    class (which inherits circ_buffer) and uses it to filter noisy 
    data. This is nearly identical to what we did in class on Friday 
    Sept 15 (week 3)

    ### Params
    * none

    ### Returns
    *none
    '''

    filter = moving_average_filter(5)
    
    file_in  = open("/data/courses/ece_3822/current/lab_03/data_noisy.txt",'r')
    file_out = open("output_moving_avg.txt",'w')

    for line in file_in:
        filter.insert( float(line) )
        y = filter.get_average()
        file_out.write(f"{y:0.2f}\n")
#----------------------------------------------------------------------

#----------------------------------------------------------------------
def demonstrate_circular_buffer():
    '''Demonstrates use of circular buffer base class

    This is similar to what we did in C++ during week 3
    
    ### Params
    * none

    ### Returns
    * none
    '''

    myBuff = circ_buffer(5)
    myBuff.insert(8)
    myBuff.insert(6)
    myBuff.insert(7)
    myBuff.insert(5)
    myBuff.insert(3)
    myBuff.insert(0)
    myBuff.insert(9)
    
    print( myBuff.get_element(0) )
    print( myBuff.get_element(1) )
    print( myBuff.get_element(2) )
#----------------------------------------------------------------------

#----------------------------------------------------------------------
def parse_inputs():
    '''parse command line inputs

    Do not edit this function

    ### Params
    * none

    ### Returns
    * parsed arguments
    '''
    
    parser = argparse.ArgumentParser(
    prog='Lab 3',
    description='Lab 3 main function')
    
    parser.add_argument('option' , help='0,1,2,3,4,5')

    args = parser.parse_args()
    return args
#----------------------------------------------------------------------

#----------------------------------------------------------------------
def main():
    ''' main function for running Lab 3
    '''
    global taps

    args = parse_inputs()

    if   args.option == '0': demonstrate_circular_buffer()
    elif args.option == '1': demonstrate_moving_average()
    elif args.option == '2': apply_FIR_filter(taps['filt_0'] , "output_filter_0.txt")
    elif args.option == '3': apply_FIR_filter(taps['filt_1'] , "output_filter_1.txt")
    elif args.option == '4': apply_FIR_filter(taps['filt_2'] , "output_filter_2.txt")
    elif args.option == '5': apply_IIR_filter(taps['filt_3'] , "output_filter_3.txt")
    elif args.option == '6': apply_IIR_filter(taps['filt_4'] , "output_filter_4.txt")

    else:
        print("error: select option 0, 1, 2, 3, 4, or 5")
        exit

#----------------------------------------------------------------------

main()

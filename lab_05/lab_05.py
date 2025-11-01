''' lab_06.py

    Shahzad Khan
    tuk44487@temple.edu
    3/13/2025

    Description:
    Implement a database that contains hash tables of students organized by first name, last name,
    and id.
    
    The following classes already exist:
        <linked_list>
        <student>
        <hash_table_base>
        <hash_table_firstname>

    The following classes have to be completed:
        <hash_table_lastname>
        <hash_table_id>
        <db>

    Usage:
    python lab_06.py TESTCASE
        where TESTCASE is either 1 or 2
    
'''

import argparse

#####################################################################
## Basic linked list class
#####################################################################
class linked_list:
    '''standard linked list class'''

    # READ AND UNDERSTAND, BUT DO NOT EDIT THIS FUNCTION

    class node:
        def __init__(self,data=None,next=None):
            self.data = data
            self.next = next
    
    def __init__(self):
        self.head = None

    def insert(self,value):
        new_node = self.node(data=value,next=self.head)
        self.head = new_node

    def lookup(self,target=None,field=None,disp=False):
        curr_ptr = self.head
        ret_val = []

        while (curr_ptr is not None):
            if hasattr(curr_ptr.data,field) and \
                getattr(curr_ptr.data,field) == target:
                    ret_val.append(curr_ptr.data)
            curr_ptr = curr_ptr.next

        if disp and ret_val:
            for r in ret_val:
                r.display()
        elif disp and not ret_val:
            print(field, "=" , target, " not found")

        return ret_val


#####################################################################
## Student class
#####################################################################
class student:
    '''class of <student>'''

    def __init__(self,firstname="",lastname="",id=0,major=""):
        self.firstname = firstname
        self.lastname  = lastname
        self.id = id
        self.major = major
    def __repr__(self):
        return f"{self.firstname} {self.lastname} {self.id} {self.major}"
    def display(self):
        print(self.__repr__())


#####################################################################
# base hash table class, designed to be inherited by other classes
#####################################################################
class hash_table_base:
    '''basic hash table designed to be inherited'''

    # READ AND UNDERSTAND, BUT DO NOT EDIT THIS FUNCTION

    class node:
        def __init__(self,k,v):
            self.key , self.value = k,v

    def __init__(self , array_len = 50):
        self.buffer = [linked_list() for _ in range(array_len)]
        self.array_len = array_len

    def insert(self,value):
        key = self.extract_key(value)
        index = self.hash_function(key)
        self.buffer[index].insert( self.node(key,value) )

    def lookup(self,key = None , disp=False):
        index = self.hash_function(key)
        retValTmp = self.buffer[index].lookup(target=key, field='key')
        retVal = [r.value for r in retValTmp]

        if disp:
            print("Search of " , key , " found:")
            if retVal:
                for v in retVal:
                    print("\t",end="")
                    print(v)
            else: print("\tNothing")
        return retVal
        
    # must be defined by the inheriting class
    def hash_function(self,key  ): return None   
    def extract_key  (self,value): return None


#####################################################################
## Hash table for hashing by first name - inherits hash_table_base
#####################################################################
class hash_table_firstname (hash_table_base):
    '''
    hash table of students organized by first name
    inherits <hash_table_base>
    '''

    def __init__(self,array_len = 50):
        super().__init__(array_len)

    def extract_key(self,student):
        return student.firstname

    def hash_function(self, key):
        s = 0
        for ch in key:
            s += ord(ch)
        return s%self.array_len


#####################################################################
## Hash table for hashing by last name
#####################################################################
class hash_table_lastname (hash_table_base):
    '''hash table of students organized by last name'''

    def __init__(self,array_len = 50):
        super().__init__(array_len)


        ## Basiclly copying the code from the first name function 
        
    def extract_key(self,student):
        # YOUR CODE HERE
        return student.lastname

    ## Using the same hashing function for the first name 
    
    def hash_function(self, key):
        # YOUR CODE HERE
        s = 0
        for ch in key:
            s +=ord(ch)
        return s%self.array_len


#####################################################################
## Hash table for hashing by student id number
#####################################################################
class hash_table_id (hash_table_base):
    '''hash table of students organized by id number'''
    
    def __init__(self,array_len = 50):
        super().__init__(array_len)

    def extract_key(self,student):
        # YOUR CODE HERE
        return student.id

    ## Instead of copying the name we just do the module of the key
    ## to put it inside the list without changing the aski value 

    
    def hash_function(self, key):
        # YOUR CODE HERE
        return key % self.array_len


#####################################################################
## Database class for combining multiple hash tables
#####################################################################
class db:
    '''database class that holds and manages multiple hash tables'''


    ## Just assigning the table to different variables
    
    
    def __init__(self):
        self.table_f_name = hash_table_firstname()
        self.table_l_name = hash_table_lastname()
        self.table_id = hash_table_id() 


    def insert(self, student):

        ## Inserting the student into the tables 
        
        self.table_f_name.insert(student)
        self.table_l_name.insert(student)
        self.table_id.insert(student)

    def lookup(self, first=None, last=None, id=None, disp=False):

        ## Going through the table and using recusion to do the lookup
        ## Kind of how we used it with a binary search tree. 
        
        results = []

        if first:
            results = self.table_f_name.lookup(first, disp)
        elif last:
            results = self.table_l_name.lookup(last, disp)
        elif id:
            results = self.table_id.lookup(id, disp)


        return results

    



#####################################################################
## Test Case 1
#####################################################################
def test_case_1():
    '''Test Case 1: test individual hash tables'''

    # READ AND UNDERSTAND, BUT DO NOT EDIT THIS FUNCTION

    table_f_name = hash_table_firstname()
    table_l_name = hash_table_lastname()
    table_id     = hash_table_id()

    st1 = student( "Bob"  , "Smith" , 123 , "ECE"     )
    st2 = student( "Jeff" , "Smith" , 456 , "ME"      )
    st3 = student( "Jeff" , "Bezos" , 492 , "CompSci" )

    table_f_name.insert(st1)
    table_f_name.insert(st2)
    table_f_name.insert(st3)

    table_l_name.insert(st1)
    table_l_name.insert(st2)
    table_l_name.insert(st3)

    table_id.insert(st1)
    table_id.insert(st2)
    table_id.insert(st3)

    print("\nLookup ID = 123")
    table_id.lookup(123,disp=True)    

    print("\nLookup firstname = Jeff")
    table_f_name.lookup("Jeff",disp=True)

    print("\nLookup lastname = Bezos")
    table_l_name.lookup("Bezos",disp=True)

    print("\nLookup lastname = Smith")
    table_l_name.lookup("Smith",disp=True)

    print("\nLookup ID = 987")
    table_id.lookup(987,disp=True)

    print("")


    return


#####################################################################
## Test Case 2
#####################################################################
def test_case_2():
    '''Test Case 2: test database'''

    # READ AND UNDERSTAND, BUT DO NOT EDIT THIS FUNCTION

    my_db = db()

    my_db.insert( student( "Bob"  , "Smith" , 123 , "ECE"     ) )
    my_db.insert( student( "Jeff" , "Smith" , 456 , "ME"      ) )
    my_db.insert( student( "Jeff" , "Bezos" , 492 , "CompSci" ) )

    my_db.lookup(last="Smith" , disp=True)
    my_db.lookup(first="Bob"  , disp=True)
    my_db.lookup(id=989       , disp=True)

    return


#####################################################################
## Parse command line inputs
#####################################################################
def parse_inputs():
    '''parse command line inputs

    Do not edit this function

    ### Params
    * none

    ### Returns
    * parsed arguments
    '''
    
    # DO NOT EDIT THIS FUNCTION

    parser = argparse.ArgumentParser(
    prog='Lab 5',
    description='Lab 5 Main Code')
    
    parser.add_argument('test_case' , help='1,2')

    args = parser.parse_args()
    return args


#####################################################################
## Main
#####################################################################
def main():

    # DO NOT EDIT THIS FUNCTION

    args = parse_inputs()
    if args.test_case == '1':
        test_case_1()
        return

    if args.test_case == '2':
        test_case_2()
        return

    print("\n>>>>> Invalid test case specified at commandline <<<<< \n")
    raise SystemError


if __name__=="__main__":
    main()

''' lab_04.py

   YOUR NAME HERE
   YOUR EMAIL ADDRESS
   DATE
   
   BRIEF DESCRIPTION OF FILE CONTENTS

   Usage:
   GIVE COMMANDS FOR HOW TO COMPILE AND RUN

   Answers to questions:
   
'''

import sys

class bst:

    class node:
        def __init__(self,val):
            self.payload = val
            self.left  = None
            self.right = None

    def __init__(self):
        self.root = None
        self.counter = [0,0,0]
    
    def insert_recursive(self,root,val):
        if root is None:
            return self.node(val)
        if val > root.payload:
            root.right = self.insert_recursive(root.right , val)
        else:
            root.left = self.insert_recursive(root.left , val)
        return root

    def insert(self,val):
        self.root = self.insert_recursive(self.root,val)

    def count(self,curr_node = None):
        '''
        WRITE THIS FUNCTION
        THE GOAL IS TO COUNT HOW MANY NODES HAVE ZERO, ONE, OR TWO CHILD NODES
        STORE YOUR RESULT IN CNT_0, CNT_1, and CNT_2 (MEMBER VARS OF THE BST CLASS) 

        RECURSION IS PROBABLY THE EASIEST WAY TO GO
        '''

        if (curr_node == None):
            # if count is called without an input var, curr_node will be None
            # which means count is being called directly from testcase (not recursively).
            # in this case, initialize curr_node to root and set the count values = 0
            curr_node = self.root
            self.counter = [0,0,0]

        if (curr_node == None):
            return

        # YOUR CODE HERE     

        child = 0;


        if(curr_node.left is not None):
            child = child + 1
            self.count(curr_node.left)


        if(curr_node.right is not None):
            child = child + 1
            self.count(curr_node.right)

        if (child == 0):
            self.counter[0] += 1

        if (child == 1):
            self.counter[1] += 1

        if (child == 2):
            self.counter[2] += 1

        








        
    def print_count(self):
        print("Nodes with 0 children: " , self.counter[0])
        print("Nodes with 1 children: " , self.counter[1])
        print("Nodes with 2 children: " , self.counter[2])
        print("")


def testcase_0():
    print("\nTestcase 0")
    print("---------------")
    x = bst()
    x.insert(8)
    x.insert(6)
    x.insert(7)
    x.insert(9)
    x.count()
    x.print_count()

def testcase_1():
    print("\nTestcase 1")
    print("---------------")
    x = bst()
    x.insert(9)
    x.insert(8)
    x.insert(7)
    x.insert(6)
    x.count()
    x.print_count()

def testcase_2():
    print("\nTestcase 2")
    print("---------------")
    x = bst()

    with open("/data/courses/ece_3822/current/lab_04/data.txt") as f:
        for str in f.readlines():
            x.insert( int(str) )

    x.count()
    x.print_count()


def main(argv):
    testcase_0()
    testcase_1()
    testcase_2()
    

if __name__ == "__main__":
    main(sys.argv)

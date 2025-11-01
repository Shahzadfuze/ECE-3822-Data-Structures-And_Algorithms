# note -> delete the "pass" statements. Those are placeholders
# until you replace them with actual code

# Every function prototype is empty - fill it with whatever you think
# is appropriate

# Add a one or two-line comment for each function

import math

class book:
    
    def __init__(self, t="",a="",y=0,p=0):
        # This is the constructor where will will put all variables in memory
        # I added default values so there wouldn't be any problems
        # Using self to tell python that we are talking about the variable in the
        # class and assigning them to the input variables
        self.title = t
        self.author = a
        self.year = y
        self.pages = p


    def set_title(self, n):
        #  simply setting the name to the variable it wants to be set in
        #
        self.title = n

    def set_author(self, a):
        #simply setting the author to the variable it wants to be set in
        #
        self.author = a
    
    def set_year(self, y):
        #simply setting the year to the variable it wants to be set in
        #
        self.year = y
    
    def set_pages(self, p):
        #simply setting the pages to the variable it wants to be set in
        #
        self.pages = p
    
    def useless_fact(self):
        # Returning a useless fact like 1
        # adding self in there because it is apart of the books class

        return math.sqrt(self.pages * self.year)


    # do not edit
    def display(self):
        str = \
            f"{self.title:30s}"     + \
            f"{self.author:15s}"    + \
            f"{self.year:<7d}"      + \
            f"{self.pages:<7d}"     + \
            f"{self.useless_fact():<12.2f}"
        print(str)

# do not edit
def display_header():
    header = \
        f"{'Title':30s}"    +\
        f"{'Author':15s}"   +\
        f"{'Year':7s}"      +\
        f"{'Pages':7s}"     +\
        f"{'Useless Fact':12s}"
    print("")
    print(header)

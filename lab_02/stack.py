class stack:



    # Shahzad Khan
    # 1/30/2025
    # shahzadkhan@temple.edu
    # run python queue.py

    #------------------------------------------------------------



    
    '''
    Implement a stack class with a fixed maximum buffer size.

    A stack is a Last In First Out (LIFO) structure. The
    most recent element to be pushed to the stack is "on top"
    and therefore is the first item to get popped off the stack.

    You cannot push to a full stack. If the stack is full, the
    push operation should just do nothing.

    You cannot pop from an empty stack. If the stack is empty,
    the pop operation should return <None>

    Don't change main.

    You can add helper methods to the class if you like.

    The <pass> commands are placeholders. Replace them with your
    code
    '''

    def __init__(self , buffsize = 10):
        # constructor
        # optional input buffsize sets the fixed size of the 
        # buffer. default value is 10

        self.buffersize = buffsize
        self.buffer = [None for _ in range(buffsize)]
        self.n_elements = 0

    def push(self,value):
        # push <value> onto the stack. If the stack is full,
        # do nothing
        if self.n_elements >= self.buffersize:
            return 
        
        self.buffer.insert(self.n_elements, value)
#        print(self.buffer[self.n_elements])        
        self.n_elements += 1

    def pop(self):
        # pop the top value from the stack and return it. If the
        # stack is empty, return <None>

        if self.n_elements <= 0:
            return 
        
    
        self.n_elements -= 1
        value = self.buffer[self.n_elements]
        self.buffer[self.n_elements] = None
        return value
        
    

    def count(self):
        #  return the number of valid elements in the stack
        return self.n_elements

def main():

    mystack = stack(buffsize=5)
    mystack.push(8)
    mystack.push(6)
    mystack.push(7)

    print( mystack.count() )        # should print 3
    print( mystack.pop() )          # should print 7
    print( mystack.pop() )          # should print 6
    print( mystack.count() )        # should print 1
    print( mystack.pop() )          # should print 8
    print( mystack.pop() )          # should print None
    print( mystack.count() )        # should print 0

    mystack.push(8)
    mystack.push(6)
    mystack.push(7)
    mystack.push(5)
    mystack.push(3)
    mystack.push(0)

    print( mystack.count() )        # should print 5
    print( mystack.pop() )          # should print 3

if __name__ == "__main__":
    main()

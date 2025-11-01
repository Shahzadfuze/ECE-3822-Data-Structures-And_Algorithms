class queue:

    # Shahzad Khan
    # 1/30/2025
    # shahzadkhan@temple.edu
    # run python queue.py

    #------------------------------------------------------------
    
    '''
    Implement a queue class with a fixed maximum buffer size.

    A queue is a First In First Out (FIFO) structure. The
    most recent element to be pushed to the queue is "at the back"
    and therefore is the last item to get popped off the queue.

    You cannot push to a full queue. If the queue is full, the
    push operation should just do nothing.

    You cannot pop from an empty queue. If the queue is empty,
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
        self.head = 0
        self.tail = 0 

    def push(self,value):
        # push <value> onto the queue. If the queue is full,
        # do nothing
        if self.n_elements >= self.buffersize:
            return
        self.buffer[self.tail] = value
        self.tail = (self.tail+1) % self.buffersize
        self.n_elements += 1
        

    def pop(self):
        # pop the top value from the queue and return it. If the
        # queue is empty, return <None>
        if self.n_elements <= 0:
            return print("Nuh uh")
        value = self.buffer[self.head]

        self.buffer[self.head] = None
        self.head = (self.head+1) % self.buffersize
        self.n_elements -= 1
        return value

    def count(self):
        #  return the number of valid elements in the queue
        return self.n_elements

def main():

    myqueue = queue(buffsize=5)
    myqueue.push(8)
    myqueue.push(6)
    myqueue.push(7)

    print( myqueue.count() )        # should print 3
    print( myqueue.pop() )          # should print 8
    print( myqueue.pop() )          # should print 6

    myqueue.push(5)
    print( myqueue.pop() )          # should print 7

    print( myqueue.count() )        # should print 1

    print( myqueue.pop() )          # should print 5
    print( myqueue.pop() )          # should print None
    print( myqueue.count() )        # should print 0

    myqueue.push(8)
    myqueue.push(6)
    myqueue.push(7)
    myqueue.push(5)
    myqueue.push(3)
    myqueue.push(0)

    print( myqueue.count() )        # should print 5
    print( myqueue.pop() )          # should print 8

if __name__ == "__main__":
    main()

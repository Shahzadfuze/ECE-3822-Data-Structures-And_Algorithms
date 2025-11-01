from abc import ABC , abstractmethod

class base (ABC):

    def __init__(self):
        self.buffer = []
        self.reset()

    def reset(self):
        self.n_swaps = 0
        self.values = None

    def insert(self,v):
        self.buffer = v.copy()

    def swap(self,i,j):
        self.buffer[i] , self.buffer[j] = self.buffer[j] , self.buffer[i]
        self.n_swaps += 1

    # this means that the inheriting class must have a <sort> function
    @abstractmethod
    def sort(self):
        pass

    def display(self):
        for value in self.buffer:
            print(value, end=" ")
        print("")

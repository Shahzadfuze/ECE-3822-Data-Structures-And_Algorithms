from base import base

class bubl(base):

    def sort(self):
        n_values = len(self.buffer)
 
        for i in range(n_values):
            for j in range(n_values-1 , i , -1):
 
                if self.buffer[j-1] > self.buffer[j]:
                    self.swap(j-1,j)
 
        return self.n_swaps                

from base import base

class heap (base):

    def parent(self,i):
        return (i-1)//2

    def bubble_up(self):
        i = len(self.buffer)-1
        while ( i > 0 ):
            i_parent = self.parent(i)
            if self.buffer[i] > self.buffer[ i_parent ]:
                self.swap( i , i_parent )
                i = i_parent
            else:
                break

    def left (self,i): return 2*i + 1
    def right(self,i): return 2*i + 2

    def count_valid_children(self,i,j):
        if   j < len(self.buffer): return 2
        elif i < len(self.buffer): return 1
        return 0

    def argmax(self,i,j):
        if self.buffer[i] >= self.buffer[j] : return i
        return j

    def bubble_down(self):
        i = 0

        while (True):
            i_left  = self.left(i)
            i_right = self.right(i)

            n_valid_children = self.count_valid_children(i_left,i_right)

            if n_valid_children == 0: break
            if n_valid_children == 1: i_largest_child = i_left
            if n_valid_children == 2:
                i_largest_child = self.argmax(i_left,i_right)
            if self.buffer[i] < self.buffer[i_largest_child]:
                self.swap(i , i_largest_child)
                i = i_largest_child
            else:
                break

    def sort(self):
        self.values = self.buffer
        self.buffer = []

        # insert values to create the heap
        for value in self.values:
            self.buffer.append(value)
            self.bubble_up()

        # pop values to sort the heap
        j = len(self.values)-1
        srtd = []
        for i in range(len(self.values)):
            srtd.append(self.buffer[0])
            self.swap(0,j)
            self.buffer=self.buffer[0:-1]
            j -= 1
            self.bubble_down()

        self.buffer = srtd[::-1]

        return self.n_swaps

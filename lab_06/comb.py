from base import base

class comb (base):

  gap = 0
  shrink = 1.3
  sorted = False
  
  def sort(self):
      self.values = self.buffer
      self.gap = len(self.values)
      self.sorted = False
      self.n_swaps = 0

      # Main comb sort loop
      while not self.sorted:
        # Update the gap
        self.gap = int(self.gap / self.shrink)
        if self.gap <= 1:
            self.gap = 1
            self.sorted = True
            
            # Compare and swap elements
        for i in range(len(self.values) - self.gap):
            if self.values[i] > self.values[i + self.gap]:
                self.swap(i, i + self.gap)
                self.sorted = False
                self.n_swaps += 1
                    
        return self.n_swaps

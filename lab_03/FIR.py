from circ_buffer import circ_buffer

class FIR(circ_buffer):
    def __init__(self,taps: list):

        buffsize = len(taps)
        super().__init__(buffsize)
        self.taps = taps
        

    def get_filtered(self):
        filtered_value = 0

        for i in range(len(self.taps)):
            h = self.taps[i]
            x = self.get_element(i)
            filtered_value += h * x

        return filtered_value
    

    

        

from FIR import FIR



class IIR():
    def __init__(self, taps: list):
        self.b = taps[0];
        self.a = taps[1];

        self.input_filter = FIR(self.b)
        self.output_filter = FIR(self.a)
        self.output_buffer = [0] * len(self.a) # Initialize output buffer




    def get_filtered(self):
        x = self.input_filter.get_element(0)  # Current input
        filtered_input = self.input_filter.get_filtered()
        
        filtered_output = 0
        for i in range(len(self.a)):
            filtered_output -= self.a[i] * self.output_buffer[i] # Note the negative sign
            
        y = filtered_input + filtered_output
            
        # Update output buffer (circularly)
        for i in range(len(self.a) - 1, 0, -1):
            self.output_buffer[i] = self.output_buffer[i - 1]
            self.output_buffer[0] = y
        
        return y

    def insert(self, x):
        self.input_filter.insert(x)

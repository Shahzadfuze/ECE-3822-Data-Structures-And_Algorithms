''' lab_07.py


    Shahzad Khan
    tuk44487@temple.edu
    4/6/2025

    Description:
    Implement a breadth-first search to determine if two nodes are connected

    To Do:
    Complete function <are_connected()>        

    Usage:
    python lab_07.py OPT SRC DST
        where 
        OPT is 0, 1, or 2 (corresponding to file_0.txt, file_1.txt, or file_2.txt)
        SRC is the number of the source node
        DST is the number of the destination node

    example:
    python lab_07.py 1 3 0
        tests if there is a connection between nodes 3 and 0 in the graph described by file_1.txt
    
'''

from argparse import ArgumentParser
import os

####################### LOAD_GRAPH() ##################################################
def load_graph(opt:int) -> list :
    '''Loads the graph from file. The first <size> values
    in the array show all the nodes that the first node (A) can
    connect to. The second <size> values show all the nodes that the
    second node (B) can connect to, etc.
    Assume that Connections are unidirectional and unweighted.

    @params: opt    select graph number to load from file
    '''

    #  pick the file
    if   opt==0: size , fname = 3  , "file_0.txt"
    elif opt==1: size , fname = 6  , "file_1.txt"
    elif opt==2: size , fname = 10 , "file_2.txt"

    # prepend directory
    fullfilename = os.path.join(os.environ['SHARE'],'lab_07',fname)

    # init the graph with zeros
    graph = [[0 for _ in range(size)] for _ in range(size)]

    # read the values from the file into the graph
    with open(fullfilename) as f:
        for i in range(size):
            for j in range(size):
                graph[j][i] = int(f.readline())

    # return the graph
    return graph


####################### ARE_CONNECTED() ##############################################
def are_connected(graph:list, src:int , dst:int , disp:bool=False) ->bool:
    '''Determine whether there is a pathway from node <src> to
    node <dst>. Edge weights are either 0 (no connection) or 1 (connection).
    Optional input variable <disp> prints the result if True.
    Returns True if there is a pathway from src to dst.
    '''
    
    # init return value
    connected = False

    # YOUR CODE HERE

    visited = []               # Track visited nodes
    queue = deque([src])       # Start with the source node

    while queue:
        current = queue.popleft()
        
        if current == dst:
            if disp:
                print(f"Node {src} is connected to Node {dst}")
                return True
            
            if current not in visited:
                visited.append(current)
                for neighbor, is_connected in enumerate(graph[current]):
                    if is_connected and neighbor not in visited and neighbor not in queue:
                        queue.append(neighbor)
                                                                                                                                                              


    
    if disp:
        print(f"Node {src} {'is' if connected else 'is not'} connected to Node {dst}")

    #  return connection status (true/false)
    return connected


####################### DISPLAY() ####################################################
def display(graph:list) -> None:
    '''Displays the graph as a matrix. Row 0 shows all the places that 
    the 0th node (A) can connect to. Row 1 shows all the places that the 1st
    node (B) can connect to (etc).
    
    You don't need this function to solve the lab but you might find it helpful
    to visualize the matrix.
    '''

    s = len(graph)
    src_txt = "SRC"
    print("")
    print("      DST")
    print("      ",end="")
    for i in range(s):
        print(i,end=" ")
    print("")

    print("     ",end="")
    for i in range(s):
        print("--",end="")
    print("")

    for j in range(s):
        if j<3: print(src_txt[j],end=" ")
        else: print("  ",end="")
        print(j,"|",end=" ")
        for i in range(s):
            print(graph[j][i],end=" ")
        print("")

####################### GET_OPTS() ###################################################
def get_opts() -> int:
    '''Retrieve commandline argument -> specify either 0, 1, or 2
    to determine which matrix gets loaded from file
    '''
    sizes = [3,6,10]

    # set up parser
    parser = ArgumentParser()
    parser.add_argument("opt",help="Matrix Number")
    parser.add_argument("src",help="Source Node")
    parser.add_argument("dst",help="Destination Node")

    # retrieve commandline arguments
    opts = parser.parse_args()
    opt  = int(opts.opt)
    src  = int(opts.src)
    dst  = int(opts.dst)

    # check that commandline arguements are in appropriate ranges
    if not opt in [0,1,2]:
        raise ValueError("Specify matrix 0, 1, or 2")

    if not src in list(range(sizes[opt])):
        raise ValueError(f"Source node must be an integer between 0 and {sizes[opt]-1}")    

    if not dst in list(range(sizes[opt])):
        raise ValueError(f"Destination node must be an integer between 0 and {sizes[opt]-1}")    

    # return commandline arguements
    return opt , src , dst


####################### MAIN() #######################################################
def main():
    '''Main Function'''

    opt , src , dst = get_opts()
    graph = load_graph(opt)
    are_connected(graph,src,dst,True)

main()

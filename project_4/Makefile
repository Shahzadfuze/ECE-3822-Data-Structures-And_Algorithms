# file: 
#
# Note that this make file uses "-g" to compile and link "debug".
#

# define a target for the application
#
all: project_4.exe

# define a target to link the application
#
project_4.exe: project_4.o
	g++ -g - project_4.o  -o project_4.exe

# define targets to compile the source code
#
project_4.o: project_4.cpp example.h Makefile
	g++ -g -c project_4.cpp -o project_4.o

# define a target to clean the directory
#
clean:
	rm -f project_4.o project_4.exe

#
# end of file



# file: 
#
# Note that this make file uses "-g" to compile and link "debug".
#

# define a target for the application
#
all: main.exe

# define a target to link the application
#
main.exe: main.o main_00.o
	g++ -g -lm main.o main_00.o -o main.exe

# define targets to compile the source code
#
main.o: main.cc exampleh Makefile
	g++ -g -c main.cc -o main.o

main_00.o: main_00.cc example.h Makefile
	g++ -g -c main_00.cc -o main_00.o

# define a target to clean the directory
#
clean:
	rm -f main.o main_00.o main.exe

#
# end of file



# This is a partial makefile. Fill in the rest as needed


# Added books.o to the make file to make everything work 
#


lab_01: lab_01.o books.o
	g++ -g lab_01.o books.o -o lab_01


lab_01.o: lab_01.cpp books.h Makefile
	g++ -c lab_01.cpp -o lab_01.o

books.o: books.cpp books.h Makefile
	g++ -c books.cpp -o books.o


clean:
	rm -f *.o lab_01

all: lab_01

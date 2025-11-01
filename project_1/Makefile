# Do not edit unless you're just adding another testcase file

CC = g++
CFLAGS = -std=c++11
INCL = ${SHARE}/include
LIBS = ${SHARE}/include
OBJ = obj

debug: CFLAGS += -g
debug: clean
debug: all

# compile the four test case source files into object code
obj/test_case_1.o: src/test_case_1.cpp
	$(CC) $(CFLAGS) -I$(INCL) -c src/test_case_1.cpp -o $@
obj/test_case_2.o: src/test_case_2.cpp
	$(CC) $(CFLAGS) -I$(INCL) -c src/test_case_2.cpp -o $@
obj/test_case_3.o: src/test_case_3.cpp
	$(CC) $(CFLAGS) -I$(INCL) -c src/test_case_3.cpp -o $@
obj/test_case_4.o: src/test_case_4.cpp
	$(CC) $(CFLAGS) -I$(INCL) -c src/test_case_4.cpp -o $@

obj/player.o: src/player.cpp src/player.h
	$(CC) $(CFLAGS) -I$(INCL) -c src/player.cpp -o $@
obj/team.o: src/team.cpp src/team.h
	$(CC) $(CFLAGS) -I$(INCL) -c src/team.cpp -o $@

obj/proj_1.o: proj_1.cpp
	$(CC) $(CFLAGS) -I$(INCL) -c proj_1.cpp -o $@

proj_1: obj/proj_1.o obj/test_case_1.o obj/test_case_2.o obj/test_case_3.o obj/test_case_4.o obj/player.o obj/team.o
	$(CC) $(CFLAGS) -I$(INCL) -L$(LIBS) obj/*.o -lece_3822 -o proj_1

all: proj_1


clean:
	rm -f obj/* proj_1

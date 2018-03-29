CXXFLAGS=-std=c++14

main: main.o funcs.o
		g++ -o main main.o funcs.o

main.o: main.cpp funcs.h
		g++ $(CXXFLAGS) -c main.cpp

tests: tests.o funcs.o
	g++ $(CXXFLAGS) -o tests tests.o funcs.o

tests.o: tests.cpp funcs.h

funcs.o: funcs.cpp funcs.h
		g++ $(CXXFLAGS) -c funcs.cpp
clean:
		rm -f main.o funcs.o tests.o
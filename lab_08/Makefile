CXXFLAGS=-std=c++14
OBJECTS= main.o funcs.o

main: $(OBJECTS)
	g++ -o main $(OBJECTS) $(CXXFLAGS)

main.o: main.cpp funcs.h

funcs.o: funcs.cpp funcs.h

tests: tests.o funcs.o
	g++ -o tests tests.o funcs.o


tests.o: tests.cpp funcs.h doctest.h

clean:
	rm -f $(OBJECTS) tests.o main tests
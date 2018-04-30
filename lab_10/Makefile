CXXFLAGS=-std=c++14
OBJECTS= main.o funcs.o

main: $(OBJECTS)
	g++ -o main $(OBJECTS) $(CXXFLAGS)

main.o: main.cpp funcs.h labstructs.h

funcs.o: funcs.cpp labstructs.h

tests: tests.o funcs.o
	g++ -o tests.o funcs.o $(CXXFLAGS)

tests.o: funcs.h labstructs.h doctest.h

clean:
	rm -rf $(OBJECTS) tests main 
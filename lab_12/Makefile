CXXFLAGS=-std=c++14
OBJECTS=main.o funcs.o 

main: $(OBJECTS)
	g++ -o main $(OBJECTS) $(CXXFLAGS)

main.o: main.cpp funcs.h

funcs.o: funcs.cpp 

tests: tests.o funcs.o
	g++ -o tests tests.o funcs.o $(CXXFLAGS)

tests.o: tests.cpp doctest.h

clean:
	rm -rf $(OBJECTS) tests.o main tests
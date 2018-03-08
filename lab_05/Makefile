CXXFLAGS=-std=c++14
OBJECTS= main.o funcs.o

main: $(OBJECTS)
	g++ -o main $(OBJECTS) $(CXXFLAGS)

main.o: main.cpp funcs.h

funcs.o: funcs.cpp funcs.h

tests: tests.o

tests.o: tests.cpp funcs.h

clean:
	rm -f $(OBJECTS) main tests
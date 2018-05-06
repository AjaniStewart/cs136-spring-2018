CXXFLAGS=-std=c++14
OBJECTS=main.o funcs.o

main: $(OBJECTS)
	g++ -o main $(OBJECTS) $(CXXFLAGS)

poem: poem.o
	g++ -o poem poem.o $(CXXFLAGS)

main.o: main.cpp def.h funcs.h

funcs.o: funcs.cpp def.h

tests: tests.o funcs.o
	g++ -o tests funcs.o tests.o $(CXXFLAGS)

tests.o: funcs.h doctest.h def.h

clean:
	rm -rf $(OBJECTS) tests.o poem.o tests main poem 



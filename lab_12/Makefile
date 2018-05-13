CXXFLAGS=-std=c++14
OBJECTS=main.o funcs.o 

main: $(OBJECTS)
	g++ -o main $(OBJECTS) $(CXXFLAGS)

main.o: main.cpp funcs.h

funcs.o: funcs.cpp 

clean:
	rm -rf $(OBJECTS) main
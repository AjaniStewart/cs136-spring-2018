CXXFLAGS=-std=c++11

main: main.o funcs.o
	g++ -o $(CXXFLAGS) main main.o funcs.o

main.o: main.cpp funcs.h

funcs.o: funcs.cpp funcs.h

clean:
	rm *.o
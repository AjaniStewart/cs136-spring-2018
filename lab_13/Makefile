CXXFLAGS=-std=c++14

taska: social.o
	g++ -o taska social.o $(CXXFLAGS)

social.o: social.cpp

taskb: social2.o
	g++ -o taskb social2.o $(CXXFLAGS)

social2.o: social2.cpp

taskc: social3.o
	g++ -o taskc social3.o $(CXXFLAGS)

social3.o: social3.cpp

taskd: social4.o
	g++ -o taskd social4.o $(CXXFLAGS)

social4.o: social4.cpp

clean:
	rm -rf taska taskb taskc taskd social.o social2.o social3.o social4.o
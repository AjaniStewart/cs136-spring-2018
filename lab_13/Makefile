CXXFLAGS=-std=c++14

taskA: social.o
	g++ -o taskA social.o $(CXXFLAGS)

social.o: social.cpp

taskB: social2.o
	g++ -o taskB social2.o $(CXXFLAGS)

social2.o: social2.cpp

taskC: social3.o
	g++ -o taskC social3.o $(CXXFLAGS)

social3.o: social3.cpp

taskD: social4.o
	g++ -o taskD social4.o $(CXXFLAGS)

social4.o: social4.cpp

clean:
	rm -rf taskA taskB taskC taskD social.o social2.o social3.o social4.o
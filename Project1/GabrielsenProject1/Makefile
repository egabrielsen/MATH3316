CXX = g++
CXXFLAGS = -O -std=c++11

all: proj1_a.exe proj1_b.exe

proj1_a.exe : proj1_a.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

proj1_b.exe : proj1_b.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	\rm -f *.txt proj1_a.exe proj1_b.exe

###################################################################
#  Makefile for project 3
#
#  Daniel R. Reynolds
#  SMU Mathematics
#  Math 3316
#  28 September 2015
###################################################################

# compiler & flags
CXX = g++
CXXFLAGS = -O2 -std=c++11

# makefile targets
all : test_Newton.exe test_Lagrange.exe compare.exe test_Lagrange2D.exe

test_Lagrange.exe : Lagrange.cpp test_Lagrange.cpp matrix.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_Lagrange2D.exe : test_Lagrange2D.cpp Lagrange2D.cpp Lagrange.cpp matrix.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_Newton.exe : test_Newton.cpp matrix.cpp Newton_interpolant.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

compare.exe : matrix.cpp Lagrange.cpp Newton_interpolant.cpp compare.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	\rm -f *.o *.txt

realclean : clean
	\rm -f *.exe *~


####### End of Makefile #######
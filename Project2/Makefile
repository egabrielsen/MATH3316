###################################################################
#  Makefile for project 2
#
#  Erik Gabrielsen
#  SMU Mathematics
#  Math 3316
#  30 September 2015
###################################################################

# compilation definitions
CXX = g++
CXXFLAGS = -O -std=c++11

# makefile targets
all : test_bisect.exe test_newton.exe test_fd_newton.exe kepler.exe

test_bisect.exe : test_bisect.cpp bisection.cpp
	${CXX} ${CXXFLAGS} $^ -o $@

test_newton.exe: test_newton.cpp
	${CXX} ${CXXFLAGS} $^ -o $@

test_fd_newton.exe: test_fd_newton.cpp
	${CXX} ${CXXFLAGS} $^ -o $@

kepler.exe: kepler.cpp matrix.cpp
	${CXX} ${CXXFLAGS} $^ -o $@


clean :
	\rm -f *.o *.txt

realclean : clean
	\rm -f *.exe *~


### end of makefile ###

###################################################################
#  Makefile for project 2
#
#  Daniel R. Reynolds
#  SMU Mathematics
#  Math 3316
#  16 September 2015
###################################################################

# compilation definitions
CXX = g++
CXXFLAGS = -O -std=c++11

# makefile targets
all : test_bisect.exe test_newton.exe test_fd_newton.cpp

test_bisect.exe : test_bisect.cpp bisection.cpp
	${CXX} ${CXXFLAGS} $^ -o $@

test_newton.exe: test_newton.cpp
	${CXX} ${CXXFLAGS} $^ -o $@

test_fd_newton.exe: test_fd_newton.cpp fd_newton.cpp
	${CXX} ${CXXFLAGS} $^ -o $@


clean :
	\rm -f *.o *.txt

realclean : clean
	\rm -f *.exe *~


####### End of Makefile #######

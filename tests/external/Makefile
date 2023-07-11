# This is a Make file to build and run google test files  
# @Mohammed Maher Abdelrahim Mohammed

# Check for Eigen3 library
EIGEN3_INSTALLED := $(shell pkg-config --exists eigen3 && echo 1 || echo 0)

# Install Eigen3 if not found
ifeq ($(EIGEN3_INSTALLED), 0)
    $(shell sudo apt-get install libeigen3-dev)
endif

# in both testing and library
CC = g++ -g3 -O3  -I./usr/include/
#added for the testing files
CFLAGSTEST = -std=c++17 -Wall -Wextra -Wconversion


TESTS = gtest_braket\
	gtest_QM_operators
 
$(TESTS): %: googletest/%.cpp
	$(CC) $(CFLAGSTEST)  -o RunTests.out $< -lgtest -lgtest_main -pthread -I/usr/include/eigen3 
clean:
	rm *.out      	

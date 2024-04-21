# This is a Make file to build and run QUANTAPLUS package files  
# Makefile for installing QuantaPlus

# Check for Eigen3 library
EIGEN3_INSTALLED := $(shell pkg-config --exists eigen3 && echo 1 || echo 0)

# Install Eigen3 if not found
ifeq ($(EIGEN3_INSTALLED), 0)
    $(shell sudo apt-get install libeigen3-dev)
endif

# Copy QuantaPlus folder to /usr/include
install:
	sudo cp -r quantaplus /usr/include/
	
# in both testing and library
CC = g++ -g3 -O3  -I./usr/include/
# added for the compilation of the libraries
CFLAGS = -Wall -Wextra -Wconversion
#added for the testing files
CFLAGSTEST = -std=c++17 -Wall -Wextra -Wconversion

#OBJECTSQNTXLIB = utilities.o \
 #       operators.o ClebschGordon.o \
         	 
INCLUDEQUANTAPLUS = include/angularmomentum.h \
                 include/braket.h \
                 include/utilities.h\
                 include/cgc.h \
                 include/constants.h \
                 include/latex.h \
                 include/operators.h \
                 include/timer.h
                                   
EXAMPLES = example1\
		QCD_example\
		Harmonic_Oscillator\
		Double_Well\
		Rb87_hyperfine_structure\
		oscillating_magnetic_field\
		shift\
		states

#TESTS = gtest_braket\
#	gtest_QM_operators
TESTS =	test_angular-momentum \
		test_braket\
		test_latex \
		test_eigenvalue\
		test_operators\
		test_clebschGordon\
		qtest	
OUTPUT = genLatex
	 #ploting_wavefunctions

PLOTS = plotting_wavefunctions
          

# making examples

$(EXAMPLES): %: examples/%.cpp 
	$(CC) $(CFLAGSTEST)  -o QUANTA.out $< 

$(OUTPUT): %: output/%.cpp  
	$(CC) $(CFLAGSTEST)  -o latex.out $< 
	
$(PLOTS): %: output/plots/%.cpp  
	$(CC) $(CFLAGSTEST)  -o plot.out $< -I/usr/include/python3.10 -lpython3.10

	
#$(TESTS): %: tests/%.cpp
#	$(CC) $(CFLAGSTEST)  -o RunTests.out $< -lgtest -lgtest_main -pthread -I/usr/include/eigen3 
$(TESTS): %: tests/%.cpp
	$(CC) $(CFLAGSTEST)  -o QUANTA.out $<  
clean:
	rm *.out      	

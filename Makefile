# This is a Make file to build and run QUANTAPLUS package files  

 
# in both testing and library
CC = g++ -O3  -I./include  #-I/home/mohammed/Downloads/eigen-3.4.0/ 
# added for the compilation of the libraries
CFLAGS = -Wall -Wextra -Wconversion
#added for the testing files
CFLAGSTEST = -std=c++17 -Wall -Wextra -Wconversion

#OBJECTSQNTXLIB = utilities.o \
 #       operators.o ClebschGordon.o \
         	 
INCLUDEQUANTAPLUS = include/constants.h \
                 include/operators.h \
                 include/utilities.h\
                 include/plot.h
                                   
EXAMPLES = example1\
		QCD_example\
		angular_momentum_test \
		braket_test\
		latex_test \
		test_eigenvalue\
		test_ClebschGordon\
		Harmonic_Oscillator\
		Double_Well\
		Rb87_hyperfine_structure\
		oscillating_magnetic_field\
		shift

TESTS = gtest_braket\
	gtest_QM_operators
	
OUTPUT = genLatex
	 #ploting_wavefunctions

PLOTS = plotting_wavefunctions
          
# making examples

$(EXAMPLES): %: examples/%.cpp 
	$(CC) $(CFLAGSTEST)  -o QUANTA.out $< -I/usr/include/eigen3 #-I/home/mohammed/Downloads/eigen-3.4.0/ 

$(OUTPUT): %: output/%.cpp  
	$(CC) $(CFLAGSTEST)  -o latex.out $< #-I/usr/include/python3.10 -lpython3.10
	
$(PLOTS): %: output/plots/%.cpp  
	$(CC) $(CFLAGSTEST)  -o plot.out $< -I/usr/include/python3.10 -lpython3.10

	
$(TESTS): %: tests/%.cpp
	$(CC) $(CFLAGSTEST)  -o RunTests.out $< -lgtest -lgtest_main -pthread -I/usr/include/eigen3 
clean:
	rm *.out      	

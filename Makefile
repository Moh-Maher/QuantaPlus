# This is a Make file to build and run QUANTAPLUS package files  

 
# in both testing and library
CC = g++ -O3  -I./include  #-I/home/mohammed/Downloads/eigen-3.4.0/ 
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
		shift

#TESTS = gtest_braket\
#	gtest_QM_operators
TESTS =	test_angular-momentum \
		test_braket\
		test_latex \
		test_eigenvalue\
		test_operators\
		test_clebschGordon	
OUTPUT = genLatex
	 #ploting_wavefunctions

#PLOTS = plotting_wavefunctions
          
# making examples

$(EXAMPLES): %: examples/%.cpp 
	$(CC) $(CFLAGSTEST)  -o QUANTA.out $< -I/usr/include/eigen3 #-I/home/mohammed/Downloads/eigen-3.4.0/ 

$(OUTPUT): %: output/%.cpp  
	$(CC) $(CFLAGSTEST)  -o latex.out $< #-I/usr/include/python3.10 -lpython3.10
	
#$(PLOTS): %: output/plots/%.cpp  
#	$(CC) $(CFLAGSTEST)  -o plot.out $< -I/usr/include/python3.10 -lpython3.10

	
#$(TESTS): %: tests/%.cpp
#	$(CC) $(CFLAGSTEST)  -o RunTests.out $< -lgtest -lgtest_main -pthread -I/usr/include/eigen3 
$(TESTS): %: tests/%.cpp
	$(CC) $(CFLAGSTEST)  -o QUANTA.out $< -I/usr/include/eigen3 
clean:
	rm *.out      	

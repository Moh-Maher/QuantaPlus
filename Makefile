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
                 include/utilities.h
                                   
EXAMPLES = example1\
		QCD_example\
		AMO_test \
		Braket_test
           
# making examples

$(EXAMPLES): %: examples/%.cpp   
	$(CC) $(CFLAGSTEST)  -o QUANTA.out $< -I/home/mohammed/Downloads/eigen-3.4.0/ 

clean:
	rm *.out        	

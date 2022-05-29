/*******************************************************************************************
testing "braket.h".
by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#include<iostream>
#include<complex>
#include"braket.h"
#include"operators.h"
#include<ctime>  
#include"utilities.h"
#include"latex.h"
 
	typedef std::complex<double>  complex;
	using std::cout;
	using std::endl;

int main()
{ 
	///<--clock stuff
	std::clock_t start;
	double duration;
 	start = std::clock();
 	///<--stop clock stuff 
	using namespace std::complex_literals; //needed to use the literal imaginary unit [ 1i = (0,1)] 
  
	ket<complex> ktA(3),ktres(3);
	bra<complex> brA(3),brres(3);
	QM_operator<complex> O(3,3);
	 
	ktA <<-1.+1i, 3, 2.+3i; 
	brA << 6., -1i, 5;
	 
	O <<5., 3.+2i, 3i , -1i, 3i, 8., 1.-1i, 1., 4.;
	 
        
      
    	ktres << O*ktA;
    	result_printf(ktres);
    	brres << brA*O;
    	result_printf(brres);
    	 
    	 begin();
    	 TolaTex("tktbto","\\ket{\\psi} = ",ktA,"\\bra{\\phi} = ",brA,"A = ",O);
    	 operation("tok=k","A\\ket{\\psi} = ",O,ktA,'=',ktres);
    	 operation("tbo=b","\\bra{\\phi}A = ",brA,O,'=',brres);
    	 end();
    	///<--clock stuff again
	duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
 
	if (duration < 60.0) {
		std::cout << "Elapsed time: " << duration << " seconds" << std::endl;
	}
 
	else {
		std::cout << "Elapsed time: " << duration/60.0 << " mins" << std::endl;
	}
    	 
	return 0;
}

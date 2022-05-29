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
//using namespace QUANTAx;
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
  
	ket<complex> ktA(3),ktB;
	bra<complex> brB(3),brA;
        complex braketAB{},braketBA{};
        complex braketAA{},braketBB{};
	brB << 6., 3.-1i, 5.;
	ktA <<1.-2i, 1i,-1i; 
	cout<<"--------|A>------------"<<endl;
    	result_printf(ktA);
    	cout<<"--------<B|------------"<<endl;
    	result_printf(brB);  
    	cout<<"--------|B>------------"<<endl;
    	ktB = DualConj(brB);
    	result_printf(ktB);
	cout<<"--------<A|------------"<<endl;
    	brA = DualConj(ktA);
    	result_printf(brA);
    	cout<<"--------<A|B>----------"<<endl;
    	braketAB = BraKet(brA,ktB);
    	result_printf(braketAB);
    	cout<<"--------<B|A>----------"<<endl;
    	braketBA = BraKet(brB,ktA);
    	result_printf(braketBA);
   
    	braketAA = BraKet(brA,ktA);
    	braketBB = BraKet(brB,ktB);
    	cout<<"--------<A|A>--------"<<endl;
    	result_printf(braketAA);   	 
    	cout<<"--------<B|B>--------"<<endl;
    	result_printf(braketBB);
    
    	
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

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
  
	ket<complex> ktA(3),ktB(3), ktAplusktB(3);
	QM_operator<complex> O(3,3);
	bra<complex> brA(3), brB(3); 
	complex bra_ketAA,bra_ketBB,bra_ketAB, bra_ketBA;
	
	ktA << 1.-2i, 1i,-1i; 
	ktB << 6., 3.-1i, 5.;
	O   << 1.,3i,0.,0.,-1i,0.,2.-5i,0.,1.;
 
     	cout<<"-------<A|-------------"<<endl;
     	brA = DualConj(ktA);
 
        cout<<"-------<B|-------------"<<endl;
     	brB = DualConj(ktB);
    
        
        
        cout<<"========================="<<endl; 
    	 //cout<<"[|A>, |B>, <A| and <B|A> ]"<<endl;
    	 literal_printf("kbkb", ktA,brA,ktB,brB);
    	cout<<"========================="<<endl; 
    	
    	
    	 
    	 TolaTex("kbkbo",ktA,brA, ktB,brB,O);
    	 
    	 system("pdflatex latex_results.tex");
    	system("make clean");
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

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
	bra<complex> brA(3), brB(3); 
	complex bra_ketAA,bra_ketBB,bra_ketAB, bra_ketBA;
	ktA <<1.-2i, 1i,-1i; 
	ktB << 6., 3.-1i, 5.;
	cout<<"--------|A>------------"<<endl;
	cplx_show(ktA);
	cout<<"--------|B>------------"<<endl;
	cplx_show(ktB);
	cout<<"--------|A> + |B>------------"<<endl;
	ktAplusktB << ktA + ktB ;
    	cplx_show(ktAplusktB);
     	cout<<"-------<A|-------------"<<endl;
     	brA = DualConj(ktA);
     	cplx_show(brA);
     	cout<<"-------<A|A>-------------"<<endl;
        bra_ketAA = BraKet(brA,ktA);
        cplx_show(bra_ketAA);
        cout<<"-------<B|-------------"<<endl;
     	brB = DualConj(ktB);
     	cplx_show(brB);
     	cout<<"-------<B|B>-------------"<<endl;
        bra_ketBB = BraKet(brB,ktB);
        cplx_show(bra_ketBB);
        cout<<"-------<A|B>-------------"<<endl;
        bra_ketAB = BraKet(brA,ktB);
        cplx_show(bra_ketAB);
        cout<<"-------<B|A>-------------"<<endl;
        bra_ketBA = BraKet(brB,ktA);
        cplx_show(bra_ketBA);
    	
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

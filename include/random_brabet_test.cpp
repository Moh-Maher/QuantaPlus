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
	ktA <<1.-2i, 1i,-1i; 
	ktB << 6., 3.-1i, 5.;
	O <<1.,3i,0.,0.,-1i,0.,2.-5i,0.,1.;
	cout<<"--------|A>------------"<<endl;
	result_printf(ktA);
	cout<<"--------|B>------------"<<endl;
	result_printf(ktB);
	cout<<"--------|A> + |B>------------"<<endl;
	ktAplusktB << ktA + ktB ;
    	result_printf(ktAplusktB);
     	cout<<"-------<A|-------------"<<endl;
     	brA = DualConj(ktA);
     	result_printf(brA);
     	cout<<"-------<A|A>-------------"<<endl;
        bra_ketAA = BraKet(brA,ktA);
        result_printf(bra_ketAA);
        cout<<"-------<B|-------------"<<endl;
     	brB = DualConj(ktB);
     	result_printf(brB);
     	cout<<"-------<B|B>-------------"<<endl;
        bra_ketBB = BraKet(brB,ktB);
        result_printf(bra_ketBB);
        cout<<"-------<A|B>-------------"<<endl;
        bra_ketAB = BraKet(brA,ktB);
        result_printf(bra_ketAB);
        cout<<"-------<B|A>-------------"<<endl;
        bra_ketBA = BraKet(brB,ktA);
        result_printf(bra_ketBA);
        
        cout<<"========================="<<endl; 
    	//cout<<"[|A>, |B>, <A| and <B|A> ]"<<endl;
    	//literal_printf("kkbc", ktA,ktB,brA, bra_ketBA);
    	cout<<"========================="<<endl; 
    	
    	
    	 
    	 TolaTex("kbkbo",ktA,brA, ktB,brB,O);
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

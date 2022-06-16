/*******************************************************************************************
testing " BraKet.h".
by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#include<iostream>
#include<complex>
#include"braket.h"
//#include"operators.h"
#include"timer.h"
//#include"utilities.h"
//using namespace QUANTAx;
	typedef std::complex<double>  complex;
	using std::cout;
	using std::endl;

int main()
{ 
	ElapsedTime time_count; //<--clock stuff
	time_count.Start();
	using namespace std::complex_literals; //needed to use the literal imaginary unit [ 1i = (0,1)] 
  
	Ket<complex> ktA(3),ktB;
	Bra<complex> brB(3),brA;
       
        complex  BraKetAB{}, BraKetBA{};
        complex  BraKetAA{}, BraKetBB{};
	brB << 6., 3.-1i, 5.;
	ktA <<1.-2i, 1i,-1i; 
	cout<<"--------|A>------------"<<endl;
    	ResultPrint(ktA);
    	cout<<"--------<B|------------"<<endl;
    	ResultPrint(brB);  
    	cout<<"--------|B>------------"<<endl;
    	ktB = DualConj(brB);
    	ResultPrint(ktB);
	cout<<"--------<A|------------"<<endl;
    	brA = DualConj(ktA);
    	ResultPrint(brA);
    	cout<<"--------<A|B>----------"<<endl;
    	BraKetAB = BraKet(brA,ktB);
    	ResultPrint( BraKetAB);
    	cout<<"--------<B|A>----------"<<endl;
    	BraKetBA = BraKet(brB,ktA);
    	ResultPrint( BraKetBA);
   
    	BraKetAA = BraKet(brA,ktA);
    	BraKetBB = BraKet(brB,ktB);
    	cout<<"--------<A|A>--------"<<endl;
    	ResultPrint( BraKetAA);   	 
    	cout<<"--------<B|B>--------"<<endl;
    	ResultPrint( BraKetBB);
    
    	
	///<--clock stuff again
	time_count.End();
    	 
	return 0;
}

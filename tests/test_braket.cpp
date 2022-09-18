 /*******************************************************************************************
testing " BraKet.h".
by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#include<iostream>
#include<complex>

#include"../quantaplus/quantaplus.h"

/*
#include"../quantaplus/utilities/utilities.h"
#include"../quantaplus/braket/ket.h"
#include"../quantaplus/braket/bra.h"
*/
 
 
using namespace QuantaPlus;
typedef std::complex<double>  complex;
using std::cout;
using std::endl;

int main()
{ 
	ElapsedTime time_count;
	
	using namespace std::complex_literals; //needed to use the literal imaginary unit [ 1i = sqrt(-1)] 
  	/*Remember that you have to set the size before you can use the comma initializer.*/
	Ket<complex> ktA(3); // deceleration of |A> with fixed space for three elements. 
	Ket<complex> ktB;    // deceleration of |B> with unspecified (Dynamic) space for its elements. 
	Bra<complex> brB(3); // deceleration of <B| with fixed space for three elements. 
	Bra<complex> brA;    // deceleration of <A| with unspecified (Dynamic) space for its elements.
 
        complex BraKetAB{};  // to hold the value of <A|B>
        complex BraKetBA{};  // to hold the value of <B|A>
        complex BraKetAA{};  // to hold the value of <A|A>
        complex BraKetBB{};  // to hold the value of <B|B>
	
	brB << 6., 3.-1i, 5.;  // <B| = (6, 3-i, 5)  it's a row vector.
	ktA <<1.-2i, 1i,-1i;   // |A> = (1-i, i, -i) it's a column vector.
	
	 
	time_count.Start(); //<--clock stuff
 
	//-----------------------------------------------------------------
	cout<<"--------|A>------------"<<endl;
    	
    	ktA.Print();
    	cout<<"--------<B|------------"<<endl;
    	
    	brB.Print();
    	
    	cout<<"--------|B>------------"<<endl;
    	ktB = brB.conjugate(); // |B> = (<B|)^Dagger. (see any QM textbook).
 
	ktB.Print();
	cout<<"--------<A|------------"<<endl;
    	brA =  ktA.conjugate();  // <A| = (|A>)^Dagger. (see any QM textbook).
 
    	brA.Print();
    	cout<<"--------<A|B>----------"<<endl;
    	BraKetAB =  brA*ktB;
    	ResultPrint( BraKetAB);
    	
    	cout<<"--------<B|A>----------"<<endl;
    	//BraKetBA = BraKet(brB,ktA);
    	BraKetBA = brB*ktA;
    	ResultPrint( BraKetBA);  	
    	
    	cout<<"--------<A|A>--------"<<endl;
    	BraKetAA =  brA*ktA;
    	ResultPrint( BraKetAA);   	 
    	
    	cout<<"--------<B|B>--------"<<endl;
    	BraKetBB =  brB*ktB;
    	ResultPrint( BraKetBB);
	//-----------------------------------------------------------------
   
	time_count.End(); //<--clock stuff again
    	 
	return 0;
}

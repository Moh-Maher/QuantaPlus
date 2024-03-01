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

using namespace QuantaPlus;
using std::cout;
using std::endl;

int main()
{ 
	ElapsedTime time_count;
	
	//using namespace std::complex_literals; //needed to use the literal imaginary unit [ 1i = sqrt(-1)] 
  	/*Remember that you have to set the size before you can use the comma initializer.*/
	Ket ketA(3); // deceleration of |A> with fixed space for three elements. 
	Ket ketB;    // deceleration of |B> with unspecified (Dynamic) space for its elements. 
	Bra braB(3); // deceleration of <B| with fixed space for three elements. 
	Bra braA;    // deceleration of <A| with unspecified (Dynamic) space for its elements.
 
        complex BraKetAB{};  // to hold the value of <A|B>
        complex BraKetBA{};  // to hold the value of <B|A>
        complex BraKetAA{};  // to hold the value of <A|A>
        complex BraKetBB{};  // to hold the value of <B|B>
	
	braB << 6., 3.-1i, 5.;  // <B| = (6, 3-i, 5)  it's a row vector.
	ketA <<1.-2i, 1i,-1i;   // |A> = (1-i, i, -i) it's a column vector.
	
	 
	time_count.Start(); //<--clock stuff
 
	//-----------------------------------------------------------------
	cout<<"--------|A>------------"<<endl;
    	
    	ketA.Print();
    	//cout<<ketA;
    	//ketA=Normalize(ketA);
    	//ketA.Print();
    	//cout<<"The selected state index after measurement: "<<ketA.Measure()<<endl;
    	cout<<"--------<B|------------"<<endl;
    	
    	//braB.Print();
	cout<<braB;
    	cout<<"--------|B>------------"<<endl;
    	ketB = braB.conjugate(); // |B> = (<B|)^Dagger. (see any QM textbook).
 
	//ketB.Print();
	cout<<ketB;
	cout<<"--------<A|------------"<<endl;
    	braA =  ketA.conjugate();  // <A| = (|A>)^Dagger. (see any QM textbook).
 
    	//braA.Print();
    	cout<<braA;
    	cout<<"--------<A|B>----------"<<endl;
    	BraKetAB =  braA*ketB;
    	ResultPrint( BraKetAB);
    	
    	cout<<"--------<B|A>----------"<<endl;
    	//BraKetBA = BraKet(brB,ktA);
    	BraKetBA = braB*ketA;
    	ResultPrint( BraKetBA);  	
    	
    	cout<<"--------<A|A>--------"<<endl;
    	BraKetAA =  braA*ketA;
    	ResultPrint( BraKetAA);   	 
    	
    	cout<<"--------<B|B>--------"<<endl;
    	BraKetBB =  braB*ketB;
    	ResultPrint( BraKetBB);
	//-----------------------------------------------------------------
   
	time_count.End(); //<--clock stuff again
    	 
	return 0;
}

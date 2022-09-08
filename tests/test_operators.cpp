/*******************************************************************************************
testing " operators.h".
by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#include<iostream>
#include<complex>
//#include"braket.h"
#include"operators.h"
 
#include"timer.h"
 
 
using namespace QuantaPlus;
typedef std::complex<double>  complex;
using std::cout;
using std::endl;

int main()
{ 
	ElapsedTime time_count;
	
	using namespace std::complex_literals; //needed to use the literal imaginary unit [ 1i = sqrt(-1)] 
  	int N =4;// 21;
  	QM_operator<complex> plus(N,N), minus(N,N);
 	plus = RisingOperator<complex>(N,N);
 	minus =  LoweringOperator<complex>(N,N);
	
	time_count.Start(); //<--clock stuff
	//-----------------------------------------------------------------
	cout<<"[ RisingOperator: ]"<<endl;
	ResultPrint(plus);
	cout<<"-------------------"<<endl;
	
	cout<<"[ LoweringOperator: ]"<<endl;
	ResultPrint(minus);
	cout<<"-------------------"<<endl;
	
	cout<<"[ Id matrix operator for spin = 3/2: ]"<<endl;
    	cout<<Id<int>(1.5)<<endl;
	//-----------------------------------------------------------------
	time_count.End(); ///<--clock stuff again
    	 
	return 0;
}

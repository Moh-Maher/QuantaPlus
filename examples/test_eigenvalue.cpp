/*******************************************************************************************
  

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#include<iostream>
#include<complex>
#include"braket.h"
#include"operators.h"
#include"timer.h"
 
typedef std::complex<double>  complex;
using std::cout;
using std::endl;
 
int main() {
 	ElapsedTime time_count; //<--clock stuff
	time_count.Start();
	using namespace std::complex_literals; //needed to use the literal imaginary unit [ 1i = (0,1)] 
	QM_operator<complex> H(4,4);
	complex t;
	H <<
	0.0, 0.3, 1.i, 0.0, 
	0.3, 1.0, 0.0, 0.0, 
	-1i, 0.0, 1.0,-0.2, 
	0.0, 0.0,-0.2, 3.0;
	//cout<<H<<endl;
	NResultPrint(H);
	//cout<<QuantumEigenValue(H,4)<<endl;
	cout<<"Eigenvalue:";
	for(int i=0;i<4;i++){
	NResultPrint(QuantumEigenValue(H,i));
	}
	cout<<endl;
	/*cout<<"---------------------"<<endl;
	cout<<"Eigenvectors:\n";
	for(int i=0;i<4;i++){
         
	//NResultPrint(QuantumEigenVector(H,i));
	cout<<QuantumEigenVector(H,i);
	}
	cout<<endl;*/
	///<--clock stuff again
	time_count.End();
}

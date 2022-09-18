/*******************************************************************************************
  

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#include<iostream>
#include<complex>

#include"../quantaplus/quantaplus.h"
/*
#include"../quantaplus/braket/ket.h"
#include"../quantaplus/braket/bra.h"
#include"../quantaplus/eigenvectors/eigenvec.h"
#include"../quantaplus/eigenvectors/eigenval.h"
#include"../quantaplus/operators/angularmomentum.h"
#include"../quantaplus/utilities/utilities.h"
*/
using namespace QuantaPlus;
typedef std::complex<double>  complex;
using std::cout;
using std::endl;
 
int main() {
 	ElapsedTime time_count; //<--clock stuff
	
	using namespace std::complex_literals; //needed to use the literal imaginary unit [ 1i = (0,1)] 
 
 	QM_operator<complex> A(3,3);
 	QM_operator<complex> vec(3,3);
 	QM_operator<complex> res(3,3);
 
	A<<0.0, 1.0, 0.0,
	   1.0, 0.0, 1.0,
	   0.0, 1.0, 0.0;
	//cout<<H<<endl;
	time_count.Start();
	
 
	A.NPrint();
	//cout<<QuantumEigenValue(H,4)<<endl;
	cout<<"----------EigenValues-----------"<<endl;
 
	res = QuantumEigenValue(A);
	//cout<<res<<endl;
 
	res.Print();
	cout<<endl;
	cout<<"----------Eigenvectors-----------"<<endl;
	 
	vec =QuantumEigenVector(A);
 
	vec.Print();
	// cout<<vec<<endl;
	cout<<endl;
	///<--clock stuff again
	time_count.End();
}

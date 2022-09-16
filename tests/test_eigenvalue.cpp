/*******************************************************************************************
  

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#include<iostream>
#include<complex>
#include"../quantaplus/braket.h"
#include"../quantaplus/angularmomentum.h"
#include"../quantaplus/utilities.h"

using namespace QuantaPlus;
typedef std::complex<double>  complex;
using std::cout;
using std::endl;
 
int main() {
 	ElapsedTime time_count; //<--clock stuff
	
	using namespace std::complex_literals; //needed to use the literal imaginary unit [ 1i = (0,1)] 
 
	//QM_operator<complex> A(3,3);
	Eigen::Matrix<complex,Eigen::Dynamic,Eigen::Dynamic> A(3,3);
	Eigen::Matrix<complex,Eigen::Dynamic,Eigen::Dynamic> vec;
	Eigen::Matrix<complex,Eigen::Dynamic,Eigen::Dynamic> res;
 
 
	A<<0.0, 1.0, 0.0,
	   1.0, 0.0, 1.0,
	   0.0, 1.0, 0.0;
	//cout<<H<<endl;
	time_count.Start();
	
	NResultPrint(A);
	//cout<<QuantumEigenValue(H,4)<<endl;
	cout<<"----------EigenValues-----------"<<endl;
 
	res = QuantumEigenValue(A);
	//cout<<res<<endl;
	ResultPrint(res);
	cout<<endl;
	cout<<"----------Eigenvectors-----------"<<endl;
	 
	vec =QuantumEigenVector(A);
	ResultPrint(vec);
	// cout<<vec<<endl;
	cout<<endl;
	///<--clock stuff again
	time_count.End();
}

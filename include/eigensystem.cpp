#include<iostream>
#include<cmath>
#include"utilities.h"
#include"operators.h"
 #include<complex>
 #include<map>
 #include<vector>
using namespace std;
 
using namespace Eigen;
 
 //cout << "The eigenvalues of A are:" << endl << es.eigenvalues() << endl;
 //cout << "The matrix of eigenvectors, V, is:" << endl << es.eigenvectors() << endl << endl;
template<typename T>
Matrix<complex<T>,Dynamic,Dynamic> EigenVector(Matrix<T,Dynamic,Dynamic>& mat )
{
		EigenSolver<Matrix<T,Dynamic,Dynamic>> es(mat);
		return es.eigenvectors();
}
template<typename T>
Matrix<complex<T>,Dynamic,Dynamic> EigenValue(Matrix<T,Dynamic,Dynamic>& mat)
{ 
	EigenSolver<Matrix<T,Dynamic,Dynamic>> es(mat);
	return es.eigenvalues();
}
 
 
int main(){

Matrix<double,Dynamic,Dynamic> A(3,3);
 	 A<<0.278980256742208, 0.0804792511519405, 0.337782855687788,
 0.392153533013471, 0.972281966495217, 0.459063532761155,
 0.774827015437448, 0.825647939801263, 0.386576536730811;

 
//cout<<EigenValue(A)<<endl;
Matrix<complex<double>,Dynamic,Dynamic> FIXEV(3,3);
 
 
FIXEV =EigenVector(A);

 

 
//cout<<EigenVector(A).col(0)<<endl;
cout<<(FIXEV.reverse().transpose())*A<<endl;
 
 

	return 0;
}

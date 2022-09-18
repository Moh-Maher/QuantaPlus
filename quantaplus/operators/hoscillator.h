//=================================================================================================
/*!
//  \file quantaplus/operators/hoscillator
//  \brief The Matrix Representation of Various Operators.
//
//  Copyright (c) 2022 Mohammed Maher Abdelrahim Mohammed
//  
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//  
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
*/
//=================================================================================================
//#pragma once 
#ifndef QUANTAPLUS_OPERATORS_HOSCILLATOR_H
#define QUANTAPLUS_OPERATORS_HOSCILLATOR_H

//********************************************************************
// Includes
//********************************************************************
#include"operators.h"
#include"../eigenvectors/eigenvec.h"
#include"../eigenvectors/eigenval.h"


namespace QuantaPlus{


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:  HOscillatorMatrixElements

  Summary: The matrix representation of Hrmonic Oscillator Hamiltonian operator 
  	   in the N -space. ( <n'|H|n> = hbar*omega (n+1/2) delat_{n',n} ).
  	    
  Args:   const int& R, const int& C
  		rows and columns. 
  	      
  Returns:  QM_operator<T>
  		Matrix of arbitrary size and generic type T.
------------------------------------------------------------------*/
template<typename T>
QM_operator<T> HOscillatorMatrixElements(const int& R, const int& C)
{
	QM_operator<T> H(R,C);
	 
	for(int i=0; i<(int)H.rows(); i++){
		for(int j =0; j<(int)H.cols();j++){
			H(i,j) = (i+1./2.)*KroneckerDelta(i,j); 
		}
	}
	return H;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: PositionOperator

  Summary: N -representation of the position operator.
  	   X = sqrt{hbar/(2m*omega)}*(sqrt{n} delta_{n',n-1} + sqrt{n+1} delta_{n',m+1}).   
  
  Args:   const int& R, const int& C
		rows and columns. 	      
  
  Returns:  QM_operator<T>
  		Matrix of arbitrary size and generic type T.
------------------------------------------------------------------*/
template<typename T>
QM_operator<T> PositionOperator(const int& R, const int& C)
{
	QM_operator<T> H(R,C);
	 
	for(int i=0; i<(int)H.rows(); i++){
		for(int j =0; j<(int)H.cols();j++){
			H(i,j) = sqrt(j)*KroneckerDelta(i,j-1) + sqrt(j+1)*KroneckerDelta(i,j+1);
		}
	}
	return H;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:  MomentumOperator

  Summary: N -representation of the Momentum operator.
  	   P = i*sqrt{m*hbar*omega/2}*(-sqrt{n} delta_{n',n-1} + sqrt{n+1} delta_{n',m+1}).

  Args:   const int& R, const int& C
		rows and columns. 
		     
  Returns:  QM_operator<T>
  		Matrix of arbitrary size and generic type T.
------------------------------------------------------------------*/
template<typename T>
QM_operator<T> MomentumOperator(const int& R, const int& C)
{
 
	QM_operator<T> H(R,C);
 
	for(int i=0; i<(int)H.rows(); i++){
		for(int j =0; j<(int)H.cols();j++){
			H(i,j) = sqrt(j+1)*KroneckerDelta(i,j+1) - sqrt(j)*KroneckerDelta(i,j-1);
		}
	}
	return H;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: LoweringOperator  

  Summary: The matrix elements of Lowering Operator (a).
  	    <n'|a|n> = sqrt{n} delta_{n',n-1}
  	    
  Args:   const int& R, const int& C
		rows and columns.       
  	      
  Returns:  QM_operator<T>
  		Matrix of arbitrary size and generic type T.
------------------------------------------------------------------*/
template<typename T>
QM_operator<T> LoweringOperator(const int& R, const int& C)
{ 
	QM_operator<T> H(R,C);
 
	for(int i=0; i<(int)H.rows(); i++){
		for(int j =0; j<(int)H.cols();j++){
			H(i,j) = sqrt(j)*KroneckerDelta(i,j-1);
		}
	}
	return H;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: RisingOperator 

  Summary: The matrix elements of Rising Operator (a^dagger).  
  	    <n'|a^dagger|n> = sqrt{n+1} delta_{n',n+1}
 
  Args:   const int& R, const int& C
		rows and columns.       
  	      
  Returns:  QM_operator<T>
  		Matrix of arbitrary size and generic type T.
------------------------------------------------------------------*/
template<typename T>
QM_operator<T> RisingOperator(const int& R, const int& C)
{	 
	QM_operator<T> H(R,C);
 
	for(int i=0; i<(int)H.rows(); i++){
		for(int j =0; j<(int)H.cols();j++){
			H(i,j) = sqrt(j+1)*KroneckerDelta(i,j+1);
		}
	}
	return H;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: Hamiltonian

  Summary:   
  	    
  Args: QM_operator<T> A
  		matrix of type T
  	QM_operator<T> B
  		matrix of type T
  	Bra<T> coff
  		row vector of type T     
  	      
  Returns:  QM_operator<T>
  		Matrix of arbitrary size and generic type T. 
------------------------------------------------------------------*/
template<typename T>
QM_operator<T> Hamiltonian(QM_operator<T> A, QM_operator<T> B, Bra<T> coff)
{
	int l = (int)coff.cols();
	QM_operator<T> res((int)A.rows(),(int)A.cols());
	QM_operator<T> a((int)A.rows(),(int)A.cols());
	a = -0.25 *B.pow(2);

	QM_operator<T> b((int)A.rows(),(int)A.cols());
	b = QM_operator<T>::Zero((int)A.rows(),(int)A.cols()) ;

	for(int i=0; i<l; i++){
		b += coff[i]*pow(0.5,0.5*i)*A.pow(i);
	}

	res = a + b;
	res.conservativeResize(res.rows()-1, res.cols()-1);
	return res;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: eval

  Summary:  gives the eigenvalues of the square matrix.  
  	    
  Args: QM_operator<T>& A
  		Square matrix of dynamic size.     
  	      
  Returns:  Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>
------------------------------------------------------------------*/
template<typename T>
Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> eval(QM_operator<T>& A)
{
	return QuantumEigenValue(A);
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: evec

  Summary:  gives the eigenvectors of the square matrix.  
  	    
  Args: QM_operator<T>& A
  		Square matrix of dynamic size.     
  	      
  Returns:  Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>
------------------------------------------------------------------*/
template<typename T>
Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> evec(QM_operator<T>& A)
{
	return QuantumEigenVector(A);
}
//------------------- Overloaded eigenvectors ----------------------
template<typename T>
Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> evec(const QM_operator<T>& A, const QM_operator<T>& B, const Bra<T>& coff)
{
	QM_operator<T> res = Hamiltonian(A,B,coff);
	return QuantumEigenVector(res);
}

//---------------------------------------------------------------------------------------------
//
//---------------------------------------------------------------------------------------------
int Factorial(const int& n)
{
        return n == 0? 1 : n * Factorial(n-1);
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:  wave_function

  Summary:   
  	    
  Args: const int& n
  		the order of the wave function
  	const double& x
  		     
  	      
  Returns:  double
  		the wave function values for given x and order n.
------------------------------------------------------------------*/
double wave_function(const int& n,const double& x)
{ 
	return (1./pow(M_PI,0.25)) *(1/(sqrt(pow(2,n))*Factorial(n)))*std::hermite(n,x)*exp(-pow(x,2)/2.);
}
/*double wave_function(const int& n,const double& x)
{ 
	return sqrt(2)*sin(n*M_PI*x);
}*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:  coefficients

  Summary:   
  	    
  Args:      
  	      
  Returns:  std::vector<T> 
------------------------------------------------------------------*/
template<typename T>
std::vector<T> coefficients(const QM_operator<T>& A, const QM_operator<T> &B,const Bra<T> &coff, const int& n)
{	
	Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> Evec;
	std::vector<T> ci;
	Evec = evec(A,B,coff);
	for(int i =0; i<(int)Evec.rows();i++){
		ci.push_back( Evec(i,n));
	}

	return ci;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:  wave_function_H

  Summary:   
  	    
  Args:      
  	      
  Returns:  
------------------------------------------------------------------*/
template<typename T>
T  wave_function_H(const QM_operator<T>& A, const QM_operator<T> &B, const Bra<T> &coff, const double& x, const int& n)
{ 	
	std::vector<T> ci;
	ci = coefficients(A,B,coff,n);
	T res=0.0;

	for(int i=0; i<(int)ci.size(); i++){
		res += ci[i]*wave_function(i,x);
	}
	return res;
}

		

}//end namespace Quantaplus
#endif  

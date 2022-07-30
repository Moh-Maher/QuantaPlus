/*******************************************************************************************
some of "operators.h" meathods implementation.

ref: [N. Zettili, “Quantum Mechanics, Concepts and Applications,” Wiley, Chichester, 2001.]

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
//#pragma once
#ifndef QUANTAPLUS_INCLUDE_OPERATORS_HPP
#define QUANTAPLUS_INCLUDE_OPERATORS_HPP

#ifndef QUANTAPLUS_INCLUDE_OPERATORS_H
#error __FILE__ should only be included from operators.h.
#endif // OPERATORS_H

//--------------------------------------------------------------------------
//		QM_operator defult constructor
//--------------------------------------------------------------------------
/*template<class T>
QM_operator<T>::QM_operator(): 
	Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>(){};
//--------------------------------------------------------------------------
//	 QM_operator constructor with a given rows and cols
//--------------------------------------------------------------------------
template<class T>
QM_operator<T>::QM_operator(int row, int col):
	Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>(row,col){};
//--------------------------------------------------------------------------
//	 
//--------------------------------------------------------------------------

template<class T>
QM_operator<T>::~QM_operator(){};
*/
//---------------------------------------------------------------------------------------------
//
//---------------------------------------------------------------------------------------------
int KroneckerDelta(const int & i, const int & j)
{
	if  (i==j){return (1);}
	else 
	return (0);
}
//---------------------------------------------------------------------------------------------
//Harmonic Oscillator Matrix Elements
//---------------------------------------------------------------------------------------------
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

//---------------------------------------------------------------------------------------------
//Position Operator
//---------------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------------
// Momentum Operator
//---------------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------------
// Lowering Operator
//---------------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------------
// Rising Operator
//---------------------------------------------------------------------------------------------
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

//---------------------------------------------------------------------------------------------
// Hamiltonian 
//---------------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------------
//Eignvalues
//---------------------------------------------------------------------------------------------
template<typename T>
Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> eval(QM_operator<T>& A)
{
	return QuantumEigenValue(A);
}
//---------------------------------------------------------------------------------------------
//Eignvectors 
//---------------------------------------------------------------------------------------------
template<typename T>
Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> evec(QM_operator<T>& A)
{
	return QuantumEigenVector(A);
}
//---------------------------------------------------------------------------------------------
//Eignvectors
//---------------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------------
// wave_function
//---------------------------------------------------------------------------------------------
double wave_function(const int& n,const double& x)
{ 
	return (1./pow(M_PI,0.25)) *(1/(sqrt(pow(2,n))*Factorial(n)))*std::hermite(n,x)*exp(-pow(x,2)/2.);
}
/*double wave_function(const int& n,const double& x)
{ 
	return sqrt(2)*sin(n*M_PI*x);
}*/
//---------------------------------------------------------------------------------------------
//coefficients
//---------------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------------
//wave_function_H
//---------------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------
//				Kronecker-Product
//---------------------------------------------------------------------------
template <class T>
Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> 
KroneckerProduct( const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> & mt1, 
		  const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> & mt2)
{   
	int rowA = (int)mt1.rows();
	int colA = (int)mt1.cols();
	int rowB = (int)mt2.rows();
	int colB = (int)mt2.cols();
	Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>  res((rowA*rowB),(colA*colB));
	for (int i = 0; i < rowA; i++)
	{
		for (int k = 0; k < rowB; k++) ///<-------- k loops till rowb
		{
			for (int j = 0; j < colA; j++)  ///<-------- j loops till cola
			{
				for (int l = 0; l < colB; l++)  ///<-------- l loops till colb
				{
					res(i*rowB+k,j*colB+l)=mt1(i,j)*mt2(k,l); 	   		
				}
			}
		}
	}
	return res;    
}
//---------------------------------------------------------------------------
//				Kronecker-Product
//---------------------------------------------------------------------------
template <class T>
Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> 
KroneckerProduct( const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> & mt1, 
		  const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> & mt2, const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> & mt3)
{   
	Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> temp = KroneckerProduct(mt1,mt2) ;
	return KroneckerProduct(temp,mt3);
}
//--------------------------------------------------------------------------
//		Identity matrix
//--------------------------------------------------------------------------
template<typename T>
Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> Id(const double& Spin)
{
	return Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>::Identity( int(2*Spin+1), int(2*Spin+1));
}
#endif // OPERATORS_TPP

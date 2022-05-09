/****************************************************************************
BraKet.tpp is a part of QUANTA-x library. 

usage: provides implementation details for bra and ket spaces.

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                         
****************************************************************************/

//#include"braket.h"
#pragma once
#ifndef BRAKET_TPP
#define BRAKET_TPP

#ifndef BRAKET_H
#error __FILE__ should only be included from braket.h.
#endif // BRAKET_H

inline void cplx_print(std::complex<double> a)
{
	double x = std::real(a);
	double y = std::imag(a);   
	if(x!=0 and y!=0)
    	{
        	if(y<0)
        	{
            		std::cout<<x<<y<<"i"<<"\t";
        	}

        	else if(y>0)
        	{	
            		std::cout<<x<<"+" <<y<<"i"<<"\t";
        	}
	}
   	else if(y==0)
    	{   
        	std::cout<<x<<"\t";
    	}
    	else if(x==0)
    	{
        	std::cout<<y<<"i"<<"\t"; 
    	}    
}	
//--------------------------------------------------------------------------
//		print  matrix elements in symbolic form
//--------------------------------------------------------------------------
template <typename U,int Q,int W>
void cplx_show(Eigen::Matrix<U,Q,W>& mt)
{
	for(int i =0; i<Q; i++)
    	{
        	for(int j =0; j<W; j++)
        	{
			cplx_print(mt(i,j));
        	}
        	std::cout<<std::endl;
    	}
}
//--------------------------------------------------------------------------
//		print complex numbers in symbolic form
//--------------------------------------------------------------------------
void cplx_show(const std::complex<double> &a)
{
	cplx_print(a);
}
//##########################################################################
// class ket:
//##########################################################################
//--------------------------------------------------------------------------
//		defult constructor
//--------------------------------------------------------------------------
template <class T, int R>
ket<T,R>::ket():Eigen::Matrix<T,R,1>(){}
//--------------------------------------------------------------------------
//		Constructor for ket vector of a given rows
//--------------------------------------------------------------------------
template <class T, int R>
ket<T,R>::ket(int row):Eigen::Matrix<T,R,1>(row,1){}
//--------------------------------------------------------------------------
//		2nd overloded constructor
//--------------------------------------------------------------------------
//template <class T, int R>
//ket<T,R>::ket(const T *data ):Eigen::Matrix<T,R,1>(data){}
//--------------------------------------------------------------------------
//		destructor
//--------------------------------------------------------------------------
template <class T, int R>
ket<T,R>::~ket(){}

 
//##########################################################################
// class bra :
//##########################################################################
//--------------------------------------------------------------------------
//		defult constructor
//--------------------------------------------------------------------------
template <class T, int C>
bra<T,C>::bra():Eigen::Matrix<T,1,C>(){}
//--------------------------------------------------------------------------
//		Constructor for bra vector of a given rows
//--------------------------------------------------------------------------
template <class T, int C>
bra<T,C>::bra(int col):Eigen::Matrix<T,1,C>(1,col){}
//--------------------------------------------------------------------------
//		2nd overloded constructor
//--------------------------------------------------------------------------
//template <class T, int C>
//bra<T,C>::bra(const T *data ):Eigen::Matrix<T,1,C>(data){}
//--------------------------------------------------------------------------
//		destructor
//--------------------------------------------------------------------------
template <class T, int C>
bra<T,C>::~bra(){}
 
//------------------------------------------------------------------------------------
// compute the Eigen vectors for Eigen::Matrix
//------------------------------------------------------------------------------------
template<typename T, int R, int C>
Eigen::Matrix<T, R, 1> QuantxEigenVector(Eigen::Matrix<T, R, C> &mat, const int &i)
{
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix<T, R, C>> eigensolver(mat);
   
	if (eigensolver.info() != Eigen::Success) abort();
  
	return eigensolver.eigenvectors().col(i);
}
//------------------------------------------------------------------------------------
// compute the Eigen value for Eigen::Matrix
//------------------------------------------------------------------------------------
template<typename T, int R, int C>
T QuantxEigenValue(Eigen::Matrix<T, R, C>  &mat,const int& i)
{
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix<T, R, C> > eigensolver(mat);
   
	if (eigensolver.info() != Eigen::Success) abort();
   
	return eigensolver.eigenvalues()[i];
}
//--------------------------------------------------------------------------
//##############	ket dual Conjugate	#########################
//--------------------------------------------------------------------------
template <typename T, int R>
bra<T,R> DualConj(const ket<T,R> &kt)
{
	bra<T,R> res(kt.rows());

	for (int i=0; i<kt.rows(); i++)
    	{
		res(i) = std::conj(kt(i));
	}
	return res;
}
//--------------------------------------------------------------------------
//#############	bra dual Conjugate	#########################
//--------------------------------------------------------------------------
template <typename T, int C>
ket<T,C> DualConj(const bra<T,C> &b)
{
	ket<T,C> res(b.cols());

	for (int i=0; i<b.cols(); i++)
	{
		res(i) = std::conj(b(i));
	}
	return res;
}
//--------------------------------------------------------------------------
//#############	Bra-Ket		#########################
//--------------------------------------------------------------------------
template <typename T, int R,int C> 
T BraKet(const bra<T,C> &b, const ket<T,R> &kt)
{     
	if(b.cols()!=kt.rows()){ throw std::invalid_argument("dimensions do not match."); }
	
	T sum = static_cast<T>(0.0);

	for(int i = 0; i < b.rows(); ++i)
	{
		for(int j = 0; j < kt.cols(); ++j)
		{
			for(int k = 0; k < (b.rows()*b.cols()); ++k)
    			{
   	        		sum += b(i,k) * kt(k,j);
            		}	
        	}
    	}
	return sum;    
}
#endif // BRAKET_TPP

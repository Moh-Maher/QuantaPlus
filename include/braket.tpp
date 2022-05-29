/****************************************************************************
BraKet.tpp is a part of QUANTAPLUS library. 

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

//--------------------------------------------------------------------------
//	print complex number in symbolic form
//--------------------------------------------------------------------------
inline void cplx_print(std::complex<double> a)
{
	double x = std::real(a);
	double y = std::imag(a);   
	if(x!=0 and y!=0)
    	{
        	if(y<0)
        	{
            		std::cout<<x<<y<<"i"<<"\t";
            		//decimalToFraction(x);
            		//decimalToFraction(y);
            		//std::cout<<"i"<<"\t";
        	}

        	else if(y>0)
        	{
            		std::cout<<x<<"+" <<y<<"i"<<"\t";
            		//decimalToFraction(x);
            		//std::cout<<"+";
            		//decimalToFraction(y);
            		//std::cout<<"i"<<"\t";
        	}
	}
   	else if(y==0)
    	{   
        	std::cout<<x<<"\t";
        	//decimalToFraction(x);
        	//std::cout<<"\t";
           
    	}
    	else if(x==0)
    	{
        	std::cout<<y<<"i"<<"\t"; 
        	
		//decimalToFraction(y);
    		//std::cout<<"i"<<"\t";
    	}    
}	
//--------------------------------------------------------------------------
//	print  matrix elements in symbolic form
//--------------------------------------------------------------------------
template <typename U>
void result_printf(bra<U>& mt)
{
	for(int i =0; i<mt.rows(); i++)
    	{
        	for(int j =0; j<mt.cols(); j++)
        	{
			cplx_print(mt(i,j));
        	}
        	std::cout<<std::endl;
    	}
}
//--------------------------------------------------------------------------
//	print  ket elements in symbolic form
//--------------------------------------------------------------------------
template <typename U>
void result_printf(ket<U>& mt)
{
	for(int i =0; i<mt.rows(); i++)
    	{
        	for(int j =0; j<mt.cols(); j++)
        	{
			cplx_print(mt(i,j));
        	}
        	std::cout<<std::endl;
    	}
}
//--------------------------------------------------------------------------
//  	function print QuantaPlus variables in a symbolic form.
//  	this function is a modified version of "Variadic functions" from:
//  	https://en.cppreference.com/w/cpp/utility/variadic 
//--------------------------------------------------------------------------
void literal_printf(const char* fmt...) 
{
	va_list args;
	va_start(args, fmt);

	while (*fmt != '\0') {
		if (*fmt == 'k') {
			ket<std::complex<double>> kt = va_arg(args, ket<std::complex<double>>);
			std::cout<<"|ket> =\n";
			result_printf(kt);
			std::cout<<"\n";
		} 
		else if (*fmt == 'b') {
			bra<std::complex<double>> br = va_arg(args, bra<std::complex<double>>);
			std::cout<<"<bra| = ";
			result_printf(br);
			std::cout<<"\n";
		}
		else if (*fmt == 'c') {
			std::complex<double> d = va_arg(args, std::complex<double>);
			std::cout<<"complex number = ";
			cplx_print(d);
			std::cout<<"\n";
		}		
		++fmt;
	}

	va_end(args);
}
//--------------------------------------------------------------------------
//	print  bra elements in symbolic form
//--------------------------------------------------------------------------
template <typename U>
void result_printf(Eigen::Matrix<U,Eigen::Dynamic,Eigen::Dynamic>& mt)
{
	for(int i =0; i<mt.rows(); i++)
    	{
        	for(int j =0; j<mt.cols(); j++)
        	{
			cplx_print(mt(i,j));
        	}
        	std::cout<<std::endl;
    	}
}
//--------------------------------------------------------------------------
//	print complex numbers in symbolic form
//--------------------------------------------------------------------------
void result_printf(const std::complex<double> &a)
{
	cplx_print(a);
	std::cout<<std::endl;
}
//##########################################################################
// class ket:
//##########################################################################
//--------------------------------------------------------------------------
//		defult constructor
//--------------------------------------------------------------------------
template <class T>
ket<T>::ket():Eigen::Matrix<T,Eigen::Dynamic,1>(){}
//--------------------------------------------------------------------------
//		Constructor for ket vector of a given rows
//--------------------------------------------------------------------------
template <class T>
ket<T>::ket(int row):Eigen::Matrix<T,Eigen::Dynamic,1>(row,1){}
//--------------------------------------------------------------------------
//		2nd overloded constructor
//--------------------------------------------------------------------------
//template <class T, int R>
//ket<T,R>::ket(const T *data ):Eigen::Matrix<T,R,1>(data){}
//--------------------------------------------------------------------------
//		destructor
//--------------------------------------------------------------------------
template <class T>
ket<T>::~ket(){}
//--------------------------------------------------------------------------
//		Overloaded Operator "=" : |ket> = |ket>
//--------------------------------------------------------------------------
/*
template <class T>
ket<T>& ket<T>::operator=(const ket<T>& kt)
{	
	ket<T> res(kt.rows());
    	if(this!=&kt)
    		for(int i =0; i<kt.rows(); i++)
        	{
            		for(int j =0; j<kt.cols(); j++)
            		{
  	          		res(i,j)=kt(i,j);
            		}
        	} 
    	    
	return res;  
	
	//return *this;     
}
*/
//--------------------------------------------------------------------------
// Overloading the  + OPERATOR: result in |A>+ |B>
//--------------------------------------------------------------------------
/*
template <class T>
inline ket<T> operator+(ket<T> lhs_ket, const ket<T>& rhs_ket) 
{
	return lhs_ket += rhs_ket;
	//return lhs_ket;
}
*/
//************************************************************************** 

//##########################################################################
// class bra :
//##########################################################################
//--------------------------------------------------------------------------
//		defult constructor
//--------------------------------------------------------------------------
template <class T>
bra<T>::bra():Eigen::Matrix<T,1,Eigen::Dynamic>(){}
//--------------------------------------------------------------------------
//		Constructor for bra vector of a given rows
//--------------------------------------------------------------------------
template <class T>
bra<T>::bra(int col):Eigen::Matrix<T,1,Eigen::Dynamic>(1,col){}
//--------------------------------------------------------------------------
//		2nd overloded constructor
//--------------------------------------------------------------------------
//template <class T, int C>
//bra<T,C>::bra(const T *data ):Eigen::Matrix<T,1,C>(data){}
//--------------------------------------------------------------------------
//		destructor
//--------------------------------------------------------------------------
template <class T>
bra<T>::~bra(){}
 
//------------------------------------------------------------------------------------
// compute the Eigen vectors for Eigen::Matrix
//------------------------------------------------------------------------------------
template<typename T, int R, int C>
Eigen::Matrix<T, R, 1> QuantumEigenVector(Eigen::Matrix<T, R, C> &mat, const int &i)
{
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix<T, R, C>> eigensolver(mat);
   
	if (eigensolver.info() != Eigen::Success) abort();
  
	return eigensolver.eigenvectors().col(i);
}
//------------------------------------------------------------------------------------
// compute the Eigen value for Eigen::Matrix
//------------------------------------------------------------------------------------
template<typename T, int R, int C>
T QuantumEigenValue(Eigen::Matrix<T, R, C>  &mat,const int& i)
{
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix<T, R, C> > eigensolver(mat);
   
	if (eigensolver.info() != Eigen::Success) abort();
   
	return eigensolver.eigenvalues()[i];
}
//--------------------------------------------------------------------------
//##############	ket dual Conjugate	#########################
//--------------------------------------------------------------------------
template <typename T>
bra<T> DualConj(const ket<T> &kt)
{
	bra<T> res(kt.rows());
        /*
	for (int i=0; i<kt.rows(); i++)
    	{
		res(i) = std::conj(kt(i));
	}
	return res;
	*/
	res << kt.adjoint();
	return res;
}
//--------------------------------------------------------------------------
//#############	bra dual Conjugate	#########################
//--------------------------------------------------------------------------
template <typename T>
ket<T> DualConj(const bra<T> &br)
{
	ket<T> res(br.cols());
        /*
	for (int i=0; i<b.cols(); i++)
	{
		res(i) = std::conj(b(i));
	}
	return res;
	*/
	res<<br.adjoint();
	return res;
}
//--------------------------------------------------------------------------
//#############	Bra-Ket		#########################
//--------------------------------------------------------------------------
template <typename T> 
T BraKet(const bra<T> &br, const ket<T> &kt)
{     
	if(br.cols()!=kt.rows()){ throw std::invalid_argument("dimensions do not match."); }
	/*
	T sum = static_cast<T>(0.0);

	for(int i = 0; i < br.rows(); ++i)
	{
		for(int j = 0; j < kt.cols(); ++j)
		{
			for(int k = 0; k < (br.rows()*br.cols()); ++k)
    			{
   	        		sum += br(i,k) * kt(k,j);
            		}	
        	}
    	}
	return sum; 
	*/
	return br*kt;   
}
 
#endif // BRAKET_TPP

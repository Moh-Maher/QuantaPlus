/*!*****************************************************************
* \file operators.h
* Define fundamental quantum operators.
*
* \cite zettili2003quantum 
******************************************************************/

/*---------------------------------------------------------------------------
by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
---------------------------------------------------------------------------*/
//#pragma once
#ifndef QUANTAPLUS_OPERATORS_H
#define QUANTAPLUS_OPERATORS_H
#include <Eigen/Dense>
#include <unsupported/Eigen/MatrixFunctions>
#include<complex>
#include"braket.h"
#include<cmath>
#include<vector>

namespace QuantaPlus{

/*!*****************************************************************
* \class QM_operator
* \brief QM_operator is a publicly derived class from Eigen::Matrix, 
*
* QM_operator are square matrices with Dynamic-size.
******************************************************************/
template<class T>
class QM_operator: public Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>
{
	public:
		/*!
	        * Create an empty one matrix. Dynamically allocate numbers of rows and columns at run-time.
	        */ 
		QM_operator():Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>(){} ///<Default constructor.
		
		/*!\brief Constructor with fixed Number of rows and columns.
	        * Create an empty one matrix. Dynamically Allocate  fixed numbers of rows and columns at compile-time.
	        * @param row is the Number of rows.
	        * @param col is the Number of columns.
                \code{.cpp}
		using namespace std::complex_literals; //needed to use the literal imaginary unit [ 1i = sqrt(-1)] 
		
		int N = 4; //fix the number of dimensions = 4.
		
		QuantaPlus::QM_operator<complex> plus(N,N), minus(N,N); // declaration of two (4 x 4) operators. 
		
		//Quantum harmonic oscillator – Ladder operators: 
		plus  = QuantaPlus::RisingOperator<complex>(N,N); // initialize operator plus to take the value of the (Harmonic oscillator) rising operator after compute it in 4 dimensions.
		minus = QuantaPlus::LoweringOperator<complex>(N,N); // initialize operator minus to the value of the (4 x 4) lowering operator of the Harmonic oscillator after compute it.
		
		cout<<"[ RisingOperator: ]"<<endl;
		
		QuantaPlus::ResultPrint(plus);
		
		cout<<"-------------------"<<endl;

		cout<<"[ LoweringOperator: ]"<<endl;
		
		QuantaPlus::ResultPrint(minus);
		
		cout<<"-------------------"<<endl;
	
	        \endcode
	        \verbatim
		[ RisingOperator: ]
		0	0	0	0	
		1	0	0	0	
		0	√2	0	0	
		0	0	√3	0	
		-------------------
		[ LoweringOperator: ]
		0	1	0	0	
		0	0	√2	0	
		0	0	0	√3	
		0	0	0	0	
		-------------------

	        \endverbatim
	        
	        @see QuantaPlus::RisingOperator(const int& R, const int& C)
	        @see QuantaPlus::LoweringOperator(const int& R, const int& C)
	        */
		QM_operator(int row,int col):Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>(row,col){}
		
		
		template<typename Derived> 
		QM_operator(const Eigen::MatrixBase<Derived>& other)
		:Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>(other){ } ///< construct QM_operator from Eigen expressions.
	 
	    	/*!Assign Eigen expressions to QM_operators*/
		template<typename Derived>
		QM_operator& operator=(const Eigen::MatrixBase <Derived>& other)
		{
			this->Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>::operator=(other);
			return *this;
		} 
		~QM_operator(){} ///< Destructor
};

#include"include/operators.hpp"
} //end of namespace QuantaPlus
#endif

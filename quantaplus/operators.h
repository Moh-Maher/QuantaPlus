/*!\file operators.h
* Define and handle some fundamental quantum operators.
ref: [N. Zettili, “Quantum Mechanics, Concepts and Applications,” Wiley, Chichester, 2001.]
*/

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

/*! \class QM_operator
* QM_operator is a publicly derived class from the well designed Eigen::Matrix, 
* represents matrices with Dynamic-size.
*/
template<class T>
class QM_operator: public Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>
{
	public:
		 
		QM_operator():Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>(){} ///<Default constructor.
		
		QM_operator(int row,int col):Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>(row,col){} ///< Constructor with row and column input. 
		
		template<typename Derived> 
		QM_operator(const Eigen::MatrixBase<Derived>& other)
		:Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>(other){ } ///<construct QM_operator from Eigen expressions.
	 
	    	/*!Assign Eigen expressions to QM_operators*/
		template<typename Derived>
		QM_operator& operator=(const Eigen::MatrixBase <Derived>& other)
		{
			this->Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>::operator=(other);
			return *this;
		} 
		~QM_operator(){}
};

#include"include/operators.hpp"
} //end of namespace QuantaPlus
#endif

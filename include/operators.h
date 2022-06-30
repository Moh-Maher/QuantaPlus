/*******************************************************************************************
@operator.h is a part of QUANTAPLUS library. 

usage: define and handle some fundamental quantum operators.

ref: [N. Zettili, “Quantum Mechanics, Concepts and Applications,” Wiley, Chichester, 2001.]

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
//#pragma once
#ifndef QUANTAPLUS_INCLUDE_OPERATORS_H
#define QUANTAPLUS_INCLUDE_OPERATORS_H
#include <Eigen/Dense>
#include <unsupported/Eigen/MatrixFunctions>
#include<complex>
#include"braket.h"
#include<cmath>
#include<vector>

//namespace QuantaPlus{
template<class T>
class QM_operator: public Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>
{
	public:
		QM_operator();
		QM_operator(int row,int col);
		//<--This constructor allows us to construct QM_operator from Eigen expressions
		template<typename Derived>
		QM_operator(const Eigen::MatrixBase<Derived>& other)
		:Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>(other){ }
	   	//Ket(const T *data );
	   	 
	    	//<--This method allows us to assign Eigen expressions to QM_operators
		template<typename Derived>
		QM_operator& operator=(const Eigen::MatrixBase <Derived>& other)
		{
			this->Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>::operator=(other);
			return *this;
		} 
		~QM_operator();
};

#include"operators.hpp"
//} //end of namespace QuantaPlus
#endif

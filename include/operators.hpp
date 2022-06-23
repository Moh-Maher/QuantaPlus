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
template<class T>
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

#endif // OPERATORS_TPP

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
//#include <unsupported/Eigen/MatrixFunctions>
#include <Eigen/Dense>
//#include"utilities.h"

//namespace QuantaPlus{
template<class T>
class QM_operator: public Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>
{
public:
	QM_operator();
	QM_operator(int row,int col);
	~QM_operator();
};

#include"operators.hpp"
//} //end of namespace QuantaPlus
#endif

/**************************************************************************************
BraKet.h is a part of QUANTA-x library. 

usage: define and handle some fundamental operations on bra and ket vectors.

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
**************************************************************************************/
#pragma once
#ifndef BRAKET_H
#define BRAKET_H
#include <Eigen/Dense>
//#include"matrix.h"
  
//namespace QUANTAx {
//####################################################################################
// ket class:
//####################################################################################
template <class T, int R>
class ket : public Eigen::Matrix<T, R, 1> 
{
public:
	ket();
	ket(int row); 
   // ket(const T *data ); 
	~ket();      
};
//####################################################################################
// bra class:
//####################################################################################
template <class T, int C>
class bra : public Eigen::Matrix<T, 1, C>  
{
public:
	bra();
	bra(int col); 
   // bra(const T *data ); 
	~bra();
     
};
#include"braket.tpp"
//} //end of namespace QUANTAx
#endif

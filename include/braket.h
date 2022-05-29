/**************************************************************************************
BraKet.h is a part of QUANTAPLUS library. 

usage: define and handle some fundamental operations on bra and ket vectors.

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
**************************************************************************************/
//#pragma once
#ifndef BRAKET_H
#define BRAKET_H
#include <Eigen/Dense>
#include <algorithm>
#include <cstdarg>

//namespace QuantaPlus {
//####################################################################################
// ket class:
//####################################################################################
template <class T>
class ket : public Eigen::Matrix<T,Eigen::Dynamic,1> 
{
public:
	ket();
	ket(int row); 
   	//ket(const T *data ); 
	~ket();
	//ket<T>& operator= (const ket<T>& kt);
	/*ket<T>& operator+=(const ket<T>& rhs_ket)
  	{
    		// actual addition of rhs_ket to *this
		return *this;
  	}*/      
};
//####################################################################################
// bra class:
//####################################################################################
template <class T>
class bra : public Eigen::Matrix<T,1, Eigen::Dynamic> 
{
public:
	bra();
	bra(int col); 
   	// bra(const T *data ); 
	~bra();  
};
#include"braket.tpp"
//} //end of namespace QuantaPlus
#endif

/*###########################################################################
  File:      BRAKET.H

  Summary:   Define and handle some fundamental operations on Bra and 
  	     ket vectors.
  	     
  Classes:   ket and Bra.  

  by:  	     Mohammed Maher Abdelrahim Mohammed
       	     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
	     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
       	     mohammed.maher@unical.it  
###########################################################################*/
//#pragma once
#ifndef QUANTAPLUS_INCLUDE_BRAKET_H
#define QUANTAPLUS_INCLUDE_BRAKET_H
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>
#include <algorithm>
#include <cstdarg>
#include"utilities.h"
//#include"operators.h"
namespace QuantaPlus {

/*! \class Ket 
* Ket is a publicly derived class from the well designed Eigen::Matrix,
* where the Ket vectors are matrices with one column and Dynamic-size rows,
*/
template <class T>
class Ket : public Eigen::Matrix<T,Eigen::Dynamic,1> 
{
	public:
		Ket():Eigen::Matrix<T,Eigen::Dynamic,1>(){ } ///< Default constructor
		Ket(int row):Eigen::Matrix<T,Eigen::Dynamic,1>(row,1){ } ///< constructor with row number
		
		template<typename Derived> 
		Ket(const Eigen::MatrixBase<Derived>& other)
		:Eigen::Matrix<T,Eigen::Dynamic,1>(other){ } ///< Construct Ket from Eigen expressions
	   	 
	    	/*!
	    	*  Allows us to assign Eigen expressions to Ket
	    	*/
		template<typename Derived>
		Ket& operator=(const Eigen::MatrixBase <Derived>& other)
		{
			this->Eigen::Matrix<T,Eigen::Dynamic,1>::operator=(other);  
			return *this;
		}
		/*!overloading the logical "=="operator */
		bool operator ==(const Ket<T>& ket) const 
       		{
            		return this->Eigen::Matrix<T,Eigen::Dynamic,1>::operator==(ket);
        	}
        	 
		~Ket(){} ///<destructor     
};

/*! \class Bra
*  Bra is a publicly derived class from the well designed Eigen::Matrix,
* where the Bra vectors are matrices with one row, and Dynamic-size column.
*/
template <class T>
class Bra : public Eigen::Matrix<T,1, Eigen::Dynamic> 
{
	public:
		Bra():Eigen::Matrix<T,1,Eigen::Dynamic>(){} ///<Default constructor
		Bra(int col):Eigen::Matrix<T,1,Eigen::Dynamic>(1,col){} ///<Constructor with column number
		
		template<typename Derived>
		Bra(const Eigen::MatrixBase<Derived>& other)
		:Eigen::Matrix<T,1,Eigen::Dynamic>(other){ } ///< Construct Bra from Eigen expressions
	   	
	   	/*!
	    	*  Assign Eigen expressions to Bra
	    	*/
		template<typename Derived>
		Bra& operator=(const Eigen::MatrixBase <Derived>& other)
		{
			this->Eigen::Matrix<T,1 ,Eigen::Dynamic>::operator=(other);
			return *this;
		}
		/*! overloading the logical "=="operator */
		bool operator ==(const Bra<T>& bra) const 
		{
            		return this->Eigen::Matrix<T,1,Eigen::Dynamic>::operator==(bra);	 
		}
		~Bra(){} ///<destructor
};
#include"braket.hpp"
} //end of namespace QuantaPlus
#endif

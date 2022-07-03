/*###########################################################################
  File:      BraKET.H

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
//namespace QuantaPlus {

/***************************************************************************
  Class:    Ket.

  Summary:  Ket is a publicly derived class from the well designed Eigen::Matrix. 
	    Ket vectors represent matrices with one column and Dynamic-size rows,

  Methods:  MyMethodOne
              Short description of MyMethodOne.
            MyMethodTwo
              Short description of MyMethodTwo.
            Ket
              Constructor.
            ~Ket
              Destructor.
***************************************************************************/
template <class T>
class Ket : public Eigen::Matrix<T,Eigen::Dynamic,1> 
{
	public:
		Ket():Eigen::Matrix<T,Eigen::Dynamic,1>(){ } //default constructor
		Ket(int row):Eigen::Matrix<T,Eigen::Dynamic,1>(row,1){ } //constructor with row number
		
		//<-- This constructor allows us to construct Ket from Eigen expressions
		template<typename Derived> 
		Ket(const Eigen::MatrixBase<Derived>& other)
		:Eigen::Matrix<T,Eigen::Dynamic,1>(other){ }
	   	//Ket(const T *data );
	   	 
	    	//<-- This method allows us to assign Eigen expressions to Ket
		template<typename Derived>
		Ket& operator=(const Eigen::MatrixBase <Derived>& other)
		{
			this->Eigen::Matrix<T,Eigen::Dynamic,1>::operator=(other);  
			return *this;
		}
		//<-- overloading the logical == operator 
		bool operator ==(const Ket<T>& ket) const
       		{
            		return this->Eigen::Matrix<T,Eigen::Dynamic,1>::operator==(ket);
        	}
        	/*
        	struct Loader {
			Ket<T>& m;
			int i;
			Loader(Ket<T>& m, int i) : m(m), i(i) {}
			Loader operator , (T x) {
			
				kt(i%(int)m.rows(),1) = x;
				return Loader(m, i+1);
			}
		};
		Loader operator>(T x) {
			
			kt(0,1) = x;
			return Loader(*this, 1);
		}
        	*/
		~Ket(){} //destructor     
};
/*
template<class T>
std::ostream& operator<<(std::ostream& out, Ket<T>& mf){
	for(int i=0;i<(int)mf.rows();i++){
		out<<mf(i)<<"\t";
	}
	out<<"\n";
	return out;
}
*/
/***************************************************************************
  Class:    Bra.

  Summary:  Bra is a publicly derived class from the well designed Eigen::Matrix. 
	    Bra vectors are matrices with one row, and Dynamic-size column.

  Methods:  MyMethodOne
              Short description of MyMethodOne.
            MyMethodTwo
              Short description of MyMethodTwo.
            Bra
              Constructor.
            ~Bra
              Destructor.
***************************************************************************/
template <class T>
class Bra : public Eigen::Matrix<T,1, Eigen::Dynamic> 
{
	public:
		Bra():Eigen::Matrix<T,1,Eigen::Dynamic>(){} //default constructor
		Bra(int col):Eigen::Matrix<T,1,Eigen::Dynamic>(1,col){} //constructor with column number
		//<--This constructor allows us to construct Bra from Eigen expressions
		template<typename Derived>
		Bra(const Eigen::MatrixBase<Derived>& other)
		:Eigen::Matrix<T,1,Eigen::Dynamic>(other){ }
	   	
	   	//<--This method allows us to assign Eigen expressions to Ket
		template<typename Derived>
		Bra& operator=(const Eigen::MatrixBase <Derived>& other)
		{
			this->Eigen::Matrix<T,1 ,Eigen::Dynamic>::operator=(other);
			return *this;
		}
		// overloading the logical == operator 
		bool operator ==(const Bra<T>& bra) const
		{
            		return this->Eigen::Matrix<T,1,Eigen::Dynamic>::operator==(bra);	 
		}
		~Bra(){} //destructor
};
#include"braket.hpp"
//} //end of namespace QuantaPlus
#endif

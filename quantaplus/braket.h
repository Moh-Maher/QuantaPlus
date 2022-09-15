/*!**************************************************************************** 
* \file quantaplus/braket.h
* \brief Define and handle some fundamental operations on Bra and  ket vectors.
******************************************************************************/

//-----------------------------------------------------------------------------
// by:	Mohammed Maher Abdelrahim Mohammed
//	UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
//	VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
//	mohammed.maher@unical.it  
//-----------------------------------------------------------------------------

//#pragma once
#ifndef QUANTAPLUS_BRAKET_H
#define QUANTAPLUS_BRAKET_H
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>
#include <algorithm>
#include <cstdarg> // for Variable arguments handling
#include"utilities.h"
//#include"operators.h"
/*!
 *  \addtogroup QuantaPlus
 *  @{
 */
//! Generic QuantaPlus interfaces and implementations
namespace QuantaPlus {

/*!******************************************************************************* 
* \class Ket 
* \brief Ket is a publicly inherited class from the well designed Eigen::Matrix,
* where the Ket vectors are matrices with one column and Dynamic-size rows.
*
* Kets belong to the Hilbert (vector) space H, or, in short, to the ket-space..
*********************************************************************************/
template <class T>
class Ket : public Eigen::Matrix<T,Eigen::Dynamic,1> 
{
	public: 
	        /*!
	        * Create an empty one column vector. Dynamically allocate numbers of rows at run-time.
	        */
		Ket():Eigen::Matrix<T,Eigen::Dynamic,1>(){ }  ///< Default constructor.
		
		/*!\brief Constructor with fixed Number of rows.
	        * Create an empty one column vector. Allocate fixed numbers of rows at compile-time.
	        * @param row is the Number of rows.
                \code{.cpp}
                using namespace std::complex_literals; //needed to use the literal imaginary unit [ 1.i = sqrt(-1)] 
	          
	          QuantaPlus::Ket<std::complex<double>> A(3); //deceleration of (an empty) complex Ket vector |A> with three rows
	        
	          A << 2.5, 3.7, 2.5+3.5i; // initialization of Ket A ,|A> = 2.5, 3.7, 2.5+3.5i
	        
	          ResultPrint(A); // print the content of |A>.
	          
	        \endcode
	        \verbatim
	        5/2
	        37/10
	        5/2+7/2i
	        \endverbatim
	        
	        @see ResultPrint(Ket<U>& ket)
	        */
		Ket(int row):Eigen::Matrix<T,Eigen::Dynamic,1>(row,1){ }
		
		/*!
		* In order to make any Ket object to work within the Eigen framework, 
		we construct Ket from Eigen expressions using Eigen API contained in its base class "Eigen::MatrixBase<Derived>".
		*/
		template<typename Derived> 
		Ket(const Eigen::MatrixBase<Derived>& other)
		:Eigen::Matrix<T,Eigen::Dynamic,1>(other){ } ///< Constructor allows us to construct Ket from Eigen expressions.
	   	 
	    	/*!
	    	*  This method allows us to assign Eigen expressions to Ket
	    	*/
		template<typename Derived>
		Ket& operator=(const Eigen::MatrixBase <Derived>& other)
		{
			this->Eigen::Matrix<T,Eigen::Dynamic,1>::operator=(other);  
			return *this;
		}
		
		bool operator ==(const Ket<T>& ket) const 
       		{
            		return this->Eigen::Matrix<T,Eigen::Dynamic,1>::operator==(ket);
        	}///< Overloading the logical operator ==
        	 
		~Ket(){} ///< Destructor.     
};

/*!***************************************************************************************************
*  \class Bra
*  \brief Bra is a publicly derived class from the well designed Eigen::Matrix,
* where the Bra vectors are matrices with one row, and Dynamic-size column.
*
* while kets belong to the Hilbert space H, the corresponding bras belong to its dual (Hilbert) space.
*****************************************************************************************************/
template <class T>
class Bra : public Eigen::Matrix<T,1, Eigen::Dynamic> 
{
	public:
		/*! 
	        * Create an empty one row vector. Dynamically allocate numbers of columns at run-time.
	        */
		Bra():Eigen::Matrix<T,1,Eigen::Dynamic>(){}  ///< Default constructor.
		
		/*!\brief Constructor with fixed Number of columns.
	        * Create an empty one row vector. Allocate fixed numbers of columns at compile-time.
	        * @param col is the Number of columns.
                \code{.cpp}
                using namespace std::complex_literals; //needed to use the literal imaginary unit [ 1.i = sqrt(-1)] 
	        QuantaPlus::Bra<std::complex<double>> B(3); //deceleration of (an empty) complex Bra vector <B| with three columns.
	        
	        B << 2.5, 3.7, 2.5+3.5i; // initialization of Bra B ,<B| = 2.5, 3.7, 2.5+3.5i
	        
	        ResultPrint(B); // print the content of <B|.
	        
	        \endcode
	        \verbatim
	        5/2	37/10	5/2+7/2i
	        \endverbatim
	        
	        @see ResultPrint(Bra<U>& bra)
	        */
		Bra(int col):Eigen::Matrix<T,1,Eigen::Dynamic>(1,col){}
		
		/*!
		* Construct Bra from Eigen expressions using Eigen API contained in its base class "Eigen::MatrixBase<Derived>".
		* That makes any Bra object to work within the Eigen framework.
		*/
		template<typename Derived>
		Bra(const Eigen::MatrixBase<Derived>& other)
		:Eigen::Matrix<T,1,Eigen::Dynamic>(other){ } ///< Constructor allows us to construct Bra from Eigen expressions.
		
	   	/*!
	    	*  Assign Eigen expressions to Bra
	    	*/
		template<typename Derived>
		Bra& operator=(const Eigen::MatrixBase <Derived>& other)
		{
			this->Eigen::Matrix<T,1 ,Eigen::Dynamic>::operator=(other);
			return *this;
		}
		 
		bool operator ==(const Bra<T>& bra) const 
		{
            		return this->Eigen::Matrix<T,1,Eigen::Dynamic>::operator==(bra);	 
		} ///< Overloading the logical operator ==
		~Bra(){} ///< Destructor.
};
#include"include/braket.hpp"
} //end of namespace QuantaPlus
/*! @} End of Doxygen Groups*/
#endif

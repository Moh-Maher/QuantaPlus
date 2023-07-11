//=================================================================================================
/*!
//  \file quantaplus/braket/bra.h
//  \brief Fundamental operations on Bra vectors.
//
//  Copyright (c) 2022 Mohammed Maher Abdelrahim Mohammed
//  
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//  
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
*/
//=================================================================================================

#ifndef QUANTAPLUS_BRAKET_BRA_H
#define QUANTAPLUS_BRAKET_BRA_H

//-------------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------------
#include<Eigen/Dense>
#include"../utilities/print.h"

///***********************************
// NAMESPACE QUANTAPLUS DOCUMENTATION 
//************************************
/*!
 * \addtogroup QuantaPlus
 *  @{
 */
//! Generic QuantaPlus interfaces and implementations
namespace QuantaPlus {

//-------------------------------------------------------------------------------------------------
//  CLASS DEFINITION
//-------------------------------------------------------------------------------------------------

//*************************************************************************************************
/*! \brief Bra is a publicly derived class from the well designed Eigen::Matrix,
*  where the Bra vectors are matrices with one row, and Dynamic-size column.
*
* \note While Kets belong to the Hilbert space \f$H\f$, 
* the corresponding Bras belong to its dual (Hilbert) space\f$H_d\f$.
*/
template <class T = std::complex<double>>
class Bra : public Eigen::Matrix<T,1, Eigen::Dynamic> 
{
  public:	 
        //**Constructors***************************************************************************
	/*!\name Constructors */
	//@{
	Bra();
	Bra(int col);	
   	//@}
	//*****************************************************************************************
	
	
	//-----------------------------------------------------------------------------------------
	/*!\brief Constructor allows us to construct Bra from Eigen expressions.
	*  Construct Bra from Eigen expressions using Eigen API contained in its 
	*  base class "Eigen::MatrixBase<Derived>".
	*  That makes any Bra object to work within the Eigen framework.
	*/
	template<typename Derived>
	Bra(const Eigen::MatrixBase<Derived>& other)
	:Eigen::Matrix<T,1,Eigen::Dynamic>(other){ }
	//*****************************************************************************************
	
	
   	//-----------------------------------------------------------------------------------------
   	/*!
    	*  Assign Eigen expressions to Bra
    	*/
	template<typename Derived>
	Bra& operator=(const Eigen::MatrixBase <Derived>& other)
	{
		this->Eigen::Matrix<T,1 ,Eigen::Dynamic>::operator=(other);
		return *this;
	}
	
	/*!\brief Overloading the logical operator == */
	bool operator ==(const Bra<T>& bra) const 
	{
    		return this->Eigen::Matrix<T,1,Eigen::Dynamic>::operator==(bra);	 
	} 
	//**************************************************************************************** 
	
	void Print(); ///< Print <Bra| elements in fractional symbolic form
	void NPrint(); ///< Print <Bra| elements in fractional fractional numeric form
	
	//**Destructor***************************************************************************** 
	/*!\name Destructor */
   	//@{
	~Bra() = default; 
	//@}
   	//***************************************************************************************** 
};
//*************************************************************************************************



//-------------------------------------------------------------------------------------------------
//  CONSTRUCTORS
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
/*!\brief The default constructor of the Bra class.
*/
template <class T>
Bra<T>::Bra():Eigen::Matrix<T,1,Eigen::Dynamic>()
{}
//*************************************************************************************************

//-------------------------------------------------------------------------------------------------
/*!\brief Constructor with fixed Number of columns.
* Create an empty one row vector. Allocate fixed numbers of columns at compile-time.
* @param col is the Number of columns.
* 
\code{.cpp}
using namespace std::complex_literals; //needed to use the literal imaginary unit [ 1.i = sqrt(-1)] 
QuantaPlus::Bra<std::complex<double>> B(3); //deceleration of (an empty) complex Bra vector <B| with three columns.

B << 2.5, 3.7, 2.5+3.5i; // initialization of Bra B ,<B| = 2.5, 3.7, 2.5+3.5i

ResultPrint(B); // print the content of <B|.
*
\endcode
\verbatim
5/2	37/10	5/2+7/2i
\endverbatim
*
* @see ResultPrint(Bra<U>& bra)
*/
template <class T>
Bra<T>::Bra(int col):Eigen::Matrix<T,1,Eigen::Dynamic>(1,col)
{}
//*************************************************************************************************


/*!**************************************************************** 
* Print \f$<Bra |\f$ elements in fractional symbolic form 
* \f$z =\frac{A}{B} + i\frac{C}{D}\f$, where \f$i = \sqrt{-1}\f$;
******************************************************************/
template <class T>
void Bra<T>::Print()
{
	for(int row_count = 0; row_count < this->rows(); row_count++)
	{	Bra<T> bra = *this;
		for(int col_count = 0; col_count < this->cols(); col_count++)
		{
			ComplexNumPrint( bra(row_count, col_count),0 );
		}
		std::cout<<std::endl;
	}
}

/*!****************************************************************
* Print \f$< Bra |\f$ elements in fractional numeric form.
*****************************************************************/
template <class T>
void Bra<T>::NPrint()
{
	for(int row_count = 0; row_count < this->rows(); row_count++)
	{	Bra<T> bra = *this;
		for(int col_count = 0; col_count < this->cols(); col_count++)
		{
			ComplexNumPrint( bra(row_count, col_count),1 );
		}
		std::cout<<std::endl;
	}
}


} //end of namespace QuantaPlus
/*! @} End of Doxygen Groups*/
#endif

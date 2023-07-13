//=================================================================================================
/*!
//  \file quantaplus/braket/ket.h
//  \brief Fundamental operations on Ket vectors.
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
 
#ifndef QUANTAPLUS_BRAKET_KET_H
#define QUANTAPLUS_BRAKET_KET_H

//*************************************************************************************************
// Includes
//*************************************************************************************************
#include <Eigen/Dense>
#include"../utilities/print.h"
#include<random>

/*!
 *  \addtogroup QuantaPlus
 *  @{
 */
//! Generic QuantaPlus interfaces and implementations
namespace QuantaPlus {

//=================================================================================================
//
//  CLASS DEFINITION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Ket is a publicly inherited class from the well designed Eigen::Matrix,
* where the Ket vectors are matrices with one column and Dynamic-size rows.
* Kets belong to the Hilbert (vector) space H, or, in short, to the ket-space..
*/
template <class T = std::complex<double>>
class Ket : public Eigen::Matrix<T,Eigen::Dynamic,1> 
{
  public:
	//**Constructors**************************************************************** 
	/*!\name Constructors */
	//@{
	Ket();
	Ket(int row);	
   	//@}
	//****************************************************************************** 
       
	//******************************************************************************
	/*!\brief Constructor allows us to construct Ket from Eigen expressions.
	* In order to make any Ket object to work within the Eigen framework, 
	* we construct Ket from Eigen expressions using Eigen API contained in 
	* its base class "Eigen::MatrixBase<Derived>".
	*/
	template<typename Derived> 
	Ket(const Eigen::MatrixBase<Derived>& other)
	:Eigen::Matrix<T,Eigen::Dynamic,1>(other){ }
   	//******************************************************************************
   	
   	//******************************************************************************
    	/*!This method allows us to assign Eigen expressions to Ket */
	template<typename Derived>
	Ket& operator=(const Eigen::MatrixBase <Derived>& other)
	{
		this->Eigen::Matrix<T,Eigen::Dynamic,1>::operator=(other);  
		return *this;
	}
	/*! Overloading the logical operator ==*/
	bool operator ==(const Ket<T>& ket) const 
	{
    		return this->Eigen::Matrix<T,Eigen::Dynamic,1>::operator==(ket);
	}///<
	//******************************************************************************
	
	void Print(); ///< print |Ket> elements  fractional symbolic form.
	void NPrint(); ///< print |Ket> elements in fractional numeric form.
	//Ket<T> Normalize();
	//T NormFactor();
	//int Measure() const;
	//**Destructor******************************************************************
	/*!\name Destructor */
   	//@{
	~Ket() = default; 
	//@}
   	//******************************************************************************     
};
//*************************************************************************************************


//=================================================================================================
//
//  CONSTRUCTORS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief the Default constructor.
*/
template <class T >
Ket<T>::Ket():Eigen::Matrix<T,Eigen::Dynamic,1>()
{}
//*************************************************************************************************

//*************************************************************************************************
/*!\brief Constructor with fixed Number of rows.
* Create an empty one column vector. Allocate fixed numbers of rows at compile-time.
* @param row is the Number of rows.
\code{.cpp}
//needed to use the literal imaginary unit [ 1.i = sqrt(-1)] 
using namespace std::complex_literals; 

//deceleration of (an empty) complex Ket vector |A> with three rows
QuantaPlus::Ket<std::complex<double>> A(3); 

A << 2.5, 3.7, 2.5+3.5i; // initialization of Ket A ,|A> = 2.5, 3.7, 2.5+3.5i

A.Print(); // print the content of |A>.
*  
\endcode
\verbatim
5/2
37/10
5/2+7/2i
\endverbatim

*/
template <class T >
Ket<T>::Ket(int row):Eigen::Matrix<T,Eigen::Dynamic,1>(row,1)
{}
//*************************************************************************************************


//**********************************************************************************
/*! 
* Print \f$|ket>\f$ elements in fractional symbolic form 
* \f$z =\frac{A}{B} + i\frac{C}{D}\f$, where \f$i = \sqrt{-1}\f$;
*/
template <class T >
void Ket<T>::Print()
{
	for(int row_count = 0; row_count < this->rows(); row_count++)
	{	Ket<T> ket = *this;
		for(int col_count = 0; col_count < this->cols(); col_count++)
		{
			ComplexNumPrint( ket(row_count, col_count),0 );
		}
		std::cout<<std::endl;
	}
}


/*!Print \f$|ket>\f$ elements in fractional numeric form.*/
template <class T>
void Ket<T>::NPrint()
{
	for(int row_count = 0; row_count < this->rows(); row_count++)
	{	Ket<T> ket = *this;
		for(int col_count = 0; col_count < this->cols(); col_count++)
		{
			ComplexNumPrint( ket(row_count, col_count),1);
		}
		std::cout<<std::endl;
	}
}
//**********************************************************************************

/*!***********************************************************************************
* \brief Compute the expectation value of given operator and normalized quantum state  
**************************************************************************************/
template <typename T >
T ExpectValue(const  Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> & mat, const Ket<T> &ket)
{    
	Eigen::Matrix<T,1, Eigen::Dynamic>  bra;
	bra = ket.conjugate();
	Ket<T> toright((int)ket.rows());
	toright << mat * ket;
	T demo = bra*ket;
	T nomr = bra*toright; 
	//T nomr = ket.conjugate()*toright;
	return nomr/demo;//dnomr; 
}
/*
template <typename T >
int Ket<T>::Measure() const
{
        // Calculate the probabilities for each state
        Ket<T> ket = *this;
        std::vector<double> probabilities;
        double norm = ket.norm();
        for (int row_count = 0; row_count < ket.rows(); row_count++)
        {
            probabilities.push_back(std::norm(ket(row_count)) / (norm * norm));
        }
	
        // Perform the measurement
        std::random_device rd;
        std::mt19937 gen(rd());
        std::discrete_distribution<int> dist(probabilities.begin(), probabilities.end());
        int measurement = dist(gen);

        return measurement;
}
*/

//--------------------------------------------------------------------------
//#############	normalization factor		#########################
//--------------------------------------------------------------------------
template <typename T> 
T NormFactor(const Ket<T> &kt )
{   
    Eigen::Matrix<T,1, Eigen::Dynamic>  br((int)kt.rows());
    br = kt.adjoint();
    T sum = br*kt; 
    return 1./sqrt(sum);   
}
//------------------------------------------------------------------------------
//#############	normalized ket	#########################
//--------------------------------------------------------------------------
template <typename T>
Ket<T> Normalize(const Ket<T> &kt)
{    
    Ket<T> res;
    res = NormFactor(kt) * kt;
    return res;   
}
} //end of namespace QuantaPlus
/*! @} End of Doxygen Groups*/
#endif

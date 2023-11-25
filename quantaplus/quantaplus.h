//=================================================================================================
/*!
//  \file quantaplus/quantaplus.h
//  \brief Primary include file of the QuantaPlus library
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

#ifndef _QUANTAPLUS_H
#define _QUANTAPLUS_H

//-------------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------------

#include"utilities/utilities.h"
#include"braket/ket.h"
#include"braket/bra.h"
#include"braket/qubit.h"
#include"utilities/latex.h"
#include"utilities/constants.h"
#include"operators/operators.h"
#include"operators/hoscillator.h"
#include"operators/angularmomentum.h"
#include"operators/cgc.h"
#include"eigenvectors/eigenvec.h"
#include"eigenvectors/eigenval.h"

 
//-------------------------------------------------------------------------------------------------
//  DOXYGEN DOCUMENTATION
//-------------------------------------------------------------------------------------------------

//*************************************************************************************************
//! Namespace of the \b QuantaPlus C++ library.
namespace QuantaPlus {
	//needed to use the literal imaginary unit [ 1i = sqrt(-1)] 
	using namespace std::complex_literals; 
	typedef std::complex<double>  complex;
}
//*************************************************************************************************

#endif

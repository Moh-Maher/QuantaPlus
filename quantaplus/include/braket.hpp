/*!\file braket.hpp
*  \brief BraKet.hpp is a part of QuantaPlus provides support for braket.h.
*/
/*------------------------------------------------------------------------------------------
  by:  	     Mohammed Maher Abdelrahim Mohammed
       	     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
	     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
       	     mohammed.maher@unical.it  
------------------------------------------------------------------------------------------*/
#ifndef QUANTAPLUS_INCLUDE_BRAKET_HPP
#define QUANTAPLUS_INCLUDE_BRAKET_HPP

#ifndef QUANTAPLUS_INCLUDE_BRAKET_HPP
#error __FILE__ should only be included from braket.h.
#endif // BRAKET_H

/*!**************************************************************** 
* \brief Print <Bra| elements in fractional symbolic form "z = n/d + in/d", where i = sqrt[-1];
@see  ComplexNumPrint( std::complex<double> complex_number, bool numerical_flag)
******************************************************************/
template <typename U>
void ResultPrint(Bra<U>& bra)
{
	for(int row_count = 0; row_count < bra.rows(); row_count++)
    	{
        	for(int col_count = 0; col_count < bra.cols(); col_count++)
        	{
			ComplexNumPrint( bra(row_count, col_count),0 );
        	}
        	std::cout<<std::endl;
    	}
}

/*!****************************************************************
* \brief Print <Bra| elements in fractional numeric form.
*****************************************************************/
template <typename U>
void NResultPrint(Bra<U>& bra)
{
	for(int row_count = 0; row_count < bra.rows(); row_count++)
    	{
        	for(int col_count = 0; col_count < bra.cols(); col_count++)
        	{
			ComplexNumPrint( bra(row_count, col_count),1 );
			//cplx_print( bra(row_count, col_count) );
        	}
        	std::cout<<std::endl;
    	}
}
 
/*!*****************************************************************************
*\brief An overlaoded version to print |Ket> elements  fractional symbolic form:
 "z = n/d + in/d", where i = sqrt[-1];
********************************************************************************/
template <typename U>
void ResultPrint(Ket<U>& ket)
{
	for(int row_count = 0; row_count < ket.rows(); row_count++)
    	{
        	for(int col_count = 0; col_count < ket.cols(); col_count++)
        	{
			ComplexNumPrint( ket(row_count, col_count),0 );
        	}
        	std::cout<<std::endl;
    	}
}
/*!*****************************************************************************
*\brief An overlaoded version to print |Ket> elements in fractional numeric form.
*******************************************************************************/
template <typename U>
void NResultPrint(Ket<U>& ket)
{
	for(int row_count = 0; row_count < ket.rows(); row_count++)
    	{
        	for(int col_count = 0; col_count < ket.cols(); col_count++)
        	{
			ComplexNumPrint( ket(row_count, col_count),1 );//cplx_print( ket(row_count, col_count) );
        	}
        	std::cout<<std::endl;
    	}
}

/*!********************************************************************************
*\brief Function to print QuantaPlus variables (Ket, Bra and C-numbers) in a symbolic form.
*
* literal_printf is a "variadic function" takes a variable number of arguments, and 
* like normal printf it needs format specifiers to define the type of data to be printed.  
*@param fmt...  is a user defined format specifier.
*
\code{.cpp}
Ket<std::complex<double>> A(3); // deceleration of complex ket vector |A> with three rows. 
Bra<std::complex<double>> B(3); // deceleration of complex Bra vector <B| with three columns.

A <<1.-2.5i, 1i,-0.25i;  // initialization of A, |A> = (1-2.5i, i, -0.25i), column vector.
B << 2.5, 3.7, 2.5+3.5i; // initialization of B, <B| = (2.5, 3.7, 2.5+3.5i), row vector.

literal_printf("kb", A, B); // use format specifier 'kb' to literally print (Ket) A and (Bra) B, respectively. 
\endcode
*
\verbatim
|Ket> =
1-5/2i	
1i	
-1/4i

<Bra| = 5/2	37/10	5/2+7/2i	
\endverbatim
***********************************************************************************/
void literal_printf(const char* fmt...) 
{
	va_list args; // Type to hold information about variable arguments.
	va_start(args, fmt); // Initialize a variable argument list.

	while (*fmt != '\0') {
		if (*fmt == 'k') {
			Ket<std::complex<double>> kt = va_arg(args, Ket<std::complex<double>>);
			std::cout<<"|Ket> =\n";
			ResultPrint(kt);
			std::cout<<"\n";
		} 
		else if (*fmt == 'b') {
			Bra<std::complex<double>> br = va_arg(args, Bra<std::complex<double>>);
			std::cout<<"<Bra| = ";
			ResultPrint(br);
			std::cout<<"\n";
		}
		else if (*fmt == 'c') {
			std::complex<double> d = va_arg(args, std::complex<double>);
			std::cout<<"complex number = ";
			ComplexNumPrint(d,0);
			std::cout<<"\n";
		}		
		++fmt;
	}

	va_end(args); // End using variable argument list.
}

/*!****************************************************************
* \brief compute specific Eigen vectors for Eigen::Matrix.
* @param mt is a square Eigen::Matrix with Dynamic-size.
* @param col_number is the column of the selected eigen vector
* @return Specified column of eigenvector for a given matrix. 
******************************************************************/
template<typename T>
Eigen::Matrix<T,Eigen::Dynamic,1> 
QuantumEigenVector(Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> &mat, const int& col_number)
{
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>> eigensolver(mat);
   
	if (eigensolver.info() != Eigen::Success) abort();
  
	return eigensolver.eigenvectors();//.col(col_number);
}
/*!****************************************************************************
* \brief overloaded version to compute all the Eigen vectors for Eigen::Matrix.
* @param mt is a square Eigen::Matrix with Dynamic-size.
* @return eigenvectors for a given matrix. 
******************************************************************************/
template<typename T> 
Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> 
QuantumEigenVector(Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> &mat)
{
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>> eigensolver(mat);
   
	if (eigensolver.info() != Eigen::Success) abort();
  
	return eigensolver.eigenvectors();//.col(col_number);
}
 
/*!****************************************************************
* \brief compute specific Eigen values for Eigen::Matrix.
* @param mt is Dynamic-size Eigen::Matrix.
* @param i the selector var to pick the specified Eigen value
* @return selected eigenvalues for a given matrix. 
******************************************************************/
template<typename T>
T QuantumEigenValue(Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>  &mat,const int& i)
{
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> > eigensolver(mat);
   
	if (eigensolver.info() != Eigen::Success) abort();
   
	return eigensolver.eigenvalues()[i];
}
/*!***********************************************************************
* \brief overloaded version to compute all Eigen values for Eigen::Matrix.
* @param mt is a Dynamic-size Eigen::Matrix.
* @return all eigenvalues for a given matrix. 
*************************************************************************/
template<typename T>
Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> 
QuantumEigenValue(const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>  &mat)
{
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> > eigensolver(mat);
   
	if (eigensolver.info() != Eigen::Success) abort();
   
	return eigensolver.eigenvalues();
}
 
/*!****************************************************************
* \brief transform the Ket vector into it's Bra dual Conjugate.
******************************************************************/
template <typename T>
Bra<T> DualConj(const Ket<T> &ket)
{
	Bra<T> resulted_bra((int)ket.rows());
	resulted_bra << ket.adjoint();
	return resulted_bra;
}
 
/*!****************************************************************
* \brief transform the Bra vector into it's Ket dual Conjugate.
******************************************************************/
template <typename T>
Ket<T> DualConj(const Bra<T> &bra)
{
	Ket<T> resulted_ket((int)bra.cols());
	resulted_ket << bra.adjoint();
	return resulted_ket;
}
 
/*!****************************************************************
* \brief Scalar product for Bra and Ket vectors.
* @return generic type value ( int, double or complex). 
******************************************************************/
template <typename T> 
T BraKet(const Bra<T> &bra, const Ket<T> &ket)
{     
	if(bra.cols()!=ket.rows())
	{ 
		throw std::invalid_argument("dimensions do not match."); 
	}
	return bra*ket;   
}

/*!***********************************************************************************
* \brief Compute the expectation value of given operator and normalized quantum state  
**************************************************************************************/
template <typename T>
T ExpectValue(const  Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> & mat, const Ket<T> &ket)
{    
    Bra<T> bra;
    bra = DualConj(ket);
    Ket<T> toright((int)ket.rows());
    toright << mat * ket;
    T nomr = BraKet(bra,toright); 
    return nomr;//dnomr; 
}
#endif // BRAKET_HPP

/*******************************************************************************************
  File:      BRAKET.TPP

  Summary:   BraKet.tpp is a part of QUANTAPLUS library, provides support for "braket.h" .

  Functions:  ComplexNumPrint, ResultPrint, literal_printf, QuantumEigenVector,
  	      QuantumEigenValue, DualConj, BraKet. 

  by:  	     Mohammed Maher Abdelrahim Mohammed
       	     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
	     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
       	     mohammed.maher@unical.it  
*******************************************************************************************/
//#include"braket.h"
//#pragma once
#ifndef QUANTAPLUS_INCLUDE_BRAKET_HPP
#define QUANTAPLUS_INCLUDE_BRAKET_HPP

#ifndef QUANTAPLUS_INCLUDE_BRAKET_H
#error __FILE__ should only be included from braket.h.
#endif // BRAKET_H

//##########################################################################
// class Ket :
//##########################################################################
//--------------------------------------------------------------------------
//		defult constructor
//--------------------------------------------------------------------------
template <class T>
Ket<T>::Ket():Eigen::Matrix<T,Eigen::Dynamic,1>(){}
//--------------------------------------------------------------------------
//		Constructor for Ket vector of a given rows
//--------------------------------------------------------------------------
template <class T>
Ket<T>::Ket(int row):Eigen::Matrix<T,Eigen::Dynamic,1>(row,1){}
//--------------------------------------------------------------------------
//		2nd overloded constructor
//--------------------------------------------------------------------------
//template <class T, int R>
//Ket<T,R>::Ket(const T *data ):Eigen::Matrix<T,R,1>(data){}
//--------------------------------------------------------------------------
//		destructor
//--------------------------------------------------------------------------
template <class T>
Ket<T>::~Ket(){}
//##########################################################################
// class Bra :
//##########################################################################
//--------------------------------------------------------------------------
//		defult constructor
//--------------------------------------------------------------------------
template <class T>
Bra<T>::Bra():Eigen::Matrix<T,1,Eigen::Dynamic>(){}
//--------------------------------------------------------------------------
//		Constructor for Bra vector of a given rows
//--------------------------------------------------------------------------
template <class T>
Bra<T>::Bra(int col):Eigen::Matrix<T,1,Eigen::Dynamic>(1,col){}
//--------------------------------------------------------------------------
//		2nd overloded constructor
//--------------------------------------------------------------------------
//template <class T, int C>
//Bra<T,C>::Bra(const T *data ):Eigen::Matrix<T,1,C>(data){}
//--------------------------------------------------------------------------
//		destructor
//--------------------------------------------------------------------------
template <class T>
Bra<T>::~Bra(){}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: ComplexNumPrint

  Summary:  print complex number in symbolic form.

  Args:      std::complex<double> a
  	        complex variable with "double-type" real and imaginary parts.  

  Returns:  void
              print complex number in " x + iy" format.
------------------------------------------------------------------*/
inline void ComplexNumPrint(std::complex<double> complex_number)
{
	double real_part = std::real(complex_number);
	double imaginary_part = std::imag(complex_number);   
	if( real_part != 0 && imaginary_part != 0 )
    	{
        	if( imaginary_part < 0 )
        	{
            		//std::cout<<real_part<<imaginary_part<<"i"<<"\t";
            		DecimalToFraction(real_part);
            		DecimalToFraction(imaginary_part);
            		std::cout<<"i"<<"\t";
        	}

        	else if( imaginary_part > 0 )
        	{
            		//std::cout<<real_part<<"+" <<imaginary_part<<"i"<<"\t";
            		DecimalToFraction(real_part);
            		std::cout<<"+";
            		DecimalToFraction(imaginary_part);
            		std::cout<<"i"<<"\t";
        	}
	}
   	else if (imaginary_part == 0 )
    	{   
        	//std::cout<<real_part<<"\t";
        	DecimalToFraction(real_part);
        	std::cout<<"\t";
           
    	}
    	else if( real_part == 0 )
    	{
        	//std::cout<<imaginary_part<<"i"<<"\t"; 
        	
		DecimalToFraction(imaginary_part);
    		std::cout<<"i"<<"\t";
    	}    
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: ResultPrint

  Summary:  print <Bra| elements in symbolic form.

  Args:      Bra<U>& bra
  	        Bra vector.  

  Returns:  void
              print complex number in " x + iy" format.
------------------------------------------------------------------*/
template <typename U>
void ResultPrint(Bra<U>& bra)
{
	for(int row_count = 0; row_count < bra.rows(); row_count++)
    	{
        	for(int col_count = 0; col_count < bra.cols(); col_count++)
        	{
			ComplexNumPrint( bra(row_count, col_count) );
        	}
        	std::cout<<std::endl;
    	}
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: ResultPrint

  Summary:  print  Ket elements in symbolic form.

  Args:      Ket<U>& ket
  	        Ket vector.  

  Returns:  void
              print complex number in " x + iy" format.
------------------------------------------------------------------*/
template <typename U>
void ResultPrint(Ket<U>& ket)
{
	for(int row_count = 0; row_count < ket.rows(); row_count++)
    	{
        	for(int col_count = 0; col_count < ket.cols(); col_count++)
        	{
			ComplexNumPrint( ket(row_count, col_count) );
        	}
        	std::cout<<std::endl;
    	}
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: literal_printf

  Summary:  function print QuantaPlus variables in a symbolic form.
  	    This function is a modified version of "Variadic functions".
	    source: https://en.cppreference.com/w/cpp/utility/variadic .

  Args:     const char* fmt...
              format identifier for multiple variables 

  Returns:  void
              printing 
--------------------------------------------------------------------*/
void literal_printf(const char* fmt...) 
{
	va_list args;
	va_start(args, fmt);

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
			ComplexNumPrint(d);
			std::cout<<"\n";
		}		
		++fmt;
	}

	va_end(args);
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: ResultPrint

  Summary:  print matrix elements in symbolic form.

  Args:      Matrix<U,Eigen::Dynamic,Eigen::Dynamic>& mat
  	        Eigen::Matrix with Dynamic-size rows or columns  

  Returns:  void
              print complex number in " x + iy" format.
------------------------------------------------------------------*/
template <typename U>
void ResultPrint(Eigen::Matrix<U,Eigen::Dynamic,Eigen::Dynamic>& mat)
{
	for(int row_count = 0; row_count < mat.rows(); row_count++)
    	{
        	for(int col_count = 0; col_count < mat.cols(); col_count++)
        	{
			ComplexNumPrint( mat(row_count, col_count) );
        	}
        	std::cout<<std::endl;
    	}
}
//-----------------------------------------------------------------
//	print complex numbers in symbolic form
//-----------------------------------------------------------------
void ResultPrint(const std::complex<double>& complex_num)
{
	ComplexNumPrint(complex_num);
	std::cout<<std::endl;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: QuantumEigenVector

  Summary:  compute the Eigen vectors for Eigen::Matrix.

  Args:      Matrix<T,Eigen::Dynamic,Eigen::Dynamic>& mt
  	        Eigen::Matrix.  

  Returns:  Eigen::Matrix<T, Eigen::Dynamic, 1> (row vector)
              return the eigenvectors of a given matrix.
------------------------------------------------------------------*/
template<typename T>
Eigen::Matrix<T,Eigen::Dynamic,1> QuantumEigenVector(Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> &mat, const int& col_number)
{
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>> eigensolver(mat);
   
	if (eigensolver.info() != Eigen::Success) abort();
  
	return eigensolver.eigenvectors().col(col_number);
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: QuantumEigenVector

  Summary:  compute the Eigen value for Eigen::Matrix.

  Args:      Matrix<U,Eigen::Dynamic,Eigen::Dynamic>& mt
  	        Eigen::Matrix.  

  Returns:  T (generic type)
              return the eigenvalues of a given matrix.
------------------------------------------------------------------*/
template<typename T>
T QuantumEigenValue(Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>  &mat,const int& i)
{
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> > eigensolver(mat);
   
	if (eigensolver.info() != Eigen::Success) abort();
   
	return eigensolver.eigenvalues()[i];
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: DualConj
  Summary:  transform the Ket vector into it's Bra dual Conjugate.
  Args:     Ket<T> &ket
  		generic Ket vecotr called by reference.
  Returns:  Bra<T>
              generic Bra vector.
-------------------------------------------------------------------*/
template <typename T>
Bra<T> DualConj(const Ket<T> &ket)
{
	Bra<T> resulted_bra(ket.rows());
        /*
	for (int i=0; i<ket.rows(); i++)
    	{
		resulted_bra(i) = std::conj(ket(i));
	}
	return resulted_bra;
	*/
	resulted_bra << ket.adjoint();
	return resulted_bra;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: DualConj
  Summary:  transform the Bra vector into it's Ket dual Conjugate.
  Args:     Bra<T> &bra
  		generic Bra vecotr called by reference.
  Returns:  Ket<T>  
              generic Ket vector.
-------------------------------------------------------------------*/
template <typename T>
Ket<T> DualConj(const Bra<T> &bra)
{
	Ket<T> resulted_ket(bra.cols());
	resulted_ket << bra.adjoint();
	return resulted_ket;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: BraKet
  Summary:   Scalar product for Bra and Ket vectors.
  Args:     Bra<T>& bra
              a generic type Bra vector called by reference.
            Ket<T>& ket
              a generic type Ket vector called by reference.
  Returns:  T
              generic type it can be int, double or complex. 
-------------------------------------------------------------------*/
template <typename T> 
T BraKet(const Bra<T> &bra, const Ket<T> &ket)
{     
	if(bra.cols()!=ket.rows()){ throw std::invalid_argument("dimensions do not match."); }
	/*
	T sum = static_cast<T>(0.0);

	for(int i = 0; i < bra.rows(); ++i)
	{
		for(int j = 0; j < ket.cols(); ++j)
		{
			for(int k = 0; k < (bra.rows()*bra.cols()); ++k)
    			{
   	        		sum += bra(i,k) * ket(k,j);
            		}	
        	}
    	}
	return sum; 
	*/
	return bra*ket;   
}
//--------------------------------------------------------------------------
//#The expectation value of given operator and normalized QM state 
//--------------------------------------------------------------------------
template <typename T>
T ExpectValue(const QM_operator<T> & mat, const Ket<T> &ket)
{    
    Bra<T> bra;
    bra = DualConj(ket);
    Ket<T> toright(ket.rows());
     toright << mat * ket;
    T nomr = BraKet(bra,toright); 
   // T dnomr = BraKet(bra,ket);
   
    return nomr;//dnomr; 
}
#endif // BRAKET_HPP

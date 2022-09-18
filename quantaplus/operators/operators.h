/*!*****************************************************************
* \file operators.h
* Define fundamental quantum operators.
*
* \cite zettili2003quantum 
******************************************************************/

/*---------------------------------------------------------------------------
by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
---------------------------------------------------------------------------*/
//#pragma once
#ifndef QUANTAPLUS_OPERATORS_OPERATORS_H
#define QUANTAPLUS_OPERATORS_OPERATORS_H
#include <Eigen/Dense>
#include <unsupported/Eigen/MatrixFunctions>
#include<complex>
#include<cmath>
#include<vector>
#include"../utilities/print.h"
#include"../braket/ket.h"
#include"../braket/bra.h"
namespace QuantaPlus{

/*!*****************************************************************
* \class QM_operator
* \brief QM_operator is a publicly derived class from Eigen::Matrix, 
*
* QM_operator are square matrices with Dynamic-size.
******************************************************************/
template<class T>
class QM_operator: public Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>
{
	public:
		/*!
	        * Create an empty one matrix. Dynamically allocate numbers of rows and columns at run-time.
	        */ 
		QM_operator():Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>(){} ///<Default constructor.
		
		/*!\brief Constructor with fixed Number of rows and columns.
	        * Create an empty one matrix. Dynamically Allocate  fixed numbers of rows and columns at compile-time.
	        * @param row is the Number of rows.
	        * @param col is the Number of columns.
                \code{.cpp}
		using namespace std::complex_literals; //needed to use the literal imaginary unit [ 1i = sqrt(-1)] 
		
		int N = 4; //fix the number of dimensions = 4.
		
		QuantaPlus::QM_operator<complex> plus(N,N), minus(N,N); // declaration of two (4 x 4) operators. 
		
		//Quantum harmonic oscillator – Ladder operators: 
		plus  = QuantaPlus::RisingOperator<complex>(N,N); // initialize operator plus to take the value of the (Harmonic oscillator) rising operator after compute it in 4 dimensions.
		minus = QuantaPlus::LoweringOperator<complex>(N,N); // initialize operator minus to the value of the (4 x 4) lowering operator of the Harmonic oscillator after compute it.
		
		cout<<"[ RisingOperator: ]"<<endl;
		
		QuantaPlus::ResultPrint(plus);
		
		cout<<"-------------------"<<endl;

		cout<<"[ LoweringOperator: ]"<<endl;
		
		QuantaPlus::ResultPrint(minus);
		
		cout<<"-------------------"<<endl;
	
	        \endcode
	        \verbatim
		[ RisingOperator: ]
		0	0	0	0	
		1	0	0	0	
		0	√2	0	0	
		0	0	√3	0	
		-------------------
		[ LoweringOperator: ]
		0	1	0	0	
		0	0	√2	0	
		0	0	0	√3	
		0	0	0	0	
		-------------------

	        \endverbatim
	        
	        @see QuantaPlus::RisingOperator(const int& R, const int& C)
	        @see QuantaPlus::LoweringOperator(const int& R, const int& C)
	        */
		QM_operator(int row,int col):Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>(row,col){}
		
		
		template<typename Derived> 
		QM_operator(const Eigen::MatrixBase<Derived>& other)
		:Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>(other){ } ///< construct QM_operator from Eigen expressions.
	 
	    	/*!Assign Eigen expressions to QM_operators*/
		template<typename Derived>
		QM_operator& operator=(const Eigen::MatrixBase <Derived>& other)
		{
			this->Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>::operator=(other);
			return *this;
		}
		
		  
		Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> dagger()
		{
			return this->conjugate().transpose();
		}
		
		void Print();
		void NPrint();
		~QM_operator(){} ///< Destructor
};

/*! @param mat is an Eigen::Matrix with Dynamic-size rows or columns */
template<class T>
void QM_operator<T>::Print()
{	
	Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> mat = *this;
	for(int row_count = 0; row_count < mat.rows(); row_count++)
    	{
        	for(int col_count = 0; col_count < mat.cols(); col_count++)
        	{
			ComplexNumPrint( mat(row_count, col_count),0 );
        	}
        	std::cout<<std::endl;
    	}
}
/*!@param mat is an Eigen::Matrix with Dynamic-size rows or columns*/
template<class T>
void QM_operator<T>::NPrint()
{	
	Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> mat = *this;
	for(int row_count = 0; row_count < mat.rows(); row_count++)
    	{
        	for(int col_count = 0; col_count < mat.cols(); col_count++)
        	{
			ComplexNumPrint( mat(row_count, col_count),0 );
        	}
        	std::cout<<std::endl;
    	}
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: KroneckerDelta

  Summary:  Function of two variables, usually just non-negative integers.
  	    
  Args: const int & i , const int & j
	      integer variables.
  	        
  Returns:  int
              The function return 1 if the variables are equal, and 0 otherwise.
------------------------------------------------------------------*/
template<typename T>
int KroneckerDelta(const T & i, const T & j)
{
	if  (i==j){return (1);}
	else 
	return (0);
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:  Kronecker-Product

  Summary:  An operation on two matrices of arbitrary size resulting in a block matrix 
  	    
  Args:  const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> &mt1
  		matrix of dynamic (m × n) size.
  	 const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> & mt2
  	 	matrix of dynamic (p × q) size. 
  	      
  Returns: Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> 
  		block matrix of size (pm × qn).
------------------------------------------------------------------*/
template <class T>
Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> 
KroneckerProduct( const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> & mt1, 
		  const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> & mt2)
{   
	int rowA = (int)mt1.rows();
	int colA = (int)mt1.cols();
	int rowB = (int)mt2.rows();
	int colB = (int)mt2.cols();
	Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>  res((rowA*rowB),(colA*colB));
	for (int i = 0; i < rowA; i++)
	{
		for (int k = 0; k < rowB; k++) ///<-------- k loops till rowb
		{
			for (int j = 0; j < colA; j++)  ///<-------- j loops till cola
			{
				for (int l = 0; l < colB; l++)  ///<-------- l loops till colb
				{
					res(i*rowB+k,j*colB+l)=mt1(i,j)*mt2(k,l); 	   		
				}
			}
		}
	}
	return res;    
}		
//------------------- Overloaded Kronecker-Product ----------------------
template <class T>
Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> 
KroneckerProduct( const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> & mt1, 
		  const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> & mt2, 
		  const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> & mt3)
{   
	Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> temp = KroneckerProduct(mt1,mt2) ;
	return KroneckerProduct(temp,mt3);
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: Id

  Summary: Unit operator operating on a spin of length S.
  	    
  Args: const double& S
           spin quantum number.  
  	      
  Returns: Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>
  	    Identity matrix of dynamic size.
------------------------------------------------------------------*/
template<typename T>
Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> Id(const double& S)
{
	return Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>::Identity( int(2*S+1), int(2*S+1));
}
 
////<--------------------------------------------------------------->
template <typename U>
Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> CtoRMateix(Eigen::Matrix<U,Eigen::Dynamic,Eigen::Dynamic>& mat)
{	
	Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> realres((int)mat.rows(),(int)mat.cols());
	for(int row_count = 0; row_count < mat.rows(); row_count++)
    	{
        	for(int col_count = 0; col_count < mat.cols(); col_count++)
        	{
			realres(row_count,col_count)= std::real(mat(row_count, col_count));
        	}
        	 
    	}
    	return realres;
}

} //end of namespace QuantaPlus
#endif

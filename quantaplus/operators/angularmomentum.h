/*!*********************************************************************
*   \file angularmomentum.h  angularmomentum.h is a part of QUANTAPLUS library. 
*   \brief Define and handle some fundamental quantum operators.
*
* For more details consult chapter 5 in \cite zettili2003quantum
*/
/*----------------------------------------------------------------------
by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
----------------------------------------------------------------------*/
//#pragma once
#ifndef QUANTAPLUS_OPERATORS_ANGULARMOMENTUM_H
#define QUANTAPLUS_OPERATORS_ANGULARMOMENTUM_H
//#include <unsupported/Eigen/MatrixFunctions>
#include <Eigen/Dense>
#include"../utilities/utilities.h"
#include"../utilities/print.h"
//#include"operators.h"

namespace QuantaPlus{

/*!********************************************************************* 
* \class AngularMomentum
* \brief The matrix representation of angular momentum operators.   
*
* AngularMomentum is a publicly derived class from QM_operator<T>, 
* where eigenkets and operators will be represented by column vectors 
* and square matrices, respectively.
* The matrices representing \f$J^2\f$ and \f$J_z\f$ in the \f$j,m\f$ eigenbasis are diagonal, their diagonal elements being equal to 
* ( after set \f$\hbar=1\f$) \f$j(j+1)\f$ and \f$m\f$, respectively
**********************************************************************/
template <class T>
class AngularMomentum : public Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>//public QM_operator<T> 
{
	public:
	 	
		AngularMomentum():Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>(){} // Default constructor.
		
		/*!
		\code{.cpp}
		QuantaPlus::AngularMomentum<complex> M(3,3) // declaration of 3 x 3 angular momentum operator with zero elements.  
		cout<<M<<endl;
		\endcode
		\verbatim
		0    0    0
		0    0    0
		0    0    0
		\endverbatim 
		*/
		AngularMomentum(int row, int col):Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>(row,col){} ///< Constructor with row and column input. 
	
		template<typename Derived>
		AngularMomentum(const Eigen::MatrixBase<Derived>& other)
		:Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>(other){ } ///<construct AngularMomentum from Eigen expressions.
	   	
	   	/*!Assign Eigen expressions to AngularMomentum*/
		template<typename Derived>
		AngularMomentum& operator=(const Eigen::MatrixBase <Derived>& other)
		{
			this->Eigen::Matrix<T,Eigen::Dynamic ,Eigen::Dynamic>::operator=(other);
			return *this;
		}
	 	
	 	/*!
		\f$<j^\prime, m^\prime|J^2|j, m > =  j(j+1)\delta_{j^\prime, j}\delta_{m^\prime, m} \f$
		*/
		AngularMomentum<T> AngularMomentum_JSquare(const double& spin_value); ///<The matrix representations of the squared general angular momentum operator \f$J^2\f$
		
		/*!
		\f$<j^\prime, m^\prime|J_x|j, m > = \frac{1}{2}  \left[\sqrt{j(j+1)-m(m+1)}\delta_{m^\prime, m+1} + \sqrt{j(j+1)-m(m-1)}\delta_{m^\prime, m-1}  \right]\delta_{j^\prime, j} \f$
		\code{.cpp}
	 	double spin = 1.5; // set physically valid spin value j = 3/2.
		
		QuantaPlus::AngularMomentum<complex> S_x; // declaration of an empty ( and dynamically sized ) angular momentum operator. 

		S_x = S_x.AngularMomentum_Jx(spin); // compute the J_x component of the spin angular momentum operator J as a function of spin, and set S_x = J_x

		QuantaPlus::ResultPrint(S_x); //print it using QuantaPlus::ResultPrint function.
	 
	 	\endcode
	 	*output
	 	\verbatim
	 
		0    √3/2    0    0	
		√3/2 0       1    0	
		0    1       0    √3/2	
		0    0      √3/2  0	
 
	 	\endverbatim
		*/
		AngularMomentum<T> AngularMomentum_Jx(const double& spin_value); ///< The matrix representations of the angular momentum operator component \f$J_x\f$
		
		/*!
		\f$<j^\prime, m^\prime|J_y|j, m > = \frac{1}{2i}  \left[\sqrt{j(j+1)-m(m+1)}\delta_{m^\prime, m+1} - \sqrt{j(j+1)-m(m-1)}\delta_{m^\prime, m-1}  \right]\delta_{j^\prime, j} \f$
		\code{.cpp}
	 	double spin = 0.5; // set physically valid spin value j = 1/2.
		
		QuantaPlus::AngularMomentum<complex> S_y; // declaration of an empty ( and dynamically sized ) angular momentum operator. 

		S_y = S_y.AngularMomentum_Jy(spin); // compute the J_y component of the spin angular momentum operator J as a function of spin, and set S_y = J_y

		QuantaPlus::ResultPrint(S_y); //print it using QuantaPlus::ResultPrint function.
	 
	 	\endcode
	 	*output
	 	\verbatim
	 
		0	-1/2i	
		1/2i	0
	 	
 
	 	\endverbatim
		*/
		AngularMomentum<T> AngularMomentum_Jy(const double& spin_value); ///< The matrix representations of the angular momentum operator component \f$J_y\f$
		
		/*!
		\f$<j^\prime, m^\prime|J_z|j, m > =  m\delta_{j^\prime, j}\delta_{m^\prime, m} \f$
		\code{.cpp}
	 	double spin = 2.5; // set physically valid spin value j = 5/2.
		
		QuantaPlus::AngularMomentum<complex> S_z; // declaration of an empty ( and dynamically sized ) angular momentum operator. 

		S_z = S_z.AngularMomentum_Jz(spin); // compute the J_z component of the spin angular momentum operator J as a function of spin, and set S_z = J_z

		QuantaPlus::ResultPrint(S_z); //print it using QuantaPlus::ResultPrint function.
	 
	 	\endcode
	 	*output
	 	\verbatim
		5/2    0    0    0    0    0	
		0      3/2  0    0    0    0	
		0      0    1/2  0    0    0	
		0      0    0    -1/2 0    0	
		0      0    0    0    -3/2 0	
		0      0    0    0    0    -5/2
	 	\endverbatim
		*/
		AngularMomentum<T> AngularMomentum_Jz(const double& spin_value); ///< The matrix representations of the angular momentum operator component \f$J_z\f$
		
		/*!
		\f$<j^\prime, m^\prime|J_+|j, m > = \sqrt{j(j+1)-m(m-1)}\delta_{j^\prime, j}\delta_{m^\prime, m+1} \f$
		*/
		AngularMomentum<T> AngularMomentum_JPlus(const double& spin_value); ///< The matrix representations of the raising operator \f$J_{+}\f$
		
		/*!
		\f$<j^\prime, m^\prime|J_-|j, m > = \sqrt{j(j+1)-m(m+1)}\delta_{j^\prime, j}\delta_{m^\prime, m-1} \f$
		*/
		AngularMomentum<T> AngularMomentum_JMinus(const double& spin_value); ///< The matrix representations of the lowering operator \f$J_{-}\f$
		
		/*!
		@param dir is the axis of rotation.
		@param alpha is the rotation angle. 
		*/
		AngularMomentum<T> RotationByAngle(const std::string& dir, const double& alpha); ///< Representation of the Rotation Operator in generic direction \f$R_{n}(\alpha)\f$
		
		void Print();
		void NPrint();
		~AngularMomentum(){} ///<Destructor 

};

/*! @param mat is an Eigen::Matrix with Dynamic-size rows or columns */
template<class T>
void AngularMomentum<T>::Print()
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
void AngularMomentum<T>::NPrint()
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
/*-------------------------------------------------------------------------------------------
 Check the physically valid (spin or orbital) angular m omentum 
 : True only if j is a nonnegative half-integer value
-------------------------------------------------------------------------------------------*/
bool validAngularMomentum(const double& x)
{
	return static_cast<int>(2*x) - 2*x == 0;
}
/*-------------------------------------------------------------------------------------------
              Kronecker Delta:  δ[ij] =  1 => (if i=j) OR 0 => (otherwise).
-------------------------------------------------------------------------------------------*/
double KroneckerDelta(const double & i, const double & j)
{
	if  (i==j){return (1);}
	else 
	return (0);
}
//---------------------------------------------------------------------------
//		commutation relation: [A,B] = A*B - B*A
//---------------------------------------------------------------------------
template<class T> 
Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> 
	Commute( Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mt1, 
		 Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mt2 )
{  
	return (mt1*mt2 - mt2*mt1);
}
//---------------------------------------------------------------------------
//		compute structure constants
//---------------------------------------------------------------------------
template <typename U>
U StructureConstant( Eigen::Matrix<U,Eigen::Dynamic,Eigen::Dynamic>& mt1, 
		     Eigen::Matrix<U,Eigen::Dynamic,Eigen::Dynamic>& mt2, 
		     Eigen::Matrix<U,Eigen::Dynamic,Eigen::Dynamic>& mt3 )
{
	U sum = static_cast<U>(0.0);
	const std::complex<double> I{0.,1.};

	Eigen::Matrix<U,3,3> cm, prod;
	cm = Commute(mt2,mt3);
	prod = mt1 * cm ;

	for (int i=0; i<3; i++)
	{
		for (int j=0; j<(3); j++)
		{
			if(i==j)
			{
				sum += prod(i,i);
			}
		}
	}
	return std::real(-0.25*I*sum);
}
//***************************************************************************** 
const double hBar = 1.; //6.58211899 * 1.e-16;
//-------------------------------------------------------------------------------------------
//           Magnatic_Quantum_Number : m which is run from -j to j. (-j<= m <= j).                      
//-------------------------------------------------------------------------------------------
void MagneticQuantumNumber(const double &j)
{    
	double spin = j;
	if(validAngularMomentum(spin))
	{
		double m[int(2*j+1)]={};
		for(auto i =-j; i<=j; i++)
		{       if(i==0){m[int(std::abs(j+i))]=0;}
			else m[int(std::abs(j+i))]=i;   
		}
		for(int i =0;i<int(2*j+1);i++)
		{   if(i!=int(2*j+1)-1){
			DecimalToFraction(m[i]); // [source utilities.h ]
			std::cout<<", ";
			}
			else DecimalToFraction(m[i]);
		}
		std::cout<<std::endl;
	}
     
	else{
		std::cout<<"spin ("<<spin<<" = ";
		DecimalToFraction(spin); std::cout<<") is physically invalid!"<<std::endl;
	}
}
//-------------------------------------------------------------------------------------------
//		The square of the angular momentum J^2 :  
//			<j',m'|J^2|j, m> = ℏ^2 j(j+1) δ[j'j] * δ[m'm].             
//-------------------------------------------------------------------------------------------
double Jsqr(const double & j, const double & j1, const double & m1, const double & j2, const double & m2)
{
	return hBar*hBar*j*(j+1) * KroneckerDelta(j1,j2) *KroneckerDelta(m1,m2);
}
//-------------------------------------------------------------------------------------------
//		The x-component of the angular momentum operator J: 
//			Eq (5.70) of N. Zettili.                                   
//-------------------------------------------------------------------------------------------
double Jx(const double & j, const double & j1,const double & m1, const double & j2,const double & m2)
{ 
	double res1,res2;

	res1 = sqrt(j*(j+1)-m2*(m2+1))* KroneckerDelta(m1,m2+1);
	res2 =   sqrt(j*(j+1)-m2*(m2-1))*  KroneckerDelta(m1,m2-1);
	return hBar*0.5*(res1+res2)*KroneckerDelta(j1,j2);
}
//-------------------------------------------------------------------------------------------
// 		The y-component of the angular momentumo peratorJ: 
//			Eq (5.71) of N. Zettili.                                    
//-------------------------------------------------------------------------------------------
std::complex<double>  Jy(const double & j, const double & j1,const double & m1, const double & j2,const double & m2)
{
    std::complex<double> Im(0.,1.);
	double res1,res2;

	res1 = sqrt(j*(j+1)-m2*(m2+1))* KroneckerDelta(m1,m2+1);
	res2 =   sqrt(j*(j+1)-m2*(m2-1))*  KroneckerDelta(m1,m2-1);
	//return hBar*(-0.5*Im)*(res1-res2)*KroneckerDelta(j1,j2);
	return hBar*(1./(2.*Im))*(res1-res2)*KroneckerDelta(j1,j2);
}
//-------------------------------------------------------------------------------------------
// 		The z-component of the angular momentum operator J: 
//			 <j',m'|J_Z|j, m> =  mℏ δ[j'j] * δ[m'm]. 
//-------------------------------------------------------------------------------------------
/*double Jz(const double & j, const double & j1, const double & m1, const double & j2, const double & m2)
{
	return hBar*m2 * KroneckerDelta(j1,j2) *KroneckerDelta(m1,m2);
}*/
double Jz(const double & j1, const double & m1, const double & j2, const double & m2)
{
	return hBar*m2 * KroneckerDelta(j1,j2) *KroneckerDelta(m1,m2);
}
//-------------------------------------------------------------------------------------------
// 		The J+ angular momentum operator J: 
//			Eq (5.69) of N. Zettili.                                   
//-------------------------------------------------------------------------------------------
double Jplus(const double & j, const double & j1,const double & m1, const double & j2,const double & m2)
{ 
	double res;
	res = sqrt(j*(j+1)-m2*(m2+1))* KroneckerDelta(m1,m2+1);
	return hBar*(res)*KroneckerDelta(j1,j2);
}
/*-------------------------------------------------------------------------------------------
 		The J- angular momentum operator J: Eq (5.69) of N. Zettili.                                   
-------------------------------------------------------------------------------------------*/
double Jminus(const double & j, const double & j1,const double & m1, const double & j2,const double & m2)
{ 
	double res;
	res = sqrt(j*(j+1)-m2*(m2-1))* KroneckerDelta(m1,m2-1);
	return hBar*(res)*KroneckerDelta(j1,j2);
}

//--------------------------------------------------------------------------
//		J- Angular Momentum perator
//--------------------------------------------------------------------------
template <class T>
AngularMomentum<T> AngularMomentum<T>::AngularMomentum_JSquare(const double &j)
//AngularMomentum<T> AngularMomentum_JSquare(const double &j)
{
	const int max =int(2*j+1);
	std::complex<double> temarr[max*max]{};
	double sp = j;
  
	if(validAngularMomentum(sp))
	{    
        	double M[max]={};
        	for(auto i =-j; i<=j; i++)
        	{
            		M[std::abs(int(j+i))]=i;   
        	}
             
        	for(int i=0;i<max;i++)
        	{
            		for(int k=0;k<max;k++)
            		{              
                		temarr[k+(i*max)] = Jsqr(j,j,-M[i],j,-M[k]);
            		}        
        	}
    	}   
    
	else{
		throw std::invalid_argument("the system has physically invalid spin!.");
	}
	AngularMomentum<T> temp(max,max);
	for(int i=0; i<max; i++)
	{
		for(int j=0; j<max; j++)
		{
	    		temp(i,j)= temarr[j+i*max];
		}
	}

	return temp;    
}
//--------------------------------------------------------------------------
//		Jx Angular Momentum perator
//--------------------------------------------------------------------------
template <class T>
AngularMomentum<T> AngularMomentum<T>::AngularMomentum_Jx(const double &j)
//AngularMomentum<T> AngularMomentum_Jx(const double &j)
{
	const int max =int(2*j+1);
	std::complex<double> temarr[max*max]{};
	double sp = j;

	if(validAngularMomentum(sp))
	{    
		double M[max]={};
		for(auto i =-j; i<=j; i++)
		{
	    		M[std::abs(int(j+i))]=i;   
		}
	     
		for(int i=0;i<max;i++)
		{
	    		for(int k=0;k<max;k++)
	    		{   
		 		temarr[k+(i*max)] = Jx(j,j,-M[i],j,-M[k]);
	    		}		

		}	
	}

	else
	{
	//std::cout<<"the system has physically invalid spin!"<<std::endl;
		throw std::invalid_argument("the system has physically invalid spin!.");
	} 
	
	AngularMomentum<T> temp(max,max);
	for(int i=0; i<max; i++)
	{
		for(int j=0; j<max; j++)
		{
	    		temp(i,j)= temarr[j+i*max];
		}
	}
	return temp;      
}
//--------------------------------------------------------------------------
//		Jy Angular Momentum perator
//--------------------------------------------------------------------------
template <class T>
AngularMomentum<T> AngularMomentum<T>::AngularMomentum_Jy(const double &j)
//AngularMomentum<T> AngularMomentum_Jy(const double &j)
{
	const int max =int(2*j+1);
	std::complex<double> temarr[max*max]{};
	double sp = j;

	if(validAngularMomentum(sp))
	{    
		double M[max]={};
		for(auto i =-j; i<=j; i++)
		{
	    		M[std::abs(int(j+i))]=i;   
		}
	     
		for(int i=0;i<max;i++)
		{
	    		for(int k=0;k<max;k++)
	    		{   
				temarr[k+(i*max)] = Jy(j,j,-M[i],j,-M[k]);
	    		}   
		}
	}

	else
	{
		throw std::invalid_argument("the system has physically invalid spin!.");
	}
	 
	AngularMomentum<T> temp(max,max);
	for(int i=0; i<max; i++)
	{
		for(int j=0; j<max; j++)
		{
	    		temp(i,j)= temarr[j+i*max];
		}
	}

	return temp;       
}
//--------------------------------------------------------------------------
//		Jz Angular Momentum perator
//--------------------------------------------------------------------------
template <class T>
AngularMomentum<T> AngularMomentum<T>::AngularMomentum_Jz(const double &j)
//AngularMomentum<T> AngularMomentum_Jz(const double &j)
{
	const int max =int(2*j+1);
	std::complex<double> temarr[max*max]{};
	double sp = j;

	if(validAngularMomentum(sp))
	{    
		double M[max]={};
		for(auto i =-j; i<=j; i++)
		{       
	    		M[std::abs(int(j+i))]=-i;   
		}
	     
		//for(int i=0;i<max;i++)
		//{
	    		for(int k=0;k<max;k++)
	    		{       if( Jz(j,M[k],j,M[k]) ==0.){ temarr[k+(k*max)]=0.;}
				//temarr[k+(i*max)] = Jz(M[i],j,M[k],j,M[i]);
				else temarr[k+(k*max)] = Jz(j,M[k],j,M[k]);
	    		}
		//}	
	}

	else
	{
		throw std::invalid_argument("the system has physically invalid spin!.");
	} 
	AngularMomentum<T> temp(max,max);
	for(int i=0; i<max; i++)
	{
		for(int j=0; j<max; j++)
		{       
	    		temp(i,j)= temarr[j+i*max];
	    	       // temp(i,j)= temarr[i+j];
		}
	}

	return temp;      
}
//--------------------------------------------------------------------------
//		J+ Angular Momentum perator
//--------------------------------------------------------------------------
template <class T>
AngularMomentum<T> AngularMomentum<T>::AngularMomentum_JPlus(const double &j)
//AngularMomentum<T> AngularMomentum_JPlus(const double &j)
{
	const int max =int(2*j+1);
	std::complex<double> temarr[max*max]{};
	double sp = j;

	if(validAngularMomentum(sp))
	{    
		double M[max]={};
		for(auto i =-j; i<=j; i++)
		{
	    		M[std::abs(int(j+i))]=i;   
		}
	     
		for(int i=0;i<max;i++)
		{
	    		for(int k=0;k<max;k++)
	    		{   
				temarr[k+(i*max)] = Jplus(j,j,-M[i],j,-M[k]);
	    		}
		}
	}

	else
	{
		throw std::invalid_argument("the system has physically invalid spin!.");
	} 
	AngularMomentum<T> temp(max,max);
	for(int i=0; i<max; i++)
	{
		for(int j=0; j<max; j++)
		{
	    		temp(i,j)= temarr[j+i*max];
		}
	}

	return temp;      
}
//--------------------------------------------------------------------------
//		J- Angular Momentum perator
//--------------------------------------------------------------------------
template <class T>
AngularMomentum<T> AngularMomentum<T>::AngularMomentum_JMinus(const double &j)
//AngularMomentum<T> AngularMomentum_JMinus(const double &j)
{
	const int max =int(2*j+1);
	std::complex<double> temarr[max*max]{};
	double sp = j;

	if(validAngularMomentum(sp))
	{    
		double M[max]={};
		for(auto i =-j; i<=j; i++)
		{
			M[std::abs(int(j+i))]=i;   
		}
	     
		for(int i=0;i<max;i++)
		{
	 		for(int k=0;k<max;k++)
	 		{     
	     			temarr[k+(i*max)] = Jminus(j,j,-M[i],j,-M[k]);
	 		}        
		}
	}

	else
	{
		throw std::invalid_argument("the system has physically invalid spin!.");
	} 
	AngularMomentum<T> temp(max,max);
	for(int i=0; i<max; i++)
	{
		for(int j=0; j<max; j++)
		{
	    		temp(i,j)= temarr[j+i*max];
		}
	}

	return temp;     
}

//--------------------------------------------------------------------------
//
//--------------------------------------------------------------------------
template <typename T>
AngularMomentum<T> MatrixExp(AngularMomentum<T> &A){

return  A.exp();
}

/*template <typename T>
Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> MatrixExp(Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> &A, Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> &V ){

return  A.exp()*V;
}*/

//--------------------------------------------------------------------------
//		 
//--------------------------------------------------------------------------
template <class T>
AngularMomentum<T> AngularMomentum<T>::RotationByAngle(const std::string& dir, const double &a)
//AngularMomentum<T> RotationByAngle(const std::string& dir, const double &a)
{
	const double spin= 3./2.;
	AngularMomentum<T> res;
	AngularMomentum<std::complex<double>> J;
	if(dir == "x")
	{
		J = J.AngularMomentum_Jx(spin);
	}

	else if (dir=="y"){
		J = J.AngularMomentum_Jy(spin);
	}

	else if(dir == "z")
	{
		J = J.AngularMomentum_Jz(spin);
	}
	//std::complex<double> i(0.,1.);
	res = -1.*std::complex<double>(0.,1.)*a*J;
	return MatrixExp(res);
}
template <class T>
AngularMomentum<T> RotationByAngle(const double &a, const AngularMomentum<T>& mat)
{
	 
	AngularMomentum<T> res;
	 
	res = -1.*std::complex<double>(0.,1.)*a*mat;
	return MatrixExp(res);
}
//--------------------------------------------------------------------------
//		Wigner functions 
//--------------------------------------------------------------------------
/*template <class T>
 AngularMomentum<T> AngularMomentum<T>::RotationByAngle(const std::string& dir, const double &a)
{}*/
} //end of namespace QuantaPlus
#endif

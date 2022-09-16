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
#ifndef QUANTAPLUS_ANGULARMOMENTUM_H
#define QUANTAPLUS_ANGULARMOMENTUM_H
//#include <unsupported/Eigen/MatrixFunctions>
#include <Eigen/Dense>
#include"utilities.h"
//#include"operators.h"

namespace QuantaPlus{

/*!********************************************************************* 
* \class AngularMomentum
* \brief Provieds General Formalism of Angular Momentum operators.   
* AngularMomentum is a publicly derived class from tQM_operator<T>
**********************************************************************/
template <class T>
class AngularMomentum : public Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>//public QM_operator<T> 
{
	public:
	 	/*!
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
	 
		AngularMomentum<T> AngularMomentum_JSquare(const double& spin_value); ///<The matrix representations of the squared general angular momentum operator \f$J^2\f$
		AngularMomentum<T> AngularMomentum_Jx(const double& spin_value); ///< The matrix representations of the angular momentum operator component \f$J_x\f$
		AngularMomentum<T> AngularMomentum_Jy(const double& spin_value); ///< The matrix representations of the angular momentum operator component \f$J_y\f$
		AngularMomentum<T> AngularMomentum_Jz(const double& spin_value); ///< The matrix representations of the angular momentum operator component \f$J_z\f$
		AngularMomentum<T> AngularMomentum_JPlus(const double& spin_value); ///< The matrix representations of the raising operator \f$J_{+}\f$
		AngularMomentum<T> AngularMomentum_JMinus(const double& spin_value); ///< The matrix representations of the raising operator \f$J_{-}\f$
		
		/*!
		@param dir is the axis of rotation.
		@param alpha is the rotation angle. 
		*/
		AngularMomentum<T> RotationByAngle(const std::string& dir, const double& alpha); ///< Representation of the Rotation Operator in generic direction \f$R_{n}(\alpha)\f$
		
		~AngularMomentum(){} ///<Destructor 

};
#include"include/angularmomentum.hpp"
} //end of namespace QuantaPlus
#endif

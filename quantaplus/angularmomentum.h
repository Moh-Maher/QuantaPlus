/*! \file angularmomentum.h is a part of QUANTAPLUS library. 
*define and handle some fundamental quantum operators.
ref: [N. Zettili, “Quantum Mechanics, Concepts and Applications,” Wiley, Chichester, 2001.]
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

/*! \class AngularMomentum
* General Formalism of Angular Momentum operators.   
* AngularMomentum is a publicly derived class from the well designed Eigen::Matrix
*/
template <class T>
class AngularMomentum : public Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>//public QM_operator<T> 
{
	public:
		AngularMomentum():Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>(){} // Default constructor.
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
	 
		AngularMomentum<T> AngularMomentum_JSquare(const double& spin_value); ///<The matrix representations of the squared general angular momentum operator J^2.
		AngularMomentum<T> AngularMomentum_Jx(const double& spin_value); ///< The matrix representations of the angular momentum operator component Jx.
		AngularMomentum<T> AngularMomentum_Jy(const double& spin_value); ///< The matrix representations of the angular momentum operator component Jy.
		AngularMomentum<T> AngularMomentum_Jz(const double& spin_value); ///< The matrix representations of the angular momentum operator component Jz.
		AngularMomentum<T> AngularMomentum_JPlus(const double& spin_value); ///< The matrix representations of the raising operator J+
		AngularMomentum<T> AngularMomentum_JMinus(const double& spin_value); ///< The matrix representations of the raising operator J-
		AngularMomentum<T> RotationByAngle(const std::string& dir, const double& alpha); ///< Representation of the Rotation Operator. 
		
		~AngularMomentum(){} ///<Destructor 

};
#include"include/angularmomentum.hpp"
} //end of namespace QuantaPlus
#endif

/*******************************************************************************************
@operator.h is a part of QUANTAPLUS library. 

usage: define and handle some fundamental quantum operators.

ref: [N. Zettili, “Quantum Mechanics, Concepts and Applications,” Wiley, Chichester, 2001.]

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
//#pragma once
#ifndef QUANTAPLUS_INCLUDE_ANGULARMOMENTUM_H
#define QUANTAPLUS_INCLUDE_ANGULARMOMENTUM_H
//#include <unsupported/Eigen/MatrixFunctions>
#include <Eigen/Dense>
#include"utilities.h"
//#include"operators.h"

namespace QuantaPlus{

/***************************************************************************
  Class:    AngularMomentum.

  Summary: General Formalism of Angular Momentum operators.   
  	   AngularMomentum is a publicly derived class from the well designed Eigen::Matrix

  Methods: AngularMomentum_JSquare
		The matrix representations of the squared general angular momentum operator J^2.
            AngularMomentum_Jx
		The matrix representations of the angular momentum operator component Jx.
            AngularMomentum_Jy
		The matrix representations of the angular momentum operator component Jy.
            AngularMomentum_Jz
		The matrix representations of the angular momentum operator component Jz.
            AngularMomentum_JPlus
		The matrix representations of the raising operator J+
            AngularMomentum_JMinus
		The matrix representations of the lowering operator J-
            RotationByAngle
		Representation of the Rotation Operator.              
            AngularMomentum
		Constructor.
            ~AngularMomentum
		Destructor.
***************************************************************************/
template <class T>
class AngularMomentum : public Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>//public QM_operator<T> 
{
	public:
		AngularMomentum():Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>(){};
		AngularMomentum(int row, int col):Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>(row,col){};
	
		template<typename Derived>
		AngularMomentum(const Eigen::MatrixBase<Derived>& other)
		:Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>(other){ }
	   	
	   	//<--This method allows us to assign Eigen expressions to Ket
		template<typename Derived>
		AngularMomentum& operator=(const Eigen::MatrixBase <Derived>& other)
		{
			this->Eigen::Matrix<T,Eigen::Dynamic ,Eigen::Dynamic>::operator=(other);
			return *this;
		}
		
		AngularMomentum<T> AngularMomentum_JSquare(const double& spin_value);
		AngularMomentum<T> AngularMomentum_Jx(const double& spin_value);
		AngularMomentum<T> AngularMomentum_Jy(const double& spin_value);
		AngularMomentum<T> AngularMomentum_Jz(const double& spin_value);
		AngularMomentum<T> AngularMomentum_JPlus(const double& spin_value);
		AngularMomentum<T> AngularMomentum_JMinus(const double& spin_value);
		AngularMomentum<T> RotationByAngle(const std::string& dir, const double& alpha);
		
		~AngularMomentum(){} 

};
#include"angularmomentum.hpp"
} //end of namespace QuantaPlus
#endif

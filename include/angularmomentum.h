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
#include"operators.h"

//namespace QuantaPlus{
template <class T>
class AngularMomentum : public QM_operator<T> 
{
public:
	AngularMomentum();
	AngularMomentum(int row, int col); 
	//AngularMomentum(const T *data );
	//AngularMomentum(const AngularMomentum<T,R,C> &amo); 
	//AngularMomentum(const double j); 
	~AngularMomentum();

	// AngularMomentum<T,R,C> operator= (const AngularMomentum<T,R,C> &amo);
	//AngularMomentum<T,R,C> operator * (const AngularMomentum<T,R,C> &amo) const;

	AngularMomentum<T> AngularMomentum_JSquare(const double& spin_value);
	AngularMomentum<T> AngularMomentum_Jx(const double& spin_value);
	AngularMomentum<T> AngularMomentum_Jy(const double& spin_value);
	AngularMomentum<T> AngularMomentum_Jz(const double& spin_value);

	AngularMomentum<T> AngularMomentum_JPlus(const double& spin_value);
	AngularMomentum<T> AngularMomentum_JMinus(const double& spin_value);

	AngularMomentum<T> RotationByAngle(const double& alpha);


};


void   MagneticQuantumNumber(const double &j);  
double KroneckerDelta (const double & i, const double & j);                          // δ[ij].
double Jsqr(const double & j, const double & j1, const double & m1, const double & j2, const double & m2);            // The square of the angular momentum J^2.
double Jx(const double & j, const double & j1,const double & m1, const double & j2,const double & m2);                // The x-component of the angular momentum operator J.
std::complex<double> Jy(const double & j, const double & j1,const double & m1, const double & j2,const double & m2);  // The y-component of J.
double Jz(const double & j1, const double & m1, const double & j2, const double & m2);              // The z-component of J. 
double Jplus(const double & j, const double & j1, const double & m1, const double & j2, const double & m2);
double Jminus(const double & j, const double & j1, const double & m1, const double & j2, const double & m2);
bool validAngularMomentum(const double &j);

#include"angularmomentum.hpp"
//} //end of namespace QuantaPlus
#endif

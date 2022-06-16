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
#ifndef QUANTAPLUS_INCLUDE_OPERATORS_H
#define QUANTAPLUS_INCLUDE_OPERATORS_H
//#include <unsupported/Eigen/MatrixFunctions>
#include <Eigen/Dense>
#include"utilities.h"

//namespace QuantaPlus{
template<class T>
class QM_operator: public Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>
{
public:
	QM_operator();
	QM_operator(int row,int col);
	~QM_operator();
};

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
double KroneckerDelta (double i, double j);                          // δ[ij].
double Jsqr(double j, double j1, double m1, double j2, double m2);            // The square of the angular momentum J^2.
double Jx(double j, double j1,double m1, double j2,double m2);                // The x-component of the angular momentum operator J.
std::complex<double> Jy(double j, double j1,double m1, double j2,double m2);  // The y-component of J.
double Jz(double j, double j1, double m1, double j2, double m2);              // The z-component of J. 
double Jplus(double j, double j1, double m1, double j2, double m2);
double Jminus(double j, double j1, double m1, double j2, double m2);
bool SpinValidation(double &j);

#include"operators.hpp"
//} //end of namespace QuantaPlus
#endif

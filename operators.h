/*******************************************************************************************
@operator.h is a part of QUANTA-x library. 

usage: define and handle some fundamental quantum operators.

ref: [N. Zettili, “Quantum Mechanics, Concepts and Applications,” Wiley, Chichester, 2001.]

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#pragma once
#ifndef OPERATORS_H
#define OPERATORS_H
#include <Eigen/Dense>
#include"utilities.h"

template <class T, int R, int C>
class Q_operator: public Eigen::Matrix<T, R, C> 
{
public:
	Q_operator();
	Q_operator(int row,int col); 
	~Q_operator();      
};

void   Magnetic_Quantum_Number(const double &j);  
double KroneckerDelta (double i, double j);                          // δ[ij].
double Jsqr(double j, double j1, double m1, double j2, double m2);            // The square of the angular momentum J^2.
double Jx(double j, double j1,double m1, double j2,double m2);                // The x-component of the angular momentum operator J.
std::complex<double> Jy(double j, double j1,double m1, double j2,double m2);  // The y-component of J.
double Jz(double j, double j1, double m1, double j2, double m2);              // The z-component of J. 
double Jplus(double j, double j1, double m1, double j2, double m2);
double Jminus(double j, double j1, double m1, double j2, double m2);
bool SpinValidation(double &j);

#include"operators.tpp"
#endif

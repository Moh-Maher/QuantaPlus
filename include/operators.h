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
#ifndef OPERATORS_H
#define OPERATORS_H
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
class Angular_Momentum : public QM_operator<T> 
{
public:
	Angular_Momentum();
	Angular_Momentum(int row, int col); 
	//Angular_Momentum(const T *data );
	//Angular_Momentum(const Angular_Momentum<T,R,C> &amo); 
	//Angular_Momentum(const double j); 
	~Angular_Momentum();

	// Angular_Momentum<T,R,C> operator= (const Angular_Momentum<T,R,C> &amo);
	//Angular_Momentum<T,R,C> operator * (const Angular_Momentum<T,R,C> &amo) const;

	Angular_Momentum<T> Angular_Momentum_OperatorJSqr(const double &j);
	Angular_Momentum<T> Angular_Momentum_OperatorJx(const double &j);
	Angular_Momentum<T> Angular_Momentum_OperatorJy(const double &j);
	Angular_Momentum<T> Angular_Momentum_OperatorJz(const double &j);

	Angular_Momentum<T> Angular_Momentum_OperatorJPlus(const double &j);
	Angular_Momentum<T> Angular_Momentum_OperatorJMinus(const double &j);

	Angular_Momentum<T> RotationByAngle(const double &a);


};
//--------------------------------------------------------------------------
//		defult constructor
//--------------------------------------------------------------------------
template <class T>
Angular_Momentum<T>::Angular_Momentum():QM_operator<T>(){}
//--------------------------------------------------------------------------
//		Constructor for oam vector of a given rows
//--------------------------------------------------------------------------
template <class T>
Angular_Momentum<T>::Angular_Momentum(int row, int col):QM_operator<T>(row,col){}
 
//---------------------------------------------------------------------------
//  test  
//---------------------------------------------------------------------------
//template <class T, int R, int C>
//Angular_Momentum<T,R,C>::Angular_Momentum(const double j)
//:matrix<T,R,C>(2*j+1,2*j+1){}
//--------------------------------------------------------------------------
//		destructor
//--------------------------------------------------------------------------
template <class T>
Angular_Momentum<T>::~Angular_Momentum(){ }


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
//} //end of namespace QuantaPlus
#endif

//=================================================================================================
/*!
//  \file qubit.h
//  \brief  Construct qubit representation in C++
//
//  Copyright (c) 2023 Mohammed Maher Abdelrahim Mohammed
*/
//=================================================================================================
#pragma once
#include <Eigen/Dense>
#include <string>
#include <cmath>
#include"ket.h"
#include"../operators/operators.h"
#include"../operators/angularmomentum.h"
#include"../utilities/print.h"
namespace QuantaPlus{

typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> EmatXd;

//class Qregister;
//--------------------------------------------------------------------------
// general rules
//--------------------------------------------------------------------------
//int MagicRule[8]={0};
/*void BinaryNum(int decimal)
{ //int MagicRule[decimal]={0};
	int binary = 0, remainder, product = 1;
	int count=0;
	while (decimal != 0) {
		remainder = decimal % 2;
		//MagicRule[count]=remainder;
		binary = binary + (remainder * product);
		decimal = decimal / 2;
		product *= 10;
		count++;
	std::cout<<binary;
	}

}*/
/*!*****************************************************************
* \class QuantumRegister
* \brief QuantumRegister is a publicly derived class from Eigen::Matrix, 
*
* QuantumRegister are square matrices with Dynamic-size.
******************************************************************/
 
class QuantumRegister: public EmatXd
{
  private: 
	int _dim;
	EmatXd _qBasis;
	Ket<double> _qState;
  public:
  	EmatXd qBasis;
	/*!
        * Create an empty one matrix. Dynamically allocate numbers of rows and columns at run-time.
        */ 
	QuantumRegister(): EmatXd(){} ///<Default constructor.
	
	/*!\brief Constructor with fixed Number of rows and columns.
        * Create an empty one matrix. Dynamically Allocate  fixed numbers of rows and columns at compile-time.
        * @param row is the Number of rows.
        * @param col is the Number of columns.
        */
	QuantumRegister(const int& d)
	{
		int N = (int)std::pow(2,d);
		_dim=N;
		_qBasis=EmatXd::Identity(N,N);
		qBasis= _qBasis;
	}
	
	template<typename Derived> 
	QuantumRegister(const Eigen::MatrixBase<Derived>& other)
	:EmatXd(other){ } ///< construct QuantumRegister from Eigen expressions.
 
    	/*!Assign Eigen expressions to QuantumRegister*/
	template<typename Derived>
	QuantumRegister& operator=(const Eigen::MatrixBase <Derived>& other)
	{
		this->EmatXd::operator=(other);
		return *this;
	}
	
	int getDim() const{
		return _dim;
	}
	
	Ket<double> getqState(const int& n){
 
		Ket<double> temp(_dim);
		for(int i=0; i<_dim; i++){
			temp[i] = _qBasis(i,n);
		}
		_qState = temp;
		//std::cout<< _qState<<std::endl;
		return _qState;
	}
	
	~QuantumRegister(){} ///< Destructor
};
class QuantumCircuit: public EmatXd
{
  private: 
	int _dim;
	EmatXd _qGate1;
	EmatXd _qGate2;
	Ket<double> _qState;
	Ket<double> _outcome;
	//_outcome = EmatXd::Zero(_dim,1)
  public:
  	EmatXd qGate1, qGate2;
 
	QuantumCircuit(): EmatXd(){} ///<Default constructor.
 
	QuantumCircuit(const int& d)
	{
		int N = (int)std::pow(2,d);
		_dim=N;
		_qGate1=EmatXd::Identity(N,N);
		_qGate2=EmatXd::Identity(N,N);
	}
	
	QuantumCircuit(const QuantumRegister& qr){
		int N = qr.getDim();//(int)std::pow(2, qr.getDim());
		_dim=N;
		_qGate1=EmatXd::Identity(N,N);
		_qGate2=EmatXd::Identity(N,N);
	
	}
	template<typename Derived> 
	QuantumCircuit(const Eigen::MatrixBase<Derived>& other)
	:EmatXd(other){ } ///< construct QuantumCircuit from Eigen expressions.
 
    	/*!Assign Eigen expressions to QuantumRegister*/
	template<typename Derived>
	QuantumCircuit& operator=(const Eigen::MatrixBase <Derived>& other)
	{
		this->EmatXd::operator=(other);
		return *this;
	}
	void operate( const EmatXd& opr,const Ket<double>& target){
		Ket<double> temp(_dim);
		//EmatXd temp_target(target.rows(),1);
		//temp_target = target;
		if(opr.rows()< _dim){
			temp = KroneckerProduct(opr,Id<double>(0.5))*target;//KroneckerProduct(temp_target,Id<double>(0.5));
					_qState = temp;
		}
		
		else{
			temp = opr*target;
					_qState = temp;
		}
		_outcome = _qState+EmatXd::Zero(_dim,1);

	}
	Ket<double> getqState(){
 
		/*Ket<double> temp(_dim);
		for(int i=0; i<_dim; i++){
			temp[i] = _qState(i);
		}
		_qState = temp;*/
		//std::cout<< _qState<<std::endl;
		return _qState;
	}
	Ket<double> getOutcome(){
		//std::cout<<_outcome<<std::endl;
		return _outcome;
	}
	
	~QuantumCircuit(){} ///< Destructor
};
//==================================================================
//
//==================================================================
QM_operator<double> xGate(){
	//QM_operator<double> sigmaX(2,2);
 	//sigmaX << 0.,1.,1.,0.;
	return PauliMatrices::sigma_x().real();//sigmaX;
}
//==================================================================
//
//==================================================================
QM_operator<std::complex<double>> yGate(){
	//using namespace std::complex_literals; 
	//QM_operator<std::complex<double>> sigmaY(2,2);
 	//sigmaY << 0., 1.0i, -1.0i, 0.;
	return PauliMatrices::sigma_y();//sigmaY;
}
//==================================================================
//
//==================================================================
QM_operator<double> zGate(){
	//QM_operator<double> sigmaz(2,2);
 	//sigmaz << 1.,0.,0.,-1.;
	return PauliMatrices::sigma_z().real();//sigmaz;
}
//==================================================================
//
//==================================================================
QM_operator<double> hadmardGate(){
	QM_operator<double> H(2,2);
 	H <<1.,1.,1.,-1.;
	return H/std::sqrt(2);
}
//==================================================================
// universal Control gate
//==================================================================
EmatXd controledGate(const EmatXd& uGateType){
	const auto size = 2*uGateType.rows();
	EmatXd cGate(size,size);	
	const auto uGate_postion_index = uGateType.rows();
	cGate = EmatXd::Identity(size, size);
	for(int i=0; i<uGateType.rows(); i++){
		for(int j=0; j<uGateType.cols(); j++){
			cGate(i+uGate_postion_index,j+uGate_postion_index) =  uGateType(i,j);	
		}
	}
	return cGate;
}
} //end of namespace QuantaPlus

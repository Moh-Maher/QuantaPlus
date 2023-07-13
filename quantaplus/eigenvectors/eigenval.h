/*!\file eigenval.h
*  \brief eigenval.h is a part of QuantaPlus provides support for braket.h.
*/
/*------------------------------------------------------------------------------------------
  by:  	     Mohammed Maher Abdelrahim Mohammed
       	     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
	     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
       	     mohammed.maher@unical.it  
------------------------------------------------------------------------------------------*/
#ifndef QUANTAPLUS_EIGENVECTORS_EIGENVAL_H
#define QUANTAPLUS_EIGENVECTORS_EIGENVAL_H

namespace QuantaPlus {


/*!****************************************************************
* \brief compute specific Eigen values for Eigen::Matrix.
* @param mt is Dynamic-size Eigen::Matrix.
* @param i the selector var to pick the specified Eigen value
* @return selected eigenvalues for a given matrix. 
******************************************************************/
template<typename T>
T QuantumEigenValue(Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>  &mat,const int& i)
{
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> > eigensolver(mat);
   
	if (eigensolver.info() != Eigen::Success) abort();
   
	return eigensolver.eigenvalues()[i];
}
/*!***********************************************************************
* \brief overloaded version to compute all Eigen values for Eigen::Matrix.
* @param mt is a Dynamic-size Eigen::Matrix.
* @return all eigenvalues for a given matrix. 
*************************************************************************/
template<typename T>
Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> 
QuantumEigenValue(const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>  &mat)
{
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> > eigensolver(mat);
   
	if (eigensolver.info() != Eigen::Success) abort();
   
	return eigensolver.eigenvalues();
}


template<typename T>
T QuantumEigenValue(const Ket<T> &mat,const int& i)
{
	Eigen::SelfAdjointEigenSolver<Ket<T> > eigensolver(mat);
   
	if (eigensolver.info() != Eigen::Success) abort();
   
	return eigensolver.eigenvalues()[i];
}
} //end of namespace QuantaPlus
#endif

/*!\file eigenvec.h
*  \brief eigenvec.h is a part of QuantaPlus provides support for braket.h.
*/
/*------------------------------------------------------------------------------------------
  by:  	     Mohammed Maher Abdelrahim Mohammed
       	     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
	     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
       	     mohammed.maher@unical.it  
------------------------------------------------------------------------------------------*/
#ifndef QUANTAPLUS_EIGENVECTORS_EIGENVEC_H
#define QUANTAPLUS_EIGENVECTORS_EIGENVEC_H
namespace QuantaPlus {
 
/*!****************************************************************
* \brief compute specific Eigen vectors for Eigen::Matrix.
* @param mt is a square Eigen::Matrix with Dynamic-size.
* @param col_number is the column of the selected eigen vector
* @return Specified column of eigenvector for a given matrix. 
******************************************************************/
template<typename T>
Eigen::Matrix<T,Eigen::Dynamic,1> 
QuantumEigenVector(Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> &mat, const int& col_number)
{
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>> eigensolver(mat);
   
	if (eigensolver.info() != Eigen::Success) abort();
  
	return eigensolver.eigenvectors();//.col(col_number);
}
/*!****************************************************************************
* \brief overloaded version to compute all the Eigen vectors for Eigen::Matrix.
* @param mt is a square Eigen::Matrix with Dynamic-size.
* @return eigenvectors for a given matrix. 
******************************************************************************/
template<typename T> 
Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> 
QuantumEigenVector(Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> &mat)
{
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>> eigensolver(mat);
   
	if (eigensolver.info() != Eigen::Success) abort();
  
	return eigensolver.eigenvectors();//.col(col_number);
}
 
 
} //end of namespace QuantaPlus
#endif // BRAKET_HPP

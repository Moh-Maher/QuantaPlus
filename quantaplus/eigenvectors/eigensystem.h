/*!\file eigensystem.h
*  \brief eigensystem.h is a part of QuantaPlus.
*/
/*------------------------------------------------------------------------------------------
  by:  	     Mohammed Maher Abdelrahim Mohammed
------------------------------------------------------------------------------------------*/
#ifndef QUANTAPLUS_EIGENVECTORS_EIGENSYSTEM_H
#define QUANTAPLUS_EIGENVECTORS_EIGENSYSTEM_H

#include"../braket/ket.h"
#include "eigenvec.h"  // Include the eigenvec.h header
#include "eigenval.h"  // Include the eigenval.h header

namespace QuantaPlus {

template <typename T = std::complex<double>>
class EigenSystem {
public:
    EigenSystem() = default;

    EigenSystem(const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mat) : matrix_(mat) {}

    void setMatrix(const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mat) {
        matrix_ = mat;
    }

    Eigen::Matrix<T, Eigen::Dynamic, 1> computeEigenVector(int col_number) {
        Eigen::SelfAdjointEigenSolver<Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>> eigensolver(matrix_);

        if (eigensolver.info() != Eigen::Success) abort();

        return eigensolver.eigenvectors().col(col_number);
    }

    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> computeAllEigenVectors() {
        Eigen::SelfAdjointEigenSolver<Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>> eigensolver(matrix_);

        if (eigensolver.info() != Eigen::Success) abort();

        return eigensolver.eigenvectors();
    }

    T computeEigenValue(int i) {
        Eigen::SelfAdjointEigenSolver<Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>> eigensolver(matrix_);

        if (eigensolver.info() != Eigen::Success) abort();

        return eigensolver.eigenvalues()[i];
    }

    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> computeAllEigenValues() {
        Eigen::SelfAdjointEigenSolver<Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>> eigensolver(matrix_);

        if (eigensolver.info() != Eigen::Success) abort();

        return eigensolver.eigenvalues();
    }

private:
    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> matrix_;
};

} // end of namespace QuantaPlus

#endif // QUANTAPLUS_EIGENVECTORS_EIGENSYSTEM_H


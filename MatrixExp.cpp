#include <unsupported/Eigen/MatrixFunctions>
#include <iostream>
using namespace Eigen;




MatrixXd MatrixExp(MatrixXd A){

return  A.exp();
}


MatrixXd MatrixExp(MatrixXd A, MatrixXd V ){

return  A.exp()*V;
}


int main()
{
/*
  const double pi = std::acos(-1.0);
  MatrixXd A(3,3);
  A << 1.2,    3.7 , 5.6,
       0, -2.2,     4,
       -5.3,    0,     1.4;
  std::cout << "The matrix A is:\n" << A << "\n\n";
  //std::cout << "The matrix exponential of A is:\n" << A.exp() << "\n\n";
std::cout << "The matrix exponential of A is:\n" << MatrixExp(A) << "\n\n";
*/

MatrixXd a(2,2);
MatrixXd v(2,1);

a<< 4, -5,
   -2,  1;
v<< 1.9,
    3.6;
    
       std::cout << "The matrix exponential of A*v is:\n" << MatrixExp(a,v) << "\n\n";

}


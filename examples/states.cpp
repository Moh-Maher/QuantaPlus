#include <iostream>
#include"../quantaplus/quantaplus.h"

int main() {
    using namespace QuantaPlus;
    
    // Creating a ket vector |psi> = (1/sqrt(2)) * (|0> + |1>)
    Ket Psi(2);
    Psi << 1.0/sqrt(2), 1.0/sqrt(2);

    // Creating a bra vector <phi| = (1/sqrt(2)) * (<0| + <1|)
    Bra Phi(2);
    Phi << 1.0/sqrt(2), 1.0/sqrt(2);
    
    // Print the ket and bra vectors
    std::cout << "Ket |psi>:" << std::endl;
    Psi.Print();
    std::cout<<"--------------"<<std::endl;
    std::cout << "Bra <phi|:" << std::endl;
    Phi.Print();
    
    return 0;
}


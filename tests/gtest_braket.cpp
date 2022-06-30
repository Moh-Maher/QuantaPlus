#include "braket.h"
#include <gtest/gtest.h>
#include <complex>

using namespace std::complex_literals;
 
 
TEST(DualConjugate, ketVector) { 
	
	Ket<std::complex<double>> ktA(3);
	Ket<std::complex<double>> brA(3);
	ktA <<1.-2i, 1i,-1i;
	brA <<1.+2i,-1i,1i;
	
	ASSERT_EQ(brA,DualConj(ktA));
	ASSERT_EQ(ktA.adjoint(),DualConj(ktA));
}

TEST(DualConjugate, BraVector) { 
	
	Bra<std::complex<double>> brA(3);
	Ket<std::complex<double>> ktA(3);
	brA <<-2i, 2.-1i,-1i;
	ktA <<2i, 2.+1i,1i;
 
	ASSERT_EQ(ktA, DualConj(brA));
	ASSERT_EQ(brA.adjoint(), DualConj(brA));
}


TEST(ScalarProduct, BraKet) { 
	
	Bra<std::complex<double>> psi(3);
	psi <<-5i, 2.,1i;
	Ket<std::complex<double>> phi(3);
	phi << 3.,8i, -9i;
        
        std::complex<double> res;
        res = psi*phi;
	
	ASSERT_EQ(9.+1i, BraKet(psi,phi));
	ASSERT_EQ(res, BraKet(psi,phi));
 
}

TEST(Sum, Kets) { 
	
	Ket<std::complex<double>> ktA(3);
	ktA <<-5i, 2.,1i;
	Ket<std::complex<double>> ktA2(3);
	ktA2 =ktA2.Ones(3);
	Ket<std::complex<double>> res(3);
	res<<1.-5i,3.,1.+1i;
 
	ASSERT_EQ(res, ktA+ktA2);

 
}

 

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

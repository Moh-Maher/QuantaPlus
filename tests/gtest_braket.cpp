/*******************************************************************************************
@gtest_braket.cpp is a part of QUANTAPLUS library. 
for tesing Ket and Bra classes from braket.h file using google test framework. 

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#include "braket.h"
#include <gtest/gtest.h>
#include <complex>

using namespace std::complex_literals;
 
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
//gtest class for testing the Ket class
class KetTest : public ::testing::Test
{
	protected:
		KetTest(){}
		virtual ~KetTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
//gtest class for testing the Bra class
class BraTest : public ::testing::Test
{
	protected:
		BraTest(){}
		virtual ~BraTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
//----------------------
//test for ket class
//----------------------
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
TEST_F(KetTest, DefaultConstructor)
{
	Ket<double> ket;
	EXPECT_EQ(ket.rows(),0);
	EXPECT_EQ(ket.cols(),1);
}
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
TEST_F(KetTest, ConstructorWithRowNumber)
{
	Ket<double> ket(3);
	EXPECT_EQ(ket.rows(),3);
	EXPECT_EQ(ket.cols(),1);
}
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
TEST_F(KetTest, ConstructorWithEigenExpression)
{
	Eigen::Matrix<double,3,1> mat;
	mat << 1,2,3;
	Ket<double> ket(mat);
	EXPECT_EQ(ket.rows(),3);
	EXPECT_EQ(ket.cols(),1);
}
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
TEST_F(KetTest, OperatorEqual)
{
	Ket<double> ket1(3);
	Ket<double> ket2(3);
	ket1 << 1,2,3;
	ket2 << 1,2,3;
	EXPECT_EQ(ket1,ket2);
}
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
//----------------------
//test for Bra class
//----------------------
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
TEST_F(BraTest, DefaultConstructor)
{
	Bra<double> bra;
	EXPECT_EQ(bra.rows(),1);
	EXPECT_EQ(bra.cols(),0);
}
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
TEST_F(BraTest, ConstructorWithColumnNumber)
{
	Bra<double> bra(3);
	EXPECT_EQ(bra.rows(),1);
	EXPECT_EQ(bra.cols(),3);
}
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
TEST_F(BraTest, ConstructorWithEigenExpression)
{
	Eigen::Matrix<double,1,3> mat;
	mat << 1,2,3;
	Bra<double> bra(mat);
	EXPECT_EQ(bra.rows(),1);
	EXPECT_EQ(bra.cols(),3);
}
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
//------------------------------
TEST_F(BraTest, OperatorEqual)
{
	Bra<double> bra1(3);
	Bra<double> bra2(3);
	bra1 << 1,2,3;
	bra2 << 1,2,3;
	EXPECT_EQ(bra1,bra2);
}
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
TEST_F(BraTest, OperatorPlus)
{
	Bra<double> bra1(3);
	Bra<double> bra2(3);
	bra1 << 1,2,3;
	bra2 << 1,2,3;
	Bra<double> bra3 = bra1 + bra2;
	EXPECT_EQ(bra3,bra1+bra2);
}
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
TEST_F(BraTest, OperatorMinus)
{
	Bra<double> bra1(3);
	Bra<double> bra2(3);
	bra1 << 1,2,3;
	bra2 << 1,2,3;
	Bra<double> bra3 = bra1 - bra2;
	EXPECT_EQ(bra3,bra1-bra2);
}
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
//----------------------
 TEST_F(KetTest, OperatorPlus)
{
	Ket<double> ket1(3);
	Ket<double> ket2(3);
	ket1 << 1,2,3;
	ket2 << 1,2,3;
	Ket<double> ket3 = ket1 + ket2;
	EXPECT_EQ(ket3.rows(),3);
	EXPECT_EQ(ket3.cols(),1);
	EXPECT_EQ(ket3(0),2);
	EXPECT_EQ(ket3(1),4);
	EXPECT_EQ(ket3(2),6);
}
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
TEST_F(KetTest, OperatorMinus)
{
	Ket<double> ket1(3);
	Ket<double> ket2(3);
	ket1 << 1,2,3;
	ket2 << 1,2,3;
	Ket<double> ket3 = ket1 - ket2;
	EXPECT_EQ(ket3.rows(),3);
	EXPECT_EQ(ket3.cols(),1);
	EXPECT_EQ(ket3(0),0);
	EXPECT_EQ(ket3(1),0);
	EXPECT_EQ(ket3(2),0);
}
//---------------------------------------------------------------------------------------------
//  
//--------------------------------------------------------------------------------------------- 
//testing the DualConj function 
TEST_F(KetTest, DualConj)
{
	Ket<std::complex<double>> ket(3);
	Bra<std::complex<double>> ket_conj(3);
	ket << 1.,2i,3.;
	ket_conj = DualConj(ket);
	EXPECT_EQ(ket_conj.rows(),1);
	EXPECT_EQ(ket_conj.cols(),3);
	EXPECT_EQ(ket_conj(0),1.);
	EXPECT_EQ(ket_conj(1),-2i);
	EXPECT_EQ(ket_conj(2),3.);
}
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
//testing the DualConj function 
TEST_F(BraTest, DualConj)
{
	Bra<std::complex<double>> bra(3);
	Ket<std::complex<double>> bra_conj(3);
	bra << -1i,2i,3.;
	bra_conj = DualConj(bra);
	EXPECT_EQ(bra_conj.rows(),3);
	EXPECT_EQ(bra_conj.cols(),1);
	EXPECT_EQ(bra_conj(0),1i);
	EXPECT_EQ(bra_conj(1),-2i);
	EXPECT_EQ(bra_conj(2),3.);
}
//---------------------------------------------------------------------------------------------
//  
//--------------------------------------------------------------------------------------------- 
//testing BraKet function of the class Bra and Ket
TEST_F(BraTest, BraKet)
{
	Ket<double> ket(3);
	ket << 1,2,3;
	Bra<double> bra(3);
	bra << 1,2,3;
	EXPECT_EQ(BraKet(bra,ket),14);
}
//----------------------------------------------------------------------

//test for void ComplexNumPrint(std::complex<double> complex_number,bool numerical_flag) 
TEST(ComplexNum, ComplexNumPrint)
{
	std::complex<double> complex_number(1.0,2.0);
	ComplexNumPrint(complex_number,true);
	EXPECT_EQ(complex_number.real(),1.0);
	EXPECT_EQ(complex_number.imag(),2.0);
}
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
// test ResultPrint(Bra<U>& bra) 
TEST_F(KetTest, ResultPrint)
{
	Ket<double> ket(2);
	ket << 1.0,2.0;
	ResultPrint(ket);
	EXPECT_EQ(ket(0),1.0);
	EXPECT_EQ(ket(1),2.0);
}
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
//test for ResultPrint(Ket<U>& ket) 
TEST_F(BraTest, ResultPrint)
{
	Bra<double> bra(2);
	bra << 1.0,2.0;
	ResultPrint(bra);
	EXPECT_EQ(bra(0),1.0);
	EXPECT_EQ(bra(1),2.0);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

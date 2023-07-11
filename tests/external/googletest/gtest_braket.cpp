/*******************************************************************************************
@gtest_braket.cpp is a part of QUANTAPLUS library. 
for tesing Ket and Bra classes from braket.h file using google test framework. 

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#include <gtest/gtest.h>
#include <complex>
#include"../quantaplus/quantaplus.h"
//---------------------------------------------------------------------------------------------
// Test the default constructor of Bra
//---------------------------------------------------------------------------------------------
TEST(BraTest, DefaultConstructor) {
  QuantaPlus::Bra<double> bra;
  EXPECT_EQ(bra.rows(), 1);
  EXPECT_EQ(bra.cols(), 0);
}
//---------------------------------------------------------------------------------------------
// Test the constructor with fixed number of columns
//---------------------------------------------------------------------------------------------
TEST(BraTest, ConstructorWithColumns) {
  QuantaPlus::Bra<std::complex<double>> bra(3);
  EXPECT_EQ(bra.rows(), 1);
  EXPECT_EQ(bra.cols(), 3);
}
//---------------------------------------------------------------------------------------------
// Test the assignment operator
//---------------------------------------------------------------------------------------------
TEST(BraTest, AssignmentOperator) {
  QuantaPlus::Bra<int> bra1(2);
  QuantaPlus::Bra<int> bra2(2);
  bra1 << 1, 2;
  bra2 = bra1;
  EXPECT_EQ(bra2(0), 1);
  EXPECT_EQ(bra2(1), 2);
}
//---------------------------------------------------------------------------------------------
// Test the equality operator
//---------------------------------------------------------------------------------------------
TEST(BraTest, EqualityOperator) {
  QuantaPlus::Bra<double> bra1(3);
  QuantaPlus::Bra<double> bra2(3);
  bra1 << 1.0, 2.0, 3.0;
  bra2 << 1.0, 2.0, 3.0;
  EXPECT_TRUE(bra1 == bra2);
}
//---------------------------------------------------------------------------------------------
// Test the Print function
//---------------------------------------------------------------------------------------------
TEST(BraTest, PrintFunction) {
  QuantaPlus::Bra<double> bra(3);
  bra << 1.0, 2.5, 3.7;
  // TODO: Redirect cout and verify the output
  bra.Print();
}
//---------------------------------------------------------------------------------------------
// Test the NPrint function
//---------------------------------------------------------------------------------------------
TEST(BraTest, NPrintFunction) {
  QuantaPlus::Bra<std::complex<double>> bra(2);
  bra << std::complex<double>(1.0, 2.0), std::complex<double>(3.0, 4.0);
  // TODO: Redirect cout and verify the output
  bra.NPrint();
}

//---------------------------------------------------------------------------------------------
//
//---------------------------------------------------------------------------------------------
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


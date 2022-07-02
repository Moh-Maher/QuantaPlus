/*******************************************************************************************
@gtest_QM_operators.cpp is a part of QUANTAPLUS library. 
for testing QM_operator from operators.h file, using google test framework. 

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#include<iostream>
#include<gtest/gtest.h>
#include<string>
#include<vector>
#include "operators.h"

//gtest class for testing QM_operator class 
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
class QM_operator_test: public ::testing::Test
{
	protected:
		QM_operator_test(){}
		virtual ~QM_operator_test(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
TEST_F(QM_operator_test, constructor_test)
{
	QM_operator<double> qm_operator_test;
	EXPECT_EQ(qm_operator_test.rows(),0);
	EXPECT_EQ(qm_operator_test.cols(),0);
}
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
TEST_F(QM_operator_test, constructor_test_with_row_and_col)
{
	QM_operator<double> qm_operator_test(2,3);
	EXPECT_EQ(qm_operator_test.rows(),2);
	EXPECT_EQ(qm_operator_test.cols(),3);
}
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
TEST_F(QM_operator_test, constructor_test_with_Eigen_expression)
{
	QM_operator<double> qm_operator_test(Eigen::Matrix<double,2,3>::Random());
	EXPECT_EQ(qm_operator_test.rows(),2);
	EXPECT_EQ(qm_operator_test.cols(),3);
}
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
TEST_F(QM_operator_test, operator_assignment_test)
{
	QM_operator<double> qm_operator_test(2,3);
	qm_operator_test = Eigen::Matrix<double,2,3>::Random();
	EXPECT_EQ(qm_operator_test.rows(),2);
	EXPECT_EQ(qm_operator_test.cols(),3);
}
//---------------------------------------------------------------------------------------------
//  
//---------------------------------------------------------------------------------------------
TEST_F(QM_operator_test, operator_assignment_test_with_Eigen_expression)
{
	QM_operator<double> qm_operator_test(2,3);
	qm_operator_test = Eigen::Matrix<double,2,3>::Random();
	EXPECT_EQ(qm_operator_test.rows(),2);
	EXPECT_EQ(qm_operator_test.cols(),3);
}

//main function
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

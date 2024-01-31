/*! \file utilities.h
*utilities.h is a part of QUANTAPLUS library. 
*/

/*-----------------------------------------------------------------------
by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
-----------------------------------------------------------------------*/
#pragma once
#ifndef QUANTAPLUS_UTILITIES_UTILITIES_H
#define QUANTAPLUS_UTILITIES_UTILITIES_H
#include<Eigen/Dense>
#include<string>
#include<sstream>
//#include <algorithm> // for using : str.find_first_not_of( "string" ) == std::string::npos
#include<complex>
#include<iostream>
#include<cmath>
#include<ctime>
#include<fstream>

 
namespace QuantaPlus{

/*! \class Output
* \brief Class to handle output operations and files.
*/
class Output
{
	public:
	 
	std::ofstream takeData; ///< Output stream class object to operate on files
	 
	/*!constructor receive input string represents thefile name
	* @param fileName is the name of the output file without the extension
	* which is already set to be ".dat"
	*/
	Output(std::string fileName) 
	{
		takeData.open(fileName + ".dat");
	}

	
	~Output()
	{
		takeData.close();
	} ///< Destructor to close the output file

	/*!function to write output to file
	*@param output represent the received data contents. 
	*/
	void writeOutput(std::string output)
	{
		takeData << output << std::endl;
	}
};

/*! \class ElapsedTime
* \brief Class to displays information about the execution time.
*/
class ElapsedTime{
	public:
		void Start(){
			start = std::clock();
		}
		void End()
		{
			std::cout<<"------------------------------------------"<<std::endl;
			duration = static_cast<double>(std::clock() - start) /static_cast<double> CLOCKS_PER_SEC;
			
			if (duration < 60.0) {
				std::cout << "Elapsed time: " << duration << " seconds !!" << std::endl;
			}
			else {
				std::cout << "Elapsed time: " << duration/60.0 << " mins" << std::endl;
			}
		}
	private:
		std::clock_t start;
		double duration;
};


//--------------------------------------------------------------------------
//	Function to check if the input is an integer. 
//--------------------------------------------------------------------------
bool IsNumber(const std::string& str) 
{
	return str.find_first_not_of( "0123456789" ) == std::string::npos;
}
//--------------------------------------
bool validInteger(const double& x)
{
	return static_cast<int>(x) - x == 0;
}

bool halfInteger(const double& x)
{
	return !validInteger(x) && validInteger(2*x);
}
//--------------------------------------------------------------------------


//--------------------------------------------------------------------------
//	Function to facrorize out a subblock of any squared Matrix
//-------------------------------------------------------------------------- 
typedef Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> DiynamicMatrixD;
DiynamicMatrixD subMatrix(const DiynamicMatrixD& composite_matrix, const std::string& block_postion){
	if(composite_matrix.rows() != composite_matrix.cols()){
		throw std::domain_error("The composite matrix was not square!");
	}
	DiynamicMatrixD subBlock(composite_matrix.rows()/2,composite_matrix.cols()/2);	
	const auto block_postion_index = composite_matrix.rows()/2;

	for(int i=0; i<subBlock.rows(); i++){
		for(int j=0; j<subBlock.cols(); j++){
			if(block_postion == "ur"){
				subBlock(i,j) = std::real(composite_matrix(i,j)); // uper right block
			}
			if(block_postion == "ul"){  
				subBlock(i,j) = std::real(composite_matrix(i,j+block_postion_index)); // uper left block
			}
			if(block_postion == "dr"){
				subBlock(i,j) = std::real(composite_matrix(i+block_postion_index,j)); // down right block

			}

			if(block_postion == "dl"){
				subBlock(i,j) = std::real(composite_matrix(i+block_postion_index,j+block_postion_index)); // down left block
			}
		}
	}
	return subBlock;
}
}//end of namespace QuantaPlus
#endif

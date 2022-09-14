/**************************************************************************************
utilities.h is a part of QUANTAPLUS library. 

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
**************************************************************************************/
//#pragma once
#ifndef QUANTAPLUS_INCLUDE_UTILITIES_H
#define QUANTAPLUS_INCLUDE_UTILITIES_H
#include <Eigen/Dense>
#include<string>
#include<sstream>
//#include <algorithm> // for using : str.find_first_not_of( "string" ) == std::string::npos
#include <complex>
#include<iostream>
#include<cmath>
#include<fstream>
#include <valarray> 
 

/* colors */
#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x)	"\x1B[1m" x RST
#define UNDL(x)	"\x1B[4m" x RST

//namespace QuantaPlus{

/*! \class Output
* class to handle output operations and files.
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

/*! convert numbers to string*/
template <typename T>
std::string ToString(const T& numb)
{
	std::stringstream ss;
	ss << numb;
	return ss.str();
}
//--------------------------------------------------------------------------
// print two numbers in literal fraction form (without any manipulation) 
//--------------------------------------------------------------------------
template <typename T1, typename T2>
std::string ToFraction(T1 numer, T2 denom)
{
	std::string res = ToString<T1>(numer);
	if(denom != 1)
	{
		res += "/";
		res += ToString<T2>(denom);
	}
	return res;
}
//--------------------------------------------------------------------------
// print the elements of QUANTx::matrix<T, R,C> in fractions form
//--------------------------------------------------------------------------
template <typename T>
void MatrixToString(T &mat)
{
	for(int i =0; i<mat.GetRow(); i++) {
		for(int j =0; j<mat.GetCol(); j++) {
		    decimalToFraction(mat.table[i][j]);
		    std::cout<<"\t";
		}
		std::cout<<std::endl;
	}
}

void ComplexNumPrint( std::complex<double> complex_number, bool numerical_flag); // print any complex number as z = x + iy 
void ResultPrint(const std::complex<double>& complex_num); // print the calculated in fraction and symbolic forms (e.g: 15/7, i/2, √2/19. ..)  
void NResultPrint(const std::complex<double>& complex_num); //Print calculated result in numric form
void DecimalToFraction(const double& decimal_number);//void DecimalToFraction(double number); // convert decimal to fraction
void StringMatrix(int r, int c, double *array); // print array elements in fractions form

bool IsNumber(const std::string& str); // gives True if str is an integer, and False otherwise. 
void Warning(const std::string & str); // show warnings in highlighted from.
bool validInteger(const double& x); // check if the input is an integer.
bool halfInteger(const double& x); // check if the input is a half-integer. 

//void TolaTex(std::string fname, std::string data);

#include"utilities.hpp"
//}//end of namespace QuantaPlus
#endif

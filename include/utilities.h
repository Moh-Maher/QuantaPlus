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

#include<string>
#include<sstream>
#include <algorithm> // for using : str.find_first_not_of( "string" ) == std::string::npos
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

//long long gcd(long long a, long long b);
void DecimalToFraction(const double& decimal_number);//void DecimalToFraction(double number); // convert decimal to fraction
void StringMatrix(int r, int c, double *array); // print array elements in fractions form

bool IsNumber(const std::string& str); // gives True if str is an integer, and False otherwise. 
void Warning(const std::string & str);

//void TolaTex(std::string fname, std::string data);

#include"utilities.hpp"
//}//end of namespace QuantaPlus
#endif

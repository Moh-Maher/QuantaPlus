/**************************************************************************************
utilities.h is a part of QUANTA-x library. 

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
**************************************************************************************/
#pragma once
#ifndef UTILITIES_H
#define UTILITIES_H
#include<string>
#include<sstream>
#include <algorithm> // for using : str.find_first_not_of( "string" ) == std::string::npos

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

//namespace QUANTAx{
long long gcd(long long a, long long b);
void decimalToFraction(double number); // convert decimal to fraction
void StringMatrix(int r, int c, double *array); // print array elements in fractions form

bool isNumber(const std::string& str); // gives True if str is an integer, and False otherwise. 
void Warning(const std::string & str);
//--------------------------------------------------------------------------
// convert numbers to string
//--------------------------------------------------------------------------
template <typename T>
std::string ToString(T numb)
{
    std::stringstream ss;
    ss << numb;
    return ss.str();
}
//--------------------------------------------------------------------------
// convert to numbers to fraction form
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
 for(int i =0; i<mat.GetRow(); i++)
    {
        for(int j =0; j<mat.GetCol(); j++)
        {
            decimalToFraction(mat.table[i][j]);
            std::cout<<"\t";
        }
        std::cout<<std::endl;
    }
}
 
//}//end of namespace QUANTAx
#endif

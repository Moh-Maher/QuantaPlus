/*******************************************************************************************
some of "utilities.h" meathods implementation.

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#pragma once
#include<iostream>
#include<cmath>
#include <valarray> 
#include<sstream>
#ifndef QUANTAPLUS_INCLUDE_UTILITIES_TTP
#define QUANTAPLUS_INCLUDE_UTILITIES_TTP

#ifndef QUANTAPLUS_INCLUDE_UTILITIES_TTP
#error __FILE__ should only be included from utilities.h.
#endif // UTILITIES_H
//--------------------------------------------------------------------------
// convert numbers to string
//--------------------------------------------------------------------------
template <typename T>
std::string ToString(const T& numb)
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
/*
//----------------------------------------------------------------------------
long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    if (a < b)
        return gcd(a, b % a);
    else
        return gcd(b, a % b);
}
*/
//--------------------------------------------------------------------------
//	Function to convert decimal to fraction
//--------------------------------------------------------------------------
/*
void DecimalToFraction(double number)
{
    // Fetch integral value of the decimal
    double intVal = floor(number);
 
    // Fetch fractional part of the decimal
    double fVal = number - intVal;
 
    // Consider precision value to
    // convert fractional part to
    // integral equivalent
    const long pVal = 1000000000;
 
    // Calculate GCD of integral
    // equivalent of fractional
    // part and precision value
    long long gcdVal
        = gcd(round(fVal * pVal), pVal);
 
    // Calculate num and deno
    long long num
        = round(fVal * pVal) / gcdVal;
    long long deno = pVal / gcdVal;
 if(deno != 1){
    // Print the fraction
    std::cout << (intVal * deno) + num
         << "/" << deno;
         }
         else{std::cout<<number;}
}
*/
void DecimalToFraction(const double& decimal_number ) 
{

	int signdec  = decimal_number > 0 ? 1 : -1;
	if(!IsNumber(ToString(decimal_number)) && decimal_number!=0 && decimal_number!=1)
	{
	 
		double z = decimal_number*decimal_number;

		if(IsNumber(ToString(z))) 
		{
			std::cout<<"√"<<z; 
		}

		else if (!IsNumber(ToString(z))) 
		{ 
			int cycles = 10;
			double precision = 5e-4;  
			double number = z;

			int sign  = number > 0 ? 1 : -1;
			number = number * sign; //abs(number);
			double new_number,whole_part;
			double decimal_part =  number - (int)number;
			int counter = 0;

			std::valarray<double> vec_1{double((int) number), 1}, vec_2{1,0}, temporary;

			while(decimal_part > precision & counter < cycles)
			{
				new_number = 1 / decimal_part;
				whole_part = (int) new_number;

				temporary = vec_1;
				vec_1 = whole_part * vec_1 + vec_2;
				vec_2 = temporary;

				decimal_part = new_number - whole_part;
				counter += 1;
			}

			double numt = sign * vec_1[0];
			double dnum = vec_1[1];
			double snumt= sqrt(numt);
			double sdnum= sqrt(dnum);
			if(signdec>0)
			{
				if(IsNumber(ToString(snumt)) && IsNumber(ToString(sdnum)))
				{
					std::cout<< snumt<<'/'<< sdnum;
				} 

				else if(IsNumber(ToString(snumt)) && (!IsNumber(ToString(sdnum))) )
				{
					std::cout<< snumt<<'/'<<"√"<< vec_1[1];
				}
				else if( !IsNumber(ToString(snumt)) && (IsNumber(ToString(sdnum))) )
				{
					std::cout<<"√"<< sign * vec_1[0]<<'/'<< sdnum;
				}
				else 
				std::cout<<"√("<< sign * vec_1[0]<<'/'<< vec_1[1]<<")";
			}
			
			else if(signdec<0)
			{
				if(IsNumber(ToString(snumt)) && IsNumber(ToString(sdnum)))
				{
					std::cout<< "-"<<snumt<<'/'<< sdnum;
				} 

				else if(IsNumber(ToString(snumt)) && (!IsNumber(ToString(sdnum))) )
				{
					std::cout<< snumt<<'/'<<"-√"<< vec_1[1];
				}
				else if( !IsNumber(ToString(snumt)) && (IsNumber(ToString(sdnum))) )
				{
					std::cout<<"-√"<< sign * vec_1[0]<<'/'<< sdnum;
				}
				else 
				std::cout<<"-√("<< sign * vec_1[0]<<'/'<< vec_1[1]<<")";
			}
		}
	}

	else std::cout<<decimal_number;
	}
//--------------------------------------------------------------------------
//	Function to convert matrix elements to fraction
//--------------------------------------------------------------------------
void StringMatrix(int r, int c, double *array)
{
    for(int i =0; i<r; i++)
    {
        for(int j =0; j<c; j++)
        {
            DecimalToFraction(array[j+i*c]);
            std::cout<<"\t";
        } 
        std::cout<<"\n";
    }
}
//--------------------------------------------------------------------------
//	Function to check if the input is an integer. 
//--------------------------------------------------------------------------
bool IsNumber(const std::string& str) 
{
    return str.find_first_not_of( "0123456789" ) == std::string::npos;
}
//--------------------------------------------------------------------------
//	Function to print highlighted message.
//-------------------------------------------------------------------------
void Warning(const std::string & str)
{ 
 //std::cout<<FYEL("[")<<FRED("ERROR!:")<<FYEL(<<str<<" ]\n");
 std::cout<<FYEL("[")<<FYEL(<<str<<" ]\n");
}
#endif // UTILITIES_TTP

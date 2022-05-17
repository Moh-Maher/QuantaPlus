/*******************************************************************************************
some of "utilities.h" meathods implementation.

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#include<iostream>
#include<cmath>
#include"utilities.h"

/*
void cplx_print(std::complex<double> a)
{
	double x = std::real(a);
	double y = std::imag(a);   
	if(x!=0 and y!=0)
    	{
        	if(y<0)
        	{
            		std::cout<<x<<y<<"i"<<"\t";
        	}

        	else if(y>0)
        	{	
            		std::cout<<x<<"+" <<y<<"i"<<"\t";
        	}
	}
   	else if(y==0)
    	{   
        	std::cout<<x<<"\t";
    	}
    	else if(x==0)
    	{
        	std::cout<<y<<"i"<<"\t"; 
    	}    
}	
 */
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

//--------------------------------------------------------------------------
//	Function to convert decimal to fraction
//--------------------------------------------------------------------------
void decimalToFraction(double number)
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
//--------------------------------------------------------------------------
//	Function to convert matrix elements to fraction
//--------------------------------------------------------------------------
void StringMatrix(int r, int c, double *array)
{
    for(int i =0; i<r; i++)
    {
        for(int j =0; j<c; j++)
        {
            decimalToFraction(array[j+i*c]);
            std::cout<<"\t";
        } 
        std::cout<<"\n";
    }
}
//--------------------------------------------------------------------------
//	Function to check if the input is an integer. 
//--------------------------------------------------------------------------
bool isNumber(const std::string& str) 
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

#ifndef QUANTAPLUS_BRAKET_PRINT_H
#define QUANTAPLUS_BRAKET_PRINT_H
#include <Eigen/Dense>
#include <complex>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include <valarray>
#include"utilities.h"

namespace QuantaPlus{

/*!
*convert input into string.
* @param numb is a generic variable of any type.
*/
template <typename T>
std::string ToString(const T& numb)
{
	std::stringstream ss;
	ss << numb;
	return ss.str();
}

/*!
* print two numbers in literal fraction form (without any manipulation) 
* @param numer is the numerator of the fraction.
* @param denom is the denominator.
*/
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

/*!
* print the elements of QUANTx::matrix<T, R,C> in fractions form
* @param mat is Dynamic-size matrix with numeric elements.
*/
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

 
/*!
* Function to convert decimal to fraction
* @param decimal_number is the targeted number we want to converted into the fractional form A/B
*/
void DecimalToFraction(const double& decimal_number ) 
{
       
	int signdec  = decimal_number > 0 ? 1 : -1;  // check the sign of the input number to select the sign of the final output.
	std::string plusorminus="";

	if(signdec==-1) {
		plusorminus="-";
	}
	// if the number in not integer and not zero or +1/-1 start the procedure to write it in fraction form 
	if(!IsNumber(ToString(std::abs(decimal_number))) && decimal_number!=0 && decimal_number!=1.  && decimal_number!=-1. ) 
	{
	 
		double z = decimal_number*decimal_number;
                //  if the square of the number z is an integer, then it can be written as + or - square root of z^2.  
		if(IsNumber(ToString(z))) 
		{
			std::cout<<plusorminus+"√"<<z;
		}

		else if (!IsNumber(ToString(z))) // if the square of the number z is not an integer, proceed to write it as fraction.
		{ 
			int cycles = 10;
			double precision = 5e-4;  
			double number = z;

			int sign  = number > 0 ? 1 : -1; // check the sign again but for different reason. 
			number = number * sign; // abs(number);
			double new_number, whole_part;
			double decimal_part =  number - (int)number; // exclude the integer on the left or the floating point "."
			int counter = 0;

			std::valarray<double> vec_1{double((int) number), 1}, vec_2{1,0}, temporary;

			while( (decimal_part > precision)  & (counter < cycles) )
			{
				new_number = 1 / decimal_part;
				whole_part = (int) new_number;

				temporary = vec_1;
				vec_1 = whole_part * vec_1 + vec_2;
				vec_2 = temporary;

				decimal_part = new_number - whole_part;
				counter += 1;
			}
			
			if(IsNumber(ToString(sqrt(sign * vec_1[0]))) && IsNumber(ToString(sqrt(vec_1[1]))))  // if both numerator and denominator square roots are integers, evaluate them directly. 
			{
				std::cout<<plusorminus<<sqrt(sign * vec_1[0])<<'/'<< sqrt(vec_1[1]);
			} 
			
			// square root of denominator not an integer, write "√denominator" explicitly 
			else if(IsNumber(ToString(sqrt(sign * vec_1[0]))) && (!IsNumber(ToString(sqrt(vec_1[1])))) )
			{
				std::cout<<plusorminus<<sqrt(sign * vec_1[0])<<'/'<<"√"<< vec_1[1];
			}
			// square root of the numerator is not an integer, write "√numerator" explicitly  
			else if( !IsNumber(ToString(sqrt(sign * vec_1[0]))) && (IsNumber(ToString(sqrt(vec_1[1])))) )
			{
				std::cout<<plusorminus+"√"<< sign * vec_1[0]<<'/'<< sqrt(vec_1[1]);
			}
			// square root of both numerator and denominator not an integer, write "√(numerator/denominator" explicitly
			else 
			std::cout<<plusorminus+"√("<< sign * vec_1[0]<<'/'<< vec_1[1]<<")";
	 
		}
	}

	else std::cout<<decimal_number; // if the number in an integer or equal 0, 1 or -1, write it directly as it is.
}
/*!
*@param complex_number is a complex variable with "double-type" real and imaginary parts.
*@param numerical_flag is boolean variable to switch between numerical an symbolic output.
*/
void ComplexNumPrint( std::complex<double> complex_number, bool numerical_flag)
{
	double real_part = std::real(complex_number); // take the real part of the input
	double imaginary_part = std::imag(complex_number);   // take the imaginary part of the input
	if( real_part != 0 && imaginary_part != 0 )
    	{
        	if( imaginary_part < 0 )
        	{
            		if(numerical_flag) {
            			std::cout<<real_part<<imaginary_part<<"i"<<"\t";
            		}
            		
            		else { 
		    		DecimalToFraction(real_part);
		    		DecimalToFraction(imaginary_part);
		    		std::cout<<"i"<<"\t";
            		}
        	}

        	else if( imaginary_part > 0 )
        	{
            		if(numerical_flag) {
            			std::cout<<real_part<<"+" <<imaginary_part<<"i"<<"\t";
            		}
            		
            		else {
		    		DecimalToFraction(real_part);
		    		std::cout<<"+";
		    		DecimalToFraction(imaginary_part);
		    		std::cout<<"i"<<"\t";
            		}
        	}
	}
   	else if (imaginary_part == 0 )
    	{   
        	if(numerical_flag) {
        		std::cout<<real_part<<"\t";
        	}
        	
        	else {
			DecimalToFraction(real_part);
			std::cout<<"\t";
        	}
           
    	}
    	else if( real_part == 0 )
    	{
        	if(numerical_flag ){
        		std::cout<<imaginary_part<<"i"<<"\t";
        	}
        	
        	else {
			DecimalToFraction(imaginary_part);
	    		std::cout<<"i"<<"\t";
    		}
    	}    
}
/*
template<class T>
class ComplexQ: public std::complex<T>
{
	public:
		ComplexQ(): std::complex<T>() {}

		void Print()
		{	ComplexQ<T> cmplx = *this;
			ComplexNumPrint(cmplx,0);
			std::cout<<std::endl;
		}

		void NPrint()
		{	ComplexQ<T> cmplx = *this;
			ComplexNumPrint(cmplx,1);
			std::cout<<std::endl;
		}

};
*/
//-----------------------------------------------------------------
//	print complex numbers in symbolic form
//-----------------------------------------------------------------
void ResultPrint(const std::complex<double>& complex_num)
{
	ComplexNumPrint(complex_num,0);
	std::cout<<std::endl;
}
//-----------------------------------------------------------------
//	print complex numbers in numeric form
//-----------------------------------------------------------------
void NResultPrint(const std::complex<double>& complex_num)
{
	ComplexNumPrint(complex_num,1);//cplx_print(complex_num);
	//std::cout<<std::endl;
}

}// end of namespace QuantaPlus
#endif

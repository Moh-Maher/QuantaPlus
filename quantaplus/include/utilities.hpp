/*******************************************************************************************
some of "utilities.h" meathods implementation.

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#pragma once

#ifndef QUANTAPLUS_INCLUDE_UTILITIES_HPP
#define QUANTAPLUS_INCLUDE_UTILITIES_HPP

#ifndef QUANTAPLUS_INCLUDE_UTILITIES_HPP
#error __FILE__ should only be included from quantaplus/utilities.h.
#endif // UTILITIES_H


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


/*! @param mat is an Eigen::Matrix with Dynamic-size rows or columns */
template <typename U>
void ResultPrint(Eigen::Matrix<U,Eigen::Dynamic,Eigen::Dynamic>& mat)
{
	for(int row_count = 0; row_count < mat.rows(); row_count++)
    	{
        	for(int col_count = 0; col_count < mat.cols(); col_count++)
        	{
			ComplexNumPrint( mat(row_count, col_count),0 );
        	}
        	std::cout<<std::endl;
    	}
}
/*!@param mat is an Eigen::Matrix with Dynamic-size rows or columns*/
template <typename U>
void NResultPrint(Eigen::Matrix<U,Eigen::Dynamic,Eigen::Dynamic>& mat)
{
	for(int row_count = 0; row_count < mat.rows(); row_count++)
    	{
        	for(int col_count = 0; col_count < mat.cols(); col_count++)
        	{
			ComplexNumPrint( mat(row_count, col_count),1 );//cplx_print( mat(row_count, col_count) );
        	}
        	std::cout<<std::endl;
    	}
}
////<--------------------------------------------------------------->
template <typename U>
Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> CtoRMateix(Eigen::Matrix<U,Eigen::Dynamic,Eigen::Dynamic>& mat)
{	
	Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> realres((int)mat.rows(),(int)mat.cols());
	for(int row_count = 0; row_count < mat.rows(); row_count++)
    	{
        	for(int col_count = 0; col_count < mat.cols(); col_count++)
        	{
			realres(row_count,col_count)= std::real(mat(row_count, col_count));
        	}
        	 
    	}
    	return realres;
}
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
//--------------------------------------
bool validInteger(const double& x)
{
	return static_cast<int>(x) - x == 0;
}
//--------------------------------------------------------------------------
//	Function to check if the input is a half integer. 
//--------------------------------------------------------------------------
bool halfInteger(const double& x)
{
	return !validInteger(x) && validInteger(2*x);
}
//--------------------------------------------------------------------------
//	Function to print highlighted message.
//-------------------------------------------------------------------------
void Warning(const std::string & str)
{ 
 //std::cout<<FYEL("[")<<FRED("ERROR!:")<<FYEL(<<str<<" ]\n");
	//std::cout<<FYEL("[")<<FYEL(<<str<<" ]\n");
	std::cout<<str<<"\n";
}

 
#endif // UTILITIES_HPP

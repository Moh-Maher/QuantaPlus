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

#ifndef QUANTAPLUS_INCLUDE_UTILITIES_H
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
//--------------------------------------------------------------------------
//	Function to convert decimal to fraction
//--------------------------------------------------------------------------
void DecimalToFraction(const double& decimal_number ) 
{
        //<-------check the sign of the input number to select the sign of the final output.
	int signdec  = decimal_number > 0 ? 1 : -1; 
	std::string plusorminus="";

	if(signdec==-1) {
		plusorminus="-";
	}
	///<------ if the number in not integer and not zero or +1/-1 start the procedure to write it in fraction form 
	if(!validInteger((std::abs(decimal_number))) && decimal_number!=0 && decimal_number!=1.  && decimal_number!=-1. ) 
	{
	 
		double z = decimal_number*decimal_number;
                ///<-- if the square of the number z is an integer, then it can be written as + or - square root of z^2.  
		if(validInteger((z))) 
		{
			std::cout<<plusorminus+"√"<<z;
		}

		else if (!validInteger((z))) ///<-- if the square of the number z is not an integer, proceed to write it as fraction.
		{ 
			int cycles = 10;
			double precision = 5e-4;  
			double number = z;

			int sign  = number > 0 ? 1 : -1; ///<-----check the sign again but for different reason. 
			number = number * sign; ///<-----abs(number);
			double new_number, whole_part;
			double decimal_part =  number - (int)number; ///<---- exclude the integer on the left or the floating point "."
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
                        /*
			double numt = sign * vec_1[0]; ///<-- numerator 
			double dnum = vec_1[1];        ///<-- denominator
			double snumt= sqrt(numt);      ///<-- √(numerator) 
			double sdnum= sqrt(dnum);      ///<-- √(denominator) 
			*/
			if(validInteger((sqrt(sign * vec_1[0]))) && validInteger((sqrt(vec_1[1]))))  ///<--if both numerator and denominator square roots are integers, evaluate them directly. 
			{
				std::cout<<plusorminus<<sqrt(sign * vec_1[0])<<'/'<< sqrt(vec_1[1]);
			} 
			
			///<- square root of denominator not an integer, write "√denominator" explicitly 
			else if(validInteger((sqrt(sign * vec_1[0]))) && (!validInteger((sqrt(vec_1[1])))) )
			{
				std::cout<<plusorminus<<sqrt(sign * vec_1[0])<<'/'<<"√"<< vec_1[1];
			}
			//<- square root of the numerator is not an integer, write "√numerator" explicitly  
			else if( !validInteger((sqrt(sign * vec_1[0]))) && (validInteger((sqrt(vec_1[1])))) )
			{
				std::cout<<plusorminus+"√"<< sign * vec_1[0]<<'/'<< sqrt(vec_1[1]);
			}
			///<- square root of both numerator and denominator not an integer, write "√(numerator/denominator" explicitly
			else 
			std::cout<<plusorminus+"√("<< sign * vec_1[0]<<'/'<< vec_1[1]<<")";
	 
		}
	}

	else std::cout<<decimal_number; ///<------ if the number in an integer or equal 0, 1 or -1, write it directly as it is.
}
/*void DecimalToFraction(const double& decimal_number ) 
{
        //<-------check the sign of the input number to select the sign of the final output.
	int signdec  = decimal_number > 0 ? 1 : -1; 
	std::string plusorminus="";

	if(signdec==-1) {
		plusorminus="-";
	}
	///<------ if the number in not integer and not zero or +1/-1 start the procedure to write it in fraction form 
	if(!IsNumber(ToString(std::abs(decimal_number))) && decimal_number!=0 && decimal_number!=1.  && decimal_number!=-1. ) 
	{
	 
		double z = decimal_number*decimal_number;
                ///<-- if the square of the number z is an integer, then it can be written as + or - square root of z^2.  
		if(IsNumber(ToString(z))) 
		{
			std::cout<<plusorminus+"√"<<z;
		}

		else if (!IsNumber(ToString(z))) ///<-- if the square of the number z is not an integer, proceed to write it as fraction.
		{ 
			int cycles = 10;
			double precision = 5e-4;  
			double number = z;

			int sign  = number > 0 ? 1 : -1; ///<-----check the sign again but for different reason. 
			number = number * sign; ///<-----abs(number);
			double new_number, whole_part;
			double decimal_part =  number - (int)number; ///<---- exclude the integer on the left or the floating point "."
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
                        
			//double numt = sign * vec_1[0]; ///<-- numerator 
			//double dnum = vec_1[1];        ///<-- denominator
			//double snumt= sqrt(numt);      ///<-- √(numerator) 
			//double sdnum= sqrt(dnum);      ///<-- √(denominator) 
			
			if(IsNumber(ToString(sqrt(sign * vec_1[0]))) && IsNumber(ToString(sqrt(vec_1[1]))))  ///<--if both numerator and denominator square roots are integers, evaluate them directly. 
			{
				std::cout<<plusorminus<<sqrt(sign * vec_1[0])<<'/'<< sqrt(vec_1[1]);
			} 
			
			///<- square root of denominator not an integer, write "√denominator" explicitly 
			else if(IsNumber(ToString(sqrt(sign * vec_1[0]))) && (!IsNumber(ToString(sqrt(vec_1[1])))) )
			{
				std::cout<<plusorminus<<sqrt(sign * vec_1[0])<<'/'<<"√"<< vec_1[1];
			}
			//<- square root of the numerator is not an integer, write "√numerator" explicitly  
			else if( !IsNumber(ToString(sqrt(sign * vec_1[0]))) && (IsNumber(ToString(sqrt(vec_1[1])))) )
			{
				std::cout<<plusorminus+"√"<< sign * vec_1[0]<<'/'<< sqrt(vec_1[1]);
			}
			///<- square root of both numerator and denominator not an integer, write "√(numerator/denominator" explicitly
			else 
			std::cout<<plusorminus+"√("<< sign * vec_1[0]<<'/'<< vec_1[1]<<")";
	 
		}
	}

	else std::cout<<decimal_number; ///<------ if the number in an integer or equal 0, 1 or -1, write it directly as it is.
}*/
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
/*bool IsNumber(const std::string& str) 
{
    return str.find_first_not_of( "0123456789" ) == std::string::npos;
}*/
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
 std::cout<<FYEL("[")<<FYEL(<<str<<" ]\n");
}
#endif // UTILITIES_HPP

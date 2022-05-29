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
//#include"utilities.h"

 
//--------------------------------------------------------------------------
// convert latex output
//--------------------------------------------------------------------------
//template <typename T>
//void KetTolaTex(std::string fname, const T &mt,std::string input, bool append)
/*
void KetTolaTex(const char* fmt...)
{	
	std::ofstream outfile;
	std::string output_path ("test.tex"); ///<-- path to the output file and its name.
	va_list args;
	va_start(args, fmt);

	//std::string str[cons];
	//std::string res;
	 
	
	
	//if(append) {outfile.open(output_path,std::ios_base::app);}
	//else outfile.open(output_path);
	outfile.open(output_path);
	outfile<<"\\documentclass[10pt,a4paper]{article}\n";
	outfile<<"\\usepackage[utf8]{inputenc}\n";
	outfile<<"\\usepackage[T1]{fontenc}\n";
	outfile<<"\\usepackage{amsmath}\n";
	outfile<<"\\usepackage{amssymb}\n";
	outfile<<"\\usepackage{graphicx}\n";
	outfile<<"\\usepackage{braket}\n";
	outfile<<"\\usepackage{amsmath}\n";
	outfile<<"\\begin{document}\n";
	
while (*fmt != '\0') 
{       if (*fmt == 'k') {
	ket<std::complex<double>> mt = va_arg(args, ket<std::complex<double>>);
	//if(mt.cols() ==1 && mt.rows()>=1)
	//{
		//outfile<<"$\\ket{"<<input<<"}=$\n";
		outfile<<"\\begin{align}\n";
    		outfile<<"\\ket{ket}&=\\begin{bmatrix}\n";
		for(int i =0; i<mt.rows(); i++)
	    	{
			for(int j =0; j<mt.cols(); j++){
			 
				double x = std::real(mt(i,j));
				double y = std::imag(mt(i,j));   
				if(x!=0 and y!=0) {
					
					if(y<0) {		
		    				outfile<<"$"<<x<<y<<"i$"<<"\\\\";
					}

					else if(y>0) {
		    				outfile<<"$"<<x<<"+"<<y<<"i$"<<"\\\\";
					}
				}
	   			else if(y==0) {   
					outfile<<"$"<<x<<"$"<<"\\\\";
	    			}
	    			else if(x==0){
					outfile<<"$"<<y<<"i$"<<"\\\\";
	    			}   
	    			outfile<<"\n";
	    		}
	    	}
		 	outfile<<"\\end{bmatrix}\n";
	  		outfile<<"\\end{align}\n";
	  		outfile<<"\n";
	//}
	}
	
	else if (*fmt == 'b') {
	bra<std::complex<double>> mt = va_arg(args, bra<std::complex<double>>);
	//if(mt.cols() >= 1 && mt.rows()==1)
	//{ 	
		outfile<<"\\begin{align}\n";
		outfile<<"\\bra{bra}=[\\,\\quad";
		for(int i =0; i<mt.rows(); i++)
	    	{
			for(int j =0; j<mt.cols(); j++) {
			 
			double x = std::real(mt(i,j));
			double y = std::imag(mt(i,j));   
			if(x!=0 and y!=0) {
			
				if(y<0) {
		    			outfile<<x<<y<<"i\\quad";
		    		//outfile<<"$"+ToString(x)+ToString(y)+"i$\t";
				}

				else if(y>0) {
		    			outfile<<x<<"+"<<y<<"i\\quad";
		    		//outfile<<"$"+ToString(x)+"+"+ToString(y)+"i$\t";
				}
			}
	   		else if(y==0) {   
				outfile<<x<<"\\quad";
			//outfile<< "$"+ToString(x)+"$\t";
	    		}
	    		else if(x==0) {
				outfile<<y<<"i\\quad";
			//outfile<< "$"+ToString(y)+"i$\t";
	    		}	   
	    		
	    	}
	    	
	    	}//-------
	    	outfile<<"\\,]\n";
	    	outfile<<"\\end{align}\n";
    	//}
    	}
	else if (*fmt == 'o') {
	QM_operator<std::complex<double>> mt = va_arg(args, QM_operator<std::complex<double>>);
	//if(mt.cols() >= 1 && mt.rows()==1)
	//{ 	

		outfile<<"\\begin{align}\n";
		outfile<<"\\begin{pmatrix}\n";
		//outfile<<"\\bra{bra}=[\\,\\quad";
		for(int i =0; i<mt.rows(); i++)
	    	{
			for(int j =0; j<mt.cols(); j++) {
			 
			double x = std::real(mt(i,j));
			double y = std::imag(mt(i,j));   
			if(x!=0 and y!=0) {
			
				if(y<0) {
		    			outfile<<x<<y<<"i &";
		    		//outfile<<"$"+ToString(x)+ToString(y)+"i$\t";
				}

				else if(y>0) {
		    			outfile<<x<<"+"<<y<<"i &";
		    		//outfile<<"$"+ToString(x)+"+"+ToString(y)+"i$\t";
				}
			}
	   		else if(y==0) {   
				outfile<<x<<"&";
			//outfile<< "$"+ToString(x)+"$\t";
	    		}
	    		else if(x==0) {
				outfile<<y<<"i &";
			//outfile<< "$"+ToString(y)+"i$\t";
	    		}	   
	    	
	    	}
	    		outfile<<"\\\\";
	    	}//-------
	    	
	    	outfile<<"\\end{pmatrix}\n";
	    	outfile<<"\\end{align}\n";
    	//}
    	}
    	++fmt;
}
 	va_end(args);  	
	outfile<<"\n";
	outfile<<"\\end{document}\n";
	outfile.close();

}*/
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

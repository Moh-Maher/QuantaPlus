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
//--------------------------------------------------------------------------
// convert latex output
//--------------------------------------------------------------------------
template <typename T>
void KetTolaTex(std::string fname, const T &mt,std::string input, bool append)
{
	//std::string str[cons];
	std::string res;
	std::ofstream outfile;
	std::string output_path (fname + ".tex"); ///<-- path to the output file and its name.
	
	if(append) {outfile.open(output_path,std::ios_base::app);}
	else outfile.open(output_path);
	outfile<<"\\documentclass[10pt,a4paper]{article}\n";
	outfile<<"\\usepackage[utf8]{inputenc}\n";
	outfile<<"\\usepackage[T1]{fontenc}\n";
	outfile<<"\\usepackage{amsmath}\n";
	outfile<<"\\usepackage{amssymb}\n";
	outfile<<"\\usepackage{graphicx}\n";
	outfile<<"\\usepackage{braket}\n";
	outfile<<"\\begin{document}\n";
	//for(int i=0; i<cons;i++){
	if(mt.cols() ==1) outfile<<"$\\ket{"<<input<<"}=$\n";
	else if(mt.cols() > 1) outfile<<"$\\bra{"<<input<<"}=$\n";
	for(int i =0; i<mt.rows(); i++)
    	{
        	for(int j =0; j<mt.cols(); j++){
        	//for(int i=0; i<cons;i++){ 
	double x = std::real(mt(i,j));
	double y = std::imag(mt(i,j));   
	if(x!=0 and y!=0)
    	{
        	if(y<0)
        	{
            		outfile<<"$"<<x<<y<<"i$"<<"\t";
            		//outfile<<"$"+ToString(x)+ToString(y)+"i$\t";
        	}

        	else if(y>0)
        	{
            		outfile<<"$"<<x<<"+"<<y<<"i$"<<"\t";
            		//outfile<<"$"+ToString(x)+"+"+ToString(y)+"i$\t";
        	}
	}
   	else if(y==0)
    	{   
        	outfile<<"$"<<x<<"$"<<"\t";
        	//outfile<< "$"+ToString(x)+"$\t";
    	}
    	else if(x==0)
    	{
        	outfile<<"$"<<y<<"i$"<<"\t";
        	//outfile<< "$"+ToString(y)+"i$\t";
    	}   
    		std::cout<<std::endl;
    		//outfile<<res;//}
    	}
    	
    	}//-------
    	
   	
   
	
	
	
	/*
	outfile<<"\\documentclass[10pt,a4paper]{article}\n";
	outfile<<"\\usepackage[utf8]{inputenc}\n";
	outfile<<"\\usepackage[T1]{fontenc}\n";
	outfile<<"\\usepackage{amsmath}\n";
	outfile<<"\\usepackage{amssymb}\n";
	outfile<<"\\usepackage{graphicx}\n";
	outfile<<"\\begin{document}\n";
		
	 
	double x = std::real(data);
	double y = std::imag(data);   
	if(x!=0 and y!=0)
    	{
        	if(y<0)
        	{
            		outfile<<"$"<<x<<y<<"i$"<<"\t";
        	}

        	else if(y>0)
        	{
            		outfile<<"$"<<x<<"+"<<y<<"i$"<<"\t";
        	}
	}
   	else if(y==0)
    	{   
        	outfile<<"$"<<x<<"$"<<"\t";
    	}
    	else if(x==0)
    	{
        	outfile<<"$"<<y<<"i$"<<"\t";
    	}    */
	//for(int i=0; i< cons; i++){
	//outfile<<str[i]<<"\\newline\n";
	//}
	outfile<<"\n";
	outfile<<"\\end{document}\n";
	outfile.close();
}
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

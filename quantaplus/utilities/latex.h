/*! \file latex.h
*Generate LaTex files for results output.
*/     
/*------------------------------------------------------------------------------
  by:  	     Mohammed Maher Abdelrahim Mohammed
       	     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
	     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
       	     mohammed.maher@unical.it  
-------------------------------------------------------------------------------*/
//#pragma once
#ifndef QUANTAPLUS_LATEX_H
#define QUANTAPLUS_LATEX_H
#include<iostream>
#include<cmath>
#include<string>
#include <cstdarg> // for Variable arguments handling
#include<map>
#include"../braket/ket.h"
#include"../braket/bra.h"
#include"../operators/operators.h"
#include"utilities.h"

namespace QuantaPlus{
//using namespace QuantaPlus;
/*!
map container holding the "capital/lower" Greek letters and their corresponding escape characters--

 -----A,B,Γ,Δ,Ε,Ζ,Η,Θ,Ι,Κ,Λ,Μ,Ν,Ξ,Ο,Π,Ρ,Σ,Τ,Υ,Φ,Χ,Ψ,Ω----------
-----α,β,γ,δ,ε,ζ,η,θ,ι,κ,λ,μ,ν,ξ,ο,π,ρ,σ,τ,υ,φ,χ,ψ,ω----------
*/
std::map<std::string, std::string> GreekLatters = { 
	{"Alpha","\u0391"}, {"Beta","\u0392"}, {"Gamma","\u0393"},
	{"Delta","\u0394"}, {"Epsilon","\u0395"}, {"Zeta","\u0396"},
	{"Eta","\u0397"}, {"Theta","\u0398"}, {"Iota","\u0399"}, 
	{"Kappa","\u039A"}, {"Lambda","\u039B"}, {"Mu","\u039C"},
	{"Nu","\u039D"}, {"Xi","\u039E"}, {"Omicron","\u039F"},
	{"Pi","\u03A0"}, {"Rho","\u03A1"}, {"Sigma","\u03A3"},
	{"Tau","\u03A4"}, {"Upsilon","\u03A5"}, {"Phi","\u03A6"},
	{"Chi","\u03A7"}, {"Psi","\u03A8"}, {"Omega","\u03A9"}, 
	
	{"_alpha","\u03B1"}, {"beta", "\u03B2"}, {"gamma","\u03B3"},
	{"delta","\u03B4"}, {"epsilon","\u03B5"}, {"zeta", "\u03B6"},
	{"eta","\u03B7"}, {"theta","\u03B8"}, {"iota", "\u03B9"},
	{"kappa","\u03BA"}, {"lambda","\u03BB"}, {"mu", "\u03BC"},
	{"nu", "\u03BD"}, {"xi", "\u03BE"}, {"omicron","\u03BF"},
	{"pi", "\u03C0"}, {"rho","\u03C1"}, {"sigma","\u03C3"},
	{"tau","\u03C4"}, {"upsilon","\u03C5"}, {"phi","\u03C6"},
	{"chi","\u03C7"}, {"psi","\u03C8"}, {"omega","\u03C9"}
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: Greek
  
  Summary:  convert string name of a Greek letter into its 
  	    equivalent Unicode escape characters to print it symbolically .  
             
  Returns:  string
             store the output directly into string variable.
------------------------------------------------------------------------------*/ 
std::string Greek(const std::string& letter_name){
	auto from = GreekLatters.find(letter_name);
	return from->second;
}
/*!********************************************************************************
  \class:    LaTex
  \brief Class to generate LaTex files. 
********************************************************************************/
class LaTex {
	private:
		
		std::ofstream ofile; ///< Output file
		 
		std::string file_path; ///<the output file name including the path 
		
		/*!map container holding string function names and their corresponding laTex math commands*/
		std::map<std::string, std::string> MathFunctions = {
		{"Exp", "\\exp"}, {"Sin", "\\sin"}, {"Cos", "\\cos"}, {"Tan", "\\tan"}, 
		{"Log", "\\log"}, {"Ln", "\\ln"}, {"Lg", "\\lg"}, {"Cot", "\\cot"}, {"Csc", "\\csc"},
		{"Sec", "\\sec"}, {"ASin", "\\arcsin"}, {"ACos", "\\arccos"}, {"ATan", "\\arctan"}, 
		{"Sgn", "\\sgn"}, {"Det", "\\det"}, {"Sqrt", "\\sqrt"} 
		};
	public: 
		/*!\brief Default constructor, with default value for file path/name.tex */			
		LaTex(): file_path("output/default.tex") {}
		
		/*!\brief Constructor, with input value for filename.*/
		LaTex(std::string filename): file_path(filename) {}	
		
		//method for quick start the Latex file settings.
		/*!\brief Set and initiate the LaTex typesetting document class.*/
		void BeginLaTex() 
		{	
			ofile.open(file_path);
			ofile<<"\\documentclass[10pt,a4paper]{article}\n";
			ofile<<"\\usepackage[utf8]{inputenc}\n";
			ofile<<"\\usepackage[T1]{fontenc}\n";
			ofile<<"\\usepackage{amsmath}\n";
			ofile<<"\\usepackage{amssymb}\n";
			ofile<<"\\usepackage{graphicx}\n";
			ofile<<"\\usepackage{braket}\n";
			ofile<<"\\usepackage{amsmath}\n";
			ofile<<"\\begin{document}\n";
			ofile.close();
		}
		/*!\brief close the Latex file document.*/
		void EndLaTex()
		{
			ofile.open(file_path,std::ios_base::app);
			ofile<<"\\end{document}\n";
			ofile.close();
		}
		//Direct typing into the Latex file with appending.
		/*!\brief Method allows us to directly write normal text or even latex commands*/
		void Typing(std::string text)
		{
			ofile.open(file_path,std::ios_base::app);
			ofile<<text;
			ofile.close();
		}
		/*!\brief Function with multiple inputs (equation or text) transformed to latex format.*/
		void ToLaTex(const char* fmt...);
		/*!\brief Function with multiple inputs (equation) transformed to latex format.*/
		void MathOperation(const char* fmt...);
		/*!\brief Convert string name of math function into its equivalent latex command.*/
		std::string LaTexMath(const std::string& function_name);
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: LaTexMathFraction
  
  Summary:   convert decimal_number into fraction form written in string format.
  	     Note: it's a modified version of [utilities.h] "DecimalToFraction" fucntion.
             
  Returns:  string
             store the output directly into string variable.
------------------------------------------------------------------------------*/ 
std::string  LaTexMathFraction(const double& decimal_number) 
{
	int signdec  = decimal_number > 0 ? 1 : -1;
	std::string plusorminus;
	std::string resulted_string;
	if(signdec>0) {
		plusorminus="";
	}
	else if(signdec<0) {
		plusorminus="-";
	}
	
	if(!validInteger(abs(decimal_number)) && decimal_number!=0 && decimal_number!=1.  && decimal_number!=-1. )
	{
	 
		double z = decimal_number*decimal_number;

		if(validInteger(z)) 
		{
			//std::cout<<plusorminus+"\sqrt{"<<z;
			resulted_string =plusorminus+"\\sqrt{"+ToString(z)+"}";
		}

		else if (!validInteger(z)) 
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

			while( (decimal_part > precision) & (counter < cycles) )
			{
				new_number = 1 / decimal_part;
				whole_part = (int) new_number;

				temporary = vec_1;
				vec_1 = whole_part * vec_1 + vec_2;
				vec_2 = temporary;

				decimal_part = new_number - whole_part;
				counter += 1;
			} 
			if(validInteger(sqrt(sign * vec_1[0])) && validInteger(sqrt(vec_1[1])))
			{
				resulted_string =plusorminus+"\\frac{"+ToString(sqrt(sign * vec_1[0]))+"}{"+ToString(sqrt(vec_1[1]))+"}";
			} 

			else if(validInteger(sqrt(sign * vec_1[0])) && (!validInteger(sqrt(vec_1[1]))) )
			{
				resulted_string =plusorminus+"\\frac{"+ToString(sqrt(sign * vec_1[0]))+"}{\\sqrt{"+ToString(vec_1[1])+"}}";
			}
			else if( !validInteger(sqrt(sign * vec_1[0])) && (validInteger(sqrt(vec_1[1]))) )
			{
				resulted_string =plusorminus+"\\frac{\\sqrt{"+ToString(sign * vec_1[0])+"}}{"+ToString(sqrt(vec_1[1]))+"}";
			}
			else 
				resulted_string =plusorminus+"\\sqrt{\\frac{"+ToString(sign * vec_1[0])+"}{"+ToString(sqrt(vec_1[1]))+"}}";
	 
		}
	}

	else resulted_string=ToString(decimal_number);//std::cout<<decimal_number;

return resulted_string;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: RealAndImaginary
  
  Summary:   convert tow double variables into string format, with 
  	     chosen separator string. 
             
  Returns:  string
             store the output directly into string variable.
-------------------------------------------------------------------*/
std::string RealAndImaginary(double x, double y, std::string separator)
{
	std::string resulted_string;
	if(x!=0 and y!=0) {
		
		if(y<0) {		
			if(y==-1){resulted_string = LaTexMathFraction(x)+"-i"+separator;}
			else resulted_string = LaTexMathFraction(x)+LaTexMathFraction(y)+"i"+separator;
		}

		else if(y>0) {
			if(y==1){resulted_string =LaTexMathFraction(x)+"+ i"+separator;}
			else resulted_string = LaTexMathFraction(x)+"+"+LaTexMathFraction(y)+"i"+separator;
		}
	}
	else if(y==0) {   
		resulted_string = LaTexMathFraction(x)+separator;
	}
	else if(x==0){
		if(y==-1){resulted_string ="-i"+separator;}
		else if(y==1){resulted_string =" i"+separator;} 
		else resulted_string = LaTexMathFraction(y)+"i"+separator; 
	}
	return  resulted_string;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: ToLaTex
  
  Summary:   convert multiple inputs into latex format.
  
  Args:     const char* fmt...
              multiple variables with identifier format "fmt".
             
  Returns:  void
              print the output directly to the specified latex file
-------------------------------------------------------------------*/
void LaTex::ToLaTex(const char* fmt...)
{	
	va_list args;
	va_start(args, fmt);
 
	ofile.open(file_path,std::ios_base::app);  ///<--- open the targeted file and appending its contents 
 
	ofile<<"\\begin{align}\n";    ///<-------- latex command to start an equation 
	while (*fmt != '\0') {       ///<-- while there is identifier char: detect its indicating case
		if (*fmt == 'k') { ///<--- ket case indicator 
			
			QuantaPlus::Ket<std::complex<double>> mt = va_arg(args, QuantaPlus::Ket<std::complex<double>>);

	    		ofile<<"\\begin{pmatrix}\n";
			for(int i =0; i<mt.rows(); i++)
		    	{
				for(int j =0; j<mt.cols(); j++)
				{ 
					double x = std::real(mt(i,j));
					double y = std::imag(mt(i,j)); 
					ofile<<RealAndImaginary(x,y,"\\\\");   
		    		}
		    	}
			 	ofile<<"\\end{pmatrix}";
		}
		else if (*fmt == 'b') { ///<--- bra case indicator
			
			QuantaPlus::Bra<std::complex<double>> mt = va_arg(args, QuantaPlus::Bra<std::complex<double>>);

			ofile<<"\\begin{pmatrix}\n";
			for(int i =0; i<mt.rows(); i++)
		    	{
				for(int j =0; j<mt.cols(); j++)
				{
					double x = std::real(mt(i,j));
					double y = std::imag(mt(i,j));
					ofile<<RealAndImaginary(x,y,"\\quad");   	   		    		
		    		}
		    	
		    	}
		    	ofile<<"\\end{pmatrix}"; 
	    	}
		else if (*fmt == 'o') { ///<--- operator case indicator
			
			QuantaPlus::QM_operator<std::complex<double>> mt = va_arg(args, QuantaPlus::QM_operator<std::complex<double>>);
 
			ofile<<"\\begin{pmatrix}\n";
			for(int i =0; i<mt.rows(); i++)
		    	{
				for(int j =0; j<mt.cols(); j++)
				{				
					double x = std::real(mt(i,j));
					double y = std::imag(mt(i,j));
					ofile<<RealAndImaginary(x,y," &");   	   
		    		}
		    		ofile<<"\\\\";
		    	} 
		    	ofile<<"\\end{pmatrix}";
	    	}
	    	else if (*fmt == 't') { ///<--- text case indicator
	    		char* s = va_arg( args, char * );
            		ofile << s;
	    	}
	    	++fmt;
	}
 	va_end(args);  	
	ofile<<"\n";
	ofile<<"\\end{align}\n"; ///<-------- latex command to end an equation 
	ofile.close();
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: MathOperation
  
  Summary:   convert multiple mathematical operations into latex equations.
  
  Args:     const char* fmt...
              multiple variables with identifier format "fmt".
             
  Returns:  void
              print the output directly to the specified latex file
---------------------------------------------------------------------------------------*/
void LaTex::MathOperation(const char* fmt...)
{	
	va_list args;
	va_start(args, fmt); 
	
	ofile.open(file_path,std::ios_base::app);
	
	ofile<<"\\begin{align}\n";
	while (*fmt != '\0') {       
		if (*fmt == 'k') { ///<--- ket case indicator
			
			QuantaPlus::Ket<std::complex<double>> mt = va_arg(args, QuantaPlus::Ket<std::complex<double>>);
			
	    		ofile<<"\\begin{pmatrix}\n";
			for(int i =0; i<mt.rows(); i++)
		    	{
				for(int j =0; j<mt.cols(); j++) 
				{				 
					double x = std::real(mt(i,j));
					double y = std::imag(mt(i,j)); 
					ofile<<RealAndImaginary(x,y,"\\\\");     
		    			ofile<<"\n";
		    		}
		    	}
			 	ofile<<"\\end{pmatrix}";	 
		}
		else if (*fmt == 'b') {///<--- bra case indicator
			
			QuantaPlus::Bra<std::complex<double>> mt = va_arg(args, QuantaPlus::Bra<std::complex<double>>);
			ofile<<"\\begin{pmatrix}\n";
			
			for(int i =0; i<mt.rows(); i++)
		    	{
				for(int j =0; j<mt.cols(); j++) 
				{
					double x = std::real(mt(i,j));
					double y = std::imag(mt(i,j));
					ofile<<RealAndImaginary(x,y,"\\quad");  	   		    		
		    		}
		    	
		    	}
		    	ofile<<"\\end{pmatrix}";
	    	}
		else if (*fmt == 'o') { ///<--- operator case indicator
			
			QuantaPlus::QM_operator<std::complex<double>> mt = va_arg(args, QuantaPlus::QM_operator<std::complex<double>>);
			ofile<<"\\begin{pmatrix}\n";
			for(int i =0; i<mt.rows(); i++)
		    	{
				for(int j =0; j<mt.cols(); j++) 
				{
					double x = std::real(mt(i,j));
					double y = std::imag(mt(i,j));
					ofile<<RealAndImaginary(x,y,"&");  
		    		}
		    		ofile<<"\\\\";
		    	} 
		    	ofile<<"\\end{pmatrix}";
		    	
	    	}
	    	else if (*fmt == 'n') { ///<--- complex number case indicator
			std::complex<double> c = va_arg(args, std::complex<double>);
    			double x = std::real(c);
			double y = std::imag(c); 
			ofile<<RealAndImaginary(x,y," &");  
	    	}
	    	
	    	else if (*fmt == '=') { ///<--- equal sign case indicator
    			int c = va_arg(args, int);
            		ofile << static_cast<char>(c);
	    	}
	    		else if (*fmt == 't') { ///<--- text case indicator
	    		char* s = va_arg( args, char * );
            		ofile << s;
	    	}
	    	
	    	++fmt;
	}
 	va_end(args);  	
	ofile<<"\\end{align}\n";
	ofile<<"\n";
	ofile.close();
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: LaTexMath
  
  Summary:  convert string name of math function into its 
  	    equivalent latex command .  
             
  Returns:  string
             store the output directly into string variable.
------------------------------------------------------------------------------*/ 
std::string LaTex::LaTexMath(const std::string& function_name){
	auto from = MathFunctions.find(function_name);
	return from->second;
}
} //end of QuantaPlus namespace
#endif

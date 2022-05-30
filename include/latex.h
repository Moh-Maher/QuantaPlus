/*=================================================================================
 generate LaTex files for results output 

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
=================================================================================*/
//#pragma once
#ifndef QUANTAPLUS_INCLUDE_LATEX_H
#define QUANTAPLUS_INCLUDE_LATEX_H
#include<iostream>
#include<cmath>
#include"utilities.h"
/*********************************************************************************
  Class:    LaTex.

  Summary:  generate LaTex files. 

  Methods:  BeginLaTex()
              set and initiate the LaTex typesetting file document class.
            
            EndLaTex()
              end the LaTex typesetting file document class.
            
            Typing()
              allows to directly write normal text or even latex commands 
            
            ToLaTex()
              transform multiple input into latex format.
            
            MathOperation()
              transform multiple mathematical operations into latex equations.
            
            LaTex()
              Constructor.
            
            LaTex(std::string filename)
              Copy Constructor.
            
            ~LaTex()
              Destructor.
********************************************************************************/
class LaTex {
	private:
		std::ofstream ofile;
		std::string file_path;
	public: 				
		LaTex(): file_path("output/default.tex") {}
		LaTex(std::string filename): file_path(filename) {}	
		
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
	
		void EndLaTex()
		{
			ofile.open(file_path,std::ios_base::app);
			ofile<<"\\end{document}\n";
			ofile.close();
		}

		void Typing(std::string text)
		{
			ofile.open(file_path,std::ios_base::app);
			ofile<<text;
			ofile.close();
		}
		
		void ToLaTex(const char* fmt...);
		void MathOperation(const char* fmt...);
};
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
			resulted_string = ToString(x)+ToString(y)+"i"+separator;
		}

		else if(y>0) {
			resulted_string = ToString(x)+"+"+ToString(y)+"i"+separator;
		}
	}
	else if(y==0) {   
		resulted_string = ToString(x)+separator; 
	}
	else if(x==0){
		resulted_string = ToString(y)+"i"+separator; 
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
			
			Ket<std::complex<double>> mt = va_arg(args, Ket<std::complex<double>>);

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
			
			Bra<std::complex<double>> mt = va_arg(args, Bra<std::complex<double>>);

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
			
			QM_operator<std::complex<double>> mt = va_arg(args, QM_operator<std::complex<double>>);
 
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
			
			Ket<std::complex<double>> mt = va_arg(args, Ket<std::complex<double>>);
			
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
			
			Bra<std::complex<double>> mt = va_arg(args, Bra<std::complex<double>>);
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
			
			QM_operator<std::complex<double>> mt = va_arg(args, QM_operator<std::complex<double>>);
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
#endif

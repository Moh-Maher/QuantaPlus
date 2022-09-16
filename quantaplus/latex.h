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
#include<map>
#include"braket.h"
#include"operators.h"
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
#include"include/latex.hpp"
} //end of QuantaPlus namespace
#endif

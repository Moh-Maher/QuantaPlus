/*******************************************************************************************
 generate latex files for results output 

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#pragma once
#include<iostream>
#include<cmath>


class latex {
	public:
		std::ofstream ofile;
		std::string file_path;
		
		latex(): file_path("output/default.tex") {}
		
		latex(std::string filename): file_path(filename) {}
	
		void begin() 
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
	
		void end()
		{
			ofile.open(file_path,std::ios_base::app);
			ofile<<"\\end{document}\n";
			ofile.close();
		}

		void typing(std::string text)
		{
			ofile.open(file_path,std::ios_base::app);
			ofile<<text;
			ofile.close();
		}
};


//=================================================================================
std::ofstream outfile, myfile;
std::string output_path ("output/latex_results.tex"); ///<-- path to the output file and its name.
//std::string filename;

void begin()
{
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
	outfile.close();

}
void end()
{
outfile.open(output_path,std::ios_base::app);
outfile<<"\\end{document}\n";
outfile.close();

}
//=================================================================================
//--------------------------------------------------------------------------
// convert latex output
//--------------------------------------------------------------------------
void TolaTex(const char* fmt...)
{	
	//std::ofstream outfile;
	//std::string output_path ("output/latex_results.tex"); ///<-- path to the output file and its name.
	va_list args;
	va_start(args, fmt);
 
	outfile.open(output_path,std::ios_base::app);
	/*
	outfile<<"\\documentclass[10pt,a4paper]{article}\n";
	outfile<<"\\usepackage[utf8]{inputenc}\n";
	outfile<<"\\usepackage[T1]{fontenc}\n";
	outfile<<"\\usepackage{amsmath}\n";
	outfile<<"\\usepackage{amssymb}\n";
	outfile<<"\\usepackage{graphicx}\n";
	outfile<<"\\usepackage{braket}\n";
	outfile<<"\\usepackage{amsmath}\n";
	*/
	//outfile<<"\\begin{document}\n";
	outfile<<"\\begin{align}\n";
	while (*fmt != '\0') {       
		if (*fmt == 'k') {
			
			ket<std::complex<double>> mt = va_arg(args, ket<std::complex<double>>);
			//outfile<<"\\begin{align}\n";
	    		outfile<<"\\begin{pmatrix}\n";
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
		    			//outfile<<"\n";
		    		}
		    	}
			 	outfile<<"\\end{pmatrix}";
		  		//outfile<<"\\end{align}\n";
		  		outfile<<"\n";
		}
		else if (*fmt == 'b') {
			
			bra<std::complex<double>> mt = va_arg(args, bra<std::complex<double>>);
 
			//outfile<<"\\begin{align}\n";
			outfile<<"\\begin{pmatrix}\n";
			for(int i =0; i<mt.rows(); i++)
		    	{
				for(int j =0; j<mt.cols(); j++) {
				 
					double x = std::real(mt(i,j));
					double y = std::imag(mt(i,j));   
					if(x!=0 and y!=0) {
					
						if(y<0) {
				    			outfile<<x<<y<<"i\\quad";
						}

						else if(y>0) {
				    			outfile<<x<<"+"<<y<<"i\\quad";	 
						}
					}
			   		else if(y==0) {   
						outfile<<x<<"\\quad";	 
			    		}
			    		else if(x==0) {
						outfile<<y<<"i\\quad";	 
			    		}	   		    		
		    		}
		    	
		    	}
		    	//outfile<<"\\,]";
		    	outfile<<"\\end{pmatrix}";
		    	//outfile<<"\\end{align}\n";
	    	}
		else if (*fmt == 'o') {
			
			QM_operator<std::complex<double>> mt = va_arg(args, QM_operator<std::complex<double>>);
			//outfile<<"\\begin{align}\n";
			outfile<<"\\begin{pmatrix}\n";
			for(int i =0; i<mt.rows(); i++)
		    	{
				for(int j =0; j<mt.cols(); j++) {
				
					double x = std::real(mt(i,j));
					double y = std::imag(mt(i,j));   
					if(x!=0 and y!=0) {
					
						if(y<0) {
				    			outfile<<x<<y<<"i &";
						}

						else if(y>0) {
				    			outfile<<x<<"+"<<y<<"i &";
						}
					}
			   		else if(y==0) {   
						outfile<<x<<"&";
		 
			    		}
			    		else if(x==0) {
						outfile<<y<<"i &";
			    		}	   
		    		}
		    		outfile<<"\\\\";
		    	} 
		    	outfile<<"\\end{pmatrix}";
		    	//outfile<<"\\end{align}\n";
	    	}
	    	else if (*fmt == 't') {
	    		char* s = va_arg( args, char * );
            		outfile << s;
	    	}
	    	++fmt;
	}
 	va_end(args);  	
	outfile<<"\n";
	outfile<<"\\end{align}\n";
	//outfile<<"\\end{document}\n";
	outfile.close();

}

//--------------------------------------------------------------------------
// convert latex output operations
//--------------------------------------------------------------------------
void operation(const char* fmt...)
{	
	//std::ofstream outfile;
	//std::string output_path ("output/latex_results.tex"); ///<-- path to the output file and its name.
	va_list args;
	va_start(args, fmt);
 
	outfile.open(output_path,std::ios_base::app);
	/*
	outfile<<"\\documentclass[10pt,a4paper]{article}\n";
	outfile<<"\\usepackage[utf8]{inputenc}\n";
	outfile<<"\\usepackage[T1]{fontenc}\n";
	outfile<<"\\usepackage{amsmath}\n";
	outfile<<"\\usepackage{amssymb}\n";
	outfile<<"\\usepackage{graphicx}\n";
	outfile<<"\\usepackage{braket}\n";
	outfile<<"\\usepackage{amsmath}\n";
	*/
	//outfile<<"\\begin{document}\n";
	
	outfile<<"\\begin{align}\n";
	while (*fmt != '\0') {       
		if (*fmt == 'k') {
			
			ket<std::complex<double>> mt = va_arg(args, ket<std::complex<double>>);
			
	    		outfile<<"\\begin{pmatrix}\n";
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
			 	outfile<<"\\end{pmatrix}";
		  		 
		}
		else if (*fmt == 'b') {
			
			bra<std::complex<double>> mt = va_arg(args, bra<std::complex<double>>);
 
			//outfile<<"[\\,\\quad";
			outfile<<"\\begin{pmatrix}\n";
			for(int i =0; i<mt.rows(); i++)
		    	{
				for(int j =0; j<mt.cols(); j++) {
				 
					double x = std::real(mt(i,j));
					double y = std::imag(mt(i,j));   
					if(x!=0 and y!=0) {
					
						if(y<0) {
				    			outfile<<x<<y<<"i\\quad";
						}

						else if(y>0) {
				    			outfile<<x<<"+"<<y<<"i\\quad";	 
						}
					}
			   		else if(y==0) {   
						outfile<<x<<"\\quad";	 
			    		}
			    		else if(x==0) {
						outfile<<y<<"i\\quad";	 
			    		}	   		    		
		    		}
		    	
		    	}
		    	//outfile<<"\\,]";
		    	outfile<<"\\end{pmatrix}";
	    	}
		else if (*fmt == 'o') {
			
			QM_operator<std::complex<double>> mt = va_arg(args, QM_operator<std::complex<double>>);
			outfile<<"\\begin{pmatrix}\n";
			for(int i =0; i<mt.rows(); i++)
		    	{
				for(int j =0; j<mt.cols(); j++) {
				
					double x = std::real(mt(i,j));
					double y = std::imag(mt(i,j));   
					if(x!=0 and y!=0) {
					
						if(y<0) {
				    			outfile<<x<<y<<"i &";
						}

						else if(y>0) {
				    			outfile<<x<<"+"<<y<<"i &";
						}
					}
			   		else if(y==0) {   
						outfile<<x<<"&";
		 
			    		}
			    		else if(x==0) {
						outfile<<y<<"i &";
			    		}	   
		    		}
		    		outfile<<"\\\\";
		    	} 
		    	outfile<<"\\end{pmatrix}";
		    	
	    	}
	    	else if (*fmt == '=') {
	    		int c = va_arg(args, int);
            		outfile << static_cast<char>(c);
	    	}
	    		else if (*fmt == 't') {
	    		char* s = va_arg( args, char * );
            		outfile << s;
	    	}
	    	
	    	++fmt;
	}
 	va_end(args);  	
	outfile<<"\\end{align}\n";
	outfile<<"\n";
	//outfile<<"\\end{document}\n";
	outfile.close();

}

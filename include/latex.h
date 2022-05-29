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
	private:
		std::ofstream ofile;
		std::string file_path;

	public: 
				
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
		void TolaTex(const char* fmt...);
		void operation(const char* fmt...);
};
//=================================================================================
//--------------------------------------------------------------------------
// convert latex output
//--------------------------------------------------------------------------
void latex::TolaTex(const char* fmt...)
{	
	va_list args;
	va_start(args, fmt);
 
	ofile.open(file_path,std::ios_base::app);
 
	ofile<<"\\begin{align}\n";
	while (*fmt != '\0') {       
		if (*fmt == 'k') {
			
			ket<std::complex<double>> mt = va_arg(args, ket<std::complex<double>>);

	    		ofile<<"\\begin{pmatrix}\n";
			for(int i =0; i<mt.rows(); i++)
		    	{
				for(int j =0; j<mt.cols(); j++){
				 
					double x = std::real(mt(i,j));
					double y = std::imag(mt(i,j));   
					if(x!=0 and y!=0) {
						
						if(y<0) {		
			    				ofile<<"$"<<x<<y<<"i$"<<"\\\\";
						}

						else if(y>0) {
			    				ofile<<"$"<<x<<"+"<<y<<"i$"<<"\\\\";
						}
					}
		   			else if(y==0) {   
						ofile<<"$"<<x<<"$"<<"\\\\";
		    			}
		    			else if(x==0){
						ofile<<"$"<<y<<"i$"<<"\\\\";
		    			}   
		    		}
		    	}
			 	ofile<<"\\end{pmatrix}";
		  		ofile<<"\n";
		}
		else if (*fmt == 'b') {
			
			bra<std::complex<double>> mt = va_arg(args, bra<std::complex<double>>);

			ofile<<"\\begin{pmatrix}\n";
			for(int i =0; i<mt.rows(); i++)
		    	{
				for(int j =0; j<mt.cols(); j++) {
				 
					double x = std::real(mt(i,j));
					double y = std::imag(mt(i,j));   
					if(x!=0 and y!=0) {
					
						if(y<0) {
				    			ofile<<x<<y<<"i\\quad";
						}

						else if(y>0) {
				    			ofile<<x<<"+"<<y<<"i\\quad";	 
						}
					}
			   		else if(y==0) {   
						ofile<<x<<"\\quad";	 
			    		}
			    		else if(x==0) {
						ofile<<y<<"i\\quad";	 
			    		}	   		    		
		    		}
		    	
		    	}
		    	ofile<<"\\end{pmatrix}";
	    	}
		else if (*fmt == 'o') {
			
			QM_operator<std::complex<double>> mt = va_arg(args, QM_operator<std::complex<double>>);
 
			ofile<<"\\begin{pmatrix}\n";
			for(int i =0; i<mt.rows(); i++)
		    	{
				for(int j =0; j<mt.cols(); j++) {
				
					double x = std::real(mt(i,j));
					double y = std::imag(mt(i,j));   
					if(x!=0 and y!=0) {
					
						if(y<0) {
				    			ofile<<x<<y<<"i &";
						}

						else if(y>0) {
				    			ofile<<x<<"+"<<y<<"i &";
						}
					}
			   		else if(y==0) {   
						ofile<<x<<"&";
		 
			    		}
			    		else if(x==0) {
						ofile<<y<<"i &";
			    		}	   
		    		}
		    		ofile<<"\\\\";
		    	} 
		    	ofile<<"\\end{pmatrix}";
	    	}
	    	else if (*fmt == 't') {
	    		char* s = va_arg( args, char * );
            		ofile << s;
	    	}
	    	++fmt;
	}
 	va_end(args);  	
	ofile<<"\n";
	ofile<<"\\end{align}\n";
	ofile.close();
}

//--------------------------------------------------------------------------
// convert latex output operations
//--------------------------------------------------------------------------
void latex::operation(const char* fmt...)
{	
	va_list args;
	va_start(args, fmt); 
	
	ofile.open(file_path,std::ios_base::app);
	
	ofile<<"\\begin{align}\n";
	while (*fmt != '\0') {       
		if (*fmt == 'k') {
			
			ket<std::complex<double>> mt = va_arg(args, ket<std::complex<double>>);
			
	    		ofile<<"\\begin{pmatrix}\n";
			for(int i =0; i<mt.rows(); i++)
		    	{
				for(int j =0; j<mt.cols(); j++){
				 
					double x = std::real(mt(i,j));
					double y = std::imag(mt(i,j));   
					if(x!=0 and y!=0) {
						
						if(y<0) {		
			    				ofile<<"$"<<x<<y<<"i$"<<"\\\\";
						}

						else if(y>0) {
			    				ofile<<"$"<<x<<"+"<<y<<"i$"<<"\\\\";
						}
					}
		   			else if(y==0) {   
						ofile<<"$"<<x<<"$"<<"\\\\";
		    			}
		    			else if(x==0){
						ofile<<"$"<<y<<"i$"<<"\\\\";
		    			}   
		    			ofile<<"\n";
		    		}
		    	}
			 	ofile<<"\\end{pmatrix}";
		  		 
		}
		else if (*fmt == 'b') {
			
			bra<std::complex<double>> mt = va_arg(args, bra<std::complex<double>>);
 
			//ofile<<"[\\,\\quad";
			ofile<<"\\begin{pmatrix}\n";
			for(int i =0; i<mt.rows(); i++)
		    	{
				for(int j =0; j<mt.cols(); j++) {
				 
					double x = std::real(mt(i,j));
					double y = std::imag(mt(i,j));   
					if(x!=0 and y!=0) {
					
						if(y<0) {
				    			ofile<<x<<y<<"i\\quad";
						}

						else if(y>0) {
				    			ofile<<x<<"+"<<y<<"i\\quad";	 
						}
					}
			   		else if(y==0) {   
						ofile<<x<<"\\quad";	 
			    		}
			    		else if(x==0) {
						ofile<<y<<"i\\quad";	 
			    		}	   		    		
		    		}
		    	
		    	}
		    	//ofile<<"\\,]";
		    	ofile<<"\\end{pmatrix}";
	    	}
		else if (*fmt == 'o') {
			
			QM_operator<std::complex<double>> mt = va_arg(args, QM_operator<std::complex<double>>);
			ofile<<"\\begin{pmatrix}\n";
			for(int i =0; i<mt.rows(); i++)
		    	{
				for(int j =0; j<mt.cols(); j++) {
				
					double x = std::real(mt(i,j));
					double y = std::imag(mt(i,j));   
					if(x!=0 and y!=0) {
					
						if(y<0) {
				    			ofile<<x<<y<<"i &";
						}

						else if(y>0) {
				    			ofile<<x<<"+"<<y<<"i &";
						}
					}
			   		else if(y==0) {   
						ofile<<x<<"&";
		 
			    		}
			    		else if(x==0) {
						ofile<<y<<"i &";
			    		}	   
		    		}
		    		ofile<<"\\\\";
		    	} 
		    	ofile<<"\\end{pmatrix}";
		    	
	    	}
	    	else if (*fmt == 'n') {
			std::complex<double> c = va_arg(args, std::complex<double>);
    			double x = std::real(c);
			double y = std::imag(c);   
			if(x!=0 and y!=0) {
			
				if(y<0) {
		    			ofile<<x<<y<<"i &";
				}

				else if(y>0) {
		    			ofile<<x<<"+"<<y<<"i &";
				}
			}
	   		else if(y==0) {   
				ofile<<x<<"&";
 
	    		}
	    		else if(x==0) {
				ofile<<y<<"i &";
	    		}
	    	}
	    	
	    	
	    	else if (*fmt == '=') {
    			int c = va_arg(args, int);
            		ofile << static_cast<char>(c);
	    	}
	    		else if (*fmt == 't') {
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

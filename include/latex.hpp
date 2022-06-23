#pragma once
#ifndef QUANTAPLUS_INCLUDE_LATEX_H
#define QUANTAPLUS_INCLUDE_LATEX_H

#ifndef QUANTAPLUS_INCLUDE_LATEX_H
#error __FILE__ should only be included from latex.h.
#endif // OPERATORS_H

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: Explicit
  
  Summary:   convert decimal_number into fraction form written in string format.
  	     Note: it's a modified version of [utilities.h] "DecimalToFraction" fucntion.
             
  Returns:  string
             store the output directly into string variable.
------------------------------------------------------------------------------*/ 
std::string Explicit(const double& decimal_number) 
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
	
	if(!IsNumber(ToString(std::abs(decimal_number))) && decimal_number!=0 && decimal_number!=1.  && decimal_number!=-1. )
	{
	 
		double z = decimal_number*decimal_number;

		if(IsNumber(ToString(z))) 
		{
			//std::cout<<plusorminus+"\sqrt{"<<z;
			resulted_string =plusorminus+"\\sqrt{"+ToString(z)+"}";
		}

		else if (!IsNumber(ToString(z))) 
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

			double numt = sign * vec_1[0];
			double dnum = vec_1[1];
			double snumt= sqrt(numt);
			double sdnum= sqrt(dnum);
 
			if(IsNumber(ToString(snumt)) && IsNumber(ToString(sdnum)))
			{
				//std::cout<<plusorminus<<snumt<<'/'<< sdnum;
				resulted_string =plusorminus+"\\frac{"+ToString(snumt)+"}{"+ToString(sdnum)+"}";
			} 

			else if(IsNumber(ToString(snumt)) && (!IsNumber(ToString(sdnum))) )
			{
				//std::cout<<plusorminus<<snumt<<'/'<<"\sqrt{"<< vec_1[1];
				resulted_string =plusorminus+"\\frac{"+ToString(snumt)+"}{\\sqrt{"+ToString(vec_1[1])+"}}";
			}
			else if( !IsNumber(ToString(snumt)) && (IsNumber(ToString(sdnum))) )
			{
				//std::cout<<plusorminus+"\sqrt{"<< sign * vec_1[0]<<'/'<< sdnum;
				resulted_string =plusorminus+"\\frac{\\sqrt{"+ToString(sign * vec_1[0])+"}}{"+ToString(sdnum)+"}";
			}
			else 
			//std::cout<<plusorminus+"\sqrt{("<< sign * vec_1[0]<<'/'<< vec_1[1]<<")";
				resulted_string =plusorminus+"\\sqrt{\\frac{"+ToString(sign * vec_1[0])+"}{"+ToString(sdnum)+"}}";
	 
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
			//resulted_string = ToString(x)+ToString(y)+"i"+separator;
			if(y==-1){resulted_string = Explicit(x)+"-i"+separator;}
			else resulted_string = Explicit(x)+Explicit(y)+"i"+separator;
		}

		else if(y>0) {
			//resulted_string = ToString(x)+"+"+ToString(y)+"i"+separator;
			if(y==1){resulted_string =Explicit(x)+"+ i"+separator;}
			else resulted_string = Explicit(x)+"+"+Explicit(y)+"i"+separator;
		}
	}
	else if(y==0) {   
		//resulted_string = ToString(x)+separator; 
		resulted_string = Explicit(x)+separator;
	}
	else if(x==0){
		//resulted_string = ToString(y)+"i"+separator;
		if(y==-1){resulted_string ="-i"+separator;}
		else if(y==1){resulted_string =" i"+separator;} 
		else resulted_string = Explicit(y)+"i"+separator; 
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
#endif
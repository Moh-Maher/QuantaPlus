/*! \file cgc.h is a part of QUANTAPLUS library. 
* Calculation of the Clebsch–Gordan Coefficients Generalized power series representations.
* For more details see:
<a href="https://functions.wolfram.com/HypergeometricFunctions/ClebschGordan/06/01/" >functions.wolfram</a>          
*/
/*-----------------------------------------------------------------------
by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it 
----------------------------------------------------------------------*/
#pragma once
#ifndef QUANTAPLUS_OPERATORS_CLEBSCHGORDON_H
#define QUANTAPLUS_OPERATORS_CLEBSCHGORDON_H
//#include<iostream>
#include<limits>
#include<cmath>
#include<complex>
#include<vector>
#include<map>
#include<stdexcept>
#include"angularmomentum.h"

namespace QuantaPlus {

/*!******************************************************************************************************
* \class CGCcoeff
* \brief CGCcoeff is a class for Clebsch–Gordan Coefficients representation \f$<j_1, j_2; m_1, m_2 | j, m >\f$.
*
* Note that the coefficients \f$<j_1, j_2; m_1, m_2 | j, m >\f$ = 0. unless \f$m1+m2=m\f$.
********************************************************************************************************/
class CGCcoeff {
	public:
		double j1=0; ///< the the first particle angular momentum (spin or orbital). 
		double j2=0; ///< the angular momentum (spin or orbital) of the second particle.
		double m1=0; ///< magnetic quantum number of the first particle (or system) 
		double m2=0; ///< magnetic quantum number of the second particle (or system) 
		double j=0; ///< total angular momentum: \f$|j1 - j2| <= j <= |j1 + j2|\f$
		double m=0; ///< total \f$m\f$ located within the rang \f$-j<m<j\f$
		 
		CGCcoeff() = default; ///< Defaulte constructor
		
		CGCcoeff(double J1, double J2, double M1, double M2, double J, double M)
		:j1(J1),j2(J2),m1(M1),m2(M2),j(J),m(M)
		{ 
		 //j1 = J1; j2 = J2; m1 = M1; m2 = M2; j = J; m = M;
		} ///<constructor with input 
		
		CGCcoeff(double J, double M):j(J),m(M){} ///< overloaded constructor with input 
		 
		CGCcoeff(double J1, double J2,double J, double M)
		:j1(J1),j2(J2),j(J),m(M){} ///< overloaded constructor with input 
		 
		CGCcoeff(const CGCcoeff& gc){
			j1 = gc.j1; j2 = gc.j2; m1 = gc.m1; m2 = gc.m2; j = gc.j; m = gc.m;
		} ///< overloaded constructor with input 

	        /*!overloading operator "<". required to be used in a std::map*/
		inline bool operator<(const CGCcoeff &rhs) const {
			if( j1 < rhs.j1 ) return true;
			if( j1 > rhs.j1 ) return false;
			if( j2 < rhs.j2 ) return true;
			if( j2 > rhs.j2 ) return false;
			if( m1 < rhs.m1 ) return true;
			if( m1 > rhs.m1 ) return false;
			if( m2 < rhs.m2 ) return true;
			if( m2 > rhs.m2 ) return false;
			if( j  < rhs.j  ) return true;
			if( j  > rhs.j  ) return false;
			return ( m  < rhs.m  );
		}
		/*! Overloading the logical "==" operator*/ 
		bool operator ==(const CGCcoeff& CG){
			
			bool res = false;
			if(j==CG.j && m == CG.m){res = true;}
			return res;
		}
};
/*! Overloaded "<<" operator*/
inline std::ostream& operator <<(std::ostream& out, const CGCcoeff& t){
	out<<"|";DecimalToFraction(t.j1);
	out<<", ";
	DecimalToFraction(t.j2);
	out<<"; ";
	DecimalToFraction(t.m1);
	out<<", ";
	DecimalToFraction(t.m2);
	out<<" >";
 
	return out;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: SquareRoot  

  Summary: gives the given current value if  it's equivalent to given previous one, else it
  will recursively call it self. 
  	    
  Args: const double& x
  		
  	const double& curr
  		
  	const double& prev  
  		  
  Returns:  double
------------------------------------------------------------------*/
double SquareRoot(const double& x, const double& curr, const double& prev)
{
        return curr == prev
               ? curr
               : SquareRoot(x, 0.5 * (curr + x / curr), curr);
}
//-------------- overloaded SquareRoot ---------------------------
double SquareRoot(const double& x)
{
	return x >= 0 && x < std::numeric_limits<double>::infinity()
               ? SquareRoot(x, x, 0)
               : std::numeric_limits<double>::quiet_NaN();
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: Factorial 

  Summary:  Factorial of an positive integer.  
  	    
  Args:  const std::size_t& n
  		 positive integer.     
  	      
  Returns: std::size_t
  		large integer.
------------------------------------------------------------------*/
/*std::size_t Factorial(const std::size_t& n)
{
        return n == 0? 1 : n * Factorial(n-1);
}*/
// -------------------overloaded Factorial -----------------------
double Factorial(const double& n)
{
        return n == 0? 1 : n * Factorial(n-1);
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: FracFactorial 

  Summary:  Factorial of fractional numbers (using gamma functions) 
  	    
  Args: const double& n
  		fractional number     
  	      
  Returns:  double
------------------------------------------------------------------*/
double FracFactorial(const double& n)
{  
	return tgamma(n+1.);
}

/*!  
* Calculate Clebsch–Gordan Coefficients using the Generalized power series representations. 
*/
double ClebschGordan(const double& j1, const double& j2, const double& m1, const double& m2, const double& J, const double& M){
	if( !validAngularMomentum(j1) || !validAngularMomentum(m1) || !validAngularMomentum(j2) || !validAngularMomentum(m2) || !validAngularMomentum(J) ){
		throw std::domain_error("clebsch_gordan: all parameters must be multiples of 0.5.");
	}
	if( (validInteger(j1) && halfInteger(m1)) || (halfInteger(j1) && validInteger(m1)) ){
		throw std::domain_error("clebsch_gordan: j1 and m1 must both be integral or half integral.");
	}
	if( (validInteger(j2) && halfInteger(m2)) || (halfInteger(j2) && validInteger(m2)) ){
		throw std::domain_error("clebsch_gordan: j2 and m2 must both be integral or half integral.");
	}
	if( (validInteger(j1 + j2) && !validInteger(J)) || (halfInteger(j1 + j2) && !halfInteger(J)) ){
		throw std::domain_error("clebsch_gordan: J is no valid value for j1 and j2 combination.");
	}
	if( j1 < 0 || j2 < 0 ){
		throw std::domain_error("clebsch_gordan: j1 and j2 must be non-negative.");
	}
	if( J > j1 + j2 || J < abs(j1 - j2) ){
		throw std::domain_error("clebsch_gordan: J must be |j1-j2| <= J <= j1+j2.");
	}
	if( abs(m1) > j1 || abs(m2) > j2 || abs(M) > J ){
		throw std::domain_error("clebsch_gordan: m1 and m2 must be |m1| <= j1 and |m2| <= j2 and |m1+m2| <= J");
	}
	if( m1 + m2 != M ){
		throw std::domain_error("clebsch_gordan: m1 + m2 != M.");
	} 

	//auto const & f = Factorial;
	double numerator = (2 * J + 1) * Factorial(J + j1 - j2) * Factorial(J - j1 + j2) * Factorial(j1 + j2 - J);
	numerator *= Factorial(J + M) * Factorial(J - M) * Factorial(j1 - m1) * Factorial(j1 + m1) * Factorial(j2 - m2) * Factorial(j2 + m2);
	double denominator = Factorial(j1 + j2 + J + 1);
	
	//int const min = std::max(0., std::max(j2 - J - m1, j1 + m2 - J));
	//int const max = std::min(j2 + m2, std::min(j1 - m1, j1 + j2 - J));
	int const min = (int)std::max(0., std::max(j2 - J - m1, j1 + m2 - J));
	int const max = (int)std::min(j2 + m2, std::min(j1 - m1, j1 + j2 - J));
	double sum = min > max ? 1 : 0;
	
	for( int k = min; k <= max; ++k ){
		sum += pow(-1., k) / (Factorial(k) * Factorial(j1 + j2 - J - k) * Factorial(j1 - m1 - k) * Factorial(j2 + m2 - k) * Factorial(J - j2 + m1 + k) * Factorial(J - j1 - m2 + k));
	}
	return SquareRoot(numerator / denominator) * sum;
}

//--------------------overloaded ClebschGordan function ----------------------
double ClebschGordan(const CGCcoeff& cgc){


	return ClebschGordan(cgc.j1,cgc.j2,cgc.m1,cgc.m2,cgc.j,cgc.m);
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: MQuantumNumber

  Summary: calculate the possible magnetic quantum number m for given
  	   spin of length j.  
  	    
  Args: const double &j
  		the length of the spin quantum number.    
  	      
  Returns:  std::vector<double>
  		list of all possible m values.
------------------------------------------------------------------*/
std::vector<double> MQuantumNumber(const double &j)
{    
	double spin = j;
	std::vector<double> m_values;
	if(validAngularMomentum(spin))
	{
		for(auto i =-j; i<=j; i++)
		{       
			if(i==0){m_values.push_back(0);}
			else m_values.push_back(i);  
		}
	}
	else{
		throw std::invalid_argument("the system has physically invalid spin!.");
	}	
	return m_values;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: possibleJ  

  Summary: calculate the possible total angular momenta values   
  	    
  Args: const double& j1
  		first angular momentum.	
  	const double& j2
  		second angular momentum.     
  	      
  Returns: std::vector<double>
  		list of all possible  total angular momenta J values.
------------------------------------------------------------------*/
std::vector<double> possibleJ(const double& j1, const double& j2){

	double Jmin = std::abs(j1-j2);
	double Jmax = j1+j2;
	std::vector<double> J_values;
	if(validAngularMomentum(j1) && validAngularMomentum(j2))
	{
		for(auto i =Jmin; i<=Jmax; i++)
		{       
			if(i==0){J_values.push_back(0);}
			else J_values.push_back(i);  
		}
	}
	else{
		throw std::invalid_argument("the system has physically invalid spin!.");
	}
	return J_values;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: ListOfAllCGCs

  Summary: calculate all Clebsch–Gordan Coefficients for addition of two angular
  	   momenta. 
  	    
  Args: const double& j1
  		first angular momentum.	
  	const double& j2
  		second angular momentum.      
  	      
  Returns:  void
  		print the list of all Clebsch–Gordan Coefficients.
------------------------------------------------------------------*/
void ListOfAllCGCs(const double& j1, const double& j2)
{
	std::vector<double> J = possibleJ(j1,j2);
	std::vector<double> M;  
 
	for(auto& j : J){
		for(int i =0;i<int(2*j+1);i++){
			M.push_back(MQuantumNumber(j)[i]);
		}
	}
	std::cout<<"----------------------------------------------------------------"<<std::endl;
	std::cout<<"Clebsch-Gordon coefficients for system with j1 = ";
	DecimalToFraction(j1);
	std::cout<<" and j2 = ";
	DecimalToFraction(j2);
	std::cout<<" :"<<std::endl;
	std::cout<<"----------------------------------------------------------------"<<std::endl;
	for(auto& jj : J){
		for(auto m = -jj; m <= jj; ++m){
			for(auto m1 = -j1; m1 <= j1; ++m1) for(auto m2 = -j2; m2 <= j2; ++m2){
				if( (-jj <= std::abs(m1+m2)) && (std::abs(m1+m2) <= jj) && ( (m1+m2) == m) ){
					std::cout<<"<";
					DecimalToFraction(j1);
					std::cout<<", ";
					DecimalToFraction(j2);
					std::cout<<"; ";
					DecimalToFraction(m1);
					std::cout<<", ";
					DecimalToFraction(m2);
					std::cout<<" | ";
					DecimalToFraction(jj);
					std::cout<<", ";
					DecimalToFraction(m1+m2);
					std::cout<<"> = ";
					std::cout<<" = ";
					DecimalToFraction(ClebschGordan(j1,j2,m1,m2,jj,m));
					std::cout<<std::endl;
				}
			}	
		}
	} 
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: CGCcoeffMap  

  Summary: store Clebsch–Gordan Coefficients as a map  
  	    
  Args: const double& j1
  		first angular momentum.	
  	const double& j2
  		second angular momentum.      
  	      
  Returns: std::map<CGCcoeff, std::vector<CGCcoeff>> 
  		mapping each GCcoeff to its all possible values
  		stored as vector.
------------------------------------------------------------------*/
std::map<CGCcoeff, std::vector<CGCcoeff>>  CGCcoeffMap (const double& j1, const double& j2)
{  ///@TODO under construction 
        std::map<CGCcoeff, std::vector<CGCcoeff>> CGCs;
	std::vector<double> J = possibleJ(j1,j2);
	std::vector<double> M;  
 
	for(auto& j : J){
		for(int i =0;i<int(2*j+1);i++){
			M.push_back(MQuantumNumber(j)[i]);
		}
	}
		
	for(auto& jj : J){
		for(auto m = -jj; m <= jj; ++m){
			for(auto m1 = -j1; m1 <= j1; ++m1) for(auto m2 = -j2; m2 <= j2; ++m2){
				if( (-jj <= std::abs(m1+m2)) && (std::abs(m1+m2) <= jj) && ( (m1+m2) == m) ){
					CGCs[CGCcoeff(jj,m1+m2)].push_back(CGCcoeff(j1,j2,m1,m2,jj,m1+m2));		 
				}	
			}
		}	 
	}
	return CGCs;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:  CoupledStates 

  Summary: List the states of the coupled system.
  	    
  Args: const double& j1
  		first angular momentum.	
  	const double& j2
  		second angular momentum.     
  	      
  Returns: void
  		print the list of all states of the coupled system.
------------------------------------------------------------------*/
void CoupledStates(const double& j1, const double& j2)
{	
	std::map<CGCcoeff, std::vector<CGCcoeff>> res = CGCcoeffMap(j1,j2);
	std::cout<<"----------------------------------------------------------------"<<std::endl;
	std::cout<<"The states of the coupled system ";
	DecimalToFraction(j1);
	std::cout<<" + ";
	DecimalToFraction(j2);
	std::cout<<" :"<<std::endl;
	std::cout<<"----------------------------------------------------------------"<<std::endl;
	
	for(auto itr = res.begin(); itr!=res.end(); itr++) {

		std::cout <<"|";DecimalToFraction(itr->first.j); std::cout<< ", ";DecimalToFraction(itr->first.m);std::cout<<">"<< " = ";

		for(auto vitr = itr->second.begin(); vitr != itr->second.end(); vitr++){

			if(ClebschGordan(*vitr)!=0){
				
				std::cout<<"{ ";
				DecimalToFraction(ClebschGordan(*vitr));
				
				if(vitr==itr->second.end()-1){
					std::cout<<" } "<<*vitr;
				}
				else std::cout<<" } "<<*vitr<<" + ";
			}

		}
		std::cout<<std::endl;
	} 
}
 
} //end of namespace QuantaPlus
#endif

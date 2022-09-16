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
#ifndef QUANTAPLUS_CLEBSCHGORDON_H
#define QUANTAPLUS_CLEBSCHGORDON_H
//#include<iostream>
#include<limits>
#include<cmath>
#include<complex>
#include<vector>
#include<map>
#include <stdexcept>
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

#include"include/cgc.hpp"
} //end of namespace QuantaPlus
#endif

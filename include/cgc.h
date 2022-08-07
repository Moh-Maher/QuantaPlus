/**************************************************************************************
cgc.h is a part of QUANTAPLUS library. 

usage: Calculation of the Clebsch–Gordan Coefficients Generalized power series representations.
	ref: https://functions.wolfram.com/HypergeometricFunctions/ClebschGordan/06/01/

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
**************************************************************************************/
#pragma once
#ifndef QUANTAPLUS_INCLUDE_CLEBSCHGORDON_H
#define QUANTAPLUS_INCLUDE_CLEBSCHGORDON_H
//#include<iostream>
#include<limits>
#include<cmath>
#include<complex>
#include<vector>
#include<map>
#include <stdexcept>
#include"angularmomentum.h"

namespace QuantaPlus {

/***************************************************************************
  Class:    CGCcoeff.

  Summary:  Clebsch–Gordan Coefficients representation <j1, j2; m1, m2 | j, m >
	   
***************************************************************************/
class CGCcoeff {
	public:
		double j1=0, j2=0, m1=0, m2=0, j=0, m=0;
		//double j, m;
		CGCcoeff() = default; //<------ defaulte constructor
		CGCcoeff(double J1, double J2, double M1, double M2, double J, double M)
		:j1(J1),j2(J2),m1(M1),m2(M2),j(J),m(M)
		{ 
		 //j1 = J1; j2 = J2; m1 = M1; m2 = M2; j = J; m = M;
		}
		CGCcoeff(double J, double M):j(J),m(M){}

		CGCcoeff(double J1, double J2,double J, double M)
		:j1(J1),j2(J2),j(J),m(M){}
			 
		CGCcoeff(const CGCcoeff& gc){
			j1 = gc.j1; j2 = gc.j2; m1 = gc.m1; m2 = gc.m2; j = gc.j; m = gc.m;
		}

	        ///<---overloading operator < : required to be used in a std::map.
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
		//<----overloading the logical == operator 
		bool operator ==(const CGCcoeff& CG){
			
			bool res = false;
			if(j==CG.j && m == CG.m){res = true;}
			return res;
		}
};
//---------------------------overloaded << operator--------------------------
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

#include"cgc.hpp"
} //end of namespace QuantaPlus
#endif

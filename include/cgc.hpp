/*******************************************************************************************
some of "cgc.h" meathods implementation.
 
by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
//#pragma once
#ifndef QUANTAPLUS_INCLUDE_CGC_HPP
#define QUANTAPLUS_INCLUDE_CGC_HPP

#ifndef QUANTAPLUS_INCLUDE_CGC_HPP
#error __FILE__ should only be included from cgc.h.
#endif // CGC_H
double SquareRoot(const double& x, const double& curr, const double& prev)
{
        return curr == prev
               ? curr
               : SquareRoot(x, 0.5 * (curr + x / curr), curr);
}

double SquareRoot(const double& x)
{
	return x >= 0 && x < std::numeric_limits<double>::infinity()
               ? SquareRoot(x, x, 0)
               : std::numeric_limits<double>::quiet_NaN();
}
 
std::size_t Factorial(const std::size_t& n)
{
        return n == 0? 1 : n * Factorial(n-1);
}
double FracFactorial(const double& n){
  
	return tgamma(n+1.);
}

double clebsch_gordan(const double& j1, const double& m1, const double& j2, const double& m2, const double& J, const double& M){
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

	auto const & f = Factorial;
	double numerator = (2 * J + 1) * f(J + j1 - j2) * f(J - j1 + j2) * f(j1 + j2 - J);
	numerator *= f(J + M) * f(J - M) * f(j1 - m1) * f(j1 + m1) * f(j2 - m2) * f(j2 + m2);
	double denominator = f(j1 + j2 + J + 1);
	
	int const min = std::max(0., std::max(j2 - J - m1, j1 + m2 - J));
	int const max = std::min(j2 + m2, std::min(j1 - m1, j1 + j2 - J));
	double sum = min > max ? 1 : 0;
	
	for( int k = min; k <= max; ++k ){
		sum += pow(-1., k) / (f(k) * f(j1 + j2 - J - k) * f(j1 - m1 - k) * f(j2 + m2 - k) * f(J - j2 + m1 + k) * f(J - j1 - m2 + k));
	}
	return SquareRoot(numerator / denominator) * sum;
}
#endif // CGC_HPP

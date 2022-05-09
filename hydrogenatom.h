#pragma once

#include<cmath>
#include<complex>  
const std::complex<double> i(0.0,1.0);
 
/****************************************************************************
		factorial
****************************************************************************/
int factorial(int n)
{
	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
/****************************************************************************
		gives the spherical harmonic Y(θ,φ) 
****************************************************************************/
std::complex<double> SphericalHarmonicY(int l, int m, double theta, double phi)
{
	std::complex<double> res{};

	if( l >= 0 )
	{
		res = sqrt((2*l+1)/(4*M_PI))*sqrt(factorial(l-m))/sqrt(factorial(l+m))*std::assoc_legendre(l, m, cos(theta))*exp(i*double(m)*phi);
	} 

	else if ( l <= -1 )
	{
		res = SphericalHarmonicY(-(l+1) ,m, theta, phi);
	}

	return res;
}
/****************************************************************************
		gives the Radial Functions R_nl(r)
****************************************************************************/
double RadialFunctionRnl(int n, int l, double r)
{
	const double a0 = 5.29e-11; 
	double res{};
	
	res= -pow( (2)/(n*a0), 3./2.)*( sqrt(factorial(n-l-1))/sqrt(2*n*pow( factorial(n+l),3 )) )*pow( (2*r)/(n*a0), l)*exp(-r/(n*a0))*std::assoc_laguerre((n+l), (2*l+1), (2*r)/(n*a0));

	return res;
}

/****************************************************************************
		
****************************************************************************/
std::complex<double> psi(int n, int l, int m, double r, double theta, double phi)
{
	return (2./(n*n))* ( sqrt(factorial(n-l-1))/sqrt(factorial(n+l)) )*pow( (2*r)/(n), l)*exp(-r/(n))*std::assoc_laguerre((n-l-1), (2*l+1), (2*r)/(n))*SphericalHarmonicY(l,m,theta,phi);	
}

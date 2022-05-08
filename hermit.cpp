#include<iostream>
#include<cmath>
#include<complex>
#include<iomanip>
using namespace std;
const std:: complex<double> i(0.0,1.0);
int factorial(int n);
  
complex<double> SphericalHarmonicY(int l, int m, double theta, double phi);
double RadialFunctionRnl(int n, int l, double r);
void Table(int expr(int), int iMax);
int main(){

int x=1;
//cout<<hermite(10,x)<<endl;
//cout<<assoc_legendre(2, 0, 0.5)<<endl;
//cout<<setprecision(17)<<SphericalHarmonicY(-3,1,60.,60.)<<endl;
cout<<RadialFunctionRnl(1,-1,1e-9)<<endl;
Table(factorial,5);
return 0;
}

int factorial(int n)
{
	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

complex<double> SphericalHarmonicY(int l, int m, double theta, double phi)
{
	complex<double> res{};

	if( l >= 0 )
	{
		res = sqrt((2*l+1)/(4*M_PI))*sqrt(factorial(l-m))/sqrt(factorial(l+m))*assoc_legendre(l, m, cos(theta))*exp(i*double(m)*phi);
	} 

	else if ( l <= -1 )
	{
		res = SphericalHarmonicY(-(l+1) ,m, theta, phi);
	}

	return res;
}

double RadialFunctionRnl(int n, int l, double r)
{
	const double a0 = 5.29e-11; 
	double res{};
	
	res= -pow( (2)/(n*a0), 3./2.)*( sqrt(factorial(n-l-1))/sqrt(2*n*pow( factorial(n+l),3 )) )*pow( (2*r)/(n*a0), l)*exp(-r/(n*a0))*assoc_laguerre((n+l), (2*l+1), (2*r)/(n*a0));

	return res;
}


void Table(int expr(int), int iMax)
{       cout<<"[ ";  
	for(int k=1; k<=iMax; k++)
	{       
		cout<<expr(k)<<",\t";
	}
	cout<<" ]\n";
}


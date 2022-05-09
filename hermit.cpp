#include<iostream>
#include<cmath>
#include<complex>
#include<iomanip>
#include"hydrogenatom.h"
#include"utilities.h"
using namespace std;
/*
const std:: complex<double> i(0.0,1.0);
int factorial(int n);
  
complex<double> SphericalHarmonicY(int l, int m, double theta, double phi);
double RadialFunctionRnl(int n, int l, double r);
void Table(int expr(int), int iMax);
*/
int main(){

//int x=1;
//cout<<hermite(10,x)<<endl;
//cout<<assoc_legendre(2, 0, 0.5)<<endl;
//cout<<"SphericalHarmonicY(-3,1,60.,60.) = "<<setprecision(10)<<SphericalHarmonicY(-3,1,60.,60.)<<endl;
cout<<"=======================================================================\n";
cout<<endl;
cout<<"SphericalHarmonicY(-3,1,60.,60.) = ";
cplx_print(SphericalHarmonicY(-3,1,60.,60.));
cout<<endl;
cout<<"-----------------------------------------------------------------------\n";
cout<<"RadialFunctionRnl(1,-1,1e-9) = "<< setprecision(16)<<RadialFunctionRnl(1,-1,1e-9)<<endl;
cout<<"-----------------------------------------------------------------------\n";
cout<<"pai(4, 3, 3, 10, 60, 60) = "<< setprecision(16)<<psi(4,3,3,5,6,6);
cout<<endl;
return 0;
}
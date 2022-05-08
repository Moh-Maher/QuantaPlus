/********************************************************************************************************************************************
* Polygamma.cpp is part of PARTON-x  
*
* By: Mohammed Maher Abdelrahim Mohammed
*     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
*     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
*     mohammed.maher@unical.it
*
*********************************************************************************************************************************************/
#include<iostream>
#include<cmath>
#include<complex>
#include <vector>
#include<iomanip>
#include <math.h>
//#include<algorithm>
 using namespace std;
 
/*------------------------------------------------------------------------------------------
                        Gamma function Γ(z) Spouge's approximation
-------------------------------------------------------------------------------------------*/
// Calculate the coefficients used by Spouge's approximation
std::vector<double> CalculateCoefficients(int numCoeff)
{
    std::vector<double> c(numCoeff);
    double k1_factrl = 1.0;
    c[0] = sqrt(2.0 * M_PI);
    for(size_t k=1; k < numCoeff; k++)
    {
        c[k] = exp(numCoeff-k) * pow(numCoeff-k, k-0.5) / k1_factrl;
        k1_factrl *= -(double)k;
    }
    return c;
}
 
// The Spouge approximation
std::complex<double> gamma(std::complex<double> z)
{       
    if (real(z) < 0.5)
    {
        return M_PI / (sin( M_PI * z) * gamma(1. - z));
    }
    else
    {
        z -= 1.;
     
        const std::vector<double>& coeffs= CalculateCoefficients(10);
        const double numCoeff = coeffs.size();
        std::complex<double> accm = coeffs[0];
        for(size_t k=1; k < numCoeff; k++)
        {
            accm += coeffs[k] / ( z + double(k) );
        }
        accm *= exp(-(z+numCoeff)) * pow(z+numCoeff, z+0.5);
        return accm;
    }
} 
/*====================================================================
                psi(z,k) function, k = 0,1,3,.....
=====================================================================*/
/*  This code is converted form R-programming language, 
   for orignial code visit: "psi: Psi (Polygamma) Function".              
   R/psi.R In pracma: Practical Numerical Math Functions. 
         ( https://rdrr.io/rforge/pracma/man/psi.html) */
                               
complex<double> psi(complex<double> z,int k)
{ 
 //double f;
 //const double PI = 3.14159265358979324e0;
    const complex<double> i= (0.,1.); 
    complex<double> n,d,gg,dz,dd;
    complex<double> zz= z,zneg,gneg,hneg,fneg,zgh;
    double isneg, isok;
    complex<double> f= 0.*z;
/*......................................................................................
case n =0 the so-called digamma function:
......................................................................................*/
    if (k == 0)
    {
        // reflection point
        double p = real(z); 
        if (p < 0.5)
        {
            z= 1. - z;
        }
        // Lanczos approximation for the complex plane
        double g = 607./128.;  // best results when 4 <= g <= 5
    
        double cc[15] = {0.99999999999999709182    ,  57.156235665862923517     , -59.597960355475491248     ,
                         14.136097974741747174     , -0.49191381609762019978    ,  0.33994649984811888699e-04,
                         0.46523628927048575665e-04, -0.98374475304879564677e-04,  0.15808870322491248884e-03,
                        -0.21026444172410488319e-03,  0.21743961811521264320e-03, -0.16431810653676389022e-03,
                         0.84418223983852743293e-04, -0.26190838401581408670e-04,  0.36899182659531622704e-05};
                            
        n= d = 0.;
        for (int j=2; j<=15;j++)
        {
            dz = 1./(z+double(j)-2.);
            dd = cc[j-1] * dz;
            d  = d + dd;
            n  = n - (dd * dz);
        }
        d  = d + cc[0];
        gg = z + g - 0.5;
    
        // log is accurate to about 13 digits...
        f = log(gg) + (n/d - g/gg);
    
        if (p < 0.5)
        {//f= f- PI*cot(PI*zz)
            f= f- M_PI*1./tan(M_PI*zz);
        }    
        //p <- which(round(zz) == zz && Real(zz) <= 0 && Imag(zz) == 0)
        //if (length(p) > 0)
          // f[p] <- Inf
    }
/*......................................................................................
cases n >=1: 
......................................................................................*/
    else if (k >= 1)
    {
        n = k;
        //the zeros of the Lanczos PFE series when g=607/128 are:
        complex<double> r[14] = { 
        {-4.1614709798720630    ,-0.14578107125196249},
        {-4.1614709798720630    , 0.14578107125196249},
        {-4.3851935502539474    ,-0.19149326909941256},
        {-4.3851935502539474    , 0.19149326909941256},
        {-4.0914355423005926    , 0.},
        {-5.0205261882982271    , 0.},
        {-5.9957952053472399    , 0.},
        {-7.0024851819328395    , 0.},
        {-7.9981186370233868    , 0.},
        {-9.0013449037361806    , 0.},
        {-9.9992157162305535    , 0.},
        {-11.0003314815563886   , 0.},
        {-11.9999115102434217   , 0.},
        {-13.0000110489923175587, 0.}
                                    };
        // the poles of the Lanczos PFE series are:
        // p <- c(0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13)
        double e = exp(1.);
        double g = 607./128. ;// best results when 4<=g<=5
        double h = 1./2.;
        complex<double > s = 0.;
        
        for ( k=0; k<=12; k++)
        {
            s = s + (1./(pow(z-r[k],n+1.)) - 1./(pow(z+double(k),n+1.)));
        }
        // what happens if n is not a positive integer?
        s = pow((-1),n) * gamma(n+1.) * s;

        zgh = z + (g-h);
        if (n == 0.)
        {
          //s=log(zgh)+(-g/zgh + s);
        //  use existing more accurate digamma function if n=0
        //  should never reach this code since we trapped it above 
            f= psi(z,0);
        }        
        else
        {
        // do derivs of front end stuff
           s = pow(-1,n+1.) * (gamma(n) *pow(zgh,-n) + 
           g*gamma(n+1.) * pow(zgh,-n-1.)) + s;
           
        }
   
        f=s;
    }
    
    else
    {                                                                                                                
        cout<<"Argument 'n': Invalid Polygamma order.!\n";
        return 0;
    }     
     
    return f; 
}

#include<iostream>
#include<complex>
#include<cmath>
#include"operators.h"
#include"braket.h"
//#include"constants.h"

/*--------------------------------------------------------------------------------------------
->> lambda_i(l_i) [with i =1...8] where "l_i" represent Gell-Mann matrices (source: phys_conts.h ) 

->> f_i(F_i)  = 1/2 * l_i are the color charges operators. (source: phys_conts.h ) 

->> Test the commutation relations [F_i, F_j]= i * f_ijk * F_k
--------------------------------------------------------------------------------------------*/
//using namespace QUANTAx;
typedef std::complex<double>  complex;
using std::cout;
using std::endl;

int main()
{
   using namespace std::complex_literals; //needed to use the literal imaginary unit [ 1i = (0,1)] 
 
   Eigen::Matrix<complex,3,3>  lambda3, lambda6, lambda7;
   Eigen::Matrix<complex,3,3> f7,f3,f6;  
   Eigen::Matrix<complex,3,3> com_res, rhs;
   complex f_ijk(0,0); // initialize the structure const f_ijk = 0+0i;
 
 
   lambda3<<1,  0, 0, 0, -1, 0, 0,  0, 0;
   lambda6<<0, 0, 0, 0, 0, 1, 0, 1 ,0;
   lambda7<<0, 0,  0,0, 0, -1i,0, 1i,  0;
   f3<<0.5,0,0,0,-0.5,0,0,0,0;
   f7<<0,0,0,0,0,1./2.,0,1./2.,0;
   f6<<0,0,0,0,0,-1i/2.,0,1i/2.,0;
   cout<<"-------------------------------------------------------------"<<endl;
   cout<<" Test the commutation relations [F_i, F,j]= i * f_ijk * F_k :"<<endl;
   cout<<"-------------------------------------------------------------"<<endl;
   
   f_ijk = StructureConstant(lambda3,lambda6,lambda7); // gives f_367  
   cout<<"structure const = "<<f_ijk<<endl;

   cout<<"******************[Right hand side ]*************************"<<endl;

   rhs = -1i*f_ijk * f7;
   cout<<rhs<<endl;
  
   cout<<"******************[Left hand side ]*************************"<<endl;
 
   com_res = Commute(f3,f6);
   cout<<com_res;
   cout<<"\n";

   if(com_res == rhs)
   {
      cout<<"PASS!: L.H.S = R.H.S"<<endl;
   }

   else
   {
      cout<<"FAIL!: L.H.S != R.H.S"<<endl;
   }
   
   return 0;
}

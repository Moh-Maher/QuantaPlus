#include<iostream>
#include<cmath>

using namespace std;
/*defining test differential equations y' = f(x,y) to be solved*/
double f(double x,double y){return exp(sin(sqrt(x+y))); }

double f2(double x,double y){return exp(sin(sqrt(x+y)))+pow(cos(x),y); }
double f3(double x,double y){return 1+x*x*x+y*y;}
/*---------------------------------------------------------------------------------------
                Euler's method to solve ordinary differential equations
---------------------------------------------------------------------------------------*/
void ODE_Euler(double x0, double y0, double xn, int n, double f(double,double), double h,bool flag)
{
 double yn, slope;//h = (xn-x0);//(xn-x0)/n;
 int i;
 
 if(flag==true)
 {
   cout<<"\nx0\ty0\tslope\tyn\n";
   cout<<"------------------------------\n";

   for(i=0; i < n; i++)
   {
    slope = f(x0,y0);
    yn = y0 + h * slope;
    cout<< x0<<"\t"<< y0<<"\t"<< slope<<"\t"<< yn<< endl;
    y0 = yn;
    x0 = x0+h;
   }
   /* Displaying result */
   cout<<"\nValue of y at x = "<< xn<< " is " << yn<<endl;
 }
 
 if(flag==false)
 {
   for(i=0; i < n; i++)
   {
    slope = f(x0,y0);
    yn = y0 + h * slope;
    y0 = yn;
    x0 = x0+h;
   }
   /* Displaying result */
   cout<<"\nValue of y at x = "<< xn<< " is " << yn<<endl;
 }
}
//==============================================================================
int main()
{
 float x0, y0, xn, h, yn, slope;
 int i, n;

 cout<<"Enter Initial Condition"<< endl;
 cout<<"x0 = ";
 cin>> x0;
 cout<<"y0 = ";
 cin >> y0;
 cout<<"Enter calculation point xn = ";
 cin>>xn;
 cout<<"Enter number of steps: ";
 cin>> n;

 ODE_Euler(x0,y0,xn,n,f3,0.01,true);
 /*
 for(int i=0;i<30;i++){
 // ODE_Euler(0.0,0.0,i,1.0e+07,psi,1.0e-05,false);
 }
 */
 return 0;
}

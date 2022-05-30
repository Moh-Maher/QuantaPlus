/*#include<iostream>
#include<iomanip>
#include"utilities.h"
using namespace std;


int main(){
//setprecision(20);
long double z =3.16667 ;
DecimalToFraction(z);

}*/
#include <iostream>
#include"utilities.h"
#include<complex>
/*
#include <valarray> 
#include<sstream>
#include<cmath>
using namespace std;

 

//------------
std::string ToString(const double& numb)
{
    std::stringstream ss;
    ss << numb;
    return ss.str();
}
//-----------------
bool IsNumber(const std::string& str) 
{
    return str.find_first_not_of( "0123456789" ) == std::string::npos;
}

//---------------------------------


void as_radical(double a , int cycles = 10, double precision = 5e-4){
//int sign  = a > 0 ? 1 : -1;
//a = a *sign;
double z = a*a;
 
 if(IsNumber(ToString(z))){ cout<<"sqrt["<<z<<"]\n"; }
 
 else if (!IsNumber(ToString(z))){
 double number = z;
 
 int sign  = number > 0 ? 1 : -1;
    number = number * sign; //abs(number);
    double new_number,whole_part;
    double decimal_part =  number - (int)number;
    int counter = 0;
    
    valarray<double> vec_1{double((int) number), 1}, vec_2{1,0}, temporary;
    
    while(decimal_part > precision & counter < cycles){
        new_number = 1 / decimal_part;
        whole_part = (int) new_number;
        
        temporary = vec_1;
        vec_1 = whole_part * vec_1 + vec_2;
        vec_2 = temporary;
        
        decimal_part = new_number - whole_part;
        counter += 1;
    }
    
    double numt = sign * vec_1[0];
    double dnum = vec_1[1];
    double snumt= sqrt(numt);
    double sdnum= sqrt(dnum);
    
    if(IsNumber(ToString(snumt)) && IsNumber(ToString(sdnum)))
    {cout<<"x: "<< number <<"\tFraction: " << snumt<<'/'<< sdnum<<endl;} 
    
     else if(IsNumber(ToString(snumt)) && (!IsNumber(ToString(sdnum))) )
    cout<<"x: "<< number <<"\tFraction: " << snumt<<'/'<<"sqrt["<< vec_1[1]<<"]"<<endl;
    else if( !IsNumber(ToString(snumt)) && (IsNumber(ToString(sdnum))) )
    cout<<"x: "<< number <<"\tFraction: " <<"sqrt["<< sign * vec_1[0]<<"]"<<'/'<< sdnum<<endl;
    else 
     cout<<"x: "<< number <<"\tFraction: " <<"sqrt["<< sign * vec_1[0]<<'/'<< vec_1[1]<<"]"<<endl;
}
 
 
 
  
}

*/
int main()
{
    //as_fraction(3.142857);
   // as_fraction(0.10188534162169866);
    //as_fraction(0.333333);
    //as_fraction(514.0/37.0);
    //as_fraction(1.17171717);
    //as_fraction(-1.17);
   // std::complex<double> i(0.,7.);
    DecimalToFraction(2.3333333333333335);
  //  DecimalToFraction(0.10188534162169866);
}


 


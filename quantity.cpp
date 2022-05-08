#include<iostream>

#include"quantity.h"
using namespace std;





/*
long double operator"" _GeVinvs(long double m){
    return (m/(0.197e-15));
}

//----------
long double operator"" _GeV(long double Kg){
    return (Kg/(1.782662e-27));
}
*/
int main(){

 

//cout<<"1 Kg = "<< 1.0e0_GeV<<endl;
//cout<<"173 cm = "<< 173e-2_GeVinvs<<endl;
 
 Quantity Q1 = {10,"kilometers"};
 Quantity Q2 = UnitConvert(Q1,"meters");
 Quantity random = 7;
 
 
//cout<<UnitConvert(meter, "Km")<<endl;

cout<<Q1<<" converted to "<<Q2<<endl;
cout<<random<<endl;
}

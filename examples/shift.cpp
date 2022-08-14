#include<iostream>
#include<complex>
#include"braket.h"
#include<cmath>
#include"operators.h"
#include"timer.h"
#include"utilities.h"
 
using namespace QuantaPlus;
	typedef std::complex<double>  complex;
	using std::cout;
	using std::endl;
int main()
{ 
	ElapsedTime time_count;
 
 	int N =25;
  	QM_operator<complex> plus(N,N), minus(N,N), res(N,N);
 	plus = RisingOperator<complex>(N,N) + LoweringOperator<complex>(N,N);
 	minus =  LoweringOperator<complex>(N,N) - RisingOperator<complex>(N,N) ;
 	//Bra<complex> ll(5);
 	//ll<<0.,0.,-1.9,0.,0.05;
        Bra<complex> ll(3);
        ll<<0.,1.0,0.5;
	Output of0("output/shiftedphi0");
	Output of1("output/shiftedphi1");
	Output of2("output/shiftedphi2");
	Output of3("output/shiftedphi3");
    
	time_count.Start(); 

 	cout<<"------ Old wave_function-----\n";
 	for(int i=-10;i<=10;i++){
  	 
 	of0.takeData<<i<<"\t"<<std::real(wave_function_H(plus,minus,ll,i,0))<<endl;
 	cout<<i<<"\t"<<std::real(wave_function_H(plus,minus,ll,i,0))<<endl;
	}
	
	cout<<"------New wave_function-----\n";
 	for(int i=-10;i<=10;i++){
 	//cout<<wave_function(0.,i)<<endl;
 	of1.takeData<<i<<"\t"<<std::real(wave_function_H(plus,minus,ll,i,1))<<endl;
 	cout<<i<<"\t"<<std::real(wave_function_H(plus,minus,ll,i,1))<<endl;
	}
	
	cout<<"------New wave_function-----\n";
 	for(int i=-10;i<=10;i++){
 	//cout<<wave_function(0.,i)<<endl;
 	of2.takeData<<i<<"\t"<<std::real(wave_function_H(plus,minus,ll,i,2))<<endl;
 	cout<<i<<"\t"<<std::real(wave_function_H(plus,minus,ll,i,6))<<endl;
	}

	cout<<"------New wave_function-----\n";
 	for(int i=-10;i<=10;i++){
 	//cout<<wave_function(0.,i)<<endl;
 	of3.takeData<<i<<"\t"<<std::real(wave_function_H(plus,minus,ll,i,3))<<endl;
 	cout<<i<<"\t"<<std::real(wave_function_H(plus,minus,ll,i,7))<<endl;
	}	 	
	
	time_count.End();		
}

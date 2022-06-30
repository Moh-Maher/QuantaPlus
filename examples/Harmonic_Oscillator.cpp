#include<iostream>
#include<complex>
#include"braket.h"
#include<cmath>
#include<vector>
#include<fstream>
#include"operators.h"
#include"timer.h"
 
	typedef std::complex<double>  complex;
	using std::cout;
	using std::endl;



int main()
{ 
	ElapsedTime time_count;
	
	using namespace std::complex_literals;
 
time_count.Start();
 	int N =5;// 21;
  	QM_operator<complex> plus(N,N), minus(N,N), res(N,N);
 	plus = RisingOperator<complex>(N,N) + LoweringOperator<complex>(N,N);
 	minus =  LoweringOperator<complex>(N,N) - RisingOperator<complex>(N,N) ;
 	Bra<complex> ll(3);
 	ll<<0.,0.,0.5;
  
 	std::ofstream outfile1;
 	std::ofstream outfile2;
	std::string output_path1 ("output/phi0.dat"); ///<-- path to the output file and its name.
	std::string output_path2 ("output/phi1.dat");
	 
	outfile1.open(output_path1);///<-- open the input file to read the data.
 
	outfile2.open(output_path2);///<-- open the input file to read the data.
 
	
 	cout<<"------ Old wave_function-----\n";
 	for(int i=-5;i<=5;i++){
  
 	outfile1<<i<<"\t"<<std::real(wave_function_H(plus,minus,ll,i,0))<<endl;
 	cout<<i<<"\t"<<std::real(wave_function_H(plus,minus,ll,i,0))<<endl;
	}
	outfile1.close();
	cout<<"------New wave_function-----\n";
 	for(int i=-5;i<=5;i++){
 	//cout<<wave_function(0.,i)<<endl;
 	outfile2<<i<<"\t"<<std::real(wave_function_H(plus,minus,ll,i,1))<<endl;
 	cout<<i<<"\t"<<std::real(wave_function_H(plus,minus,ll,i,1))<<endl;
	}
	outfile2.close();
time_count.End();
	
 
	
	
}

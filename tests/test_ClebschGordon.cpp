/*******************************************************************************************
testing " cgc.h".
by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#include<iostream>
#include"cgc.h"
#include"timer.h" 

using namespace QuantaPlus;
int main(){
	
	ElapsedTime time_count; 
	
	double j1,j2;
	std::cout<<"Insert the following: j1,j2\n";
	std::cin>>j1>>j2;
	
	time_count.Start();
	/*{
		double j1,m1,j2,m2,J,M;
		std::cout<<"Insert the following: j1,j2,m1,m2,j,m\n";
		std::cin>>j1>>j2>>m1>>m2>>J>>M;
		
		std::cout<<"------------------------------------------"<<std::endl;
		std::cout<<"< "<<j1<<", "<<j2<<", "<<m1<<", "<<m2<<"|"<<J<<", "<<M<<" > = ";
		DecimalToFraction(ClebschGordan(j1,m1,j2,m2,J,M));
		std::cout<<std::endl;
	}*/
 
	ListOfAllCGCs(j1,j2);
 	CoupledStates(j1,j2);
 
	time_count.End();
	return 0;
}


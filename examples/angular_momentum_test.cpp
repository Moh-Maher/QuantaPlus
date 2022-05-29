/*******************************************************************************************
testing "amo".

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#include<iostream>
#include<complex>
#include<ctime>
#include"utilities.h"
#include"operators.h"
#include"braket.h"

	typedef std::complex<double>  complex;
	using std::cout;
	using std::endl;
 
int main()
{
        ///<--clock stuff
	std::clock_t start;
	double duration;
 	start = std::clock();
 	///<--stop clock stuff
 	
 	/*
 	double spin; 
 	cout<<"Insert valid spin: (e.g 1/2, 3/2, 5/2,...) \n";
 	std::cin>>spin;
 	*/
        const double spin= 1./2.; // 3./2.;
	 
	
	Angular_Momentum<complex> S_x, S_y, S_z;
	Angular_Momentum<complex> S_sqr, S_plus, S_minus;
       
	S_sqr = S_sqr.Angular_Momentum_OperatorJSqr(spin);
	S_x = S_x.Angular_Momentum_OperatorJx(spin);
	S_y = S_y.Angular_Momentum_OperatorJy(spin);
	S_z = S_z.Angular_Momentum_OperatorJz(spin);
	S_plus = S_plus.Angular_Momentum_OperatorJPlus(spin);
	S_minus = S_minus.Angular_Momentum_OperatorJMinus(spin);

	cout<<"For spin ";
	decimalToFraction(spin);
	cout<<" system:\n";

	cout<<"------------S_x operator:-------------\n";
	result_printf(S_x);

	cout<<"------------S_y operator:-------------\n";
	result_printf(S_y);
	cout<<"------------S_z operator:-------------\n";
	result_printf(S_z);

	cout<<"------------S^2 operator:-------------\n";
	result_printf(S_sqr);

	cout<<"------------S_+ operator:-------------\n";
	result_printf(S_plus);
	cout<<"------------S_- operator:-------------\n";
	result_printf(S_minus);
	
	///<--clock stuff again
	duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
 
	if (duration < 60.0) {
		std::cout << "Elapsed time: " << duration << " seconds" << std::endl;
	}
 
	else {
		std::cout << "Elapsed time: " << duration/60.0 << " mins" << std::endl;
	}
	
	return 0;
}
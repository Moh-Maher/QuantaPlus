/*******************************************************************************************
testing "amo".

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#include<iostream>
#include<complex>
#include"utilities.h"
#include"operators.h"
#include"braket.h"

	typedef std::complex<double>  complex;
	using std::cout;
	using std::endl;
 
int main()
{
	//const double spin= 1./2.;
	const double spin= 1./2.;
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
	cplx_show(S_x);

	cout<<"------------S_y operator:-------------\n";
	cplx_show(S_y);
	cout<<"------------S_z operator:-------------\n";
	cplx_show(S_z);

	cout<<"------------S^2 operator:-------------\n";
	cplx_show(S_sqr);

	cout<<"------------S_+ operator:-------------\n";
	cplx_show(S_plus);
	cout<<"------------S_- operator:-------------\n";
	cplx_show(S_minus);
	return 0;
}

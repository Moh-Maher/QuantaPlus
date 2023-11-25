#include<iostream>
#include<complex>
#include<cmath>
#include"../quantaplus/quantaplus.h"
/*
#include"../quantaplus/operators/angularmomentum.h"
#include"../quantaplus/braket/ket.h"
#include"../quantaplus/braket/bra.h"
#include"../quantaplus/operators/operators.h"
#include"../quantaplus/utilities/utilities.h"
*/
using namespace QuantaPlus;
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
	ElapsedTime time_count; //<--clock stuff
	time_count.Start();
	using namespace std::complex_literals; //needed to use the literal imaginary unit [ 1i = (0,1)] 

	QM_operator<complex>  lambda3(3,3), lambda6(3,3), lambda7(3,3);
	QM_operator<complex> f7(3,3),f3(3,3),f6(3,3);  
	QM_operator<complex> com_res(3,3), rhs(3,3);
	complex f_ijk(0,0); // initialize the structure const f_ijk = 0+0i;


	lambda3<<1,  0, 0, 
		 0, -1, 0, 
		 0,  0, 0;
	
	lambda6<<0, 0, 0, 
		 0, 0, 1, 
		 0, 1 ,0;
	
	lambda7<<0, 0, 0,
		 0, 0, -1i,
		 0, 1i,  0;
	
	f3<<0.5,   0, 0,
	      0,-0.5, 0,
	      0,   0, 0;
	      
	f7<<0, 0, 0,
	    0, 0,1./2.,
	    0,1./2. ,0;
	    
	f6<<0, 0, 0,
	    0, 0,-1i/2.,
	    0, 1i/2., 0;
	    
	cout<<"-------------------------------------------------------------"<<endl;
	cout<<" Test the commutation relations [F_i, F,j]= i * f_ijk * F_k :"<<endl;
	cout<<"-------------------------------------------------------------"<<endl;

	f_ijk = StructureConstant(lambda3,lambda6,lambda7); // gives f_367  
	cout<<"structure const = "<<f_ijk<<endl;

	cout<<"******************[Right hand side ]*************************"<<endl;

	rhs << -1i*f_ijk * f7;
	//ResultPrint(rhs);
	rhs.Print();
	cout<<endl;

	cout<<"******************[Left hand side ]*************************"<<endl;

	com_res << Commute(f3,f6);
	//ResultPrint(com_res);
	com_res.Print();
	cout<<"\n";

	if(com_res == rhs)
	{
	cout<<"PASS!: L.H.S = R.H.S"<<endl;
	}

	else
	{
	cout<<"FAIL!: L.H.S != R.H.S"<<endl;
	}
	time_count.End();
	return 0;
}

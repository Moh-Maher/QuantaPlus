/*******************************************************************************************
testing "braket.h".

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#include<iostream>
#include<complex>
#include<cmath>
#include"braket.h"
#include"operators.h"
//#include"constants.h"


//using namespace QUANTAx;
typedef std::complex<double>  complex;
//using namespace Eigen;
using std::cout;
using std::endl;

int main()
{ 
	using namespace std::complex_literals; //needed to use the literal imaginary unit [ 1i = (0,1)] 
  
  
 //  MatrixXd m(2,2);
 
	Eigen::Matrix<complex,1,1> mt;
	Eigen::Matrix<double,3,3> mat;
	mat<<2.,0,0,0,3.,4.,0.,4.,9.;
	ket<complex,3> kt(3),kt2;
	bra<complex,3> br(3),br2;
        
       // Q_operator<complex,3,3> A;
       // A<<1.,0.,0.,0.,1.,0.,0.,0.,1.;
	
	br << 6., 3.-1i, 5.;
	kt <<1.-2i, 1i,-1i;
  
 
        Q_operator<complex,2,2> sx, sy, com;
        sx<<0.,1.,1.,0;
        sy<<0,-1i,1i,0;
 
	cout<<"--------------------"<<endl;
    	cplx_show(kt);
    	cout<<"--------------------"<<endl;
    	cplx_show(br);
    	cout<<"--------------------"<<endl;
    	mt<<br*kt;
    	cplx_show(mt);
 
   // std::cout<<"For eigen Value "<< QuantxEigenValue(mat,2)<<endl;  
  
    	cout<<"--------------------"<<endl;
    	kt2 = DualConj(br);
    	cplx_show(kt2);
     
	cout<<"--------------------"<<endl;
    	br2 = DualConj(kt);
    	cplx_show(br2);
    	cout<<"--------------------"<<endl;
    	complex braket1{},braket2{};
    	braket1= BraKet(br2,kt);
    	braket2= BraKet(br,kt);
    	cplx_show(braket1);
    	cplx_show(braket2);
    	cout<<endl;
    //cout<<braket1<<endl;
       cout<<"----------------\n";
       //cout<<Commute(sx,sy)<<endl;
       com<<Commute(sx,sy);
       cplx_show(com);
	cout<<endl;
	return 0;
}

 

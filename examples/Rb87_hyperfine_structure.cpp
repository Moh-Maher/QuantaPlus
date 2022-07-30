//*******************************************************************************************
//	testing "angularmomentum.h".
//
//	by:  Mohammed Maher Abdelrahim Mohammed
//	     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
//	     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
//	     mohammed.maher@unical.it                                          
//*******************************************************************************************
#include<iostream>
#include<complex>
#include<ctime>
#include"utilities.h"
#include"angularmomentum.h"
#include"braket.h"
#include"latex.h"
#include"timer.h"
#include"operators.h"
	typedef std::complex<double>  complex;
	using std::cout;
	using std::endl;

QM_operator<complex> Hhf(const complex& Bz)
{
	double const A = 3417.3413054521448;
	double const muB =1.3996244936072704;
	//double const Bz = 1000;
	double const gI = 0.0009951414;
	double const gS = -2.0023193043622;
	double const gL = -0.99999369; 

	AngularMomentum<complex> S_x, S_y, S_z; 
	AngularMomentum<complex> Hhf;
	 


	AngularMomentum<complex> Ix,Iy,Iz;
	AngularMomentum<complex> Sx,Sy,Sz;
	AngularMomentum<complex> Lx,Ly,Lz;

	AngularMomentum<complex> Jx,Jy,Jz;
	AngularMomentum<complex> Fx,Fy,Fz;

	Ix = KroneckerProduct( S_x.AngularMomentum_Jx(1.5), Id<complex>(0.5), Id<complex>(0));
	Iy = KroneckerProduct( S_y.AngularMomentum_Jy(1.5), Id<complex>(0.5), Id<complex>(0));
	Iz = KroneckerProduct( S_z.AngularMomentum_Jz(1.5), Id<complex>(0.5), Id<complex>(0));

	Sx = KroneckerProduct(Id<complex>(1.5), S_x.AngularMomentum_Jx(0.5), Id<complex>(0));
	Sy = KroneckerProduct(Id<complex>(1.5), S_y.AngularMomentum_Jy(0.5), Id<complex>(0));
	Sz = KroneckerProduct(Id<complex>(1.5), S_z.AngularMomentum_Jz(0.5), Id<complex>(0));

	Lx = KroneckerProduct(Id<complex>(1.5), Id<complex>(0.5), S_x.AngularMomentum_Jx(0));
	Ly = KroneckerProduct(Id<complex>(1.5), Id<complex>(0.5), S_y.AngularMomentum_Jy(0));
	Lz = KroneckerProduct(Id<complex>(1.5), Id<complex>(0.5), S_z.AngularMomentum_Jz(0));

	Jx = Sx + Lx;
	Jy = Sy + Ly;
	Jz = Sz + Lz;

	Fx = Ix + Jx;
	Fy = Iy + Jy;
	Fz = Iz + Jz;

	return A*(Ix*Jx + Iy*Jy +Iz*Jz) - muB*Bz*(gI*Iz+gS*Sz+gL*Lz); 

}
int main()
{
	ElapsedTime time_count; //<--clock stuff
	
	/* double const A = 3417.3413054521448;
 	 double const muB =1.3996244936072704;
 	 double const Bz = 1000;
 	 double const gI = 0.0009951414;
 	 double const gS = -2.0023193043622;
 	 double const gL = -0.99999369; 
 
	 
	
	AngularMomentum<complex> S_x, S_y, S_z; 
	AngularMomentum<complex> Hhf;
       	time_count.Start();////
 
	
	AngularMomentum<complex> Ix,Iy,Iz;
	AngularMomentum<complex> Sx,Sy,Sz;
	AngularMomentum<complex> Lx,Ly,Lz;
	
	AngularMomentum<complex> Jx,Jy,Jz;
	AngularMomentum<complex> Fx,Fy,Fz;
	
	Ix = KroneckerProduct( S_x.AngularMomentum_Jx(1.5), Id<complex>(0.5), Id<complex>(0));
	Iy = KroneckerProduct( S_y.AngularMomentum_Jy(1.5), Id<complex>(0.5), Id<complex>(0));
	Iz = KroneckerProduct( S_z.AngularMomentum_Jz(1.5), Id<complex>(0.5), Id<complex>(0));
	
	Sx = KroneckerProduct(Id<complex>(1.5), S_x.AngularMomentum_Jx(0.5), Id<complex>(0));
	Sy = KroneckerProduct(Id<complex>(1.5), S_y.AngularMomentum_Jy(0.5), Id<complex>(0));
	Sz = KroneckerProduct(Id<complex>(1.5), S_z.AngularMomentum_Jz(0.5), Id<complex>(0));
	
	Lx = KroneckerProduct(Id<complex>(1.5), Id<complex>(0.5), S_x.AngularMomentum_Jx(0));
	Ly = KroneckerProduct(Id<complex>(1.5), Id<complex>(0.5), S_y.AngularMomentum_Jy(0));
	Lz = KroneckerProduct(Id<complex>(1.5), Id<complex>(0.5), S_z.AngularMomentum_Jz(0));
	
 	Jx = Sx + Lx;
 	Jy = Sy + Ly;
 	Jz = Sz + Lz;
 	
 	Fx = Ix + Jx;
 	Fy = Iy + Jy;
 	Fz = Iz + Jz;
 	
	Hhf = A*(Ix*Jx + Iy*Jy +Iz*Jz) - muB*Bz*(gI*Iz+gS*Sz+gL*Lz); 
	 */
	Output of0("output/BFiled");
	time_count.Start();///<--clock stuff again
	AngularMomentum<complex> res;
	for(int i=0;i<=3000;i++)
	{
	  	 res = Hhf(i);
		 res = QuantumEigenValue(res);
	 	 //of0.takeData<<i<<"\t"<<CtoRMateix(res)<<endl;
 	 	 of0.takeData<<CtoRMateix(res)<<endl;
 	 }
	/*
	res = Hhf(0);
	cout<<"----------EigenValues-----------"<<endl;
 
	res = QuantumEigenValue(res);
	//cout<<res<<endl;
	NResultPrint(res);
	*/
	time_count.End();
	return 0;
}

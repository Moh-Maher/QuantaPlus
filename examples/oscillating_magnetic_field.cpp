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
#include"../quantaplus/quantaplus.h"
/*
#include"../quantaplus/utilities.h"
#include"../quantaplus/angularmomentum.h"
#include"../quantaplus/braket.h"
#include"../quantaplus/latex.h"
#include"../quantaplus/operators.h"
*/
using namespace QuantaPlus;
	typedef std::complex<double>  complex;
	using std::cout;
	using std::endl;
QM_operator<complex> h0(const double& Bz = 3.22896)
{
	double const A = 3417.3413054521448;
	double const muB =1.3996244936072704;
	
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
 
     
	
	return  A*(Ix*Jx + Iy*Jy +Iz*Jz) - muB*Bz*(gI*Iz+gS*Sz+gL*Lz);

}
QM_operator<complex> H(const double& t)
{
	double const A = 3417.3413054521448;
	double const muB =1.3996244936072704;
	double const Bz = 3.22896;
	double const gI = 0.0009951414;
	double const gS = -2.0023193043622;
	double const gL = -0.99999369; 
	double const omega = 2.*M_PI*6827.9;
	double const Bacx = 0.1;
	double const Bacy = 0.0;
	double const Bacz = 0.0;

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
        QM_operator<complex> H0(8,8);
        QM_operator<complex> H1(8,8);
        H0 = A*(Ix*Jx + Iy*Jy +Iz*Jz) - muB*Bz*(gI*Iz+gS*Sz+gL*Lz);
        H1 = (- muB*( gS*(Bacx*Sx+Bacy*Sy+Bacz*Sz)
	   + gI*(Bacx*Ix+Bacy*Iy+Bacz*Iz) 
	   + gL*(Bacx*Lx+Bacy*Ly+Bacz*Lz) ) );
	
	return H0 + H1 * cos(omega*t);

}
/*****************************************
complex psi(const double& t){
const complex I(0.,1.);
complex res=0.0;
AngularMomentum<complex> H0(8,8);
H0=h0( 3.22896);
double const omega = 2.*M_PI*6827.9;
for(int i=0;i<8;i++){
	for(int j=0;j<8;j++)
	{
		res += exp(-I*(QuantumEigenValue( H0,j)-QuantumEigenValue( H0,i))*t)*cos(omega*t);
	}
}

//res = QuantumEigenValue( H0,0);
return res;
}
****************************************************/

//------------------------------------------------------------------------
// norm[m_?MatrixQ] := Array[m[[#]] . m[[#]] &, Length[m]];
//------------------------------------------------------------------------
//Eigen::MatrixXd Norm(Eigen::MatrixXd& mat){
Eigen::Matrix<complex,Eigen::Dynamic,1> Norm(const Eigen::Matrix<complex,Eigen::Dynamic,Eigen::Dynamic>& mat){
	//Eigen::MatrixXd res(mat.rows(),mat.cols());
	Eigen::Matrix<complex,Eigen::Dynamic,1>  res(mat.cols());
	for(int i=0; i<mat.rows();i++){
		for(int j=0; j<mat.cols();j++){
			res(i)+=mat(i,j)*mat(i,j);
		}
	}
	return res;
}
//------------------------------------------------------------------------
// normalize[x_] := x/Sqrt[norm[x]];
//------------------------------------------------------------------------
Eigen::Matrix<complex,Eigen::Dynamic,Eigen::Dynamic> Normalize(const Eigen::Matrix<complex,Eigen::Dynamic,Eigen::Dynamic>& mat){
	Eigen::Matrix<complex,Eigen::Dynamic,Eigen::Dynamic> res(mat.rows(),mat.cols());
	Eigen::Matrix<complex,Eigen::Dynamic,1>  norm_res(mat.cols());
	norm_res = Norm(mat);
	for(int i=0; i<mat.rows();i++){
		for(int j=0; j<mat.cols();j++){
			res(i,j)=mat(i,j)/std::sqrt(norm_res(i));
		}
	}
	return res;
}
AngularMomentum<complex>Tij(const int& i,const int& j){
//complex Tij(const int& i,const int& j){
 //AngularMomentum<complex> res;
	double const muB =1.3996244936072704;
	 
	double const gI = 0.0009951414;
	double const gS = -2.0023193043622;
	double const gL = -0.99999369; 
	double const omega = 2.*M_PI*6827.9;
	double const Bacx = 0.1;
	double const Bacy = 0.0;
	double const Bacz = 0.0;

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
       
        QM_operator<complex> H1(8,8);
      AngularMomentum<complex> H0(8,8);
H0=h0( 1.22896);
        H1 = (- muB*( gS*(Bacx*Sx+Bacy*Sy+Bacz*Sz)
	   + gI*(Bacx*Ix+Bacy*Iy+Bacz*Iz) 
	   + gL*(Bacx*Lx+Bacy*Ly+Bacz*Lz) ) );

 return Normalize(QuantumEigenVector(H0))*H1*Normalize(QuantumEigenVector(H0)).transpose();
//res = (QuantumEigenVector(H0))*H1*(QuantumEigenVector(H0)).transpose();
//return res(i,j);
}
complex psi(const double& t){
const complex I(0.,1.);
complex res=0.0;
 
AngularMomentum<complex> H0(8,8);
H0=h0( 3.22896);
double const omega = 2.*M_PI*6827.9;
for(int i=0;i<8;i++){
	for(int j=0;j<8;j++)
	{
		res +=exp(-I*(QuantumEigenValue( H0,j)-QuantumEigenValue( H0,i))*t)*cos(omega*t);//*Tij(i,j);
	}
}

//res = QuantumEigenValue( H0,0);
return res;
}
int main()
{
	ElapsedTime time_count; //<--clock stuff
	 
	/*Output of0("output/BFiled");
	time_count.Start();///<--clock stuff again
	AngularMomentum<complex> res;
	for(int i=0;i<=3000;i++)
	{
	  	 res = Hhf(i);
		 res = QuantumEigenValue(res);
	 	 //of0.takeData<<i<<"\t"<<CtoRMateix(res)<<endl;
 	 	 of0.takeData<<CtoRMateix(res)<<endl;
 	 }*/
 	 time_count.Start();
 	 AngularMomentum<complex> res;
 	 //res =H(0);
 	//cout<<CtoRMateix(res)<<endl;
 	//cout<<psi(0)<<endl;
 	//cout<<psi(17)<<endl;
 	res = Tij(0,0);
 	cout<<CtoRMateix(res)<<endl;
	time_count.End();
	return 0;
}

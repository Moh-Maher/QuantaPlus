#include<iostream>
#include<complex>
#include"braket.h"
#include<cmath>
#include<vector>
 #include<fstream>
#include"operators.h"
#include"timer.h"
#include"plt_all.h"
#include <unsupported/Eigen/MatrixFunctions>

	typedef std::complex<double>  complex;
	using std::cout;
	using std::endl;

//---------------------------------------------------------------------------------------------
//
//---------------------------------------------------------------------------------------------
int KroneckerDelta(const int & i, const int & j)
{
	if  (i==j){return (1);}
	else 
	return (0);
}
//---------------------------------------------------------------------------------------------
//Harmonic Oscillator Matrix Elements
//---------------------------------------------------------------------------------------------
QM_operator<complex> HOscillatorMatrixElements(const int& R, const int& C)
{
	QM_operator<complex> H(R,C);
	 
	for(int i=0; i<H.rows(); i++){
		for(int j =0; j<H.cols();j++){
			H(i,j) = (i+1./2.)*KroneckerDelta(i,j); 
		}
	}
	return H;
}

//---------------------------------------------------------------------------------------------
//Position Operator
//---------------------------------------------------------------------------------------------
QM_operator<complex> PositionOperator(const int& R, const int& C)
{
	 
	QM_operator<complex> H(R,C);
	 
	for(int i=0; i<H.rows(); i++){
		for(int j =0; j<H.cols();j++){
			H(i,j) = sqrt(j)*KroneckerDelta(i,j-1) + sqrt(j+1)*KroneckerDelta(i,j+1);
		}
	}
	return H;
}
//---------------------------------------------------------------------------------------------
// Momentum Operator
//---------------------------------------------------------------------------------------------
QM_operator<complex> MomentumOperator(const int& R, const int& C)
{
 
	QM_operator<complex> H(R,C);
 
	for(int i=0; i<H.rows(); i++){
		for(int j =0; j<H.cols();j++){
			H(i,j) = sqrt(j+1)*KroneckerDelta(i,j+1) - sqrt(j)*KroneckerDelta(i,j-1);
		}
	}
	return H;
}
//---------------------------------------------------------------------------------------------
// Lowering Operator
//---------------------------------------------------------------------------------------------
QM_operator<complex> LoweringOperator(const int& R, const int& C)
{ 
	QM_operator<complex> H(R,C);
 
	for(int i=0; i<H.rows(); i++){
		for(int j =0; j<H.cols();j++){
			H(i,j) = sqrt(j)*KroneckerDelta(i,j-1);
		}
	}
	return H;
}
//---------------------------------------------------------------------------------------------
// Rising Operator
//---------------------------------------------------------------------------------------------
QM_operator<complex> RisingOperator(const int& R, const int& C)
{	 
	QM_operator<complex> H(R,C);
 
	for(int i=0; i<H.rows(); i++){
		for(int j =0; j<H.cols();j++){
			H(i,j) = sqrt(j+1)*KroneckerDelta(i,j+1);
		}
	}
	return H;
}

//---------------------------------------------------------------------------------------------
// Hamiltonian 
//---------------------------------------------------------------------------------------------
QM_operator<complex> Hamiltonian(QM_operator<complex> A, QM_operator<complex> B, Bra<complex> coff)
{
	int l = coff.cols();
	QM_operator<complex> res(A.rows(),A.cols());
	QM_operator<complex> a(A.rows(),A.cols());
	a = -0.25 *B.pow(2);

	QM_operator<complex> b(A.rows(),A.cols());
	b = QM_operator<complex>::Zero(A.rows(),A.cols()) ;

	for(int i=0; i<l; i++){
		b += coff[i]*pow(0.5,0.5*i)*A.pow(i);
	}

	res = a + b;
	res.conservativeResize(res.rows()-1, res.cols()-1);
	return res;
}
//---------------------------------------------------------------------------------------------
//Eignvalues
//---------------------------------------------------------------------------------------------
Eigen::Matrix<complex,Eigen::Dynamic,Eigen::Dynamic> eval(QM_operator<complex>& A)
{
	return QuantumEigenValue(A);
}
//---------------------------------------------------------------------------------------------
//Eignvectors 
//---------------------------------------------------------------------------------------------
Eigen::Matrix<complex,Eigen::Dynamic,Eigen::Dynamic> evec(QM_operator<complex>& A)
{
	return QuantumEigenVector(A);
}
//---------------------------------------------------------------------------------------------
//Eignvectors
//---------------------------------------------------------------------------------------------
Eigen::Matrix<complex,Eigen::Dynamic,Eigen::Dynamic> evec(const QM_operator<complex>& A, const QM_operator<complex>& B, const Bra<complex>& coff)
{
	QM_operator<complex> res = Hamiltonian(A,B,coff);
	return QuantumEigenVector(res);
}

//---------------------------------------------------------------------------------------------
//
//---------------------------------------------------------------------------------------------
std::size_t Factorial(const std::size_t& n)
{
        return n == 0? 1 : n * Factorial(n-1);
}
//---------------------------------------------------------------------------------------------
// wave_function
//---------------------------------------------------------------------------------------------
double wave_function(const int& n,const double& x)
{ 
	return (1./pow(M_PI,0.25)) *(1/(sqrt(pow(2,n))*Factorial(n)))*std::hermite(n,x)*exp(-pow(x,2)/2.);
}
//---------------------------------------------------------------------------------------------
//coefficients
//---------------------------------------------------------------------------------------------
std::vector<complex> coefficients(const QM_operator<complex>& A, const QM_operator<complex> &B,const Bra<complex> &coff, const int& n)
{	
	Eigen::Matrix<complex,Eigen::Dynamic,Eigen::Dynamic> Evec;
	std::vector<complex> ci;
	Evec = evec(A,B,coff);
	for(int i =0; i<Evec.rows();i++){
		ci.push_back( Evec(i,n));
	}

	return ci;
}
//---------------------------------------------------------------------------------------------
//wave_function_H
//---------------------------------------------------------------------------------------------
complex  wave_function_H(const QM_operator<complex>& A, const QM_operator<complex> &B, const Bra<complex> &coff, const double& x, const int& n)
{ 	
	std::vector<complex> ci;
	ci = coefficients(A,B,coff,n);
	complex res=0.0;

	for(int i=0; i<ci.size(); i++){
		res += ci[i]*wave_function(i,x);
	}
	return res;
}

int main()
{ 
	ElapsedTime time_count;
	
	using namespace std::complex_literals;
	/*
	QM_operator<complex> H(4,4); 
	QM_operator<complex> X(4,4);
	 
	QM_operator<complex> P(4,4);
	QM_operator<complex> A(4,4); 
	QM_operator<complex> Ad(4,4); 
	
        H = HOscillatorMatrixElements(4,4);
        X = PositionOperator(4,4);
        P = MomentumOperator(4,4);
        A = LoweringOperator(4,4);
        Ad = RisingOperator(4,4);
		//cout<<"-----------\n";
	 
	cout<<"-----[Harmonic Oscillator Matrix Elements]------\n";
	ResultPrint(H);
	cout<<"-----[Position Operator ]------\n";
	ResultPrint(X);
	cout<<"-----[ Momentum Operator ]------\n";
 	 
 	ResultPrint(P);
	cout<<"-----[ Lowering Operator]------\n";
 	ResultPrint(A);
 	cout<<"-----[ Rising Operator ]------\n";
 	ResultPrint(Ad);
 	 */
 time_count.Start();
 	int N =5;// 21;
  	QM_operator<complex> plus(N,N), minus(N,N), res(N,N);
 	plus = RisingOperator(N,N) + LoweringOperator(N,N);
 	minus =  LoweringOperator(N,N) - RisingOperator(N,N) ;
 	Bra<complex> ll(3);
 	ll<<0.,0.,0.5;
 	res = Hamiltonian(plus,minus,ll);
 	ResultPrint(res);
 	cout<<"-----------\n";
 	/*cout<<eval(res);
 	cout<<endl;
 	cout<<"-----------\n";
 	cout<<evec(res);
 	cout<<endl;*/
 	std::ofstream outfile1;
 	std::ofstream outfile2;
	std::string output_path1 ("phi0A.dat"); ///<-- path to the output file and its name.
	std::string output_path2 ("phi0B.dat");
	 
	outfile1.open(output_path1);///<-- open the input file to read the data.
 
	outfile2.open(output_path2);///<-- open the input file to read the data.
 
	
 	cout<<"------ Old wave_function-----\n";
 	for(int i=-5;i<=5;i++){
 	//cout<<wave_function(1,i)<<endl;
 	outfile1<<i<<"\t"<<wave_function(2,i)<<endl;
 	//cout<<wave_function_H(plus,minus,ll,i,0)<<endl;
	}
	outfile1.close();
	cout<<"------New wave_function-----\n";
 	for(int i=-5;i<=5;i++){
 	//cout<<wave_function(0.,i)<<endl;
 	outfile2<<i<<"\t"<<std::real(wave_function_H(plus,minus,ll,i,2))<<endl;
	}
	outfile2.close();
time_count.End();
	
	plot_phi0() ;
	
	
}

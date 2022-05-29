#include<iostream>
#include<complex>
#include"braket.h"
#include"operators.h"
#include<ctime>  
#include"utilities.h"
#include"latex.h"
using namespace std;
 
 
int main()
{
	using namespace std::complex_literals; //needed to use the literal imaginary unit [ 1i = (0,1)] 
  

 	ket<std::complex<double>> ktA(3),ktB(3), OktA(3);
	QM_operator<std::complex<double>> O(3,3);
	bra<std::complex<double>> brA(3), brB(3); 
	std::complex<double> AOA;
 	
 
	 
	ktA <<-1.+1i, 3, 2.+3i; 
	brA << 6., -1i, 5;
	 
	O <<5., 3.+2i, 3i , -1i, 3i, 8., 1.-1i, 1., 4.;
	
        OktA<< O * ktA;
        AOA = brA * OktA;
	latex mypdf("doc.tex");
	mypdf.begin();
	mypdf.operation("tbok=n","\\bra{\\phi}A\\ket{\\psi}= ",brA,O,ktA,'=',AOA);
	mypdf.end();
return 0;
}

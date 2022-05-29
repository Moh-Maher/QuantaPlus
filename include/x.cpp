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
	std::complex<double> AOA,braketAB,braketBA,braketAA,braketBB;
 	
 
	 
	ktA <<-1.+1i, 3, 2.+3i; 
	brA = DualConj(ktA);
	 
	brB << 6., -1i, 5;
	ktB = DualConj(brB); 
	O <<5., 3.+2i, 3i , -1i, 3i, 8., 1.-1i, 1., 4.;
	
	
        OktA << O * ktA;
        AOA = brB * OktA;
        braketBA = brB*ktA;
        braketBB = brB*ktB;
 
        braketAA = brA*ktA;
        braketAB = brA*ktB;
        
	latex mypdf("doc.tex");
	mypdf.begin();
	mypdf.operation("tktbto","\\ket{\\psi} = ",ktA,", \\bra{\\phi} = ",brB,", A = ",O);
	mypdf.operation("tok=k","A\\ket{\\psi} = ",O,ktA,'=',OktA);
	mypdf.operation("tbok=n","\\bra{\\phi}A\\ket{\\psi}= ",brB,O,ktA,'=',AOA);
	mypdf.operation("tbk=n","\\braket{\\psi|\\phi}= ",brA,ktB,'=',braketAB);
	mypdf.operation("tbk=n","\\braket{\\phi|\\psi}= ",brB,ktA,'=',braketBA);
	mypdf.operation("tbk=n","\\braket{\\psi|\\psi}= ",brA,ktA,'=',braketAA);
	mypdf.operation("tbk=n","\\braket{\\phi|\\phi}= ",brB,ktB,'=',braketBB);
	mypdf.end();
return 0;
}

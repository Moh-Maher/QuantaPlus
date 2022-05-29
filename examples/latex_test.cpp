/*******************************************************************************************
testing "braket.h".
by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#include<iostream>
#include<complex>
#include"braket.h"
#include"operators.h"
#include<ctime>  
#include"utilities.h"
#include"latex.h"
 
	typedef std::complex<double>  complex;
	using std::cout;
	using std::endl;

int main()
{ 
	///<--clock stuff
	std::clock_t start;
	double duration;
 	start = std::clock();
 
	using namespace std::complex_literals; //needed to use the literal imaginary unit [ 1i = (0,1)] 
  

 	ket<std::complex<double>> psi_ket(3),phi_ket(3), A_TIMS_psi_ket(3);
	QM_operator<std::complex<double>> A(3,3);
	bra<std::complex<double>> psi_bra(3), phi_bra(3); 
	
	std::complex<double> AOA, brapsi_phi_ket, braphi_ketA ,brapsi_ketA, braphi_ketB;
 	
 
	 
	psi_ket <<-1.+1i, 3, 2.+3i; 
	psi_bra = DualConj(psi_ket);
	 
	phi_bra << 6., -1i, 5;
	phi_ket = DualConj(phi_bra); 
	A <<5., 3.+2i, 3i , -1i, 3i, 8., 1.-1i, 1., 4.;
	
	
        A_TIMS_psi_ket << A * psi_ket;
        AOA = phi_bra * A_TIMS_psi_ket;
        braphi_ketA = phi_bra*psi_ket;
        braphi_ketB = phi_bra*phi_ket;
 
        brapsi_ketA = psi_bra*psi_ket;
        brapsi_phi_ket = psi_bra*phi_ket;
        
	latex mypdf("output/latex_results.tex");
	mypdf.begin();
	mypdf.operation("tktbto","\\ket{\\psi} = ",psi_ket,", \\bra{\\phi} = ",phi_bra,", A = ",A);
	mypdf.operation("tok=k","A\\ket{\\psi} = ",A,psi_ket,'=',A_TIMS_psi_ket);
	mypdf.operation("tbok=n","\\bra{\\phi}A\\ket{\\psi}= ",phi_bra,A,psi_ket,'=',AOA);
	mypdf.operation("tbk=n","\\braket{\\psi|\\phi}= ",psi_bra,phi_ket,'=',brapsi_phi_ket);
	mypdf.operation("tbk=n","\\braket{\\phi|\\psi}= ",phi_bra,psi_ket,'=',braphi_ketA);
	mypdf.operation("tbk=n","\\braket{\\psi|\\psi}= ",psi_bra,psi_ket,'=',brapsi_ketA);
	mypdf.operation("tbk=n","\\braket{\\phi|\\phi}= ",phi_bra,phi_ket,'=',braphi_ketB);
	mypdf.end();
	
	
    	///<--clock to measure execution time for gauging performance 
	duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
 
	if (duration < 60.0) {
		std::cout << "Elapsed time: " << duration << " seconds" << std::endl;
	}
 
	else {
		std::cout << "Elapsed time: " << duration/60.0 << " mins" << std::endl;
	}
    	 
	return 0;
}

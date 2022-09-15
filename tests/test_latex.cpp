/*******************************************************************************************
testing "latex.h".
by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
#include<iostream>
#include<complex>
#include<ctime>  
#include"../quantaplus/braket.h"
#include"../quantaplus/angularmomentum.h"
#include"../quantaplus/utilities.h"
#include"../quantaplus/latex.h"
#include"../quantaplus/timer.h"
using namespace QuantaPlus;
	typedef std::complex<double>  complex;
	using std::cout;
	using std::endl;

int main()
{ 
	ElapsedTime time_count; //<--clock stuff
	time_count.Start();

 
	using namespace std::complex_literals; //needed to use the literal imaginary unit [ 1i = (0,1)] 
  

 	Ket<std::complex<double>> psi_Ket(3),phi_Ket(3), A_TIMS_psi_Ket(3);
	QM_operator<std::complex<double>> A(3,3);
	Bra<std::complex<double>> psi_Bra(3), phi_Bra(3); 
	
	std::complex<double> AOA, Brapsi_phi_Ket, Braphi_KetA ,Brapsi_KetA, Braphi_KetB;
 	
 
	 
	psi_Ket <<-1.+1i, 3, 2.+3i; 
	psi_Bra = DualConj(psi_Ket);
	 
	phi_Bra << 6., -1i, 5;
	phi_Ket = DualConj(phi_Bra); 
	A <<5., 3.+2i, 3i , -1i, 3i, 8., 1.-1i, 1., 4.;
	
	
        A_TIMS_psi_Ket << A * psi_Ket;
        AOA = phi_Bra * A_TIMS_psi_Ket;
        Braphi_KetA = phi_Bra*psi_Ket;
        Braphi_KetB = phi_Bra*phi_Ket;
 
        Brapsi_KetA = psi_Bra*psi_Ket;
        Brapsi_phi_Ket = psi_Bra*phi_Ket;
        
	//LaTex mypdf("output/latex_results.tex");
	
	LaTex mypdf("latex_results.tex");
	mypdf.BeginLaTex();
	//mypdf.ToLaTex("k",psi_Ket);
	
	mypdf.MathOperation("tktbto","\\ket{\\psi} = ",psi_Ket,", \\bra{\\phi} = ",phi_Bra,", A = ",A);
	mypdf.MathOperation("tok=k","A\\ket{\\psi} = ",A,psi_Ket,'=',A_TIMS_psi_Ket);
	mypdf.MathOperation("tbok=n","\\bra{\\phi}A\\ket{\\psi}= ",phi_Bra,A,psi_Ket,'=',AOA);
	mypdf.MathOperation("tbk=n","\\braket{\\psi|\\phi}= ",psi_Bra,phi_Ket,'=',Brapsi_phi_Ket);
	mypdf.MathOperation("tbk=n","\\braket{\\phi|\\psi}= ",phi_Bra,psi_Ket,'=',Braphi_KetA);
	mypdf.MathOperation("tbk=n","\\braket{\\psi|\\psi}= ",psi_Bra,psi_Ket,'=',Brapsi_KetA);
	mypdf.MathOperation("tbk=n","\\braket{\\phi|\\phi}= ",phi_Bra,phi_Ket,'=',Braphi_KetB);
	
	mypdf.EndLaTex();
	
	time_count.End();
    	 
	return 0;
}

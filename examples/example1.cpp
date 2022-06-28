/*-------------------------------------------------------------------------------------------------------------------------------------------

# This file provides solutions for Exercise 5.29 of [N. Zettili, “Quantum Mechanics, Concepts and Applications,” Wiley, Chichester, 2001.]  


#=> Consider a particle of angular momentum j = 3/2:

# (a) Find the matrices representing the operator: J^2, J_X, J_y and J_z in the { |3./2., m> } basis.

# (b) Using these matrices, show that J_X, J_y , J_z satisfy the commutator: [J_x, J_y] = i* J_z.

# (c) Calculate the mean values of J_x and (J_x)^2 with respect to the state | Ket > = {0, 0, 1, 0}.

# (d) Calculate Delta(J_x), Dlta(J_y) with respect to the state | Ket > = {0, 0, 1, 0},
# and verify that this product satisfies Heisenberg’s uncertainty principle.
--------------------------------------------------------------------------------------------------------------------------------------------*/
#include<iostream>
#include<complex>
#include"angularmomentum.h"  //  Angular Momentum Operators
#include"braket.h" // BraKet vectors
#include"latex.h"
#include"utilities.h"
#include"timer.h"


	using std::cout;
	using std::endl;
	typedef std::complex<double>  complex;

 
int main()
{       
	ElapsedTime time_count; //<--clock stuff
	time_count.Start();
	
	const double j = 3./2.; ///<--- j = 3./2. or 1.5

	AngularMomentum<complex> J2, J_x, J_y, J_z;

	J2  = J2.AngularMomentum_JSquare( j ); // J^2
	J_x = J_x.AngularMomentum_Jx( j );
	J_y = J_y.AngularMomentum_Jy( j );
	J_z = J_z.AngularMomentum_Jz( j );

	cout<<"*****************************************************************************************************\n";
	cout<<"#=> Consider a particle of angular momentum j = 3/2:\n";
	cout<<"# (a) Find the matrices representing the operator: J^2, J_X, J_y and J_z in the { |3./2., m> } basis.\n";
	cout<<"# (b) Using these matrices, show that J_X, J_y , J_z satisfy the commutator: [J_x, J_y] = i* J_z.\n";
	cout<<"# (c) Calculate the mean values of J_x and (J_x)^2 with respect to the state | Ket > = {0, 0, 1, 0}.\n";
	cout<<"# (d) Calculate Delta(J_x), Dlta(J_y) with respect to the state | Ket > = {0, 0, 1, 0},\n";
	cout<<"# and verify that this product satisfies Heisenberg’s uncertainty principle.\n";
	cout<<"*****************************************************************************************************\n";
	cout<<"##########################################################################################\n";
	cout<<"(a) matrices representing the operator: J^2, J_X, J_y and J_z in the { |3./2., m> } basis.\n";
	cout<<"##########################################################################################\n";

	cout<<"------------------[J^2]----------------------\n";

	ResultPrint(J2);

	cout<<"------------------[J_x]----------------------\n";
	ResultPrint(J_x);

	cout<<"------------------[J_y]----------------------\n";
	ResultPrint(J_y);

	cout<<"------------------[J_z]----------------------\n";
	ResultPrint(J_z);

	cout<<"######################################################################################\n";
	cout<<"############### (b) RHS result of the commutator: [J_x, J_y] = i* J_z ################\n";
	cout<<"######################################################################################\n";
	QM_operator<complex> commutatorJxJy((int)J_z.rows(),(int)J_z.cols());
	commutatorJxJy<<Commute(J_x, J_y);
	ResultPrint(commutatorJxJy);

	cout<<"######################################################################################\n";
	cout<<"##### (c) <J_x> and <(J_x)^2> with respect to the state | Ket > = {0, 0, 1, 0}:  #####\n";
	cout<<"######################################################################################\n";
	cout<<"------------------ <J_x> ----------------------\n";

	complex Jx_MeanVal;

	Ket<complex> KetState(4); //Jx_Ket(4);
	//Bra<complex> BraState(4);
	KetState<<0., 0., 1., 0.;
	//BraState = DualConj(KetState); //<------<Bra|: Dual conjugate of the given |Ket >.
	//Jx_Ket << J_x * KetState;       //<------------Action of  J_X  on the given |Ket >.
	Jx_MeanVal = ExpectValue(J_x,KetState);//BraKet( BraState , Jx_Ket );//<--------- J_X mean value: <Jx> = <Bra|J_x|Ket>.

	cout<<"<J_x>= "<<Jx_MeanVal<<endl;

	cout<<"------------------<(J_x)^2> ----------------------\n";
	complex JxSqr_MeanVal;
	AngularMomentum<complex> J_xSqr(4,4);
	Ket<complex> Jx_Sqr_Ket(4);

	J_xSqr << J_x * J_x;
	//Jx_Sqr_Ket << J_xSqr*KetState; //<------------Action of (J_X)^2 on the given |Ket >.
	//Jx_Sqr_Ket = KetState; 
	JxSqr_MeanVal = ExpectValue(J_xSqr,KetState);//BraKet( BraState , Jx_Sqr_Ket );//<--------- (J_X)^2 mean value: <(Jx)^2> = <Bra|(J_x)^2|Ket>.

	cout<<"<(J_x)^2> = ";
	ResultPrint(JxSqr_MeanVal);
	cout<<endl;

	cout<<"######################################################################################\n";
	cout<<"### (D) Delta J_x and Delta J_y with respect to the state | Ket > = {0, 0, 1, 0}.  ###\n";
	cout<<"######################################################################################\n";
	cout<<"------------------Delta J_x----------------------\n";
	complex delta_Jx(0,0);

	delta_Jx = sqrt(JxSqr_MeanVal - pow( Jx_MeanVal , 2) );
cout<<"Delta J_x= ";ResultPrint(delta_Jx);cout<<endl;

	//--------------------------------------------------------J_y---------------------------------------------------------------
	cout<<"------------------Delta J_y----------------------\n";
	complex Jy_MeanVal;
	//Ket<complex>  Jy_Ket(4);

	//Jy_Ket << J_y * KetState;
	Jy_MeanVal = ExpectValue(J_y,KetState);//BraKet( BraState , Jy_Ket ); //<--------- J_y mean value: <Jx> = <Bra|J_y|Ket>.

	cout<<"<J_y>= ";
	ResultPrint(Jy_MeanVal);
	cout<<endl;

	//cout<<"######################################################################################\n";
	//cout<<"############# <(J_y)^2> with respect to the state | Ket > = {0, 0, 1, 0}:  ###########\n";
	//cout<<"######################################################################################\n";
	complex JySqr_MeanVal;
	AngularMomentum<complex> J_ySqr(4,4);
	//Ket<complex> Jy_Sqr_Ket(4);

	J_ySqr << J_y * J_y;
	//Jy_Sqr_Ket << J_ySqr * KetState;

	JySqr_MeanVal = ExpectValue(J_ySqr,KetState);//BraKet( BraState , Jy_Sqr_Ket ); //<--------- (J_y)^2 mean value: <(Jx)^2> = <Bra|(J_y)^2|Ket>.

	//cout<<"<(J_y)^2>= "<<JySqr_MeanVal<<endl;

	complex delta_Jy(0,0);

	delta_Jy = sqrt(JySqr_MeanVal - pow( Jy_MeanVal , 2) );
	cout<<"Delta J_y= ";ResultPrint(delta_Jy);cout<<endl;
	/*
	cout<<"######################################################################################\n";
	cout<<"##################  Delta J_x * Delta J_y >= 1/2 * |<[ J_x, J_y]>|:  #################\n";
	cout<<"######################################################################################\n";
	complex lhs(0.,0.), rhs(0.,0.);

	cout<<"------------LHS:-----------\n";
	lhs = delta_Jx *delta_Jy;
	//lhs ={0,0};
	cout<<"Delta J_x * Delta J_y ="<<lhs<<endl;
	cout<<"------------RHS:-----------\n";
	rhs = 0.5*abs( ExpectValue(commutatorJxJy , KetState ) ); //<--- |<[ J_x, J_y]>|.
	cout<<"1/2 * |<[ J_x, J_y]>|= "<<rhs<<endl;
	if(std::real(lhs) >= std::real(rhs)) {cout<<"satisfies Heisenberg’s uncertainty principle!\n";}
	*/
	
	LaTex mypdf("output/example1.tex");
	
	
	mypdf.BeginLaTex();
	mypdf.Typing("(a) matrices representing the operator: $J^2, J_X, J_y$ and $J_z$ in the $\\ket{3/2, m}$ basis.");
	mypdf.MathOperation("to","J^2 = ",J2);
	mypdf.MathOperation("to","J_x = ",J_x);
	mypdf.MathOperation("to","J_y = ",J_y);
	mypdf.MathOperation("to","J_z = ",J_z);
	mypdf.Typing("(b) RHS result of the commutator: $[J_x,J_y]=i*J_z$");
	mypdf.MathOperation("to","[J_x,J_y] = ",commutatorJxJy);
	mypdf.Typing("(c) $<J_x>$ and $<(J_x)^2>$ with respect to the state $\\Ket{\\psi} = (0, 0, 1, 0)$:");
	mypdf.MathOperation("tn","<J_x> = ",Jx_MeanVal);
	mypdf.MathOperation("tn","<J_x^2> = ",JxSqr_MeanVal);
	mypdf.Typing("(d) $\\delta J_x$ and $\\delta J_y$ with respect to the state $\\Ket{\\psi} = (0, 0, 1, 0)$:");
	mypdf.MathOperation("tn"," \\delta J_x = ",delta_Jx);
	mypdf.MathOperation("tn"," \\delta J_y = ",delta_Jy);
	mypdf.EndLaTex();
	
	///<--clock stuff again
	time_count.End();
	return 0;
}

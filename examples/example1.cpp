/*-------------------------------------------------------------------------------------------------------------------------------------------

# This file provides solutions for Exercise 5.29 of [N. Zettili, “Quantum Mechanics, Concepts and Applications,” Wiley, Chichester, 2001.]  


#=> Consider a particle of angular momentum j = 3/2:

# (a) Find the matrices representing the operator: J^2, J_X, J_y and J_z in the { |3./2., m> } basis.

# (b) Using these matrices, show that J_X, J_y , J_z satisfy the commutator: [J_x, J_y] = i* J_z.

# (c) Calculate the mean values of J_x and (J_x)^2 with respect to the state | ket > = {0, 0, 1, 0}.

# (d) Calculate Delta(J_x), Dlta(J_y) with respect to the state | ket > = {0, 0, 1, 0},
# and verify that this product satisfies Heisenberg’s uncertainty principle.
--------------------------------------------------------------------------------------------------------------------------------------------*/
#include<iostream>
#include<complex>
#include"operators.h"  //  Angular Momentum Operators
#include"braket.h" // braket vectors
 


	using std::cout;
	using std::endl;
	typedef std::complex<double>  complex;

 
int main()
{
	const double j = 3./2.; ///<--- j = 3./2. or 1.5

	Angular_Momentum<complex> J2, J_x, J_y, J_z;

	J2  = J2.Angular_Momentum_OperatorJSqr( j ); // J^2
	J_x = J_x.Angular_Momentum_OperatorJx( j );
	J_y = J_y.Angular_Momentum_OperatorJy( j );
	J_z = J_z.Angular_Momentum_OperatorJz( j );

	cout<<"*****************************************************************************************************\n";
	cout<<"#=> Consider a particle of angular momentum j = 3/2:\n";
	cout<<"# (a) Find the matrices representing the operator: J^2, J_X, J_y and J_z in the { |3./2., m> } basis.\n";
	cout<<"# (b) Using these matrices, show that J_X, J_y , J_z satisfy the commutator: [J_x, J_y] = i* J_z.\n";
	cout<<"# (c) Calculate the mean values of J_x and (J_x)^2 with respect to the state | ket > = {0, 0, 1, 0}.\n";
	cout<<"# (d) Calculate Delta(J_x), Dlta(J_y) with respect to the state | ket > = {0, 0, 1, 0},\n";
	cout<<"# and verify that this product satisfies Heisenberg’s uncertainty principle.\n";
	cout<<"*****************************************************************************************************\n";
	cout<<"##########################################################################################\n";
	cout<<"(a) matrices representing the operator: J^2, J_X, J_y and J_z in the { |3./2., m> } basis.\n";
	cout<<"##########################################################################################\n";

	cout<<"------------------[J^2]----------------------\n";

	cplx_show(J2);

	cout<<"------------------[J_x]----------------------\n";
	cplx_show(J_x);

	cout<<"------------------[J_y]----------------------\n";
	cplx_show(J_y);

	cout<<"------------------[J_z]----------------------\n";
	cplx_show(J_z);

	cout<<"######################################################################################\n";
	cout<<"############### (b) RHS result of the commutator: [J_x, J_y] = i* J_z ################\n";
	cout<<"######################################################################################\n";
	QM_operator<complex> commutatorJxJy(J_x.rows(),J_x.cols());
	commutatorJxJy<<Commute(J_x, J_y);
	cplx_show(commutatorJxJy);
  
 
	cout<<"######################################################################################\n";
	cout<<"##### (c) <J_x> and <(J_x)^2> with respect to the state | ket > = {0, 0, 1, 0}:  #####\n";
	cout<<"######################################################################################\n";
	cout<<"------------------ <J_x> ----------------------\n";

	complex Jx_MeanVal;

	ket<complex> KetState(4), Jx_Ket(4);
	bra<complex> braState(4);
	KetState<<0., 0., 1., 0.;
	braState = DualConj(KetState); //<------<bra|: Dual conjugate of the given |ket >.
	Jx_Ket << J_x * KetState;       //<------------Action of  J_X  on the given |ket >.
	Jx_MeanVal = BraKet( braState , Jx_Ket );//<--------- J_X mean value: <Jx> = <bra|J_x|ket>.

	cout<<"<J_x>= "<<Jx_MeanVal<<endl;

	cout<<"------------------<(J_x)^2> ----------------------\n";
	complex JxSqr_MeanVal;
	Angular_Momentum<complex> J_xSqr(4,4);
	ket<complex> Jx_Sqr_Ket(4);

	J_xSqr << J_x * J_x;
	Jx_Sqr_Ket << J_xSqr*KetState; //<------------Action of (J_X)^2 on the given |ket >.
	//Jx_Sqr_Ket = KetState; 
	JxSqr_MeanVal = BraKet( braState , Jx_Sqr_Ket );//<--------- (J_X)^2 mean value: <(Jx)^2> = <bra|(J_x)^2|ket>.

	cout<<"<(J_x)^2> = ";
	cplx_show(JxSqr_MeanVal);
	cout<<endl;

	cout<<"######################################################################################\n";
	cout<<"### (D) Delta J_x and Delta J_y with respect to the state | ket > = {0, 0, 1, 0}.  ###\n";
	cout<<"######################################################################################\n";
	cout<<"------------------Delta J_x----------------------\n";
	complex delta_Jx(0,0);

	delta_Jx = sqrt(JxSqr_MeanVal - pow( Jx_MeanVal , 2) );
	cout<<"Delta J_x= ";cplx_show(delta_Jx);cout<<endl;
	//--------------------------------------------------------J_y---------------------------------------------------------------
	cout<<"------------------Delta J_y----------------------\n";
	complex Jy_MeanVal;
	ket<complex>  Jy_Ket(4);

	Jy_Ket << J_y * KetState;
	Jy_MeanVal = BraKet( braState , Jy_Ket ); //<--------- J_y mean value: <Jx> = <bra|J_y|ket>.

	cout<<"<J_y>= ";
	cplx_show(Jy_MeanVal);
	cout<<endl;

	//cout<<"######################################################################################\n";
	//cout<<"############# <(J_y)^2> with respect to the state | ket > = {0, 0, 1, 0}:  ###########\n";
	//cout<<"######################################################################################\n";
	complex JySqr_MeanVal;
	Angular_Momentum<complex> J_ySqr(4,4);
	ket<complex> Jy_Sqr_Ket(4);

	J_ySqr << J_y * J_y;
	Jy_Sqr_Ket << J_ySqr * KetState;

	JySqr_MeanVal = BraKet( braState , Jy_Sqr_Ket ); //<--------- (J_y)^2 mean value: <(Jx)^2> = <bra|(J_y)^2|ket>.

	//cout<<"<(J_y)^2>= "<<JySqr_MeanVal<<endl;

	complex delta_Jy(0,0);

	delta_Jy = sqrt(JySqr_MeanVal - pow( Jy_MeanVal , 2) );
	cout<<"Delta J_y= ";cplx_show(delta_Jy);cout<<endl;
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
	return 0;
}

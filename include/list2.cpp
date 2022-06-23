#include<iostream>
#include<cmath>
#include"utilities.h"
#include"operators.h"
#include<vector>
#include<list>
#include <functional>
using namespace std;
using namespace Eigen;
 
 //cout << "The eigenvalues of A are:" << endl << es.eigenvalues() << endl;
 //cout << "The matrix of eigenvectors, V, is:" << endl << es.eigenvectors() << endl << endl;
template<typename T>
Matrix<complex<T>,Dynamic,Dynamic> EigenVector(Matrix<T,Dynamic,Dynamic>& mat )
{
	EigenSolver<Matrix<T,Dynamic,Dynamic>> es(mat);
	//return es.eigenvectors().rowwise().reverse().transpose();
	return es.eigenvectors();
}
template<typename T>
Matrix<complex<T>,Dynamic,Dynamic> EigenValue(Matrix<T,Dynamic,Dynamic>& mat)
{ 
	EigenSolver<Matrix<T,Dynamic,Dynamic>> es(mat);
	
	return es.eigenvalues();
}
 
template<typename T>
int Sign(T& n){
 return ( n >= 0 ) ? 1: -1;
}
struct ketstate{ 
	double J1,M1,J2,M2;
	double factor=1.0;
	ketstate(){}
	ketstate(const double& j1, const double& m1,const double& j2,  const double& m2)
			:J1(j1),M1(m1),J2(j2),M2(m2){}
	void PrintF(){
			if(factor==1.0){
				cout<<"AMuket["<<J1<<", "<<M1<<", "<<J2<<", "<<M2<<"]\n";
			}
			else if(factor==0){cout<<0<<"\n";}
			else{
				DecimalToFraction(factor);cout<<" AMuket["<<J1<<", "<<M1<<", "<<J2<<", "<<M2<<"]\n";
				//cout<<factor<<" AMuket["<<J1<<", "<<M1<<", "<<J2<<", "<<M2<<"]\n";
			}   
		}
	void PrintFketstate_List(const std::vector<ketstate>& kl){ 
			for (auto n : kl) {
				n.PrintF();
			}
			std::cout <<"\n";
		}
		friend int operator* (const ketstate& kts1 , const ketstate& kts2);
		 ketstate operator + (const ketstate &kt);
		 bool operator == (ketstate& fv){

        	if ( (J1==fv.J1) && (J2==fv.J2) && (M1==fv.M1) && (M2==fv.M2) && factor == fv.factor )
        	{return true;}
        	else
            		return false;
        	}

};
inline ketstate  ketstate::operator + (const ketstate &kt) 
{
   ketstate res(kt);//=*this;
 
            if ((J1==kt.J1) && (J2==kt.J2) && (M1==kt.M1) && (M2==kt.M2))
  		{
  	    res.factor =this->factor+ kt.factor;
  
   		}
   return res;   
}
//------------------------------------------------------------------------
//AMuket /: AMuket[j1_, m1_, j2_, m2_] AMuket[j1p_, m1p_, j2p_, m2p_] = 0; /;
//  (j1 =!= j1p) || (m1 =!= m1p) || (j2 =!= j2p) || (m2 =!= m2p);
//AMuket /: AMuket[j1_, m1_, j2_, m2_] AMuket[j1_, m1_, j2_, m2_] = 1;
//AMuket /: Power[AMuket[j1_, m1_, j2_, m2_], 2] = 1;
//------------------------------------------------------------------------
int operator* (const ketstate& kts1 , const ketstate& kts2)
{
     int n=1;
     if((kts1.J1!=kts2.J1) || (kts1.J2!=kts2.J2) ||  (kts1.M1!=kts2.M1) ||  (kts1.M2!=kts2.M2) ){n=0;}
    
      return n;
}
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
class Basis:public ketstate{
	public:
		double J1,M1,J2,M2;
		//double factor=1.0;
		std::vector<ketstate> ketstate_list;
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
		Basis(){}
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
		Basis(const double& j1, const double& j2):J1(j1),J2(j2) {
			setketstate_list();
		}
		Basis(const double& j1, const double& m1,const double& j2,  const double& m2)
			 :J1(j1),M1(m1),J2(j2),M2(m2){
			 ketstate(J1,M1, J2, M2);
			 }
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
		void PrintF(){
			ketstate::PrintF();
		}
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
		void setketstate_list(){
			for(auto i=0.; i<=int(2);i+=J1){
				for(auto j=0.; j<=int(2);j+=J2){
				ketstate_list.push_back(ketstate(J1,J1-i,J2,J2-j) );	 
				}
			}
		}
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
		void PrintFketstate_List(){
			ketstate::PrintFketstate_List(ketstate_list);
		}	
};
//------------------------------------------------------------------------
//AM /: AM[j12] AMuket[j1_, m1_, j2_, m2_] := j1 (j1 + 1) AMuket[j1, m1, j2, m2];
//------------------------------------------------------------------------
ketstate J12(const ketstate& b){
       	 
	ketstate res = b;
	res.factor=  b.factor*b.J1*(b.J1+1.);
	return res;    
}
////-------overloaded for basis
std::vector<ketstate> J12(const Basis& b){
       
    std::vector<ketstate> res;
	for(auto n : b.ketstate_list) {
		n.factor=  b.factor*n.J1*(n.J1+1.);
		res.push_back(n);
	}
    return res;    
}
//------------------------------------------------------------------------
//AM /: AM[j1z] AMuket[j1_, m1_, j2_, m2_] := m1*AMuket[j1, m1, j2, m2];
//------------------------------------------------------------------------
ketstate J1z(const ketstate& b){  
    	ketstate res = b; 
	res.factor=  b.factor*b.M1;
     	return res;      
}
////-------overloaded for basis
std::vector<ketstate> J1z(const Basis& b){  
    	std::vector<ketstate> res;
	for(auto n : b.ketstate_list) {
		n.factor=  b.factor*n.M1;
		res.push_back(n);
	}
     	return res;      
}
//------------------------------------------------------------------------
//AM /: AM[j1p] AMuket[j1_, m1_, j2_, m2_] := Sqrt[j1 (j1 + 1) - m1 (m1 + 1)] AMuket[j1, m1 + 1, j2, m2];
//------------------------------------------------------------------------
ketstate J1p(const ketstate& b){
	
	ketstate res = b;	 
		res.factor= b.factor*std::sqrt( std::abs(((b.J1 - b.M1))*(b.J1+b.M1+1.)) );
		res.M1 +=1.; 
     	return res; 
}
////-------overloaded for basis
std::vector<ketstate> J1p(const Basis& b){
	
	std::vector<ketstate> res ;// b.ketstate_list;
	for(auto n : b.ketstate_list) {
		n.factor= b.factor*std::sqrt( std::abs(((n.J1 - n.M1))*(n.J1+n.M1+1.)) );
		n.M1 +=b.M1+1.; 		
		res.push_back(n);
	}
     	return res; 
}
//------------------------------------------------------------------------
//AM /: AM[j1m] AMuket[j1_, m1_, j2_, m2_] := Sqrt[j1 (j1 + 1) - m1 (m1 - 1)] AMuket[j1, m1 - 1, j2, m2];
//------------------------------------------------------------------------
ketstate J1m(const ketstate& b){
	
	ketstate res = b;	 
		res.factor= b.factor*std::sqrt( std::abs(((b.J1 + b.M1))*(b.J1-b.M1+1.)) );
		res.M1 -=1.; 	
     	return res; 
}
////-------overloaded for basis
std::vector<ketstate> J1m(const Basis& b){
	
	std::vector<ketstate> res ;// b.ketstate_list;
	for(auto n : b.ketstate_list) {
		n.factor= b.factor*std::sqrt( std::abs(((n.J1 + n.M1))*(n.J1-n.M1+1.)) );
		n.M1 +=b.M1-1.; 
		res.push_back(n);
	}
     	return res; 
}

//------------------------------------------------------------------------
//AM /: AM[j22] AMuket[j1_, m1_, j2_, m2_] := j2 (j2 + 1) AMuket[j1, m1, j2, m2];
//------------------------------------------------------------------------
ketstate J22(const ketstate& b){
       	 
	ketstate res = b;
	res.factor=  b.factor*b.J2*(b.J2+1.);	 
	return res;    
}
////-------overloaded for basis
std::vector<ketstate> J22(const Basis& b){

       	std::vector<ketstate> res;
	for(auto n : b.ketstate_list) {
		n.factor=  b.factor*n.J2*(n.J2+1.);
		res.push_back(n);
	}
     	return res;    
}
//------------------------------------------------------------------------
//AM /: AM[j2z] AMuket[j1_, m1_, j2_, m2_] := m2*AMuket[j1, m1, j2, m2];
//------------------------------------------------------------------------
ketstate J2z(const ketstate& b){  
    	ketstate res = b; 
	res.factor= b.factor* b.M2;
     	return res;      
}
////-------overloaded for basis
std::vector<ketstate> J2z(const Basis& b){  
    	std::vector<ketstate> res;
	for(auto n : b.ketstate_list) {
		n.factor=  b.factor*n.M2;
		res.push_back(n);
	}
     	return res;      
}
//------------------------------------------------------------------------
//AM /: AM[j2p] AMuket[j1_, m1_, j2_, m2_] := Sqrt[j2 (j2 + 1) - m2 (m2 + 1)] AMuket[j1, m1, j2, m2 + 1];
//------------------------------------------------------------------------
ketstate J2p(const ketstate& b){
	
	ketstate res = b;	 
		res.factor= b.factor*std::sqrt( std::abs(((b.J2 - b.M2))*(b.J2+b.M2+1.)) );
		res.M2 +=1.; 
     	return res; 
}
////-------overloaded for basis
std::vector<ketstate> J2p(const Basis& b){
	
	std::vector<ketstate> res ;// b.ketstate_list;
	for(auto n : b.ketstate_list) {
		n.factor= b.factor*std::sqrt( std::abs(((n.J2 - n.M2))*(n.J2+n.M2+1.)) );
		n.M2 +=b.M2+1.; 		
		res.push_back(n);
	}
     	return res; 
}
//------------------------------------------------------------------------
//AM /: AM[j2m] AMuket[j1_, m1_, j2_, m2_] := Sqrt[j2 (j2 + 1) - m2 (m2 - 1)] AMuket[j1, m1, j2, m2 - 1];
//------------------------------------------------------------------------
ketstate J2m(const ketstate& b){
	
	ketstate res = b;	 
		res.factor=b.factor* std::sqrt( std::abs(((b.J2 + b.M2))*(b.J2-b.M2+1.)) );
		res.M2 -=1.; 
     	return res; 
}
////-------overloaded for basis
std::vector<ketstate> J2m(const Basis& b){
	
	std::vector<ketstate> res ;// b.ketstate_list;
	for(auto n : b.ketstate_list) {
		n.factor= b.factor*std::sqrt( std::abs(((n.J2 + n.M2))*(n.J2-n.M2+1.)) );
		n.M2 +=b.M2-1.; 		
		res.push_back(n);
	}
     	return res; 
}

//------------------------------------------------------------------------
// AM /: AM[a_][ket_] := AM[a] ket;
//AM /: AM[a_, b_] ket_ := AM[a] (Compose @@ Join[AM /@ {b}, {ket}]);
//------------------------------------------------------------------------
ketstate  OStateTimesState(ketstate fun1(const ketstate&),ketstate fun2(const ketstate&),const ketstate& target){
 	
 	ketstate resf1  = fun1(target);
	ketstate resf2 = fun2(resf1);		 
	return resf2;
}
////--------------
double  OStateTimesState(ketstate fun(const ketstate&),const ketstate& target){
 	
 	ketstate resf  = fun(target);	 	
	return resf.factor;
}
//--------------------
std::vector<double>  OStateTimesState(std::vector<ketstate> fun(const Basis&),const Basis& target){
 	
 	std::vector<ketstate> resf  = fun(target);
 	std::vector<double> factors;	 
	for(auto m : target.ketstate_list){
		for (auto n : resf){		 
			factors.push_back((n*m)*n.factor);
		}
	}
	return factors;	 
}
std::vector<ketstate>  OStateTimesState(ketstate fun1(const ketstate&),ketstate fun2(const ketstate&),const Basis& target){
 	std::vector<ketstate> resf1;  //= fun1(target);
 	std::vector<ketstate> resf2;  //= fun2(resf1);
 	 for(auto& trg:target.ketstate_list){
 	      
 	      resf1.push_back(fun1(trg));
 	 
 	 }
 	 for(auto& trg : resf1){
 	      
 	      resf2.push_back(fun2(trg));
 	 
 	 }		 	
	return  resf2;
}

//******************************
std::vector<double>  OStateTimesState2(ketstate fun1(const ketstate&),ketstate fun2(const ketstate&),const Basis& target){
	std::vector<ketstate> resf1;  //= fun1(target);
	std::vector<ketstate> resf2;  //= fun2(resf1);
	std::vector<double> factors;
	for(auto& trg:target.ketstate_list){
		resf1.push_back(fun1(trg));
	}
	for(auto& trg : resf1){
		resf2.push_back(fun2(trg));
	}	 
	for(auto m : target.ketstate_list){
		for(auto& l : resf2){

			factors.push_back((l*m)*l.factor);
		}
	}
	return  factors;
}

std::vector<double>  OStateTimesState05(ketstate fun1(const ketstate&),ketstate fun2(const ketstate&),const Basis& target){
 	std::vector<ketstate> resf1;  //= fun1(target);
 	std::vector<ketstate> resf2;  //= fun2(resf1);
 	std::vector<double> factors;
 	 for(auto& trg:target.ketstate_list){
 	      
 	      resf1.push_back(fun1(trg));
 	 
 	 }
 	 for(auto& trg : resf1){
 	      
 	      resf2.push_back(fun2(trg));
 	 
 	 }
		 
		 
	for(auto m : target.ketstate_list){
		//for (auto n : resf1){
			for(auto& l : resf2){
			 
			factors.push_back(0.5*(l*m)*l.factor);
		//}
	}
	}
	return  factors;
}
 
//****************
//------------------------------------------------------------------------
// AMmatrix[op_, basis_List] := Expand[Outer[Times, Expand[op basis], basis]]
//------------------------------------------------------------------------
Eigen::MatrixXd AMmatrix(const std::vector<double>& L, const Basis& B)
{
	int k = 0;	 
	Eigen::VectorXd v(L.size());
	for (auto n : L) { 
		v(k++)=n;	 
	}
 
	Eigen::MatrixXd m(B.ketstate_list.size(),B.ketstate_list.size());	
	for(int i=0; i<B.ketstate_list.size(); i++) {
		for(int j=0; j<B.ketstate_list.size(); j++){
			m(i,j)=v[j+i*B.ketstate_list.size()];
		}
	}
	return m.transpose();
}
//****************************
 
//**********************
//------------------------------------------------------------------------
//setphase[m_?MatrixQ] := Table[Sign[N[Select[m[[i]]]][[1]]], {i, Length[m]}] m;
//------------------------------------------------------------------------
Eigen::MatrixXd setphase(Eigen::MatrixXd& mat){
	Eigen::MatrixXd res(mat.rows(),mat.cols());
	for(int i=0; i<mat.rows();i++){
		for(int j=0; j<mat.cols();j++){
			if(mat(i,j)<0) {
				res(i,j)=std::abs(mat(i,j));
			}
			else res(i,j)=mat(i,j);
		}
	}
	return res;
}
//------------------------------------------------------------------------
//jval[j1_, j2_, v_] := Array[(-1 + Sqrt[1 + 4*(j1 (j1 + 1) + j2 (j2 + 1) + 2*v[[#]])])/2 &, Length[v]]
//------------------------------------------------------------------------
Eigen::VectorXd jval(const double& j1, const double& j2, Eigen::VectorXd& vec){
    
	Eigen::VectorXd res(vec.size());
	for(int i =0; i<vec.size(); i++){
		res[i] =(-1.+ std::sqrt(1.+4.*(j1*(j1+1.) +j2*(j2+1.)+2.*vec(i))))/2.;
	}
	return res; 
}
/*
Eigen::VectorXd mval(Eigen::MatrixXd vec, const Basis& basis){
    
	Eigen::VectorXd res(vec.size());
	for(int i =0; i<vec.size(); i++){
		res[i] = vec(i)*basis.ketstate_list[i];
	}
	return res; 
}*/
//------------------------------------------------------------------------
// norm[m_?MatrixQ] := Array[m[[#]] . m[[#]] &, Length[m]];
//------------------------------------------------------------------------
//Eigen::MatrixXd Norm(Eigen::MatrixXd& mat){
Eigen::VectorXd Norm(Eigen::MatrixXd& mat){
	//Eigen::MatrixXd res(mat.rows(),mat.cols());
	Eigen::VectorXd res(mat.cols());
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
Eigen::MatrixXd Normalize(Eigen::MatrixXd& mat){
	Eigen::MatrixXd res(mat.rows(),mat.cols());
	Eigen::VectorXd norm_res(mat.cols());
	norm_res = Norm(mat);
	for(int i=0; i<mat.rows();i++){
		for(int j=0; j<mat.cols();j++){
			res(i,j)=mat(i,j)/std::sqrt(norm_res(i));
		}
	}
	return res;
}

///*The elements of the eigenvectors of this matrix are the
//Clebsch-Gordan coefficients for the Clebsch-Gordan se-
//ries |j1 -j2|<=j <=j1+j2*/
Eigen::MatrixXd totAMj1j2(const Basis& B){
	vector<double> state1 = OStateTimesState2(J1z,J2z,B);
	vector<double> state2 = OStateTimesState05(J1p,J2m,B);
	vector<double> state3 = OStateTimesState05(J1m,J2p,B);



	Eigen::MatrixXd mat1 = AMmatrix(state1,B);
	Eigen::MatrixXd mat2 = AMmatrix(state2,B);
	Eigen::MatrixXd mat3 = AMmatrix(state3,B);
	Eigen::MatrixXd muj1j2 = mat1+mat2+mat3;
	return muj1j2;
 }
int main(){

	  double spin1,spin2;
	
	 
	 cout<<"Insert two spins values j1 and j2:\n";
	 cin>>spin1>>spin2;
 
	 //test sigle state
	 /*
	 ketstate b(spin1,spin2,1,1);
	 b.PrintF();
	  ketstate newket = J12(b);
	  newket.PrintF();
	  */
	  
	 //test basis of states  
	/*
	 Basis B(spin1,spin2);
	 B.PrintFketstate_List();
	 */
	 //-----------------------J1-----------------------
	 /* 
	 ketstate test(spin1,-1,spin2,-1);
	 ketstate ketopefJ12 = J12(test);
	  ketopefJ12.PrintF();
	 std::vector<ketstate> opefJ12 = J12(B);
	 for(auto& s:opefJ12){
	 s.PrintF();
	 }
	 */
	 
	 /*
	 ketstate test(spin1,-1,spin2,-1);
	 ketstate ketopefJ1z = J1z(test);
	  ketopefJ1z.PrintF();
	std::vector<ketstate> opefJ1z = J1z(B);
	 for(auto& s:opefJ1z){
	 s.PrintF();
	 }
	 */
	 
	 /*ketstate test(spin1,-1,spin2,-1);
	 ketstate ketopefJ1p = J1p(test);
	 opefJ1p.PrintF();*/
	 /*std::vector<ketstate> opefJ1p = J1p(B);
	 for(auto& s:opefJ1p){
	 s.PrintF();
	 }*/
	 
	 //-----------------------J2-----------------------
	 /*ketstate test(spin1,1,spin2,1);
	 ketstate ketopefJ1m = J1m(test);
	  ketopefJ1m.PrintF();*/
	 /*std::vector<ketstate> opefJ1m = J1m(B);
	 for(auto& s:opefJ1m){
	 s.PrintF();
	 }*/
	 
	 /*
	 ketstate test(spin2,-1,spin2,-1);
	 ketstate ketopefJ22 = J22(test);
	  ketopefJ22.PrintF();
	 std::vector<ketstate> opefJ22 = J22(B);
	 for(auto& s:opefJ22){
	 s.PrintF();
	 }*/
	 
	 
	 /*
	 ketstate test(spin2,-1,spin2,-1);
	 ketstate ketopefJ2z = J2z(test);
	  ketopefJ2z.PrintF();
	std::vector<ketstate> opefJ2z = J2z(B);
	 for(auto& s:opefJ2z){
	 s.PrintF();
	 }*/
	 
	 /*
	 ketstate test(spin2,-1,spin2,-1);
	 ketstate ketopefJ2p = J2p(test);
	  ketopefJ2p.PrintF();
	 std::vector<ketstate> opefJ2p = J2p(B);
	 for(auto& s:opefJ2p){
	 s.PrintF();
	 }*/
	 
	 /*
	 ketstate test(spin2,2,spin2,2);
	 ketstate ketopefJ2m = J2m(test);
	  ketopefJ2m.PrintF();
	 std::vector<ketstate> opefJ2m = J2m(B);
	 for(auto& s:opefJ2m){
	 s.PrintF();
	 }*/
	 
	 /*
	 ketstate test(spin2,2,spin2,2);
	 test.PrintF();
	 //ketstate J12test = J1p(test);
	 //J12test.PrintF();
	 //cout<<J12test.factor*(J12test*test)<<endl;
	
	// ketstate op = OStateTimesState(J12,test);
	 //op.PrintF();
	 ketstate op = J12(test);
	 
	 ketstate op2 = J1z(op);
	// ketstate op3 = J12(op2);
	 //ketstate op4 = OStateTimesState(J1z,J12,test);
	 //op4.PrintF();
	 op2.PrintF();
	 cout<<OStateTimesState(J1z,op)<<endl;
	 */
	 
	/* Basis B(spin1,spin2);
	 vector<double> dores = OStateTimesState(J1p,B); 
	 
	 cout<<AMmatrix(dores,B)<<endl;*/
	/* ketstate testplus(1,1,1,1);
	  ketstate testplus2(1,2,1,2);
	 ketstate plus = OStateTimesState(J1m,J2m,testplus);
	 ketstate plus2 = OStateTimesState(J1z,J2z,testplus2);
	  plus.PrintF();
	  plus2.PrintF();
	 
	 ketstate p = plus+plus2;
	 p.PrintF();*/
	
	Basis B(spin1,spin2);
	/* vector<ketstate> state1 = OStateTimesState(J1z,J2z,B);
	 vector<ketstate> state2 = OStateTimesState(J1p,J2m,B);
	 vector<ketstate> state3 = OStateTimesState(J1m,J2p,B);
	for(auto& s: state2){
	 
	 s.PrintF();
	 
	 
	 }
	 B.PrintFketstate_List();*/
	/* vector<double> state1 = OStateTimesState2(J1z,J2z,B);
	 vector<double> state2 = OStateTimesState05(J1p,J2m,B);
	 vector<double> state3 = OStateTimesState05(J1m,J2p,B);
	 
	  
	 
	   Eigen::MatrixXd mat1 = AMmatrix(state1,B);
	   Eigen::MatrixXd mat2 = AMmatrix(state2,B);
	   Eigen::MatrixXd mat3 = AMmatrix(state3,B);
	   Eigen::MatrixXd muj1j2 = mat1+mat2+mat3;*/
	   Eigen::MatrixXd muj1j2 = totAMj1j2(B);
	   cout<<muj1j2<<endl;
	   //Matrix<complex<double>,Dynamic,Dynamic> val1 = EigenValue(muj1j2);
	   //Matrix<complex<double>,Dynamic,Dynamic> vec1 = EigenVector(muj1j2);
      	//cout<<"EigenValue:\n"<<val1;
      //cout<<"EigenValue:\n"<<vec1;
	return 0;
}

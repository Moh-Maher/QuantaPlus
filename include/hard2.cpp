#include<iostream>
#include<cmath>
#include"utilities.h"
#include"operators.h"
#include<vector>
#include<list>
#include <functional>
using namespace std;
 

class basis{
public:
  double J1,M1,J2,M2;
  double factor=1.0;
  std::list<basis> basis_list;
  basis(const double& j1, const double& j2)
  {
  J1=j1;
  J2=j2;
  for(auto i=0.; i<=int(2);i+=j1){
			for(auto j=0.; j<=int(2);j+=j2){
				basis_list.push_front( basis(j1,j1-i,j2,j2-j) );
			}
		}
  }
  basis(const double& j1, const double& m1,const double& j2,  const double& m2)
  	:J1(j1),M1(m1),J2(j2),M2(m2){}
  
  void printL(){
  if(factor==1.0)
 {
  	cout<<"AMuket["<<J1<<", "<<M1<<", "<<J2<<", "<<M2<<"]\n"; }
  	
  	else {DecimalToFraction(factor);cout<<" AMuket["<<J1<<", "<<M1<<", "<<J2<<", "<<M2<<"]\n";}   
  }
  
	void setbasis_list(const double& j1,const double& j2){


		for(auto i=0.; i<=int(2);i+=j1){
			for(auto j=0.; j<=int(2);j+=j2){
				basis_list.push_front( basis(j1,j1-i,j2,j2-j) );
			}
		}
	}
   void printAll(){
   	//std::cout << "l = { ";
	for (auto n : basis_list) {
		n.printL();
	}
	std::cout <<"\n";
   }
  struct Jop{
 
    
    Jop();

};


friend int operator* (const basis& b1 , const basis& b2);

};



int operator* (const basis& b1 , const basis& b2)
{
     int n=1;
     if((b1.J1!=b2.J1) || (b1.J2!=b2.J2) ||  (b1.M1!=b2.M1) ||  (b1.M2!=b2.M2) ){n=0;}
    
      return n;
}







basis J12(const basis& b){
 
     
     basis res(b.J1,b.M1,b.J2,b.M2); 
     res.factor=b.J1*(b.J1+1.);
    return res;    
}

basis J1z(const basis& b){
 
     
     basis res(b.J1,b.M1,b.J2,b.M2); 
     res.factor=b.M1;
    return res;    
}

basis J22(const basis& b){
 
     
     basis res(b.J1,b.M1,b.J2,b.M2); 
     res.factor=b.J2*(b.J2+1.);
    return res;    
}

basis J2z(const basis& b){
 
     
     basis res(b.J1,b.M1,b.J2,b.M2); 
     res.factor=b.M2;
    return res;    
}

basis J1p(const basis& b){
 
     
     basis res(b.J1,b.M1+1.,b.J2,b.M2); 
     res.factor= std::sqrt( b.J1*(b.J1+1.) - b.M1*(b.M1+1.) );
    return res;    
}

basis J1m(const basis& b){
 
     
     basis res(b.J1,b.M1-1.,b.J2,b.M2);  
     res.factor= std::sqrt(b.J1*(b.J1+1.)-b.M1*(b.M1-1.));
    return res;    
}

basis J2p(const basis& b){
 
     
     basis res(b.J1,b.M1,b.J2,b.M2+1.);  
     res.factor= std::sqrt(b.J1*(res.J2+1.)-b.M2*(b.M2+1.));
    return res;    
}

basis J2m(const basis& b){
 
     
     basis res(b.J1,b.M1,b.J2,b.M2-1.); 
     res.factor= std::sqrt(b.J2*(b.J2+1.)-b.M1*(b.M2-1.));
    return res;    
}
 

basis AM(basis f1(const basis&),basis f2(const basis&), const basis& target){
  // basis Res(f1(f2(target)));
  basis A = f2(target) ;
  //double temp = A.factor;
  basis B(f1(A));
  //double temp2 = B.factor;
  basis Res(B);
  Res.factor=A.factor*B.factor;
      return Res;

}

std::list<int>  AMmatrix(basis fun(const basis&),const basis& target){
 std::list<int> pro_list;
  for (auto n : target.basis_list) {
		pro_list.push_front(n*fun(target));
	}
return pro_list;
}

int main(){

	 double spin1,spin2;
	
	cout<<"Insert two spins values j1 and j2:";
	cin>>spin1>>spin2;
 
	
	basis b(spin1,spin2);
	b.printAll();
 /*basis b(1,1);
 b.printL();
 basis testres =  AM(J1z,J1m,b);//J1p(b);
 testres.printL();
 */
/*basis b1(1,-1,1,1);
  
 int pro = testres*b1;
 cout<<testres.factor<<"*"<<pro<<endl;*/
 /*basis b1(1,0,1,1);
 basis b2(1,0,0,1);
 int pro = b1*b2;
 if(pro==0) cout<<"it is zero"<<endl;
 if(pro==1) cout<<"it is 1"<<endl;*/
  std::list<int> pro_res = AMmatrix(J1p,b);
 //std::cout << "l = { ";
	for (auto n : pro_res) {
		cout<<n<<", ";
	}
	std::cout <<"\n";
	return 0;
}

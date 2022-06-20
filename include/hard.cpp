#include<iostream>
#include<cmath>
#include"utilities.h"
#include"operators.h"
#include<vector>
using namespace std;
 

vector<double> MQuantumNumber(const double &j)
{    
	double spin = j;
	vector<double> m_values;
	if(SpinValidation(spin))
	{
		
		for(auto i =-j; i<=j; i++)
		{       
			if(i==0){m_values.push_back(0);}
			else m_values.push_back(i);  
		}

	}
     
	else{
		throw std::invalid_argument("the system has physically invalid spin!.");
	}
	
 return m_values;
}
 
vector<double> possibleJ(const double& j1, const double& j2){

	double Jmin = std::abs(j1-j2);
	double Jmax = j1+j2;
 	double spin1 = j1;
 	double spin2 = j2;
	vector<double> J_values;
	if(SpinValidation(spin1) && SpinValidation(spin1))
	{
		
		for(auto i =Jmin; i<=Jmax; i++)
		{       
			if(i==0){J_values.push_back(0);}
			else J_values.push_back(i);  
		}

	}
     
	else{
		throw std::invalid_argument("the system has physically invalid spin!.");
	}
	
 return J_values;
} 
 
void PossibleStates(const double& j){
 
		 
		 
	for(int i =0;i<int(2*j+1);i++)
		{    
		        cout<<"|";
		        DecimalToFraction(j);
		        cout<<", ";
			 
			DecimalToFraction(MQuantumNumber(j)[i]); // [source utilities.h ]
			std::cout<<">\n";
			 
		}
		std::cout<<std::endl;
}
 
 
void possibleCoupled_JM(const double& j1, const double& j2){

	double Jmin = std::abs(j1-j2);
	double Jmax = j1+j2;
	
	cout<<"possible J, M: \n";
	double J[int(Jmax-Jmin)+1]={};
		for(auto i =Jmin; i<=Jmax; i++)
		{       
			 J[int(i-Jmin)]=i;   
		}
		for(int i =0;i<int(Jmax-Jmin)+1;i++)
		{   
			PossibleStates(J[i]);
		}
		std::cout<<std::endl;
}


int totNumberOfCGC(const double& j1, const double& j2, const double& J) {
 	
 	int count =0;
	vector<double> M = MQuantumNumber(J);
	vector<double> m1 = MQuantumNumber(j1);
	vector<double> m2 = MQuantumNumber(j2);

	for(auto m : m1)for(auto n : m2){
		
		for(int j=0;j<M.size();j++)
		{
			if(m+n==M[j]){count++;}
		}
	}
	return count;
}

int totNumberOfCGC(const double& j1, const double& j2) {

	//double Jmin = std::abs(j1-j2);
	//double Jmax = j1+j2;
	int count=0;
	 
	/*double J[int(Jmax-Jmin)+1]={};
		for(auto i =Jmin; i<=Jmax; i++)
		{       
			 J[int(i-Jmin)]=i;   
		}*/
	vector<double> J=possibleJ(j1,j2);
	for(int i =0;i<J.size();i++)
	{   
		count += totNumberOfCGC(j1,j2, J[i]);
	}
	 
	return count;
}


class AMState
{
public:
double J;
double M;
AMState(double j, double m):J(j),M(m){}

void PossibleStates(){
 
		 
		 
	for(int i =0;i<int(2*J+1);i++)
		{    
		        cout<<"|";
		        DecimalToFraction(J);
		        cout<<", ";
			 
			DecimalToFraction(MQuantumNumber(J)[i]); // [source utilities.h ]
			std::cout<<">\n";
			 
		}
		std::cout<<std::endl;
}

void JMinus(){
 
	double prefactor = sqrt((J+M)*(J-M+1));
	    if(prefactor!=0){      DecimalToFraction(sqrt((J+M)*(J-M+1)));cout<<"|";
		        DecimalToFraction(J);
		        cout<<", ";
			 
			DecimalToFraction(M-1); 
			std::cout<<">\n";
 }
 else 
 	    { cout<<"|"; DecimalToFraction(J);
		        cout<<", ";
			 
			DecimalToFraction(M-1); 
			std::cout<<"> =0 \n";}
		std::cout<<std::endl;
}

void JPlus(){
 
		 
  double prefactor = sqrt((J-M)*(J+M+1));
  if(prefactor!=0){
		        DecimalToFraction(sqrt((J-M)*(J+M+1)));cout<<"|";
		        DecimalToFraction(J);
		        cout<<", ";
			 
			DecimalToFraction(M+1); 
			std::cout<<">\n";
 }
 else {cout<<"|";
		        DecimalToFraction(J);
		        cout<<", ";
			 
			DecimalToFraction(M+1); 
			std::cout<<"> = 0.\n";}
		std::cout<<std::endl;
}

};



int main(){

	double spin1,spin2;
	
	cout<<"Insert two spins values j1 and j2:";
	cin>>spin1>>spin2;
	PossibleStates(spin1);
	PossibleStates(spin2);
 	possibleCoupled_JM(spin1,spin2);
 	 
 	cout<<"The total number of Clebsch-Gordon Coefficients = "<<totNumberOfCGC(spin1,spin2)<<endl;
 	 
 	 /*AMState ket(0.5,0.5);
 	// ket.PossibleStates();
 	 
 	 ket.JMinus();
 	 ket.JPlus();*/
	return 0;
}

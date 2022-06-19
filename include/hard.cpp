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



void compainM(const double& j1, const double& j2){
vector<double> m1 = MQuantumNumber(j1);
vector<double> m2 = MQuantumNumber(j2);
 
for(int i =0;i<int(2*j1+1);i++)
		{
		        cout<<"|";
		        DecimalToFraction(j1);
		        
		        cout<<", ";
		        DecimalToFraction(j2);
		        cout<<", ";
		DecimalToFraction(m1[i]); // [source utilities.h ]
		cout<<", ";
		        
		        DecimalToFraction(m2[i]); 
			std::cout<<">\n";
		}   
		cout<<endl; 
 
}



int totNumberOfCGC(const double& j1, const double& j2, const double& J){
 
	vector<double> M = MQuantumNumber(J);
	int count =0;

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

int  totNumberOfCGC(const double& j1, const double& j2){

	double Jmin = std::abs(j1-j2);
	double Jmax = j1+j2;
	int count=0;
	//cout<<"possible J, M: \n";
	double J[int(Jmax-Jmin)+1]={};
		for(auto i =Jmin; i<=Jmax; i++)
		{       
			 J[int(i-Jmin)]=i;   
		}
		for(int i =0;i<int(Jmax-Jmin)+1;i++)
		{   
			count += totNumberOfCGC(j1,j2, J[i]);
		}
		 
return count;
}
int main(){

	/*double spin1,spin2;
	
	cout<<"Insert two spins values j1 and j2:";
	cin>>spin1>>spin2;
	PossibleStates(spin1);
	PossibleStates(spin2);
 	possibleCoupled_JM(spin1,spin2);*/
 	//compainM(spin1,spin2);
 	//double a[3]={-1,0,1};
 	//vector<double> m = MQuantumNumber(4);
 	//cout<<"the possible ways "<<counter(m,m.size())<<endl;
 	cout<<"the possible ways "<<totNumberOfCGC(0.5,0.5)<<endl;
	return 0;
}

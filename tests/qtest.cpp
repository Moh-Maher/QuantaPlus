#include<iostream>
#include <iomanip>
#include"../quantaplus/quantaplus.h"
 



using namespace QuantaPlus; 
using std::cout;
using std::endl;
void sperator(const char &c, const int &width){
	cout.fill(c);
	cout<<cout.fill()<<std::setw(width)<<"\n";
}
 
int main(){


QuantaPlus::QuantumRegister qr(1);

cout<<qr.qBasis<<endl;
sperator('-',20);
//cout<<cout.fill('-')<<setw(20)<<"\n";
cout<<qr.getqState(0)<<endl;
sperator('-',20);

//cout<<cout.fill('-')<<setw(20)<<"\n";
cout<<qr.getqState(1)<<endl;
sperator('-',20);
/*
//cout<<cout.fill('-')<<setw(20)<<"\n";
cout<<qr.getqState(2)<<endl;
sperator('*',20);
//cout<<cout.fill('-')<<setw(20)<<"\n";
cout<<qr.getqState(3)<<endl;*/


cout<<xGate()<<endl;
//yGate().Print();
//(yGate()*qr.getqState(1)).Print();
cout<<xGate()*qr.getqState(1)<<endl;
}

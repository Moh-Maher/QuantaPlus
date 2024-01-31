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

void info(const std::string& text){
	cout<<text<<"\n";
}
 
int main(){



cout<<"Quanta Plus version: "<<QuantaPlus::getVersion()<<endl;

QuantaPlus::QuantumRegister qr(1);

info("state |0> + |1>");
cout<<qr.qBasis<<endl;
sperator('-',20);

info("State |0> ");
cout<<qr.getqState(0)<<endl;
sperator('-',20);

info("State |1>");
cout<<qr.getqState(1)<<endl;
sperator('-',20);
/*
//cout<<cout.fill('-')<<setw(20)<<"\n";
cout<<qr.getqState(2)<<endl;
sperator('*',20);
//cout<<cout.fill('-')<<setw(20)<<"\n";
cout<<qr.getqState(3)<<endl;*/

info("Not Gate");
cout<<xGate()<<endl;
sperator('-',20);
//yGate().Print();
//(yGate()*qr.getqState(1)).Print();

info("Not Gate |1> = |0>");
cout<<xGate()*qr.getqState(1)<<endl;
sperator('-',20);

info("CNOT Gate");
cout<<controledGate(xGate())<<endl;
}

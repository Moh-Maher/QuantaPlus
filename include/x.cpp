#include<iostream>
#include<complex>
#include"braket.h"
#include"operators.h"
#include<ctime>  
#include"utilities.h"
#include"latex.h"
using namespace std;
int main()
{

 
 
 latex mypdf("doc.tex");
 mypdf.begin();
 mypdf.typing("$$H\\ket{\\psi}=E\\ket{\\psi}$$");
 mypdf.end();
return 0;
}

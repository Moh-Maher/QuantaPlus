#include<iostream>
#include"plot.h"
int main()
{
 	
	
	
	//TODO not working...   
	Plot p("phi0","x","$\\phi$","phi0.dat", "-10:10", "0:1");
	//Plot p("phi0","x","$\\phi$","phi0.dat");
	p.savefig("myplot.pdf");
	p.show();
}

#include<iostream>
#include"plot.h"
int main()
{
 	
	
	
	//TODO not working...   
	//Plot p("phi0","x","$\phi$","phi0.dat", "-10:10", "0:1");
	Plot p;
	p.title = "phi0"; 
	p.xlabel = "x"; 
	p.ylabel = "$\\phi$"; 
	p.filename = "phi0.dat"; 
	p.xrange = "-10:10"; 
	p.yrange = "0:1"; 
	//Plot p("phi0","x","$\\phi$","phi0.dat");
	p.savefig("myplot.pdf");
	p.show();
}

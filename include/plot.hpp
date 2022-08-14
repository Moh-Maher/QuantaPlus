/*******************************************************************************************
  File:      	PLOT.TPP

  Summary:    
 
  by:  	     Mohammed Maher Abdelrahim Mohammed
       	     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
	     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
       	     mohammed.maher@unical.it  
*******************************************************************************************/
#ifndef QUANTAPLUS_INCLUDE_PLOT_HPP
#define QUANTAPLUS_INCLUDE_PLOT_HPP

#ifndef QUANTAPLUS_INCLUDE_PLOT_H
#error __FILE__ should only be included from plot.h.
#endif // PLOT_H

Plot::Plot() 
{ 
	this->title = title; 
	this->xlabel = xlabel; 
	this->ylabel = ylabel; 
	this->filename = filename; 
	this->xrange = xrange; 
	this->yrange = yrange; 
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:  

  Summary:   

  Args:      

  Returns:   
------------------------------------------------------------------*/
Plot::Plot(vector<double> x, vector<double> y) 
{ 
	this->xs = x; 
	this->ys = y; 
	this->title =  ylabel;
	this->xlabel = "x"; 
	this->ylabel = "y"; 
	this->filename = title+".dat";
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:  

  Summary:   

  Args:      

  Returns:   
------------------------------------------------------------------*/
Plot::Plot(vector<double> x, vector<double> y, string xlabel, string ylabel) 
{ 
	this->xs = x; 
	this->ys = y; 
	this->title = ylabel; 
	this->xlabel = xlabel; 
	this->ylabel = ylabel; 
	this->filename = title+".dat";
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:  

  Summary:   

  Args:      

  Returns:   
------------------------------------------------------------------*/
Plot::Plot(vector<double> x, vector<double> y, string title, string xlabel, string ylabel) 
{ 
	this->xs = x; 
	this->ys = y; 
	this->title = title; 
	this->xlabel = xlabel; 
	this->ylabel = ylabel; 
	this->filename = title+".dat";
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:  

  Summary:   

  Args:      

  Returns:   
------------------------------------------------------------------*/
Plot::Plot(vector<double> x, vector<double> y, string title, string xlabel, string ylabel, string xrange, string yrange)
{ 
	this->xs = x; 
	this->ys = y; 
	this->title = title; 
	this->xlabel = xlabel; 
	this->ylabel = ylabel;
	this->xrange = xrange; 
	this->yrange = yrange;  
	this->filename = title+".dat";
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:  

  Summary:   

  Args:      

  Returns:   
------------------------------------------------------------------*/
Plot::Plot(string title, string xlabel, string ylabel) 
{ 
	this->title = title; 
	this->xlabel = xlabel; 
	this->ylabel = ylabel;
	this->filename = title+".dat";
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:  

  Summary:   

  Args:      

  Returns:   
------------------------------------------------------------------*/
Plot::Plot(string title, string xlabel, string ylabel, string filename) 
{ 
	this->title = title; 
	this->xlabel = xlabel; 
	this->ylabel = ylabel; 
	this->filename = filename;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:  

  Summary:   

  Args:      

  Returns:   
------------------------------------------------------------------*/
Plot::Plot(string title, string xlabel, string ylabel, string filename, string xrange, string yrange) 
{ 
	this->title = title; 
	this->xlabel = xlabel; 
	this->ylabel = ylabel; 
	this->filename = filename; 
	this->xrange = xrange; 
	this->yrange = yrange; 
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: add

  Summary:   

  Args:      

  Returns:   
------------------------------------------------------------------*/
void Plot::add(double x, double y) 
{ 
	xs.push_back(x); 
	ys.push_back(y); 
}
//------------------------------------------------------------------ 
void Plot::add(vector<double> x, vector<double> y) 
{ 
	for(int i=0;i<x.size();i++) 
	{ 
		xs.push_back(x[i]); 
		ys.push_back(y[i]); 
	} 
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: show

  Summary:   

  Args:      

  Returns:   
------------------------------------------------------------------*/
void Plot::show() 
{   
	ofstream data; 
	//----------------------------------------------
	/*data.open(filename);
	for (int i = 0; i < xs.size(); i++) 
	    data << xs[i] << "\t" << ys[i] << endl; 
	data.close(); */
	//-----------------------------------------------------
	FILE *gnuplotPipe = popen("gnuplot --persist ", "w");  // Open a pipe to gnuplot

	if (gnuplotPipe)
	{   // If gnuplot is found
		//fprintf(gnuplotPipe, "set logscale y\n");

		fprintf(gnuplotPipe, "set title '%s' \n", title.c_str());  // Set the title of the graph
		fprintf(gnuplotPipe, "set xlabel '%s' \n", xlabel.c_str());  // Set the x-axis label
		fprintf(gnuplotPipe, "set ylabel '%s' \n", ylabel.c_str());  // Set the y-axis label
		fprintf(gnuplotPipe, "set xrange [%s] \n", xrange.c_str());  // Set the x-axis range
		fprintf(gnuplotPipe, "set yrange [%s] \n", yrange.c_str());  // Set the y-axis range
		fprintf(gnuplotPipe, "plot '%s' with linespoints \n", filename.c_str());  // Plot the data
		//fprintf(gnuplotPipe, "plot %s %s\n",dvecTostr(xs).c_str(),dvecTostr(ys).c_str());  // Plot the data
		//fprintf(gnuplotPipe, "plot %s \n",dvecTostr(ys).c_str());  // Plot the data
		//fprintf(gnuplotPipe, "p '%s' w lp lw 1.1\n",(name).c_str());

		fflush(gnuplotPipe); //flush pipe

		fprintf(gnuplotPipe,"exit \n");   // exit gnuplot        
		pclose(gnuplotPipe);    //close pipe
	}

	//string cmd = "rm "+filename;
	//system(cmd.c_str());
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: saveshow 

  Summary:   

  Args:      

  Returns:   
------------------------------------------------------------------*/
void Plot::saveshow()
{
	ofstream data; 
	//----------------------------------------------
	/*data.open(filename);
	for (int i = 0; i < xs.size(); i++) 
		data << xs[i] << "\t" << ys[i] << endl; 
	data.close(); */
	//-----------------------------------------------------
	FILE *gnuplotPipe = popen("gnuplot --persist ", "w");  // Open a pipe to gnuplot

	if (gnuplotPipe)
	{
		if(save)
		{ 
			string saveExtension = savefilename.substr(savefilename.find_last_of(".")+1);
			fprintf(gnuplotPipe, "set terminal %s  \n", saveExtension.c_str());  // Set the terminal type to png
			fprintf(gnuplotPipe, "set output '%s' \n", savefilename.c_str());  // Set the output file name
			fprintf(gnuplotPipe, "set title '%s' \n", title.c_str());  // Set the title of the graph
			fprintf(gnuplotPipe, "set xlabel '%s' \n", xlabel.c_str());  // Set the x-axis label
			fprintf(gnuplotPipe, "set ylabel '%s' \n", ylabel.c_str());  // Set the y-axis label
			fprintf(gnuplotPipe, "set xrange [%s] \n", xrange.c_str());  // Set the x-axis range
			fprintf(gnuplotPipe, "set yrange [%s] \n", yrange.c_str());  // Set the y-axis range
			fprintf(gnuplotPipe, "plot '%s' with linespoints \n", filename.c_str());  // Plot the data

			fflush(gnuplotPipe); //flush pipe

			fprintf(gnuplotPipe,"exit \n");   // exit gnuplot        
			pclose(gnuplotPipe);    //close pipe
		}
		//string cmd = "rm "+filename;
		//system(cmd.c_str());
	}
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: savefig  

  Summary:   

  Args:      

  Returns:   
------------------------------------------------------------------*/
void Plot::savefig(const string& filenamewithextension) 
{   
	save = true;
	savefilename = filenamewithextension;

	saveshow();
}
#endif

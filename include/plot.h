/* @plot.h file is part of QUANTAPLUS-x 
   API class for gnuplot to plot the data points 
by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          */
//#pragma once
#ifndef QUANTAPLUS_INCLUDE_PLOT_H
#define QUANTAPLUS_INCLUDE_PLOT_H

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<fstream>
#include<ctime>
#include<stdio.h>
using namespace std;
 

string dvecTostr(vector<double> dvec)
{
	stringstream ss;
	for(int i=0;i<dvec.size();i++)
	{
		ss<<dvec[i]<<" ";
	}
	return ss.str();
}
 
//*********************************************************************************************
//		API class for gnuplot to plot the data points
//---------------------------------------------------------------------------------------------
class Plot
{ 
	public:
		Plot(vector<double> x, vector<double> y);
		Plot(vector<double> x, vector<double> y, string xlabel, string ylabel);
		Plot(vector<double> x, vector<double> y, string title, string xlabel, string ylabel);
		Plot(vector<double> x, vector<double> y, string title, string xlabel, string ylabel, string xrange, string yrange);
		Plot(string title, string xlabel, string ylabel) ;
		Plot(string title, string xlabel, string ylabel, string filename);
		Plot(string title, string xlabel, string ylabel, string filename, string xrange, string yrange);
		void add(double x, double y);
		void add(vector<double> x, vector<double> y);
		void show();
		void saveshow();
		void savefig(const string& filenamewithextension);
	public: 
		string title, xlabel, ylabel, filename;
		string xrange, yrange;
		vector<double> xs, ys;
		bool save = false;
		string savefilename;
};
//*********************************************************************************************


#include"plot.hpp"
#endif

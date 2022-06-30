/* plt_all.h file is part of QUANTAPLUS-x 

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          */
#pragma once
#ifndef PLT_H_INCLUDED
#define PLT_H_INCLUDED
#include <cmath>
#include <vector>
#include<fstream>

#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;


/********************************************************
               ploting Alpha Strong test
********************************************************/
void plot_phi0() {

  const unsigned n = 11;
  std::ifstream infile;   
  infile.open("output/phi0.dat");
  if(infile.fail()) ///<-- checks to see if file opended 
    { 
      std::cout << "error!, the needed output file doesn't exist yet. !" << std::endl; 
      exit (-1); ///<-- no point continuing if the file didn't open...
    } 
 
 std::vector<double> x(n), y(n);
   for (unsigned i = 0; i < n; i++) {
      
    infile >> x[i];    
    infile >> y[i]; 
     
  }
  
  infile.close();
 
  plt::title("Wave function $\\phi_0$");
  plt::xlabel("$x$");
  plt::ylabel("$\\phi_0$");
  plt::text(5.7e+3, 0.299, "QUANTAPLUS-xv1.1");
   plt::xlim(-4, 4);
   //plt::ylim(0, 1);
   
  plt::plot(x, y, {{"color", "red"}, {"label", "Harmonic_Oscillator"}, {"linestyle", "--"}});
 // plt::scatter(w, z, {{"color", "blue"}, {"label", "Sine wave"}});
  plt::legend();
   plt::savefig("output/plots/phi0.pdf");
   printf("-----------------------------------------------------\n");
   printf("the plot has been saved in output/plots directory\n");
   printf("-----------------------------------------------------\n");
  plt::show();
  
}

/********************************************************
               ploting Alpha Strong test
********************************************************/
void plot_phi1() {

  const unsigned n = 11;
  std::ifstream infile;   
  infile.open("output/phi1.dat");
  if(infile.fail()) ///<-- checks to see if file opended 
    { 
      std::cout << "error!, the needed output file doesn't exist yet. !" << std::endl; 
      exit (-1); ///<-- no point continuing if the file didn't open...
    } 
 
 std::vector<double> x(n), y(n);
   for (unsigned i = 0; i < n; i++) {
      
    infile >> x[i];    
    infile >> y[i]; 
     
  }
  
  infile.close();
 
  plt::title("Wave function $\\phi_1$");
  plt::xlabel("$x$");
  plt::ylabel("$\\phi_1$");
  plt::text(5.7e+3, 0.299, "QUANTAPLUS-xv1.1");
   plt::xlim(-4, 4);
   //plt::ylim(0, 1);
   
  plt::plot(x, y, {{"color", "red"}, {"label", "Harmonic_Oscillator"},{"linestyle", "--"}}); 
  plt::legend();
   plt::savefig("output/plots/phi1.pdf");
   printf("-----------------------------------------------------\n");
   printf("the plot has been saved in output/plots directory\n");
   printf("-----------------------------------------------------\n");
  plt::show();
  
}
 
#endif

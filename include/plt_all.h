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

  const unsigned n = 21;
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
  //plt::text(0.,-0.01, "QUANTAPLUSv1.0");
   plt::xlim(-9, 9);
   //plt::ylim(0, 1);
   
  plt::plot(x, y, {{"color", "red"}, {"label", "Energy level 0"}, {"linestyle", "--"}});
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

  const unsigned n = 21;
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
 //plt::text(0.,-0.01, "QUANTAPLUSv1.0");
   plt::xlim(-9, 9);
   //plt::ylim(0, 1);
   
  plt::plot(x, y, {{"color", "red"}, {"label", "Energy level 1"},{"linestyle", "--"}}); 
  plt::legend();
   plt::savefig("output/plots/phi1.pdf");
   printf("-----------------------------------------------------\n");
   printf("the plot has been saved in output/plots directory\n");
   printf("-----------------------------------------------------\n");
  plt::show();
  
}

/********************************************************
               ploting Alpha Strong test
********************************************************/
void plot_phi2() {

  const unsigned n = 21;
  std::ifstream infile;   
  infile.open("output/phi2.dat");
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
 
  plt::title("Wave function $\\phi_2$");
  plt::xlabel("$x$");
  plt::ylabel("$\\phi_2$");
  //plt::text(0.,-0.01, "QUANTAPLUSv1.0");
   plt::xlim(-9, 9);
   //plt::ylim(0, 1);
   
  plt::plot(x, y, {{"color", "red"}, {"label", "Energy level 2"},{"linestyle", "--"}}); 
  plt::legend();
   plt::savefig("output/plots/phi2.pdf");
   printf("-----------------------------------------------------\n");
   printf("the plot has been saved in output/plots directory\n");
   printf("-----------------------------------------------------\n");
  plt::show();
  
}


/********************************************************
               ploting Alpha Strong test
********************************************************/
void plot_phi3() {

  const unsigned n = 21;
  std::ifstream infile;   
  infile.open("output/phi3.dat");
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
 
  plt::title("Wave function $\\phi_3$");
  plt::xlabel("$x$");
  plt::ylabel("$\\phi_3$");
 //plt::text(0.,-0.01, "QUANTAPLUSv1.0");
   plt::xlim(-9, 9);
   //plt::ylim(0, 1);
   
  plt::plot(x, y, {{"color", "red"}, {"label", "Energy level 3"},{"linestyle", "--"}}); 
  plt::legend();
   plt::savefig("output/plots/phi3.pdf");
   printf("-----------------------------------------------------\n");
   printf("the plot has been saved in output/plots directory\n");
   printf("-----------------------------------------------------\n");
  plt::show();
  
}

void plot_phi() {

  const unsigned n = 21;
  std::ifstream infile1;
  std::ifstream infile2;
  std::ifstream infile3;
  std::ifstream infile4;   
  infile1.open("output/phi0.dat");
   infile2.open("output/phi1.dat");
     infile3.open("output/phi2.dat");
   infile4.open("output/phi3.dat");
  if(infile1.fail()) ///<-- checks to see if file opended 
    { 
      std::cout << "error!, the needed output file doesn't exist yet. !" << std::endl; 
      exit (-1); ///<-- no point continuing if the file didn't open...
    } 
      if(infile2.fail()) ///<-- checks to see if file opended 
    { 
      std::cout << "error!, the needed output file doesn't exist yet. !" << std::endl; 
      exit (-1); ///<-- no point continuing if the file didn't open...
    } 
          if(infile3.fail()) ///<-- checks to see if file opended 
    { 
      std::cout << "error!, the needed output file doesn't exist yet. !" << std::endl; 
      exit (-1); ///<-- no point continuing if the file didn't open...
    } 
       if(infile4.fail()) ///<-- checks to see if file opended 
    { 
      std::cout << "error!, the needed output file doesn't exist yet. !" << std::endl; 
      exit (-1); ///<-- no point continuing if the file didn't open...
    } 
 std::vector<double> x1(n), y1(n);
   for (unsigned i = 0; i < n; i++) {
      
    infile1 >> x1[i];    
    infile1 >> y1[i]; 
     
  }
  
  infile1.close();
  
   std::vector<double> x2(n), y2(n);
   for (unsigned i = 0; i < n; i++) {
      
    infile2 >> x2[i];    
    infile2 >> y2[i]; 
     
  }
  
  infile2.close();
  
     std::vector<double> x3(n), y3(n);
   for (unsigned i = 0; i < n; i++) {
      
    infile3 >> x3[i];    
    infile3 >> y3[i]; 
     
  }
  
  infile3.close();
 
    std::vector<double> x4(n), y4(n);
   for (unsigned i = 0; i < n; i++) {
      
    infile4 >> x4[i];    
    infile4 >> y4[i]; 
     
  }
  
  infile4.close();
  plt::title("Harmonic Oscillator Wave functions");
  plt::xlabel("$x$");
  plt::ylabel("$\\phi$");
  //plt::text(0.,-0.01, "QUANTAPLUSv1.0");
   //plt::xlim(-7, 7);
   //plt::ylim(0, 1);
   
  plt::plot(x1, y1, {{"color", "red"}, {"label", "Energy level 0"}, {"linestyle", "--"}});
  plt::plot(x2, y2, {{"label", "Energy level 1"}, {"linestyle", "--"}});
  plt::plot(x3, y3, {{"label", "Energy level 2"}, {"linestyle", "--"}});
  plt::plot(x4, y4, {{"label", "Energy level 3"}, {"linestyle", "--"}});
  
  plt::legend();
   plt::savefig("output/plots/phiall.pdf");
   printf("-----------------------------------------------------\n");
   printf("the plot has been saved in output/plots directory\n");
   printf("-----------------------------------------------------\n");
  plt::show();
  
}



void DoubleWellplot_phi01() {

  const unsigned n = 21;
  std::ifstream infile1;
  std::ifstream infile2;
    
  infile1.open("output/DoubleWellphi0.dat");
   infile2.open("output/DoubleWellphi1.dat");
 
  if(infile1.fail()) ///<-- checks to see if file opended 
    { 
      std::cout << "error!, the needed output file doesn't exist yet. !" << std::endl; 
      exit (-1); ///<-- no point continuing if the file didn't open...
    } 
      if(infile2.fail()) ///<-- checks to see if file opended 
    { 
      std::cout << "error!, the needed output file doesn't exist yet. !" << std::endl; 
      exit (-1); ///<-- no point continuing if the file didn't open...
    } 
 
 std::vector<double> x1(n), y1(n);
   for (unsigned i = 0; i < n; i++) {
      
    infile1 >> x1[i];    
    infile1 >> y1[i]; 
     
  }
  
  infile1.close();
  
   std::vector<double> x2(n), y2(n);
   for (unsigned i = 0; i < n; i++) {
      
    infile2 >> x2[i];    
    infile2 >> y2[i]; 
     
  }
  
 
  
  infile2.close();
  plt::title("Wave functions under Double Well potential");
  plt::xlabel("$x$");
  plt::ylabel("$\\phi$");
  //plt::text(0.,-0.01, "QUANTAPLUSv1.0");
  plt::xlim(-10, 10);
   //plt::ylim(0, 1);
   
  plt::plot(x1, y1, {{"color", "red"}, {"label", "Energy level 0"}, {"linestyle", "--"}});
  plt::plot(x2, y2, {{"label", "Energy level 1"}, {"linestyle", "--"}});
 
  
  plt::legend();
   plt::savefig("output/plots/DoublePotential_phi0_1.pdf");
   printf("-----------------------------------------------------\n");
   printf("the plot has been saved in output/plots directory\n");
   printf("-----------------------------------------------------\n");
  plt::show();
  
}

void DoubleWellplot_phi23() {

  const unsigned n = 21;
  std::ifstream infile1;
  std::ifstream infile2;
    
  infile1.open("output/DoubleWellphi2.dat");
   infile2.open("output/DoubleWellphi3.dat");
 
  if(infile1.fail()) ///<-- checks to see if file opended 
    { 
      std::cout << "error!, the needed output file doesn't exist yet. !" << std::endl; 
      exit (-1); ///<-- no point continuing if the file didn't open...
    } 
      if(infile2.fail()) ///<-- checks to see if file opended 
    { 
      std::cout << "error!, the needed output file doesn't exist yet. !" << std::endl; 
      exit (-1); ///<-- no point continuing if the file didn't open...
    } 
 
 std::vector<double> x1(n), y1(n);
   for (unsigned i = 0; i < n; i++) {
      
    infile1 >> x1[i];    
    infile1 >> y1[i]; 
     
  }
  
  infile1.close();
  
   std::vector<double> x2(n), y2(n);
   for (unsigned i = 0; i < n; i++) {
      
    infile2 >> x2[i];    
    infile2 >> y2[i]; 
     
  }
  
 
  
  infile2.close();
  plt::title("Wave functions under Double Well potential");
  plt::xlabel("$x$");
  plt::ylabel("$\\phi$");
  //plt::text(0.,-0.01, "QUANTAPLUSv1.0");
   plt::xlim(-10, 10);
   //plt::ylim(0, 1);
   
  plt::plot(x1, y1, {{"color", "red"}, {"label", "Energy level 2"}, {"linestyle", "--"}});
  plt::plot(x2, y2, {{"label", "Energy level 3"}, {"linestyle", "--"}});
 
  
  plt::legend();
   plt::savefig("output/plots/DoublePotential_phi2_3.pdf");
   printf("-----------------------------------------------------\n");
   printf("the plot has been saved in output/plots directory\n");
   printf("-----------------------------------------------------\n");
  plt::show();
  
}

/********************************************************
               ploting Alpha Strong test
********************************************************/
void Shiftplot_phi0() {

  const unsigned n = 21;
  std::ifstream infile;   
  infile.open("output/shiftedphi0.dat");
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
  //plt::text(0.,-0.01, "QUANTAPLUSv1.0");
   plt::xlim(-9, 9);
   //plt::ylim(0, 1);
   
  plt::plot(x, y, {{"color", "red"}, {"label", "Energy level 0"}, {"linestyle", "--"}});
 // plt::scatter(w, z, {{"color", "blue"}, {"label", "Sine wave"}});
  plt::legend();
   plt::savefig("output/plots/shiftedphi0.pdf");
   printf("-----------------------------------------------------\n");
   printf("the plot has been saved in output/plots directory\n");
   printf("-----------------------------------------------------\n");
  plt::show();
  
}

/********************************************************
               ploting Alpha Strong test
********************************************************/
void Shiftplot_phi1() {

  const unsigned n = 21;
  std::ifstream infile;   
  infile.open("output/shiftedphi1.dat");
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
 //plt::text(0.,-0.01, "QUANTAPLUSv1.0");
   plt::xlim(-9, 9);
   //plt::ylim(0, 1);
   
  plt::plot(x, y, {{"color", "red"}, {"label", "Energy level 1"},{"linestyle", "--"}}); 
  plt::legend();
   plt::savefig("output/plots/shiftedphi1.pdf");
   printf("-----------------------------------------------------\n");
   printf("the plot has been saved in output/plots directory\n");
   printf("-----------------------------------------------------\n");
  plt::show();
  
}

/********************************************************
               ploting Alpha Strong test
********************************************************/
void Shiftplot_phi2() {

  const unsigned n = 21;
  std::ifstream infile;   
  infile.open("output/shiftedphi2.dat");
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
 
  plt::title("Wave function $\\phi_2$");
  plt::xlabel("$x$");
  plt::ylabel("$\\phi_2$");
  //plt::text(0.,-0.01, "QUANTAPLUSv1.0");
   plt::xlim(-9, 9);
   //plt::ylim(0, 1);
   
  plt::plot(x, y, {{"color", "red"}, {"label", "Energy level 2"},{"linestyle", "--"}}); 
  plt::legend();
   plt::savefig("output/plots/shiftedphi2.pdf");
   printf("-----------------------------------------------------\n");
   printf("the plot has been saved in output/plots directory\n");
   printf("-----------------------------------------------------\n");
  plt::show();
  
}


/********************************************************
               ploting Alpha Strong test
********************************************************/
void Shiftplot_phi3() {

  const unsigned n = 21;
  std::ifstream infile;   
  infile.open("output/shiftedphi3.dat");
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
 
  plt::title("Wave function $\\phi_3$");
  plt::xlabel("$x$");
  plt::ylabel("$\\phi_3$");
 //plt::text(0.,-0.01, "QUANTAPLUSv1.0");
   plt::xlim(-9, 9);
   //plt::ylim(0, 1);
   
  plt::plot(x, y, {{"color", "red"}, {"label", "Energy level 3"},{"linestyle", "--"}}); 
  plt::legend();
   plt::savefig("output/plots/shiftedphi3.pdf");
   printf("-----------------------------------------------------\n");
   printf("the plot has been saved in output/plots directory\n");
   printf("-----------------------------------------------------\n");
  plt::show();
  
}
#endif

/**************************************************************************************
cgc.h is a part of QUANTAPLUS library. 

 
by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
**************************************************************************************/
#pragma once
#ifndef QUANTAPLUS_INCLUDE_CLEBSCHGORDON_H
#define QUANTAPLUS_INCLUDE_CLEBSCHGORDON_H
//#include<iostream>
#include<limits>
#include<cmath>
#include <complex>
#include<vector>
#include <stdexcept>
#include"angularmomentum.h"
  
double SquareRoot(const double& x, const double& curr, const double& prev);
double SquareRoot(const double& x);
std::size_t Factorial(const std::size_t& n);
double FracFactorial(const double& n);
double clebsch_gordan(const double& j1, const double& m1, const double& j2, const double& m2, const double& J, const double& M);

#include"cgc.hpp"
#endif

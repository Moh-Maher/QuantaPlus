/************************************************************************ 
constants.h is a part of QUANTAPLUS

usage: define some fundamental Physical and mathematical constants.

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
************************************************************************/ 
//#pragma once
#ifndef QUANTAPLUS_INCLUDE_CONSTANTS_H
#define QUANTAPLUS_INCLUDE_CONSTANTS_H
#include<cmath>
#include<complex>

namespace QuantaPlus { 
/*=============================================================
                      Mathematical constants
=============================================================*/
const double ZETA_2 = M_PI*M_PI/6.;
//const double ZETA_2 = 1.6449340668482262;
const double ZETA_3 = 1.2020569031595942;
const double ZETA_4 = (pow(M_PI,4))/90.;
const double ZETA_5 = 1.0369277551433699;
/*=============================================================
                      Physical constants
=============================================================*/
const double SPEED_OF_LIGHT = 299792458;            ///< PDG2008
const double PLANCK_CONSTANT = 6.62606896 * 1.e-34; ///< PDG2009
const double PLANCK_CONSTANT_REDUCED = 6.58211899 * 1.e-16;
const double FINE_STRUCTURE_CONSTANT = 1. / 137.035999679; ///< PDG2008
const double HIGGS_VEV = 246.22; ///< Higgs vacuum expectation value
/*=============================================================
                       Units convertors
=============================================================*/
const double HBarC = 197.3269631;                           ///< Conversion constant \f$\hbar c\f$ in \f$\mathrm{MeV}\cdot\mathrm{fm}\f$ @cite Amsler:2008zzb
const double HBarC2 = 0.389379304;                          ///< Conversion constant \f$(\hbar c)^2\f$ in \f$\mathrm{GeV}^2\cdot\mathrm{mbarn}\f$ @cite Amsler:2008zzb
const double CONV_GEVm1_TO_FM = 0.1973269631;               ///< Conversion constant \f$\mathrm{GeV}^{-1} \rightarrow \mathrm{fm}\f$.
const double CONV_GEVm2_TO_NBARN = 0.389379304e+6;          ///< Conversion constant \f$\mathrm{GeV}^{-2} \rightarrow \mathrm{nbarn}\f$.
const double CONV_GEVm2_TO_PBARN = 0.389379304e+9;          ///< Conversion constant \f$\mathrm{GeV}^{-2} \rightarrow \mathrm{pbarn}\f$.
/*=============================================================
                       QCD Parameters
=============================================================*/
int NF;
int const CA = 3; ///<------------- for SU(3) QCD
//double CF = (CA*CA-1.)/(2*CA);
double const CF = 4./3.;   ///<-----for SU(3) QCD
const double TR = 0.5;
//static double BETA0 = 11.-2./3.*double(NF);
//static double BETA1 = 102.-38./3.*double(NF);
 
/*=============================================================
                      Gell-Mann matrices
=============================================================*/
 std::complex<double> i (0,1);

 std::complex<double> lambda1[9]{0.0, 1.0, 0.0,
                            	 1.0, 0.0, 0.0,
                            	 0.0, 0.0, 0.0};
                           
 std::complex<double> lambda2[9]{0.0,  -i, 0.0,
                            	   i, 0.0, 0.0,
                            	 0.0, 0.0, 0.0};

 std::complex<double> lambda3[9]{1.0,  0.0, 0.0,
                            	 0.0, -1.0, 0.0,
                            	 0.0,  0.0, 0.0};
                           
 std::complex<double> lambda4[9]{0.0, 0.0, 1.0,
                             	 0.0, 0.0, 0.0,
                            	 1.0, 0.0, 0.0};
                           
 std::complex<double> lambda5[9]{0.0, 0.0,  -i,
	                    	 0.0, 0.0, 0.0,
		                   i, 0.0, 0.0};
                           
 std::complex<double> lambda6[9]{0.0, 0.0, 0.0,
                            	 0.0, 0.0, 1.0,
                            	 0.0, 1.0 ,0.0};
                           
 std::complex<double> lambda7[9]{0.0, 0.0, 0.0,
                            	 0.0, 0.0,  -i,
                            	 0.0,   i, 0.0};
                           
std::complex<double> lambda8[9]{0.5773502691896258, 0.0000000000000000,   0.0000000000000000, 
                            	0.0000000000000000, 0.5773502691896258,   0.0000000000000000,
                            	0.0000000000000000, 0.0000000000000000, - 1.1547005383792517};
                                     
 std::complex<double> F1[9]{0.0, 0.5, 0.0,
		            0.5, 0.0, 0.0,
		            0.0, 0.0, 0.0};
				  
 std::complex<double> F2[9]{0.00, -i/2., 0.00,
                            i/2.,  0.00, 0.00,
                            0.00,  0.00, 0.00};
                                 
 std::complex<double> F3[9]{0.5, 0.0, 0.0,
 			    0.0,-0.5, 0.0,
 			    0.0, 0.0, 0.0};

 std::complex<double> F4[9]{0.0, 0.0, 0.5,
 			    0.0, 0.0, 0.0,
 			    0.5, 0.0, 0.0};
 			    
 std::complex<double> F5[9]{0.0, 0.0,-i/2.,
 			    0.0, 0.0,  0.0,
 			   i/2., 0.0,  0.0};
 			   
 std::complex<double> F6[9]{0.0, 0.0, 0.0,
 			    0.0, 0.0, 0.5,
 			    0.0, 0.5, 0.0};
 			    
 std::complex<double> F7[9]{0.0,  0.0,  0.0,
 			    0.0,  0.0,-i/2.,
 			    0.0, i/2.,  0.0};
 			    
 std::complex<double> F8[9]{ 0.5/sqrt(3), 0.0000000000, 0.0000000000000,
 			     0.000000000, 0.5/sqrt(3) , 0.0000000000000,
 			     0.000000000, 0.0000000000, -2.*0.5/sqrt(3)};
//std::complex<double> F8[9]{0.5,0,0,0,0.5,0,0,0,-1};
//const double strc_cons[9]{1,0.5,-0.5,0.5,0.5,0.5,-0.5,sqrt(3)/2. ,sqrt(3)/2.};
/*=============================================================
                      Pauli matrices
=============================================================*/
 std::complex<double> sigma1[4]{0., 1.,
				1., 0.};
				  
std::complex<double> sigma2[4]{0., i,
			       -i, 0.};
				  
 std::complex<double> sigma3[4]{1., 0.,
                                0.,-1.};
/*=============================================================
                        Particle masses
==============================================================*/
const double PROTON_MASS = 0.938272013;            ///< PDG2010

const double ELECTRON_MASS = 0.510998910e-3;       ///< PDG2008
const double MUON_MASS = 105.658367e-3;            ///< PDG2008
const double TAU_MASS = 1.77684;                   ///< PDG2008

const double QUARK_UP_MASS = 0.0024;                ///< PDG2010
const double QUARK_DOWN_MASS = 0.0049;              ///< PDG2010
const double QUARK_STRANGE_MASS = 0.1;              ///< PDG2010
const double QUARK_CHARM_MASS = 1.29;               ///< PDG2010
const double QUARK_BOTTOM_MASS = 4.19;              ///< PDG2010
const double QUARK_TOP_MASS = 173.21;           ///<172.9;  PDG2010

const double PI_ZERO_MASS = 0.1349766;              ///< PDG2010

const double W_BOSON_MASS = 80.1;
const double Z_BOSON_MASS = 91.1876;                ///< PDG2010
const double HIGGS_BOSON_MASS= 125.18 ;
/*============================================================= 
                     Particle electric charges
============================================================*/
const double U_ELEC_CHARGE = 2. / 3.;  ///< Electric charge of up quark (in units of e)
const double D_ELEC_CHARGE = -1. / 3.; ///< Electric charge of down quark (in units of e)
const double S_ELEC_CHARGE = -1. / 3.; ///< Electric charge of strange quark (in units of e)
const double C_ELEC_CHARGE = 2. / 3.;  ///< Electric charge of charm quark (in units of e)
const double B_ELEC_CHARGE = -1. / 3.; ///< Electric charge of bottom quark (in units of e)
const double T_ELEC_CHARGE = 2. / 3.;  ///< Electric charge of top quark (in units of e)

const double U2_ELEC_CHARGE = 4. / 9.; ///< Square of electric charge of up quark
const double D2_ELEC_CHARGE = 1. / 9.; ///< Square of electric charge of down quark
const double S2_ELEC_CHARGE = 1. / 9.; ///< Square of electric charge of strange quark
const double C2_ELEC_CHARGE = 4. / 9.; ///< Square of electric charge of charm quark
const double B2_ELEC_CHARGE = 1. / 9.; ///< Square of electric charge of bottom quark
const double T2_ELEC_CHARGE = 1. / 9.; ///< Square of electric charge of top quark

const double POSITRON_CHARGE = 0.30282211985966434;

}//end of namespace QuantaPlus

#endif /* CONSTANTS_H */

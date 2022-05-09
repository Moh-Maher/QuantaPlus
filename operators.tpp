/*******************************************************************************************
some of "operators.h" meathods implementation.

ref: [N. Zettili, “Quantum Mechanics, Concepts and Applications,” Wiley, Chichester, 2001.]

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
//#include"braket.h"
#pragma once
//#ifndef OPERATORS_TPP
//#define OPERATORS_TPP

//#ifndef OPERATORS_H
//#error __FILE__ should only be included from operators.h.
//#endif // OPERATORS_H

template <class T, int R,int C>
Q_operator<T,R,C>::Q_operator():Eigen::Matrix<T,R,C>(){}
//--------------------------------------------------------------------------
//	 
//--------------------------------------------------------------------------
template <class T, int R,int C>
Q_operator<T,R,C>::Q_operator(int row,int col):Eigen::Matrix<T,R,C>(row,col){}
 
//--------------------------------------------------------------------------
//	 
//--------------------------------------------------------------------------
template <class T, int R,int C>
Q_operator<T,R,C>::~Q_operator(){}
//---------------------------------------------------------------------------
//		commutation relation: [A,B] = A*B - B*A
//---------------------------------------------------------------------------
template <typename T, int R, int C>
Eigen::Matrix<T,R,C> Commute(Eigen::Matrix<T,R,C> & mt1, Eigen::Matrix<T,R,C> &mt2)
{  
	return (mt1*mt2 - mt2*mt1);
}
//---------------------------------------------------------------------------
//		compute structure constants
//---------------------------------------------------------------------------
template <typename U,int R,int C>
U StructureConstant(Eigen::Matrix<U,R,C>& mt1, Eigen::Matrix<U,R,C>& mt2, Eigen::Matrix<U,R,C>& mt3 )
{
	U sum = static_cast<U>(0.0);
	const std::complex<double> I{0.,1.};

	Eigen::Matrix<U,3,3> cm, prod;
	cm = Commute(mt2,mt3);
	prod = mt1 * cm ;

	for (int i=0; i<3; i++)
	{
		for (int j=0; j<(3); j++)
		{
			if(i==j)
			{
				sum += prod(i,i);
			}
		}
	}
	return std::real(-0.25*I*sum);
}
 
//using namespace QUANTAx;
const double hBar = 1.; //6.58211899 * 1.e-16;
/*-------------------------------------------------------------------------------------------
           Magnatic_Quantum_Number : m which is run from -j to j. (-j<= m <= j).                      
-------------------------------------------------------------------------------------------*/
void Magnetic_Quantum_Number(const double &j)
{    
     double sp = j;
     if(SpinValidation(sp))
     {
         double m[int(2*j+1)]={};
         for(auto i =-j; i<=j; i++)
         {
             m[int(abs(j+i))]=i;   
         }
         for(int i =0;i<int(2*j+1);i++)
         {   
             decimalToFraction(m[i]); // [source utilities.h ]
             std::cout<<"\t";
         }
         std::cout<<std::endl;
     }
     
     else{
         std::cout<<"the system has physically invalid spin!"<<std::endl;
     }
}
/*-------------------------------------------------------------------------------------------
 The square of the angular momentum J^2 :  <j',m'|J^2|j, m> = ℏ^2 j(j+1) δ[j'j] * δ[m'm].             
-------------------------------------------------------------------------------------------*/
double Jsqr(double j, double j1, double m1, double j2, double m2)
{
    return hBar*hBar*j*(j+1) * KroneckerDelta(j1,j2) *KroneckerDelta(m1,m2);
}
/*-------------------------------------------------------------------------------------------
 The x-component of the angular momentum operator J: Eq (5.70) of N. Zettili.                                   
-------------------------------------------------------------------------------------------*/
double Jx(double j, double j1,double m1, double j2,double m2)
{ 
    double res1,res2;

    res1 = sqrt(j*(j+1)-m2*(m2+1))* KroneckerDelta(m1,m2+1);
    res2 =   sqrt(j*(j+1)-m2*(m2-1))*  KroneckerDelta(m1,m2-1);
    return hBar*0.5*(res1+res2)*KroneckerDelta(j1,j2);
}
/*-------------------------------------------------------------------------------------------
 The y-component of the angular momentumo peratorJ: Eq (5.71) of N. Zettili.                                    
-------------------------------------------------------------------------------------------*/
std::complex<double>  Jy(double j, double j1,double m1, double j2,double m2)
{
    std::complex<double> Im(0.,1.);
    double res1,res2;

    res1 = sqrt(j*(j+1)-m2*(m2+1))* KroneckerDelta(m1,m2+1);
    res2 =   sqrt(j*(j+1)-m2*(m2-1))*  KroneckerDelta(m1,m2-1);
    return hBar*(-0.5*Im)*(res1-res2)*KroneckerDelta(j1,j2);
}
/*-------------------------------------------------------------------------------------------
 The z-component of the angular momentum operator J:  <j',m'|J_Z|j, m> =  mℏ δ[j'j] * δ[m'm]. 
-------------------------------------------------------------------------------------------*/
double Jz(double j, double j1, double m1, double j2, double m2)
{
    return hBar*m2 * KroneckerDelta(j1,j2) *KroneckerDelta(m1,m2);
}
/*-------------------------------------------------------------------------------------------
 The J+ angular momentum operator J: Eq (5.69) of N. Zettili.                                   
-------------------------------------------------------------------------------------------*/
double Jplus(double j, double j1,double m1, double j2,double m2)
{ 
    double res;
    res = sqrt(j*(j+1)-m2*(m2+1))* KroneckerDelta(m1,m2+1);
    return hBar*(res)*KroneckerDelta(j1,j2);
}
/*-------------------------------------------------------------------------------------------
 The J- angular momentum operator J: Eq (5.69) of N. Zettili.                                   
-------------------------------------------------------------------------------------------*/
double Jminus(double j, double j1,double m1, double j2,double m2)
{ 
    double res;
    res = sqrt(j*(j+1)-m2*(m2-1))* KroneckerDelta(m1,m2-1);
    return hBar*(res)*KroneckerDelta(j1,j2);
}
/*-------------------------------------------------------------------------------------------
              Kronecker Delta:  δ[ij] =  1 => (if i=j) OR 0 => (otherwise).
-------------------------------------------------------------------------------------------*/
double KroneckerDelta(double i, double j)
{
   if  (i==j){return (1);}
   else 
   return (0);
}
/*-------------------------------------------------------------------------------------------
 Check the physically valid spin: True only if j is a nonnegative half-integer value
-------------------------------------------------------------------------------------------*/
bool SpinValidation(double &j)
{ 
  double jTimes2 = 2*j;
  bool flag = false;
  std::string strj = ToString(jTimes2); //ToString->> [source utilities.h]
  
  if(j>=0 && isNumber(strj) ) // isNumber ->> [source utilities.h]
  {
      return true;
  }
  
  return flag; 
}

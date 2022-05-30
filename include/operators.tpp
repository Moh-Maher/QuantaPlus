/*******************************************************************************************
some of "operators.h" meathods implementation.

ref: [N. Zettili, “Quantum Mechanics, Concepts and Applications,” Wiley, Chichester, 2001.]

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*******************************************************************************************/
//#pragma once
#ifndef OPERATORS_TPP
#define OPERATORS_TPP

#ifndef OPERATORS_H
#error __FILE__ should only be included from operators.h.
#endif // OPERATORS_H

//--------------------------------------------------------------------------
//		QM_operator defult constructor
//--------------------------------------------------------------------------
template<class T>
QM_operator<T>::QM_operator(): 
	Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>(){};
//--------------------------------------------------------------------------
//	 QM_operator constructor with a given rows and cols
//--------------------------------------------------------------------------
template<class T>
QM_operator<T>::QM_operator(int row, int col):
	Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>(row,col){};
//--------------------------------------------------------------------------
//	 
//--------------------------------------------------------------------------
template<class T>
QM_operator<T>::~QM_operator(){};


//--------------------------------------------------------------------------
//		AngularMomentum defult constructor
//--------------------------------------------------------------------------
template <class T>
AngularMomentum<T>::AngularMomentum():QM_operator<T>(){}
//--------------------------------------------------------------------------
//	Constructor for AngularMomentum matrix of a given rows and cols
//--------------------------------------------------------------------------
template <class T>
AngularMomentum<T>::AngularMomentum(int row, int col):
	QM_operator<T>(row,col){} 
//--------------------------------------------------------------------------
//		AngularMomentum destructor
//--------------------------------------------------------------------------
template <class T>
AngularMomentum<T>::~AngularMomentum(){ }
//---------------------------------------------------------------------------
//		commutation relation: [A,B] = A*B - B*A
//---------------------------------------------------------------------------
template<class T> Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> 
Commute(Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mt1, 
	Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> &mt2)
{  
	return (mt1*mt2 - mt2*mt1);
}
//---------------------------------------------------------------------------
//		compute structure constants
//---------------------------------------------------------------------------
template <typename U>
U StructureConstant( Eigen::Matrix<U,Eigen::Dynamic,Eigen::Dynamic>& mt1, 
		     Eigen::Matrix<U,Eigen::Dynamic,Eigen::Dynamic>& mt2, 
		     Eigen::Matrix<U,Eigen::Dynamic,Eigen::Dynamic>& mt3 )
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
//***************************************************************************** 
const double hBar = 1.; //6.58211899 * 1.e-16;
//-------------------------------------------------------------------------------------------
//           Magnatic_Quantum_Number : m which is run from -j to j. (-j<= m <= j).                      
//-------------------------------------------------------------------------------------------
void MagneticQuantumNumber(const double &j)
{    
	double spin = j;
	if(SpinValidation(spin))
	{
		double m[int(2*j+1)]={};
		for(auto i =-j; i<=j; i++)
		{
			m[int(abs(j+i))]=i;   
		}
		for(int i =0;i<int(2*j+1);i++)
		{   
			DecimalToFraction(m[i]); // [source utilities.h ]
			std::cout<<"\t";
		}
		std::cout<<std::endl;
	}
     
	else{
		std::cout<<"the system has physically invalid spin!"<<std::endl;
	}
}
//-------------------------------------------------------------------------------------------
//		The square of the angular momentum J^2 :  
//			<j',m'|J^2|j, m> = ℏ^2 j(j+1) δ[j'j] * δ[m'm].             
//-------------------------------------------------------------------------------------------
double Jsqr(double j, double j1, double m1, double j2, double m2)
{
	return hBar*hBar*j*(j+1) * KroneckerDelta(j1,j2) *KroneckerDelta(m1,m2);
}
//-------------------------------------------------------------------------------------------
//		The x-component of the angular momentum operator J: 
//			Eq (5.70) of N. Zettili.                                   
//-------------------------------------------------------------------------------------------
double Jx(double j, double j1,double m1, double j2,double m2)
{ 
	double res1,res2;

	res1 = sqrt(j*(j+1)-m2*(m2+1))* KroneckerDelta(m1,m2+1);
	res2 =   sqrt(j*(j+1)-m2*(m2-1))*  KroneckerDelta(m1,m2-1);
	return hBar*0.5*(res1+res2)*KroneckerDelta(j1,j2);
}
//-------------------------------------------------------------------------------------------
// 		The y-component of the angular momentumo peratorJ: 
//			Eq (5.71) of N. Zettili.                                    
//-------------------------------------------------------------------------------------------
std::complex<double>  Jy(double j, double j1,double m1, double j2,double m2)
{
    std::complex<double> Im(0.,1.);
	double res1,res2;

	res1 = sqrt(j*(j+1)-m2*(m2+1))* KroneckerDelta(m1,m2+1);
	res2 =   sqrt(j*(j+1)-m2*(m2-1))*  KroneckerDelta(m1,m2-1);
	return hBar*(-0.5*Im)*(res1-res2)*KroneckerDelta(j1,j2);
}
//-------------------------------------------------------------------------------------------
// 		The z-component of the angular momentum operator J: 
//			 <j',m'|J_Z|j, m> =  mℏ δ[j'j] * δ[m'm]. 
//-------------------------------------------------------------------------------------------
double Jz(double j, double j1, double m1, double j2, double m2)
{
	return hBar*m2 * KroneckerDelta(j1,j2) *KroneckerDelta(m1,m2);
}
//-------------------------------------------------------------------------------------------
// 		The J+ angular momentum operator J: 
//			Eq (5.69) of N. Zettili.                                   
//-------------------------------------------------------------------------------------------
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

	if(j>=0 && IsNumber(strj) ) // IsNumber ->> [source utilities.h]
	{
		return true;
	}

	return flag; 
}
//--------------------------------------------------------------------------
//		J- Angular Momentum perator
//--------------------------------------------------------------------------
template <class T>
AngularMomentum<T> AngularMomentum<T>::AngularMomentum_JSquare(const double &j)
{
	const int max =int(2*j+1);
	std::complex<double> temarr[max*max]{};
	double sp = j;
  
	if(SpinValidation(sp))
	{    
        	double M[max]={};
        	for(auto i =-j; i<=j; i++)
        	{
            		M[abs(int(j+i))]=i;   
        	}
             
        	for(int i=0;i<max;i++)
        	{
            		for(int k=0;k<max;k++)
            		{              
                		temarr[k+(i*max)] = Jsqr(j,j,-M[i],j,-M[k]);
            		}        
        	}
    	}   
    
	else{
		throw std::invalid_argument("the system has physically invalid spin!.");
	}
	AngularMomentum<T> temp(max,max);
	for(int i=0; i<max; i++)
	{
		for(int j=0; j<max; j++)
		{
	    		temp(i,j)= temarr[j+i*max];
		}
	}

	return temp;    
}
//--------------------------------------------------------------------------
//		Jx Angular Momentum perator
//--------------------------------------------------------------------------
template <class T>
AngularMomentum<T> AngularMomentum<T>::AngularMomentum_Jx(const double &j)
{
	const int max =int(2*j+1);
	std::complex<double> temarr[max*max]{};
	double sp = j;

	if(SpinValidation(sp))
	{    
		double M[max]={};
		for(auto i =-j; i<=j; i++)
		{
	    		M[abs(int(j+i))]=i;   
		}
	     
		for(int i=0;i<max;i++)
		{
	    		for(int k=0;k<max;k++)
	    		{   
		 		temarr[k+(i*max)] = Jx(j,j,-M[i],j,-M[k]);
	    		}		

		}	
	}

	else
	{
	//std::cout<<"the system has physically invalid spin!"<<std::endl;
		throw std::invalid_argument("the system has physically invalid spin!.");
	} 
	
	AngularMomentum<T> temp(max,max);
	for(int i=0; i<max; i++)
	{
		for(int j=0; j<max; j++)
		{
	    		temp(i,j)= temarr[j+i*max];
		}
	}
	return temp;      
}
//--------------------------------------------------------------------------
//		Jy Angular Momentum perator
//--------------------------------------------------------------------------
template <class T>
AngularMomentum<T> AngularMomentum<T>::AngularMomentum_Jy(const double &j)
{
	const int max =int(2*j+1);
	std::complex<double> temarr[max*max]{};
	double sp = j;

	if(SpinValidation(sp))
	{    
		double M[max]={};
		for(auto i =-j; i<=j; i++)
		{
	    		M[abs(int(j+i))]=i;   
		}
	     
		for(int i=0;i<max;i++)
		{
	    		for(int k=0;k<max;k++)
	    		{   
				temarr[k+(i*max)] = Jy(j,j,-M[i],j,-M[k]);
	    		}   
		}
	}

	else
	{
		throw std::invalid_argument("the system has physically invalid spin!.");
	}
	 
	AngularMomentum<T> temp(max,max);
	for(int i=0; i<max; i++)
	{
		for(int j=0; j<max; j++)
		{
	    		temp(i,j)= temarr[j+i*max];
		}
	}

	return temp;       
}
//--------------------------------------------------------------------------
//		Jz Angular Momentum perator
//--------------------------------------------------------------------------
template <class T>
AngularMomentum<T> AngularMomentum<T>::AngularMomentum_Jz(const double &j)
{
	const int max =int(2*j+1);
	std::complex<double> temarr[max*max]{};
	double sp = j;

	if(SpinValidation(sp))
	{    
		double M[max]={};
		for(auto i =-j; i<=j; i++)
		{
	    		M[abs(int(j+i))]=i;   
		}
	     
		for(int i=0;i<max;i++)
		{
	    		for(int k=0;k<max;k++)
	    		{   
				temarr[k+(i*max)] = Jz(j,j,-M[i],j,-M[k]);
	    		}
		}	
	}

	else
	{
		throw std::invalid_argument("the system has physically invalid spin!.");
	} 
	AngularMomentum<T> temp(max,max);
	for(int i=0; i<max; i++)
	{
		for(int j=0; j<max; j++)
		{
	    		temp(i,j)= temarr[j+i*max];
		}
	}

	return temp;      
}
//--------------------------------------------------------------------------
//		J+ Angular Momentum perator
//--------------------------------------------------------------------------
template <class T>
AngularMomentum<T> AngularMomentum<T>::AngularMomentum_JPlus(const double &j)
{
	const int max =int(2*j+1);
	std::complex<double> temarr[max*max]{};
	double sp = j;

	if(SpinValidation(sp))
	{    
		double M[max]={};
		for(auto i =-j; i<=j; i++)
		{
	    		M[abs(int(j+i))]=i;   
		}
	     
		for(int i=0;i<max;i++)
		{
	    		for(int k=0;k<max;k++)
	    		{   
				temarr[k+(i*max)] = Jplus(j,j,-M[i],j,-M[k]);
	    		}
		}
	}

	else
	{
		throw std::invalid_argument("the system has physically invalid spin!.");
	} 
	AngularMomentum<T> temp(max,max);
	for(int i=0; i<max; i++)
	{
		for(int j=0; j<max; j++)
		{
	    		temp(i,j)= temarr[j+i*max];
		}
	}

	return temp;      
}
//--------------------------------------------------------------------------
//		J- Angular Momentum perator
//--------------------------------------------------------------------------
template <class T>
AngularMomentum<T> AngularMomentum<T>::AngularMomentum_JMinus(const double &j)
{
	const int max =int(2*j+1);
	std::complex<double> temarr[max*max]{};
	double sp = j;

	if(SpinValidation(sp))
	{    
		double M[max]={};
		for(auto i =-j; i<=j; i++)
		{
			M[abs(int(j+i))]=i;   
		}
	     
		for(int i=0;i<max;i++)
		{
	 		for(int k=0;k<max;k++)
	 		{     
	     			temarr[k+(i*max)] = Jminus(j,j,-M[i],j,-M[k]);
	 		}        
		}
	}

	else
	{
		throw std::invalid_argument("the system has physically invalid spin!.");
	} 
	AngularMomentum<T> temp(max,max);
	for(int i=0; i<max; i++)
	{
		for(int j=0; j<max; j++)
		{
	    		temp(i,j)= temarr[j+i*max];
		}
	}

	return temp;     
}
/*
//--------------------------------------------------------------------------
//
//--------------------------------------------------------------------------
template <typename T>
Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> MatrixExp(Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> &A){

return  A.exp();
}

template <typename T>
Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> MatrixExp(Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> &A, Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> &V ){

return  A.exp()*V;
}
//--------------------------------------------------------------------------
//		 
//--------------------------------------------------------------------------

template <class T>
AngularMomentum<T> AngularMomentum<T>:: RotationByAngle(const double &a)
{
 const double spin= 1./2.;
 AngularMomentum<std::complex<double>> S_x;
 S_x = S_x.AngularMomentum_Jx(spin);
 std::complex<double> i(0.,1.);
 return MatrixExp(i*a*S_x);
}*/
#endif // OPERATORS_TPP

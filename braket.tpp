/****************************************************************************
BraKet.tpp is a part of QUANTA-x library. 

usage: provides implementation details for bra and ket spaces.

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                         
****************************************************************************/

//#include"braket.h"
#pragma once
#ifndef BRAKET_TPP
#define BRAKET_TPP

#ifndef BRAKET_H
#error __FILE__ should only be included from braket.h.
#endif // BRAKET_H

//##########################################################################
// class ket:
//##########################################################################
//--------------------------------------------------------------------------
//		defult constructor
//--------------------------------------------------------------------------
template <class T, int R>
ket<T,R>::ket():matrix<T,R,1>(){}
//--------------------------------------------------------------------------
//		Constructor for ket vector of a given rows
//--------------------------------------------------------------------------
template <class T, int R>
ket<T,R>::ket(int row):matrix<T,R,1>(row,1){}
//--------------------------------------------------------------------------
//		2nd overloded constructor
//--------------------------------------------------------------------------
template <class T, int R>
ket<T,R>::ket(const T *data ):matrix<T,R,1>(data){}
//--------------------------------------------------------------------------
//		destructor
//--------------------------------------------------------------------------
template <class T, int R>
ket<T,R>::~ket(){}
//--------------------------------------------------------------------------
//		Overloaded Operator "=" : |ket> = |ket>
//--------------------------------------------------------------------------
template <class T, int R>
ket<T,R> ket<T,R>::operator=(const ket<T,R>& kt)
{
    if(this!=&kt)
        for(int i =0; i<kt.Row; i++)
        {
            for(int j =0; j<kt.Col; j++)
            {
  	         this->table[i][j] = kt.table[i][j];
            }
        }
    ket<T,R> res(*this);
    return res;       
}
//--------------------------------------------------------------------------
//		Muliplay ket by scalar: a |ket>
//--------------------------------------------------------------------------
template <class T,int R>
ket<T,R> operator* (const T& scalar, const ket<T,R>& kt)
{ 
    ket<T,R> res(kt.GetRow());
    for(int i = 0; i < kt.GetRow(); ++i)
    {
        for(int j = 0; j < kt.GetCol(); ++j)
        {
  	    res.table[i][j] = scalar*kt.table[i][j];
  	}
    }
    return res;    
}
 
//--------------------------------------------------------------------------
//		access |ket> elements 
//--------------------------------------------------------------------------
template <class T, int R>
T ket<T,R>::GetValue(int row) const
{  
   return matrix<T,R,1>::GetElement(row, 0);   
}
//--------------------------------------------------------------------------
//		|ket[i]> = value
//--------------------------------------------------------------------------
template <typename T, int R>
T ket<T,R>::operator[](int i) const
{ 
return GetValue(i);   
}
//--------------------------------------------------------------------------
//		Matrix actcting on a ket vector : A * |ket>
//--------------------------------------------------------------------------
template <class T, int R, int C>
ket<T,R> operator*  (const matrix<T,R,C> &mat, const ket<T,R>& kt)
{
    ket<T,R> res(kt.GetRow());
    for(int i = 0; i < kt.GetRow(); ++i)
    {
        for(int j = 0; j < kt.GetCol(); ++j)
        {
             for(int k = 0; k < kt.GetSize(); ++k)
             {
  	         res.table[i][j] += mat.table[i][k] * kt.table [k][j];
  	     }
  	}
    }
    return res;      
}
//--------------------------------------------------------------------------
// Overloading the  + OPERATOR: result in |A>+ |B>
//--------------------------------------------------------------------------
template <class T, int R>
ket<T,R> ket<T,R>::operator + (const ket<T,R> &kt) const
{
    //bool match  = CheckDimension(*this,kt);
    //if(!match){ throw std::invalid_argument("matrices dimensions do not match."); }
    
    ket<T,R> res(kt.GetRow());
 
    for(int i =0; i<kt.GetRow(); i++)
    {
      //  for(int j =0; j<Col; j++)
        //{
  	    res.table[i][0] = this->table[i][0]+kt.table[i][0];
        //}
    }
    
    return res;    
}
//--------------------------------------------------------------------------
// Overloading the  - OPERATOR: result in |A>- |B>
//--------------------------------------------------------------------------
template <class T, int R>
ket<T,R> ket<T,R>::operator - (const ket<T,R> &kt) const
{
    //bool match  = CheckDimension(*this,kt);
    //if(!match){ throw std::invalid_argument("matrices dimensions do not match."); }
    
    ket<T,R> res(kt.GetRow());
 
    for(int i =0; i<kt.GetRow(); i++)
    {
      //  for(int j =0; j<Col; j++)
        //{
  	    res.table[i][0] = this->table[i][0]-kt.table[i][0];
        //}
    }
    
    return res;    
}
//-----------------------------------------------------
// Overloading the insertion << operator
//-----------------------------------------------------
template <typename U,int R>
std::ostream& operator<<(std::ostream& output,
const ket<U,R>& kt)
{
//output << "[ ";
 for(int i =0; i<kt.GetRow(); i++)
    {
    
            cplx_print(kt.table[i][0]);
       
        output<<"\n";
    }
// output << "]\n";
return output;
}
//##########################################################################
// class bra :
//##########################################################################
//--------------------------------------------------------------------------
//		defult constructor
//--------------------------------------------------------------------------
template <class T, int C>
bra<T,C>::bra():matrix<T,1,C>(){}
//--------------------------------------------------------------------------
//		Constructor for bra vector of a given rows
//--------------------------------------------------------------------------
template <class T, int C>
bra<T,C>::bra(int col):matrix<T,1,C>(1,col){}
//--------------------------------------------------------------------------
//		2nd overloded constructor
//--------------------------------------------------------------------------
template <class T, int C>
bra<T,C>::bra(const T *data ):matrix<T,1,C>(data){}
//--------------------------------------------------------------------------
//		destructor
//--------------------------------------------------------------------------
template <class T, int C>
bra<T,C>::~bra(){}
//--------------------------------------------------------------------------
//		Overloaded Operator "=" : |bra> = |bra>
//--------------------------------------------------------------------------
template <class T, int C>
bra<T,C> bra<T,C>::operator=(const bra<T,C>& br)
{
    if(this!=&br)
        for(int i =0; i<br.GetRow(); i++)
        {
            for(int j =0; j<br.GetCol(); j++)
            {
  	         this->table[i][j] = br.table[i][j];
            }
        }
    bra<T,C> res(*this);
    return res;       
}
//--------------------------------------------------------------------------
//		Muliplay bra by scalar: a |bra>
//--------------------------------------------------------------------------
template <class T,int C>
bra<T,C> operator* (const T& scalar, const bra<T,C>& br)
{ 
    bra<T,C> res(br.GetCol());
    for(int i = 0; i < br.GetRow(); ++i)
    {
        for(int j = 0; j < br.GetCol(); ++j)
        {
  	    res.table[i][j] = scalar*br.table[i][j];
  	}
    }
    return res;    
}
//--------------------------------------------------------------------------
//		access |bra> elements 
//--------------------------------------------------------------------------
template <class T, int C>
T bra<T,C>::GetValue(int col) const
{  
   return matrix<T,1,C>::GetElement(0, col);   
}
//--------------------------------------------------------------------------
//		|bra[i]> = value
//--------------------------------------------------------------------------
template <typename T, int C>
T bra<T,C>::operator[](int i) const
{ 
return GetValue(i);   
}
//--------------------------------------------------------------------------
//		Matrix actcting on a bra vector : <bra|*A
//--------------------------------------------------------------------------
template <class U, int V, int C>
bra<U, V> operator*(const bra<U, V>& br, const matrix<U, V, C>& mat)
{
    bra<U,V> res(br.GetCol());
    for(int i = 0; i < br.GetRow(); ++i)
    {
        for(int j = 0; j < br.GetCol(); ++j)
        {
             for(int k = 0; k < br.GetSize(); ++k)
             {
  	         res.table[i][j] += br.table [i][k]*mat.table[k][j] ;
  	     }
  	}
    }
    return res;      
}
//-----------------------------------------------------
// Overloading the insertion << operator
//-----------------------------------------------------
template <typename U,int C>
std::ostream& operator<<(std::ostream& output,
const bra<U,C>& br)
{
//output << "[ ";
 for(int i =0; i<br.GetCol(); i++)
    {
      //  for(int j =0; j<kt.GetCol(); j++)
       // {
            //output<<mt.table[i][j]<<"\t";
            cplx_print(br.table[0][i]);
        //}
        output<<"";
    }
    output<<"\n";
// output << "]\n";
return output;
}
//---------------------------------------------------------------------------
//		commutation relation: [A,B] = A*B - B*A
//---------------------------------------------------------------------------
template <typename T, int R, int C>
matrix<T,R,C> Commute(matrix<T,R,C> & mt1, matrix<T,R,C> &mt2)
{  
    return (mt1*mt2 - mt2*mt1);
}
//---------------------------------------------------------------------------
//		compute structure constants
//---------------------------------------------------------------------------
template <typename U,int R,int C>
U StructureConstant(matrix<U,R,C>& mt1, matrix<U,R,C>& mt2, matrix<U,R,C>& mt3 )
{
    U sum=0.0;
    const std::complex<double> I (0,1);

    matrix<U,3,3> cm, prod;
    cm = Commute(mt2,mt3);
    prod = mt1 * cm ;

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<(3); j++)
        {
            if(i==j)
            {
                sum += prod.table[i][i];
            }
  	}
    }
    return std::real(-0.25*I*sum);
}
//--------------------------------------------------------------------------
//#############	bra dual Conjugate	#########################
//--------------------------------------------------------------------------
template <typename T, int C>
ket<T,C> DualConj(const bra<T,C> &b)
{
    ket<T,C> res(b.GetCol());

    for (int i=0; i<b.GetCol(); i++)
    {
  	    res.table[i][0] = std::conj(b.table[0][i]);
    }
    return res;
}
//--------------------------------------------------------------------------
//##############	ket dual Conjugate	#########################
//--------------------------------------------------------------------------
template <typename T, int R>
bra<T,R> DualConj(const ket<T,R> &kt)
{
    bra<T,R> res(kt.GetRow());

    for (int i=0; i<kt.GetRow(); i++)
    {
  	    res.table[0][i] = std::conj(kt.table[i][0]);
    }
    return res;
}

//--------------------------------------------------------------------------
//##############	ket Conjugate	#########################
//--------------------------------------------------------------------------
template <typename T, int R>
ket<T,R> Conj(const ket<T,R> &kt)
{
    ket<T,R> res(kt.GetRow());

    for (int i=0; i<kt.GetRow(); i++)
    {
  	    res.table[i][0] = std::conj(kt.table[i][0]);
    }
    return res;
}
//--------------------------------------------------------------------------
//##############	bra Conjugate	#########################
//--------------------------------------------------------------------------
template <typename T, int C>
bra<T,C> Conj(const bra<T,C> &br)
{
    bra<T,C> res(br.GetCol());

    for (int i=0; i<br.GetCol(); i++)
    {
  	    res.table[0][i] = std::conj(br.table[0][i]);
    }
    return res;
}
//--------------------------------------------------------------------------
//#############	Bra-Ket		#########################
//--------------------------------------------------------------------------
template <typename T, int R,int C> 
T BraKet(const bra<T,C> &b, const ket<T,R> &kt)
{     
    if(b.GetCol()!=kt.GetRow()){ throw std::invalid_argument("dimensions do not match."); }

    //int dim= b.GetCol() * kt.GetRow();

    T sum = static_cast<T>(0.0);

    for(int i = 0; i < b.GetRow(); ++i)
    {
        for(int j = 0; j < kt.GetCol(); ++j)
        {
            for(int k = 0; k < b.GetSize(); ++k)
            {
   	        sum += b.table[i][k] * kt.table [k][j];
            }
        }
    }
    return sum;    
}
//--------------------------------------------------------------------------
//#############	normalization factor		#########################
//--------------------------------------------------------------------------
template <typename T, int R> 
T NormFactor(const ket<T,R> &kt)
{    
    bra<T,R> br(kt.GetRow());
    br = DualConj(kt);
    T sum = BraKet(br,kt); 
    return 1./sqrt(sum);   
}
//------------------------------------------------------------------------------
//#############	normalization factor		#########################
//--------------------------------------------------------------------------
template <typename T,int C>
T NormFactor(const bra<T,C> &br)
{    
    ket<T,C> kt(br.GetCol());
    kt = DualConj(br);
    T sum = BraKet(br,kt); 
    return 1./sqrt(sum);   
}
//------------------------------------------------------------------------------
//#############	normalized ket	#########################
//--------------------------------------------------------------------------
template <typename T,int R>
ket<T,R> Normalized(const ket<T,R> &kt)
{    
    ket<T,R> res;
    res = NormFactor(kt) * kt;
    return res;   
}
//------------------------------------------------------------------------------
//#############	normalized bra		#########################
//--------------------------------------------------------------------------
template <typename T,int C>
bra<T,C> Normalized(const bra<T,C> &br)
{    
    bra<T,C> res;
    res = NormFactor(br) * br;
    return res;   
}
//--------------------------------------------------------------------------
//#############	Dagar of operator	###############################
//--------------------------------------------------------------------------
template <typename T, int R,int C>
matrix<T,R,C> Dagar(const matrix<T,R,C> & mt)
{    
    matrix<T,R,C> res(mt.GetCol(),mt.GetRow());

    for (int i=0; i<mt.GetRow(); i++)
    {
        for (int j=0; j<(mt.GetCol()); j++)
        {
  	    res.table[i][j] = std::conj(mt.table[j][i]);
  	}
    }
    return res;
}
//--------------------------------------------------------------------------
//#############	The expectation value of operator A	##############
//--------------------------------------------------------------------------
template <typename T, int R,int C>
T ExpectValue(const matrix<T,R,C> & mt, const ket<T,R> &kt)
{    
    bra<T,C> br = DualConj(kt);
    ket<T,R> toright = mt * kt;
    T nomr = BraKet(br,toright); 
    T dnomr = BraKet(br,kt);
   
    return nomr/dnomr; 
}
//--------------------------------------------------------------------------
//#############	orthonormal Bra-Ket		######################
//--------------------------------------------------------------------------
template <typename T, int R,int C>
T OrthnormalBraKet(const bra<T,C> &b, const ket<T,R> &kt)
{   
    if(b.GetCol()!=kt.GetRow()){ throw std::invalid_argument("dimensions do not match."); }

    int dim= b.GetCol() * kt.GetRow();

    T sum = static_cast<T>(0.0);

    for(int i = 0; i < b.GetRow(); ++i)
    {
        for(int j = 0; j < kt.GetCol(); ++j)
        {  
            if( b.GetValue(j)==std::conj(kt.GetValue(i)))
            {
   	        sum =1.0;
   	    }   	    
        }
    }
    //else {sum=0.;}
    return sum;    
}
//--------------------------------------------------------------------------
//#############	orthonormal Basis		####################
//--------------------------------------------------------------------------
template <typename T> 
T Basis(const T &b, const T &kt)
{       
    T sum = static_cast<T>(0.0);      
    if( std::conj(b) == kt)
    {
        sum =1.0;
    }
    return sum;    
}
#endif // BRAKET_TPP

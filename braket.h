/**************************************************************************************
BraKet.h is a part of QUANTA-x library. 

usage: define and handle some fundamental operations on bra and ket vectors.

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
**************************************************************************************/
#pragma once
#ifndef BRAKET_H
#define BRAKET_H
#include"matrix.h"
  
namespace QUANTAx {
//####################################################################################
// ket class:
//####################################################################################
template <class T, int R>
class ket : public matrix<T,R,1> 
{
public:
    ket();
    ket(int row); 
    ket(const T *data ); 
    ~ket();
    
    T GetValue(int row) const;
    ket<T,R> operator= (const ket<T,R> &mat);
    T  operator[] (int i) const;
    template<class U, int V> 
    friend ket<U,V> operator* (const U &scalar, const ket<U,V>& mat);
    
    template<class U, int V, int C> 
    friend ket<U,V> operator* (const matrix<U,V,C> &mat, const ket<U,V> &kt);
    ket<T,R> operator + (const ket<T,R> &mat) const;
    ket<T,R> operator - (const ket<T,R> &mat) const;      
};

//####################################################################################
// bra class:
//####################################################################################
template <class T, int C>
class bra : public matrix<T,1,C> 
{
public:
    bra();
    bra(int col); 
    bra(const T *data ); 
    ~bra();
    
    T GetValue(int col) const;
    bra<T,C> operator= (const bra<T,C> &mat);
    T  operator[] (int i) const;
    template<class U, int V> friend bra<U,V> 
    operator* (const U &scalar, const bra<U,V>& mat);
    
    template<class U, int V, int W> 
    friend bra<U,V> operator* (const bra<U,V> &br, const matrix<U,V,W> &mat);       
};

#include"braket.tpp"
} //end of namespace QUANTAx
#endif

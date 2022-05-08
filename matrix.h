/*matxx.h is a part of QUANTA-x library.

usage: define and handle some fundamental operations on two-dimensional matrices.

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          */
#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include<cmath>
//#include"utilities.h"
namespace QUANTAx {

//----------------------------------------------------
//  print c-numbers in the form z= x+iy
//---------------------------------------------------
inline void cplx_print(std::complex<double> a)
{
    double x = std::real(a);
    double y = std::imag(a);
   
    if(x!=0 and y!=0)
    {
        if(y<0)
        {
            std::cout<<x<<y<<"i"<<"\t";
            //decimalToFraction(x);
            //decimalToFraction(y);
            //std::cout<<"i"<<"\t";
        }

        else if(y>0)
        {
            std::cout<<x<<"+" <<y<<"i"<<"\t";
            //decimalToFraction(x);
            //std::cout<<"+";
            //decimalToFraction(y);
            //std::cout<<"i"<<"\t";
            
        }
    }

    else if(y==0)
    {   
        std::cout<<x<<"\t";
        //decimalToFraction(x);
        //std::cout<<"\t";
    }

    else if(x==0)
    {
        std::cout<<y<<"i"<<"\t";
        //decimalToFraction(y);
        //std::cout<<"i"<<"\t";
    }    
}
//----------------------------------------------------
// Overloading the insertion << operator
//---------------------------------------------------
inline std::ostream& operator<<(std::ostream& output, const std::complex<double>& z)
{ 
    cplx_print(z);     
    return output;
}
//====================================================
//===============[ matrix calss ]===============
//====================================================
template <class T, int R, int C>
class matrix
{
public:
    matrix();
    matrix(int const &row, const int &col);
    matrix(const T *data);
    matrix(const matrix<T,R,C> &mat);
    virtual ~matrix();
    
    T Trace(const matrix<T,R,C> & mt);
    T Det( const matrix<T,R,C> & mt, const int &n);
    T determinant(const matrix<T, R, C> & A, const int &n);
    
    int GetRow() const;
    int GetCol() const;
    int GetSize() const;
    T GetElement(const int &row, const int &col) const;
    //matrix<T,R,C> KroneckerProduct(const matrix<T,R,C>& mt1, const matrix<T,R,C>& mt2);
    //template<class U,int Q,int W> friend void show(matrix<U,Q,W> & mt);
    template<class U,int Q,int W> 
    friend std::ostream& operator<<(std::ostream& output, const matrix<U,Q,W>& mt);
  //  template<class U> friend U braket(matrix<U,R,C> &b, matrix<U,R,C> &kt);
   // template<class U,int Q,int W> friend void cplx_show(matrix<U,Q,W> & mt);
    //void SetToUnit(const matrix<T,R,C> & mt);    
    //void Trans(const matrix<T,R,C> & mt);    
    void adjoint(const matrix<T,R,C> & A , const matrix<T,R,C> & adj);      
    void GetCofactor( const matrix<T,R,C> & A,  const matrix<T,R,C> & temp, 
    					const int &p, const int &q, const int &n);
    
    template<class U,int Q,int W>
    friend bool CheckDimension(const matrix<U,Q,W> &mat1,const matrix<U,Q,W> &mat2);
    
    bool Inverse(const matrix<T,R,C>& A, const matrix<T,R,C> & inverse);
    
    bool operator== (const matrix<T,R,C>& mt);
    matrix<T,R,C> operator= (const matrix<T,R,C> &mat);
    matrix<T,R,C> operator + (const matrix<T,R,C> &mat) const;
    matrix<T,R,C> operator - (const matrix<T,R,C> &mat) const;
    virtual matrix<T,R,C> operator * (const matrix<T,R,C> &mat) const;
    
    template<class U,int Q,int W> 
    friend matrix<U,Q,W> operator* (const U &scalar, const matrix<U,Q,W>& mat);
    //template<class U> friend matrix<U,R,C> Dagar(const matrix<U,R,C> & mt); //QM 
   // void dual(const matrix<T,R,C> & mt); //QM   
    T **table;   
protected:
    int Row, Col;
    int Dim;
    //T **table;
};
#include"matrix.tpp"
}//end of namespace QUANTAx 
#endif

/*****************************************************************************
matxx.h is a part of QUANTA-x library.

usage: provides implementation details for the fundamental operations on 
       two-dimensional matrices.

by:  Mohammed Maher Abdelrahim Mohammed
     UNIVERSITÀ DELLA CALABRIA, DIPARTIMENTO DI FISICA AND INFN-COSENZA
     VIA P. BUCCI, CUBO 31 C, I-87036 COSENZA, ITALY
     mohammed.maher@unical.it                                          
*****************************************************************************/
#pragma once
#ifndef MATRIX_TPP
#define MATRIX_TPP

#ifndef MATRIX_H
#error __FILE__ should only be included from matrix.h.
#endif // MATRIX_H

//---------------------------------------------------------------------------
//      default constructor (set the matrix to zero)
//---------------------------------------------------------------------------
template <class T, int R, int C>
matrix<T,R,C>::matrix(): Row(R), Col(R)
{
    Dim = Row * Col;
    
    table = new T*[Row];

    for(int k = 0; k < Row; k++)
    {
        table[k] = new T[Col];
    }

    for(int i =0; i<Row; i++)
    {
        for(int j =0; j<Col; j++)
        {
            table[i][j] = {};
        }
    }
}
//---------------------------------------------------------------------------
//  defined constructor
//---------------------------------------------------------------------------
template <class T, int R, int C>
matrix<T,R,C>::matrix(int const &row, const int &col): Row(row), Col(col)
{  
    Dim= Row * Col;
     
    table = new T*[Row];

    for(int k = 0; k < Row; k++)
    {
        table[k] = new T[Col];
    }

    for(int i =0; i<Row; i++)
    {
        for(int j =0; j<Col; j++)
        {
  	    table[i][j] = {};
        }
    }
}
//---------------------------------------------------------------------------
//  defined constructor (read data and store it in the matrix)
//---------------------------------------------------------------------------
template <class T, int R, int C>
matrix<T,R,C>::matrix(const T *data):  Row(R), Col(C)
{
    Dim= Row * Col;
    
    table = new T*[Row];

    for(int k = 0; k < Row; k++)
    {
        table[k] = new T[Col];
    }

    for(int i =0; i<Row; i++)
    {
        for(int j =0; j<Col; j++)
        {
  	    table[i][j] = data[j+i*Col];
        }
    }
}
//---------------------------------------------------------------------------
//  defined constructor (read a matrix)
//---------------------------------------------------------------------------
template <class T, int R, int C>
matrix<T,R,C>::matrix(const matrix<T,R,C> &mat): Row(mat.Row), Col(mat.Col)
{  
    Dim= Row * Col;
    
    table = new T*[Row];

    for(int k = 0; k < Row; k++)
    {
        table[k] = new T[Col];
    }

    for(int i =0; i<Row; i++)
    {
        for(int j =0; j<Col; j++)
        {
  	    table[i][j] = mat.table[i][j];
        }
    }
}
//---------------------------------------------------------------------------
//  change matrix to the identity matirx
//---------------------------------------------------------------------------
template <class T, int R, int C>
matrix<T,R,C> SetToUnit(const matrix<T,R,C> & mt)
{
    
    for(int i =0; i<mt.Row; i++)
    {
        for(int j =0; j<mt.Col; j++)
        {
            if(i==j)
            {
   	         mt.table[i][i] = 1.0;
            }
        }
    }
    return mt;
}
//---------------------------------------------------------------------------
// Displaying the matrix contents
//---------------------------------------------------------------------------
/*template <typename U,int Q,int W>
void show(matrix<U,Q,W>& mt)
{
    for(int i =0; i<mt.Row; i++)
    {
        for(int j =0; j<mt.Col; j++)
        {
            std::cout<<mt.table[i][j]<<"\t";
        }
        std::cout<<std::endl;
    }
}*/
//---------------------------------------------------------------------------
// Displaying the complex matrix contents
//---------------------------------------------------------------------------
/*template <typename U,int Q,int W>
void cplx_show(matrix<U,Q,W>& mt)
{
    for(int i =0; i<mt.Row; i++)
    {
        for(int j =0; j<mt.Col; j++)
        {
            cplx_print(mt.table[i][j]);
        }
        std::cout<<std::endl;
    }
}*/
//---------------------------------------------------------------------------
// transpose
//---------------------------------------------------------------------------
template <class T, int R, int C>
matrix<T,R,C> Trans(const matrix<T,R,C> & mt)
{
matrix<T,R,C> res(mt.GetRow(),mt.GetCol());
    for (int i=0; i<mt.GetRow(); i++)
    {
        for (int j=0; j<(mt.GetCol()); j++)
        {
  	    res.table[i][j] = mt.table[j][i];
  	}
    }
   return res;
}
//---------------------------------------------------------------------------
// Trace:
//---------------------------------------------------------------------------
template <class T, int R, int C>
T matrix<T,R,C>::Trace(const matrix<T,R,C> & mt)
{
    T  Tr=0.0;
    for (int i=0; i<mt.Row; i++)
    {
        for (int j=0; j<(mt.Col); j++)
        {
            if(i==j)
            {
    	        Tr += mt.table[i][i];
    	    }
        }
    }
    return Tr;
}
//---------------------------------------------------------------------------
//         Overloading the == OPERATOR
//---------------------------------------------------------------------------
template <class T, int R, int C>
bool matrix<T,R,C>::operator== (const matrix<T,R,C>& mt)
{
 // Check if the matricies are the same size, if not return false.
    if ((this->Row != mt.Row) && (this->Col != mt.Col))
    {
        return false;
    }
 // Check if the elements are equal.
    bool flag = true;

    for(int i =0; i<Row; i++)
    {
        for(int j =0; j<Col; j++)
        {
            if (table[i][j] != mt.table[i][j])
            {
   	        flag = false;
  	     }
  	}
    }
    return flag;
}
//--------------------------------------------------------------------------
// Overloading the  = OPERATOR
//--------------------------------------------------------------------------
template <class T, int R, int C>
matrix<T,R,C> matrix<T,R,C>::operator= (const matrix<T,R,C> &mat)
{
    bool match  = CheckDimension(*this,mat);
    if(!match)
    {   
       throw std::invalid_argument("lhand matrix dimensios must match the rhand one.");
    }
    
    if(this!=&mat)
        for(int i =0; i<Row; i++)
        {
            for(int j =0; j<Col; j++)
            {
  	         table[i][j] = mat.table[i][j];
            }
        }
    matrix<T,R,C> res(*this);
    return res;       
}
//--------------------------------------------------------------------------
// Overloading the  + OPERATOR: result in A + B
//--------------------------------------------------------------------------
template <class T, int R, int C>
matrix<T,R,C> matrix<T,R,C>::operator + (const matrix<T,R,C> &mat) const
{
    bool match  = CheckDimension(*this,mat);
    if(!match){ throw std::invalid_argument("matrices dimensions do not match."); }
    
    matrix<T,R,C> res(Row,Col);
 
    for(int i =0; i<Row; i++)
    {
        for(int j =0; j<Col; j++)
        {
  	    res.table[i][j] = table[i][j]+mat.table[i][j];
        }
    }
    
    return res;    
}
//--------------------------------------------------------------------------
// Overloading the  - OPERATOR: result in A - B
//--------------------------------------------------------------------------
template <class T, int R, int C>
matrix<T,R,C> matrix<T,R,C>::operator - (const matrix<T,R,C> &mat) const
{
    bool match  = CheckDimension(*this,mat);
    if(!match){ throw std::invalid_argument("matrices dimensions do not match."); }
    
    matrix<T,R,C> res(Row,Col);
 
    for(int i =0; i<Row; i++)
    {
        for(int j =0; j<Col; j++)
        {
  	    res.table[i][j] = table[i][j]-mat.table[i][j];
        }
    }
    
    return res;    
}
//--------------------------------------------------------------------------
// Overloading the * OPERATOR: result in A * B
//--------------------------------------------------------------------------
template <class T, int R, int C>
matrix<T,R,C> matrix<T,R,C>::operator * (const matrix<T,R,C> &mat) const
{
    //bool match  = CheckDimension(*this,mat);
    if(Col!=mat.Row){ throw std::invalid_argument("matrices dimensions do not match."); }
    
   matrix<T,R,C> res(Row,mat.Col);
     // Multiplying matrix mt1 and mt2 and storing in array table.
    for(int i = 0; i < Row; ++i)
    {
        for(int j = 0; j < Col; ++j)
        {
            for(int k = 0; k < mat.Col; ++k)
            {
   	         res.table[i][j] += table[i][k] * mat.table [k][j];
            }
        }
    }
    return res;    
}
//--------------------------------------------------------------------------
// Scalar times matrix: a* A
//--------------------------------------------------------------------------
template <class T, int R, int C>
matrix<T,R,C> operator* (const T& scalar, const matrix<T,R,C>& mat)
{
     
    matrix<T,R,C> res(mat.Row,mat.Col);
     // Multiplying matrix mt1 and mt2 and storing in array table.
    for(int i = 0; i < mat.Row; ++i)
    {
        for(int j = 0; j < mat.Col; ++j)
        {
  	    res.table[i][j] = scalar*mat.table[i][j];
  	}
    }
    return res;    
}
//---------------------------------------------------------------------------
// Calculate:"Det" 
//---------------------------------------------------------------------------
template <class T, int R, int C>
T matrix<T,R,C>::Det( const matrix<T,R,C> &mt, const int &n)
{
    T c, r=1;
    for(int i = 0; i < n; i++)
    {
        for(int k = i+1; k < n; k++)
        {
  	    c = mt.table[k][i] / mt.table[i][i];
   	    for(int j = i; j < n; j++)
   	    {
   	        mt.table[k][j]= mt.table[k][j] - c*mt.table[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        r *=mt.table[i][i];
    }
    return r;
}
//---------------------------------------------------------------------------
// Compute Cofactor
//---------------------------------------------------------------------------
template <class T, int R, int C>
void matrix<T,R,C>::GetCofactor( const matrix<T,R,C> & A,  const matrix<T,R,C> & temp, const int &p, const int &q, const int &n)
{
    int i = 0, j = 0;
    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q)
            {
                temp.table[i][j++] = A.table[row][col];

                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
//---------------------------------------------------------------------------
// Recursive function for finding determinant of matrix.
// n is current dimension of A.
//---------------------------------------------------------------------------
template <class T, int R, int C>
T matrix<T,R,C>::determinant(const matrix<T,R,C> & A,const int &n)
{
    T D = 0.; // Initialize result

    //  Base case : if matrix contains single element
    if (n == 1)
        return A.table[0][0];

    matrix<T,R,C> temp(A.Row,A.Col); // To store cofactors

    T sign = 1.;  // To store sign multiplier

     // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of A[0][f]
        temp.GetCofactor(A, temp, 0, f, n);
        D += sign * A.table[0][f] * determinant(temp, n - 1);

        // terms are to be added with alternate sign
        sign = -sign;
    }

    return D;
}
//---------------------------------------------------------------------------
//  Function to Get adjoint of A[N][N] in adj[N][N].
//---------------------------------------------------------------------------
template <class T, int R, int C>
void matrix<T,R,C>:: adjoint(const matrix<T,R,C>& A , const matrix<T,R,C> & adj)
{
    if (A.Row == 1)
    {
        adj.table[0][0] = 1.;
        return;
    }

    // temp is used to store cofactors of A[][]
    T sign = 1;
    matrix<T,R,C> temp(A.Row,A.Col);

    for (int i=0; i<A.Row; i++)
    {
        for (int j=0; j<A.Row; j++)
        {
            // Get cofactor of A[i][j]
            temp.GetCofactor(A, temp, i, j, A.Row);

            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i+j)%2==0)? 1: -1;

            // Interchanging rows and columns to Get the
            // transpose of the cofactor matrix
            adj.table[j][i] = (sign)*(determinant(temp, A.Row-1));
        }
    }
}
//---------------------------------------------------------------------------
// Function to calculate and store inverse, returns false if matrix is singular
//---------------------------------------------------------------------------
template <class T, int R, int C>
bool matrix<T,R,C>::Inverse(const matrix<T,R,C>& A, const matrix<T,R,C> & inverse)
{
    // Find determinant of A[][]
    T det = determinant(A, A.Row);
    if (det == 0.)
    {
        std::cout << "Singular matrix, can't find its inverse\n";
        return false;
    }

    // Find adjoint
   matrix<T,R,C> adj(A.Row,A.Col);
    adj.adjoint(A, adj);

    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i=0; i<A.Row; i++)
        for (int j=0; j<A.Row; j++)
            inverse.table[i][j] = adj.table[i][j]/(det);

    return true;
}
//---------------------------------------------------------------------------
//check dimensionlity
//---------------------------------------------------------------------------
 template<class U,int Q,int W>
bool CheckDimension(const matrix<U,Q,W> &mat1,const matrix<U,Q,W> &mat2)
{
  bool flag = false;
  
  if(mat1.Row==mat2.Row && mat1.Col==mat2.Col) return true;
  
  else
    return flag;
}
//---------------------------------------------------------------------------
// Dagar
//---------------------------------------------------------------------------
/*
template <class T>
matrix<T> Dagar(const matrix<T> & mt)
{
    
  matrix<T> res(mt.Col,mt.Row);

    for (int i=0; i<mt.Row; i++)
    {
        for (int j=0; j<(mt.Col); j++)
        {
  	    res.table[i][j] = std::conj(mt.table[j][i]);
  	}
    }
    return res;
}
*/
//---------------------------------------------------------------------------
// Dual
//---------------------------------------------------------------------------
/*
template <class T>
void matrix<T>::dual(const matrix<T> & mt)
{
    Row = mt.Col;
    Col = mt.Row;
    Dim = Row * Col;

    table = new T*[Row];

    for(int k = 0; k < Row; k++)
    {
        table[k] = new T[Col];
    }

    for(int i = 0; i < Row; ++i)
    {
        for(int j = 0; j < Col; ++j)
        {
  	    table[i][j]={};
  	}
    }

    for (int i=0; i<Row; i++)
    {
        for (int j=0; j<(Col); j++)
        {
  	    table[i][j] =  std::conj(mt.table[j][i]);
  	}
    }
}
*/
//---------------------------------------------------------------------------
// A * B
//---------------------------------------------------------------------------
/*
template <class T> 
T braket(matrix<T> &b, matrix<T> &kt)
{
    //bool match  = CheckDimension(*this,mat);
    if(b.Col!=kt.Row){ throw std::invalid_argument("matrices dimensions do not match."); }
    int dim= b.Col * kt.Row;
    //bool match  = CheckDimension(*this,mat);
    //if(Col!=mat.Row){ throw std::invalid_argument("matrices dimensions do not match."); }
    T sum = static_cast<T>(0.0);
    //matrix<T> res(Row,mat.Col);
     // Multiplying matrix mt1 and mt2 and storing in array table.
    for(int i = 0; i < b.Row; ++i)
    {
        for(int j = 0; j < kt.Col; ++j)
        {
            for(int k = 0; k < b.Dim; ++k)
            {
   	        // res.table[i][j] += table[0][k] * mat.table [k][0];
   	        sum += b.table[i][k] * kt.table [k][j];
            }
        }
    }
    return sum;    
}
*/
//---------------------------------------------------------------------------
// GetRow
//---------------------------------------------------------------------------
template <class T, int R, int C>
int matrix<T,R,C>::GetRow() const
{
    return Row;
}
//---------------------------------------------------------------------------
// GetCol
//---------------------------------------------------------------------------
template <class T, int R, int C>
int matrix<T,R,C>::GetCol() const
{
    return Col;
}
//---------------------------------------------------------------------------
// GetElement
//---------------------------------------------------------------------------
template <class T, int R, int C>
T matrix<T,R,C>::GetElement(const int &row, const int &col) const
{  
   return table[row][col];   
}
//---------------------------------------------------------------------------
// GetSize
//---------------------------------------------------------------------------
template <class T, int R, int C>
int matrix<T,R,C>::GetSize() const
{  
   return Dim;
}
//---------------------------------------------------------------------------
// GGauss Elimination method
//---------------------------------------------------------------------------
/*
template <class T, int R, int C>
void GaussElimination(matrix<T,R,C> &mt)
{
    int n = mt.GetRow();
    double x[n];
    // mt must be the Augmented matrix
    for(int i =0; i<n;i++)
    {
        if(mt.table[i][i]==0) //if the pivot element is zero, change this row with the one below
        {
            for(int j =0; j<=n; j++) // for each element in col:
            {   //replace each it with the one below 
                double temp = mt.table[i][j];  
                mt.table[i][j] = mt.table[i+1][j];
                mt.table[i+1][j] = temp;
            }
        }
        
        for(int j =i+1; j<n; j++) // perform the gauss elimination
        {
            double factor = mt.table[j][i]/mt.table[i][i];
            for(int k=0;k<=n;k++) 
            {
                mt.table[j][k] = mt.table[j][k] - factor * mt.table[i][k];
            }
        }
    }
    
    for (int i=n-1;i>=0;i--)  // back substitution             
    {                         
        x[i]=mt.table[i][n];   // this is the last varlible of               
        for (int j=i+1;j<n;j++)
        {
            if (j!=i)
            {    
                x[i]=x[i]-mt.table[i][j]*x[j];
            }  
        } 
        x[i]=x[i]/mt.table[i][i];  
    }
    
    for(int i =0; i<n;i++)
    {
        std::cout<<x[i]<<std::endl;
    } 
}
*/
//---------------------------------------------------------------------------
// Overloading the insertion << operator
//---------------------------------------------------------------------------
template <typename U,int Q,int W>
std::ostream& operator<<(std::ostream& output,
const matrix<U,Q,W>& mt)
{
//output << "[ ";
    for(int i =0; i<mt.Row; i++)
    {
        for(int j =0; j<mt.Col; j++)
        {
            //output<<mt.table[i][j]<<"\t";
            cplx_print(mt.table[i][j]);
        }
        output<<"\n";
    }
// output << "]\n";
return output;
}
//---------------------------------------------------------------------------
//				Kronecker-Product
//---------------------------------------------------------------------------
template <class T, int R, int C>
matrix<T,R,C> KroneckerProduct(const matrix<T,R,C>& mt1, const matrix<T,R,C>& mt2)
{   
    //int row = mt1.GetRow() * mt2.GetRow();
    //int col = mt1.GetCol() * mt2.GetCol();
    int rowA = mt1.GetRow();
    int colA = mt1.GetCol();
    int rowB = mt2.GetRow();
    int colB = mt2.GetCol();
    matrix<T,R,C> res((rowA*rowB),(colA*colB));
    
    for (int i = 0; i < rowA; i++)
    {
        // k loops till rowb
        for (int k = 0; k < rowB; k++)
        {
            // j loops till cola
            for (int j = 0; j < colA; j++)
            {
                // l loops till colb
                for (int l = 0; l < colB; l++)
                {
  	   	     res.table[i*rowB+k][j*colB+l]=mt1.table[i][j]*mt2.table[k][l]; 	   		
  	        }
            }
  	
        }
    }
     
    return res;    
}
//---------------------------------------------------------------------------
//  matrix class destructor: where we free all allocated memories
//---------------------------------------------------------------------------
template <class T, int R, int C>
matrix<T,R,C>::~matrix()
{
    for(int i = 0; i < Row; ++i)
    {
        delete [] table[i];
    }
   delete [] table;
}
#endif//MATRIX_TPP

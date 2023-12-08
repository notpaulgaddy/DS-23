#ifndef MATRIX
#define MATRIX
#include <vector>
#include <iostream>
class Matrix{

    public:
        Matrix(unsigned int rows, unsigned int columns, double fill);//original Matrix with the 3 params
        Matrix (const Matrix&m) { copy(m); }
        Matrix();//define it
        int num_rows() const { return numRows; }//func for the number of rows
        int num_cols() const { return numCols; }//func for the number of cols
        void clear();//func to reset
        void multiply_by_coeffecient(double coeffecient);//func to multiply each by the coeff
        bool swap_row(unsigned int sourceRowNum, unsigned int targetRowNum);
        void transpose();//transpose function
        bool add(const Matrix& B);//func to add
        bool subtract(const Matrix& B);//func to subtract
        bool get(unsigned int row,unsigned int column, double& output) const;//getter
        bool set(unsigned int row,unsigned int column, double value);//setter
        double* get_row(unsigned int retrievedRow) const;//get the value of the row
        double* get_col(unsigned int retrievedCol) const;//get the value of the column
        Matrix* quarter();//quarter function
        bool operator== (const Matrix& b);//equals operator
        bool operator!= (const Matrix& b);//doesnt equal operator
        Matrix& operator=(const Matrix& v); 
        ~Matrix();
    private:
        void copy(const Matrix& b);
        unsigned int numRows;
        unsigned int numCols;
        // std::vector<int> theMatrix;
        double **data;//array to hold the values, array of arrays
        // int operator [](int i) const    {return arr[i];}
}; 
std::ostream& operator<< (std::ostream& out, const Matrix& m);
#endif
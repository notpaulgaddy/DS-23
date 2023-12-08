#include "Matrix.h"
#include <iostream>
#include <ostream>
#include <vector>
#include <cmath>
using namespace std;
Matrix::Matrix(){
    numRows = 0;//initialize the number of rows to 0
    numCols = 0;//initialize the number of cols to 0
}
Matrix::~Matrix() {
   if (numRows != 0 || numCols != 0) {
        clear();
    }
}

void Matrix::copy(const Matrix& m) {
    numRows = m.num_rows();//call the number of rows
    numCols = m.num_cols();//call the number of cols
    data = new double *[ m.num_rows()];//double pointer with value of rows
    for (int i = 0; i <  m.num_rows(); i++){
        // create matrix data
        data[i] = new double[m.num_cols()];
        // new array for each row then fill each row with the number fill
        for (int j = 0; j < m.num_cols(); j++){
            double value = 0;
            if(m.get(i,j,value)){
                data[i][j] = value; // builds the matrix
            }
        }
    }
}
Matrix& Matrix::operator=(const Matrix& v) {
    if (*this != v) {
        if (numRows != 0 || numCols != 0) {
            clear();
        }
        copy(v);
    }
    return *this;
}
Matrix::Matrix(unsigned int rows, unsigned int columns, double fill){
    numRows = rows;
    numCols = columns;
    data = new double *[rows];
    for (int i = 0; i < rows; i++){
        // create matrix data
        data[i] = new double[columns];
        // new array for each row then fill each row with the number fill
        for (int j = 0; j < columns; j++) {
            data[i][j] = fill; // builds the matrix
        }
    }
}

void Matrix::clear(){
    for (int i = 0; i < numRows; i++)
    {
        delete[] data[i];//delete the matrix items
    }
    delete[] data;//delete the individual matrix
    numRows = 0;//set rows back to 0
    numCols = 0;//set cols back to 0
}
bool Matrix::get(unsigned int row, unsigned int column, double &output) const
{
    if (row < numRows && column < numCols)
    {
        // then the value at arow,col should be stored in the double
        //  output = m1[row][column];
        output = data[row][column];
        return true;
    }
    return false;
}
bool Matrix::set(unsigned int row, unsigned int column, double value) 
{
    if (row < numRows && column < numCols)
    {
        // then the value at arow,col should be stored in the double
        //  output = m1[row][column];
        data[row][column] = value;
        return true;
    }
    return false;
}
void Matrix::multiply_by_coeffecient(double coeffecient){
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++){
            data[i][j] *= coeffecient;//multiply by the specified coeffecient
        }
    }
}
bool Matrix::swap_row(unsigned int sourceRowNum, unsigned int targetRowNum)
{
    if (numRows > sourceRowNum && numRows > targetRowNum)
    {
        // switch values in the 2 rows
        double *temp = data[sourceRowNum];          // store address to SRN
        data[sourceRowNum] = data[targetRowNum]; // set SRN to address of TRN
        data[targetRowNum] = temp;               // set TRN address to temp address
        return true;
    }
    return false;
}
void Matrix::transpose(){
    unsigned int newRows = numCols;
    unsigned int newCols = numRows;
    double **a = new double *[newRows];
    for (int i = 0; i < newRows; i++)
    {
        a[i] = new double[newCols];
        for (int j = 0; j < newCols; j++)
        {
            a[i][j] = data[j][i];
        }
    }
    clear();
    data = a;
    numRows = newRows;
    numCols = newCols;
}
bool Matrix::add(const Matrix &B)
{
    if (B.num_rows() == numRows && B.num_cols() == numCols)
    { // if dimesions between both objects match
        for (int i = 0; i < B.num_rows(); i++)
        {
            for (int j = 0; j < B.num_cols(); j++)
            {
                // data = A
                double k = 0;
                if (B.get(i, j, k))
                { // k is the value of the set double value
                    data[i][j] += k;
                }
            }
        }
        return true;
    }
    return false;
}
bool Matrix::subtract(const Matrix &B)
{
    if (B.num_rows() == numRows && B.num_cols() == numCols)
    { // if dimesions between both objects match
        for (int i = 0; i < B.num_rows(); i++)
        {
            for (int j = 0; j < B.num_cols(); j++)
            {
                // data = A
                double k = 0;
                if (B.get(i, j, k))
                { // k is the value of the set double value
                    data[i][j] -= k;
                }
            }
        }
        return true;
    }
    return false;
}
double* Matrix::get_row(unsigned int retrievedRow) const{
    if (retrievedRow >= numRows) {
        return NULL;
    }
    double* ret = new double[numCols];
    for (int i = 0; i < num_cols(); i++) {
        ret[i] = data[retrievedRow][i];
    }
    return ret;
}
double* Matrix::get_col(unsigned int retrievedCol) const{
   if (retrievedCol >= numCols) {
        return NULL;
    }
    double* ret = new double[numRows];
    for (int i = 0; i < num_cols(); i++) {
        ret[i] = data[i][retrievedCol];
    }
    return ret;
}
Matrix* Matrix::quarter(){
    //do math.ceil
    //write destructor and logic error
    int new_rows = (int)(numRows/2.0+0.5);//get the number of rows per new matrix
    int new_cols = (int)(numCols/2.0+0.5);//get the number of columns per new matrix
    // int new_rows = (int)(numRows/2);//get the number of rows per new matrix
    // int new_cols = (int)(numCols/2);//get the number of columns per new matrix
    Matrix* quadrants = new Matrix[4];//4 quadrants with the size of 4
    //set the size and width of the quandrant
    quadrants[0] = Matrix(new_rows, new_cols,0);
    quadrants[1] = Matrix(new_rows, new_cols,0);
    quadrants[2] = Matrix(new_rows, new_cols,0);
    quadrants[3] = Matrix(new_rows, new_cols,0);//4 quadrants with same size
    for(int i=0;i<new_rows;i++){
        for(int j=0;j<new_cols;j++){
            // quadrants[0].data[i][j] = data[i][j];
            quadrants[0].set(i,j,data[i][j]);//EXPLAIN THESE AFTER
            quadrants[1].set(i,new_cols-j-1,data[i][numCols-j-1]);
            quadrants[2].set(new_rows-i-1,j,data[numRows-i-1][j]);
            quadrants[3].set(new_rows-i-1,new_cols-j-1,data[numRows-i-1][numCols-j-1]);
        }
    }
    return quadrants;
    // quadrants[0] = Matrix(new_rows,new_cols);
}
std::ostream& operator<< (std::ostream& out, const Matrix& m){
// std::ostream& operator<< (std::ostream& out, const Matrix m){
    out << endl << m.num_rows() << " x " << m.num_cols() << " matrix:";
    out << endl << "[ ";
    for(int i=0;i< m.num_rows();i++){
        for(int j=0;j< m.num_cols();j++){
            double value;
            if(j==0 && i>0){
                out << "  ";
            }
            //call m.get, pass in m and j in output
            if(m.get(i,j,value) == true){
                out << value;
            }
            // if(j==columns-1){
            if(j==m.num_cols()-1){
                if(i<m.num_rows()){
                  out << endl;  
                }
                
            }else{
                out << " ";
            }
        }
    }
    out << "]" << endl;
    // out << endl << "Completed all simple tests." << endl;
    // out << "Completed all student tests." << endl;
    // for(int i=0;i<quadrants.size();i++){

    // }
    //delete data
    //
    return out;
}

bool Matrix::operator==(const Matrix& b){
    if(b.num_rows() == numRows && b.num_cols() == numCols){
        for(int i=0;i < b.num_rows();i++){
            for(int j=0;j < b.num_cols();j++){
                double v1;
                if(b.get(i,j,v1) && v1!=data[i][j]){//v1 and 2 are the fill values
                    return false;
                }
            }
        }
        return true;
    }
    return false;
    // return(b.num_rows() == m.num_rows() && b.num_cols() == m.num_cols());
}
bool Matrix::operator!=(const Matrix& b){
    if(b.num_rows() == numRows && b.num_cols() == numCols){
        for(int i=0;i < b.num_rows();i++){
            for(int j=0;j < b.num_cols();j++){
                double v1;
                if(b.get(i,j,v1) && v1!=data[i][j]){//v1 and 2 are the fill values
                    return true;
                }
            }
        }
        return false;
    }
    return true;
}
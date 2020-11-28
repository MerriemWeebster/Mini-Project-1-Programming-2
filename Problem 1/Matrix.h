#include<iostream>
using namespace std;
#ifndef MATRIX_H
#define MATRIX_H
class Matrix
{
friend ostream& operator<<(ostream& out, Matrix& x); // Overloaded Insertion Operator
friend istream& operator>>(istream& in, Matrix& x); // Overloaded Extraction Operator 

public:
    Matrix(int r=2,int c=3); // Default Constructor(Initializes Rows To 2 And Columns To 3)
    Matrix(const Matrix& x); // Copy Constructor
    ~Matrix(); // Destructor
    Matrix operator-(); // Negation Operator(Multiplies Each Element of The Matrix By 1)
    Matrix operator-(const Matrix& x); // Subtraction Operator(Subtracts Corresponding Elements Of 2 Matrices With Equal Dimensions)
    Matrix& operator()(Matrix& x); // Non-Const Indices Operator
    const Matrix& operator()(const Matrix& x);// Const Indices Operator
    Matrix& operator++(); // Overloaded Increment Operator
    bool operator==(const Matrix& x);//Overloaded Equality Operator
    bool operator!=(const Matrix& x);// Overloaded Inequality Operator
    Matrix get_matrix_elements();// Getter Function
    void set_matrix_elements();// Setter Function
    Matrix& operator--();// Overloaded Decrement Operator
    const Matrix& operator=(const Matrix& x); // Overloaded Assignment Operator
    Matrix& operator*(const Matrix& x); // Overloaded Multiplication Operator(Multiplies Each Row Element With The Corresponding Column Element Of The Second Matrix, They Must Be Of Compatible Sizes)
    Matrix& operator+=(const Matrix& x); // Overloaded Shorthand Additon Operator
    Matrix& operator-=(const Matrix& x); // Overloaded Shorthand Subtraction Operator

private:
    double** mtx;
    int r,c;

};
#endif
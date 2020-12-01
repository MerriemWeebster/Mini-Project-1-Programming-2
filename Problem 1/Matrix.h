#include<iostream>
using namespace std;
#ifndef MATRIX_H
#define MATRIX_H
class Matrix
{
friend const Matrix operator+(const Matrix &a1, const Matrix &a2); //addition operator: adds the two objects in the argument
friend const Matrix operator-(const Matrix &a1, const Matrix &a2); //subtraction operator: subtracts the two objects in the argument
friend ostream& operator<<(ostream& out, Matrix& x); // Overloaded Insertion Operator
friend istream& operator>>(istream& in, Matrix& x); // Overloaded Extraction Operator

public:
    Matrix(int row=2,int col=3); // Default Constructor(Initializes Rows To 2 And Columns To 3)
    Matrix(const Matrix& x); // Copy Constructor
    ~Matrix();// Destructor
    Matrix operator+(const Matrix& x); //addition operator: adds calling object with the object in argument
    Matrix operator-(); // Negation Operator(Multiplies Each Element of The Matrix By 1)
    Matrix operator-(const Matrix& x); // Subtraction Operator(Subtracts Corresponding Elements Of 2 Matrices With Equal Dimensions)
    double operator()(int row, int col); // Non-Const Indices Operator
    const double operator()(int row, int col) const;// Const Indices Operator
    Matrix& operator++(); // Overloaded Increment Operator
    bool operator==(const Matrix& x);//Overloaded Equality Operator
    bool operator!=(const Matrix& x);// Overloaded Inequality Operator
    Matrix get_matrix_elements(int,int);// Getter Function
    void set_matrix_elements(int r,int c,double val);// Setter Function
    Matrix& operator--();// Overloaded Decrement Operator
    const Matrix& operator=(const Matrix& x); // Overloaded Assignment Operator
    Matrix operator*(const Matrix& x); // Overloaded Multiplication Operator(Multiplies Each Row Element With The Corresponding Column Element Of The Second Matrix, They Must Be Of Compatible Sizes)
    Matrix& operator+=(const Matrix& x); // Overloaded Shorthand Additon Operator
    Matrix& operator-=(const Matrix& x); // Overloaded Shorthand Subtraction Operator

private:
    double** mtx;
    int r,c;

};



const Matrix operator+(const Matrix &a1, const Matrix &a2)
{ //addition operator: adds the two objects in the argument
    if(a1.r!=a2.r || a1.c!=a2.c){ // checking size, if size does not match then function directly returns false
      cout<<"SIZE Mismatch!";
      exit(1);
    }
    Matrix a3(a1.r,a1.c); //REVIEW!! is this object declaration correct?
    
    for(int i=0; i<a1.r; i++){
    for(int j=0; j<a1.c; j++){ //Double for-loop to use all elements
    a3.mtx[i][j]=a1.mtx[i][j]+a2.mtx[i][j];
    }
    }
    return a3;
}

//Prem Rajendran - b00084833

const Matrix operator-(const Matrix& a1, const Matrix& a2) //subtraction operator to subtract two different objects
{
    if (a1.r != a2.r || a1.c != a2.c) //size check
    {
        cout << "The matrices cannot be subtracted as they are of different sizes!";
        exit(1);
    }
    Matrix diff(a1.r, a1.c);
    for (int i = 0; i < a1.r; i++)
    {
        for (int j = 0; j < a1.c; j++)
        {
            diff.mtx[i][j] = a1.mtx[i][j] - a2.mtx[i][j];
        }
    }
    return diff;
}

ostream& operator<<(ostream& out, Matrix& x) //output stream
{
    for (int i = 0; i < x.r; i++)
    {
        for (int j = 0; j < x.c; i++)
        {
            out << x.mtx[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

istream& operator>>(istream& in, Matrix& x) //input stream
{
    for (int i = 0; i < x.r; i++)
    {
        for (int j = 0; j < x.c; j++)
        {
            in >> x.mtx[i][j];
        }
    }
    return in;
}

#endif
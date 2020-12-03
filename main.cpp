//Author - Daniyal Khan b00082137
//Problem 2 Solution

#include <iostream>
#include <cmath>
#include "Matrix.h"
using namespace std;

double SumMatrixElements (const Matrix &); //Decleration of sum func
double stdev (const Matrix &); //Decleration of standard dev func

int main()
{

	//Create 3 different matrices
	Matrix a;
	Matrix b(3, 3);
	Matrix c(b);
	
	//Take in values for all 3
	cout<<"Enter The Matrix a(Size:2x3):";
	cin >> a;
	cout<<"Enter The Matrix b(Size:3x3):";
	cin >> b;
	cout<<"Enter The Matrix c(Size:3x3):";
	cin >> c;
	
	//Output sum and standard deviation for all 3 matrices
	cout << "Sum of Matrix a: " << SumMatrixElements(a) << endl;
	cout << "Standard Deviation of Matrix a: " << stdev(a) << endl;
	cout << "Sum of Matrix b: " << SumMatrixElements(b) << endl;
	cout << "Standard Deviation of Matrix b: " << stdev(b) << endl;
	cout << "Sum of Matrix c: " << SumMatrixElements(c) << endl;
	cout << "Standard Deviation of Matrix c: " << stdev(c) << endl;

    cout<<"\n---------------------------------Testing Out All Memebers Of The Matrix Class-------------------------------------------\n\n";

    Matrix A(2, 2); //testing default constructor
    Matrix B(A); //testing copy constructor
    cout << "Enter Matrix A (Size:2x2):";
	cin >> A; //testing extraction operator
	cout<<"Enter Matrix B (Size:2x2):";
	cin>> B;
	cout << "\nMatrix A : " << endl << A << endl;
	cout << "\nMatrix B : " << endl << B << endl;
	cout<<"Matrix A After A-B:"<<endl <<(A-B)<<endl; // Testing The subtraction operator
	cout << "Matrix -B : " << endl << -B << endl; //testing negation operator
	cout << "Element at row 1, column 0 of Matrix A : " << A(1, 0) << endl; //testing rvalue indices operator
	A(0, 0) = 5; //testing lvalue indices operator
	cout << "\nMatrix A after A(0, 0) = 5 : " << endl << A << endl;
	Matrix C = A; //testing assignment operator
	cout << "C = A gives us : " << endl << C << endl;
	--C; //testing decrement operator
	cout << "--C = " << endl << C << endl;
	++C; //Testing The Increment Operator
	cout << "++C = " << endl << C << endl;
	cout << "A==B = "<<(A==B)<<endl; // Testing The Equality Operator
	cout << "A!=B = "<<(A!=B)<<endl; // Testing The Inequality Operator
	cout << "A * B = "<<endl<<(A*B)<<endl; // Testing The Matrix Multiplication Operator
	cout<<" 5 * A = "<<endl<<(A*5)<<endl; // Testing The Scalar Multiplication Operator
	B += A; //testing shorthand addition operator
	cout << "B += A : " << endl << B << endl;
	C -= B; //testing shorthand subtraction operator
	cout << "C -= B : " << endl << C << endl;
    
    
    
    return 0;
}
	
    


double SumMatrixElements (const Matrix &m) //Implementation of sum func
{
    double sum = 0; //Declare sum double
    int r = m.get_rows(), c = m.get_cols(); //Store length of rows and cols in int r and c

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            sum += m(i, j); //Loop through all elements and add them to sum
        }
    }
    
    return sum; //Return sum
}

double stdev (const Matrix &m) //Implementation of standard dev func
{
    int r = m.get_rows(), c = m.get_cols(); //Store length of rows and cols in int r and c
    double avg = SumMatrixElements(m) / (r * c), //Calculate average
    devSum = 0; //Used in loop for numerator of standard dev
    
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            devSum += pow((m(i, j) - avg), 2); //Get the numerator (deviation sum) by going through each row and col
        }
    }
    
    double standardDev = sqrt(devSum / (r * c - 1)); //Standard Dev calculated using formula
    return standardDev; //Return standardDev
}
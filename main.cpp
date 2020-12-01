//Author - Daniyal Khan b00082137

#include <iostream>
#include <cmath>
#include "Matrix.h"
using namespace std;

double SumMatrixElements (const Matrix &); //Decleration of sum func
double stdev (const Matrix &); //Decleration of standard dev func

int main()
{
	Matrix a;
	Matrix b(3, 3);
	Matrix c(b);
	
	cin >> a;
	cin >> b;
	cin >> c;
	
	cout << "Sum of Matrix a: " << SumMatrixElements(a) << endl;
	cout << "Standard Deviation of Matrix a: " << stdev(a) << endl;
	cout << "Sum of Matrix b: " << SumMatrixElements(b) << endl;
	cout << "Standard Deviation of Matrix b: " << stdev(b) << endl;
	cout << "Sum of Matrix c: " << SumMatrixElements(c) << endl;
	cout << "Standard Deviation of Matrix c: " << stdev(c) << endl;
	
    return 0;
}

double SumMatrixElements (const Matrix &m) //Implementation of sum func
{
    int sum = 0; //Declare sum int
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
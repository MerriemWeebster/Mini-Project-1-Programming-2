#include <iostream>
#include"Matrix.h"
using namespace std;
int main()
{
	Matrix A(2, 2); //testing default constructor
	cout << "Enter Matrix A : ";
	cin >> A; //testing extraction operator
	cout << "\nMatrix A : " << endl << A << endl;
	Matrix B(A); //testing copy constructor
	cout << "Matrix -B : " << endl << -B << endl; //testing negation operator
	cout << "Element at row 1, column 0 of Matrix A : " << A(1, 0) << endl; //testing rvalue indices operator
	A(0, 0) = 5; //testing lvalue indices operator
	cout << "\nMatrix A after A(0, 0) = 5 : " << endl << A << endl;
	Matrix C = A; //testing assignment operator
	cout << "C = A gives us : " << endl << C << endl;
	--C; //testing decrement operator
	cout << "--C = " << endl << C << endl;
	B += A; //testing shorthand addition operator
	cout << "B += A : " << endl << B << endl;
	C -= B; //testing shorthand subtraction operator
	cout << "C -= B : " << endl << C << endl;
}
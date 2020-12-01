#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
	Matrix A;
	Matrix B(2, 2);
	Matrix C(B);
	cin >> A;
	cout << A << endl;
	cout << B << endl;
	cout << C << endl;
    return 0;
}
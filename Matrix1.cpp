 #include<iostream>

 using namespace std;
 
 //SAADs PART
 #include "Matrix.h"
Matrix::~Matrix(){ // destructor
    delete [] mtx;
} 
Matrix Matrix::operator-(){ //negate every element in the matrix
for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){ //Double for-loop to multiply all elements
        mtx[i][j]=mtx[i][j]*-1;
    }
}
    return *this; // for cascading
}
Matrix Matrix::operator+(const Matrix& x){
if(r!=x.r || c!=x.c){ // checking size, if size does not match then function directly returns false
      cout<<"SIZE Mismatch!";
      exit(1);
    }
    
    for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){ //Double for-loop to use all elements
    mtx[i][j]=mtx[i][j]+x.mtx[i][j];
    }
    }
    return *this;
}

bool Matrix::operator==(const Matrix& x){
        if(r!=x.r || c!=x.c){ // checking size, if size does not match then function directly returns false
            cout<<"SIZE Mismatch!";
            return false;
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){ //double for loop to check every element
            if(mtx[i][j]!=x.mtx[i][j]){ // condition, even if they are not equal once, loop will exit and false will be returned.
                return false;
            }
            }   
        }
        return true; //otherwise, they are equal
    }
bool Matrix::operator!=(const Matrix& x){
    if(r!=x.r || c!=x.c){ // checks if the size is equal. if they are not equal then function directly returns false.
            cout<<"SIZE Mismatch!";
            return false;
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
            if(mtx[i][j]==x.mtx[i][j]){ // if they are equal even once, then the fucntion will exit loop and return false
                return false;
            }
            }   
        }
        return true; // otherwise they are not equal
    }// Overloaded Inequality Operator



//Author - Akchunya Chanchal

Matrix Matrix::get_matrix_elements(int r,int c) // To Get The Value Of A Specific Element Of The Matrix
{
    return this->mtx[r][c];
}

void Matrix::set_matrix_elements(int r, int c, double val) // To Set The Value Of A Specific Element Of The Matrix
{
    this->mtx[r][c] = val;

}

Matrix& Matrix::operator--() // To Decrement Each Value In The Matrix 
{
    for(int i=0;i<r;++i) // To Loop Through The Rows
    {
        for(int j=0;j<c;++j) // To Loop Through The Columns
        {
            --mtx[i][j]; // Decrementing The Element
        }
    }

    return *this; // We Return The Address As The Function Is Cascading 
}


const Matrix& Matrix::operator=(const Matrix& x) // To Assign The Values Of A Matrix to Another Matrix 
{
    if (this == &x) // Checking If The Matrices Are The Same
	 {
		 return *this;
	 }

	 if (this->r != x.r || this->c != x.c) // Checking To See If The Two Matrices Have Equal Dimensions
	 {
		 for(int i=0;i<this->r;++i)
         {
             delete [] this->mtx[r]; // We Free Up The Memory From The Heap By Deleting Row By Row The Existing Array
         }
         delete[] this->mtx; // We Delete The Intial Matrix
         
        double**mtx = new double*[x.r];// We Intialise
        for(int i=0;i<x.r;++i)         // The New Array
        {                              // To The Size
            mtx[i] = new double[x.c];  // Of The Array
        }                              // To Be Copied
        this->r = x.r; // Assigning The New No. Of Rows To The Calling Element
        this->c = x.c; // Assigning The New No. Of Columns To The Calling Element

    }

	 for (int i = 0; i < this->r; ++i)
	 {
		 for(int j=0;j< this->c;++j)
         {
             this->mtx[i][j] = x.mtx[i][j];
         }
	 }

	 return *this;
}

Matrix & Matrix::operator+= (const Matrix & x)
{
    if (this->r != x.r || this->c != x.c) // Checking To See If The Two Matrices Are Of Equal Dimensions
	{
		cout << "These Cannot Be Added";
		exit(1);
	}

	for (int i = 0; i < this->r; ++i)
	{
		for(int j=0; j<this->c; ++j)
        {
            this->mtx[i][j]+=x.mtx[i][j]; // Adding The Matrix Values Of The Second Matrix To The Calling Matrix
        }
	}

	return *this;



}

Matrix & Matrix::operator-= (const Matrix & x)
{
    if (this->r != x.r || this->c != x.c) // Checking To See If The Two Matrices Are Of Equal Dimensions
	{
		cout << "These Cannot Be Subtracted";
		exit(1);
	}

	for (int i = 0; i < this->r; ++i)
	{
		for(int j=0; j<this->c; ++j)
        {
            this->mtx[i][j]-=x.mtx[i][j]; // Subtracting The Matrix Values Of The Second Matrix To The Calling Matrix
        }
	}

	return *this;
}

Matrix Matrix::operator*(const Matrix& x)
{
    if(this->c!=x.r) // Condition For Multiplying 2 Matrices - The No. Of Columns In The First Matrix Must Be Equal To The No. Of Rows In The Second Matrix
    {
        cout<<"The Elements Cannot Be Multiplied Together";
        exit(1);
    }
    int num_rows = this->r;
    int num_columns = x.c;
    Matrix product(num_rows,num_columns); 
    for(int i=0;i<num_rows;++i)
    {
        for(int j=0;j<num_columns;++j)
        {
            int k = 0;
            while(k<num_rows)
            {
                product.mtx[i][j]+=(this->mtx[i][k]*x.mtx[k][j]); // Multiplying The Row Elements Of The Calling Matrix With The Column Elements Of The 2nd Matrix
                k++;
            }
        }
    }

    return product;
}

// Prem Rajendran - b00084833

Matrix::Matrix(int row, int col) //default parameterized constructor
{
    r = row;
    c = col;
    mtx = new double * [row];
    for (int i = 0; i < r; i++) //loop to dynamically allocate and initialize at the same time
    {
        for (int j = 0; j < c; j++)
        {
            mtx[i] = new double[col];
            mtx[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix& x) //copy constructor
{
    r = x.r;
    c = x.c;
    mtx = new double* [r];
    for (int i = 0; i < r; i++) //loop to dynamically allocate and copy at the same time
    {
        for (int j = 0; j < c; j++)
        {
            mtx[i] = new double[c];
            mtx[i][j] = x.mtx[i][j];
        }
    }
}

Matrix Matrix::operator-(const Matrix& x) //subtraction operator to subtract from existing object
{
    if (r != x.r || c != x.c)
    { //size check
        cout << "The matrices cannot be subtracted as they are of different sizes!";
        exit(1);
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            mtx[i][j] = mtx[i][j] - x.mtx[i][j];
        }
    }
    return *this;
}

double Matrix::operator()(int row, int col) //lvalue indices operator
{
    if (row < 0 || row > r || col < 0 || col > c)
    {
        cout << "Invalid indices!!" << endl;
        exit(0);
    }
    return mtx[row][col];
}

const double Matrix::operator()(int row, int col) const //rvalue indices operator
{
    if (row < 0 || row > r || col < 0 || col > c)
    {
        cout << "Invalid indices!!" << endl;
        exit(0);
    }
    return mtx[row][col];
}
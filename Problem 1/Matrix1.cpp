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
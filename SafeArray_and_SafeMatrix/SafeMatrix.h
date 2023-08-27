#ifndef SAFEMATRIX_H
#define SAFEMATRIX_H

#include <cstdlib>
#include <iostream>
#include "SafeArray.cpp"
template <class T>
class SafeMatrix
{
    private:
	int rows,cols;
	SafeArray<SafeArray<T>> m;

    public:
	//default constructor sets value to default
        SafeMatrix();
        //2 parameter constructor calls safeArray to store cols and saves the row for itself
        SafeMatrix(int r, int c);
        //returns the rows of the array
        int length() const;
        //overloaded operator to store values
        SafeArray<T>& operator [] (int index);
        //overloaded operator to return values only
        const SafeArray<T>& operator [] (int index) const;

};



#endif

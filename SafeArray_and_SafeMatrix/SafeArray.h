#ifndef SAFEARRAY_H
#define SAFEARRAY_H

#include <cstdlib>
#include <iostream>

template <class T>
class SafeArray
{
    private:
	int size;
        T* array;
    public:
        //default constructor initializes the values to null
        SafeArray();
        //1 parameter constructor saves the size of the dynamic array
        SafeArray(int s);
        //returns the length of the SafeArray class
        int length() const;
        //operator overloaded to accept input
        T& operator [] (int index);
        //operator overloaded to return value
        const T& operator [] (int index) const;

	    // destructor
        ~SafeArray();

	    // copy constructor
	    SafeArray(const SafeArray<T>& other);

	    // assignment operator
	    SafeArray<T>& operator = (const SafeArray<T>& other);
};

#endif

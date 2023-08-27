#include "SafeArray.h"

template <class T>
SafeArray<T>::SafeArray() : size(0), array(NULL)
{
    // empty
}

template <class T>
SafeArray<T>::SafeArray(int s) : size(s), array(new T[s])
{
    // empty
}

template <class T>
int SafeArray<T>::length() const
{
    return size;
}

template <class T>
T& SafeArray<T>::operator [] (int index)
{
    if (index < 0 || index >= size)
    {
	    std::cout << "Index: " << index
		          << " is out of bounds."
				  << std::endl;
	    std::exit(1);
    }
    return array[index];
}

template <class T>
const T& SafeArray<T>::operator [] (int index) const
{
    if (index < 0 || index >= size)
    {
	    std::cout << "Index: " << index
		          << " is out of bounds."
				  << std::endl;
	    std::exit(1);
    }
    return array[index];
}

template <class T>
SafeArray<T>::~SafeArray()
{
    if (array != NULL)
    {
        delete [] array;
        array = NULL;
    }
}

template <class T>
SafeArray<T>::SafeArray(const SafeArray<T>& other) : size(other.size),
	                                             array(new T[other.size])
{
    for (int i = 0; i < size; i++)
    {
       array[i] = other.array[i];
    }
}

template <class T>
SafeArray<T>& SafeArray<T>::operator = (const SafeArray<T>& other)
{
    if(this != &other)
    {
        if (array != NULL)
	    {
            delete [] array;
	    }
        size = other.size;
	    array = new T[size];
	    for (int i = 0; i < size; i++)
	    {
            array[i] = other.array[i];
	    }
    }
    return *this;
}

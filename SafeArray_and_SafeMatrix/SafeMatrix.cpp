#include "SafeMatrix.h"

template<class T>
SafeMatrix<T>::SafeMatrix():rows(0), cols(0), m(NULL)
{
	//empty
}

template<class T>
SafeMatrix<T>::SafeMatrix(int r, int c):rows(r), cols(c), m(SafeArray<SafeArray<T>>(rows))
{
	for(int i=0; i<rows; i++)
	{
		m[i]=SafeArray<T>(cols);
	}
}

template<class T>
SafeArray<T>& SafeMatrix<T>::operator [] (int index)
{
	if (index < 0 || index >= rows)
	    {
		    std::cout << "Index: " << index
			          << " is out of bounds."
					  << std::endl;
		    std::exit(1);
	 }
	return m[index];
}

template<class T>
const SafeArray<T>& SafeMatrix<T>::operator [] (int index) const
{
	if (index < 0 || index >= rows)
	{
		std::cout << "Index: "<<index<< " is out of bounds."<< std::endl;
		std::exit(1);
	}
	return m[index];
}

template<class T>
int SafeMatrix<T>::length() const
{
	return rows;
}

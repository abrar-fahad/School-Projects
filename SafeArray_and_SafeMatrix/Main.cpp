// Abrar Fahad
// SafeArray and SafeMatrix Practice
#include <iostream>
#include "SafeMatrix.cpp"

using namespace std;

int main() {
	//a 2 by 3 dimensional array of integers is created
	SafeMatrix<double> arr1(5,7);

	arr1[2][5]=17.56;
	cout<<"Double Array 1 value at index [2][5]: "<<arr1[2][5]<<endl;
	cout<<"Double Array 1 rows size: "<<arr1.length()<<endl;
	cout<<"Double Array 1 columns size: "<<arr1[1].length()<<endl;
	//Test case with 2 by 2 dimensional integer array
	SafeMatrix<int> m(2,3);
	m[1][2]=10;
	cout<<"Int Array m value at index [1][2]: "<<m[1][2]<<endl;
	cout<<"Int Array m rows size: "<<m.length()<<endl;
	cout<<"Int Array m columns size: "<<m[1].length()<<endl;
	//Test case with 2 by 1 dimensional string array
	SafeMatrix<string> arr2(2,1);
	arr2[1][0]="Cat";
	cout<<"String Array arr2 value at index [1][2]: "<<arr2[1][0]<<endl;
	cout<<"String Array arr2 rows size: "<<arr2.length()<<endl;
	cout<<"String Array arr2 columns size: "<<arr2[1].length()<<endl;

}

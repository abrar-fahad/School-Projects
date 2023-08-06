/*
Abrar Fahad - CSCI 211
Project Description:
This program repeatedly takes a positive integer as input from the user and prints its digits in reverse order.
The user can continue to enter positive integers, and the program will print each reversed number.
If a non-positive integer is entered, the program terminates.

The program includes a main function and a helper function:
- printReverse: Converts an integer to a string and prints it in reverse.
- main: Implements the main loop of the program, repeatedly taking user input and calling printReverse.
*/

#include <iostream>
#include <string>
using namespace std;

// Function to print an integer in reverse order
void printReverse(int n)
{
    string s = to_string(n);
    cout << "Reverse of your number is: ";
    for (int i = s.length() - 1; i >= 0; i--)
    {
        cout << s[i];
    }
    cout << endl;
}

// Main function to execute the program
int main()
{
    int num;
    // The program runs as long as the input is a positive integer
    do
    {
        cout << "Enter a positive integer: ";
        cin >> num;

        // Checks if the value is a positive integer and prints its reverse if so
        // For integers less than 1, the program terminates
        if (num > 0)
        {
            printReverse(num);
        }
        else
        {
            cout << "Not a positive integer.";
        }

    } while (num > 0);

    return 0;
}

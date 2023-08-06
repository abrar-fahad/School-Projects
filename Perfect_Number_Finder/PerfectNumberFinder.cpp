// Abrar Fahad - CS211
/*
Project Description:
This program takes a positive integer input from the user and prints all perfect numbers up to that number.
A perfect number is a positive integer that is equal to the sum of its proper divisors (excluding itself).
The program includes two main functions:
- divisor: Computes the sum of the divisors of a given number.
- printPerfect: Prints all perfect numbers within the given range.

For example, 6 is a perfect number because its divisors 1, 2, and 3 sum up to 6.
*/

#include <iostream>
#include <cstdlib> // For using exit

// Function to return the sum of all the possible divisors of a given number
int divisor(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum = sum + i;
        }
    }
    return sum;
}

// Function to print all perfect numbers up to the given user input number
void printPerfect(int n)
{
    std::cout << "Perfect numbers up to " << n << " are: ";
    for (int i = 1; i <= n; i++)
    {
        if (divisor(i) == i)
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

// Main function to execute the program
int main()
{
    int num;
    std::cout << "Enter a positive integer: ";
    std::cin >> num;

    // Checking for non-positive integer input
    if (num < 1)
    {
        std::cout << "Not a positive integer.";
        exit(0);
    }
    // Handling cases where no perfect numbers exist in the given range
    else if (num >= 1 && num < 6)
    {
        std::cout << "No perfect number exists between the number you entered.";
        exit(0);
    }

    // Printing perfect numbers for valid input
    printPerfect(num);
    return 0;
}


/*
Abrar Fahad - CSCI 211
Project Description:
This program takes a range of years as input from the user and prints all leap years within that range.
A leap year is defined as a non-century year that is divisible by 4 or a century year that is divisible by 400.

The program includes two main functions:
- isLeap: Determines whether a given year is a leap year.
- printLeap: Prints all leap years in a given range, with a maximum of 5 years displayed on each line.
*/

#include <iostream>
#include <cstdlib> // For using exit

// Function to check whether a given year is a leap year
bool isLeap(int year)
{
    if (((year % 4) == 0 && (year % 100) != 0) || (year % 400) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function to print all leap years within a given range
void printLeap(int x, int y)
{
    int counter = 0;
    std::cout << "The Leap Years for the given range are as follows: " << std::endl;
    for (int i = x; i <= y; i++)
    {
        if (isLeap(i))
        {
            if (counter < 5)
            {
                counter++;
                std::cout << i << " ";
            }
            else
            {
                counter = 1;
                std::cout << std::endl << i << " ";
            }
        }
    }
}

// Main function to execute the program
int main() {
    int from, to;
    std::cout << "Enter the Range of years" << std::endl;
    std::cout << "From: ";
    std::cin >> from;
    std::cout << "To: ";
    std::cin >> to;

    // Internal adjustments for years less than 0
    if (from > to || from < 0)
    {
        std::cout << "No possible Leap Year found.";
        exit(0);
    }
    if (from == 0)
    {
        from = 1;
    }

    // Calls the function printLeap by giving it a range to print from
    // The function prints the results
    printLeap(from, to);
    return 0;
}

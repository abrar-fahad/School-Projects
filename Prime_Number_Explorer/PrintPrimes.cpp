// Abrar Fahad - CS211
/*
Project Description:
This program takes an integer input from the user and prints all prime numbers up to that number.
A prime number is a natural number greater than 1 that is divisible only by 1 and itself.

The isPrime function checks whether a number is prime by dividing it with numbers from 2 to its square root.
If there's a case where the remainder is zero, the function returns false, meaning the number is not prime.

The printPrime function prints all the prime numbers up to the given number. If the input is less than 2, it prints an appropriate message.
*/

#include <iostream>
#include <cmath>
#include <cstdlib>

// Function to check if a given number is prime
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= std::sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to print all prime numbers up to a given number
void printPrime(int n) {
    if (n < 2) {
        std::cout << "No Prime numbers available.";
        exit(0);
    } else {
        std::cout << "The list of all the Prime numbers are as follows: ";
        for (int x = 2; x <= n; x++) {
            if (isPrime(x)) {
                std::cout << x << " ";
            }
        }
    }
}

// Main function to execute the program
int main() {
    int num;
    std::cout << "Enter Number: ";
    std::cin >> num;
    printPrime(num);
    exit(0);
}


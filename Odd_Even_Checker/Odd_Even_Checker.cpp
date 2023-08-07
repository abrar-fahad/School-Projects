// Abrar Fahad - Basic Programming 
/*
Project Description:
This program takes integer inputs from the user and checks whether they are odd or even. The user can continue to enter numbers, and the program will identify whether they are odd or even until the user decides to exit by pressing anything other than 'y'.
*/

#include <iostream>

int main() {
    int n;
    char choice;
    do {
        std::cout << "Enter an integer: ";
        std::cin >> n;

        if (n % 2 == 0) {
            std::cout << n << " is an even number.\n";
        } else {
            std::cout << n << " is an odd number.\n";
        }

        std::cout << "Do you want to check another number? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
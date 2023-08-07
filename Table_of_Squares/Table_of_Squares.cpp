// Abrar Fahad - Basic Programming.
/*
Project Description:
This program prints a table of squares for the numbers 1 to n, where n is provided by the user.
*/

#include <iostream>

int main() {
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    std::cout << "Number  |  Square\n";
    for (int i = 1; i <= n; ++i) {
        std::cout << i << "          |  " << i * i << "\n";
    }

    return 0;
}
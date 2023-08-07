// Abrar Fahad - Basic Programming
/*
Project Name: Simple Calculator
Project Description:
This program implements a basic calculator that can perform addition, subtraction, multiplication, and division. The user is prompted to enter two numbers and choose an operation. The program then displays the result of the chosen operation on the two numbers.
*/

#include <iostream>

int main() {
    // Variable to store the user's choice to continue or not
    char choice;

    // Variables to store the operands
    double num1, num2;

    do {
        std::cout << "Enter two numbers: ";
        
        // Read the operands from the user
        std::cin >> num1 >> num2; 

        std::cout << "Choose an operation (+, -, *, /): ";
        
        // Variable to store the chosen operation
        char operation;

        // Read the operation from the user
        std::cin >> operation; 

        // Perform the chosen operation
        switch (operation) {
            case '+':
                // Addition
                std::cout << "Result: " << num1 + num2 << "\n"; 
                break;
            case '-':
                // Subtraction
                std::cout << "Result: " << num1 - num2 << "\n"; 
                break;
            case '*':
                // Multiplication
                std::cout << "Result: " << num1 * num2 << "\n"; 
                break;
            case '/':
                if (num2 != 0) {
                    // Division
                    std::cout << "Result: " << num1 / num2 << "\n"; 
                } else {
                    // Error message for division by zero
                    std::cout << "Cannot divide by zero.\n"; 
                }
                break;
            default:
                // Error message for invalid operation
                std::cout << "Invalid operation.\n"; 
                break;
        }

        std::cout << "Do you want to perform another calculation? (y/n): ";
        
        // Read the user's choice to continue or not
        std::cin >> choice; 

    // Repeat if the user's choice is 'y' or 'Y'
    } while (choice == 'y' || choice == 'Y'); 

    return 0;
}

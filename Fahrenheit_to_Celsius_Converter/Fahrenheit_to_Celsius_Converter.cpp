// Abrar Fahad - Basic Programming
/*
Project Description:
This program takes a temperature in Fahrenheit from the user and converts it to Celsius. 
*/

#include <iostream>

int main() {
    // Variable to store the temperature in Fahrenheit
    double fahrenheit; 

    // Variable to store the temperature in Celsius
    double celsius; 

    std::cout << "Enter temperature in Fahrenheit: ";
    
    // Read the temperature in Fahrenheit from the user
    std::cin >> fahrenheit; 

    // Convert the temperature to Celsius
    celsius = (fahrenheit - 32) * 5.0 / 9.0;

    // Print the temperature in Celsius
    std::cout << "Temperature in Celsius: " << celsius << "\n";

    return 0;
}

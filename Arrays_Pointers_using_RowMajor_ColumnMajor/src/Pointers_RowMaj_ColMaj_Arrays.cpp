/*=====================================================================================
* Name        : CSCI316 Project 2 - Pointers in C++
* Author      : Abrar Fahad - ******** (***)

* Version     : Final
* Copyright   : Your copyright notice
* Description : The purpose of this project is demonstrating our understanding of
				pointers The project reads an input file containing information
 	 	 	 	about arrays, convert the arrays to row-major and column-major order,
				display the results, and save the results in an output file.

======================================================================================*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;

// Fill the RowMaj array with using pointers
void fillRowMajor(int* RowMaj, int rows, int cols, int* data)
{
    for (int i = 0; i < rows * cols; i++)
    {
        // Access the memory location pointed to by RowMaj using the index i
        RowMaj[i] = data[i];
    }
}

// Fill the ColMaj array using pointers
void fillColumnMajor(int* ColMaj,int rows, int cols, int* data)
{
    int index = 0;
    for (int c = 0; c < cols; c++)
    {
        for (int r = 0; r < rows; r++)
        {
            // Calculate the index for column-major order (r * cols + c)
            ColMaj[r * cols + c] = data[index++];
        }
    }
}
// Convert the array to a string for printing and file saving
std::string string_Array(int* arr, int rows, int cols)
{
    std::stringstream ss;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            // Access the memory location pointed to by arr using the row-major index (r * cols + c)
            ss << arr[r * cols + c] << " ";
        }
        ss << endl;
    }
    // Return the string representation of the array
    return ss.str();
}

// Save the input, RowMaj, and ColMaj strings to the output file
void saveArrayToOutputFile(const std::string& input, const std::string& RowMajStr, const std::string& ColMajStr)
{
    // Open the output file and append to it
    std::ofstream output_file("ArrayOutput.txt", std::ios::app);

    // Check if the output file is open
    if (output_file.is_open())
    {
        // Write the input, RowMaj, and ColMaj strings to the output file
        output_file << "Input: " << input << endl << endl;
        output_file << "Row-major order:" << endl << RowMajStr << endl;
        output_file << "Column-major order:" << endl << ColMajStr << endl;
        output_file << "-------------------------------------------------------------------" << endl;
        // Close the output file
        output_file.close();
    }
    else
    {
        // Display an error message if the output file cannot be opened
        cout << "Error opening output file." << endl;
    }
}

int main()
{
    // Open the input file
    std::ifstream input_file("input.txt");
    // Check if the input file is open
    if (!input_file.is_open())
    {
        // Display an error message if the input file cannot be opened
    	cout << "Error opening input file." << endl;
        return 1;
    }

    // Read the input file line by line
    std::string line;
    while (std::getline(input_file, line))
    {
        // Parse the input line using a string stream
        std::istringstream str(line);
        int rows, cols;
        str >> rows >> cols;

        // Allocate memory for the input data array
        int* data = new int[rows * cols];
        // Read the input data values from the string stream
        for (int i = 0; i < rows * cols; i++)
        {
            str >> data[i];
        }

        // Allocate memory for the RowMaj and ColMaj arrays
        int* RowMaj = new int[rows * cols];
        int* ColMaj = new int[rows * cols];

        // Fill the RowMaj array with data in row-major order
        fillRowMajor(RowMaj, rows, cols, data);

        // Fill the ColMaj array with data in column-major order
        fillColumnMajor(ColMaj, rows, cols, data);

        // Convert the RowMaj and ColMaj arrays to strings for display and file saving
        std::string RowMajStr = string_Array(RowMaj, rows, cols);
        std::string ColMajStr = string_Array(ColMaj, rows, cols);

        // Print to console the RowMaj and ColMaj arrays
        cout << "Input: " << line << endl << endl;
        cout << "Row-major order:" << endl << RowMajStr << endl;
        cout << "Column-major order:" << endl << ColMajStr << endl;
        cout << "-------------------------------------------------------------------" << endl;

        // Save the input, RowMaj, and ColMaj strings to the output file
        saveArrayToOutputFile(line, RowMajStr, ColMajStr);

        // Deallocate memory for the data, RowMaj, and ColMaj arrays
        delete[] data;
        delete[] RowMaj;
        delete[] ColMaj;
    }

    // Close the input file
    input_file.close();

    return 0;
}



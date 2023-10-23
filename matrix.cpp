#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using std::istringstream; // Using directive for the istringstream class
using std::cout; // Using directive for the cout stream
using std::endl; // Using directive for the endl (end of line) symbol

// Function to print a matrix
void printMatrix(int matrixSize, std::vector<std::vector<int> > &matrix) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            cout << matrix[i][j] << " "; // Print the element at row i and column j
        }
        cout << endl; // Move to the next line after printing a row
    }
}

// Function to create a zero-filled matrix
std::vector<std::vector<int> > zeroMatrix(int matrixSize) {
    std::vector<std::vector<int> > result(matrixSize, std::vector<int>(matrixSize, 0)); // Create a matrix with all elements initialized to 0
    return result; // Return the zero matrix
}

// Function to add two matrices
std::vector<std::vector<int> > matrixSum(int matrixSize, const std::vector<std::vector<int> > &matrix1, const std::vector<std::vector<int> > &matrix2) {
    std::vector<std::vector<int> > result = zeroMatrix(matrixSize); // Initialize the result matrix with zeros

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j]; // Add corresponding elements from matrix1 and matrix2
        }
    }

    return result; // Return the resulting sum matrix
}

// Function to multiply two matrices
std::vector<std::vector<int> > matrixMultiplication(int matrixSize, const std::vector<std::vector<int> > &matrix1, const std::vector<std::vector<int> > &matrix2) {
    std::vector<std::vector<int> > result = zeroMatrix(matrixSize); // Initialize the result matrix with zeros

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            for (int k = 0; k < matrixSize; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j]; // Multiply and accumulate values for each element in the result matrix
            }
        }
    }

    return result; // Return the resulting product matrix
}

// Function to subtract two matrices
std::vector<std::vector<int> > matrixSubtraction(int matrixSize, const std::vector<std::vector<int> > &matrix1, const std::vector<std::vector<int> > &matrix2) {
    std::vector<std::vector<int> > result = zeroMatrix(matrixSize); // Initialize the result matrix with zeros

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j]; // Subtract corresponding elements from matrix1 and matrix2
        }
    }

    return result; // Return the resulting difference matrix
}

// The main function
int main() {
    std::ifstream file("matrix_input.txt"); // Open a file for reading
    std::vector<std::vector<int> > matrixList; // Create a vector to store matrix data
    std::string line;

    // Read the matrix data from the file
    while (std::getline(file, line)) { // Read each line in the file
        std::vector<int> row;
        istringstream iss(line); // Create a string stream to parse the line
        int num;
        while (iss >> num) {
            row.push_back(num); // Parse and store numbers from the line in a row
        }
        matrixList.push_back(row); // Add the row to the matrix list
    }

    int matrixSize = matrixList[0][0]; // Get the size of the matrix
    std::vector<std::vector<int> > matrix1;
    std::vector<std::vector<int> > matrix2;

    // Separate matrix data into two matrices (A and B)
    for (int i = 1; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            matrixList[i][j] = static_cast<int>(matrixList[i][j]); // Ensure data type is int
        }
        if (i < 4) {
            matrix1.push_back(matrixList[i]); // Add rows to matrix A
        } else {
            matrix2.push_back(matrixList[i]); // Add rows to matrix B
        }
    }

    // Print the original matrices A and B
    cout << "Matrix A:" << endl;
    printMatrix(matrixSize, matrix1);

    cout << "Matrix B:" << endl;
    printMatrix(matrixSize, matrix2);

    // Perform matrix operations and print the results
    cout << "Matrix Sum (A + B):" << endl;
    std::vector<std::vector<int> > sumResult = matrixSum(matrixSize, matrix1, matrix2);
    printMatrix(matrixSize, sumResult);

    cout << "Matrix Product (A * B):" << endl;
    std::vector<std::vector<int> > productResult = matrixMultiplication(matrixSize, matrix1, matrix2);
    printMatrix(matrixSize, productResult);

    cout << "Matrix Difference (A - B):" << endl;
    std::vector<std::vector<int> > diffResult = matrixSubtraction(matrixSize, matrix1, matrix2);
    printMatrix(matrixSize, diffResult);

    return 0; // Exit the program
}

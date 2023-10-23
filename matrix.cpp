#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using std::istringstream;
using std::cout; 
using std::endl;

void printMatrix(int matrixSize, std::vector<std::vector<int> > &matrix) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

std::vector<std::vector<int> > zeroMatrix(int matrixSize) {
    std::vector<std::vector<int> > result(matrixSize, std::vector<int>(matrixSize, 0));
    return result;
}

std::vector<std::vector<int> > matrixSum(int matrixSize, const std::vector<std::vector<int> > &matrix1, const std::vector<std::vector<int> > &matrix2) {
    std::vector<std::vector<int> > result = zeroMatrix(matrixSize);

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

std::vector<std::vector<int> > matrixMultiplication(int matrixSize, const std::vector<std::vector<int> > &matrix1, const std::vector<std::vector<int> > &matrix2) {
    std::vector<std::vector<int> > result = zeroMatrix(matrixSize);

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            for (int k = 0; k < matrixSize; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

std::vector<std::vector<int> > matrixSubtraction(int matrixSize, const std::vector<std::vector<int> > &matrix1, const std::vector<std::vector<int> > &matrix2) {
    std::vector<std::vector<int> > result = zeroMatrix(matrixSize);

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return result;
}

int main() {
    std::ifstream file("matrix_input.txt");
    std::vector<std::vector<int> > matrixList;
    std::string line;

    while (std::getline(file, line)) {
        std::vector<int> row;
        istringstream iss(line);
        int num;
        while (iss >> num) {
            row.push_back(num);
        }
        matrixList.push_back(row);
    }

    int matrixSize = matrixList[0][0];
    std::vector<std::vector<int> > matrix1;
    std::vector<std::vector<int> > matrix2;

    for (int i = 1; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            matrixList[i][j] = static_cast<int>(matrixList[i][j]);
        }
        if (i < 4) {
            matrix1.push_back(matrixList[i]);
        } else {
            matrix2.push_back(matrixList[i]);
        }
    }

    cout << "Matrix A:" << endl;
    printMatrix(matrixSize, matrix1);

    cout << "Matrix B:" << endl;
    printMatrix(matrixSize, matrix2);

    cout << "Matrix Sum (A + B):" << endl;
    std::vector<std::vector<int> > sumResult = matrixSum(matrixSize, matrix1, matrix2);
    printMatrix(matrixSize, sumResult);

    cout << "Matrix Product (A * B):" << endl;
    std::vector<std::vector<int> > productResult = matrixMultiplication(matrixSize, matrix1, matrix2);
    printMatrix(matrixSize, productResult);

    cout << "Matrix Difference (A - B):" << endl;
    std::vector<std::vector<int> > diffResult = matrixSubtraction(matrixSize, matrix1, matrix2);
    printMatrix(matrixSize, diffResult);

    return 0;
}

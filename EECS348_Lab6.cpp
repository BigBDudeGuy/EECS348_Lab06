//EECS348 lab6
//Blake Ebner
//3100983
//3/21/2023
//creating a code in C++ that adds, subtracts, multiplies, chnages, and transposes matrices
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void readMatricesFromFile(const string& filename, vector<vector<int>>& matrix1, vector<vector<int>>& matrix2) {
    ifstream file(filename);
    if (file.is_open()) 
    {
        for (int i = 0; i < 3; ++i) {
            matrix1.push_back(vector<int>());
            int num1, num2, num3;
            file >> num1 >> num2 >> num3;
            matrix1[i].push_back(num1);
            matrix1[i].push_back(num2);
            matrix1[i].push_back(num3);
        }

        for (int i = 0; i < 3; ++i) {
            matrix2.push_back(vector<int>());
            int num1, num2, num3;
            file >> num1 >> num2 >> num3;
            matrix2[i].push_back(num1);
            matrix2[i].push_back(num2);
            matrix2[i].push_back(num3);
        }
        file.close();
    } else {
        cerr << "File doesn't exist " << filename << endl;
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> addMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    vector<vector<int>> result;
    for (int i = 0; i < matrix1.size(); ++i) {
        result.push_back(vector<int>());
        for (int j = 0; j < matrix1[i].size(); ++j) {
            result[i].push_back(matrix1[i][j] + matrix2[i][j]);
        }
    }
    return result;
}

vector<vector<int>> subtractMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    vector<vector<int>> result;
    for (int i = 0; i < matrix1.size(); ++i) {
        result.push_back(vector<int>());
        for (int j = 0; j < matrix1[i].size(); ++j) {
            result[i].push_back(matrix1[i][j] - matrix2[i][j]);
        }
    }
    return result;
}

vector<vector<int>> multiplyMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    vector<vector<int>> result(3, vector<int>(3, 0));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int findLargestNumber(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    int largestNumber = matrix1[0][0]; 

    for (const auto& row : matrix1) 
    {
        for (int num : row) {
            largestNumber = max(largestNumber, num);
        }
    }

    for (const auto& row : matrix2) 
    {
        for (int num : row) {
            largestNumber = max(largestNumber, num);
        }
    }

    return largestNumber;
}

vector<vector<int>> transposeMatrix(const vector<vector<int>>& matrix) {
    vector<vector<int>> transposed(matrix[0].size(), vector<int>(matrix.size()));
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

int main() {
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;

    vector<vector<int>> matrix1, matrix2;
    readMatricesFromFile(filename, matrix1, matrix2);

    cout << "Matrix 1:\n";
    printMatrix(matrix1);
    cout << endl;

    cout << "Matrix 2:\n";
    printMatrix(matrix2);
    cout << endl;

    cout << "Matrix 1 + Matrix 2:\n";
    printMatrix(addMatrices(matrix1, matrix2));
    cout << endl;

    cout << "Matrix 1 - Matrix 2:\n";
    printMatrix(subtractMatrices(matrix1, matrix2));
    cout << endl;

    cout << "Matrix 1 * Matrix 2:\n";
    printMatrix(multiplyMatrices(matrix1, matrix2));
    cout << endl;

    int rowIndex, colIndex, newValue;
    cout << "Enter the row index (0-2) of the element you want to change in the first matrix: ";
    cin >> rowIndex;
    cout << "Enter the column index (0-2) of the element you want to change in the first matrix: ";
    cin >> colIndex;
    cout << "Enter the new value for the element: ";
    cin >> newValue;

    if (rowIndex >= 0 && rowIndex < 3 && colIndex >= 0 && colIndex < 3) {
        matrix1[rowIndex][colIndex] = newValue;
        cout << "Modified Matrix 1:\n";
        printMatrix(matrix1);
        cout << endl;
    } else 
    
    {
        cout << "This row does not exist" << endl;
    }

    cout << "Largest number in either matrix: " << findLargestNumber(matrix1, matrix2) << endl;

     cout << "Transposed Matrix 1:\n";
    printMatrix(transposeMatrix(matrix1));
    cout << endl;

    return 0;
}

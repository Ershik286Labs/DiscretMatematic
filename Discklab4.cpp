#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int lineOneMatrix = 0;
int colomnOneMatrix = 0;
int lineTwoMatrix = 0;
int colomnTwoMatrix = 0;

void printMatrix(int** matrix, int lines, int columns) {
    for (int x = 0; x < columns; x++) {
        int k = 0;
        for (int y = 0; y < lines; y++) {
            if (matrix[y][x] == 0) {
                k++;
            }
        }
        if (k == lines) {
            for (int y = 0; y < lines; y++) {
                matrix[y][x] = 5;
            }
        }
    }
    for (int y = 0; y < lines; y++) {
        cout << " " << y + 1 << "|";
        for (int x = 0; x < columns; x++) {
            int number = matrix[y][x];
            if (number == 5) {
                continue;
            }
            if (number >= 0) cout << " " << number << " ";
            else cout << number << " ";
        }
        cout << endl;
    }
}

int** createDifferenceGraphMatrix(int** matrix1, int** matrix2, int lines, int columns) {
    int** diffMatrix = new int* [lines];
    for (int i = 0; i < lines; i++) {
        diffMatrix[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            // Ребро есть в первой матрице и его нет во второй (значения разные)
            if (matrix1[i][j] != 0) {
                int check = matrix1[i][j];
                int len = i;
                int col = j;
                diffMatrix[i][j] = check;
                for (int y = 0; y < lines; y++) {
                    if (matrix1[y][j] == check * -1) {
                        int len1 = y;
                        if (matrix2[len][j] == check && matrix2[len1][j] == check * -1) {
                            diffMatrix[i][j] = 0;
                        }
                        else {
                            diffMatrix[i][j] = check;
                        }
                        break;
                    }
                }

            }
            else diffMatrix[i][j] = 0;
        }
    }
    return diffMatrix;
}

void freeMatrix(int** matrix, int lines) {
    for (int i = 0; i < lines; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    fstream OneMatrixFile("Исходная первая М-ца инциндетности Ершов Никита 1304.txt", ios::in);
    fstream TwoMatrixFile("Исходная вторая М-ца инциндетности Ершов Никита 1304.txt", ios::in);


    OneMatrixFile >> lineOneMatrix;
    OneMatrixFile >> colomnOneMatrix;
    TwoMatrixFile >> lineTwoMatrix;
    TwoMatrixFile >> colomnTwoMatrix;

    // Чтение первой матрицы
    int** matrixOne = new int* [lineOneMatrix];
    for (int i = 0; i < lineOneMatrix; i++) {
        matrixOne[i] = new int[colomnOneMatrix];
        for (int j = 0; j < colomnOneMatrix; j++) {
            OneMatrixFile >> matrixOne[i][j];
        }
    }

    // Чтение второй матрицы
    int** matrixTwo = new int* [lineTwoMatrix];
    for (int i = 0; i < lineTwoMatrix; i++) {
        matrixTwo[i] = new int[colomnTwoMatrix];
        for (int j = 0; j < colomnTwoMatrix; j++) {
            TwoMatrixFile >> matrixTwo[i][j];
        }
    }

    cout << "Первая матрица инцидентности:" << endl << endl;
    printMatrix(matrixOne, lineOneMatrix, colomnOneMatrix);
    cout << endl;

    cout << "Вторая матрица инцидентности:" << endl << endl;
    printMatrix(matrixTwo, lineTwoMatrix, colomnTwoMatrix);
    cout << endl;

    // Создание матрицы разностного графа
    int** differenceGraphMatrix = createDifferenceGraphMatrix(matrixOne, matrixTwo, lineOneMatrix, colomnOneMatrix);

    cout << "Матрица инциндентности разностного графа:" << endl << endl;
    printMatrix(differenceGraphMatrix, lineOneMatrix, colomnOneMatrix);
    cout << endl;

    return 0;
}
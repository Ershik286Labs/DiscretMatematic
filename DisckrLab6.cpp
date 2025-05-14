#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>>& matrix) {
    cout << " |";
    for (int i = 0; i < matrix[0].size(); i++) {
        cout <<" " << i + 1 << "|";
    }
    cout << endl;
    for (int i = 0; i < matrix.size(); i++) {
        cout << i + 1 << "|";
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] < 0)
                cout << matrix[i][j] << "|";
            else cout << " " << matrix[i][j] << "|";
        }
        cout << endl;
    }
}

// Функция для умножения двух матриц
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// Функция для возведения матрицы в степень (бинарное возведение в степень)
vector<vector<int>> matrixPower(vector<vector<int>> base, int exponent) {
    int n = base.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    // Единичная матрица
    for (int i = 0; i < n; ++i) {
        result[i][i] = 1;
    }

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = multiplyMatrices(result, base);
        }
        base = multiplyMatrices(base, base);
        exponent /= 2;
    }

    return result;
}

int main() {
    string filename;
    int pathLength;

    cout << "Введите имя файла с матрицей инцидентности: ";
    cin >> filename;
    cout << "Введите длину пути: ";
    cin >> pathLength;

    ifstream file(filename);

    int n, m;
    file >> n >> m;

    if (n < 5 || m < 5) {
        cerr << "Матрица должна содержать как минимум 5 вершин и 5 дуг." << endl;
        return 1;
    }

    vector<vector<int>> incidenceMatrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            file >> incidenceMatrix[i][j];
        }
    }
    cout << "Матрица инцидентностности: " << endl;
    printMatrix(incidenceMatrix);

    file.close();

    // Преобразование матрицы инцидентности в матрицу смежности
    vector<vector<int>> adjacencyMatrix(n, vector<int>(n, 0));
    for (int j = 0; j < m; ++j) {
        int from = -1, to = -1;
        for (int i = 0; i < n; ++i) {
            if (incidenceMatrix[i][j] == -1) {
                from = i;
            }
            else if (incidenceMatrix[i][j] == 1) {
                to = i;
            }
        }
        if (from != -1 && to != -1) {
            adjacencyMatrix[to][from] = 1;
        }
    }
    cout << "Матрица смежности: " << endl;
    printMatrix(adjacencyMatrix);

    // Возведение матрицы смежности в степень pathLength
    vector<vector<int>> poweredMatrix = matrixPower(adjacencyMatrix, pathLength);

    // Вычисление общего количества путей
    int totalPaths = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            totalPaths += poweredMatrix[i][j];
        }
    }

    cout << "Общее количество путей длины " << pathLength << ": " << totalPaths << endl;

    return 0;
}
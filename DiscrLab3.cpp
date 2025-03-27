#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int dimension = 0;

struct itogMassive {
    int row1;
    int row2;
};

int main() {
    fstream MatrixFile("matrix.txt", ios::in | ios::out); //открыли файл
    MatrixFile >> dimension;
    if (dimension > 0) {
        int** matrix{ new int* [dimension] {} };
        for (int i = 0; i < dimension; i++)
            matrix[i] = new int[dimension];

        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                MatrixFile >> matrix[i][j];
            }
        }

        // 3. Подсчет двунаправленных дуг
        vector<itogMassive> bidirectionalEdges; // Используем вектор для хранения результатов
        for (int i = 0; i < dimension; ++i) {
            for (int j = i + 1; j < dimension; ++j) { // Перебираем пары вершин
                bool hasEdgeIJ = false;  // Флаг: есть ли дуга i -> j
                bool hasEdgeJI = false;  // Флаг: есть ли дуга j -> i

                for (int k = 0; k < dimension; ++k) {
                    if (matrix[i][k] == 1 && matrix[j][k] == -1) {
                        hasEdgeIJ = true; // Нашли дугу i -> j
                    }
                    if (matrix[j][k] == 1 && matrix[i][k] == -1) {
                        hasEdgeJI = true; // Нашли дугу j -> i
                    }
                }

                if (hasEdgeIJ && hasEdgeJI) {
                    bidirectionalEdges.push_back({ i, j }); // Добавляем двунаправленное ребро в список
                }
            }
        }

        // 4. Вывод результатов
        if (!bidirectionalEdges.empty()) { // Corrected condition: if the vector is NOT empty
            for (const auto& edge : bidirectionalEdges) {
                cout << "Найденная двунаправленная дуга: " << edge.row1 + 1 << " - " << edge.row2 + 1 << endl;
            }
            cout << "Количество двунаправленных дуг - " << bidirectionalEdges.size() << endl; // Corrected count, no + 1
        }
        else {
            cout << "Двунаправленные дуги не найдены" << endl;
        }
    }
    else {
        cout << "Некорректная размерность матрицы" << endl;
    }

    return 0;
}
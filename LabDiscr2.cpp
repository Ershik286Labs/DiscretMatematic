#include <iostream>

using namespace std;

int hangingPeaks = 0;

int main(){
	int dimension;
	while (true) {
		system("cls");
		cout << "Введите размерность матрицы" << endl;
		cin >> dimension;
		if (dimension < 4 || dimension > 10) {
			cout << "размерность больше 4 и меньше 10" << endl;
			dimension = 0;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("pause");
			continue;
		}
		int* hangingPeaksMassive = new int[dimension * 2];//массив для висячих точек

		int** matrix{ new int* [dimension] {} };
		for (int i = 0; i < dimension; i++)
			matrix[i] = new int[dimension];

		cout << endl;
		
		srand(time(0));
		for (int y = 0; y < dimension; y++) {
			for (int x = 0; x < dimension; x++) {
				int temp = rand() % (1 - 0 + 1) + 0;
				matrix[y][x] = temp;
			}
		}

		for (int y = 0; y < dimension; y++) {
			int degree = 0;
			for (int x = 0; x < dimension; x++) {
				if (matrix[y][x] == 1) {
					degree++;
				}
			}
			int k = 0;
			for (int Line = 0; Line < dimension; Line++) {
				if (matrix[Line][y] == 1) {
					k++;
				}
			}
			if (degree + k == 1) {
				hangingPeaksMassive[hangingPeaks] = y;
				hangingPeaks++;
			}
		}


		cout << "  |";
		for (int i = 0; i < dimension; i++)
			cout << " " << i + 1 << "|";
		cout << endl;
		for (int y = 0; y < dimension; y++) {
			cout << " " << y + 1 << "|";
			for (int x = 0; x < dimension; x++)
				cout << " " << matrix[y][x] << "|";
			cout << endl;
		}

		cout << "Количество висячих вершин: " << hangingPeaks << endl;
		cout << "Висячие вершины:";
		for (int i = 0; i < hangingPeaks; i++) {
			cout << hangingPeaksMassive[i] + 1 << ", ";
		}

		break;
	}

}
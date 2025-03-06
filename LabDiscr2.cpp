#include <iostream>
using namespace std;

int hangingPeaks = 0;

int main() {
	int dimension;
	while (true) {
		system("cls");
		cout << "Введите размерность матрицы" << endl;
		cin >> dimension;
		if (dimension < 4 || dimension > 10) {//проверка на дурака
			cout << "размерность больше 4 и меньше 11" << endl;
			dimension = 0;
			system("pause");
			continue;
		}
		int* hangingPeaksMassive = new int[dimension * 2];//массив для висячих точек
		int** matrix{ new int* [dimension] {} };
		for (int i = 0; i < dimension; i++)
			matrix[i] = new int[dimension];
		cout << endl;

		srand(time(0));//настройка для генераии чисел, чтобы значения менялись
		for (int y = 0; y < dimension; y++) { //формируем матрицу
			int degree = 0;//переменная счетчик для количества точек с единицей в строке
			for (int x = 0; x < dimension; x++) {
				matrix[y][x] = rand() % (1 - 0 + 1) + 0;
				if (matrix[y][x] == 1) { //условие
					degree++;
				}
			}
			int k = 0;//счетчик для столбца
			for (int Line = 0; Line < dimension; Line++) { //проверяем матрицу со столцом
				//равным предыдущей строке
				if (matrix[Line][y] == 1) {
					k++;
				}
			}
			if (degree + k == 1) {//если их сумма равна 1 - то это висячая вершина
				hangingPeaksMassive[hangingPeaks] = y;//записываем в массив
				hangingPeaks++;//увеличиваем номер элемента в массиве
			}
		}
		//вывод на экран полученной матрицы
		cout << "  |";
		for (int i = 0; i < dimension; i++)
			cout << " " << i + 1 << "|"; //вывод на экран строчки с номерами столбцов
		cout << endl;
		for (int y = 0; y < dimension; y++) {
			cout << " " << y + 1 << "|"; //вывод на экран номера строки
			for (int x = 0; x < dimension; x++)
				cout << " " << matrix[y][x] << "|"; //вывод значения в этой матрице
			cout << endl;
		}
		cout << "Количество висячих вершин: " << hangingPeaks << endl;
		cout << "Висячие вершины:";
		for (int i = 0; i < hangingPeaks; i++) {
			cout << hangingPeaksMassive[i] + 1 << ", "; //выводим строки с висячими вершинами
		}
		return 0;
	}
}

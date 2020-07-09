#include "pch.h"
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <fstream>

using namespace std;

//В первом файле хранится k матриц размерности m × n, во втором -kматриц размерности m × 1. Получить k произведений соответствующих матриц из первого и второго файлов и записать их в третий файл в виде компонент структуры, где каждая компонента содержит три матрицы: а) первая размерности m x n из первого файла; б) вторая размерности m× 1 из второго файла; в) третья, матрица размерностиn × 1, результат произведения.Вывести на экран содержимое первого и второго файлов.

struct Matrixs {
	int * mat1, * mat2, * mat3;
};

void WriteFile(int k, int raw, int column, int ***arr, const char* filename);
void Countproperties(int* columns, int* raws, int* matrix, const char* filename);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int k, m, n, l;
	srand(time(0));
	
	cout << "Введите кол-во матриц в файлах data1.txt и data2.txt: ";
	cin >> k;
	cout << "Введите n и m матриц в файле data2.txt: ";
	cin >> n >> m;
	cout << "Введите кол-во столбцов матриц в файле data2.txt: ";
	cin >> l;
	
	//Создание файлов с матрицами
	int ***arr1 = new int**[k];
	int ***arr2 = new int**[k];
	const char* filename1 = "data1.txt";
	const char* filename2 = "data2.txt";
	const char* filename3 = "data3.txt";
	WriteFile(k, n, m, arr1, filename1);
	WriteFile(k, m, l, arr2, filename2);
	delete[] arr1;
	delete[] arr2;

	//Считывание матриц из файлов
	int columns1 = 0, columns2 = 0;
	int raws1 = 0, raws2 = 0;
	int matrix = 0;
	Countproperties(&columns1, &raws1, &matrix, filename1);
	Countproperties(&columns2, &raws2, &matrix, filename2);

	//Создание структур, выделение памяти и запись матриц
	Matrixs* massMat = new Matrixs[matrix];
	ifstream pt, pb;
	pt.open(filename1);
	pb.open(filename2);
	for (int i = 0; i < matrix; i++) {
		massMat[i].mat1 = (int*)malloc(n * m * sizeof(int));
		for (int j = 0; j < raws1 * columns1; j++) {
			pt >> massMat[i].mat1[j];
		}
		massMat[i].mat2 = (int*)malloc(m * l * sizeof(int));
		for (int j = 0; j < raws2 * columns2; j++) {
			pb >> massMat[i].mat2[j];
		}
		massMat[i].mat3 = (int*)malloc(n * l * sizeof(int));
		int s = 0, s1 = 0;
		for (int j = 0; j < raws1 * columns2; j++) {
			int sum = 0;
			for (int g = 0; g < columns1; g++) {
				sum += massMat[i].mat1[g*s1] * massMat[i].mat2[(g*columns2) + s];
			}
			s++;
			if (s == columns2) {
				s1++;
				s = 0;
			}
			massMat[i].mat3[j] = sum;
		}
	}
	pt.close();
	pb.close();

	//for (int i = 0; i < raws1 * columns1; i++) {
	//	cout << massMat[0].mat1[i] << " ";
	//}
	//cout << "\n" << "\n";
	//for (int i = 0; i < raws2 * columns2; i++) {
	//	cout << massMat[0].mat2[i] << " ";
	//}
	//cout << "\n" << "\n";
	//for (int i = 0; i < n * l; i++) {
	//	cout << massMat[0].mat3[i] << " ";
	//}

	//Запись файла data3.txt
	ofstream ps;
	//ifstream pz;
	ps.open(filename3);
	if (!ps.is_open()) {
		cout << "Не удалось открыть файл data3.txt";
	}
	else {
		ps << matrix;
		for (int i = 0; i < matrix; i++) {
			ps << columns1 << raws1;
			for (int j = 0; j < columns1*raws1; j++) {
				ps << massMat[i].mat1[j];
			}
			ps << columns2 << raws2;
			for (int j = 0; j < columns2*raws2; j++) {
				ps << massMat[i].mat2[j];
			}
			ps << columns2 << raws1;
			for (int j = 0; j < columns2*raws1; j++) {
				ps << massMat[i].mat3[j];
			}
		}
	}
	ps.close();
	/*pz.open(filename3);
	if (!pz.is_open()) {
		cout << "Не удалось открыть файл data3.txt";
	}
	else {
		int columns11 = 0, raws11 = 0, columns22 = 0, raws22 = 0;
		char columns12, raws12, columns21, raws21,  matrix12, force;
		pz.get(matrix12);
		int matrix1 = atoi(&matrix12);
		for (int m = 0; m < matrix1 ; m++) {
			cout << m + 1 << " матрица из первого файла: " << endl;
			pz.get(columns12);
			int columns11 = atoi(&columns12);
			pz.get(raws12);
			int raws11 = atoi(&raws12);
			for (int i = 0; i < raws11 * columns11; i++) {
				pz.get(force);
				cout << force << ' ';
				if (i % columns11 == 0) {
					cout << "\n";
				}
			}
			cout << '\n' << '\n';
			cout << m + 1 << " матрица из второго файла: " << endl;
			pz.get(columns21);
			int columns22 = atoi(&columns21);
			pz.get(raws21);
			int raws22 = atoi(&raws21);
			for (int i = 0; i < raws22 * columns22; i++) {
				pz.get(force);
				cout << force << ' ';
				if (i % columns22 == 0) {
					cout << "\n";
				}
			}
			for (int i = 0; i < raws11 * columns22 + 2; i++) {
				pz.get(force);
			}
			cout << '\n' << '\n';
		}
	}
	pz.close();*/
}


void WriteFile(int k, int raw, int column, int ***arr, const char* filename) {

	//Выделяем память под трехмерный массив
	for (int i = 0; i < k; i++) {
		arr[i] = new int*[raw];

		for (int j = 0; j < raw; j++) {
			arr[i][j] = new int[column];
		}
	}

	//Записываем значения
	for (int z = 0; z < k; z++)
		for (int y = 0; y < raw; y++)
			for (int x = 0; x < column; x++)
				arr[z][y][x] = (1 + rand() % 9);

	//Запись файла
	ofstream fp;
	fp.open(filename);
		for (int z = 0; z < k; z++) {
			for (int y = 0; y < raw; y++) {
				for (int x = 0; x < column; x++) {
					fp << arr[z][y][x] << " ";
				}
				fp << '\n';
			}
			fp << '\n' << '\n';
		}
	fp.close();

	//Очистка памяти
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < raw; j++) {
			delete[] arr[i][j];
		}
		delete[] arr[i];
	}
}


void Countproperties(int* columns, int* raws, int* matrix, const char* filename){
	ifstream ft;
	ft.open(filename);
	if (ft.is_open()) {
		char symbol;
		int counter = 0;
		(*columns) = 0;
		(*raws) = 0;
		(*matrix) = 0;
		while (ft.get(symbol)) {
			if (symbol == '\n') {
				break;
			}
			if (symbol == ' ') {
				(*columns)++;
			}
		}
		while (ft.get(symbol)) {
			if (symbol == '\n') {
				counter++;
				(*raws)++;
			}
			else {
				counter = 0;
			}
			if (counter == 2) {
				break;
			}
		}
		counter = 0;
		ft.seekg(0, ios::beg);
		while (!ft.eof()) {
			ft.get(symbol);
			symbol == '\n' ? counter++ : counter = 0;
			if (counter == 2) {
				(*matrix)++;
			}
		}
	}
	else {
		cout << "broke";
	}
	ft.close();
}
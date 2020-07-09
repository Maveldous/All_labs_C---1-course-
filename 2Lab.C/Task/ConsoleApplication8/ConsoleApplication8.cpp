#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <cstring>

using namespace std;

//Вариант 11

struct State {
	char countrname[40];  //the name of the country
	char capital[40];  //capital
	char offlanguage[40];  //official language
	int population;  //population
	int arealand;  //the area of the land
	char curunit[40];  //currency unit
	char polsyst[40];  //political system
	char headstate[40];  //head of state
};

void getstruct(State *, int);
void showstruct(State *, int);
State* addstruct(State *, int);
void find(State *, int);
void sort(State *, int);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N = 0;
	cout << "Введите количество структур: ";
	cin >> N;
	cin.ignore();
	State *M = new State[N];
	getstruct(M, N);
	showstruct(M, N);
	State* New = addstruct(M, N);
	N++;
	find(New, N);
	sort(New, N);
}

//Функция заполнения объектов структуры

void getstruct(State *M, int N)
{
	for (int i = 0; i < N; i++) {
		cout << "Введите название страны: ";
		cin.getline(M[i].countrname, 40);
		cout << "Введите столицу указанной страны: ";
		cin.getline(M[i].capital, 40);
		cout << "Введите государственный язык указанной страны: ";
		cin.getline(M[i].offlanguage, 40);
		cout << "Введите население указанной страны: ";
		cin >> M[i].population;
		cin.ignore();
		cout << "Введите площадь территории указанной страны: ";
		cin >> M[i].arealand;
		cin.ignore();
		cout << "Введите денежную единицу указанной страны: ";
		cin.getline(M[i].curunit, 40);
		cout << "Введите государственный строй указанной страны: ";
		cin.getline(M[i].polsyst, 40);
		cout << "Введите главу государства указанной страны: ";
		cin.getline(M[i].headstate, 40);
	}
}

//Функция вывода данных

void showstruct(State *M, int N)
{
	for (int i = 0; i < N; i++) {
		cout << endl << "№ " << i + 1 << endl;
		cout << "Название страны: " << M[i].countrname << endl;
		cout << "Cтолица: " << M[i].capital << endl;
		cout << "Государственный язык: " << M[i].offlanguage << endl;
		cout << "Население: " << M[i].population << endl;
		cout << "Площадь территории: " << M[i].arealand << endl;
		cout << "Денежная единица: " << M[i].curunit << endl;
		cout << "Государственный строй: " << M[i].polsyst << endl;
		cout << "Глава государства: " << M[i].headstate << endl << endl;
	}
}

State* addstruct(State *M, int N) {
	State *M1 = new State[N + 1];
	for (int i = 0; i < N + 1; i++) {
		M1[i] = M[i];
		if (i == N) {
			cout << "Введите данные новой структуры" << endl;
			cout << "Введите название страны: ";
			cin.getline(M1[i].countrname, 40);
			cout << "Введите столицу указанной страны: ";
			cin.getline(M1[i].capital, 40);
			cout << "Введите государственный язык указанной страны: ";
			cin.getline(M1[i].offlanguage, 40);
			cout << "Введите население указанной страны: ";
			cin >> M1[i].population;
			cin.ignore();
			cout << "Введите площадь территории указанной страны: ";
			cin >> M1[i].arealand;
			cin.ignore();
			cout << "Введите денежную единицу указанной страны: ";
			cin.getline(M1[i].curunit, 40);
			cout << "Введите государственный строй указанной страны: ";
			cin.getline(M1[i].polsyst, 40);
			cout << "Введите главу государства указанной страны: ";
			cin.getline(M1[i].headstate, 40);
		}
	}
	delete[] M;
	M = M1;
	return M;
}

void find(State *M, int N) {
	int max = 0, min = 0, counter = 0;
	cout << "В каком промежутке населения сортировать?" << endl;
	cout << "от: ";
	cin >> min;
	cout << "до: ";
	cin >> max;
	cout << "Страны, имеющие население в пределах от " << min << " до " << max << ":" << endl;
	for (int i = 0; i < N; i++) {
		if (M[i].population > min && M[i].population < max) {
			cout << "Название страны: " << M[i].countrname << endl;
			cout << "Cтолица: " << M[i].capital << endl;
			cout << "Государственный язык: " << M[i].offlanguage << endl;
			cout << "Население: " << M[i].population << endl;
			cout << "Площадь территории: " << M[i].arealand << endl;
			cout << "Денежная единица: " << M[i].curunit << endl;
			cout << "Государственный строй: " << M[i].polsyst << endl;
			cout << "Глава государства: " << M[i].headstate << endl << endl;
		}
		else {
			counter++;
		}
	}
	if (counter == N) {
		cout << "Страны с заданными параметрами не найдены" << endl << endl;
	}
}

void sort(State *M, int N) {
	int i = 0, j = 0;
	State Temp;

	cout << "Сортированные данные по названию стран в алфавитном порядке: " << endl;

	for (i = 0; i <= N; i++) {
		for (j = 0; j < N - i - 1; j++) {
			if (strcmp(M[j].countrname, M[j + 1].countrname) > 0) {
				Temp = M[j];
				M[j] = M[j + 1];
				M[j + 1] = Temp;
			}
		}
	}
	showstruct(M, N);
}
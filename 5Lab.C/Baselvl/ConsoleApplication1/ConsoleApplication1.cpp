#include "pch.h"
#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#pragma warning(disable : 4996)

//Задание: создать текстовый файл с произвольной информацией. Орга-низовать просмотр содержимого файла. Организовать чтение и обработку данных из файла в соответствии с индивидуальным заданием. Сохранить полученные результаты в новый текстовый файл
//Вариант 11: «Государство»:название страны; государственный язык; население; площадь территории; денежная единица; государственный строй; глава государства

using namespace std;

struct State {
	char countrname[20];
	char offlanguage[20];
	long long population;
	int area;
	char curunit[20];
	char polsyst[20];
	char headcontr[20];
	void Print() {
		cout << "Название страны: " << countrname << "\n"
			<< "Государственный язык: " << offlanguage << "\n"
			<< "Население: " << population << "\n"
			<< "Площадь территории: " << area << "\n"
			<< "Денежная единица:  " << curunit << "\n"
			<< "Государственный строй: " << polsyst << "\n"
			<< "Глава государства: " << headcontr << endl << endl;
	}
};

void getstruct(State *, int);
void cfile(State *, int);
void rfile();

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N = 0;
	cout << "Введите количество структур: ";
	cin >> N;
	cin.ignore();
	State *M = new State[N];
	getstruct(M, N);
	cfile(M, N);
	rfile();

	return 0;
}

void getstruct(State *M, int N)
{
	for (int i = 0; i < N; i++) {
		cout << "Введите название страны: ";
		cin.getline(M[i].countrname, 20);
		cout << "Введите государственный язык указанной страны: ";
		cin.getline(M[i].offlanguage, 20);
		cout << "Введите население указанной страны: ";
		cin >> M[i].population;
		cin.ignore();
		cout << "Введите площадь территории указанной страны: ";
		cin >> M[i].area;
		cin.ignore();
		cout << "Введите денежную единицу указанной страны: ";
		cin.getline(M[i].curunit, 20);
		cout << "Введите государственный строй указанной страны: ";
		cin.getline(M[i].polsyst, 20);
		cout << "Введите главу государства указанной страны: ";
		cin.getline(M[i].headcontr, 20);
	}
}

void cfile(State *M, int N) {
	const char * filename = "D://data.txt";
	ofstream ft;
	ft.open(filename);
	if (!ft.is_open()) {
		cout << "stuck";
	}
	else {
		for (int i = 0; i < N; i++) {
			ft.write((char*)&M[i], sizeof(State));
		}
	}
	ft.close();
}

void rfile() {
	const char * filename = "D://data.txt";
	const char * filename1 = "D://data1.txt";
	ifstream ft;
	ofstream fp;
	ft.open(filename);
	fp.open(filename1);
	if (!ft.is_open() || !fp.is_open()) {
		cout << "stuck";
	}
	else {
		State Mviev;
		cout << endl << "Содержание файла data.txt: " << endl;
		while (ft.read((char*)&Mviev, sizeof(State))) {
			Mviev.Print();
			if (Mviev.population > 20000000) {
				fp.write((char*)&Mviev, sizeof(Mviev));
			}
		}
	}
	ft.close();
	fp.close();
}
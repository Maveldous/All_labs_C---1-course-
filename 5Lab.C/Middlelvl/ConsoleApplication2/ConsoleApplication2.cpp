#include "pch.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

//Задание: создать текстовый файл в текстовом редакторе. Организовать просмотр содержимого файла и выполнения действий в соответствии с услови-ем индивидуального задания. Обеспечить сохранение всех полученных результатов в новый файл
//Дан файл f, компоненты которого являются действительными числами. Найти сумму компонент файла.

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double sum = 0;
	ifstream fp;
	ofstream ft;
	const char* file  = "data.txt";
	const char* filer = "result.txt";
	fp.open(file);
	ft.open(filer);
	if (!fp.is_open()) {
		cout << "stack";
	}
	else {
		char num;
		cout << "Содержание файла data.txt: ";
		while (fp.get(num)) {
			cout << num;
			double num1 = atof(&num);
			sum = sum + num1;
		}
	}
	if (!ft.is_open()) {
		cout << "stack";
	}
	else {
		ft << "Сумма компонент файла: " << sum;
	}
	fp.close();
	ft.close();
	return 0;
}

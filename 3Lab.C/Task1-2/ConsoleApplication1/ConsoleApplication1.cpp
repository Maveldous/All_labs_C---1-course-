#include "pch.h"
#include <iostream>
#include <Windows.h>

using namespace std;

//Вариант 11

void Baselvl();
void Middlelvl();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Baselvl();
	Middlelvl();
}

void Baselvl() {
	cout << "Введите строку: " << endl;
	char str[1000];
	cin.getline(str, 1205);
	int size = strlen(str), cnt_ellipsis = 0, cnt_colon = 0, cnt_semicolon = 0;
	for (int i = 0; i < size; i++) {
		if (str[i] == '*') {
			cnt_ellipsis++;
		}
		if (str[i] == ':') {
			cnt_colon++;
		}
		if (str[i] == ';') {
			cnt_semicolon++;
		}
	}
	cout << "В тексте содержится " 
		 << cnt_ellipsis << " - '*', " 
		 << cnt_colon << " - ':' и " 
		 << cnt_semicolon << " - ';' символов.";
}

void Middlelvl() {
	cout << "Введите строку:" << endl;
	char str[1000];
	cin.getline(str, 1205);
	int size = strlen(str), cntA = 0, cntA1 = 0;
	for (int i = 0; i <= size; i++) {
		if (str[i] == 'a' || str[i] == 'A' ) {
			cntA++;
		}
		else {
			if (cntA1 < cntA) {
				cntA1 = cntA;
			}
			cntA = 0;
		}
	}
	cout << "В тексте содержится " << cntA1 << " идущих подряд букв а/A.";
}
#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
#pragma warning(disable : 4996)

using namespace std;

void Baselvl();
void Middlelvl();
void Highlvl();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Baselvl();
	Middlelvl();
	Highlvl();
}

void Baselvl() {
	string str;
	cout << "Введите строку: ";
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (i == 1 || i == 2) {
			str.erase(i, 1);
		}
	}
	cout << str;
}

void Middlelvl() {
	string str;
	cout << "Введите строку: ";
	getline(cin,str);
	sort(str.begin(), str.end());
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == str[i + 1]) {
			str.erase(i, 1);
			i--;
		}
	}
	cout << str;
}

void Highlvl() {
	char str[100], str1[100] = "", str2[100] = "";
	int n1 = -1, n2 = 0;
	cout << "Введите строку: ";
	cin.getline(str, 100);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ' ') {
			n2 = i;
			if (n1 == -1) {
				n1 = i;
			}
		}
	}
	if (n1 != -1) {
		strcat(str1, str + n2 + 1);
		strncpy(str2, str + n1, n2-n1);
		strcat(str1, str2);
		strcat(str1, " ");
		strncat(str1, str, n1);
		cout << str1;
	}
	else {
		cout << "Введено меньше двух слов" << endl;
	}
}


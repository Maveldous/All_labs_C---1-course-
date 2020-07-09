#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <string.h>

using namespace std;

int sort(char str[13]);
void getoff(char *str1, char *str, int n);
int getnum(char z);
void trans(char *ans, int n, int z);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите число" << endl;
	char str[14];
	cin.getline(str, 14);
	int numbers = 13 - sort(str) - 1;
	char *str1 = new char[numbers];
	getoff(str1, str, sort(str));
	char *ans = new char[1000];
	for (int i = 0; i < numbers; i++) {
		trans(ans, getnum(str1[i]), i);
	}
	for (int i = 0; i < strlen(ans)/2; i++) {
		char temp = ans[i];
		ans[i] = ans[strlen(ans) - i];
		ans[strlen(ans) - i] = temp;
	}
}

int sort(char str[13]) {
	int count = 0;
	for (int i = 0; i < 13; i++) {
		if (str[i] == '0') {
			count++;
		}
		else {
			break;
		}
	}
	return count;
}

void getoff(char *str1, char *str, int n) {
	int n1 = 0;
	for (int i = 12; i > n - 1 ; i--) {
		str1[n1] = str[i];
		n1++;
	}
}

int getnum(char z) {
	switch (z)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	default:
		break;
	}
}

void trans(char *ans ,int n, int z) {
	switch (z)
	{
	case '0':
		if (n < 5) {
			for (int i = 0; i < n; i++) {
				strcat(ans, "I");
			}
		}
		else {
			strcat(ans, "V");
			for (int i = 0; i < n - 5; i++) {
				strcat(ans, "I");
			}
		}
	case '1':
		if (n < 5) {
			for (int i = 0; i < n; i++) {
				strcat(ans, "X");
			}
		}
		else {
			strcat(ans, "L");
			for (int i = 0; i < n - 5; i++) {
				strcat(ans, "X");
			}
		}
	case '2':
		if (n < 5) {
			for (int i = 0; i < n; i++) {
				strcat(ans, "C");
			}
		}
		else {
			strcat(ans, "D");
			for (int i = 0; i < n - 5; i++) {
				strcat(ans, "C");
			}
		}
	case '3':
		if (n < 5) {
			for (int i = 0; i < n; i++) {
				strcat(ans, "M");
			}
		}
		else {
			strcat(ans, "V̅");
			for (int i = 0; i < n - 5; i++) {
				strcat(ans, "M");
			}
		}
	case '4':
		if (n < 5) {
			for (int i = 0; i < n; i++) {
				strcat(ans, "X̅");
			}
		}
		else {
			strcat(ans, "L̅");
			for (int i = 0; i < n - 5; i++) {
				strcat(ans, "X̅");
			}
		}
	case '5':
		if (n < 5) {
			for (int i = 0; i < n; i++) {
				strcat(ans, "C̅");
			}
		}
		else {
			strcat(ans, "D̅");
			for (int i = 0; i < n - 5; i++) {
				strcat(ans, "C̅");
			}
		}
	default:
		for (int i = 0; i < n; i++) {
			strcat(ans, "M̅");
		}
	}
}


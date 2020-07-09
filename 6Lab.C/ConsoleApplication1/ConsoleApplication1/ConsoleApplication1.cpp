#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable : 4996)

using namespace std;

struct Workers {
	string lname;
	int age;
	string education;
	string position;
	string gender;
};

void taskMiddle();
void taskHigh();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	taskMiddle();
	taskHigh();
}

//Создать бинарный файл с информацией о работниках предприятия:фамилия;возраст;образование;должность;пол.Распечатать информацию о всех работниках женского пола без высшего образования, которым в этом году необходимо оформлять пенсию.

void taskMiddle() {
	srand(time(0));
	const char path[20] = "data.bin";
	string lnames[] = { "Lisa", "Petrov", "Sumchat", "Clara" };
	string educations[] = { "seceducation", "heducation", "heducation", "seceducation" };
	string positions[] = { "technical admin", "economist", "programmer", "vice president" };
	string genders[] = { "woman", "man", "man", "woman" };
	const int NUMBER = 4;

	Workers* workers = new Workers[NUMBER];
	for (size_t i = 0; i < NUMBER; i++) {
		cout << (workers[i].lname = lnames[i]) << '\n' << (workers[i].age = (50 + rand() % 50)) << '\n' << (workers[i].education = educations[i]) << '\n' << (workers[i].position = positions[i]) << '\n' << (workers[i].gender = genders[i]) << "\n\n";
	}
	FILE* f_out, *f_in;
	f_out = fopen(path, "wb");
	fwrite(workers, sizeof(Workers), NUMBER, f_out);
	fclose(f_out);
	delete[] workers;

	cout << "Required workers from file: " << "\n\n";

	Workers* workers1 = new Workers[NUMBER];
	f_in = fopen(path, "rb");
	fread(workers1, sizeof(Workers), NUMBER, f_in);
	for (size_t i = 0; i < NUMBER; i++) {
		if (workers1[i].gender == "woman" && workers1[i].education != "heducation" && workers1[i].age >= 60) {
			cout << workers[i].lname << '\n' << workers[i].age << '\n' << workers[i].education << '\n' << workers[i].position << '\n' << workers[i].gender << '\n' << '\n';
		}
	}
	fclose(f_in);
	delete[] workers1;
}

//Ввести в StringGrid значения двухмерного массива целых чисел размер-ностью 5×5 и записать в бинарный файл элементы этого массива по строчкам. Переписать бинарный файл так, чтобы значения элементов в каждой строке были увеличены в два раза. Распечатать этот массив до и после изменения данных в файле

void taskHigh() {
	srand(time(0));
	const char path[20] = "data.bin";
	const int NUMBER = 5;
	int **arr = new int*[NUMBER];
	for (size_t i = 0; i < NUMBER; i++) {
		arr[i] = new int[NUMBER];
	}
	for (size_t i = 0; i < NUMBER; i++) {
		for (size_t j = 0; j < NUMBER; j++) {
			arr[i][j] = (1 + rand() % 20);
		}
	}

	FILE * f_out, *f_in, *f_ed;
	f_out = fopen(path, "wb");
	fwrite(arr, sizeof(*arr), NUMBER, f_out);
	fclose(f_out);
	arr = nullptr;
	delete[] arr;

	cout << "\n\n" << "Файл, до перезаписи: " "\n";

	int **arr1 = new int*[NUMBER];
	for (size_t i = 0; i < NUMBER; i++) {
		arr1[i] = new int[NUMBER];
	}
	f_in = fopen(path, "rb");
	fread(arr1, sizeof(*arr1), NUMBER, f_out);
	for (size_t i = 0; i < NUMBER; i++) {
		cout << '\n';
		for (size_t j = 0; j < NUMBER; j++) {
			cout << arr1[i][j] << ' ';
		}
	}
	fclose(f_in);
	delete[] arr1;
	arr1 = nullptr;

	cout << "\n\n" << "Файл, после перезаписи: " << "\n";

	int **arr2 = new int*[NUMBER];
	for (size_t i = 0; i < NUMBER; i++) {
		arr2[i] = new int[NUMBER];
	}
	f_ed = fopen(path, "r+b");
	fread(arr2, sizeof(*arr2), NUMBER, f_out);
	for (size_t i = 0; i < NUMBER; i++) {
		for (size_t j = 0; j < NUMBER; j++) {
			arr2[i][j] = arr2[i][j] * 2;
		}
	}
	fclose(f_ed);
	arr2 = nullptr;
	delete[] arr2;

	int **arr3 = new int*[NUMBER];
	for (size_t i = 0; i < NUMBER; i++) {
		arr3[i] = new int[NUMBER];
	}
	f_in = fopen(path, "rb");
	fread(arr3, sizeof(*arr3), NUMBER, f_out);
	for (size_t i = 0; i < NUMBER; i++) {
		cout << '\n';
		for (size_t j = 0; j < NUMBER; j++) {
			cout << arr3[i][j] << ' ';
		}
	}
	fclose(f_in);
	delete[] arr3;
	arr3 = nullptr;
}
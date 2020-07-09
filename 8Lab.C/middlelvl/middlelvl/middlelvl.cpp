#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

//Средний уровень: Создать линейный однонаправленный список из вещественных чисел.
//Вставить в список число 1.5 после каждого элемента с отрицательным значением. Удалить из списка все числа от 2 до 5.

class List
{
public:
	List();
	void push_back(double number);
	int getSize();
	void remItem(const int index);
	void readAll();
	double& operator[](const int index);
	void insertVal(const int index, double value);

private:

	class Node {
	public:
		Node *pNext;
		double number;

		Node(double number = 2, Node *pNext = nullptr) {
			this->number = number;
			this->pNext = pNext;
		}
	};

	int Size;
	Node *head;
};

List::List() {
	Size = 0;
	head = nullptr;
}

void List::push_back(double number) {
	if (head == nullptr) {
		head = new Node(number);
		Size++;
	}
	else {
		Node *cur = this->head;
		while (cur->pNext != nullptr) {
			cur = cur->pNext;
		}
		cur->pNext = new Node(number);
		Size++;
	}
}

void List::remItem(const int index) {
	if (head == nullptr) {
		cout << "Список пуст!" << endl;
	}
	else if (this->Size < index || index < 0) {
		cout << "Введен неверный номер элемента в списке" << endl;
	}
	else {
		int counter = 0;
		Node *cur = this->head;
		while (counter + 1 != index)
		{
			cur = cur->pNext;
			counter++;
		}
		Node *temp = cur->pNext;
		cur->pNext = temp->pNext;
		delete temp;
		this->Size--;
	}
}

int List::getSize() {
	return this->Size;
}

void List::insertVal(const int index, double value) {
	if (head == nullptr) {
		cout << "Список пуст!" << endl;
	}
	else if (this->Size < index) {
		cout << "Введен неверный номер элемента в списке" << endl;
	}
	else {
		int counter = 0;
		Node *cur = this->head;
		while (counter != index)
		{
			cur = cur->pNext;
			counter++;
		}
		Node *temp = cur->pNext;
		cur->pNext = new Node(value, temp);
		this->Size++;
	}
}

void List::readAll() {
	if (head != nullptr) {
		Node *current = head;
		cout << "Числа в списке: " << current->number;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
			cout << ", " << current->number;
		}
		cout << '\n' << '\n';
	}
	else {
		cout << "Список пуст!";
	}
}

double& List::operator[](const int index) {
	int counter = 0;
	Node *cur = this->head;
	while (cur != nullptr) {
		if (counter == index) {
			return cur->number;
		}
		cur = cur->pNext;
		counter++;
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List first;

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0) first.push_back(-i);
		else first.push_back(i);
	}

	for (int i = 0; i < first.getSize(); i++) {
		if (first[i] < 0) {
			first.insertVal(i, 1.5);
		}
	}

	first.readAll();
	cout << '\n';

	for (int i = 0; i < first.getSize(); i++) {
		if (first[i] >= 2 && first[i] <= 5) {
			first.remItem(i);
		}
	}
	first.readAll();

	return 0;
}

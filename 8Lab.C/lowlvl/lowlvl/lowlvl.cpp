#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

//Низкий уровень: Создать линейный однонаправленный список из целых чисел. 
//Определить среднее арифметическое значений элементов списка, начиная с 5-го элемента списка
// до конца (если элементов меньше пяти, выдать результат 0).

class List
{
public:
	List();
	//~List();
	void push_back(int number);
	int getSize();
	int getAver(const int index);
	int& operator[](const int index);

private:

	class Node {
	public:
		Node *pNext;
		int number;

		Node(int number = 2, Node *pNext = nullptr) {
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

void List::push_back(int number) {
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

int List::getSize() {
	return this->Size;
}

int List::getAver(const int index) {
	if (head == nullptr) {
		cout << "Список пуст!" << endl;
		return 0;
	}
	else if (this->Size < index) {
		cout << "Введено меньше чем " << index << " элементов" << endl;
		return 0;
	}
	else {
		int counter = 0, sum = 0;
		Node *cur = this->head;
		while (cur != nullptr)
		{
			if (counter >= index) {
				sum = sum + cur->number;
			}
			cur = cur->pNext;
			counter++;
		}
		return (sum / (this->Size - index));
	}
}

int& List::operator[](const int index) {
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
		first.push_back(i);
	}
	cout << "Среднее арифметическое чисел в списке от 5 элемента: " << first.getAver(5);

	return 0;
}

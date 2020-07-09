#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

//Высокий уровень: Дан указатель P1 на первый элемент не пустого двусвязного списка. 
//Перегруппировать его элементы, переместив все элементы с нечетными номерами в конец списка (в том же порядке) и вывести указатель на первый элемент преобразованного списка. 
//Операции выделения и освобождения памяти не использовать, поля с данными (Data) не изменять.

class List
{
public:
	List();
	void push_back(int number);
	void push_front(int number);
	void remItem(const int index);
	int getSize();
	void readAll();
	bool isEmpty();
	int& operator[](const int index);

private:

	class Node {
	public:
		Node *pNext, *pPrev;
		int number;

		Node(int number = 2, Node *pNext = nullptr, Node *pPrev = nullptr) {
			this->number = number;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};

	int Size;
	Node *head, *tail;
};

List::List() {
	Size = 0;
	head = nullptr;
	tail = nullptr;
}

int List::getSize() {
	return this->Size;
}

void List::push_back(int number) {
	if (head == nullptr) {
		head = new Node(number);
		tail = head;
		Size++;
	}
	else {
		head = new Node(number, head);
		Node *temp = head->pNext;
		temp->pPrev = head;
		Size++;
	}
}

void List::push_front(int number) {
	if (tail == nullptr) {
		tail = new Node(number);
		head = tail;
		Size++;
	}
	else {
		tail = new Node(number, nullptr, tail);
		Node *temp = tail->pPrev;
		temp->pNext = tail;
		Size++;
	}
}


void List::remItem(const int index) {
	int counter = 0;
	if (head == nullptr) {
		cout << "Список пуст!" << endl;
	}
	else if (this->Size < index || index < 0) {
		cout << "Введен неверный номер элемента в списке" << endl;
	}
	else if (index > Size / 2) {
		counter = Size - 1;
		Node *cur = this->tail;
		while (cur != nullptr) {
			if (counter == index) {
				break;
			}
			cur = cur->pPrev;
			counter--;
		}
		Node *temp = cur->pPrev;
		temp->pNext = cur->pNext;
		(cur->pNext)->pPrev = temp;
		delete cur;
		this->Size--;
	}
	else{
		counter = 0;
		Node *cur = this->head;
		while (counter != index)
		{
			cur = cur->pNext;
			counter++;
		}
		Node *temp = cur->pPrev;
		temp->pNext = cur->pNext;
		(cur->pNext)->pPrev = temp;
		delete cur;
		this->Size--;
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
		cout << "Очередь пуста!";
	}
}

bool List::isEmpty() {
	if (head == nullptr) return true;
	else return false;
}

int& List::operator[](const int index) {
	int counter = 0;
	if (index > Size / 2) {
		counter = Size-1;
		Node *cur = this->tail;
		while (cur != nullptr) {
			if (counter == index) {
				return cur->number;
			}
			cur = cur->pPrev;
			counter--;
		}
	}
	else if (index <= Size / 2) {
		Node *cur = this->head;
		while (cur != nullptr) {
			if (counter == index) {
				return cur->number;
			}
			cur = cur->pNext;
			counter++;
		}
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int counter = 0;
	List first;
	for (int i = 0; i < 10; i++) {
		first.push_back(i);
	}
	first.readAll();

	for (int i = 0; i < first.getSize(); i++) {
		if (i % 2 != 0) {
			first.push_front(first[i - counter]);
			first.remItem(i - counter);
			counter++;
		}
	}
	first.readAll();

	return 0;
}
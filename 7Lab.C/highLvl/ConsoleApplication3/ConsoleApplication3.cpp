#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

//Высокий уровень: Даны две непустые очереди; адреса начала иконца первой равны P1 иP2, авторой—P3 иP4.
//Элементы каждой изочередей упорядочены по возрастанию (в направлении отначала очереди к концу).
//Объединить очереди в одну с сохранением упорядоченности элементов.
//Вывести указатели наначало иконец полученной очереди.
//Операции выделения и освобождения памяти не использовать, поля с данными (Data) не изменять.


class List
{
public:
	List();
	//~List();
	void push(int number);
	void out();
	int readF();
	int readL();
	void readAll();
	bool isEmpty();

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

	Node *head, *tail;
};

List::List() {
	head = nullptr;
	tail = nullptr;
}

void List::push(int number) {
	if (head == nullptr) {
		head = new Node(number);
		tail = head;
	}
	else {
		head = new Node(number, head);
		Node *temp = head->pNext;
		temp->pPrev = head;
	}
}

void List::out() {
	if (head == nullptr) {
		cout << "The list is empty" << endl;
	}
	else if (tail->pPrev == nullptr) {
		delete tail;
		head = nullptr;
		tail = nullptr;
	}
	else {
		tail = tail->pPrev;
		delete tail->pNext;
		tail->pNext = nullptr;
	}
}

int List::readF() {
	//cout << "Первый элемент списка: " << tail->number << endl;
	return tail->number;
}

int List::readL() {
	//cout << "Последний элемент списка: " << head->number << endl;
	return head->number;
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


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List first, second, third;
	for (size_t i = 10; i > 0; i--) {
		first.push(i);
	}

	for (size_t i = 15; i > 3; i--) {
		second.push(i);
	}

	first.readAll();
	second.readAll();
	while (!first.isEmpty() || !second.isEmpty()) {
		if (!first.isEmpty() && !second.isEmpty()) {
			if (first.readF() >= second.readF()) {
				third.push(first.readF());
				first.out();
			}
			else {
				third.push(second.readF());
				second.out();
			}
		}
		else if (second.isEmpty()) {
			third.push(first.readF());
			first.out();
		}
		else {
			third.push(second.readF());
			second.out();
		}
	}
	third.readAll();

	return 0;
}

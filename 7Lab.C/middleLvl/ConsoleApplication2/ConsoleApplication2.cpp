#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>

using namespace std;

//Средний уровень: Создать очередь вещественных значений, для реализации используя односвязные списки.
//Реализовать операции добавления (enqueue) и удаления (dequeue) элемента из очереди. Добавьте в очередь числа 2.2, 3.2, 2.4, -3.2 и распечатайте содержимое очереди.
//Удалите 1 элемент из очереди, затем добавьте в очередь число 0.04 и распечатайте очередь еще раз. * Найдите сумму чисел по модулю меньших 1, принадлежащих очереди.

class List
{
public:
	List();
	//~List();
	void push(double number);
	void out();
	void readF();
	void readL();
	void readAll();
	void readAll(int enter);

private:

	class Node {
	public:
		Node *pNext, *pPrev;
		double number;

		Node(double number = 2, Node *pNext = nullptr, Node *pPrev = nullptr) {
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

void List::push(double number) {
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

void List::readF() {
	cout << "Первый элемент очереди: " << tail->number << '\n' << '\n';
}

void List::readL() {
	cout << "Последний элемент очереди: " << head->number << '\n' << '\n';
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

void List::readAll(int enter) {
	if(head != nullptr && enter > 0){
		double sum = 0;
		Node *current = head;
		do
		{
			if (abs(current->number) < enter) {
				sum += current->number;
			}
			current = current->pNext;
		} while (current->pNext != nullptr);
		cout << "Сумма всех элементов очереди по модулю меньших " << enter << " равна: " << sum;
	}
	else {
		cout << "Введены недопустимые значения или очередь пуста!";
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List first;

	first.push(2.2);
	first.push(3.2);
	first.push(2.4);
	first.push(-3.2);
	first.readAll();

	first.readF();
	first.readL();
	first.out();
	first.push(0.04);
	first.readAll();
	first.readAll(1);

	return 0;
}

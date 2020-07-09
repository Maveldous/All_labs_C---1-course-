#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

//Начальный уровень: Создать очередь, информационными полями которой являются: фамилия и средний бал студента.
//Добавить в очередь сведения о новом студенте. Организовать просмотр данных очереди.


class List
{
public:
	List();
	//~List();
	void push(string surName, int averMark);
	void out();
	void readF();
	void readL();

private:

	class Node {
	public:
		Node *pNext, *pPrev;
		string surName;
		int averMark;

		Node(string surName = "n", int averMark = 2, Node *pNext = nullptr, Node *pPrev = nullptr) {
			this->surName = surName;
			this->averMark = averMark;
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

void List::push(string surName, int averMark) {
	if (head == nullptr) {
		head = new Node(surName, averMark);
		tail = head;
	}
	else {
		head = new Node(surName, averMark, head);
		Node *temp = head->pNext;
		temp->pPrev = head;
	}
}

void List::out() {
	if (head == nullptr) {
		cout << "The list is empty" << endl;
	}
	else if(tail->pPrev == nullptr) {
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
	cout << "Фамилия студента: " << tail->surName << ", средний бал: " << tail->averMark << endl;
}

void List::readL() {
	cout << "Фамилия студента: " << head->surName << ", средний бал: " << head->averMark << endl;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List first;
	first.push("Misurin", 10);
	first.push("Soma", 9);

	first.readF();
	first.readL();
	first.out();

	first.readF();
	first.readL();
	return 0;
}

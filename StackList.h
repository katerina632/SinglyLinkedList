#pragma once
#include<iostream>

using namespace std;

template <class T>
class StackList
{
private:
	struct Node {
		T value;
		Node* next;
	};
	Node* head;
	int size;
public:
	StackList() : head(nullptr), size(0) { }
	StackList(const StackList& other)
	{
		head = nullptr;
		size = 0;

		Node* current = other.head;

		while (current != nullptr) {
			AddToHead(current->value);
			current = current->next;
		}
	}

	~StackList()
	{
		DeleteAll();
	}
	StackList& operator=(const StackList& other) {

		if (this == &other)
			return *this;

		while (!IsEmpty())
			DeleteHead();

		Node* current = other.head;

		while (current != nullptr) {
			AddToHead(current->value);
			current = current->next;
		}

		return *this;
	}

	bool IsEmpty() const
	{
		return head == nullptr;
	}

	void Push(const T& value) {
		Node* newNode = new Node;
		newNode->value = value;
		if (IsEmpty())
			newNode->next = nullptr;
		else
			newNode->next = head;
		head = newNode;
	}

	T Pop() {
		if (IsEmpty()) {
			cout << "List is empty!" << endl;
			return 0;
		}

		Node* temp = head->next;
		T value = head->value;
		delete head;
		head = temp;
		return value;
	}

	T Peek()const {
		if (IsEmpty()) {
			cout << "List is empty!" << endl;
			return 0;
		}
		return head->value;
	}

	void Print() const
	{
		Node* current = head;
		while (current != nullptr) {

			if (current->next == nullptr)
				cout << current->value << " ";
			else
				cout << current->value << ", ";

			current = current->next;
		}
	}

	void DeleteAll() {
		while (!IsEmpty())
			DeleteHead();
	}

	void DeleteHead()
	{
		if (head == nullptr) return;

		Node* temp = head->next;
		delete head;

		if (temp == nullptr)
			head = nullptr;
		else
			head = temp;

		size--;
	}





};


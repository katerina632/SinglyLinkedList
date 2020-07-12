#pragma once
#include <iostream>
using namespace std;

template <class T>
class List
{
private:
	struct Node
	{
		T value;
		Node* next;
	};

	Node* head;
	int size;
public:
	List() : head(nullptr), size(0) { }
	~List()
	{
		DeleteAll();
	}

	List(const List& other)
	{
		head = nullptr;
		size = 0;

		Node* current = other.head;

		while (current != nullptr) {
			AddToHead(current->value);
			current = current->next;
		}
	}

	List& operator=(const List& other) {
		
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

	bool IsValidPos(int pos) {

		return (pos >= 1 && pos <= size);
	}
	
	void AddToHead(T value)
	{
		Node* newElem = new Node;
		newElem->value = value;
		newElem->next = head;
		head = newElem;

		size++;
	}

	
	void AddToTail(T value)
	{
		Node* newElem = new Node;
		newElem->value = value;
		newElem->next = nullptr;

		if (head == nullptr)
		{
			head = newElem;
		}
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{				
				current = current->next;
			}
			current->next = newElem;
		}
		size++;
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

	
	void DeleteTail()
	{
		if (head == nullptr) return;

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* current = head;
			while (current->next->next != nullptr)
			{
				
				current = current->next;
			}

			
			delete current->next;
			current->next = nullptr;
		}

		size--;
	}

	int GetSize() {
		return size;
	}

	void Print() const
	{
		Node* current = head;
		while (current != nullptr)	{			
			
			if (current->next==nullptr)
				cout<< current->value << " ";
			else
				cout << current->value << ", ";
			
			current = current->next;
		}
	}

	void DeleteAll() {
		while (!IsEmpty())
			DeleteHead();
	}

	void Find(int pos) {

		if (IsEmpty()) {
			cout << "List is empty!" << endl;
			return;
		}

		if (!IsValidPos(pos))
		{			
			cout << "Incorrect position! " << endl;
			return;
		}
		Node* temp;

		temp = head;
		int i = 1;
		while (i < pos)		{
			
			temp = temp->next;
			i++;
		}		
		cout << pos << " element: ";
		cout << temp->value << endl;
	}


	void Insert(int pos, T value) {	
		
		if (pos < 1 || pos > size + 1)
		{
			cout << "Incorrect position! " << endl;
			return;
		}
		
		if (pos == size + 1)
		{			
			AddToTail(value);
			return;
		}
		else if (pos == 1)
		{			
			AddToHead(value);
			return;
		}	
		else {

			int i = 1;
			Node* temp = new Node;
			temp->value = value;
			Node* insert = head;
			while (i < pos - 1)
			{
				insert = insert->next;
				i++;
			}
			temp->next = insert->next;
			insert->next = temp;

			size++;
		}
	}

	void DelPos(int pos) {
				
		if (!IsValidPos(pos))
		{
			cout << "Incorrect position! " << endl;
			return;
		}
		
		int i = 1;
		Node* del = head;
		while (i < pos-1)
		{			
			del = del->next;
			i++;
		}		
		
		if (pos == 1)
			DeleteHead();
		else if (pos == size)
			DeleteTail();
		else {

			Node* temp = del->next;
			del->next = temp->next;
			delete temp;
			size--;
		}				
	}

};




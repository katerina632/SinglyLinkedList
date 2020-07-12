#include<iostream>
#include "List.h"
#include "StackList.h"

using namespace std;

int main()
{
	//Zavdannja 1
	List<int> ls;

	ls.AddToHead(10);
	ls.AddToHead(15);
	ls.AddToHead(5);
	ls.AddToHead(20);

	ls.Print(); cout << endl;

	ls.DeleteHead();
	ls.AddToTail(777);

	ls.Print(); cout << endl;

	ls.DeleteTail();

	ls.Print(); cout << endl;
	cout << ls.GetSize() << endl;	

	ls.Find(2);	
	
	List<int> l2;
	l2 = ls;
	l2.Print();

	l2.Insert(2,4);
	cout << endl;
	l2.Print();

	l2.DelPos(3);
	cout << endl;
	l2.Print();
	cout << endl << endl;

	//Zavdannja 2
	StackList<int> st1;
	st1.Push(1);
	st1.Push(2);
	st1.Push(3);

	st1.Print();

	cout<<st1.Peek();
	cout << st1.Pop();
	cout << st1.Peek();


	system("pause");
	return 0;
}
// main.cpp : Defines the entry point for the console application.
#include "CircularPriorityQueue.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	int choice;
	int size;
	int value = 0;
	cout << "---------- Priority Circular Queue ----------" << endl;
	cout << "Enter the size of queue : ";
	cin >> size;
	CircularPriorityQueue op = CircularPriorityQueue(size);
	do
	{
		cout << endl;
		op.options();
		cout << endl; 
		cout << "Enter your choice : ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			cout << "Enter the value for input : ";
			cin >> value;
			op.insertElement(value);
			break;

		case 2:
			op.removeFirst();
			break;

		case 3:
			op.removeLast();
			break;
		
		case 4:
			cout << endl;
			cout << "Head is pointing at : " << op.getHead() << endl;
			cout << endl;
			break;

		case 5:
			cout << endl;
			cout << "Tail is pointing at : " << op.getTail() << endl;
			cout << endl;
			break;

		case 6:
			cout << "endl";
			cout << "Element at head is : " << op.headElement() << endl;
			break;

		case 7:
			cout << endl;
			cout << "Element at tail is : " << op.tailElement() << endl;
			break;

		case 8:
			cout << endl;
			op.printQueue();
			break;

		case 9:
			cout << "Size is : " << op.size << endl;
			break;
		
		case 10:
			op.grow();
			break;
		
		case 11:
			cout << "Thank you :)" << endl;
			break;

		default:
			cout << "Choose right option!" << endl;
			break;
		}
	} while (choice != 11);
	_getch();
	return 0;
}


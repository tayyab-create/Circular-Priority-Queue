#include "CircularPriorityQueue.h" // Include the header file
#include <iostream>
using namespace std;

//This file consists the implementation of functions of Circular Priority Queue!
CircularPriorityQueue::CircularPriorityQueue()
{
	size = 100;
	A = new int[size];
	head = tail = 0;
	count = 0;
}

CircularPriorityQueue::CircularPriorityQueue(int value)
{
	size = value;
	A = new int[size];
	head = tail = 0;
	count = 0;
}

CircularPriorityQueue::~CircularPriorityQueue()
{
	delete[]A;
}


void CircularPriorityQueue::insertElement(int value)
{
	if (!isFull())
	{
		if (isEmpty())
		{
			A[0] = value;
			tail = (tail + 1) % size;
			count++;
			cout << "Element is added!" << endl;
		}
		else
		{
			//grow();
			if (tail > 0 && A[tail - 1] < value)
			{
				A[tail] = value;
				tail = (tail + 1) % size;
				count++;
				cout << "Element is inserted!" << endl;
			}
			else
			{
				int temp;
				int temp1;
				int max = NULL;
				for (int i = head; i != tail;)
				{
					if (A[i] >= value)					// Find greater value from upcoming value
					{
						max = i;
						temp = A[i];
						break;
					}
					i = (i + 1) % size;
				}
				for (int j = max; j != tail;)		// Shifting elements from that positon where we find greater value to tail 
				{
					temp1 = A[(j + 1) % size];
					A[(j + 1) % size] = temp;
					temp = temp1;
					j = (j + 1) % size;
				}
				A[max] = value;					// Insert value where we find greater value
				tail = (tail + 1) % size;
				count++;
				cout << "Element inserted successfully!" << endl;
			}
		}
	}
	else
	{
		cout << endl;
		cout << "Queue is full!\nCannot add element!" << endl;
		cout << endl;
	}
}



void CircularPriorityQueue::removeFirst()
{
	if (!isEmpty())
	{
		A[head] = NULL;
		head = (head + 1) % size;
		count--;
		cout << endl;
		cout << "Element is removed!" << endl;
	}
	else
	{
		cout << endl;
		cout << "Queue is Empty!" << endl;
		cout << endl;
	}
}


bool CircularPriorityQueue::isEmpty()
{
	return (count == 0);
}


bool CircularPriorityQueue::isFull()
{
	return (count == size);
}


void CircularPriorityQueue::printQueue() //This is a tricky function! You have to give some extra attention towards it.
{
	if (!isEmpty())
	{
		cout << endl;
		cout << "Head = " << head << endl;
		cout << "Tail = " << tail << endl;
		cout << endl;
		int i = head;
		do
		{
			cout << "A[" << i << "] = " << A[i] << endl;
			i = (i + 1) % size;
		} while (i != tail);
	}
	else
	{
		cout << endl;
		cout << "Queue is empty!" << endl;
		cout << endl;
	}
}


int CircularPriorityQueue::headElement()
{
	return A[head];
}


int CircularPriorityQueue::tailElement()
{
	return A[tail - 1];
}


int CircularPriorityQueue::getTail()
{
	return tail;
}


int CircularPriorityQueue::getHead()
{
	return head;
}

void CircularPriorityQueue::removeLast()
{
	if (!isEmpty())
	{
		if (tail == 0)
		{
			A[size - 1] = NULL;
			tail = size - 1;
			count--;
			cout << endl;
			cout << "Element is removed!" << endl;
		}
		else
		{
			A[(tail - 1) % size] = NULL;
			tail = (tail - 1) % size;
			count--;
			cout << endl;
			cout << "Element is removed!" << endl;
		}
	}
	else
	{
		cout << endl;
		cout << "Queue is Empty!" << endl;
		cout << endl;
	}
}


int CircularPriorityQueue::grow() // Dynamically growing array function
{
	CircularPriorityQueue temp;
	if (float (count) / size >= 0.7) //When size of array becomes 70% of given size then the size of array will increase!
	{
		size = size * 2;
		temp.A = new int[count];
		for (int i = 0; i < count; i++) //Copying all elemnts in a new array
		{
			temp.A[i] = A[i];
		}
		A = new int[size];
		for (int i = 0; i < count; i++)
		{
			A[i] = temp.A[i];
		}
		delete[]temp.A;
		cout << "Grow sucessfuly!" << endl;
		return *A;
	}
	else
	{
		cout << "Array cannot be grow !" << endl;
		return NULL;
	}
	
}


void CircularPriorityQueue::options()	//Menu options
{
	cout << "Enter 1 for inserting element!" << endl;
	cout << "Enter 2 for deleting First!" << endl;
	cout << "Enter 3 for deleting Last!" << endl;
	cout << "Enter 4 for getting Head value!" << endl;
	cout << "Enter 5 for getting Tail value!" << endl;
	cout << "Enter 6 for getting Head Element!" << endl;
	cout << "Enter 7 for getting tail Element!" << endl;
	cout << "Enter 8 for printing queue!" << endl;
	cout << "Enter 9 for total size!" << endl;
	cout << "Enter 10 for grow!" << endl;
	cout << "Enter 11 for exiting!" << endl;
}


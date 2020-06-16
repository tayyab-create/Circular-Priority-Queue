class CircularPriorityQueue	//Header file consists of all functions performed in this program
{
public:
	CircularPriorityQueue();
	CircularPriorityQueue(int);0
	~CircularPriorityQueue();
	void insertElement(int);
	void removeFirst();
	int headElement();
	int tailElement();
	int headPoint();
	int tailPoint();
	int getTail();
	int getHead();
	int *A;
	int head, tail, size, count;
	bool isEmpty();
	bool isFull();
	void printQueue();
	void options();
	void removeLast();
	int grow();
};

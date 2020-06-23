#include<iostream>
using namespace std;
typedef int Error_code;
#define  SUCCESS 0
#define OVERFLOW -1
#define UNDERFLOW -2


class queue{
protected:
	int front, rear;
	int size;
	int count;
	int* queuearray;

public:
	queue();
	queue(int n);
	~queue();
	Error_code appened(int item);
	Error_code serve();
	Error_code retrive(int& item);
	bool isEmpty();
	bool isFull();
};


queue::queue() {
	front = rear = 0;
	size = 10;
	count = 0;
	queuearray = new int[size];//defulat size 10
}

queue::queue(int n) {
	front = rear = 0;
	size = n;
	count = 0;
	queuearray = new int[size];
}

queue::~queue() {
	delete[] queuearray;
}

// appened to rear ....
Error_code queue::appened(int item) {  
	Error_code outcome = SUCCESS;
	if (isFull()) {
		cout << "full queue" << endl;
		outcome = OVERFLOW;
	}
	else {
		queuearray[rear] = item;
		rear = (rear + 1) % size;
		count++;
	}
	return outcome;
}

//take from Front and return data....
Error_code queue::retrive(int &item) {
	Error_code outcome = SUCCESS;
	if (isEmpty()) {
		cout << "Empty queue" << endl;
		outcome = UNDERFLOW;
	}
	else {
	 item=queuearray[front]  ;
	}
	return outcome;
}



Error_code queue::serve() {
	Error_code outcome = SUCCESS;
	if (isEmpty()) {
		cout << "Empty queue" << endl;
		outcome = UNDERFLOW;
	}
	else {
		front = (front + 1) % size;
		count--;
	}
	return outcome;
}

bool queue::isEmpty() {
	if (front== rear)
		return true;
	else
		return false;
}


bool queue::isFull() {
	if ((rear+1)%size==front)
		return true;
	else
		return false;
}


int main() {
	int x;
	queue q1(4);
	queue q2();
	cout << "the queue is ";
	q1.isFull() ? cout << "\n is full \n " : cout << "\n not full \n";
	cout << "the queue is ";
	q1.isEmpty() ? cout << "\n is empty \n " : cout << "\n not empty \n";

	q1.appened(2);
	q1.appened(3);
	q1.appened(5);

	q1.appened(2);

	q1.retrive(x);
	cout << x << endl;
	q1.serve();

	q1.retrive(x);
	cout << x << endl;
	q1.serve();


	q1.retrive(x);
	cout << x << endl;
	q1.serve();

	q1.retrive(x);
	cout << x << endl;
	q1.serve();

	q1.retrive(x);
	cout << x << endl;
	return 0;
};





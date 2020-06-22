#include<iostream>
using namespace std;
typedef int Error_code;
#define  SUCCESS 0
#define OVERFLOW -1
#define UNDERFLOW -2


class queue {
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
Error_code queue::retrive(int& item) {
	Error_code outcome = SUCCESS;
	if (isEmpty()) {
		cout << "Empty queue" << endl;
		outcome = UNDERFLOW;
	}
	else {
		item = queuearray[front];
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
	if (front == rear)
		return true;
	else
		return false;
}


bool queue::isFull() {
	if ((rear + 1) % size == front)
		return true;
	else
		return false;
}

class extendedqueue : public queue {
public:
	extendedqueue();
	extendedqueue(int n);
	int queuesize();
	void clear();
	Error_code serveandretreve(int& item);
};

extendedqueue::extendedqueue() {
	cout << "extended queue defult constructer, size = " << size << endl;
}

extendedqueue::extendedqueue(int n):queue(n) {
	cout << "extended queue constructer, size = " << size << endl;
}int extendedqueue::queuesize() {
	return count;
}
void extendedqueue::clear() {
	count=front=rear;
}

Error_code extendedqueue :: serveandretreve(int& item){
	Error_code outcome = SUCCESS;
	if (isEmpty()) {

		outcome = UNDERFLOW;
		cout << "Empty queue" << endl;
	}
	else {
		item = queuearray[front];
		front = (front + 1) % size;
		count--;
	}
	return outcome;
}

int main() {
	int x;
	extendedqueue eq1(4);
	extendedqueue eq2();
	cout << "the queue is ";
	eq1.isFull() ? cout << "\n is full \n " : cout << "\n not full \n";
	cout << "the queue is ";
	eq1.isEmpty() ? cout << "\n is empty \n " : cout << "\n not empty \n";

	eq1.appened(2);
	eq1.appened(3);
	eq1.appened(5);
	cout << "current size = " << eq1.queuesize() << endl;
	eq1.appened(7);

	eq1.retrive(x);
	cout << x << endl;
	eq1.serve();

	eq1.serveandretreve(x);
	cout << x << endl;
	eq1.serveandretreve(x);
	cout << x << endl;
	eq1.serveandretreve(x);
	return 0;
};





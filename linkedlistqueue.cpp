#include<iostream>
using namespace std;
typedef int Error_code;
#define SUCCESS 0
#define OVERFLOW -1
#define UNDERFLOW -2

class NODE {
public:
	int item;
	NODE* next;
	NODE() {
		item = 0;
		next = NULL;
	}
	NODE(int n) {
		item = n;
		next = NULL;
	}
};

class queue {
protected:
	int count;
	NODE* front, * rear;
public:
	queue();
	~queue();
	Error_code serve();
	Error_code append(int item);
	Error_code retreive(int &item);
	bool isfull() { return false; };
	bool isempty();
};

queue::queue() {
	cout << "queue defult constructer" << endl;
	front = rear = NULL;
	count = 0;
}
queue::~queue() {
	NODE* p;
	while (front != NULL) {
		p = front;
		front = front->next;
		delete p;
	}
}
Error_code queue::append(int item) {
	NODE* n;
	n = new NODE;
	n->item = item;
	n->next = NULL;
	if (isempty()) {
		front = rear = n;
	}
	else {
		rear->next = n;
		rear = n;
	}
	count++;
	return SUCCESS;
}
Error_code queue::retreive(int& item) {
	Error_code outcome = SUCCESS;
	if (isempty()) {
		cout << "empty queue.." << endl;
		outcome = UNDERFLOW;
	} 
	else {
		item = front->item;
	}
	return outcome;
}

Error_code queue::serve() {
	Error_code outcome = SUCCESS;
	if (isempty()) {
		cout << "empty queue.." << endl;
		outcome = UNDERFLOW;
	}
	else {
		NODE *p = front;
		front= front->next;
		delete p;
		count--;
	}
	return outcome;
}

bool queue::isempty()
{
	if (front == NULL)
		return true;
	else
		return false;
}

int main() {
	int x;
	queue q;
	cout << "the queue is...";
	q.isempty() ? cout << "empty \n\n" : cout << "not empty \n\n";
	q.append(2);
	q.append(3);
	q.append(5);

	q.retreive(x);
	cout << x << endl;
	q.serve();

	q.retreive(x);
	cout << x << endl; //must call serve...


	q.retreive(x);
	cout << x << endl;
	q.serve();

	q.retreive(x);
	cout << x << endl;
	q.serve();

	q.retreive(x);
	return 0;
}
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
	Error_code retreive(int& item);
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
		NODE* p = front;
		front = front->next;
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

class extendedqueue : public queue {
public:
	extendedqueue();
	int queuesize();
	void clear();
	Error_code serveandretrive(int& item);
};
extendedqueue::extendedqueue() {
	cout << "extended queue defult constructer ..." << endl;
}

void extendedqueue::clear() {
	NODE* P;
	while (front != NULL) {
		P = front;
		front = front->next;
		delete P;
	}
	rear = NULL;
	count = 0;
}

int extendedqueue::queuesize() {
	return count;
}
Error_code extendedqueue :: serveandretrive(int& item) {
	Error_code outcome = SUCCESS;
	NODE* P;
	if (isempty()) {
		outcome = UNDERFLOW;
		cout << "empty queue ..."<<endl;
	}
	else {
		item = front->item;
		P = front;
		front = front->next;
		delete P;
		count--;
	}
	return outcome;
}

int main() {
	int x;
	extendedqueue eq;
	cout << "the queue is...";
	eq.isempty() ? cout << "empty \n\n" : cout << "not empty \n\n";
	eq.append(2); eq.append(4); eq.append(6);
	eq.append(8); eq.append(10); eq.append(12);
	cout << "current size = " << eq.queuesize() << endl;
	

	eq.retreive(x);
	cout << x << endl; //2
	eq.serve();
	eq.serveandretrive(x);
	cout << x << endl; //4..
	eq.serveandretrive(x);
	cout << x << endl;
	cout << "current size = " << eq.queuesize() << endl;
	eq.serveandretrive(x);
	cout << x << endl; 
	eq.clear();
	cout << "current size after clear  = " << eq.queuesize() << endl;
	return 0;
	
}
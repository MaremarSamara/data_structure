#include<iostream>
using namespace std;
#define size 100

int q[size];
int first = 0;
int last = 0;

void add(int item) {
	if ((last + 1) % size == first) {
		cout << "full queue " << endl;
		return;
	}
	q[last] = item;
	last = (last + 1) % size;
}

int get() {
	int data;
	if ( last== first) {
		cout << "empty queue"<<endl;
		return -1;
	}
	data = q[first];
	first = (first + 1) % size;
	return data;
}

int main() {
	int x = 3;
	int y = 4;
	int z = 5;
	add(x);
	add(y);
	add(z);
	cout << get() << endl;
	cout << get() << endl;
	cout << get() << endl;
	cout << get() << endl;
	return 0;
}
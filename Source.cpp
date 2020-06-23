#include <iostream> 
using namespace std;
#define size 100
int stack[size];
int sp = 0;
void push(int data) {
	if (sp == size) {
		cout << "Full stack" << endl;
	}
	stack[sp] = data;
	sp++;

}
int pop() {
	if (sp == 0) {
		cout << "Empty stack";
		return -1;
	}
	--sp;
	return stack[sp];
}

int main() {
	int x = 5, y = 6;
	push(x);
	push(y);
	push(7);
	cout << pop() << endl;
	cout << pop() << endl;

	push(3);
	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;
}




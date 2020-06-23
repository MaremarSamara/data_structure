#include<iostream>
using namespace std;
typedef int Error_code;
#define SUCCESS 0
#define OVERFLOW -1
#define UNDERFLOW -2

class Stack {
private:
	int count;
	int size;
	int *stackArray;

public:
	Stack();
	Stack(int n);
	~Stack();
	Error_code pop();
	Error_code push(int item);
	Error_code top(int &item);
	bool isEmptyst();
	bool isFullst();

};

Stack::Stack(){
	size=10;
	count=0;
	stackArray=new int[size];
}




Stack::Stack(int n){
	size=n;
	count=0;
	stackArray=new int[size];
}


Stack::~Stack(){
 delete []stackArray;
}

Error_code Stack:: push(int item){
	Error_code outcome=SUCCESS;
	if(isFullst())
		outcome =OVERFLOW;
	else{
		stackArray[count]=item;
		count++;
	}
	return outcome;
}
Error_code Stack::top(int& item) {
	Error_code outcome = SUCCESS;
	if (isEmptyst())
		outcome = UNDERFLOW;
	else
		item = stackArray[count-1];
	return outcome;
}
Error_code Stack::pop() {
	Error_code outcome = SUCCESS;
	if (isEmptyst())
		outcome = UNDERFLOW;
	else 
		count--;
	
	return outcome;
}

bool Stack::isEmptyst() {
	if (count == 0)
		return true;
	else
		return false;
}

bool Stack::isFullst() {
	if (count == size)
		return true;
	else
		return false;
}




int main() {
	int x, y;
	Stack st1; 
	Stack st2(20);

	cout << st1.isFullst() << endl;
	cout << st1.isEmptyst() << endl;



	st1.push(3);
	st1.push(5);
	cout << st1.top(x) << endl;
	cout << x << endl;


	st1.pop();
	cout << st1.top(y) << endl;
	cout << y << endl;
	st1.pop();

	cout << st1.top(y) << endl;
	cout << y << endl;
	return 0;

}


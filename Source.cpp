#include<iostream>
using namespace std;
typedef int error_code;
#define SUCCESS 0
#define OVERFLOW -1
#define UNDERFLOW -2

class stack {
private:
	int count;
	int size;
	int* stackArray;

public:
	stack();
	stack(int n);
	~stack();
	error_code pop();
	error_code push(int item);

};
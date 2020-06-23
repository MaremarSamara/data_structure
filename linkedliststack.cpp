#include<iostream>
using namespace std;
typedef int Error_code;
#define  SUCCESS 0
#define OVERFLOW -1
#define UNDERFLOW -2


class node{
public:
	int item;
	node* next;
	node(){
		item=0;
		next=NULL;
	}
	node(int n){
		item=n;
		next=NULL;
	}
};


class stack{
private:
	node* topnode;

public:
	stack();
	Error_code push(int item);
	Error_code pop();
	Error_code top(int &item);
	bool isEmpty();
	bool isFull(){return false;}
};

stack::stack(){
	topnode=NULL;
}

Error_code stack::push(int item){
	node *n;
	n=new node;
	n->item=item;
	n->next=topnode;
	return SUCCESS;
}
Error_code stack::top(int &item){
	Error_code outcome=SUCCESS;
	if(topnode==NULL)
		outcome=UNDERFLOW;
	else{
		item=topnode->item;
		return outcome;
	}
}
Error_code stack::pop(){
	node *p;
	Error_code outcome=SUCCESS;
	if(topnode==NULL)
		outcome=UNDERFLOW;
	else{
		p=topnode;
		topnode=topnode->next;
		delete p;
	}
	return outcome;
}

bool stack::isEmpty(){
	if(topnode==NULL)
		return true;
	else
		return false;
}


int main(){
	int n,item;
	stack st;
	st.isEmpty() ? cout<<"\n is empty \n " : cout<<"\n not empty \n";
	cout<<"Enter n"<< endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the item "<< endl;
	cin>>item;
	st.push(item);
    }

	st.isEmpty() ? cout<<"\n is empty \n " : cout<<"\n not empty \n";
	while(!st.isEmpty()){
		st.top(item);
	cout<<item;
	st.pop();
	}
	st.isEmpty() ? cout<<"\n is empty \n " : cout<<"\n not empty \n";
	return 0;
}
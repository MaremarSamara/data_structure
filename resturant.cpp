#include <iostream>
using namespace std;

typedef struct tabelnumber {
	int tnumber;
	tabelnumber * next;
} node;
//creating a node with data
node * createnode(int tnumber){
	node * t;
	t = new node;
	t->tnumber = tnumber;
	t->next = NULL;
	return t;
}
//node insertion
node * addnode(node *head, node *n){
	node *p1, *p2;
	if(head == NULL)//check for empty list
	{
		head = n;
		return head;
	}
	if(n->tnumber < head->tnumber)//check for first node
	{
		n->next = head;
		head = n;
		return head;
	}
	//general case
	p1=p2=head;
	while(p2 != NULL){
		if(n->tnumber < p2->tnumber){
			n->next = p2;
			p1->next = n;
			return head;
		}
		else
		{
			p1=p2;
			p2=p2->next;
			return head;
		}
	}

}

void printmenu(){
	cout<<"  \n M_E_N_U    \t"<<endl;
	cout<<"1. Choice Your Table Number "<<endl;
	cout<<"2. Choice Your Food"<<endl;
	cout<<"3. The Bill "<<endl;
	cout<<"\n Enter Your Choice:"<<endl;
}

void food(){
	cout<<"\n Enter Your Choice:"<<endl;
	cout << "1.pizza (5$)"<<endl;
	cout << "2.burger (7$)"<<endl;
	cout << "3.pasta (8$)"<<endl;
}
int main() {
		int tnumber ,foodnum;
	node* n;
	node *head;
	node*b;
	head = NULL;
	while(true)
	{
		printmenu();
		cin>>tnumber;
		switch(tnumber)
		{
			case 1:
				cout<<"Enter The Id For Table:";
				cin>>tnumber;
				b=head;
				if(n->tnumber==tnumber){
					cout<<"\n The Table Number Is Already Exist \t ";
					break;
				}
				n = createnode(tnumber);
				head = addnode(head, n);
				break;
			case 2:
				food();
				cout<<"Enter Your Food Number:";
				cin>>foodnum;
				break;
			case 3:
				cout<<"Enter Your Table Number :";
				cin>>tnumber;
				cout<<"Enter Your Food Number  :";
				cin>>foodnum;
				if(foodnum==1){
					cout<<"Your Bill is 5$"<<endl;
				}
				if(foodnum==2){
					cout<<"Your Bill is 7$"<<endl;

				}
				if (foodnum==3){
					cout<<"Your Bill is 8$"<<endl;
				}
				break;

			default:
				cout<<"....."<<endl;

		}
	}
	return 0;
}
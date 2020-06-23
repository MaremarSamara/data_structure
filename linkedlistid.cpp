#include <iostream>
#include <string.h>
using namespace std;

typedef struct st {
	char name[16];
	int Id;
	char address[64];
	int age;
	st * next;
} node;

node * createnode(char * name,int age,int id,char * addr){
	node * n;
	n = new node;
	n->Id = id;
	n->age = age;
	strcpy (n->name, name);
	strcpy (n->address, addr);
	n->next = NULL;
	return n;}


node * addnode(node *head, node *n){
	node *p1, *p2;

	if(head == NULL)
	{
		head = n;
		return head;
	}
	 if(n->Id < head->Id)
	{
		n->next = head;
		head = n;
		return head;
	}
	
	p1=p2=head;
	while(p2 != NULL){
		if(n->Id < p2->Id){
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


	n->next = p2;
	p1->next = n;
	return head;
}
node * deletenode (node * head, int id) {
	node *p1, *p2;
	if (head == NULL) 
		return head;

	p1 = p2 = head;
	if (head->Id == id)
	{
		head = head->next;
		delete (p2);
		return head;
	}

	

	while(p2!= NULL){
		if(p2->Id == id)
		{
			p1->next = p2->next;
			delete p2;
			return head;
		}
		else
		{
			p1 = p2;
			p2 = p2->next;
		}
	}

	return (head);
}


node * deletelist(node * head) {
	node * p;
	while (head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
	return head;
}

void printnode(node * head, int id) {
	node *p;
	p = head;
	while(p != NULL)
	{
		if(p->Id == id)
		{
			cout<<"Id \t Name \t Address \t age"<<endl;
			cout<<p->Id<<" \t";
			cout<<p->name<<" \t";
			cout<<p->address<<" \t";
			cout<<p->age<<" \t";
			return;
		}
		p=p->next;
	}
	cout<<"NODE DOES NOT EXIST"<<endl;
}

void  printlist(node * head) {
	node *p;
	p = head;
	if (head == NULL)
	{
		cout<<"empty list"<<endl;
		return;
	}
	cout<<"Id \t Name \t Address \t age"<<endl;
	cout<<"================================"<<endl;
	while(p != NULL)
	{
		cout<<p->Id<<" \t";
		cout<<p->name<<" \t";
		cout<<p->address<<" \t";
		cout<<p->age<<" \t";
		p=p->next;
	}
}

void printmenu(){

	cout<<"____**MENU**______\t"<<endl;

	cout<<"1.add anew node"<<endl;
	cout<<"2.print a node"<<endl;
	cout<<"3.print the list"<<endl;
	cout<<"4.delete a node"<<endl;
	cout<<"5.delete the list completely"<<endl;
	cout<<"6.exit"<<endl;
	cout<<"\n\n  Enter your choice:"<<endl;
}


int main()
{
	int ch, id,age;
	node* n;
	char name[32];
	char address[64];
	node *head;

	node*b;

	head = NULL;
	while(true)
	{
		printmenu();
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"enter the Id:";
				cin>>id;
				b=head;
				if(n->Id==id){
          cout<<"the ID is taken .....\t";
					break;

				}

				cout<<"enter the name:";
				cin>>name;
				cout<<"enter the address:";
				cin>>address;
				cout<<"enter the age:";
				cin>>age;
				n = createnode(name,age,id,address);
				head = addnode(head, n);
				
				break;
			case 2:
				cout<<"enter the Id to print:";
				cin>>id;
				printnode(head, id);
				break;
			case 3:
				printlist(head);
				break;
			case 4:
				cout<<"enter the Id to delete:";
				cin>>id;
				head = deletenode(head, id);
				break;
			case 5:
				head = deletelist(head);
				break;
			case 6:
				head = deletelist(head);

				break;

			default:
				cout<<"unknown choice"<<endl;

		}
	}
	return 0;
}
#include <iostream>
using namespace std;
typedef struct st {
	char name[16];
	int id;
	char address[64];
	int age;
	st* next;
}node;




node* createnode(char* name, int age, int id, char* addr) {
	node* n;
	n = new node;
	n->id = id;
	n->age = age;
	strcpy(n->name, name);
	strcpy_s(n->address, addr);
	n->next = NULL;
	return n;
}


node* addnode(node* head, node* n) {
	node* p1, * p2;
	if (head == NULL) {
		head = n;
		return head;
	}

	else if (n->id < head->id) {
		n->next = head;
		head = n;
		return head;
	}
	p1 = p2 = head;

	while (p2 != NULL) {
		if (n->id < p2->id) {
			n->next = p2;
			p1->next = n;
			return head;
		}
		else {
			p1 = p2;
			p2 = p2->next;


		}
	}
	n->next = p2;
	p1->next = n;
	return head;
}


node* deletenode(node* head, int id) {
	node* p1, * p2;
	if (head == NULL)
		return head;
	p1 = p2 = head;
	if (head->id == id) {
		head = head->next;
		delete (p2);
		return head;
	}
	while (p2 != NULL) {
		if (p2->id == id)
		{
			p1->next = p2->next;
			delete p2;
			return head;
		}
		else {
			p1 = p2;
			p2 = p2->next;

		}
	}
	return (head);
}



node* deletelist(node* head) {
	node* p;
	while (head != NULL) {
		p = head;
		head = head->next;
		delete p;
	}
	return head;
}

void printnode(node* head, int id) {
	node* p;
	p = head;
	while (p != NULL) {
		if (p->id == id) {
			cout << "Id \t Name\t address\tage" << endl;
			cout << p->id << "\t";
			cout << p->name << "\t";
			cout << p->address << "\t";
			cout << p->age << "\t";
			return;
		}
		p = p->next;
	}
	cout << "node does not exists" << endl;
}

void printlist(node* head) {
	node* p;
	p = head;
	if (head == NULL) {
		cout << "the list is empty";
		return;
	}

	cout << "Id \t Name \t Address \t age" << endl;
	cout << "==================================================" << endl;
	while (p != NULL) {
		cout << p->address << "\t";
		cout << p->age << "\t";
		cout << p->name << "\t";
		cout << p->id << endl;
		p = p->next;
	}
}


void printmenu() {
	cout << "***************************************************" << endl;
	cout << "1. add a new node " << endl;
	cout << "2. print a node " << endl;
	cout << "3. print the list " << endl;
	cout << "4. delete a node " << endl;
	cout << "5. delete the list completly " << endl;
	cout << "exit" << endl;
	cout << "\n\n entre the choice";
}




void main() {
	int ch, id, age;
	char name[32];
	char address[64];
	node* head, * n;
	head = NULL;

	while (true) {
		printmenu();
		cin >> ch;
		switch (ch) {
		case 1:
			cout << "entre the id :";
			cin >> id;
			void search(node * head, int id);
			{
				node* current = head; // Initialize current  
				while (current != NULL)
				{
					if (current->id == id)
						cout << "the id is taken..." << endl;
					return;
				}

					cout << "entre the name :  ";
					cin >> name;
					cout << "entre the address: ";
					cin >> address;
					cout << "entre the age: ";
					cin >> age;
					n = createnode(name, age, id, address);
					head = addnode(head, n);
				
			}

			break;

		case 2:
			cout << "entre the id to print: ";
			cin >> id;
			printnode(head, id);
			break;


		case 3:
			printlist(head);
			break;

		case 4:
			cout << "entre the id for delete: ";
			cin >> id;
			head = deletenode(head, id);
			break;

		case 5:
			head = deletelist(head);
			break;

		case 6:
			head = deletelist(head);
			exit(0);
			break;

		default:
			cout << "unknown choice" << endl;
		}
	}
	return;
}
#include <cstddef>
#include <iostream>
using namespace std;




typedef struct sn {
	int data;
	sn* left;
	sn* right;
}node;



node* creat_node(int data) {
	node* n;
	n = new node;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}


void add(node* root, node* n)
{
	if (n->data < root->data)
	{
		if (root->left == NULL){
			root->left = n;
		return;
	}
	add(root->left, n);
}
      else {
		if (root->right == NULL) {
			root->right = n;
			return;
		}
		add(root->right,n);
 }
}


void printin_order(node* root) {
	if (root == NULL)
		return;


	printin_order(root->left);
	cout << root->data;
	printin_order(root->right);
}

void printpre_order(node* root) {
	if (root == NULL)
		return;

	cout << root->data;
	printpre_order(root->left);
	
	printpre_order(root->right);
}

void printpost_order(node* root) {
	if (root == NULL)
		return;
	printpost_order(root->left);
	printpost_order(root->right);
	cout << root->data;
	
}
node * InsertNode(node* root, node* newNode)
{
	if (root == NULL) {
		root = newNode;
		return root;
	}
	if(newNode->data<root->data)
	{ 
		if (root->left == NULL) 
			root->left = newNode;
		else
			root->left = InsertNode(root->left, newNode);
		return root;
		}//if
	else
	{
		if (root->right == NULL)
			root->right = newNode;
		else
			root->right= InsertNode(root->right, newNode);
		return root;
	}//else
}

bool search(node* root, int id) {
	bool found = false;
	if (root == NULL)
		return false;
	if (root->data == id)
	{
		cout << "the node exists..";
		found = true;
	}
	if (!found)
		found = search(root->left, id);
	if (!found)
		found = search(root->right, id);
	return found;
}


void remove(node*& subroot) {
	node* to_delete;
	node* parent;
	if (subroot == NULL)
		return;


	to_delete = subroot;


	if (subroot->right == NULL)
		subroot = subroot->left;



	else if (subroot->left == NULL)
		subroot = subroot->right;

	else
	{
		to_delete = subroot->left;
		parent = subroot;
		while (to_delete->right != NULL)
		{
			parent = to_delete;
			to_delete = to_delete->right;
		}
		subroot->data = to_delete->data;

		if (parent == subroot)
			subroot->left = to_delete->left;
		else
			parent->right = to_delete->left;
	}
	delete to_delete;
	return;
}


bool delete_node(node* root, int data) {
	bool result = false;
	if (root == NULL)
		return false;
	if (root->left != NULL)
	{
		if (root->left->data == data) {
			remove(root->left);
			result = true;
		}
	}

	if (root->right != NULL)
	{
		if (root->right->data == data) {
			remove(root->right);
			result = true;
		}
	}

	if (!result)
		result = delete_node(root->left, data);

	if (!result)
		result = delete_node(root->right, data);
	return result;

}



int main() {
	int choice;
	int data;
	node* root;
	node* n;
	root = NULL;
	bool result = false;
	while (true) {
		cout << "____________________Main Menu_______________________" << endl;
		cout << "| 1. Add a new node                                  | " << endl;
		cout << "| 2. print Pre-order                                 | " << endl;
		cout << "| 3. print In-order                                  |" << endl;
		cout << "| 4. print Post-order                                |  " << endl;
		cout << "| 5. Find a node                                     |" << endl;
		cout << "| 6. Delete a  node                                  | " << endl;
		cout << "| 7. Exists                                          |" << endl;
		cout << "|____________________________________________________|" << endl;
		cout << "Entre the choice : ";
		cin >> choice;



		switch (choice) {
		case 1:
			cout << "Entre the data :";
			cin >> data;
			n = creat_node(data);
			root = InsertNode(root, n);
			break;


		case 2:
			printpre_order(root);
			break;

		case 3:
			printin_order(root);
			break;

		case 4:
			printpost_order(root);
			break;

		case 5:
			cout << "Entre the id: ";
			cin >> data;
			result = search(root, data);
			if (!result)
				cout << "the node was not found " << endl;
			break;

		case 6:
			cout << "Entre the id: ";
			cin >> data;
			if(root!=NULL)
				if (data == root->data)
				{
					remove(root);
					result =true;
				}
				else {
					result = delete_node(root, data);
				}
			if (!result)
				cout << "the node was not found.." << endl;
			break;

		case 7: while (root != NULL)
			remove(root);
			exit(0);

		default:
			cout << "Unknown choice " << endl;
		}//switch
	}//while
	return 0;
}
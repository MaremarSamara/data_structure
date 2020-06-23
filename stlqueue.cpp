#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n, item;
	queue <int> q;
	cout << "the queue is..." << endl;
	q.empty() ? cout << "empty" : cout << "not empty";


	cout << "entre n :...";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "entre the item # " << i + 1 << ":";
		cin >> item;
		q.push(item);
	}
	cout << "the queue is..." << endl;
	q.empty() ? cout << "empty \n\n" : cout << "not empty\n\n";
	cout << "current size= " << q.size() << endl;


	while (!q.empty())
	{
		item = q.front();
		cout << item << endl;
		q.pop();
	}
	cout << "the queue is  ";
	q.empty() ? cout << "empty" : cout << "not empty\n\n";
	return 0;

}
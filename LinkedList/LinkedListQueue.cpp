#include <iostream>

using namespace std;

class Node
{
public:
	Node(int a = 0, Node* n = 0) { data = a, node = n; }
	int data;
	Node* node;
};

int main() {
	Node* rear,*front, * a, * b, * c, * d, * e, * current;

	a = new Node(5);
	front = a;
	b = new Node(4, a);
	c = new Node(3, b);
	d = new Node(2, c);
	e = new Node(1, d);
	current = rear = e;

	cout << "print linked list queue" << endl;
	while (current) {//print
		cout << current->data << " ";
		current = current->node;
	}

	cout << endl << "push" << endl;
	Node* f = new Node(0, e);
	rear = current = f;
	cout << "print linked list queue" << endl;
	while (current) {//print
		cout << current->data << " ";
		current = current->node;
	}
	current = rear;

	cout << endl << "pop" << endl;
	while (current->node!=front)
		current = current->node;
	
	Node* del = new Node();
	del = front;
	front = current;
	front->node = 0;
	delete del;

	cout << "print linked list queue" << endl;
	current = rear;
	while (current) {//print
		cout << current->data << " ";
		current = current->node;
	}
	cout << endl;


	system("pause"); return 0;
}

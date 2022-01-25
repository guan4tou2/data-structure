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
	Node* first,*top,*a,*b,*c,*d,*e,*current;

	a = new Node(5);
	first = a;
	b = new Node(4, a);
	c = new Node(3, b);
	d = new Node(2, c);
	e = new Node(1, d);
	current=top = e;

	cout << "print linked list stack" << endl;
	while (current) {//print
		cout << current->data <<" ";
		current = current->node;
	}

	cout <<endl<< "push" << endl;
	Node* f = new Node(0, e);
	top = current = f;
	cout << "print linked list stack" << endl;
	while (current) {//print
		cout << current->data << " ";
		current = current->node;
	}


	cout << endl << "pop" << endl;
	current= top->node;//
	Node* del = new Node();
	del = top;
	top = current;

	current = top->node;//
	del = top;
	top = current;
	delete del;//

	cout << "print linked list stack" << endl;
	while (current) {//print
		cout << current->data << " ";
		current = current->node;
	}
	cout << endl;


	system("pause"); return 0;
}

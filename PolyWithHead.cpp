#include <iostream>
#include<math.h>
using namespace std;

class Node
{
public:
	Node(int n = 0,int i=0 ,Node* no = 0) { num = n,index=i, node = no; }
	int num,index;
	Node* node;
};

int main() {
	Node* tail,*head, * a, * b, * c,*d, * current;
	a = new Node(1, 2, 0);
	b = new Node(2, 3, a);
	c = new Node(3, 2, b);
	d = new Node(0, 0, c);
	a->node = d;
	head = c;
	tail = a;

	int x = 3,sum=0;
	current = head;
	cout << "poly with head" << endl;
	while (current!=tail->node) {//print
		cout <<current->num* pow(x, current->index);
		if (current != tail) cout << "+";
		sum += current->num * pow(x, current->index);
		current = current->node;
	}
	cout << "="<<sum << endl;
	system("pause"); return 0;
}

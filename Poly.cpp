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
	Node* first,*top, * a, * b, * c, * current;
	a = new Node(1, 2, 0);
	b = new Node(2, 3, a);
	c = new Node(3, 2, b);

	int x = 3,sum=0;
	current = c;
	cout << "poly" << endl;
	while (current) {//print
		cout <<current->num* pow(x, current->index);
		if (current->node != 0) cout << "+";
		sum += current->num * pow(x, current->index);
		current = current->node;
	}
	cout << "="<<sum << endl;
	system("pause"); return 0;
}

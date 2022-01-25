#include<iostream>
#include <fstream>
#include<stack>
using namespace std;

class ENode {
	friend void Equivalence();
public:
	ENode(int d = 0) { data = d; link = 0; }
	ENode(int d=0,ENode *l=0) { data = d; link = l; }
private:
	int data;
	ENode *link;
};

void Equivalence() {
	ifstream inFile("equiv.in", ios::in);
	if (!inFile)throw "cannot open";
	int i, j, n;
	inFile>> n;
	ENode **first = new ENode* [n];
	bool *out = new bool[n];
	fill(first, first + n, 0);
	fill(out, out + n, false);

	inFile >> i >> j;
	while (inFile.good()) {
		first[i] = new ENode(j, first[i]);
		first[j] = new ENode(i, first[j]);
		inFile >> i >> j;
	}

	/*stack<int> stk;
	for (i = 0; i < n; i++) {
		if (!out[i]) {
			cout << endl << "A new class" << i;
			out[i] = true;
			ENode*x = first[i];
			while (1) {
				while (x) {
					j = x->data;
					if (!out[j]) {
						cout << "," << j;
						out[j] = true;
						stk.push(x->data);
					}
					else x = x->link;
				}
				if (stk.empty())break;
				x = first[stk.top()];
				stk.pop();
			}
		}
		cout << endl;

		for (i = 0; i < n; i++) 
			while (first[i]) {
				ENode *delnode = first[i];
				first[i] = delnode->link;
				delete delnode;
			}
		delete[]first; delete[]out;
	}*/
}
int main() {
	Equivalence();
	system("pause");
	return 0;
}

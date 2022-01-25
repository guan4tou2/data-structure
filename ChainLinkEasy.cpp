#include<iostream>
using namespace std;

class ChainLink {
	friend class Chain;
public:
	ChainLink(int d = 0, ChainLink* n = 0) { data = d; link = n; }
private:
	int data;
	ChainLink* link;
};
class Chain {
public:
	Chain() {}
	ChainLink* first=0 , * last=0 ;
	void  create() {
		ChainLink* a = new ChainLink(1, 0);
		ChainLink* b = new ChainLink(2 , a);
		ChainLink* c = new ChainLink(3 , b);
		ChainLink* d = new ChainLink(4, c);
		ChainLink* e = new ChainLink(5, d);
		first = e;
		last = a;
		last->link = first;
	}
	void insertFront(const int& e) {
		ChainLink* newnode = new ChainLink(e);
		//this->print();
		if (last) {
			newnode->link = last->link;
			last->link = newnode;
		}
		else {
			last = newnode;
			newnode->link = newnode;
		}
	}
	void print() {
		ChainLink* current = first;
		while (current->link!=first) {
			cout << current->data << " ";
			current = current->link;
		}
		cout << endl;
	}
};

int main() {
	Chain a;
	a.create();
	//a.insertFront(8);
	a.print();

	system("pause"); return 0;
}

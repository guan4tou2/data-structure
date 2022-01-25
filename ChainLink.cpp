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
class Chain{
public:
	Chain(){}
	ChainLink* first=0, * last=0;
	/*void  create(int x) {
		ChainLink* a = new ChainLink(1*x, 0);
		ChainLink* b = new ChainLink(2 * x, a);
		ChainLink* c = new ChainLink(3 * x, b);
		ChainLink* d = new ChainLink(4*x, c);
		ChainLink* e = new ChainLink(5*x, d);
		first = d;
		last = a;
	}*/
	void insertBack(const int& e) {
		if (first) {
			last->link = new ChainLink(e);
			last = last->link;
		}
		else first = last = new ChainLink(e);
	}
	Chain concatenate(Chain &b) {
		if (first) { last->link = b.first; last = b.last; }
		else { first = b.first; last = b.last; }
		b.first = b.last = 0;
		return *this;
	}
	void Reverse() {
		ChainLink* current = first, * previous = 0;
		while (current) {
			ChainLink* r = previous;
			previous = current;
			current = current->link;
			previous->link = r;
		}
		first = previous;
	}
	void print() {
		ChainLink* current = first;
		while (current) {
			cout << current->data << " ";
			current = current->link;
		}
		cout << endl;
	}
};

int main() {
	Chain a,b,c;

	cout << "a insertback" << endl;
	a.insertBack(5);
	a.insertBack(4);
	a.insertBack(3);
	a.insertBack(2);
	a.insertBack(1);
	a.print();

	cout << "b insertback" << endl;
	b.insertBack(10);
	b.insertBack(9);
	b.insertBack(8);
	b.insertBack(7);
	b.insertBack(6);
	b.print();

	cout << "c concatenate" << endl;
	c = b.concatenate(a);
	c.print();

	cout << "c reverse" << endl;
	c.Reverse();
	c.print();

	system("pause"); return 0;
}

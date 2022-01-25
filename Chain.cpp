#include<iostream>
using namespace std;

class Chain;
class ChainNode {
	friend class Chain;
public:
	ChainNode(float element = 0, ChainNode* next = 0) {
		data = element; link = next;
	}
private:
	float data;
	ChainNode* link;
};

class Chain {
public:
	void create() {
		int i = 100;
		ChainNode* last = new ChainNode(i, 0);
		for (i-=1; i >0; i--) {
			last = new ChainNode(i, last);
		}
		first = last;
	}
	void print() {
		ChainNode* ptr = first;
		while (ptr) {
			float y= ptr->data ;
			cout << y << " ";
			ptr = ptr->link;
		}
		cout << endl << endl;
	}
	void append() {
		ChainNode* ptr ,*next;
		ptr = first;
		next = ptr->link;
		while (ptr) {
			if (next->data == 56) {
				ptr->link = new ChainNode(55.5,next);
				break;
			}
			else
				ptr = ptr->link;
				next = ptr->link;
		}
	}
	void Delete() {
		ChainNode* ptr, *next;
		ptr = first;
		next = ptr->link;
		while (ptr) {
			if (next->data == 61) {
				ptr->link = next->link;
				break;
			}
			else
				ptr = ptr->link;
				next = ptr->link;
		}
	}
private:
	ChainNode *first = 0;
};
int main() {
	Chain c;
	c.create();
	c.print();
	c.append();
	c.print();
	c.Delete();
	c.print();

	system("pause"); return 0;
}

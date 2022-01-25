#include<iostream>
using namespace std;
void addp(int* p) {
	int a = 10;
	p = &a;
	cout << *p << endl;
}
void addpp(int** p) {
	int a = 10;
	int *b = &a;
	*p = b;
	cout << **p << endl;
}
void addpr(int& p) {
	p = 10;
	cout << p << endl;
}
int main() {
	int a = 3;
	cout << a << endl;
	addp(&a);
	cout << a << endl << endl;

	int b = 1;
	int *c = &b;
	int **d = &c;
	cout << **d << endl;
	addpp(d);
	cout << **d << endl << endl;

	int e = 1;
	int *f = &e;
	int &g = *f;
	cout << g << endl;
	addpr(g);
	cout << g << endl;


	system("pause");
	return 0;
}

#include <iostream>
#include"TreeNode.hpp"
#include"Tree.hpp"

using namespace std;

int main() {
	char charItem[] = { 'o','h','i','t' };
	TreeNode<char>* o, * h, * i;
	Tree<char>* t;

	o = new TreeNode<char>(nullptr, charItem[0], nullptr);
	h = new TreeNode<char>(nullptr, charItem[1], o);
	i = new TreeNode<char>(nullptr, charItem[2], nullptr);
	t = new Tree<char>(h, charItem[3], i);

	cout << "\n Inorder traversal";
	t->Inorder();

	system("pause"); return 0;
}

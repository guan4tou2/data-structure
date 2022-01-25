#include<iostream>
#include"Tree.hpp"
#include<queue>
using namespace std;

template<class T>
Tree<T>::Tree() {
	root = nullptr;
}

template<class T>
Tree<T>::Tree(TreeNode<T>* left, T& item, TreeNode<T>* right) {
	root = new TreeNode<T>(left, item, right);
}

template<class T>
Tree<T>::Tree(const Tree<T>&s) {
	root = new TreeNode<T>(s.root);
}

template<class T>
void Tree<T>::Inorder() {
	Inorder(root);
}

template<class T>
void Tree<T>::Inorder(TreeNode<T>* currentNode) {
	if (currentNode) {
		Inorder(currentNode->leftChild);
		Visit(currentNode);
		Inorder(currentNode->rightChild);
	}
}

template<class T>
void Tree<T>::Preorder() {
	Preorder(root);
}

template<class T>
void Tree<T>::Preorder(TreeNode<T>* currentNode) {
	if (currentNode) {
		Visit(currentNode);
		Preorder(currentNode->leftChild);
		Preorder(currentNode->rightChild);
	}
}

template<class T>
void Tree<T>::Postorder() {
	Postorder(root);
}

template<class T>
void Tree<T>::Postorder(TreeNode<T>* currentNode) {
	if (currentNode) {
		Postorder(currentNode->leftChild);
		Postorder(currentNode->rightChild);
		Visit(currentNode);
	}
}

template<class T>
void Tree<T>::Levelorder() {
	Levelorder(root);
}

template<class T>
void Tree<T>::Levelorder(TreeNode<T>* currentNode) {
	queue<TreeNode<T>*> q;
	while (currentNode) {
		Visit(currentNode);
		if (currentNode->leftChild)
			q.push(currentNode->leftChild);
		if (currentNode->rightChild)
			q.push(currentNode->rightChild);
		if (q.empty()) return;
		currentNode = q.front();
		q.pop();
	}
}

template<class T>
void Tree<T>::Visit(TreeNode<T>* node) {
	cout << node->data << " ";
}

template<class T>
TreeNode<T>* Tree<T>::Copy(TreeNode<T>* origNode) {
	if (!origNode)return 0;
	return new TreeNode<T>(Copy(origNode->leftChild), origNode->data, Copy(origNode->rightChild));
}


template<class T>
bool Tree<T>::operator==(const Tree<T>&t) {
	return Equal(root, t.root);
}

template<class T>
bool Tree<T>::Equal(TreeNode<T>* a, TreeNode<T>* b) {
	if ((!a) && (!b))return true;
	return(a && b && (a->data == b->data) && Equal(a->leftChild, b->leftChild) && Equal(a->rightChild, b->rightChild));
}

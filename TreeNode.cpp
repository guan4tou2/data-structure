#include "TreeNode.hpp"

template<class T>
TreeNode<T>::TreeNode(TreeNode<T>* left, T& item, TreeNode<T>* right) {
	leftChild = left;
	data = item;
	rightChild = right;
}
//#pragma once

#ifndef TreeNode_hpp
#define TreeNode_hpp

template<class T>class Tree;

template<class T>class TreeNode
{
	friend class Tree<T>;
public:
	TreeNode(TreeNode<T>* left, T& item, TreeNode<T>* right);
private:
	T data;
	TreeNode<T>* leftChild;
	TreeNode<T>* rightChild;
};
#endif // TreeNode_hpp

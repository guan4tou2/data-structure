#include "TreeNode.hpp"
template <class T>
class Tree {
public:
	Tree();
	Tree(TreeNode<T>* left, T& item, TreeNode<T>* right);
	Tree(const Tree<T>& s);

	void Inorder();
	void Inorder(TreeNode<T>* curentNode);

	void Preorder();
	void Preorder(TreeNode<T>* curentNode);

	void Postorder();
	void Postorder(TreeNode<T>* curentNode);

	void Levelorder();
	void Levelorder(TreeNode<T>* curentNode);

	void NonrecInorder();

	void Visit(TreeNode<T>* node);
	TreeNode<T>* Copy(TreeNode<T>* origNode);

	bool operator==(const Tree <T>& t);
	bool Equal(TreeNode<T>* a, TreeNode<T>* b);
private:
	TreeNode<T>* root;
};
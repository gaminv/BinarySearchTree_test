#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H


#include <iostream>
#include <stack>

template <class T>
class BinarySearchTree
{
private:
	template <class T>
	struct Node {
		T key_;
		Node<T>* left_;
		Node<T>* right_;
		Node<T>* p_;

		Node(T key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) : key_(key), left_(left), right_(right), p_(p) {}
		~Node() {
			if (left_) {
				left_->~Node();
			}
			if (right_)
			{
				right_->~Node();
			}
		}
	};
	Node<T>* root_;

	void printNode(std::ostream& out, Node<T>* node) const
	{
		if (node) {
			out << node->key_;
			if (node->left_ or node->right_) {
				out << '(';
				if (node->left_) {
					printNode(out, node->left_);
				}
				out << ')';

				out << '(';
				if (node->right_) {
					printNode(out, node->right_);
				}
				out << ')';
			}
		}
	}

	size_t countLeavesRecursion(const Node<T>* node) const
	{
		size_t result;
		if ((node->left_ == nullptr) and (node->right_ == nullptr))
		{
			result = 1;
		}
		else
		{
			result = 0;
		}
		if (node->left_)
		{
			result += countLeavesRecursion(node->left_);
		}
		if (node->right_)
		{
			result += countLeavesRecursion(node->right_);
		}
		return result;
	}

	size_t countLeavesCycle(Node<T>* root) {
		if (root == nullptr) {
			return 0;
		}
		size_t result = 0;
		std::stack<Node<T>*> stack;
		stack.push(root);
		while (!stack.empty()) {
			Node<T>* node = stack.top();
			stack.pop();
			if ((node->left_ == nullptr) and (node->right_ == nullptr)) {
				result++;
			}
			if (node->right_) {
				stack.push(node->right_);
			}
			if (node->left_) {
				stack.push(node->left_);
			}
		}
		return result;
	}

public:
	BinarySearchTree() : root_(nullptr) {}
	BinarySearchTree(const BinarySearchTree<T>& scr) = delete;
	BinarySearchTree(BinarySearchTree<T>&& scr) noexcept = delete;
	BinarySearchTree <T>& operator= (const BinarySearchTree <T>& src) = delete;
	BinarySearchTree <T>& operator= (BinarySearchTree <T>&& src) noexcept = delete;

	virtual ~BinarySearchTree()
	{
		root_->~Node();
	}

	bool insert(const T& key)
	{
		Node<T>* parent = nullptr;
		Node<T>* current = this->root_;
		while (current != nullptr) {
			parent = current;
			if (key == current->key_) {
				return false;
			}
			else if (key < current->key_) {
				current = current->left_;
			}
			else {
				current = current->right_;
			}
		}
		Node<T>* newNode = new Node<T>(key);
		newNode->p_ = parent;
		if (parent == nullptr) {
			root_ = newNode;
		}
		else if (key < parent->key_) {
			parent->left_ = newNode;
		}
		else {
			parent->right_ = newNode;
		}
		return true;
	}

	void print(std::ostream& out) const
	{
		if (root_) {
			printNode(out, root_);
		}
		out << std::endl;
	}

	size_t countLeavesRecursion() {
		return countLeavesRecursion(this->root_);
	}

	size_t countLeavesCycle() {
		return countLeavesCycle(this->root_);
	}
}; 
#endif // !BINARY_SEARCH_TREE_H
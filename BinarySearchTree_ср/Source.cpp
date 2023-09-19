#include <iostream>
#include "BinarySearchTree.h"

int main() {
	std::cout << "Test 1\n";
	BinarySearchTree<int> test;
	for (int i = 0; i < 10; i++) {
		test.insert(rand() % 20);
	}
	test.print(std::cout);
	std::cout << "The number of leaves of a tree (using a recursion) " << test.countLeavesCycle() << '\n';
	std::cout << "the number of leaves of a tree (using a cycle) " << test.countLeavesRecursion() << "\n\n";

	std::cout << "Test 2\n";
	BinarySearchTree<int> test1;
	for (int i = 0; i < 15; i++) {
		test1.insert(rand() % 20);
	}
	test1.print(std::cout);
	std::cout << "The number of leaves of a tree (using a recursion) " << test1.countLeavesCycle() << '\n';
	std::cout << "the number of leaves of a tree (using a cycle) " << test1.countLeavesRecursion() << "\n\n";

	std::cout << "Test 3\n";
	BinarySearchTree<int> test2;
	for (int i = 0; i < 20; i++) {
		test2.insert(rand() % 20);
	}
	test2.print(std::cout);
	std::cout << "The number of leaves of a tree (using a recursion) " << test2.countLeavesCycle() << '\n';
	std::cout << "the number of leaves of a tree (using a cycle) " << test2.countLeavesRecursion() << "\n\n";

	test.~BinarySearchTree();
	test1.~BinarySearchTree();
	test2.~BinarySearchTree();
	return 0;
}
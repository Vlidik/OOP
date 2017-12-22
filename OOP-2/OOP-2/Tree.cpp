#include "Tree.h"
#include "TreeItem.h"
#include <cstdlib>
#include <iostream>


Tree::Tree() {
	head = nullptr;
}


TreeItem* Tree::find(int32_t a)
{
	TreeItem* item = head;
	while (item != nullptr) {
		if (item->Side() == a) {
			return item;
		}
		else if (item->Side() > a) {
			item = item->left;
		}
		else if (item->Side() < a) {
			item = item->right;
		}
	}
	return nullptr;
}


TreeItem* Tree::minValueNode(TreeItem* root)
{
	TreeItem* min = root;

	while (min->left != nullptr) {
		min = min->left;
	}

	return min;
}

TreeItem* Tree::deleteNode(TreeItem* root, int32_t a)
{
	if (root == nullptr) {
		return root;
	}

	if (a < root->Side()) {
		root->left = deleteNode(root->left, a);
	}
	else if (a > root->Side()) {
		root->right = deleteNode(root->right, a);
	}
	else {
		if (root->left == nullptr) {
			TreeItem *temp = root->right;
			root->left = nullptr;
			root->right = nullptr;
			delete root;
			return temp;
		}
		else if (root->right == nullptr) {
			TreeItem *temp = root->left;
			root->left = nullptr;
			root->right = nullptr;
			delete root;
			return temp;
		}

		TreeItem* temp = minValueNode(root->right);
		root->rhomb = temp->rhomb;
		root->right = deleteNode(root->right, temp->Side());
	}
	return root;
}


void Tree::remove(int32_t a)
{
	head = Tree::deleteNode(head, a);

}

void Tree::insert(Rhomb &&rhomb)
{
	if (head == nullptr) {
		head = new TreeItem(rhomb);
		return;
	}


	TreeItem* item = head;
	while (true) {
		if (rhomb.Side() <= item->Side()) {
			if (item->left == nullptr) {
				item->left = new TreeItem(rhomb);
				break;
			}
			else {
				item = item->left;
			}
		}
		else {
			if (item->right == nullptr) {
				item->right = new TreeItem(rhomb);
				break;
			}
			else {
				item = item->right;
			}
		}
	}
}

void Tree::print_tree(TreeItem* item, int32_t a, std::ostream& os)
{
	for (int32_t i = 0; i < a; i++) {
		os << "  ";
	}
	os << item->Side() << std::endl;
	if (item->left != nullptr) {
		Tree::print_tree(item->left, a + 1, os);
	}
	else if (item->right != nullptr) {
		for (int32_t i = 0; i <= a; i++) {
			os << "  ";
		}
		os << "null" << std::endl;
	}
	if (item->right != nullptr) {
		Tree::print_tree(item->right, a + 1, os);
	}
	else if (item->left != nullptr) {
		for (int32_t i = 0; i <= a; i++) {
			os << "  ";
		}
		os << "null" << std::endl;
	}
}



void Tree::print()
{
	if (head != nullptr) {
		Tree::print_tree(head, 0, std::cout);
	}
}

void Tree::print(std::ostream& os)
{
	if (head != nullptr) {
		Tree::print_tree(head, 0, os);
	}
}


bool Tree::empty()
{
	return head == nullptr;
}

Tree::~Tree()
{
	delete head;
}


std::ostream& operator<<(std::ostream& os, Tree& tree) {
	tree.print(os);
	return os;
}
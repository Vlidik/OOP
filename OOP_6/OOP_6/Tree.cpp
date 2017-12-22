#include "Tree.h"
#include <cstdlib>
#include <iostream>

template <class T>
Tree<T>::Tree()
{
	head = nullptr;
}
template <class T>
std::shared_ptr<TreeItem<T>> Tree<T>::minValueNode(std::shared_ptr<TreeItem<T>> root)
{
	std::shared_ptr<TreeItem<T>> min = root;

	while (min->left != nullptr) {
		min = min->left;
	}

	return min;
}

template <class T>
std::shared_ptr<TreeItem<T>> Tree<T>::find(std::shared_ptr<T> &obj)
{
	std::shared_ptr<TreeItem<T>> item = head;
	while (item != nullptr) {
		if (item->item->Side() == obj->Side()) {
			return item;
		}
		else if (item->item->Side() > obj->Side()) {
			item = item->left;
		}
		else if (item->item->Side() < obj->Side()) {
			item = item->right;
		}
	}
	return nullptr;
}

template <class T>
std::shared_ptr<TreeItem<T>> Tree<T>::deleteNode(std::shared_ptr<TreeItem<T>> root, int32_t side)
{
	if (root == nullptr) {
		return root;
	}

	if (side < root->item->Side()) {
		root->left = deleteNode(root->left, side);
	}
	else if (side > root->item->Side()) {
		root->right = deleteNode(root->right, side);
	}
	else {
		if (root->left == nullptr) {
			std::shared_ptr<TreeItem<T>> temp = root->right;
			root->left = nullptr;
			root->right = nullptr;
			return temp;
		}
		else if (root->right == nullptr) {
			std::shared_ptr<TreeItem<T>> temp = root->left;
			root->left = nullptr;
			root->right = nullptr;
			return temp;
		}

		std::shared_ptr<TreeItem<T>> temp = minValueNode(root->right);
		root->item = temp->item;
		root->right = deleteNode(root->right, temp->item->Side());
	}
	return root;
}

template <class T>
void Tree<T>::remove(int32_t side)
{
	head = Tree<T>::deleteNode(head, side);

}

template <class T>
void Tree<T>::insert(std::shared_ptr<T> &obj)
{
	if (head == nullptr) {
		head = std::make_shared<TreeItem<T>>(obj);
		return;
	}


	std::shared_ptr<TreeItem<T>> item = head;
	while (true) {
		if (obj->Side() <= item->item->Side()) {
			if (item->left == nullptr) {
				item->left = std::make_shared<TreeItem<T>>(obj);
				break;
			}
			else {
				item = item->left;
			}
		}
		else {
			if (item->right == nullptr) {
				item->right = std::make_shared<TreeItem<T>>(obj);
				break;
			}
			else {
				item = item->right;
			}
		}
	}
}

template <class T>
void Tree<T>::print_tree(std::shared_ptr<TreeItem<T>> item, int32_t a, std::ostream& os)
{
	for (int32_t i = 0; i < a; i++) {
		os << "  ";
	}
	item->GetFigure()->Print();
	if (item->left != nullptr) {
		Tree<T>::print_tree(item->left, a + 1, os);
	}
	else if (item->right != nullptr) {
		for (int32_t i = 0; i <= a; i++) {
			os << "  ";
		}
		os << "null" << std::endl;
	}
	if (item->right != nullptr) {
		Tree<T>::print_tree(item->right, a + 1, os);
	}
	else if (item->left != nullptr) {
		for (int32_t i = 0; i <= a; i++) {
			os << "  ";
		}
		os << "null" << std::endl;
	}
}

template <class T>
void Tree<T>::print()
{
	if (head != nullptr) {
		Tree<T>::print_tree(head, 0, std::cout);
	}
}

template <class T>
void Tree<T>::print(std::ostream& os)
{
	if (head != nullptr) {
		Tree<T>::print_tree(head, 0, os);
	}
}

template <class T>
bool Tree<T>::empty()
{
	return head == nullptr;
}

template <class T>
TIterator<TreeItem<T>, T> Tree<T>::begin()
{
	return TIterator<TreeItem<T>, T>(head);
}

template <class T>
TIterator<TreeItem<T>, T> Tree<T>::end()
{
	return TIterator<TreeItem<T>, T>(nullptr);
}

template <class T>
Tree<T>::~Tree()
{
}

template <class T>
std::ostream& operator<<(std::ostream& os, Tree<T>& tree) {
	tree.print(os);
	return os;
}


#include "Figure.h"
template class Tree<Figure>;
template std::ostream& operator<<(std::ostream& os, Tree<Figure> &tree);

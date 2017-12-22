#include "Tree.h"

template <class T>
Tree<T>::Tree()
{
	head = nullptr;
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
std::shared_ptr<TreeItem<T>> Tree<T>::minValueNode(std::shared_ptr<TreeItem<T>> root)
{
	std::shared_ptr<TreeItem<T>> min = root;

	while (min->left != nullptr) {
		min = min->left;
	}

	return min;
}

template <class T>
std::shared_ptr<TreeItem<T>> Tree<T>::Successor(std::shared_ptr<TreeItem<T>> node)
{
	if (!node->right) {
		return minValueNode(node->right);
	}
	std::shared_ptr<TreeItem<T>> parent = node->parent;
	while (parent && node == parent->right) {
		node = parent;
		parent = parent->parent;
	}
	return parent;
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
		if (root->left == nullptr && root->right == nullptr) {
			std::shared_ptr<TreeItem<T>> temp = nullptr;
			root->parent = nullptr;
			return temp;
		}
		else if (root->left == nullptr) {
			std::shared_ptr<TreeItem<T>> temp = nullptr;
			temp = std::make_shared<TreeItem<T>>(root->right->item, nullptr, nullptr, root->parent);
			temp->left = root->right->left;
			temp->right = root->right->right;
			root->left = nullptr;
			root->right = nullptr;
			root->parent = nullptr;
			return temp;
		}
		else if (root->right == nullptr) {
			std::shared_ptr<TreeItem<T>> temp = nullptr;
			temp = std::make_shared<TreeItem<T>>(root->left->item, nullptr, nullptr, root->parent);
			temp->left = root->left->left;
			temp->right = root->left->right;
			root->left = nullptr;
			root->right = nullptr;
			root->parent = nullptr;
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
		std::shared_ptr<TreeItem<T>> tmp = nullptr;
		head = std::make_shared<TreeItem<T>>(obj, nullptr, nullptr, tmp);
		return;
	}


	std::shared_ptr<TreeItem<T>> item = head;
	std::shared_ptr<TreeItem<T>> parent = head;
	while (true) {
		if (obj->Side() <= item->item->Side()) {
			if (item->left == nullptr) {
				item->left = std::make_shared<TreeItem<T>>(obj, nullptr, nullptr, parent);
				break;
			}
			else {
				parent = item->left;
				item = item->left;
			}
		}
		else {
			if (item->right == nullptr) {
				item->right = std::make_shared<TreeItem<T>>(obj, nullptr, nullptr, parent);
				break;
			}
			else {
				parent = item->right;
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
Tree<T>::~Tree()
{
}

template <class T>
std::ostream& operator<<(std::ostream& os, Tree<T> &tree)
{
	tree.print(os);
	return os;
}

template <class T>
Iterator<TreeItem<T>, T> Tree<T>::begin()
{
	if (!head || !head->left) {
		return Iterator<TreeItem<T>, T>(head);
	}

	std::shared_ptr<TreeItem<T>> tmp = head;
	while (tmp->left) {
		tmp = tmp->left;
	}
	return Iterator<TreeItem<T>, T>(tmp);
}

template <class T>
Iterator<TreeItem<T>, T> Tree<T>::end()
{
	return Iterator<TreeItem<T>, T>(nullptr);
}

template <class T>
void Tree<T>::rm(std::shared_ptr<TreeItem<T>> node)
{
	if (!node) {
		return;
	}
	node->parent = nullptr;
	if (node->left) {
		rm(node->left);
	}
	if (node->right) {
		rm(node->right);
	}
}


template <class T>
void Tree<T>::gg()
{
	if (!head) {
		return;
	}
	if (head->left) {
		rm(head->left);
	}
	if (head->right) {
		rm(head->right);
	}
}

#include "figure.h"
template class Tree<Figure>;
template std::ostream& operator<<(std::ostream& os, Tree<Figure> &tree);
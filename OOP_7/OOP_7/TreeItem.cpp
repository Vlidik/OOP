#include "TreeItem.h"

template <class T>
TreeItem<T>::TreeItem()
{
	item = nullptr;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}

template <class T>
TreeItem<T>::TreeItem(const std::shared_ptr<T> obj, std::shared_ptr<TreeItem<T>> l, std::shared_ptr<TreeItem<T>> r, std::shared_ptr<TreeItem<T>> p)
{
	item = obj;
	left = l;
	right = r;
	parent = p;
}

template <class T>
TreeItem<T>::~TreeItem()
{
}

template <class T>
std::shared_ptr<T> TreeItem<T>::GetFigure()
{
	return this->item;
}

template <class T>
std::shared_ptr<TreeItem<T>> TreeItem<T>::GetNext()
{
	if (this->right) {
		std::shared_ptr<TreeItem<T>> temp = this->right;
		while (temp->left) {
			temp = temp->left;
		}
		return temp;
	}

	std::shared_ptr<TreeItem<T>> succ = nullptr;
	std::shared_ptr<TreeItem<T>> n = std::make_shared<TreeItem<T>>(*this);
	std::shared_ptr<TreeItem<T>> root = std::make_shared<TreeItem<T>>(*this);
	while (root->parent) {
		root = root->parent;
	}


	while (root) {
		if (n->item->Side() < root->item->Side()) {
			succ = root;
			root = root->left;
		}
		else if (n->item->Side() > root->item->Side()) {
			root = root->right;
		}
		else {
			break;
		}
	}
	return succ;
}

#include "figure.h"
template class TreeItem<Figure>;
//template std::ostream& operator<<(std::ostream &out, TreeItem<Figure> &obj);
#ifndef TITERATOR_H
#define TITERATOR_H
#include <memory>
#include <iostream>
template <class node, class T>
class TIterator
{
public:
	TIterator(std::shared_ptr<node> n) {

		node_ptr = n;
	}
	std::shared_ptr<T> operator * () {
		return node_ptr->GetFigure();
	}
	std::shared_ptr<T> operator -> () {
		return node_ptr->GetFigure();
	}
	void operator ++ () {
		node_ptr = Next(node_ptr);
	}

	std::shared_ptr<node> Next(std::shared_ptr<node> _cur)
	{
		if (_cur->right != NULL)
		{
			_cur = _cur->right;

			while (_cur->left != NULL)
				_cur = _cur->left;
		}
		else
		{
			std::shared_ptr<TreeItem<T>> succ = NULL;
			std::shared_ptr<TreeItem<T>> root = node_ptr;

			while (root != NULL)
			{
				if (_cur->item < root->item)
				{
					succ = root;
					root = root->left;
				}
				else if (root->item < _cur->item)
					root = root->right;
				else
					break;
			}

			_cur = succ;
		}

		return _cur;
	}

	TIterator operator ++ (int) {
		TIterator iter(*this);
		++(*this);
		return iter;
	}
	bool operator == (TIterator const& i) {
		return node_ptr == i.node_ptr;
	}
	bool operator != (TIterator const& i) {
		return !(*this == i);
	}
private:
	std::shared_ptr<node> node_ptr;
};
#endif
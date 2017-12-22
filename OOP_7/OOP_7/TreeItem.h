#ifndef TBINARYTREEITEM
#define TBINARYTREEITEM

#include <cstdlib>
#include <iostream>
#include <memory>
#include "hexagon.h"
#include "pentagon.h"
#include "rhomb.h"

template <class T> class Tree;

template <class T> class TreeItem
{
public:
	TreeItem();
	TreeItem(const std::shared_ptr<T> obj, std::shared_ptr<TreeItem<T>> l, std::shared_ptr<TreeItem<T>> r, std::shared_ptr<TreeItem<T>> p);
	std::shared_ptr<T> GetFigure();
	~TreeItem();
	std::shared_ptr<TreeItem<T>> GetNext();
	friend class Tree<T>;
private:
	std::shared_ptr<T> item;
	std::shared_ptr<TreeItem<T>> left;
	std::shared_ptr<TreeItem<T>> right;
	std::shared_ptr<TreeItem<T>> parent;
};

#endif
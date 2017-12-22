#ifndef TREEITEM
#define TREEITEM

#include <cstdlib>
#include <iostream>
#include <memory>
#include "Hexagon.h"
#include "Pentagon.h"
#include "Rhomb.h"


template <class T> class Tree;

template <class T> class TreeItem
{
public:
	TreeItem();
	TreeItem(const std::shared_ptr<T> &obj);

	std::shared_ptr<T> GetFigure();
	~TreeItem();
	friend class Tree<T>;

	std::shared_ptr<T> item;
	std::shared_ptr<TreeItem<T>> left;
	std::shared_ptr<TreeItem<T>> right;

};

#endif

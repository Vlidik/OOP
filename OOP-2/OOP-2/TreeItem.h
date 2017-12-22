#ifndef TREEITEM
#define TREEITEM

#include "Rhomb.h"

class Tree;

class TreeItem
{
public:
	TreeItem();
	TreeItem(Rhomb& rhomb);

	int32_t Side();
	Rhomb GetRhomb();
	~TreeItem();
	friend Tree;
private:
	Rhomb rhomb;
	TreeItem* left;
	TreeItem* right;
};

#endif
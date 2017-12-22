#include "TreeItem.h"


TreeItem::TreeItem()
{
	left = nullptr;
	right = nullptr;
}
TreeItem::TreeItem(Rhomb& rhomb)
{
	this->rhomb = rhomb;
	left = nullptr;
	right = nullptr;
}


int32_t TreeItem::Side()
{
	return rhomb.Side();
}

TreeItem::~TreeItem()
{
	delete left;
	delete right;
}

Rhomb TreeItem::GetRhomb() {
	return rhomb;
}
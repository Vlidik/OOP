#include "TreeItem.h"

template <class T>
TreeItem<T>::TreeItem()
{
	left = nullptr;
	right = nullptr;
}

template <class T>
TreeItem<T>::TreeItem(const std::shared_ptr<T> &obj)
{
	this->item = obj;
	left = nullptr;
	right = nullptr;
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



#include "Figure.h"
template class TreeItem<Figure>;
//template std::ostream& operator<<(std::ostream &out, TBinaryTreeItem<Figure> &obj);

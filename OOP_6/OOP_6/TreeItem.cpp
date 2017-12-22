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

template <class T> TAllocationBlock
TreeItem<T>::treeitem_allocator(sizeof(TreeItem<T>), 100);


template <class T>
TreeItem<T>::~TreeItem()
{
}

template <class T>
std::shared_ptr<T> TreeItem<T>::GetFigure()
{
	return this->item;
}

template <class T> void * TreeItem<T>::operator new (size_t size) {
	return treeitem_allocator.allocate();
}

template <class T> void TreeItem<T>::operator delete(void *p) {
	treeitem_allocator.deallocate(p);
}

#include "Figure.h"
template class TreeItem<Figure>;
//template std::ostream& operator<<(std::ostream &out, TBinaryTreeItem<Figure> &obj);

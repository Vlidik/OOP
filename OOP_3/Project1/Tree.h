#ifndef TREE
#define TREE

#include "TreeItem.h"

template <class T> class Tree
{
public:
	Tree();
	std::shared_ptr<TreeItem<T>> find(std::shared_ptr<T> &obj);
	void remove(int32_t side);
	void insert(std::shared_ptr<T> &obj);
	void print();
	void print(std::ostream& os);
	template <class A> friend std::ostream& operator<<(std::ostream& os, Tree<A> &tree);
	bool empty();
	virtual ~Tree();
private:
	std::shared_ptr<TreeItem<T>> head;
	std::shared_ptr<TreeItem<T>> minValueNode(std::shared_ptr<TreeItem<T>> root);
	std::shared_ptr<TreeItem<T>> deleteNode(std::shared_ptr<TreeItem<T>> root, int32_t side);
	void print_tree(std::shared_ptr<TreeItem<T>> item, int32_t a, std::ostream& os);
};

#endif
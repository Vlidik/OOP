#ifndef TBINARYTREE_H
#define TBINARYTREE_H

#include <cstdlib>
#include <iostream>
#include "TreeItem.h"
#include "Iterator.h"
#include <future>
#include <thread>
#include <mutex>
#include <functional>

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

	void gg();
	Iterator<TreeItem<T>, T> begin();
	Iterator<TreeItem<T>, T> end();

	virtual ~Tree();
private:
	std::shared_ptr<TreeItem<T>> head;
	void  rm(std::shared_ptr<TreeItem<T>> node);
	std::shared_ptr<TreeItem<T>> Successor(std::shared_ptr<TreeItem<T>> node);
	std::shared_ptr<TreeItem<T>> minValueNode(std::shared_ptr<TreeItem<T>> root);
	std::shared_ptr<TreeItem<T>> deleteNode(std::shared_ptr<TreeItem<T>> root, int32_t side);
	void print_tree(std::shared_ptr<TreeItem<T>> item, int32_t a, std::ostream& os);
};

#endif
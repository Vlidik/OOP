#ifndef TREE
#define TREE

#include "TreeItem.h"

class Tree
{
public:
	friend std::ostream& operator<<(std::ostream& os, Tree& tree);
	Tree();
	TreeItem* find(int32_t a);
	void remove(int32_t a);
	void insert(Rhomb &&rhomb);
	void print();
	void print(std::ostream& os);
	bool empty();
	virtual ~Tree();

private:
	TreeItem* head;
	TreeItem* minValueNode(TreeItem* root);
	TreeItem* deleteNode(TreeItem* root, int32_t a);
	void print_tree(TreeItem* item, int32_t a, std::ostream& os);
};

#endif
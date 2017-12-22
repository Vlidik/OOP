#include <iostream>
#include <cstdlib>
#include <cstring>
#include <memory>

#include "Tree.h"
#include "figure.h"
#include "hexagon.h"
#include "pentagon.h"
#include "rhomb.h"
#include "TTree.h"

void menu()
{
	std::cout << "Oparations:" << std::endl;
	std::cout << "1) Insert rhomb" << std::endl;
	std::cout << "2) Insert pentagon" << std::endl;
	std::cout << "3) Insert hexagon" << std::endl;
	std::cout << "4) Delete of type 1)rhomb 2)pentagon 3)hexagon" << std::endl;
	std::cout << "5) Delete side" << std::endl;
	std::cout << "6) Print" << std::endl;
	std::cout << "0) Exit" << std::endl;
}

int main(void)
{
	int act = 0, index;
	TTree<Tree<Figure>, std::shared_ptr<Figure>> tree;
	std::shared_ptr<Figure> ptr;
	std::cout << "Press 7 for success" << std::endl;
	do {
		std::cin >> act;
		switch (act) {
		case 1:
			ptr = std::make_shared<Rhomb>(std::cin);
			tree.insert(ptr);
			break;
		case 2:
			ptr = std::make_shared<Pentagon>(std::cin);
			tree.insert(ptr);
			break;
		case 3:
			ptr = std::make_shared<Hexagon>(std::cin);
			tree.insert(ptr);
			break;
		case 4:
			std::cin >> index;
			tree.removeByType(index);
			break;
		case 5:
			int32_t numb;
			std::cin >> numb;
			tree.removeLesser(numb);
			break;
		case 6:
			tree.inorder();
			break;
		case 7:
			menu();
			break;
		case 0:
			tree.RM();
			break;
		default:
			std::cout << "Error" << std::endl;;
			break;
		}
	} while (act);
	return 0;
}
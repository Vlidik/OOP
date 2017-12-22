#include <iostream>
#include <cstdlib>
#include <cstring>
#include <memory>

#include "Rhomb.h"
#include "Hexagon.h"
#include "Pentagon.h"
#include "Tree.h"

int main()
{
	std::cout << "List of operations:" << std::endl;
	std::cout << "1) Insert rhomb" << std::endl;
	std::cout << "2) Insert hexagon" << std::endl;
	std::cout << "3) Insert pentagon" << std::endl;
	std::cout << "4) Remove figure" << std::endl;
	std::cout << "5) Print" << std::endl;
	std::cout << "0) Exit" << std::endl;

	int action;
	Tree<Figure> tree;
	std::shared_ptr<Figure> ptr;
	do
	{
		std::cin >> action;
		switch (action) {
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
			if (tree.empty())
			{
				std::cout << "Empty" << std::endl;
			}
			else
			{
				int32_t item;
				std::cin >> item;
				tree.remove(item);
			}
			break;
		case 5:
			if (tree.empty())
			{
				std::cout << "Empty" << std::endl;
			}
			else
			{
				std::cout << tree << std::endl;
			}
			break;
		case 0:
			break;


		}
	} while (action);

	return 0;

}
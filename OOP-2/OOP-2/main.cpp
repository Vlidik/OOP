#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Rhomb.h"
#include "Tree.h"

const int size = 10;

int main(int argc, char** argv)
{
	Tree *tree = new Tree();
	char s[size];

	while (1)
	{
		std::cin.getline(s, size);
		std::cin.clear();
		std::cin.sync();
		if (!strcmp(s, "in"))
		{
			int32_t side;
			int32_t hight;
			if (!(std::cin >> side >> hight))
			{
				std::cout << "wrong value" << std::endl;
				continue;
			}
			tree->insert(Rhomb(side, hight));
		}
		else if (!strcmp(s, "rem"))
		{
			int32_t side;
			if (!(std::cin >> side))
			{
				std::cout << "wrong value" << std::endl;
				continue;
			}
			tree->remove(side);
		}
		else if (!strcmp(s, "find"))
		{
			if (tree->empty())
			{
				std::cout << "Tree is empty" << std::endl;
				continue;
			}
			int32_t side;
				if (!(std::cin >> side))
				{
					std::cout << "wrong value" << std::endl;
					continue;
				}
				TreeItem* t = tree->find(side);
				if (t != nullptr)
				{
					t->GetRhomb().Print();
				}
				else
				{
					std::cout << "Rhomb not found" << std::endl;
				}
		}
		else if (!strcmp(s, "destroy"))
		{
			delete tree;
			tree = new Tree();
			std::cout << "Destroied" << std::endl;
		}
		else if (!strcmp(s, "p"))
		{
			if (!tree->empty())
			{
				std::cout << *tree << std::endl;
			}
			else std::cout << "Empty" << std::endl;

		}
		else if (!strcmp(s, "quit"))
		{
			delete tree;
			break;
		}

		
	}
	return 0;
}
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <memory>

#include "figure.h"
#include "Hexagon.h"
#include "Pentagon.h"
#include "Rhomb.h"
#include "Tree.h"

int ParSort(std::shared_ptr<Figure> *&arr, int l, int r)
{
	int x = l + (r - l) / 2;
	int i = l;
	int j = r;

	while (i <= j) {
		while (arr[i]->Side() < arr[x]->Side()) {
			i++;
		}
		while (arr[j]->Side() > arr[x]->Side()) {
			j--;
		}
		if (i <= j) {
			std::shared_ptr<Figure> tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	if (i < r) {
		std::packaged_task<int(std::shared_ptr<Figure> *&, int, int)> task(ParSort);
		auto result = task.get_future();

		std::thread task_td(std::move(task), std::ref(arr), i, r);
		task_td.join();
		result.get();
	}
	if (l < j) {
		std::packaged_task<int(std::shared_ptr<Figure> *&, int, int)> task(ParSort);
		auto result = task.get_future();

		std::thread task_td(std::move(task), std::ref(arr), l, j);
		task_td.join();
		result.get();
	}
	return 0;
}

void menu()
{
	std::cout << "Operations:" << std::endl;
	std::cout << "1) Add rhomb(2 sides)" << std::endl;
	std::cout << "2) Add pentagon" << std::endl;
	std::cout << "3) Add hexagon" << std::endl;
	std::cout << "4) Delete max side" << std::endl;
	std::cout << "5) Print" << std::endl;
	std::cout << "6) Print wirh iterator" << std::endl;
	std::cout << "7) ParSort of tree" << std::endl;
	std::cout << "8) Parallel sort of tree" << std::endl;
	std::cout << "0) Exit" << std::endl;
}

int main(void)
{
	int act = 0;
	Tree<Figure> tree;
	std::shared_ptr<Figure> ptr;
	std::shared_ptr<Figure> *arr;
	arr = new std::shared_ptr<Figure>[20];
	int n;
	std::cout << "Print 9" << std::endl;
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

			if (tree.empty()) {
				std::cout << "Empty" << std::endl;
			}
			else {
				int32_t numb;
				std::cin >> numb;
				tree.remove(numb);
			}
			break;
		case 5:
			if (tree.empty()) {
				std::cout << "Empty" << std::endl;
			}
			else {
				std::cout << tree << std::endl;
			}
			break;
		case 6:
			if (tree.empty()) {
				std::cout << "Empty" << std::endl;
			}
			else {
				for (auto i : tree) {
					i->Print();
				}
				std::cout << std::endl;
			}
			break;
		case 7:
			tree.Clear();
			std::cout << "Enter number of sides" << std::endl;
			std::cin >> n;
			for (int i = 0; i < n; ++i) {
				std::cout << "Left " << n - i << " sides" << std::endl;
				ptr = std::make_shared<Hexagon>(std::cin);
				arr[i] = ptr;
			}
			tree.Sort(arr, 0, n - 1);
			tree.Balanced(arr, 0, n - 1);
			break;
		case 8:
			tree.Clear();
			std::cout << "Enter number of sides" << std::endl;
			std::cin >> n;
			for (int i = 0; i < n; ++i) {
				std::cout << "Left " << n - i << " sides" << std::endl;
				ptr = std::make_shared<Hexagon>(std::cin);
				arr[i] = ptr;
			}
			ParSort(arr, 0, n - 1);
			tree.Balanced(arr, 0, n - 1);
			break;
		case 9:
			menu();
			break;
		case 0:
			tree.gg();
			break;
		default:
			std::cout << "Error" << std::endl;;
			break;
		}
	} while (act);
	delete[] arr;
	return 0;
}
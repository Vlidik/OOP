#include <cstdlib>
#include "Pentagon.h"
#include "Rhomb.h"
#include "Hexagon.h"


int main(int argc, char** argv)
{
	int num;
	while (true)
	{
		std::cout << "Menu: " << std::endl;
		std::cout << "1) Rhomb" << std::endl;
		std::cout << "2) Pentagon" << std::endl;
		std::cout << "3) Hexagon" << std::endl;
		std::cout << "4) Exit" << std::endl;

		std::cin >> num;
		std::cin.ignore();

		if (num == 4)
			break;

		switch (num)
		{
		case 1:
		{
			Figure *ptr = new Rhomb(std::cin);
			ptr->Print();
			std::cout << "Square = " << ptr->Square() << std::endl;

			delete ptr;

			break;
		}

		case 2:
		{
			Figure *ptr = new Pentagon(std::cin);
			ptr->Print();
			std::cout << "Square = " << ptr->Square() << std::endl;

			delete ptr;

			break;
		}

		case 3:
		{
			Figure *ptr = new Hexagon(std::cin);
			ptr->Print();
			std::cout << "Square = " << ptr->Square() << std::endl;

			delete ptr;

			break;
		}
		}
	}
	return 0;
}
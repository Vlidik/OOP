#include <iostream>
#include <cmath>

#include "Rhomb.h"

Rhomb::Rhomb() : Rhomb(0, 0)
{

}

Rhomb::Rhomb(size_t i, size_t j) : side(i), hight(j)
{
	std::cout << "Rhomb created: " << side << " " << hight << std::endl;
}

Rhomb::Rhomb(std::istream &is)
{
	is >> side;
	is >> hight;
}

Rhomb::Rhomb(const Rhomb& orig)
{
	side = orig.side;
	hight = orig.hight;
}

int32_t Rhomb::Side()
{
	return side;
}

double Rhomb::Square()
{
	return side * hight;
}

void Rhomb::Print()
{
	std::cout << side << std::endl;
	std::cout << hight << std::endl;
	std::cout << side*hight << std::endl;
}

Rhomb::~Rhomb()
{
}

Rhomb& Rhomb::operator=(const Rhomb& right)
{
	if (this == &right) {
		return *this;
	}

	std::cout << "Rhomb copied" << std::endl;

	side = right.side;
	hight = right.hight;

	return *this;
}

Rhomb& Rhomb::operator++()
{
	side++;
	hight++;
	return *this;
}

Rhomb operator+(const Rhomb& left, const Rhomb& right)
{
	return Rhomb(left.side + right.side, left.hight + right.hight);
}


std::ostream& operator<<(std::ostream& os, const Rhomb& obj) {
	os << "Side = " << obj.side << std::endl;
	os << "Hight = " << obj.hight << std::endl;
	return os;
}

std::istream& operator >> (std::istream& is, Rhomb& obj)
{
	is >> obj.side;
	is >> obj.hight;
	return is;
}

bool operator==(const Rhomb& left, const Rhomb& right) {
	return left.side == right.side,
		left.hight == right.hight;
}

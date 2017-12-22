#include <iostream>
#include <cmath>
#include "pentagon.h"

Pentagon::Pentagon() : Pentagon(0)
{
}

Pentagon::Pentagon(int32_t i) : side(i)
{
	std::cout << "Pentagon created: " << side << std::endl;
}

Pentagon::Pentagon(std::istream &is)
{
	is >> side;
}

Pentagon::Pentagon(const Pentagon& orig)
{
	std::cout << "Pentagon copy created" << std::endl;
	side = orig.side;
}

double Pentagon::Square()
{
	return (2.0 * double(side) * double(side)) * (1.0 + sqrt(2.0));
}

void Pentagon::Print()
{
	std::cout << "Side = " << side << std::endl;
}

Pentagon::~Pentagon()
{
	//std::cout << "Pentagon deleted" << std::endl;
}

int32_t Pentagon::Side()
{
	return side;
}

Pentagon& Pentagon::operator=(const Pentagon& right)
{
	if (this == &right) {
		return *this;
	}

	side = right.side;

	return *this;
}

Pentagon& Pentagon::operator++()
{
	side++;
	return *this;
}

Pentagon operator+(const Pentagon& left, const Pentagon& right)
{
	return Pentagon(left.side + right.side);
}


std::ostream& operator<<(std::ostream& os, const Pentagon& obj)
{
	os << "Side = " << obj.side << std::endl;
	return os;
}

std::istream& operator >> (std::istream& is, Pentagon& obj)
{
	is >> obj.side;
	return is;
}

bool operator==(const Pentagon& left, const Pentagon& right)
{
	return left.side == right.side;
}

bool operator>(const Pentagon& left, const Pentagon& right)
{
	return left.side > right.side;
}

bool operator<(const Pentagon& left, const Pentagon& right)
{
	return left.side < right.side;
}
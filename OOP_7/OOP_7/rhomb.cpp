#include <iostream>
#include <cmath>
#include "rhomb.h"

Rhomb::Rhomb() : Rhomb(0)
{
}

Rhomb::Rhomb(int32_t i) : side(i)
{
	std::cout << "Rhomb created: " << side << std::endl;
}

Rhomb::Rhomb(std::istream &is)
{
	is >> side;
}

Rhomb::Rhomb(const Rhomb& orig)
{
	std::cout << "Rhomb copy created" << std::endl;
	side = orig.side;
}

double Rhomb::Square()
{
	return (2.0 * double(side) * double(side)) * (1.0 + sqrt(2.0));
}

void Rhomb::Print()
{
	std::cout << "Side = " << side << std::endl;
}

Rhomb::~Rhomb()
{
	//std::cout << "Rhomb deleted" << std::endl;
}

int32_t Rhomb::Side()
{
	return side;
}

Rhomb& Rhomb::operator=(const Rhomb& right)
{
	if (this == &right) {
		return *this;
	}

	side = right.side;

	return *this;
}

Rhomb& Rhomb::operator++()
{
	side++;
	return *this;
}

Rhomb operator+(const Rhomb& left, const Rhomb& right)
{
	return Rhomb(left.side + right.side);
}


std::ostream& operator<<(std::ostream& os, const Rhomb& obj)
{
	os << "Side = " << obj.side << std::endl;
	return os;
}

std::istream& operator >> (std::istream& is, Rhomb& obj)
{
	is >> obj.side;
	return is;
}

bool operator==(const Rhomb& left, const Rhomb& right)
{
	return left.side == right.side;
}

bool operator>(const Rhomb& left, const Rhomb& right)
{
	return left.side > right.side;
}

bool operator<(const Rhomb& left, const Rhomb& right)
{
	return left.side < right.side;
}
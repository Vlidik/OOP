#include "Pentagon.h"
#include <iostream>
#include <cmath>

Pentagon::Pentagon() : Pentagon(0, 0) {

}

Pentagon::Pentagon(size_t i, size_t r) : side(i), rad(r) {
	std::cout << side << std::endl;
	std::cout << rad << std::endl;


}

Pentagon::Pentagon(std::istream &is) {
	is >> side;
	is >> rad;
	if (!is) {
		std::cout << "Error" << std::endl;
		side = 0;
		rad = 0;
		is.clear();
		is.ignore();
	}
}

Pentagon::Pentagon(const Pentagon& orig) {
	std::cout << "Pentagon copy created" << std::endl;
	side = orig.side;
	rad = orig.rad;
}

double Pentagon::Square() {
	return (double(side * 5) / 2.0) * double(rad);

}

void Pentagon::Print() {
	std::cout << side << std::endl;
	std::cout << rad << std::endl;
	std::cout << side * rad << std::endl;
}

Pentagon::~Pentagon() {
	std::cout << "Pentagon deleted" << std::endl;

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

	std::cout << "Pentagon copied" << std::endl;

	side = right.side;
	rad = right.rad;

	return *this;
}

Pentagon& Pentagon::operator++()
{
	side++;
	rad++;
	return *this;
}

Pentagon operator+(const Pentagon& left, const Pentagon& right)
{
	return Pentagon(left.side + right.side, left.rad + right.rad);
}


std::ostream& operator<<(std::ostream& os, const Pentagon& obj) {
	os << "Side = " << obj.side << std::endl;
	os << "Hight = " << obj.rad << std::endl;
	return os;
}

std::istream& operator >> (std::istream& is, Pentagon& obj)
{
	is >> obj.side;
	is >> obj.rad;
	return is;
}

bool operator==(const Pentagon& left, const Pentagon& right) {
	return left.side == right.side,
		left.rad == right.rad;
}

#include "Hexagon.h"
#include <iostream>
#include <cmath>

Hexagon::Hexagon() : Hexagon(0, 0) {

}

Hexagon::Hexagon(size_t i, size_t r) : side(i), rad(r) {
	std::cout << side << std::endl;
	std::cout << rad << std::endl;


}

Hexagon::Hexagon(std::istream &is) {
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

Hexagon::Hexagon(const Hexagon& orig) {
	std::cout << "Hexagon copy created" << std::endl;
	side = orig.side;
	rad = orig.rad;
}

double Hexagon::Square() {
	return (double(side * 6) / 2.0) * double(rad);

}

void Hexagon::Print() {
	std::cout << side << std::endl;

}

Hexagon::~Hexagon() {
	std::cout << "Hexagon deleted" << std::endl;

}

int32_t Hexagon::Side()
{
	return side;
}

Hexagon& Hexagon::operator=(const Hexagon& right)
{
	if (this == &right) {
		return *this;
	}

	std::cout << "Hexagon copied" << std::endl;

	side = right.side;
	rad = right.rad;

	return *this;
}

Hexagon& Hexagon::operator++()
{
	side++;
	rad++;
	return *this;
}

Hexagon operator+(const Hexagon& left, const Hexagon& right)
{
	return Hexagon(left.side + right.side, left.rad + right.rad);
}


std::ostream& operator<<(std::ostream& os, const Hexagon& obj) {
	os << "Side = " << obj.side << std::endl;
	os << "Hight = " << obj.rad << std::endl;
	return os;
}

std::istream& operator >> (std::istream& is, Hexagon& obj)
{
	is >> obj.side;
	is >> obj.rad;
	return is;
}

bool operator==(const Hexagon& left, const Hexagon& right) {
	return left.side == right.side,
		left.rad == right.rad;
}
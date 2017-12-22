#ifndef Hexagon_H
#define Hexagon_H

#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Hexagon : public Figure {
public:
	Hexagon();
	Hexagon(std::istream &is);
	Hexagon(size_t i, size_t j);
	Hexagon(const Hexagon& orig);

	Hexagon& operator++();
	friend bool operator==(const Hexagon& left, const Hexagon& right);
	friend Hexagon operator+(const Hexagon& left, const Hexagon& right);
	friend std::ostream& operator<<(std::ostream& os, const Hexagon& obj);
	friend std::istream& operator >> (std::istream& is, Hexagon& obj);

	double Square() override;
	void Print() override;
	virtual ~Hexagon();
	int32_t Side();
	Hexagon& operator=(const Hexagon& right);

private:
	size_t side;
	size_t rad;
};

#endif
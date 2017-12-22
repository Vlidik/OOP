#pragma once
#ifndef Pentagon_H
#define Pentagon_H

#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Pentagon : public Figure {
public:
	Pentagon();
	Pentagon(std::istream &is);
	Pentagon(size_t i, size_t j, size_t k, size_t l, size_t m, size_t n);
	Pentagon(const Pentagon& orig);

	double Square() override;
	void Print() override;
	virtual ~Pentagon();

private:
	size_t side1;
	size_t side2;
	size_t side3;
	size_t side4;
	size_t side5;
	size_t rad;
};

#endif
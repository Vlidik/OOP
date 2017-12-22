#ifndef RHOMB_H
#define RHOMB_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Rhomb : public Figure
{
public:
	Rhomb();
	Rhomb(size_t i, size_t j);
	Rhomb(const Rhomb& orig);
	Rhomb& operator++();
	friend bool operator==(const Rhomb& left, const Rhomb& right);
	friend Rhomb operator+(const Rhomb& left, const Rhomb& right);
	friend std::ostream& operator<<(std::ostream& os, const Rhomb& obj);
	friend std::istream& operator >> (std::istream& is, Rhomb& obj);

	Rhomb(std::istream &is);
	double Square() override;
	int32_t Side();
	void Print() override;
	Rhomb& operator=(const Rhomb& right);
	virtual ~Rhomb();
private:
	size_t side;
	size_t hight;
};

#endif /* RHOMB_H */
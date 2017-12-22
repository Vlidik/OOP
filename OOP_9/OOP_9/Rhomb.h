#ifndef RHOMB_H
#define RHOMB_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Rhomb : public Figure {
public:
	Rhomb();
	Rhomb(std::istream &is);
	Rhomb(size_t i, size_t j);
	Rhomb(const Rhomb& orig);

	Rhomb& operator++();
	Rhomb& operator=(const Rhomb& right);

	friend Rhomb operator+(const Rhomb& left, const Rhomb& right);
	friend std::ostream& operator<<(std::ostream& os, const Rhomb& obj);
	friend std::istream& operator >> (std::istream& is, Rhomb& obj);
	friend bool operator>(const Rhomb& left, const Rhomb& right);
	friend bool operator<(const Rhomb& left, const Rhomb& right);
	friend bool operator==(const Rhomb& left, const Rhomb& right);

	int32_t Side() override;
	double Square() override;
	void Print() override;
	virtual ~Rhomb();
	int type() { return 1; }
private:
	size_t side;
	size_t hight;
};

#endif /* RHOMB_H */
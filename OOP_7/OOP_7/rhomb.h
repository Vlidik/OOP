#ifndef RHOMB_H
#define RHOMB_H
#include <cstdlib>
#include <iostream>
#include "figure.h"

class Rhomb : public Figure {
public:
	Rhomb();
	Rhomb(std::istream &is);
	Rhomb(int32_t i);
	Rhomb(const Rhomb& orig);

	Rhomb& operator=(const Rhomb& right);
	Rhomb& operator++();

	friend Rhomb operator+(const Rhomb& left, const Rhomb& right);
	friend std::ostream& operator<<(std::ostream& os, const Rhomb& obj);
	friend std::istream& operator >> (std::istream& is, Rhomb& obj);
	friend bool operator==(const Rhomb& left, const Rhomb& right);
	friend bool operator>(const Rhomb& left, const Rhomb& right);
	friend bool operator<(const Rhomb& left, const Rhomb& right);

	int32_t Side() override;
	double Square() override;
	void Print() override;

	virtual ~Rhomb();
	int type() { return 1; }
private:
	int32_t side;
};

#endif /* RHOMB_H */
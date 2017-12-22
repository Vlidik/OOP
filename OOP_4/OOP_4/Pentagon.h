#ifndef Pentagon_H
#define Pentagon_H

#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Pentagon : public Figure {
public:
	Pentagon();
	Pentagon(std::istream &is);
	Pentagon(size_t i, size_t j);
	Pentagon(const Pentagon& orig);

	Pentagon& operator++();
	friend bool operator==(const Pentagon& left, const Pentagon& right);
	friend Pentagon operator+(const Pentagon& left, const Pentagon& right);
	friend std::ostream& operator<<(std::ostream& os, const Pentagon& obj);
	friend std::istream& operator >> (std::istream& is, Pentagon& obj);

	double Square() override;
	void Print() override;
	virtual ~Pentagon();
	int32_t Side();
	Pentagon& operator=(const Pentagon& right);

private:
	size_t side;
	size_t rad;
};

#endif

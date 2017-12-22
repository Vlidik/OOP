#ifndef PENTAGON_H
#define PENTAGON_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Pentagon : public Figure {
public:
	Pentagon();
	Pentagon(std::istream &is);
	Pentagon(int32_t i);
	Pentagon(const Pentagon& orig);

	Pentagon& operator=(const Pentagon& right);
	Pentagon& operator++();

	friend Pentagon operator+(const Pentagon& left, const Pentagon& right);
	friend std::ostream& operator<<(std::ostream& os, const Pentagon& obj);
	friend std::istream& operator >> (std::istream& is, Pentagon& obj);
	friend bool operator==(const Pentagon& left, const Pentagon& right);
	friend bool operator>(const Pentagon& left, const Pentagon& right);
	friend bool operator<(const Pentagon& left, const Pentagon& right);

	int32_t Side() override;
	double Square() override;
	void Print() override;

	virtual ~Pentagon();
	int type() { return 2; }
private:
	int32_t side;
};

#endif /* PENTAGON_H */
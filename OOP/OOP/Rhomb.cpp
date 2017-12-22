#include "Rhomb.h"
#include <iostream>
#include <cmath>

Rhomb::Rhomb() : Rhomb(0, 0) {

}

Rhomb::Rhomb(size_t i, size_t j) : a(i), h(j) {
	std::cout << "Rhomb created" << std::endl;
	std::cout << "side = " << a << std::endl;
	std::cout << "height = " << h << std::endl;
}

Rhomb::Rhomb(std::istream &is) {
	is >> a;
	is >> h;
	if (!is) {
		std::cout << "Error" << std::endl;
		a = 0;
		h = 0;
		is.clear();
		is.ignore();
	}
}

Rhomb::Rhomb(const Rhomb& orig) {
	std::cout << "Rhomb copy created" << std::endl;
	a = orig.a;
	h = orig.h;
}

double Rhomb::Square() {
	return double(a) * double(h);
}

void Rhomb::Print() {
	
	std::cout << "side: " << a << std::endl;
	std::cout << "height: " << h << std::endl;

}


Rhomb::~Rhomb() {
	std::cout << "Rhomb deleted" << std::endl;
}

#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>
#include <iostream>

template <class N, class T>
class Iterator
{
public:
	Iterator(std::shared_ptr<N> n) {
		cur = n;
	}

	std::shared_ptr<T> operator * () {
		return cur->GetFigure();
	}

	std::shared_ptr<T> operator -> () {
		return cur->GetFigure();
	}

	void operator++() {
		cur = cur->GetNext();
	}

	Iterator operator++ (int) {
		Iterator cur(*this);
		++(*this);
		return cur;
	}

	bool operator== (const Iterator &i) {
		return (cur == i.cur);
	}

	bool operator!= (const Iterator &i) {
		return !(cur == i.cur);
	}

private:
	std::shared_ptr<N> cur;
};

#endif
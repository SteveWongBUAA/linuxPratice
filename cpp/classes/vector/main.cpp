#include "vect.h"
#include <iostream>


int main()
{
	VECTOR::Vector foo(3.0, 4.0);
	std::cout << foo << std::endl;
	VECTOR::Vector bar(3.0, 4.0, VECTOR::Vector::Mode(0));
	std::cout << bar << std::endl;
	VECTOR::Vector foo1(3.0, 4.0, VECTOR::Vector::Mode(1));
	std::cout << foo1 << std::endl;
	VECTOR::Vector bar1(3.0, 4.0, VECTOR::Vector::POL);
	std::cout << bar1 << std::endl;
	return 0;
}

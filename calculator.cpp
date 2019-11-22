#include <iostream>
#include "factor.hpp"

int main() {
	Factory* factory = new Factory();
	std::string st = "2+2*3/4-2";
	std::cout << "--Test (" << st << ") with size 9\n";
	Base* expression = factory->parse(st,9);
	if (expression!=NULL) std::cout << expression->stringify() << " = " << expression->evaluate() << std::endl;

	st = "2+2*3/4-2+2";
	std::cout << "--Test (" << st << ") with size 9\n";
	expression = factory->parse(st, 9);
	if (expression != NULL) std::cout << expression->stringify() << " = " << expression->evaluate() << std::endl;

	st = "2+2*3//-2";
	std::cout << "--Test (" << st << ") with size 9\n";
	expression = factory->parse(st, 9);
	if (expression != NULL) std::cout << expression->stringify() << " = " << expression->evaluate() << std::endl;

	st = "++2*3/4-2";
	std::cout << "--Test (" << st << ") with size 9\n";
	expression = factory->parse(st, 9);
	if (expression != NULL) std::cout << expression->stringify() << " = " << expression->evaluate() << std::endl;

	st = "2+2*3/4-+";
	std::cout << "--Test (" << st << ") with size 9\n";
	expression = factory->parse(st, 9);
	if (expression != NULL) std::cout << expression->stringify() << " = " << expression->evaluate() << std::endl;
}

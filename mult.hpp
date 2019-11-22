#ifndef __MULT_HPP__
#define __MULT_HPP__
#include "base.hpp"

class Mult :public Base {
private:
	Base* left;
	Base* right;
	Base* parent;
public:
	Mult() {
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	Mult(Base*, Base*);
	double evaluate() {
		return left->evaluate() * right->evaluate();
	}
	std::string stringify() {
		return left->stringify() + "*" + right->stringify();
	}	
	void setleft(Base*);
	void setright(Base*);
	void setfather(Base*);
};
Mult::Mult(Base* pointer1, Base* pointer2) {
	left = pointer1;
	right = pointer2;
	parent = nullptr;
}
void Mult::setleft(Base* pointer) {
	left = pointer;
}
void Mult::setright(Base* pointer) {
	right = pointer;
}
void Mult::setfather(Base* pointer) {
	parent = pointer;
}
#endif


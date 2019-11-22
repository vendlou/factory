#ifndef __DIV_HPP__
#define __DIV_HPP__
#include "base.hpp"

class Div :public Base {
private:
	Base* left;
	Base* right;
	Base* parent;
public:
	Div() {
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	Div(Base*, Base*);
	double evaluate() {
		return left->evaluate() / right->evaluate();
	}
	std::string stringify() {
		return left->stringify() + "/" + right->stringify();
	}
	void setleft(Base*);
	void setright(Base*);
	void setfather(Base*);
};
Div::Div(Base* pointer1, Base* pointer2) {
	left = pointer1;
	right = pointer2;
	parent = nullptr;
}
void Div::setleft(Base* pointer) {
	left = pointer;
}
void Div::setright(Base* pointer) {
	right = pointer;
}
void Div::setfather(Base* pointer) {
	parent = pointer;
}
#endif


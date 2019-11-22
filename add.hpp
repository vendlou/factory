#ifndef __ADD_HPP__
#define __ADD_HPP__
#include "base.hpp"

class Add :public Base {
private:
	Base* left;
	Base* right;
	Base* parent;
public:
	Add() {
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	Add(Base*, Base*);
	double evaluate() {
		return left->evaluate() + right->evaluate();
	}
	std::string stringify() {
		return left->stringify() + "+" + right->stringify();
	}
	void setleft(Base*);
	void setright(Base*);
	void setfather(Base*);
};
Add::Add(Base* pointer1, Base* pointer2) {
	left = pointer1;
	right = pointer2;
	parent = nullptr;
}
void Add::setleft(Base* pointer) {
	left = pointer;
}
void Add::setright(Base* pointer) {
	right = pointer;
}
void Add::setfather(Base* pointer) {
	parent = pointer;
}
#endif


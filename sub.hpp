#ifndef __SUB_HPP__
#define __SUB_HPP__
#include "base.hpp"

class Sub :public Base {
private:
	Base* left;
	Base* right;
	Base* parent;
public:
	Sub() {
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	Sub(Base*, Base*);
	double evaluate() {
		return left->evaluate() - right->evaluate();
	}
	std::string stringify() {
		return left->stringify() + "-" + right->stringify();
	}
	void setleft(Base*);
	void setright(Base*);
	void setfather(Base*);
}; 
Sub::Sub(Base* pointer1, Base* pointer2) {
	left = pointer1;
	right = pointer2;
	parent = nullptr;
}
void Sub::setleft(Base* pointer) {
	left = pointer;
}
void Sub::setright(Base* pointer) {
	right = pointer;
}
void Sub::setfather(Base* pointer) {
	parent = pointer;
}
#endif


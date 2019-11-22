#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
private:
	double operands;
public:
	Op() {};
	Op(double value) {
		operands = value;
	}
	double evaluate() { return operands; }
	std::string stringify() { return std::to_string(operands); }
	void setleft(Base*) {}
	void setright(Base*) {}
};

#endif //__OP_HPP__


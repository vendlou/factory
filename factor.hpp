#ifndef __FACTOR_HPP__
#define __FACTOR_HPP__

#include <stdlib.h>
#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "op.hpp"


class Factory {
public:
	Factory() {}
	Factory(std::string, int);
	Base* parse(std::string, int);
};
Factory::Factory(std::string input, int length) {
	parse(input, length);
}
Base* Factory::parse(std::string input, int length) {
	if (input.size() != length) {
		std::cout << "Size Error!\n";
		return NULL;
	}
	Base* left = NULL;
	Base* root = NULL;
	Base* right = NULL;
	int index = 0;
	std::string st = "";
	while (input[index] != '+' && input[index] != '-' && input[index] != '*' && input[index] != '/') {
		st += input[index];
		index++;
	}
	if (st == "") {
		std::cout << "Format Error!\n";
		return NULL;
	}
	left = new Op(stod(st));
	st = "";
	switch ((char)input[index]) {
	case '+':
		root = new Add();
		break;
	case '-':
		root = new Sub();
		break;
	case '*':
		root = new Mult();
		break;
	case '/':
		root = new Div();
		break;
	}
	index++;
	root->setleft(left);
	while (index < length) {
		if ((input[index] == '+' || input[index] == '-' || input[index] == '*' || input[index] == '/') && st == "") {
			std::cout << "Format Error!\n";
			return NULL;
		}
		switch (input[index]) {
		case '+':
			right = new Op(stod(st));
			root->setright(right);
			left = root;
			root = new Add();
			root->setleft(left);
			st = "";
			break;
		case '-':
			right = new Op(stod(st));
			root->setright(right);
			left = root;
			root = new Sub();
			root->setleft(left);
			st = "";
			break;
		case '*':
			right = new Op(stod(st));
			root->setright(right);
			left = root;
			root = new Mult();
			root->setleft(left);
			st = "";
			break;
		case '/':
			right = new Op(stod(st));
			root->setright(right);
			left = root;
			root = new Div();
			root->setleft(left);
			st = "";
			break;
		default:
			st += input[index];
		}
		index++;
	}
	if (st == "") {
		std::cout << "Format Error!\n";
		return NULL;
	}
	right = new Op(stod(st));
	root->setright(right);
	return root;
}
#endif

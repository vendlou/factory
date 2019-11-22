#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>
#include <stdio.h>
class Base {
    public:
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
		virtual void setleft(Base*) = 0;
		virtual void setright(Base*) = 0;
};

#endif //__BASE_HPP__


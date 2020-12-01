#ifndef ____OPERATOR_H__
#define ____OPERATOR_H__

#include "base.hpp"
#include <string>
class Operate : public Base{
	protected:
		Base* left;
		Base* right;
	public:
		Operate(Base* left, Base* right) : left(left), right(right) {};

		virtual double evaluate() =0;
                virtual std::string stringify() {return "";}
};
#endif //Operator_H


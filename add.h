#ifndef __Add_H__
#define __Add_H__

#include "Operator.h"
#include "op.hpp"
class Add: public Operate {

	public:
		Add(Base* left,Base* right): Operate(left,right) {};

		double evaluate() {
			return left->evaluate() + right->evaluate();
		}
		std::string stringify(){
			return "(" + left->stringify() +")" + "+"+ "(" + right->stringify() + ")";
		}
};
#endif //__Add_H__  

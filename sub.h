#ifndef __SUB_H__
#define __SUB_H__

#include "Operator.h"
class Sub: public Operate {

	public:
		Sub(Base* left,Base* right): Operate(left,right) {};

		double evaluate(){
			return left->evaluate() - right->evaluate();
		}
		std::string stringify(){
			return "(" + left->stringify() +")" + "-"+ "(" + right->stringify() + ")";
		}
};
#endif //__SUB_H__  

#ifndef __DIV_H__
#define __DIV_H__

#include "Operator.h"
#include "op.hpp"
class Div: public Operate {

	public:
		Div(Base* left,Base* right): Operate(left,right) {};

		double evaluate() {
			if(right->evaluate()== 0){
				std::cout<<"Trying to divide by 0"<<std::endl;
			}
			else{
				return left->evaluate() / right->evaluate();
			}
		}
		std::string stringify(){
			return "(" + left->stringify() +")" + "/"+ "(" + right->stringify() + ")";
		}
};
#endif //__Div_H__  


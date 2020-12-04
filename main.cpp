#include <iostream>
#include "base.hpp"
#include "div.h"
#include "pow.h"
#include "add.h"
#include "op.hpp"
#include "sub.h"
#include "rand.h"
#include "mult.h"
#include "factory.h"

int main(int argc, char * argv[]){
	std::cout<<"Length: "<<argc<<endl;
	Factory* factory = new Factory();
	Base* conversion = factory->parse(argv,argc);
	if(factory->check_valid_main(argv,argc) == false){
		std::cout<<"Auto Quiting program return 0"<<endl;
		return 0;
	}
	std::cout<<"Results: "<<conversion->evaluate()<<endl;
	std::cout<<"Stringify: "<<conversion->stringify()<<endl;
	   
}

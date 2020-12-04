#ifndef FACTORY_H
#define FACTORY_H
#include <iostream>
#include <sstream>
#include "base.hpp"
#include "add.h"
#include "sub.h"
#include "mult.h"
#include "div.h"
#include "pow.h"
#include "op.hpp"
#include <string>
using namespace std;

class Factory{
public:
    Factory(){};
    Base* find_operator(char* input[],int &current,Base* &left, Base* &right){
        Base* results;
        int i = current;
        double tnum =0;
        switch(*input[i]){
            case '+':
                i++;
                tnum = stod(input[i]);
                right = new Op(tnum);
                results = new Add(left,right);
            break;
            case '-':
                i++;
                tnum = stod(input[i]);
                right = new Op(tnum);
                results = new Sub(left,right);
            break;
            case '*':
                i++;
                tnum = stod(input[i]);
                right = new Op(tnum);
                results = new Mult(left,right);
            break;
            case '/':
                i++;
                tnum = stod(input[i]);
                right = new Op(tnum);
                results = new Div(left,right);
            break;
           case '^':
               i++;
               tnum = stod(input[i]);
               right = new Op(tnum);
               results = new Pow(left,right);
           break;

        default:
            results = nullptr;
            break;

        }
        current = i;
        return results;

    };
    Base* parse(char* input[], int length){
        if(check_valid_main(input,length) == false){
            cout<<"Invalid input returning NULL"<<endl;
            return nullptr;
        }
        int i=0;
        string stringtemp;
        double tnum = 0;
        Base* hold_left;
        Base* hold_right;
        Base* results;
        while(i<length){
            if(isdigit(*input[i])){
                tnum = stod(input[i]);
                hold_left = new Op(tnum);
            }
            else if(*input[i]== '+' || *input[i] == '-' || *input[i] == '/' || *input[i] == '*' ||*input[i]=='^'){
                results =find_operator(input,i,hold_left,hold_right);
                hold_left = results;
            }
            i++;
        }
        return results;
    };
    bool check_valid(char* input[], int length){
        int change = 0;
        int op_change = 0;
        int i=1;
	if(!isdigit(*input[0])){return false;};
        while(i<length){

	    //if(!isdigit(*input[1])) { return false;}
            if(isdigit(*input[i] != 1)){
                return false;
            }
            if(isdigit(*input[i]) && i%2 != 0){
                change++;
            }
            else if ((*input[i]== '+' || *input[i] == '-' || *input[i] == '/' || *input[i] == '*' ||*input[i]=='^') && i% 2== 0){
                op_change++;
            }
            else if(isdigit(*input[i]) && isdigit(*input[i+1])){
                return false;
            }
            else if(isdigit(*input[i]) == 0 && isdigit(*input[i+1]) == 0){
                return false;
            }
            i++;
        }
        if(op_change > change){
            return false;
        }

        return true;

    };
    bool check_valid_main(char* input[], int length){
        int change = 0;
        int op_change = 0;
        int i=1;
	if(length == 2){
		return false;
	}
        while(i<length){
		if(isdigit(*input[i]!= 1)){
			return false;
		}
		if(isdigit(*input[i]) && i%2 != 0){
			change++;
		}
		else if((*input[i]== '+' || *input[i] == '-' || *input[i] == '/' || *input[i] == '*' ||*input[i]=='^') && i% 2== 0){
			op_change++;
		}
		else if(isdigit(*input[i])==1 && isdigit(*input[i+1])==1){
			return false;
		}	
		else if(isdigit(*input[i]) == 0 && isdigit(*input[i+1]) == 0){
			return false;
		}
		i++;
	}
	if(op_change > change){
		return false;
	}
	return true;
	
     };
};
#endif //_FACTORY_H_

#ifndef RAND
#define RAND



#include <string>
#include <stdlib.h>

using namespace std;


class Rand : public Base
{
        private:
                Op* value;
        public:
                Rand()
                {
                        value = new Op(rand() % 100);
                }
                double evaluate()
                {
                        return value->evaluate();
                }
                string stringify()
                {
                        string result = to_string(value->evaluate());
                        return result;

                }


};

#endif

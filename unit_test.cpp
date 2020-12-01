#include "gtest/gtest.h"
#include <iostream>
#include "base.hpp"
#include "div.h"
#include "pow.h"
#include "add.h"
#include "op.hpp"
#include "sub.h"
#include "mult.h"
#include "factory.h"
TEST(FactoryTest, BasicAddition){
	char* test_val [3];
	test_val[0] = "8";
	test_val[1] = "+";
	test_val[2] = "2";
	Factory* factory = new Factory();
	Base* conversion = factory->parse(test_val,3);
	EXPECT_EQ(conversion->evaluate(),10);

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

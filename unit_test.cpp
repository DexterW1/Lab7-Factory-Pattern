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
        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "8.000000 + 2.000000");
	EXPECT_EQ(conversion->evaluate(),10);

}
TEST(FactoryTest, BasicSubtraction){
        char* test_val [3];
        test_val[0] = "4";
        test_val[1] = "-";
        test_val[2] = "2";
        Factory* factory = new Factory();
        Base* conversion = factory->parse(test_val,3);
	ASSERT_NE(conversion, nullptr);
	EXPECT_EQ(conversion->stringify(), "4.000000 - 2.000000");
        EXPECT_EQ(conversion->evaluate(),2);

}
TEST(FactoryTest, BasicMultiplication){
        char* test_val [3];
        test_val[0] = "9";
        test_val[1] = "*";
        test_val[2] = "2";
        Factory* factory = new Factory();
        Base* conversion = factory->parse(test_val,3);
        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "9.000000 * 2.000000");
        EXPECT_EQ(conversion->evaluate(),18);

}
TEST(FactoryTest, BasicDivision){
        char* test_val [3];
        test_val[0] = "10";
        test_val[1] = "/";
        test_val[2] = "5";
        Factory* factory = new Factory();
        Base* conversion = factory->parse(test_val,3);
        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "10.000000 / 5.000000");
        EXPECT_EQ(conversion->evaluate(),2);

}
TEST(FactoryTest, BasicPower){
        char* test_val [3];
        test_val[0] = "8";
        test_val[1] = "^";
        test_val[2] = "2";
        Factory* factory = new Factory();
        Base* conversion = factory->parse(test_val,3);
        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "8.000000 ^ 2.000000");
        EXPECT_EQ(conversion->evaluate(),64);

}
TEST(FactoryTest, LongExpressionPt1){
	//also need to check for invalid i think
	//need to check for at least 5 long expression so like test val so be around 12 for each
        char* test_val [12];
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

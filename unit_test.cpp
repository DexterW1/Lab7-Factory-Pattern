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
        char* test_val [7];
        test_val[0] = "8";
        test_val[1] = "+";
        test_val[2] = "2";
	test_val[3] = "/";
	test_val[4] = "5";
	test_val[5] = "^";
	test_val[6] = "3";
        Factory* factory = new Factory();
        Base* conversion = factory->parse(test_val,7);
	ASSERT_NE(conversion, nullptr);
	EXPECT_EQ(conversion->stringify(),"8.000000 + 2.000000 / 5.000000 ^ 3.000000");
        EXPECT_EQ(conversion->evaluate(),8);

}
TEST(FactoryTest, LongExpressionPt2){
        char* test_val [9];
	test_val[0] = "100";
	test_val[1] = "-";
	test_val[2] = "50";
	test_val[3] = "/";
	test_val[4] = "25";
	test_val[5] = "*";
	test_val[6] = "5";
	test_val[7] = "^";
	test_val[8] = "2";
        Factory* factory = new Factory();
        Base* conversion = factory->parse(test_val,9);
	EXPECT_EQ(conversion->stringify(),"100.000000 - 50.000000 / 25.000000 * 5.000000 ^ 2.000000");
        EXPECT_EQ(conversion->evaluate(),100);

}

TEST(FactoryTest, LongExpressionPt3){

        char* test_val [10];
        test_val[0] = "4";
        test_val[1] = "+";
        test_val[2] = "4";
        test_val[3] = "-";
        test_val[4] = "4";
	test_val[5] = "*";
	test_val[6] = "4";
	test_val[7] = "^";
	test_val[8] = "1";
	test_val[9] = "/";
	test_val[10] = "4";
        Factory* factory = new Factory();
        Base* conversion = factory->parse(test_val,10);
	EXPECT_EQ(conversion->stringify(),"4.000000 + 4.000000 - 4.000000 * 4.000000 ^ 1.000000 / 4.000000");
        EXPECT_EQ(conversion->evaluate(),4);

}

TEST(FactoryTest, LongExpressionPt4){
        char* test_val [11];
        test_val[0] = "2";
        test_val[1] = "*";
        test_val[2] = "0";
        test_val[3] = "+";
        test_val[4] = "3";
        Factory* factory = new Factory();
        Base* conversion = factory->parse(test_val,5);
	EXPECT_EQ(conversion->stringify(),"2.000000 * 0.000000 + 3.000000");
        EXPECT_EQ(conversion->evaluate(), 3);
}
TEST(FactoryTest, LongExpressionPt5){
        char* test_val [10];
        test_val[0] = "5";
        test_val[1] = "+";
        test_val[2] = "5";
        test_val[3] = "+";
        test_val[4] = "5";
        test_val[5] = "+";
        test_val[6] = "5";
        Factory* factory = new Factory();
        Base* conversion = factory->parse(test_val,7);
	EXPECT_EQ(conversion->stringify(),"5.000000 + 5.000000 + 5.000000 + 5.000000");
        EXPECT_EQ(conversion->evaluate(), 20);
}

TEST(FactoryTest, validity1){
    char* test_val[1];
    test_val[0] = "-";

    Factory* factory = new Factory();
    bool check = factory->check_valid(test_val,1);
    EXPECT_EQ(check, false);
  
}



TEST(FactoryTest, validity2){
    char* test_val[1];
    test_val[0] = "1";

    Factory* factory = new Factory();
    bool check = factory->check_valid(test_val,1);
    EXPECT_EQ(check, true);

}


TEST(FactoryTest, incorrectTest){
    char* test_val[1];
    test_val[0] = "-";

    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val,1);
    EXPECT_TRUE(conversion == nullptr);
  
}

TEST(FactoryTest, incorrectTest2){
    char* test_val[4];
    test_val[0] = "1";
    test_val[1] = "3";
    test_val[2] = "5";
    test_val[3] = "1";

    Factory* factory = new Factory();
    Base* conversion = factory->parse(test_val,4);
    EXPECT_TRUE(conversion == nullptr);
  
}


TEST(FactoryTest, validity3){
    char* test_val[4];
    test_val[0] = "1";
    test_val[1] = "3";
    test_val[2] = "5";
    test_val[3] = "1";

    Factory* factory = new Factory();
    bool check = factory->check_valid(test_val,4);
    EXPECT_EQ(check, false);
  
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#include "factor.hpp"

TEST(ErrorTest,SizeTest){
 	Factory* factory = new Factory();
	std::string st = "2+2*3/4-2";
	Base* expression = factory->parse(st,8);
	EXPECT_TRUE(expression==NULL);
}
 
TEST(ErrorTest,FormatTest){
	Factory* factory = new Factory();
	std::string st = "2+2*3/4-2+";
	Base* expression = factory->parse(st,10);
	EXPECT_TRUE(expression==NULL);	
}

TEST(CaculatorTest,EvaluateTest){
	Factory* factory = new Factory();
	std::string st = "2+2*3/4-2";
	Base* expression = factory->parse(st,9);
	EXPECT_EQ(expression->evaluate(),1);	
}

TEST(CaculatorTest,StringfyTest){
	Factory* factory = new Factory();
	std::string st = "2+2*3/4-2";
	Base* expression = factory->parse(st,9);
	EXPECT_EQ(expression->stringify(),"2.000000+2.000000*3.000000/4.000000-2.000000");	
}

#include "pch.h"
#include "../sem5/moveable.h"


TEST(MoveableTest, Construction) {
	auto s = new moveable(1, 0, 1.5, 2.5, 0);
	std::cout << s->x;
	EXPECT_EQ(1, 1);
	//EXPECT_TRUE(true);
}
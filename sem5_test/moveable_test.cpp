#include "pch.h"
#include "../sem5/moveable.h"
#include "../sem5/moveable.cpp"


TEST(MoveableTest, Construction) {
	moveable * s = new moveable(1, 0, 1.5, 2.5, 0.1);
	
	EXPECT_EQ(s->N, 1);
	EXPECT_EQ(s->N_prev, 0);
	EXPECT_EQ(s->Alpha, 0.1);
	EXPECT_EQ(s->x, 1.5);
	EXPECT_EQ(s->y, 2.5);
}

TEST(MoveableTest, Construction2) {
	moveable* s = new moveable(2, 1, 1, 2.5, 0.1);

	EXPECT_EQ(s->N, 2);
	EXPECT_EQ(s->N_prev, 1);
	EXPECT_EQ(s->Alpha, 0.1);
	EXPECT_EQ(s->x, 1);
	EXPECT_EQ(s->y, 2.5);
}
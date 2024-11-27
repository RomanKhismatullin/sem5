#include "pch.h"
#include "../sem5/Grip.h"
#include "../sem5/Grip.cpp"

TEST(GripTest, DefaultConstructor) {
	Grip* s = new Grip(0, 1);
	EXPECT_EQ(s->NPrev(), 0);
	EXPECT_EQ(s->N(), 1);
	EXPECT_EQ(s->X(), 0);
	EXPECT_EQ(s->Y(), 0);
	EXPECT_EQ(s->Alpha(), 0);
	EXPECT_EQ(s->AlphaOpening(), 0);
}


TEST(GripTest, testSetAlphaOpening) {
	Grip* s = new Grip(0, 1);
	s->SetOpeningAlpha(3);
	EXPECT_EQ(s->AlphaOpening(), 3);
}


TEST(GripTest, Constructor) {
	Grip* s = new Grip(0, 1, 2, 3, 4, 5);


	EXPECT_EQ(s->NPrev(), 0);
	EXPECT_EQ(s->N(), 1);
	EXPECT_EQ(s->X(), 2);
	EXPECT_EQ(s->Y(), 3);
	EXPECT_EQ(s->Alpha(), 4);

	EXPECT_EQ(s->AlphaOpening(), 5);
}

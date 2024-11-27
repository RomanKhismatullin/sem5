#include "pch.h"
#include "../sem5/Grip.h"
#include "../sem5/Grip.cpp"

TEST(GripTest, DefaultConstructor) {
	Grip* s = new Grip(0, 1);
	EXPECT_EQ(s->N_prev(), 0);
	EXPECT_EQ(s->N(), 1);
	EXPECT_EQ(s->X(), 0);
	EXPECT_EQ(s->Y(), 0);
	EXPECT_EQ(s->Alpha(), 0);
	EXPECT_EQ(s->OpeningAlpha(), 0);
}


TEST(GripTest, testSetOpeningAlpha) {
	Grip* s = new Grip(0, 1);
	s->SetOpeningAlpha(3);
	EXPECT_EQ(s->OpeningAlpha(), 3);
}


TEST(GripTest, Constructor) {
	Grip* s = new Grip(0, 1, 2, 3, 4, 5);


	EXPECT_EQ(s->N_prev(), 0);
	EXPECT_EQ(s->N(), 1);
	EXPECT_EQ(s->X(), 2);
	EXPECT_EQ(s->Y(), 3);
	EXPECT_EQ(s->Alpha(), 4);

	EXPECT_EQ(s->OpeningAlpha(), 5);
}

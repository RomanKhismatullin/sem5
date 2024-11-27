#include "pch.h"
#include "../sem5/Element.h"
#include "../sem5/Element.cpp"

TEST(ElementTest, DefaultConstructor) {
	Element* s = new Element(0, 1);
	EXPECT_EQ(s->N(), 1);
	EXPECT_EQ(s->NPrev(), 0);
	EXPECT_EQ(s->X(), 1);
	EXPECT_EQ(s->Y(), 0);
	EXPECT_EQ(s->Alpha(), 0);
}


TEST(ElementTest, testSetAlpha) {
	Element* s = new Element(0, 1);
	s->SetAlpha(3);
	EXPECT_EQ(s->Alpha(), 3);
}

TEST(ElementTest, TestMoveAlpha) {
	Element* s = new Element(0, 1);
	s->MoveAlpha(2);
	EXPECT_EQ(s->Alpha(), 2);
	s->MoveAlpha(3);
	EXPECT_EQ(s->Alpha(), 5);
}


TEST(ElementTest, Constructor) {
	Element* s = new Element(0, 1, 2, 3, 4);


	EXPECT_EQ(s->NPrev(), 0);
	EXPECT_EQ(s->N(), 1);
	EXPECT_EQ(s->X(), 2);
	EXPECT_EQ(s->Y(), 3);
	EXPECT_EQ(s->Alpha(), 4);
}

#include "pch.h"
#include "../sem5/Positionable.h"
#include "../sem5/Positionable.cpp"
#include "../sem5/TreeObj.h"
#include "../sem5/TreeObj.cpp"

TEST(MoveableTest, DefaultConstructor) {
	Positionable* s = new Positionable(0, 1);
	EXPECT_EQ(s->N(), 1);
	EXPECT_EQ(s->NPrev(), 0);
	EXPECT_EQ(s->X(), 0);
	EXPECT_EQ(s->Y(), 0);
	EXPECT_EQ(s->Alpha(), 0);
}


TEST(PositionableTest, Construction) {
	Positionable* s = new Positionable(0, 1, 1.5, 2.5, 0.1);

	EXPECT_EQ(s->N(), 1);
	EXPECT_EQ(s->NPrev(), 0);
	EXPECT_EQ(s->Alpha(), 0.1);
	EXPECT_EQ(s->X(), 1.5);
	EXPECT_EQ(s->Y(), 2.5);
}

TEST(PositionableTest, Construction2) {
	Positionable* s = new Positionable(1, 2, 1, 2.5, 0.1);

	EXPECT_EQ(s->N(), 2);
	EXPECT_EQ(s->NPrev(), 1);
	EXPECT_EQ(s->Alpha(), 0.1);
	EXPECT_EQ(s->X(), 1);
	EXPECT_EQ(s->Y(), 2.5);
}


//ћетоды движени€ угла протестированы в наследнике Element

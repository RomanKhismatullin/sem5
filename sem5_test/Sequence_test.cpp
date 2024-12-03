#include "pch.h"
#include "../sem5/Sequence.h"
#include "../sem5/Sequence.cpp"
#include "../sem5/MockManipulator.h"
#include "../sem5/ActionMove.h"

TEST(SequenceTests, AddNextWorkMove) {
	auto mn = new MockManipulator();
	auto el = new Element(0, 1);
	mn->AddElement(el);
	auto sq = new Sequence(mn);
	bool disp = false;

	ActionMove* a1 = new ActionMove(0, 2.0);
	ActionMove* a2 = new ActionMove(0, 2.0);
	sq->Add(a1);
	sq->Add(a2);
	int j = sq->Next();
	ASSERT_FALSE(j);
	ASSERT_EQ(el->Alpha(), 2.0);
	j = sq->Next();
	ASSERT_FALSE(j);
	ASSERT_EQ(el->Alpha(), 4.0);

	j = sq->Next();//no more elements
	ASSERT_TRUE(j);
	ASSERT_EQ(el->Alpha(), 4.0);
}

#include "../sem5/ActionSet.h"

TEST(SequenceTests, AddNextWorkSet) {
	auto mn = new MockManipulator();
	auto el = new Element(0, 1);
	mn->AddElement(el);
	auto sq = new Sequence(mn);
	bool disp = false;

	IAction* a1 = new ActionSet(0, 2.0);
	IAction* a2 = new ActionSet(0, 4.0);
	sq->Add(a1);
	sq->Add(a2);
	int j = sq->Next();
	ASSERT_FALSE(j);
	ASSERT_EQ(el->Alpha(), 2.0);
	j = sq->Next();
	ASSERT_FALSE(j);
	ASSERT_EQ(el->Alpha(), 4.0);

	j = sq->Next();//no more elements
	ASSERT_TRUE(j);
	ASSERT_EQ(el->Alpha(), 4.0);
}

#include "../sem5/ActionGrip.h"
#include "../sem5/Grip.h"
TEST(SequenceTests, AddNextWorkGrip) {
	auto mn = new MockManipulator();
	auto el = new Grip(0, 1);
	mn->AddElement(el);
	auto sq = new Sequence(mn);
	bool disp = false;

	ActionGrip* a1 = new ActionGrip(0, 1, 2);
	ActionGrip* a2 = new ActionGrip(0, 2, 4);
	sq->Add(a1);
	sq->Add(a2);

	int j = sq->Next();
	ASSERT_FALSE(j);
	ASSERT_EQ(el->Alpha(), 1.0);
	ASSERT_EQ(el->AlphaOpening(), 2);
	j = sq->Next();
	ASSERT_FALSE(j);
	ASSERT_EQ(el->Alpha(), 2);
	ASSERT_EQ(el->AlphaOpening(), 4);

	j = sq->Next();//no more elements
	ASSERT_TRUE(j);
	ASSERT_EQ(el->Alpha(), 2.0);
}

TEST(SequenceTests, AddNextWorkGripWrongType) {
	auto mn = new MockManipulator();
	auto el = new Element(0, 1);
	mn->AddElement(el);
	auto sq = new Sequence(mn);
	bool disp = false;

	ActionGrip* a1 = new ActionGrip(0, 1, 2);
	ActionGrip* a2 = new ActionGrip(0, 2, 4);
	sq->Add(a1);
	sq->Add(a2);

	int j = sq->Next();//wrong type
	ASSERT_TRUE(j == -1);
	ASSERT_EQ(el->Alpha(), 0);
}

TEST(SequenceTests, AddNextWorkSetWrongType) {
	auto mn = new MockManipulator();
	auto el = new Grip(0, 1);
	mn->AddElement(el);
	auto sq = new Sequence(mn);
	bool disp = false;

	ActionMove* a1 = new ActionMove(0, 1);
	sq->Add(a1);

	int j = sq->Next();//wrong type
	ASSERT_TRUE(j);
	ASSERT_EQ(el->Alpha(), 0);
}

#include "../sem5/MockAction.h"
#include "../sem5/MockAction.cpp"

TEST(SequenceTests, NextFailed) {
	auto mn = new MockManipulator();
	auto el = new Element(0, 1);
	mn->AddElement(el);
	auto sq = new Sequence(mn);
	bool disp = false;

	MockAction* a1 = new MockAction(7, &disp);
	MockAction* a2 = new MockAction();
	sq->Add(a1);
	sq->Add(a2);
	int j = sq->Next();
	ASSERT_TRUE(j!=0);
	ASSERT_EQ(el->Alpha(), 0);
	ASSERT_FALSE(disp);
	//j = sq->Next();
	//ASSERT_FALSE(j);
	//ASSERT_EQ(el->Alpha(), 2.0);

	//j = sq->Next();//no more elements
	//ASSERT_TRUE(j!=0);
	//ASSERT_EQ(el->Alpha(), 2.0);
}


TEST(SequenceTests, NextGood) {
	auto mn = new MockManipulator();
	auto el = new Element(0, 1);
	mn->AddElement(el);
	auto sq = new Sequence(mn);
	bool disp = false;

	MockAction* a1 = new MockAction(0, &disp);
	MockAction* a2 = new MockAction();
	sq->Add(a1);
	sq->Add(a2);
	int j = sq->Next();
	ASSERT_TRUE(j == 0);
	ASSERT_EQ(el->Alpha(), 1.0);
	ASSERT_TRUE(disp);
	j = sq->Next();
	ASSERT_FALSE(j);
	ASSERT_EQ(el->Alpha(), 2.0);

	j = sq->Next();//no more elements
	ASSERT_TRUE(j!=0);
	ASSERT_EQ(el->Alpha(), 2.0);
}






#define N_t 10

TEST(SequenceTests, AddNextWorkMem1234) {
	ASSERT_TRUE(true);
	auto mn = new MockManipulator();
	auto el = new Element(0, 1);
	mn->AddElement(el);


	MockAction* act[N_t];
	bool disp[N_t];

	auto sq = new Sequence(mn);

	for (int i = 0; i < N_t; i++) {
		act[i] = new MockAction(0, disp+i);
		sq->Add(act[i]);
	}
	
	for (int i = 0; i < N_t; i++) {
		int j = sq->Next();
		ASSERT_FALSE(j);
		ASSERT_TRUE(act[i]->DISPOSEFLAG);
		ASSERT_EQ(el->Alpha(), i+1);
	}

}



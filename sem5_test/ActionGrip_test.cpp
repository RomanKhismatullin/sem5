#include "pch.h"
#include "../sem5/ActionGrip.h"
#include "../sem5/MockManipulator.h"
#include "../sem5/Grip.h"
#include "../sem5/ActionGrip.cpp"

/*#include "pch.h"
#include "../sem5/IAction.h"
#include "../sem5/ActionMove.h"
#include "../sem5/ActionMove.cpp"

#include "../sem5/MockManipulator.h"
#include "../sem5/MockManipulator.cpp"
*/
TEST(ActionGripTest1, UsualGripTest) {
	ActionGrip* act = new ActionGrip(0, 3.14, 1.4);
	EXPECT_EQ(act->Alpha, 3.14);
	EXPECT_EQ(act->OpeningAlpha, 1.4);
	EXPECT_EQ(act->N, 0);

	IAction* act2 = act;

	Grip* el = new Grip(0, 1);
	el->MoveAlpha(1.1);
	el->SetOpeningAlpha(2.0);

	Positionable* pos = el;
	EXPECT_EQ(el->Alpha(), 1.1);
	EXPECT_EQ(el->AlphaOpening(), 2);

	auto mm = new MockManipulator();
	mm->AddElement(pos);
	int rs = act->DoWork(mm);
	EXPECT_EQ(mm->Pos->Alpha(), 3.14);
	EXPECT_EQ(el->AlphaOpening(), 1.4);
	EXPECT_EQ(rs, 0);
}


TEST(ActionGripTest1, WrongClass) {
	ActionGrip* act = new ActionGrip(0, 3.14, 1.4);
	EXPECT_EQ(act->Alpha, 3.14);
	EXPECT_EQ(act->OpeningAlpha, 1.4);
	EXPECT_EQ(act->N, 0);

	IAction* act2 = act;

	Element* el = new Element(0, 1);
	el->MoveAlpha(1.1);
	//el->SetOpeningAlpha(2.0);

	Positionable* pos = el;
	EXPECT_EQ(el->Alpha(), 1.1);
	//EXPECT_EQ(el->AlphaOpening(), 2);

	auto mm = new MockManipulator();
	mm->AddElement(pos);
	int rs = act->DoWork(mm);
	EXPECT_EQ(mm->Pos->Alpha(), 1.1);
	//EXPECT_EQ(mm->Po->AlphaOpening(), 1.4);
	EXPECT_EQ(rs, 1);
}
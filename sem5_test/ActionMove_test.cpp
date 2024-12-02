#include "pch.h"
#include "../sem5/IAction.h"
#include "../sem5/ActionMove.h"
#include "../sem5/ActionMove.cpp"

#include "../sem5/MockManipulator.h"
#include "../sem5/MockManipulator.cpp"



TEST(ActionMoveTest, MoveTest2) {
	ActionMove* act = new ActionMove(2, 3.14);
	EXPECT_EQ(act->Fi, 3.14);
	EXPECT_EQ(act->N, 2);

	IAction* act2 = act;

	Element* el = new Element(0, 1);
	el->MoveAlpha(1.1);

	Positionable* pos = el;
	EXPECT_EQ(el->Alpha(), 1.1);

	auto mm = new MockManipulator();
	mm->AddElement(pos);
	int rs = act->DoWork(mm);
	EXPECT_EQ(mm->Pos->Alpha(), 1.1);
	EXPECT_EQ(rs, 1);
}

TEST(ActionMoveTest, MoveTest1) {
	ActionMove* act = new ActionMove(0, 3.14);
	EXPECT_EQ(act->Fi, 3.14);
	EXPECT_EQ(act->N, 0);

	IAction* act2 = act;

	Element* el = new Element(0, 1);
	el->MoveAlpha(1.1);

	Positionable* pos = el;
	EXPECT_EQ(el->Alpha(), 1.1);

	auto mm = new MockManipulator();
	mm->AddElement(pos);
	int rs = act->DoWork(mm);
	EXPECT_EQ(mm->Pos->Alpha(), 3.14 + 1.1);
	EXPECT_EQ(rs, 0);
	rs = act->DoWork(mm);
	EXPECT_EQ(mm->Pos->Alpha(), 2 * 3.14 + 1.1);
	EXPECT_EQ(rs, 0);
}

#include "../sem5/Camera.h"

TEST(ActionMoveTest, WrongType) {
	ActionMove* act = new ActionMove(0, 3.14);
	EXPECT_EQ(act->Fi, 3.14);
	EXPECT_EQ(act->N, 0);

	IAction* act2 = act;

	Positionable* el = new Camera(0, 1);
	el->MoveAlpha(1.1);

	//Positionable* pos = el;
	EXPECT_EQ(el->Alpha(), 1.1);

	auto mm = new MockManipulator();
	mm->AddElement(el);
	int rs = act->DoWork(mm);
	EXPECT_EQ(mm->Pos->Alpha(), 1.1);
	EXPECT_EQ(rs, 1);
}
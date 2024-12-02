#include "pch.h"
#include "../sem5/MockManipulator.h"
#include "../sem5/ActionCamera.h"
#include "../sem5/ActionCamera.cpp"
#include "../sem5/Camera.h"

TEST(ActionCameraTest, WrongN) {
	ActionCamera* act = new ActionCamera(2, 3.14, 1.2); //exp false N!=0
	EXPECT_EQ(act->Alpha, 3.14);
	EXPECT_EQ(act->AlphaView, 1.2);
	EXPECT_EQ(act->N, 2);

	IAction* act2 = act;

	Camera* el = new Camera(0, 1);
	el->MoveAlpha(1.1);

	Positionable* pos = el;
	EXPECT_EQ(el->Alpha(), 1.1);

	auto mm = new MockManipulator();
	mm->AddElement(pos);
	int rs = act->DoWork(mm);
	EXPECT_EQ(mm->Pos->Alpha(), 1.1);
	EXPECT_EQ(rs, 1);
}


TEST(ActionCameraTest, GOOD) {
	ActionCamera* act = new ActionCamera(0, 3.14, 1.2); //exp false N!=0
	EXPECT_EQ(act->Alpha, 3.14);
	EXPECT_EQ(act->AlphaView, 1.2);
	EXPECT_EQ(act->N, 0);

	IAction* act2 = act;

	Camera* el = new Camera(0, 1);
	el->MoveAlpha(1.1);

	EXPECT_EQ(el->Alpha(), 1.1);

	auto mm = new MockManipulator();
	mm->AddElement(el);
	EXPECT_EQ(el->Alpha(), 1.1);

	int rs = act->DoWork(mm);
	EXPECT_EQ(el->Alpha(), 3.14);
	EXPECT_EQ(el->AlphaView(), 1.2);
	EXPECT_EQ(rs, 0);
}


TEST(ActionCameraTest, WrongType) {
	ActionCamera* act = new ActionCamera(0, 3.14, 1.2); //exp false N!=0
	EXPECT_EQ(act->Alpha, 3.14);
	EXPECT_EQ(act->AlphaView, 1.2);
	EXPECT_EQ(act->N, 0);

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